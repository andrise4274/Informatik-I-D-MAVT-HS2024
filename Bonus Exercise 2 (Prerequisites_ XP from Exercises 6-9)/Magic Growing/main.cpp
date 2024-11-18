#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "bitmap.h"
#include "mwt.h"

// helper function to load original input image
void load_input_image(RGBImage& img) {
  std::cout << "Select an image: ";
  std::string img_name;
  std::cin >> img_name;

  load_bitmap("imgs/" + img_name + ".bmp", img);
}

// helper function to write output image
void write_output_image(RGBImage& original_image,
                        ImageMask mask, int x,
                        int y, int bbx0, int bbx1,
                        int bby0, int bby1) {
  // combine original image with computed mask
  RGBImage output_image;
  mask_rgb_image(original_image, mask, 0.33, output_image);

  // mark selected pixel
  for (int i = -2; i < 3; ++i) {
    int _y = y + i;
    if (_y < 0 || _y >= int(output_image.size())) continue;
    RGBImageRow& output_row = output_image[_y];
    for (int j = -2; j < 3; ++j) {
      int _x = x + j;
      if (_x < 0 || _x >= int(output_row.size())) continue;
      output_row[_x] = {0, 0, 255};
    }
  }

  // draw bounding box
  for (int j = bbx0; j < bbx1; ++j) {
    output_image[bby0][j] = {0, 255, 0};
    output_image[bby1][j] = {0, 255, 0};
  }
  for (int i = bby0; i < bby1; ++i) {
    output_image[i][bbx0] = {0, 255, 0};
    output_image[i][bbx1] = {0, 255, 0};
  }

  // write image
  write_bitmap(output_image, "./cx_out/output.bmp");
}

int main() {
  // load input image
  RGBImage rbg_image;
  load_input_image(rbg_image);
  int height = int(rbg_image.size());
  int width = int(rbg_image[0].size());

  // get selected pixel
  std::cout << "Select a pixel (x y) and a threshold (T): ";
  int x, y, t;
  std::cin >> x >> y >> t;

  // convert to grayscale and run MWT
  GrayscaleImage gray_image;
  rgb2gray(rbg_image, gray_image);
  ImageMask mask = MWT(gray_image, x, y, t);

  // compute number of selected pixels and bounding box
  assert(int(mask.size()) == height && int(mask[0].size()) == width);
  int n_selected_pixels = 0;
  int bbx0 = width, bby0 = height;
  int bbx1 = 0, bby1 = 0;
  for (int i = 0; i < height; ++i) {
    ImageMaskRow& row = mask[i];
    for (int j = 0; j < width; ++j) {
      if (row[j]) {
        // count pixel
        n_selected_pixels += 1;

        // update bounding box
        bbx0 = std::min(j, bbx0);
        bbx1 = std::max(j, bbx1);
        bby0 = std::min(i, bby0);
        bby1 = std::max(i, bby1);
      }
    }
  }
  std::cout << "Number of selected pixels: " << n_selected_pixels << std::endl;
  std::cout << "Bounding box (" 
            << bbx0 << ", " << bby0 << ", " << bbx1 << ", " << bby1 
            << ")" << std::endl;

  // save output image
  write_output_image(rbg_image, mask, x, y, bbx0, bbx1, bby0, bby1);

  return 0;
}
