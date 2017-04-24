/*Programa para converte algarismo Romanos em Indo-Arábico*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*Função que verifica o tamanho do vetor de inteiro*/
int tam_vet(int *vetor);


/*Função responsável pela conversão do vetor romano para arabico
	* e também resṕonsável pelo valor da soma*/
int converte(char romano[]);


/*Função que verifica se o algarismo romano 'I' está correto
	* levando em consideração: I, II, III
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro*/
unsigned int verifica_I(char romano[]);

/*Função que verifica se o algarismo romano 'V' está correto
	* levando em consideração: IV, V, VI, VII, VIII
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro*/
unsigned int verifica_V(char romano[]);

/*Função que verifica se o algarismo romano 'X' está correto
	* levando em consideração: IX, X, XI, XII, XIII, XIV
	* XVI, XVII, XVIII, XIX, XX, ....
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro
	* recebe como paramentro além do vetor
	* uma variavel inteira*/
unsigned int verifica_X(char romano[], int vezes);

/*Função que verifica se o algarismo romano 'L' está correto
	* levando em consideração: XL, L, LX, LXX, LVI...
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro
	* recebe como paramentro além do vetor
	* uma variavel inteira*/
unsigned int verifica_L(char romano[], int vezes);

/*Função que verifica se o algarismo romano 'C' está correto
	* levando em consideração: XC, C, CC, CCC, CL, ...
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro
	* recebe como paramentro além do vetor
	* uma variavel inteira*/
unsigned int verifica_C(char romano[], int vezes);