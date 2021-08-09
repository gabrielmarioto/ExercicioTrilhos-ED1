#include "Pilha.h"

void estacao(tpilha p)
{
	FILE *vagao=fopen("trem.txt","r");
	FILE *arq=fopen("temp.txt","w");
	
	char frase[maxpilha],op[4]="YES",nova[maxpilha];
	int cont,maior,i=0;
	
	inicializar(p);
	
	fgets(frase,maxpilha,vagao);
	
	while(!feof(vagao))
	{
		if(strlen(frase)-1==1)
		{
			if(strcmp(frase,"0")==0)
			{
				fgets(frase,maxpilha,vagao);
				if(strcmp(frase,"0")!=0)
				{
					maior=strlen(frase)-1;
			
					cont=1;
					inserir(p,cont);
					
					fgets(frase,maxpilha,vagao);
					
					while(cont<=maior)
					{
						while(eletopo(p)==frase[i])
						{
							retirar(p);
							i++;
						}
						
						inserir(p,++cont);
					}
					retirar(p);
					
					if(!vazia(p.topo))
						strcpy(op,"NO");
				
					strcpy(nova,frase);
					strcat(nova,op);
				
					fputs(nova,arq);
					
					fgets(frase,maxpilha,vagao);
				}
			}
		}
		else
		{
			maior=strlen(frase)-1;
			
			cont=1;
			inserir(p,cont);
			
			fgets(frase,maxpilha,vagao);
			
			while(cont<=maior)
			{
				while(eletopo(p)==frase[i])
				{
					retirar(p);
					i++;
				}
				
				inserir(p,++cont);
			}
			retirar(p);
			
			if(!vazia(p.topo))
				strcpy(op,"NO");
		
			strcpy(nova,frase);
			strcat(nova,op);
		
			fputs(nova,arq);
			
			fgets(frase,maxpilha,vagao);
		}
	
		
	}
	
	//fgets(frase,maxpilha,vagao);
	
	/*int i=0;
	while(i<strlen(frase)-1)
	{
		if(!cheia(p.topo))
			inserir(p,frase[i]);
		
			
		i++;
	}
	
	exibir(p);*/
	printf("%s\t%d",frase,strlen(frase)-1);
	
	fclose(vagao);
	fclose(arq);	
}
int main(void)
{
	tpilha p;
	estacao(p);
}
