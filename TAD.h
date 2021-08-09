#define MaxP 1000

struct TpPilha
{
	int topo;
	int pilha[MaxP];
};

void inicializarPilha(TpPilha &P)
{
	P.topo = -1;
}
char pilhaCheia(int topo)
{
	return topo == MaxP-1;
}
char pilhaVazia(int topo)
{
	return topo == -1; // SE SIM RETORNA 1
}
void inserirPilha(TpPilha &P, int vagao)
{
	P.pilha[++P.topo] = vagao;
}
int removerPilha(TpPilha &P)
{
	return P.pilha[P.topo--];
}
int elemento(TpPilha P)
{
	return P.pilha[P.topo];
}
void exibirPilha(TpPilha P)
{
	while(!pilhaVazia(P.topo))
		printf("%d \t",removerPilha(P));
	printf("\n");
}
