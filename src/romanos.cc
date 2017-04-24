/*Programa para converte algarismo Romanos em Indo-Arábico*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "romanos.h"

unsigned int verifica_L(char romano[], int vezes);

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
	int valido;

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
		printf("algarismo invalido I \n");
		valido = -1;
	}

	/*Caso o contador seja igual a 2 e
		* e o próximo elemento depois do ultimo
		* 'I' for diferente do '\o'
		* o algarismo esta incorreto*/
	else if(cont == 2 && romano[2] != '\0')
	{
		printf("algarismo invalido I \n");
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
			printf("algarismo invalido I \n");
			/*Apenas valida a expressao*/
			valido = -1;
		}

	}
	/*Caso o numero de algarismo 'I'
		* for maior que 3, o algarismo
		* tambpem sera invallido*/
	else if(cont > 3)
	{
		printf("algarismo invalido I \n");
		/*Apenas valida a expressao*/
		valido = -1;
	}

	return valido;
}


/*Função que verifica se o algarismo romano 'V' está correto
	* levando em consideração: IV, V, VI, VII, VIII
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro*/
unsigned int verifica_V(char romano[])
{
	/*Variaveis de incremento*/
	int i, cont = 0;

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido = 0;

	/*Vetor de caracteres que contera
		* todos os algarismo 'I'
		* caso seja digitado após o algarismo 'V'*/
	char auxiliar_I[29];

	/*Variavel que conterá a primeira posição
		* do vetor para ser analisado
		* se realmente contem o algarismo 'I'
		* ou '\o' que são condições verdadeiras*/
	char algarismo;


	/*O vetor auxiliar_I recebe todos
		* os elementos do vetor romano
		* a partir da posição 1*/
	for(i = 0; i < strlen(romano); i++)
	{
		auxiliar_I[i] = romano[i + 1];
	}

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição*/
	for(i = 0; i < 1; i++)
	{
		/*Se a primeira posição for 'V'
			* entra no laço*/	
		if(romano[i] == 'V')
		{
			/*Variavel que recebe a proxima posição
				* do vetor*/
			algarismo = romano[i + 1];

			/*Laço que ira analisar as condições
				* para o que o algarismo esteja 
				* correto
				* Nesse caso sera 'I' e '\0'*/
			switch(algarismo)
			{
				case 'I':
					valido = verifica_I(auxiliar_I);
					break;
				case '\0':
					break;
				default:
					printf("algarismo invalido V\n");
					valido = -1;
			}	
		}
		/*Caso qualquer algarismo que
			* não seja 'V
			* está incorreto*/
		else
		{
			printf("algarismo invalido V \n");

			/*Apenas valida a expressao*/
			valido = -1;
		}
	}

	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;
	
}

/*Função que verifica se o algarismo romano 'X' está correto
	* levando em consideração: IX, X, XI, XII, XIII, XIV
	* XVI, XVII, XVIII, XIX, XX, ....
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro
	* recebe como paramentro além do vetor
	* uma variavel inteira*/
unsigned int verifica_X(char romano[], int vezes)
{
	/*Variaveis de incremento*/
	int i, cont_X = 0, cont_L = 0, contador_C = 0, contador_L = 0;;

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido = 0;

	/*Variavel responsavel por verificar
		* se o algarismo 'X' aceita apenas
		* essas condições: X, XX, XXX*/
	int soma_X = 1;

	/*Recebe o valor do paramentro da função
		* que sera somado com a variavel soma_X*/
	cont_X = vezes;
	cont_L = vezes;

	/*Vetores auxiliares para realizar a analise
		* se o seu primeiro elemento corresponde
		* as condições verdadeiras*/
	char auxiliar_I[29], auxiliar_V[29], auxiliar_X[29], auxiliar_L[29];
	
	/*Variavel que conterá a primeira posição
		* do vetor para ser analisado
		* se realmente contem o algarismo 'I', 'V', 'X'
		* 'L', 'C' ou '\o' que são condições verdadeiras*/
	char algarismo;

	/*Os vetores auxiliar_I, auxiliar_V e auxiliar_X 
		* recebem todos os elementos do vetor romano
		* a partir da posição 1*/
	for(i = 0; i < strlen(romano); i++)
	{
		auxiliar_I[i] = romano[i + 1];
		auxiliar_V[i] = romano[i + 1];
		auxiliar_X[i] = romano[i + 1];
		auxiliar_L[i] = romano[i + 1];
	}


	/*Como o programa funciona com recursividade e ainda não está terminado
		* numero maiores que primeiro = 'X'
		* passarão nesse laço para um analise
		* de correção*/
	for (i = 0; i < strlen(romano); ++i)
	{
		if(romano[i] == 'C')
		{
			contador_C++;
		}
		else if(romano[i] == 'L')
		{
			contador_L++;
		}
	}


	/*Verifica a condição para que
		* o algarismo 'X' não seja digitado
		* mais de 3 vezes.
		* condições aceita: 'X', 'XX' e 'XXX'*/
	if(cont_X > 3)
	{
		printf("algarismo invalido XXX \n");
		valido = -1;
	}

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição*/
	for(i = 0; i < 1; i++)
	{
		/*Se a primeira posição for 'X'
			* entra no laço*/
		printf("%c\n\n\n", romano[i]);
		if(romano[i] == 'X')
		{
			/*Variavel que recebe a proxima posição
				* do vetor*/
			algarismo = romano[i + 1];

			/*Laço que ira analisar as condições
				* para o que o algarismo esteja 
				* correto
				* Nesse caso sera 'I', 'V', 'X', 'L', 'C' e '\0'*/
			switch(algarismo)
			{
				case 'I':
					valido = verifica_I(auxiliar_I);
					break;
				case 'V':
					valido = verifica_V(auxiliar_V);
					break;
				case 'X':
					soma_X += cont_X;
					valido = verifica_X(auxiliar_X, soma_X);
					break;
				case 'L':
					valido = verifica_L(auxiliar_L,cont_L);
					break;
				case 'C':
					break;
				case '\0':
					break;
				default:
					printf("algarismo invalido X BREAK\n");
					valido = -1;
			}
		}

		/*Senão se a primeira posição for 'L'
			* entra no laço*/
		else if(romano[i] == 'L')
		{
			valido = verifica_L(romano, cont_L);
		}

		/*Caso qualquer algarismo digitado que
			* não seja 'X'
			* está incorreto*/
		else
		{
			printf("algarismo invalido X UL \n");
			valido = -1;
		}
	}

	/*Verifica a condição para que
		* o algarismo 'X' não seja digitado
		* mais de 3 vezes.
		* condições aceita: 'X', 'XX' e 'XXX'*/
	if(cont_X > 3)
	{
		printf("algarismo invalido 10 \n");
		valido = -1;
	}
	else if(contador_C > 1)
	{
		valido = -1;
	}
	else if(contador_L > 1)
	{
		valido = -1;
	}

	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;
}


