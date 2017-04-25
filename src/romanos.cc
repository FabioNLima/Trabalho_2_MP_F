/*Programa para converte algarismo Romanos em Indo-Arábico*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "romanos.h"

unsigned int verifica_L(char romano[], int vezes);
unsigned int verifica_C(char romano[], int vezes);
unsigned int verifica_D(char romano[], int vezes);

/*Função que verifica o tamanho do vetor de inteiro
	* redecebe como parâmetro de entrada um vetor
	* e retorna o tamanho dele*/
int tam_vet(int *vetor)
{
	int i =0 ;
	while(vetor[i]!=0)
		i++;
	return i;
}


/*Função responsável pela conversão do vetor romano para arabico
	* e também responsável pelo valor da soma
	* essa função só é executada caso o algarismo
	* passe na verificação e for verdadeiro*/
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
				/*Senão será subtraido o próximo número do número atual*/
				numero_menor = (arabico[i + 1] - arabico[i]);

				/*Recebe o resultado da operação*/
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
				/*Senão será subtraido o próximo número do número atual*/
				numero_menor = (arabico[i + 1] - arabico[i]);

				/*Recebe o resultado da operação*/
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
	* a função retorna -1*/
unsigned int verifica_I(char romano[])
{
	/*Variaveis de incremento*/	
	int i = 0, cont = 0;

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido = 0;

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
		/*Nesse caso, podemos imaginar que o valor
			* digitado seria "IIII" que causaria erroa
			* e a variável valido recebe o valor -1*/
		valido = -1;
	}

	/*Caso o contador seja igual a 2 e
		* e o próximo elemento depois do ultimo
		* 'I' for diferente do '\o'
		* o algarismo esta incorreto*/
	else if(cont == 2 && romano[2] != '\0')
	{
		/*Nesse caso, podemos imaginar que o valor
			* digitado seria "IIV" que causaria erroa
			* e a variável valido recebe o valor -1*/
		valido = -1;
	}

	/*Caso o contador seja igual a 1
		* ele entra dentro do outro laço
		* para ser analisado as outras
		* condições*/
	else if(cont == 1)
	{
		/*Se o próximo elemento, depois
			* do ultimo 'I' for igual
			* a '\0', ele não faz nada
			* esse comando apenas faz a verificação verdadeira*/
		if(romano[1] == '\0')
		{
			/*Apenas valida a expressão*/
			valido = 0;
		}

		/*Se o próximo elemento, depois
			* do ultimo 'I' for igual
			* a 'V' e, o elemento depois dele 
			* for igaul a '0\'ele não faz nada
			* esse comando apenas faz a verificação verdadeira*/
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
			* ele entra nesse informando que 
			* foi digitado um algarismo invalido*/
		else
		{	
			/*Nesse caso, podemos imaginar que o valor
			* digitado seria diferente de "I" que causaria erro
			* e a variável valido recebe o valor -1*/
			valido = -1;
		}

	}
	/*Caso o numero de algarismo 'I'
		* for maior que 3, o algarismo
		* tambpem sera invallido*/
	else if(cont > 3)
	{
		/*Nesse caso, o contador execeu o valor de 3
			* e a variável valido recebe o valor -1*/
		valido = -1;
	}

	/*Retorna o valor 0 para verdadeiro ou -1 para falso*/
	return valido;
}


/*Função que verifica se o algarismo romano 'V' está correto
	* levando em consideração: IV, V, VI, VII, VIII
	* caso as alternativas seja diferentes das apresentada
	* a função retorna -1, caso contrário retorna 0*/
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
		* a partir da posição 1, assumindo que
		* os únicos algarismo que podem entrar são o "I" e "V"*/
	for(i = 0; i < strlen(romano); i++)
	{
		auxiliar_I[i] = romano[i + 1];
	}

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição são imoprtantes*/
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
					/*Cahamada para a função verifica_I*/
					valido = verifica_I(auxiliar_I);
					break;
				case '\0':
					/*Não realiza nenhuma operação*/
					break;
				default:
					/*Caso contrário a variável valido recebe
						* o valor -1*/
					valido = -1;
			}	
		}
		/*Caso qualquer algarismo digitado
			* não seja 'V
			* ele entra nessa verifica
			* para informar que está incorreto*/
		else
		{
			/*Recebe o valor -1 para informar que 
			* o algarismo digitado está invalido*/
			valido = -1;
		}
	}

	/*Retorna o valor 0 para verdadeiro ou -1 para falso*/
	return valido;
	
}

