#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para imprimir os valores de uma matriz
void printMatrix(double **mat, int *height, int *width){
  for (size_t i = 0; i < *height; i++) {
    for (size_t j = 0; j < *width; j++) {
      printf("%14.6f ", mat[i][j]);
    }
    printf("\n");
  }
}

// Função para receber a entrada de uma matriz
double** getInputMatrix(double **mat, int *m, int *n, bool square){
  // Recebe entrada do número de linhas e colunas
  printf("Digite o número de linhas da matriz: ");
  scanf("%d", m);

  // Se for uma matriz quadrada de lado par, cancela o programa;
  if (square && *m % 2 == 0) {
    printf("O Kernel deve ser uma matriz com tamanho ímpar\n");
    exit(0);
  }

  // Se a matriz for quadrada não há necessidade de pedir o número de colunas
  if(!square){
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", n);
  }

  // Aloca a memória para a matriz
  mat = (double **)malloc(*m * sizeof(double*));
  for(int i = 0; i < *m; i++)
    mat[i] = (double *)malloc(*n * sizeof(double));


  // Recebe a entrada dos valores da matriz
  printf("Digite os valores da matriz: \n");
  for (size_t i = 0; i < *m; i++) {
    printf("Linha %d: ", (i+1));
    for (size_t j = 0; j < *n; j++) {
      scanf("%lf", &mat[i][j]);
    }
  }

  return mat;
}

double** convolution2D(double **mat, double **kernel, int *matR, int *matC, int *kernelS){
  double **result; // Matriz resultante

  // Alocação de memória para a matriz resultante
  result = (double **)malloc(*matR * sizeof(double*));
  for(int i = 0; i < *matR; i++)
    result[i] = (double *)malloc(*matC * sizeof(double));

  int squaredKernelS = *kernelS * *kernelS;

  for (size_t i = 0; i < *matR; i++) { // Linhas da matriz
    for (size_t j = 0; j < *matC; j++) { // Colunas da matriz

      result[i][j] = 0; // Inicializa o valor em 0

      for (int p = 0; p < *kernelS; p++) { // Linhas do kernel

        int ii = i + (p - *kernelS/2); // Índice da linha a ser calculada
        if(ii < 0 || ii >= *matR) continue; // Se o índice estiver fora da matriz, ele não é calculado

        for (int q = 0; q < *kernelS; q++) { // Colunas do kernel

          int jj = j + (q - *kernelS/2); // Índice da coluna a ser calculada
          if(jj < 0 || jj >= *matC) continue; // Se o índice estiver fora da matriz, ele não é calculado

          result[i][j] += mat[ii][jj] * kernel[p][q]; // Cada número calculado é acrescentado à matriz resultante
        }
      }
    }
  }


  return result;
}

int main() {
  int matR, matC, kernelS; // Número de linhas e colunas da matriz a ser processada e do filtro
  double **mat, **kernel, **result; // Matriz a ser processada, filtro e resultado

  printf("MATRIZ A SER PROCESSADA:\n\n");
  mat = getInputMatrix(mat, &matR, &matC, false); // Entrada para a matriz

  printf("\nFILTRO:\n\n");
  kernel = getInputMatrix(kernel, &kernelS, &kernelS, true); // Entrada para o Kernel

  result = convolution2D(mat, kernel, &matR, &matC, &kernelS); // Calcula a matriz resultante

  printf("\n\n\nMatriz resultante\n\n");

  printMatrix(result, &matR, &matC); // Imprime a matriz resultante

  return 0;
}
