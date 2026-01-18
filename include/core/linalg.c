#include "core/linalg.h"
#include <math.h>

// matrix multiplication is done using vDSP_mmul
// vDSP_mmul uses 'Row-Major' or 'Column-Major' logic depending on stride

void mat_mul(const float* A, const float* B, float* C, int m, int n, int k) {
   //M: rows of A and C 
  //N: columns of B and C 
  //P: colums of A and rows of B
  vDSP_mmul(A, 1, B, 1, C, 1, m, n, k);
}

void sigmoid_vec(float* data, int size) {
  // neural network need non-linear activation
  // sigmoid func: 1.0/(1.0 + exp(-x))
for (int i = 0; i < size; i++) {
    data[i] = 1.0f / (1.0f + expf(-data[i]));
  }
}

float dot_product(const float* A, const float* B, int size) {
  float result = 0;
  vDSP_dotpr(A, 1, B, 1, &result, size);
  return result;
}

// vector sigmoid activation 
//  formula: f(x) = 1 / (1+ exp(-x))
void sigmoid_vec(float* data, int size) {
  //Note: to calculate exponentials for the entire vector at once
  for(int i = 0; i < size; i++) {
    data[i] = 1.0 / (1.0f + expf(-data[i]));

  }
}
// Dot product using vDSP_dotpr, great for single neuron activation
float dot_product(const float* A, const float* B, int size){
  float result = 0;
  vDSP_dotpr(A, 1, B, 1, &result, size);
  return result;
}