/*Função que verifica se o algarismo romano 'X' está correto
	* levando em consideração: IX, X, XI, XII, XIII, XIV
	* XVI, XVII, XVIII, XIX, XX, ....
	* caso as alternativas seja diferentes das apresentada
	* a função retorna -1, caso contrário retorna 0
	* recebe como paramentro além do vetor
	* uma variavel inteira, que será o contador
	* de acesso quando essa função for chamada
	*Serve para validar o "X" já que ele pode aparecer no máximo
	* 3 vezes*/
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

	/*Como o programa funciona com recursividade
		* numero maiores que primeiro = 'X'
		* passarão nesse laço para um analise
		* de correção*/
	for (i = 0; i < strlen(romano); ++i)
	{
		if(romano[i] == 'C')
		{
			/*Se depois do algarismo "X" for digitado o "C"
				* o mesmo só pode aparecer um vez depois do 
				* "X*, caso contrário está errado*/
			contador_C++;
		}

		else if(romano[i] == 'L')
		{
			/*Se depois do algarismo "X" for digitado o "L"
				* o mesmo só pode aparecer um vez depois do 
				* "X*, caso contrário está errado*/
			contador_L++;
		}
	}

	/*Verifica a condição para que
		* o algarismo 'X' não seja digitado
		* mais de 3 vezes.
		* condições aceita: 'X', 'XX' e 'XXX'*/
	if(cont_X > 3)
	{
		/*Valido recebe o valor -1
			*informando que o algarismo está invalido*/
		valido = -1;
	}

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição*/
	for(i = 0; i < 1; i++)
	{
		/*Se a primeira posição for 'X'
			* entra no laço*/
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
					/*Cahamada para a função verifica_I*/
					valido = verifica_I(auxiliar_I);
					break;
				case 'V':
					/*Chamada para a função verifica_V*/
					valido = verifica_V(auxiliar_V);
					break;
				case 'X':
					/*Incremento responsável por valida
						* o número máximo que "X" pode ter
						* no caso 3*/
					soma_X += cont_X;
					/*Chamada para a função verifica_X*/
					valido = verifica_X(auxiliar_X, soma_X);
					break;
				case 'L':
					/*Chamada para a função verifica_L*/
					valido = verifica_L(auxiliar_L,cont_L);
					break;
				case 'C':
					/*Não realiza nenhuma operação
						* pois "C" só precisa passar na verificação
						* para depois ser convertido*/
					break;
				case '\0':
					/*Não realiza nenhuma operação*/
					break;
				default:
					/*Caso contrário a variável valido recebe
						* o valor -1*/
					valido = -1;
			}
		}

		/*Senão se a primeira posição for 'L'
			* entra no laço*/
		else if(romano[i] == 'L')
		{	
			/*Chamada para a função verifica_L*/
			valido = verifica_L(romano, cont_L);
		}

		/*Caso qualquer algarismo digitado que
			* não seja 'X'
			* está incorreto*/
		else
		{
			/*Recebe o valor -1*/
			valido = -1;
		}
	}

	/*Verifica a condição para que
		* o algarismo 'X' não seja digitado
		* mais de 3 vezes.
		* condições aceita: 'X', 'XX' e 'XXX'*/
	if(cont_X > 3)
	{
		/*Valido recebe o valor -1*/
		valido = -1;
	}

	/*Verifica a condição para que
		* o algarismo 'C' não seja digitado
		* mais de 2 vezes.
		* condições aceita: 'XC'*/
	else if(contador_C > 1)
	{
		/*Recebe o valor -1
			* confirmando o algarismo errado*/
		valido = -1;
	}

	/*Verifica a condição para que
		* o algarismo 'L' não seja digitado
		* mais de 1 vezes.
		* condições aceita: 'XL'*/
	else if(contador_L > 1)
	{
		/*Recebe o valor -1
			* confirmando o algarismo errado*/
		valido = -1;
	}

	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;
}

