/* Módulo Baralho Final: Módulo referente ao baralho de cartas no final do jogo
*
* Modificado:	27/05 ajustes com os testes de script
*			28/05 Testado e ajustado
*/
#include <stdlib.h>
#include <stdio.h>
#include "barFinal.h"

// Descritor da estrutura baralho final
typedef struct barFinal
{
	PIL_tppPilha pilha;
} BarF_tpBarFinal;

/***************************************************************************
*
*  Função: Criar Baralho Final
*  ****/
BarFinalCondRet criarBarFinal(BarF_tppBarFinal* barFinal)
{
	*barFinal = (BarF_tppBarFinal)malloc(sizeof(BarF_tpBarFinal));

	// Verifica se criou o baralho
	if(!barFinal)
		return BarF_CondRetNaoCriou;

	// Cria a pilha a ser usada pelo baralho
	if (criarPilha(&(*barFinal)->pilha) == PIL_CondRetNaoCriou)
		return BarF_CondRetNaoCriou;

	return BarF_CondRetOk;
} /* Fim Função: Criar Baralho Final */

/***************************************************************************
*
*  Função: Destruir Baralho Final
*  ****/
BarFinalCondRet destruirBarFinal(BarF_tppBarFinal barFinal)
{
	// Verifica e existência do baralho
	if (!barFinal)
		return BarF_CondRetNaoExiste;

	if (destrPilha(barFinal->pilha) != PIL_CondRetOk)
		return BarF_CondRetErro;

	// Destrói o baralho
	free(barFinal);

	return BarF_CondRetOk;
} /* Fim Função:  Destruir Baralho Final */

/***************************************************************************
*
*  Função: Adicionar Carta
*  ****/
BarFinalCondRet adicionarCartaBarFinal(BarF_tppBarFinal barFinal, void* carta)
{
	// Verifica e existência do baralho
	if (!barFinal)
		return BarF_CondRetNaoExiste;

	// Verifica se a carta existe
	if (!carta)
		return BarF_CondRetErro;

	// Adiciona a carta
	if (adicionarElementoPilha(barFinal->pilha, carta) != PIL_CondRetOk)
		return BarF_CondRetErro;

	return BarF_CondRetOk;
} /* Fim Função:  Adicionar Carta */

/***************************************************************************
*
*  Função: Pegar Carta do topo
*  ****/
BarFinalCondRet pegarCartaBarFinal(BarF_tppBarFinal barF, tppCarta* carta)
{
	if(obterValorPilha(barF->pilha, (void**)carta)!= PIL_CondRetOk) // obtem o elemento no topo da pilha
		return BarF_CondRetErro;

	if(removerElementoPilha(barF->pilha) != PIL_CondRetOk) // Retira do baralho o elemento obtido
		return BarF_CondRetErro;

	return BarF_CondRetOk;
}/* Fim Função: Pegar Carta do topo */

/***************************************************************************
*
*  Função: Obter Tamanho Baralho Final
*  ****/
BarFinalCondRet obterTamanhoBarFinal(BarF_tppBarFinal barFinal, int* tam)
{
	if(obterTamanhoPilha(barFinal->pilha, tam)!= PIL_CondRetOk)
	{
		printf("Erro ao obter tamanho do baralho final \n");
		return BarF_CondRetErro;
	}
	return BarF_CondRetOk;
}/* Fim Função: Obter Tamanho Baralho Final */

