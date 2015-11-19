/* Módulo Pilha de Carta: Módulo referente a uma Pilha de Cartas
* Autor: Felipe Vieira Côrtes, Klaus Fischer
* Modificado 27/05 teste com scripts
*		   28/05 ajustes com teste de scripts
*		   29/05  debugs com teste com scripts
*		   01/06  debugs com teste com scripts
*		   02/06  Implementação
*		   06/06 Ajustes finais
*/
#include "pilhaCarta.h"
#include <stdlib.h>
#include <stdio.h>

// Descritor da estrutura pilha
typedef struct PIL_pilha {
	LIS_tppLista	lista;
	int						qntd;
} PIL_tpPilha;

 /***************************************************************************
*
*  Função: Criar Pilha
*  ****/
PilhaCondRet criarPilha(PIL_tppPilha* pilha)
{
	*pilha = (PIL_tppPilha)malloc(sizeof(PIL_tpPilha));
	if (!pilha)
		return PIL_CondRetNaoCriou;

	(*pilha)->qntd = 0;
	(*pilha)->lista = LIS_CriarLista(NULL);

	// Verifica se foi possível criar a lista da pilha
	if (!(*pilha)->lista)
		return PIL_CondRetNaoCriou;

	return PIL_CondRetOk;
} /*  Fim Função: Criar Pilha */

/***************************************************************************
*
*  Função: Destruir Pilha
*  ****/
PilhaCondRet destrPilha(PIL_tppPilha pilha)
{
	if (!pilha)
		return PIL_CondRetNaoExiste;

	LIS_DestruirLista(pilha->lista);
	free(pilha);
	
	return PIL_CondRetOk;
}/*  Fim Função: Destruir Pilha */

/***************************************************************************
*
*  Função: Adicionar Elemento
*  ****/
PilhaCondRet	adicionarElementoPilha(PIL_tppPilha pilha, void* conteudo)
{
	// Verifica a existência da pilha
	if (!pilha)
		return PIL_CondRetNaoExiste;

	// Adiciona o elemento ao final da lista
	IrFinalLista(pilha->lista);
	if (LIS_InserirElementoApos(pilha->lista, conteudo) != LIS_CondRetOK)
		return PIL_CondRetErro;
	else
	{
		pilha->qntd++;
		return PIL_CondRetOk;
	}
} /*  Fim Função: Adicionar Elemento */

/***************************************************************************
*
*  Função: Remover Elemento
*  ****/
PilhaCondRet	removerElementoPilha(PIL_tppPilha pilha)
{
	// Verifica a existência da pilha
	if (!pilha)
		return PIL_CondRetNaoExiste;

	// Remove o último elemento da lista
	IrFinalLista(pilha->lista);
	if (LIS_ExcluirElemento(pilha->lista) != LIS_CondRetOK)
		return PIL_CondRetErro;
	else
	{
		pilha->qntd--;
		return PIL_CondRetOk;
	}
} /*  Fim Função: Remover Elemento */

/***************************************************************************
*
*  Função: Obter Valor do topo
*  ****/
PilhaCondRet	obterValorPilha(PIL_tppPilha pilha, void** valor)
{
	// Verifica a existência da pilha
	if (!pilha)
		return PIL_CondRetNaoExiste;

	// Obtém o último elemento da lista
	IrFinalLista(pilha->lista);
	*valor = LIS_ObterValor(pilha->lista);

	return PIL_CondRetOk;
} /*  Fim Função: Obter Valor do topo */

/***************************************************************************
*
*  Função: Obter Tamanho da pilha
*  ****/
PilhaCondRet obterTamanhoPilha(PIL_tppPilha pilha, int* qtd)
{
	if(pilha == NULL)
		return PIL_CondRetNaoExiste;
	*qtd = pilha->qntd;
	return PIL_CondRetOk;
} /*  Fim Função: Obter Tamanho da pilha */

/***************************************************************************
*
*  Função: Exibe Pilha
*  ****/
PilhaCondRet exibePilha(PIL_tppPilha pilha)
{
	int i, Aberta,Valor;
	char cNaipe, cValor;
	void* Caux;
	PIL_tppPilha Paux = pilha;
	i = Paux->qntd;
	IrInicioLista(Paux->lista);
	if(i == 0) {// se não houver cartas na pilha
		printf(" V \n");
		return PIL_CondRetOk;
	}
	while (i>1)
	{
		Caux = LIS_ObterValor(Paux->lista);
		if(obterValorCarta((tppCarta)Caux, &cNaipe, &Valor, &Aberta) != CAR_CondRetOk)
			return PIL_CondRetErro;
		if(!Aberta) // Se a carta está fechada entao...
			printf(" #");
		else // Se a carta está aberta então exibe seus valores
		{
			if( Valor ==1 || Valor > 10 ) // se o valor for uma letra (A, J, Q, K)
			{
				if(Valor == 1) cValor = 'A';
				else if(Valor == 11) cValor = 'J';
				else if(Valor == 12) cValor = 'Q';
				else cValor = 'K';
				printf(" %c%c", cNaipe, cValor);
			}
			else printf(" %c%d", cNaipe, Valor);
		}
		if(LIS_AvancarElementoCorrente(Paux->lista, 1) != LIS_CondRetOK)
			return PIL_CondRetErro;
		i--;
	}
		Caux = LIS_ObterValor(Paux->lista);
		if(obterValorCarta((tppCarta)Caux, &cNaipe, &Valor, &Aberta) != CAR_CondRetOk)
			return PIL_CondRetErro;
		if(!Aberta) // Se a carta está fechada entao...
			printf(" #");
		else // Se a carta está aberta então exibe seus valores
		{
			if( Valor == 1 || Valor > 10 ) // se o valor for uma letra (A, J, Q, K)
			{
				if(Valor == 1) cValor = 'A';
				else if(Valor == 11) cValor = 'J';
				else if(Valor == 12) cValor = 'Q';
				else cValor = 'K';
				printf(" %c%c", cNaipe, cValor);
			}
			else printf(" %c%d", cNaipe, Valor);
		}
	printf("\n");
	return PIL_CondRetOk;
}/*  Fim Função: Exibe Pilha */