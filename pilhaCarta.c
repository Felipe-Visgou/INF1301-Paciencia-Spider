/* M�dulo Pilha de Carta: M�dulo referente a uma Pilha de Cartas
* Autor: Felipe Vieira C�rtes, Klaus Fischer
* Modificado 27/05 teste com scripts
*		   28/05 ajustes com teste de scripts
*		   29/05  debugs com teste com scripts
*		   01/06  debugs com teste com scripts
*		   02/06  Implementa��o
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
*  Fun��o: Criar Pilha
*  ****/
PilhaCondRet criarPilha(PIL_tppPilha* pilha)
{
	*pilha = (PIL_tppPilha)malloc(sizeof(PIL_tpPilha));
	if (!pilha)
		return PIL_CondRetNaoCriou;

	(*pilha)->qntd = 0;
	(*pilha)->lista = LIS_CriarLista(NULL);

	// Verifica se foi poss�vel criar a lista da pilha
	if (!(*pilha)->lista)
		return PIL_CondRetNaoCriou;

	return PIL_CondRetOk;
} /*  Fim Fun��o: Criar Pilha */

/***************************************************************************
*
*  Fun��o: Destruir Pilha
*  ****/
PilhaCondRet destrPilha(PIL_tppPilha pilha)
{
	if (!pilha)
		return PIL_CondRetNaoExiste;

	LIS_DestruirLista(pilha->lista);
	free(pilha);
	
	return PIL_CondRetOk;
}/*  Fim Fun��o: Destruir Pilha */

/***************************************************************************
*
*  Fun��o: Adicionar Elemento
*  ****/
PilhaCondRet	adicionarElementoPilha(PIL_tppPilha pilha, void* conteudo)
{
	// Verifica a exist�ncia da pilha
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
} /*  Fim Fun��o: Adicionar Elemento */

/***************************************************************************
*
*  Fun��o: Remover Elemento
*  ****/
PilhaCondRet	removerElementoPilha(PIL_tppPilha pilha)
{
	// Verifica a exist�ncia da pilha
	if (!pilha)
		return PIL_CondRetNaoExiste;

	// Remove o �ltimo elemento da lista
	IrFinalLista(pilha->lista);
	if (LIS_ExcluirElemento(pilha->lista) != LIS_CondRetOK)
		return PIL_CondRetErro;
	else
	{
		pilha->qntd--;
		return PIL_CondRetOk;
	}
} /*  Fim Fun��o: Remover Elemento */

/***************************************************************************
*
*  Fun��o: Obter Valor do topo
*  ****/
PilhaCondRet	obterValorPilha(PIL_tppPilha pilha, void** valor)
{
	// Verifica a exist�ncia da pilha
	if (!pilha)
		return PIL_CondRetNaoExiste;

	// Obt�m o �ltimo elemento da lista
	IrFinalLista(pilha->lista);
	*valor = LIS_ObterValor(pilha->lista);

	return PIL_CondRetOk;
} /*  Fim Fun��o: Obter Valor do topo */

/***************************************************************************
*
*  Fun��o: Obter Tamanho da pilha
*  ****/
PilhaCondRet obterTamanhoPilha(PIL_tppPilha pilha, int* qtd)
{
	if(pilha == NULL)
		return PIL_CondRetNaoExiste;
	*qtd = pilha->qntd;
	return PIL_CondRetOk;
} /*  Fim Fun��o: Obter Tamanho da pilha */

/***************************************************************************
*
*  Fun��o: Exibe Pilha
*  ****/
PilhaCondRet exibePilha(PIL_tppPilha pilha)
{
	int i, Aberta,Valor;
	char cNaipe, cValor;
	void* Caux;
	PIL_tppPilha Paux = pilha;
	i = Paux->qntd;
	IrInicioLista(Paux->lista);
	if(i == 0) {// se n�o houver cartas na pilha
		printf(" V \n");
		return PIL_CondRetOk;
	}
	while (i>1)
	{
		Caux = LIS_ObterValor(Paux->lista);
		if(obterValorCarta((tppCarta)Caux, &cNaipe, &Valor, &Aberta) != CAR_CondRetOk)
			return PIL_CondRetErro;
		if(!Aberta) // Se a carta est� fechada entao...
			printf(" #");
		else // Se a carta est� aberta ent�o exibe seus valores
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
		if(!Aberta) // Se a carta est� fechada entao...
			printf(" #");
		else // Se a carta est� aberta ent�o exibe seus valores
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
}/*  Fim Fun��o: Exibe Pilha */