/*Função que verifica se o algarismo romano 'L' está correto
	* levando em consideração: XL, L, LX, LXX, LVI...
	* caso as alternativas seja diferentes das apresentada
	* a função retorna -1, caso contrário retorna 0
	* recebe como paramentro além do vetor
	* uma variavel inteira que será o contador
	* de acesso quando essa função for chamada
	*Serve para validar o "L" já que ele pode aparecer no máximo
	* 1 vezes. Também server para contador de outras variaveis*/
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
		/*Recebe o valor -1, pois "L" foi
			* digitado mais de 1 vez*/
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
					/*chamada para a função verifica_I*/
					valido = verifica_I(auxiliar_I);
					break;
				case 'V':
					/*Chamada para a função verifica_V*/
					valido = verifica_V(auxiliar_V);
					break;
				case 'X':
					/*Chamada para a função verifica_X*/
					valido = verifica_X(auxiliar_X,cont_X);
					break;
				case 'L':
					/*Incrmento para verificar a condição do
						*"L", que pode ser digitado apenas 1 vez*/
					soma_L += cont_L;
					/*Chamada para a função verifica_L*/
					valido = verifica_L(auxiliar_L, soma_L);
				case '\0':
					/*Não realiza nenhuma operação*/
					break;
				default:
					/*Se nenhuma das opções acima são válidas
						* valido recebe -1*/
					valido = -1;
			}
		}

		/*Senão se a primeira posição for 'I'
			* entra no laço*/
		else if(romano[i] == 'I')
		{	
			/*Chamada para a função verifica_I*/
			valido = verifica_I(romano);
		}

		/*Senão se a primeira posição for 'V'
			* entra no laço*/
		else if(romano[i] == 'V')
		{
			/*Chamada para a função verifica_V*/
			valido = verifica_V(romano);
		}

		/*Senão se a primeira posição for 'X'
			* entra no laço*/
		else if(romano[i] == 'X')
		{
			/*Chamada para a função verifica_X*/
			valido = verifica_X(romano, cont_X);
		}

		/*Senão se a primeira posição for 'L'
			* entra no laço*/
		else if(romano[i] == 'L')
		{
			/*Chamada para a função verifica_L*/
			valido = verifica_L(romano, cont_L);
		}

		/*Caso qualquer algarismo digitado que
			* não seja 'L'
			* está incorreto*/
		else
		{
			/*Valido recebe o valor -1*/
			valido = -1;
		}
	}

	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;
}

/*Função que verifica se o algarismo romano 'C' está correto
	* levando em consideração: XC, C, CC, CCC, CL, ...
	* caso as alternativas seja diferentes das apresentada
	* a função retorna -1, caso contrário retorna 0
	* recebe como paramentro além do vetor
	* uma variavel inteira que servirá de contador para
	* verificar a condição de "C" aparecer 3 vezes*/
