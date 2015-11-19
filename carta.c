/* Módulo Carta: Módulo referente a uma única carta
* Autor: Klaus Fischer
* Modificado 27/05 Teste com scripts e ajustes
*		   28/05 ajustes com teste de scripts
*		   06/06 Ajustes finais
*/
#include <stdlib.h>
#include "carta.h"
#include <stdio.h>

// Descritor da estrutura carta
typedef struct tgCarta
{
	char	naipe;
	int		valor;
	int		aberta;
} tpCarta;

/***************************************************************************
*
*  Função: Criar Carta
*  ****/
CartaCondRet criarCarta(char naipe, int valor, tppCarta* carta)
{	
	*carta = (tppCarta)malloc(sizeof(tpCarta));
	
	if (!carta)
		return CAR_CondRetNaoCriou;
	if (naipe != 'o' && naipe != 'p' && naipe != 'e' && naipe != 'c')
		return CAR_CondRetErro;
    if (valor < 1 || valor > 13)
		return CAR_CondRetErro;
	(*carta)->naipe = naipe;
	(*carta)->valor = valor;
	(*carta)->aberta = 0;	// Carta não está virada
	//printf("CRIAR!! Naipe = %c    Valor = %d    Aberta ou nao = %d \n", (*carta)->naipe, (*carta)->valor, (*carta)->aberta);
	return CAR_CondRetOk;
} /* Fim Função: Criar carta */

/***************************************************************************
*
*  Função: Destruir Carta
*  ****/
CartaCondRet destrCarta(tppCarta carta)
{
	if (carta == NULL)
		return CAR_CondRetNaoExiste;

	free(carta);
	return CAR_CondRetOk;
}  /* Fim Função: Destruir carta */

/***************************************************************************
*
*  Função: Alterar Naipe
*  ****/
CartaCondRet alterarNaipe(tppCarta carta, char novoNaipe)
{
	// Verifica a existência da carta
	if (!carta)
		return CAR_CondRetNaoExiste;

	// Valida o naipe
	if (novoNaipe != 'o' && novoNaipe != 'p' && novoNaipe != 'e' && novoNaipe != 'c')
		return CAR_CondRetErro;
	else
	{
		carta->naipe = novoNaipe;
		return CAR_CondRetOk;
	}
} /* Fim Função: Alterar Naipe */

/***************************************************************************
*
*  Função: Aletrar Valor
*  ****/
CartaCondRet alterarValor(tppCarta carta, int novoValor)
{
	// Verifica a existência da carta
	if (!carta)
		return CAR_CondRetNaoExiste;

	// Valida o valor
	if (novoValor < 1 || novoValor > 13)
		return CAR_CondRetErro;
	else
	{
		carta->valor = novoValor;
		return CAR_CondRetOk;
	}
} /* Fim Função: Aletrar Valor */

/***************************************************************************
*
*  Função: Abre a Carta 
*  ****/
CartaCondRet abreCarta(tppCarta carta)
{
	// Verifica a existência da carta
	if (!carta)
		return CAR_CondRetNaoExiste;
	else
	{
		carta->aberta = 1;
		return CAR_CondRetOk;
	}
} /* Fim Função: Abre a Carta  */

/***************************************************************************
*
*  Função: Obter Valor da carta
*  ****/
CartaCondRet obterValorCarta(tppCarta carta, char* naipe, int* valor, int* aberta )
{
	// Verifica a existência da carta
	if (!carta)
		return CAR_CondRetNaoExiste;
	else if (!naipe || !valor)
		return CAR_CondRetErro;
	else
	{
		// Passa os valores
		*naipe	= carta->naipe;
		*valor	= carta->valor;
		*aberta = carta->aberta;
		return CAR_CondRetOk;
	}
} /* Fim Função: Obter Valor da carta */
void imprimeCarta (tppCarta carta) {
	printf (" \n IMPRIME CARTA \n");
	printf ("naipe = %c \n valor = %d \n aberta = %d \n", carta->naipe, carta->valor, carta->aberta);
}