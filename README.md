# Trabalho de ED1

Trabalho realizado no 3º período da faculdade. Trata-se um desenvolvimento dinâmico, com o objetivo de criar matrizes esparsas.



## 1. Matrizes Esparsas

(Utilização de Listas por meio de Estruturas Auto-Referencias ([3] apud [2]))
Objetivos
Consiste em concretizar os conceitos de Listas implementadas por encadeamento através de uma
aplicação: Matrizes esparsas.
Descrição
Matrizes esparsas são matrizes nas quais a maioria das posições é preenchida por zeros. Para essas matrizes,
podemos economizar um espaço significativo de memória se apenas os termos diferentes de zero forem
armazenados. As operações usais sobre essas matrizes (somar, multiplicar, inverter, pivotar) também podem
ser feitas em tempo muito menor se não armazenarmos as posições que contêm zeros.
 Uma maneira eficiente de presentar estruturas com tamanho variável e/ou desconhecido é com o
emprego de alocação encadeada, utilizando listas. Vamos usar essa representação para armazenar as matrizes
esparsas. Cad coluna da matriz será representada por uma lista linear circular com uma célula cabeça. Da
mesma maneira, cada linha da matriz também será representada por uma lista linear circular com uma célula
cabeça. Cada célula da estrutura, além das células cabeça, representará os termos diferentes de zero da matriz
e deverá ser como no código abaixo:

typedef struct Celula {
 Celula direita, abaixo;
 int linha, coluna;
 double valor;
} Celula;

O campo abaixo deve ser usado para referenciar o elemento diferente de zero na mesma coluna. O
campo direita deve ser usadao para referenciar o próximo elemento diferente de zero na mesma linha. Dada
uma matriz A, para um valor A(i,j) diferente de zero, deverá haver uma célula com o campo valor contendo
A(i,j), o campo linha contendo i e o campo coluna contendo j. Essa célula deverá pertencer a lista ciruclar da
linha i e também deverá pertencer à lista circular da coluna j. Ou seja, cada célula pertencerá a duas listas ao
mesmo tempo. Para diferenciar as células cabeça, coloque -1 nos campos linha e coluna dessas células.

Dada a representação de listas duplamente encadeadas, o trabalho consiste em desenvolver em
C/C++ um tipo abstrato de dados Matriz com as seguintes operações, conforme esta especificação: 

a) void imprimeMatriz()
Esse método imprime (uma linha da matriz por linha na saída) a matriz A, inclusive os
elementos iguais a zero.

b) void leMatriz()
Esse método lê, de algum arquivo de entrada, os elementos diferentes de zero de uma matriz
e monta a estrutura especificada anteriormente. Considere que a entrada conssite dos valores
de m e n (número de linhas e de colunas da matriz) seguidos de triplas ( i, j, valor) para os
elementos diferentes de zero da matriz. Por exemplo, para a matriz anterior, a entrada seria:
4, 4
1, 1, 50.0
2, 1, 10.0
2, 3, 20.0
4, 1, -30.0
4, 3, -60.0
4, 4, -5.0

c) TMatriz somaMatriz(TMatriz A, TMatriz B)
Esse método recebe como parâmetros as matrizes A e B, devolvendo uma matriz C que é a
soma de A com B.

d) TMatriz multiplicaMatriz(TMatriz A, TMatriz B)
Esse método recebe como parâmetros as matrizes A e B, devolvendo uma matriz C que é o
produto de A por B.
 Para inserir e retirar células das listas que formam a matriz, crie métodos especiais para esse fim. Por
exemplo
void insere(int i, int j, double v)
para inserir o valor v na linha i, coluna j da matriz A será útil tanto na função leMatriz quando na função
somaMatriz. 

 