unsigned int verifica_C(char romano[], int vezes)
{
	/*Variaveis de incremento*/
	int i = 0, cont_X = 0, cont_C = 0, cont_D = 0, cont_M = 0; 

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido = 0;

	/*Variavel responsavel por verificar
		* se o algarismo 'X' aceita apenas
		* essas condições: X, XX, XXX
		* e o algarismo 'C' aceita apenas
		* essas condições: 'C', 'CC' e 'CCC'*/
	int soma_X = 1, soma_C = 1;

	/*Recebe o valor do paramentro da função
		* que sera somado com a variavel soma_X
		* e soma_X*/
	cont_X = vezes;
	cont_C = vezes;
	cont_D = vezes;
	cont_M = vezes;

	/*Vetores auxiliares para realizar a analise
		* se o seu primeiro elemento corresponde
		* as condições verdadeiras*/
	char auxiliar_I[29], auxiliar_V[29], auxiliar_X[29], auxiliar_L[29], auxiliar_C[29], auxiliar_D[29], auxiliar_M[29];

	/*Variavel que conterá a primeira posição
		* do vetor para ser analisado
		* se realmente contem o algarismo 'I', 'V', 'X', 'L', 'C', 'M' e '\0'
		* ou '\o' que são condições verdadeiras*/
	char algarismo;

	/*Os vetores auxiliar_I, auxiliar_V e auxiliar_X, auxiliar_L
		* auxiliar_C e auxiliar_M
		* recebem todos os elementos do vetor romano
		* a partir da posição 1*/
	for(i = 0; i < strlen(romano); i++)
	{		
		auxiliar_I[i] = romano[i + 1];
		auxiliar_V[i] = romano[i + 1];
		auxiliar_X[i] = romano[i + 1];
		auxiliar_L[i] = romano[i + 1];
		auxiliar_C[i] = romano[i + 1];
		auxiliar_D[i] = romano[i + 1];
		auxiliar_M[i] = romano[i + 1];
	}
	
	/*Verifica a condição para que
		* o algarismo 'C' não seja digitado
		* mais de 3 vezes.
		* condições aceita: 'C'*/
	if(cont_C > 3)
	{
		/*Valido recebe o valor -1*/
		valido = -1;
	}

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição*/
	for(i = 0; i < 1; i++)
	{
		/*Se a primeira posição for 'C'
			* entra no laço*/
		if (romano[i] == 'C')
		{
			/*Variavel que recebe a proxima posição
				* do vetor*/	
			algarismo = romano[i + 1];

			/*Laço que ira analisar as condições
				* para o que o algarismo esteja 
				* correto
				* Nesse caso sera 'I', 'V', 'X', 'L', 'C', 'M'e '\0'*/
			switch(algarismo)
			{
				case 'I':
					/*Chamada para a função verifica_I*/
					valido = verifica_I(auxiliar_I);
					break;
				case 'V':
					/*Chamada para a função verifica_V*/
					valido = verifica_V(auxiliar_V);
					break;
				case 'X':
					/*Chamada para a função verifica_X*/
					valido = verifica_X(auxiliar_X, cont_X);
					break;
				case 'L':
					/*Chamada para a função verifica_L*/
					valido = verifica_L(auxiliar_L, 1);
					break;
				case 'C':
					/*Incremento para verificar a condição
						* verdadeira que "C" não pode ser
						* digitado mais de 3 vezes*/
					soma_C += cont_C;
					/*Chamada para a função verifica_C*/
					valido = verifica_C(auxiliar_C, soma_C);
					break;
				case 'D':
					/*Chamada para a função verifica_D*/
					valido = verifica_D(auxiliar_D, cont_D);
					break;
				case 'M':
					/*Não realiza operação, apenas verifica a condição
						* se aparecer apenas 1 vez segue para a conversão*/
					break;
				case '\0':
					/*Não realiza nenhuma operação*/
					break;
				default:
					/*Caso nenhuma das opção acima forem válidas
						* valido recebe o valor -1*/
					valido = -1;
			}
		}
		
		/*Senão se a primeira posição for 'I'
			* entra no laço*/
		else if(romano[i] == 'I')
		{	
			/*Chamada para a função verifica_I*/
			valido = verifica_I(romano);
		}

		/*Senão se a primeira posição for 'V'
			* entra no laço*/
		else if(romano[i] == 'V')
		{
			/*Chamada para a função verifica_V*/
			valido = verifica_V(romano);
		}

		/*Senão se a primeira posição for 'X'
			* entra no laço*/
		else if(romano[i] == 'X')
		{
			/*Chamada para a função verifica_X*/
			valido = verifica_X(romano, cont_X);
		}

		/*Senão se a primeira posição for 'L'
			* entra no laço*/
		else if(romano[i] == 'L')
		{
			/*Chamada para a função verifica_L*/
			valido = verifica_L(romano, 1);
		}

		/*Senão se a primeira posição for 'D'
			* entra no laço*/
		else if(romano[i] == 'D')
		{
			/*Chamada para a função verifica_D*/
			valido = verifica_D(auxiliar_D, cont_D);
		}

		/*Senão se algarismo invalido*/
		else
		{
			/*Se nenhuma das opções acima são validas
				* valido recebe o valor -1*/
			valido = -1;
		}	
	}

	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;	
}

