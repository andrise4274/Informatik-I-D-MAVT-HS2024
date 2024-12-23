#include "mwt.h"

#include <assert.h>

// function header
void compute_mask(const GrayscaleImage& image, 
                  ImageMask& mask, 
                  const int x, 
                  const int y, 
                  const int T, 
                  const int luminence);

// PRE:  All rows in image have the same size.
//       x and y must be valid indices of the image.
// POST: Returns a matrix of bools where every true value corresponds to a pixel
//       with at least one path of T-similar pixels starting at x,y.
ImageMask MWT(const GrayscaleImage& image,
              const int x, const int y,
              const int T) {
  // get image dimensions
  const int height = image.size();
  assert(height > 0);
  const int width = image[0].size();
  assert(y < height && x < width);

  // init mask
  ImageMask mask(height, ImageMaskRow(width, false));

  // compute mask
  // give arguments x, y in reverse, due to reversed index into image
  compute_mask(image, mask, y, x, T, image[y][x]);
  
  // return mask
  return mask;
}


// recursively traverses the image and adapt the mask
// with breadth first search (as I learned in https://cs50.harvard.edu/ai/2024/weeks/0/)
// keep track of explored set (as in breadth first search) to avoid infinite loops -> shortcut with existing mask vector
void compute_mask(const GrayscaleImage& image,
                  ImageMask& mask,
                  const int x,
                  const int y,
                  const int T,
                  const int luminence) {
  
  // terminal conditions
  // edge cases
  if (x < 0 || x >= int(image[0].size())) {
    return;
  }
  if (y < 0 || y >= int(image.size())) {
    return;
  }
  
  // check if pixel is in explored set (has true at the mask vector)
  if (mask[x][y]) {
    return;
  }
  
  // if luminence difference is too big
  if (std::abs(luminence - int(image[x][y])) > T) {
    return;
  }
  
  // else, if no terminal condition triggered
  mask[x][y] = true;
  
  // recursively go to all neighbours
  compute_mask(image, mask, x + 1, y, T, luminence);
  compute_mask(image, mask, x, y + 1, T, luminence);
  compute_mask(image, mask, x - 1, y, T, luminence);
  compute_mask(image, mask, x, y - 1, T, luminence);
}