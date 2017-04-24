/*Programa para converte algarismo Romanos em Indo-Arábico*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "romanos.h"


/*Função que verifica o tamanho do vetor de inteiro*/
int tam_vet(int *vetor)
{
	int i =0 ;
	while(vetor[i]!=0)
		i++;
	return i;
}


/*Função responsável pela conversão do vetor romano para arabico
	* e também resṕonsável pelo valor da soma*/
int converte(char romano[])
{
	/*Variaveis de controle
		* numero_maior recebe a soma do elemento atual com o proximo elemento
		* numero_menor recebe a soma do proximo elemento com o elemento atual
		* tamanho do vetor sera usado para fazer o calculo
		* caso o vetor seja de tamanho par, as operações serão a cada 2 elementos
		* caso seja impar, primeiro recebe o primeiro elemento do vetor
		* e a operação ocorre com o vetor par*/
	int i, numero_maior, numero_menor, primeiro, tamanho_vetor;
	int soma_maior = 0, soma_menor = 0, final;
	int arabico[30];

	/*Preenchendo todo o vetor com zero
		* Vetor responsável por receber os algarismo indo-arabico*/
	for (int i = 0; i < 30; ++i)
	{
		arabico[i] = 0;
	}

	/*Percorre o vetor algarismo-romano
		* e para cada algarismo que for encontrado
		* será adicionado o seu respectivo valor
		* no vetor arabico*/
	for(i = 0; i < strlen(romano); i++)
	{
		switch(romano[i])
		{
			case 'I': arabico[i] = 1; break;
			case 'V': arabico[i] = 5; break;
			case 'X': arabico[i] = 10; break;
			case 'L': arabico[i] = 50; break;
			case 'C': arabico[i] = 100; break;
			case 'D': arabico[i] = 500; break;
			case 'M': arabico[i] = 1000; break;

		}
	}
	
	/*Verificar o tamanho do vetor*/
	tamanho_vetor = tam_vet(arabico);

	/*Se o tamanho do vetor for um numero par
		* os elementod do vetor serão somados a cada 2 elementos */
	if(tamanho_vetor % 2 == 0)
	{

		/*Percorre todo o vetor até o final dele*/
		for (i = 0; i < strlen(romano); i+= 2)
		{	

			/*Se elemento atual for maior ou igual ao proximo elemento
				* serão somados e adicionado em uma variavel de incremento*/	
			if(arabico[i] >= arabico[i + 1])
			{
				numero_maior = (arabico[i] + arabico[i + 1]);
				soma_maior += numero_maior;
			}
			/*Caso contratrio, elemento atual menor que proximo
				* será feito uma subtração do proximo elemento menos o atual*/
			else
			{
				numero_menor = (arabico[i + 1] - arabico[i]);
				soma_menor += numero_menor;
			}
		}

		/*Variavel final recebe todo valor das condições anteriores
			* somando as variaveis soma_maior e soma_menor*/
		final = (soma_maior + soma_menor);

		/*Retorna o valor total*/
		return final;	

	}
	else
	{
		/*Caso o tamanho do vetor seja impar,
			* a variavel primeiro recebe o primeiro elemento do vetor
			* e logo após realiza os mesmo procedimentos como se o
			* vetor tivesse o tamanho par*/
		primeiro = arabico[0];
		
		/*Percorre todo o vetor até o final dele*/
		for (i = 1; i < strlen(romano); i+= 2)
		{	

			/*Se elemento atual for maior ou igual ao proximo elemento
				* serão somados e adicionado em uma variavel de incremento*/	
			if(arabico[i] >= arabico[i + 1])
			{
				numero_maior = (arabico[i] + arabico[i + 1]);
				soma_maior += numero_maior;
			
			}
			/*Caso contratrio, elemento atual menor que proximo
				* será feito uma subtração do proximo elemento menos o atual*/
			else
			{
				numero_menor = (arabico[i + 1] - arabico[i]);
				soma_menor += numero_menor;

			}
		}
		/*Variavel final recebe todo valor das condições anteriores
			* somando as variaveis soma_maior e soma_menor*/
		final = (primeiro + soma_maior + soma_menor);

		/*Retorna o valor total*/
		return final;	
	}
}

/*Função que verifica se o algarismo romano 'I' está correto
	* levando em consideração: I, II, III
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro*/
unsigned int verifica_I(char romano[])
{
	/*Variaveis de incremento*/	
	int i = 0, cont = 0;

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido  = 0;

	/*Percorre toda o vetor e conta quantas vezes
		* o algarismo 'I' foi encontrado*/
	for(i = 0; i < strlen(romano); i++)
	{
		if(romano[i] == 'I')
		{	
			cont++;
		}	
	}

	/*Caso o contador seja igual a 3 e
		* e o próximo elemento depois do ultimo
		* 'I' for diferente do '\o'
		* o algarismo esta incorreto*/
	if(cont == 3 && romano[3] != '\0')
	{
		
		valido = -1;
	}

	/*Caso o contador seja igual a 2 e
		* e o próximo elemento depois do ultimo
		* 'I' for diferente do '\o'
		* o algarismo esta incorreto*/
	else if(cont == 2 && romano[2] != '\0')
	{
		
		/*Apenas valida a expressao*/
		valido = -1;
	}

	/*Caso o contador seja igual a 1 e
		* ele entra dentro do outro laço
		* para ser analisado as outras
		* condições*/
	else if(cont == 1)
	{
		/*Se o próximo elemento, depois
			* do ultimo 'I' for igual
			* a '\0', ele não faz nada
			* esse comando apenas faz a verificação*/
		if(romano[1] == '\0')
		{
			/*Apenas valida a expressão*/
			valido = 0;
		}

		/*Se o próximo elemento, depois
			* do ultimo 'I' for igual
			* a 'V' e, o elemento depois dele 
			* for igaul a '0\'ele não faz nada
			* esse comando apenas faz a verificação*/
		else if(romano[1] == 'V' && romano[2] == '\0')
		{
			/*Apenas valida a expressao*/
			valido = 0;
		}

		/*Se o próximo elemento, depois
			* do ultimo 'I' for igual
			* a 'X' e, o elemento depois dele 
			* for igaul a '0\'ele não faz nada
			* esse comando apenas faz a verificação*/
		else if(romano[1] == 'X' && romano[2] == '\0')
		{
			/*Apenas valida a expressao*/
			valido = 0;
		}
		/*Caso todas as condições anteriores forem falsas
			* ele entra nesse "else"*/
		else
		{	
			
			/*Apenas valida a expressao*/
			valido = -1;
		}

	}
	/*Caso o numero de algarismo 'I'
		* for maior que 3, o algarismo
		* tambpem sera invallido*/
	else if(cont > 3)
	{
		
		/*Apenas valida a expressao*/
		valido = -1;
	}

	return valido;
}