/*Função que verifica se o algarismo romano 'C' está correto
	* levando em consideração: D, DC, CD, ...
	* caso as alternativas seja diferentes das apresentada
	* a função retorna o valor -1, caso contrario retorna 0
	* recebe como paramentro além do vetor
	* uma variavel inteira, que servirá de contador
	* parava verificar a condição de ser digitado apenas 1 vez*/
unsigned int verifica_D(char romano[], int vezes)
{
	/*Variaveis de incremento*/
	int i = 0, cont_X = 0, cont_L = 0, cont_C = 0, cont_D  = 0;

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido = 0;

	/*Variavel responsavel por verificar
		* se o algarismo 'X' aceita apenas
		* essas condições: X, XX, XXX
		* e o algarismo 'C' aceita apenas
		* essas condições: 'C', 'CC' e 'CCC'*/
	int soma_X = 1, soma_C = 1, soma_D = 1;

	/*Recebe o valor do paramentro da função
		* que sera somado com a variavel soma_X
		* soma_C
		* Ja cont_L e cont_D, servem apenas para
		* paramentro de entrada*/
	cont_X = vezes;
	cont_L = vezes;
	cont_C = vezes;
	cont_D = vezes;

	/*Vetores auxiliares para realizar a analise
		* se o seu primeiro elemento corresponde
		* as condições verdadeiras*/
	char auxiliar_I[29], auxiliar_V[29], auxiliar_X[29], auxiliar_L[29], auxiliar_C[29], auxiliar_D[29];

	/*Variavel que conterá a primeira posição
		* do vetor para ser analisado
		* se realmente contem o algarismo 'I', 'V', 'X', 'L', 'C' e '\0'
		* ou '\o' que são condições verdadeiras*/
	char algarismo;

	/*Os vetores auxiliar_I, auxiliar_V e auxiliar_X, auxiliar_L
		* auxiliar_C
		* recebem todos os elementos do vetor romano
		* a partir da posição 1*/
	for(i = 0; i < strlen(romano); i++)
	{		
		auxiliar_I[i] = romano[i + 1];
		auxiliar_V[i] = romano[i + 1];
		auxiliar_X[i] = romano[i + 1];
		auxiliar_L[i] = romano[i + 1];
		auxiliar_C[i] = romano[i + 1];
		auxiliar_D[i] = romano[i + 1];
	}
	
	/*Verifica a condição para que
		* o algarismo 'D' não seja digitado
		* mais de 1 vezes.
		* condições aceita: 'D'*/
	if(cont_D > 1)
	{
		/*Valido recebe o valor -1*/
		valido = -1;
	}

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição*/
	for(i = 0; i < 1; i++)
	{
		/*Se a primeira posição for 'D'
			* entra no laço*/
		if (romano[i] == 'D')
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
					/*Chamada para a função verifica_I*/
					valido = verifica_I(auxiliar_I);
					break;
				case 'V':
					/*Chamada para a função verifica_V*/
					valido = verifica_V(auxiliar_V);
					break;
				case 'X':
					/*Chamada para a função verifica_X*/
					valido = verifica_X(auxiliar_X, soma_X);
					break;
				case 'L':
					/*Chamada para a função verifica_L*/
					valido = verifica_L(auxiliar_L, cont_L);
					break;
				case 'C':
					/*Chamada para a função verifica_C*/
					valido = verifica_C(auxiliar_C, soma_C);
					break;
				case 'D':
					/*Incremento para verificar a validação de
						* "D" ser digitado 1 vez*/
					soma_D += cont_D;
					/*Chamada para a função verifica_D*/
					valido = verifica_D(auxiliar_D, soma_D);
					break;
				case '\0':
					/*Não realiza nenhume operação*/
					break;
				default:
					/*Caso nenhuma das opção acima forem válidas
						* valido recebe o valor -1*/
					valido = -1;
			}
		}

		/*Senão se a primeira posição for 'I'
			* entra no laço*/
		else if(romano[i] == 'I')
		{
			/*Chamada para a função verifica_I*/
			valido = verifica_I(romano);
		}

		/*Senão se a primeira posição for 'V'
			* entra no laço*/
		else if(romano[i] == 'V')
		{
			/*Chamada para a função verifica_V*/
			valido = verifica_V(romano);
		}

		/*Senão se a primeira posição for 'X'
			* entra no laço*/
		else if(romano[i] == 'X')
		{
			/*Chamada para a função verifica_X*/
			valido = verifica_X(romano, cont_X);
		}

		/*Senão se a primeira posição for 'L'
			* entra no laço*/
		else if(romano[i] == 'L')
		{
			/*Chamada para a função verifica_L*/
			valido = verifica_L(romano, 1);
		}

		else if(romano[i] == 'C')
		{
			/*Chamada para a função verifica_C*/
			valido = verifica_C(romano, cont_C);
		}

		else if(romano[i] == 'D')
		{
			/*Chamada para a função verifica_I*/
			valido = verifica_D(romano, cont_D);
		}

		/*Senão se algarismo invalido*/
		else
		{
			/*Caso nenhume das opções forem válidas
				* valido recebe o valor -1*/
			valido = -1;
		}
	}

	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;	
}


