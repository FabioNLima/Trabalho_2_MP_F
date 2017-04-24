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



