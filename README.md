# Trabalho final desenvolvido para a disciplina de algoritmos

## Convolução 2D

O algoritmo recebe duas matrizes de entrada: a matriz a ser processada e o kernel (ou filtro). A matriz então é processada pelo kernel e o algoritmo imprime a matriz resultante.

<p align="center">
  <img src="https://miro.medium.com/max/790/1*1okwhewf5KCtIPaFib4XaA.gif" />
</p>

A função convolution2D é a parte essencial do algoritmo. Ela recebe como parâmetros a matriz a ser processada (mat), o kernel e os respectivos tamanhos de cada matriz e retorna a matriz resultante.

```
result = convolution2D(mat, kernel, &matR, &matC, &kernelS);
```

Primeiramente, a matriz resultante é declarada e tem sua memória alocada dinamicamente.

```
double **result; // Matriz resultante

// Alocação de memória para a matriz resultante
result = (double **)malloc(*matR * sizeof(double*));
for(int i = 0; i < *matR; i++)
  result[i] = (double *)malloc(*matC * sizeof(double));
```

É preciso calcular o valor de cada um dos índices da matriz, para isso são utilizados dois loops: um para os índices das linhas (i) e outro para os índices das colunas (j). Este algoritmo cria uma matriz resultante de mesma altura e largura que a matriz original, o que significa que alguns dos valores serão calculados sem terem valores vizinhos, como ocorre na animação à cima. Nesse caso, é como se esses vizinhos tivessem o valor de 0.

```
for (size_t i = 0; i < *matR; i++) { // Linhas da matriz
  for (size_t j = 0; j < *matC; j++) { // Colunas da matriz
```

Já que o valor em determinado índice será a soma dos produtos de seus vizihos com o filtro, o valor na matriz resultante é inicializado com o valor 0;

```
result[i][j] = 0; // Inicializa o valor em 0
```

Para calcular o valor de determinado índice na matriz, o algoritmo vai checar todos os seus vizinhos baseado no kernel passado como argumento. O primeiro loop roda por todos os índices de linhas do kernel, começando no índice 0 e terminando no índice kernelS-1.

O índice da linha do elemento vizinho é dado pela variável ii, que é definida pelo índice da linha atual, i, mais o índice atual da linha do kernel, q, menos metade do tamanho do kernel. Para um kernel de tamanho 5, por exemplo, os valores de ii serão o valor de i mais -2, -1, 0, 1 e 2, ou seja, dois índices para cima até dois para baixo.

Se o índice do vizinho for menor que 0 ou maior que o número de linhas da matriz, então nada é calculado neste índice, já que ele não está na matriz, e é tratado como se tivesse o valor de 0;

O mesmo processo é feito para as colunas em um outro loop dentro do das linhas. Assim, para cada linha dos vizinhos, é passado por todas as colunas.

Exemplo dos valores de ii e jj para i = 1, j = 2 e um kernel com tamanho 3, kernelS = 3:

<div style="display:flex; justify-content: center;">
<table>
  <tr>
    <td style="font-weight: bold;font-family: monospace">ii</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>2</td>
    <td>2</td>
    <td>2</td>
  </tr>
  <tr>
    <td style="font-weight: bold;font-family: monospace">jj</td>
    <td>1</td>
    <td>2</td>
    <td>3</td>
    <td>1</td>
    <td>2</td>
    <td>3</td>
    <td>1</td>
    <td>2</td>
    <td>3</td>
  </tr>
</table>
</div>

A matriz:

<div style="display:flex; justify-content: center;">
<table>
  <tr>
    <td>0,0</td>
    <td><i>0,1</i></td>
    <td><i>0,2</i></td>
    <td><i>0,3</i></td>
    <td>0,4</td>
  </tr>
  <tr>
    <td>1,0</td>
    <td><i>1,1</i></td>
    <td><b>1,2</b></td>
    <td><i>1,3</i></td>
    <td>1,4</td>
  </tr>
  <tr>
    <td>2,0</td>
    <td><i>2,1</i></td>
    <td><i>2,2</i></td>
    <td><i>2,3</i></td>
    <td>2,4</td>
  </tr>
  <tr>
    <td>3,0</td>
    <td>3,1</td>
    <td>3,2</td>
    <td>3,3</td>
    <td>3,4</td>
  </tr>
  <tr>
    <td>4,0</td>
    <td>4,1</td>
    <td>4,2</td>
    <td>4,3</td>
    <td>4,4</td>
  </tr>
</table>
</div>

```
for (int p = 0; p < *kernelS; p++) { // Linhas do kernel

  int ii = i + (p - *kernelS/2); // Índice da linha a ser calculada
  if(ii < 0 || ii >= *matR) continue; // Se o índice estiver fora da matriz, ele não é calculado

  for (int q = 0; q < *kernelS; q++) { // Colunas do kernel

    int jj = j + (q - *kernelS/2); // Índice da coluna a ser calculada
    if(jj < 0 || jj >= *matC) continue; // Se o índice estiver fora da matriz, ele não é calculado

```

Tendo todos os índices dos vizinhos, o que resta é calcular o valor para a matriz resultante nesse índice. Ao valor na matriz resultante, que é inicializado em 0, é adicionado o produto do vizinho mat[ii][jj] com o valor do kernel para esse índice do vizinho, kernel[p][q].

```
result[i][j] += mat[ii][jj] * kernel[p][q]; // Cada número calculado é acrescentado à matriz resultante

```

Depois de calcular o resultado para todos os índices, a função retorna a matriz resultante.

```
return result;
```