/*Função que verifica se o algarismo romano 'C' está correto
	* levando em consideração: M, CM, MC, MM, MMCMLXXXVIII ...
	* caso as alternativas seja diferentes das apresentada
	* a função retorna -1, caso contrário retorna 0
	* recebe como paramentro além do vetor
	* uma variavel inteira que será contador
	* para analise de validação*/
unsigned int verifica_M(char romano[], int vezes)
{
	/*Variaveis de incremento*/
	int i, cont_M = 0, soma = 1;

	/*Variavel reponsável para verificar a validação da expressão
		* caso seja valido, recebe 0
		* senão, recebe -1*/
	int valido = 0;
	
	/*Variavel responsavel por verificar
		* se o algarismo 'M' aceita apenas
		* essas condições: M, MM, MMM*/
	int soma_M = 1;   	

	/*Recebe o valor do paramentro da função
		* que sera somado com a variavel soma_M*/
	cont_M = vezes;

	/*Vetores auxiliares para realizar a analise
		* se o seu primeiro elemento corresponde
		* as condições verdadeiras*/
	char auxiliar_I[29], auxiliar_V[29], auxiliar_X[29], auxiliar_L[29], auxiliar_C[29], auxiliar_D[29], auxiliar_M[29];

	/*Variavel que conterá a primeira posição
		* do vetor para ser analisado
		* se realmente contem o algarismo 'I', 'V', 'X', 'L', 'C', 'D', 'M' e '\0'
		* ou '\o' que são condições verdadeiras*/
	char algarismo;

	/*Os vetores auxiliar_I, auxiliar_V e auxiliar_X, auxiliar_L
		* auxiliar_C, auxiliar_D, auxiliar_M
		* recebem todos os elementos do vetor romano
		* a partir da posição 1*/
	for(i = 0; i < strlen(romano); i++)
	{		
		auxiliar_I[i] = romano[i + 1];
		auxiliar_V[i] = romano[i + 1];
		auxiliar_X[i] = romano[i + 1];
		auxiliar_L[i] = romano[i + 1];
		auxiliar_C[i] = romano[i + 1];
		auxiliar_D[i] = romano[i + 1];
		auxiliar_M[i] = romano[i + 1];
	}
	
	/*Verifica a condição para que
		* o algarismo 'M' não seja digitado
		* mais de 4 vezes.
		* condições aceita: 'M'*/
	if(cont_M > 4)
	{	
		/*Valido recebe valor -1*/
		valido =  -1;
	}
	else
	{	
		/*valido recebe o valor 0*/
		valido =  0 ;
	}		

	/*Nesse laço, não precisamos percorrer
		* todo o vetor, apenas a primeira
		* e segunda posição*/
	for(i = 0; i < 1; i++)
	{

		/*Se a primeira posição for 'M'
			* entra no laço*/
		if (romano[i] == 'M')
		{
			/*Primeiro incremento para verificar
				* as condições: M, MM, MMM*/
			soma_M += cont_M;

			/*Variavel que recebe a proxima posição
				* do vetor*/	
			algarismo = romano[i + 1];

			/*Laço que ira analisar as condições
				* para o que o algarismo esteja 
				* correto
				* Nesse caso sera 'I', 'V', 'X', 'L', 'C', 'D', 'M' e '\0'*/
			switch(algarismo)
			{
				case 'I':
					/*Chamada para a função verifica_I*/
					verifica_I(auxiliar_I);
					break;
				case 'V':
					/*Chamada para a função verifica_V*/
					verifica_V(auxiliar_V);
					break;
				case 'X':
					/*Chamada para a função verifica_X*/
					verifica_X(auxiliar_X, 1);
					break;
				case 'L':
					/*Chamada para a função verifica_L*/
					verifica_L(auxiliar_L, 1);
					break;
				case 'C':
					/*Chamada para a função verifica_C*/
					verifica_C(auxiliar_C, 1);
					break;
				case 'D':
					/*Chamada para a função verifica_D*/
					verifica_D(auxiliar_D, 1);
				case 'M':
					/*Incremento responsável pela validação
						* de "M" que pode ser digitado 3 vezes*/
					soma_M++;
					/*Chamada para a função verifica_M*/
					valido = verifica_M(auxiliar_M, soma_M);
				case '\0':
					/*Não realiza nenhuma operação*/
					break;
				default:
					/*Caso nenhuma das opção acima forem válidas
						* valido recebe o valor -1*/
					valido = -1;
			}
		}
		/*Senão se a primeira posição for 'I'
			* entra no laço*/
		else if(romano[i] == 'I')
		{
			/*Chamada para a função verifica_I*/
			valido = verifica_I(romano);
		}

		/*Senão se a primeira posição for 'V'
			* entra no laço*/
		else if(romano[i] == 'V')
		{
			/*Chamada para a função verifica_V*/
			valido = verifica_V(romano);
		}

		/*Senão se a primeira posição for 'X'
			* entra no laço*/
		else if(romano[i] == 'X')
		{
			/*Chamada para a função verifica_X*/
			valido = verifica_X(romano, 1);
		}

		/*Senão se a primeira posição for 'L'
			* entra no laço*/
		else if(romano[i] == 'L')
		{
			/*Chamada para a função verifica_L*/
			valido = verifica_L(romano, 1);
		}

		/*Senão se a primeira posição for 'C'
			* entra no laço*/
		else if(romano[i] == 'C')
		{
			/*Chamada para a função verifica_C*/
			valido = verifica_C(romano, 1);
		}

		/*Senão se a primeira posição for 'D'
			* entra no laço*/
		else if(romano[i] == 'D')
		{
			/*Chamada para a função verifica_D*/
			valido = verifica_D(romano, 1);
		}

		/*Se nenhum algarismo acima for digitado
			* acredita-se que ele está incorreto*/
		else
		{	
			/*Caso nenhume das opções forem válidas
				* valido recebe o valor -1*/
			valido = -1;
		}	
	}
	/*Retorna valido: se 0 algarismo valido
		* senão retorna -1*/
	return valido;
}
