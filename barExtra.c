/* M�dulo Baralho Extra: M�dulo referente ao baralho extra de compra de cartas
*
* Modificado: 27/05 Ajustes na implementa��o
*			28/05 Testado e ajustado
*			03/06 Testado e ajustado
*			06/06 ajustes finais
*/

#include <stdlib.h>
#include "barExtra.h"

// Descritor da estrutura baralho extra
typedef struct barExt
{
	PIL_tppPilha pilha;
}BarE_tpBarExt;

/***************************************************************************
*
*  Fun��o: Criar Baralho Inicial
*  ****/
BarExtCondRet criarBarExtra(BarE_tppBarExtra* barExt)
{
	*barExt = (BarE_tppBarExtra)malloc(sizeof(BarE_tpBarExt));

	// Verifica se criou
	if (!barExt)
		return BarE_CondRetNaoCriou;

	// Cria uma pilha para ser usada pelo baralho
	if (criarPilha(&(*barExt)->pilha) == PIL_CondRetNaoCriou)
		return BarE_CondRetNaoCriou;

	return BarE_CondRetOk;
} /* Fim Fun��o: Criar Baralho Inicial */

/***************************************************************************
*
*  Fun��o: Destruir Baralho Inicial
*  ****/
BarExtCondRet destruirBarExtra(BarE_tppBarExtra barExt)
{
	// Verifica a exist�ncia do baralho extra
	if (!barExt)
		return BarE_CondRetNaoExiste;

	// Destr�i a pilha associada ao baralho
	if (destrPilha(barExt->pilha) != PIL_CondRetOk)
		return BarE_CondRetErro;

	// Destr�i o baralho
	free(barExt);

	return BarE_CondRetOk;
} /* Fim Fun��o: Destruir Baralho Inicial */

/***************************************************************************
*
*  Fun��o: Adicionar Carta
*  ****/
BarExtCondRet	adicionarCartaBarExtra(BarE_tppBarExtra barExtra, void* carta)
{

	// Verifca se existe o baralho extra
	if (!barExtra)
		return BarE_CondRetNaoExiste;

	// Verifca se a carta existe
	if (!carta)
		return BarE_CondRetErro;

	// Adiciona a carta
	if (adicionarElementoPilha(barExtra->pilha, carta) != PIL_CondRetOk)
		return BarE_CondRetErro;

	return BarE_CondRetOk;
} /* Fim Fun��o:  Adicionar Carta */

/***************************************************************************
*
*  Fun��o: Pegar Carta do topo
*  ****/
BarExtCondRet pegarCartaBarExtra(BarE_tppBarExtra barExtra, tppCarta* carta)
{
	if(obterValorPilha(barExtra->pilha, (void**)carta)!= PIL_CondRetOk) // obtem o elemento no topo da pilha
		return BarE_CondRetErro;

	if(removerElementoPilha(barExtra->pilha) != PIL_CondRetOk) // Retira do baralho o elemento obtido
		return BarE_CondRetErro;

	return BarE_CondRetOk;
} /* Fim Fun��o: Pegar Carta do topo */

int obterTamanhoBarE(BarE_tppBarExtra barE)
{
	int tam;
	if(obterTamanhoPilha(barE->pilha, &tam)!= PIL_CondRetOk)
		return -1;
	return tam;
}