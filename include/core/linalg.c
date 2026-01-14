#include "core/linalg.h"
#include <math.h>

// matrix multiplication is done using vDSP_mmul
// vDSP_mmul uses 'Row-Major' or 'Column-Major' logic depending on stride

void mat_mul(const float* A, const float* B, float* C, int m, int n, int k) {
   //M: rows of A and C 
  //N: columns of B and C 
  //P: colums of A and rows of B
  vDSP_mmul(A, 1 B, 1 C, 1 m, n, k);

}