/*Função que verifica se o algarismo romano 'L' está correto
	* levando em consideração: XL, L, LX, LXX, LVI...
	* caso as alternativas seja diferentes das apresentada
	* aparecerá uma mensagem de erro
	* recebe como paramentro além do vetor
	* uma variavel inteira*/
unsigned int verifica_L(char romano[], int vezes)
{
	/*Variaveis de incremento*/
	int i = 0, cont_X = 0, cont_L = 0;

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido = 0;

	/*Variavel responsavel por verificar
		* se o algarismo 'L' aceita apenas
		* essas condições: L*/
	int soma_L = 1;

	/*Recebe o valor do paramentro da função
		* que que será verificada para
		* chamar a função verifica_X*/
	cont_X = vezes;

	/*Recebe o valor do paramentro da função
		* que será verificada a condição
		* verdade: 'L' não pode repetir*/
	cont_L = vezes;

	/*Vetores auxiliares para realizar a analise
		* se o seu primeiro elemento corresponde
		* as condições verdadeiras*/
	char auxiliar_I[29], auxiliar_V[29], auxiliar_X[29], auxiliar_L[29];

	/*Variavel que conterá a primeira posição
		* do vetor para ser analisado
		* se realmente contem o algarismo 'I', 'V', 'X'
		* ou '\o' que são condições verdadeiras*/
	char algarismo;

	/*Os vetores auxiliar_I, auxiliar_V e auxiliar_X 
		* recebem todos os elementos do vetor romano
		* a partir da posição 1*/
	for(i = 0; i < strlen(romano); i++)
	{
		auxiliar_I[i] = romano[i + 1];
		auxiliar_V[i] = romano[i + 1];
		auxiliar_X[i] = romano[i + 1];
		auxiliar_L[i] = romano[i + 1];

	}

	/*Verifica a condição para que
		* o algarismo 'L' não seja digitado
		* mais de 1 vezes.
		* condições aceita: 'L'*/
	if(cont_L > 1)
	{
		printf("algarismo invalido L \n");
		valido = -1;
	}

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição*/
	for(i = 0; i < 1; i++)
	{
		/*Se a primeira posição for 'L'
			* entra no laço*/
		if(romano[i] == 'L')
		{
			/*Variavel que recebe a proxima posição
				* do vetor*/
			algarismo = romano[i + 1];

			/*Laço que ira analisar as condições
				* para o que o algarismo esteja 
				* correto
				* Nesse caso sera 'I', 'V', 'X' e '\0'*/
			switch(algarismo)
			{
				case 'I':
					valido = verifica_I(auxiliar_I);
					break;
				case 'V':
					valido = verifica_V(auxiliar_V);
					break;
				case 'X':
					valido = verifica_X(auxiliar_X,cont_X);
					break;
				case 'L':
					soma_L += cont_L;
					valido = verifica_L(auxiliar_L, soma_L);
				case '\0':
					break;
				default:
					printf("algarismo invalido L \n");
					valido = -1;
			}
		}


		/*Senão se a primeira posição for 'I'
			* entra no laço*/
		else if(romano[i] == 'I')
		{
			valido = verifica_I(romano);
		}

		/*Senão se a primeira posição for 'V'
			* entra no laço*/
		else if(romano[i] == 'V')
		{
			valido = verifica_V(romano);
		}

		/*Senão se a primeira posição for 'X'
			* entra no laço*/
		else if(romano[i] == 'X')
		{

			valido = verifica_X(romano,cont_X);
		
		}

		/*Senão se a primeira posição for 'L'
			* entra no laço*/
		else if(romano[i] == 'L')
		{
			valido = verifica_L(romano, cont_L);
		}

		/*Caso qualquer algarismo digitado que
			* não seja 'L'
			* está incorreto*/
		else
		{
			printf("algarismo invalido L \n");
			valido = -1;
		}
	}

	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;
}

/*
int main()
{
	char parada, algarismo[30];
	int decimal;
	int valida_expressao;
	memset(algarismo, 0, 30);
	printf("Programa de conversão de algarismo romanos para indo-arabico!\n");
	printf("O maior algarismo pertimido eh MMM ou 3000!\n");
	printf("Informe os algarismo romanos: ");
	scanf("%s", algarismo);

	valida_expressao = verifica_L(algarismo, 1);

	if(valida_expressao == -1)
	{
		printf("Excedeu o tamanho maximo pertimido!\n");
	}
	else
	{
		decimal = converte(algarismo);
		printf("Resultado sera: %d\n", decimal);	
	}
	

	return 0;
}
*/
