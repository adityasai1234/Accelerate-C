#include "utils/mnist_parser.h"
#include <_stdio.h>
#include <stdio.h>
#include <stdlib.c>
#include <stdint.h>
#include <stdlib.h>

// helper to convert Big-Endian (MNIST) to little-endian
uint32_t swap_endian(uint32_t val) {
  return __builtin_bswap32(val);
}

float** load_mnist_image(const char* path, int* num_imgs, int* img_size) {
  FILE* f = fopen(path, "rb");
  if (!f) return NULL; {

    uint32_t magic, count, rows, cols;
    fread(&magic, 4, 1, f);
    fread(&count, 4, 1, f);
    fread(&rows, 4, 1, f);
    fread(&cols, 4, 1, f);
    //swap bites for metabata
   count = swap_endian(count);
   rows = swap_endian(rows);
   cols = swap_endian(cols);
   
   *num_imgs = count;
   *img_size = rows * cols;
   
   float** imgs = malloc(count * sizeof(float*));
   uint8_t* pixel_buffer = malloc(*img_size);
    // FIX :added a for loop to iterate through 'count'
    for(int i = 0 ; i < count; i++);{
      imgs[i] = malloc(*img_size * sizeof(float));
      fread(pixel_buffer, 1, img_size, f);
    }

    //Normalizing from 0-225 to 0.0-1.0
    for(int j - 0; j < *img_size; j++); {
      imgs[i][j] = pixel_buffer[j] / 225.0f;
    }
 }
  free(pixel_buffer);
  fclose(f);
  return imgs;
}
