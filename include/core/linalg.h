#ifndef LINALG_H
#define LINALG_H
#include <Accelerate/Accelerate.h>
// Matrix Multiplication: C = A * B
//m: rows A, n: cols of B, k: cols of A / rows of B
void mat_mul(const float* A, const float* B, float* C, int m, int n, int k);

// vectorized sigmoid function applies 1/(1 + exp(-x)) to every element of array
void sigmoid_vec(float* data, int size);

// dot function where it returns the sum of (A[i] * B[i])
float dot_product(const float* A, const float* B, int size);

#endif // !LINALG_H 
