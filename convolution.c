#include <stdio.h>
#include <stdlib.h>

// Função para imprimir os valores de uma matriz
void printMatrix(double **mat, int *height, int *width){
  for (size_t i = 0; i < *height; i++) {
    for (size_t j = 0; j < *width; j++) {
      printf("%lf ", mat[i][j]);
    }
    printf("\n");
  }
}

// Função para receber a entrada de uma matriz  
double** getInputMatrix(double **mat, int *m, int *n){
  // Recebe entrada do número de linhas e colunas
  printf("Digite o número de linhas da matriz: ");
  scanf("%d", m);
  printf("Digite o número de colunas da matriz: ");
  scanf("%d", n);

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

int main() {
  int matRows, matCols, filterRows, filterCols; // Número de linhas e colunas da matriz a ser processada e do filtro
  double **mat, **filter; // Matriz a ser processada e filtro

  printf("MATRIZ A SER PROCESSADA:\n\n");
  mat = getInputMatrix(mat, &matRows, &matCols);

  printf("\nFILTRO:\n\n");
  filter = getInputMatrix(filter, &filterRows, &filterCols);

  printMatrix(mat, &matRows, &matCols);
  printMatrix(filter, &filterRows, &filterCols);

  return 0;
}
