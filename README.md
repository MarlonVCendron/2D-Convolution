# Trabalho final desenvolvido para a disciplina de algoritmos

## Convolução 2D

O algoritmo recebe duas matrizes de entrada: a matriz a ser processada e o kernel (ou filtro). A matriz então é processada pelo kernel e o algoritmo imprime a matriz resultante.

![Animação convolução](https://miro.medium.com/max/790/1*1okwhewf5KCtIPaFib4XaA.gif)

A função convolution2D é a parte essencial do algoritmo. Ela recebe como parâmetros a matriz a ser processada (mat), o kernel e os respectivos tamanhos de cada matriz e retorna a matriz resultante.

    result = convolution2D(mat, kernel, &matR, &matC, &kernelR, &kernelC);
