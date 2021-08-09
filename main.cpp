#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "TAD.h"

void Estacao(TpPilha &P)
{
	FILE *vagao = fopen("Entrada.txt", "r");
	FILE *saida = fopen("Saida.txt", "w");

	inicializarPilha(P);
	int i = 0, tl = 0, j = 0, p = 1, vet[MaxP], sai[MaxP];
	char sequencia[MaxP];
	char aux[MaxP];

	
	while(!pilhaCheia(P))
	{
		tl=0;
		fgets(aux, MaxP, vagao); // quantidade de vagões
		//		if(strcmp(aux,"0") != 0)
		fgets(sequencia, MaxP, vagao); // sequencia dos vagões
		for(i = 0; i < strlen(sequencia) - 1; i++)
		{
			vet[i] += i + 1; // numero de vagões
			tl++;
		}
		i = 0;
		inserirPilha(P, vet[i]);
		while(i < tl)
		{
			while(elemento(P) == sequencia[j] - 48) //SE O TOPO É IGUAL A SEQUENCIA DESEJADA
			{
				sai[j] = removerPilha(P); // RECEBE O ELEMENTO NA SEQUENCIA DA SAIDAs
				j++;
			}
			i++;
			inserirPilha(P, vet[i]);
		}
		for(i = 0; i < tl; i++)
		{
			if(sai[i] != sequencia[i] - 48)
				p = 0;
		}
		if(p == 1)
		{
			strcat(sequencia, "Yes");
			fputs(sequencia, saida);
		}
		else
		{
			strcat(sequencia, "No");
			fputs(sequencia, saida);
		}

	}


	fclose(vagao);
	fclose(saida);
}
int main(void)
{
	TpPilha P;
	Estacao(P);

	return 0;
}
