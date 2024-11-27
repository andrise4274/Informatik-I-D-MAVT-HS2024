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
  assert(false);

}
