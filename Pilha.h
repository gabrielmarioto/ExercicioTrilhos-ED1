#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define maxpilha 100
struct tpilhas
{
	char pilha[maxpilha][100];
	int topo;	
};

struct tpilha
{
	char pilha[maxpilha];
	int topo;	
};

//1º passo: Inicializar  void inicializar(tpilha &pilha);
void inicializa(tpilhas &p)
{
	p.topo=-1;
}

void inicializar(tpilha &p)
{
	p.topo=-1;
}

char cheia(int topo)
{
	return topo==maxpilha-1; //if(topo==maxpilha-1) return 1; else return 0;
}

char vazia(int topo)
{
	return topo==-1; //if(topo==-1) return 1; else return 0;
}
void inserir(tpilha &p, int ele)
{
	p.topo++;
	p.pilha[p.topo]=ele;
}
char retirar(tpilha &p)
{	
	return p.pilha[p.topo--];
}

char eletopo(tpilha p)
{
	return p.pilha[p.topo];
}

void exibir(tpilha p)
{
	while(!vazia(p.topo))
		printf("\n %d",retirar(p)-48);
}
void exp_pol()
{
	char l,l1,l2;
	
	tpilha paux;
	inicializar(paux);
	
	printf("Informe o elemento da expressão:\n");
	l=getche();
	
	while(l!=13)
	{		
		if(l=='*' || l=='/' || l=='+' || l=='-')
		{
			if(!vazia(paux.topo))
			{
				l1=retirar(paux);
			
				if(!vazia(paux.topo))
				{
					l2=retirar(paux);
					
					if(l=='*')
						inserir(paux,l2*l1);		
					
					else if(l=='/')
						inserir(paux,l2/l1);
			
					else if(l=='+')
						inserir(paux,l2+l1);
				
					else
						inserir(paux,l2-l1);
				}
				else
					printf("Pilha vazia!!\n");
			}
			else
				printf("Pilha vazia!!\n");	
			
		}
		else
			inserir(paux,l-48);
		
		fflush(stdin);
		l=getche();

	}
	
	printf("\n\n**Resultado da expressao**");
	exibir(paux);
}

