/* M�dulo Baralho Extra: M�dulo referente ao baralho extra de compra de cartas

Modificado: 27/05 Ajustes na implementa��o
			28/05 Testado e ajustado
			03/06 Testado e ajustado
			06/06 ajustes finais
*/
#ifndef BARALHO_EXTRA_H
#define BARALHO_EXTRA_H


#include "pilhaCarta.h"

/* Tipo refer�ncia para um baralho extra */
typedef struct barExt* BarE_tppBarExtra;

// Condi��es de retorno das fun��es
typedef enum {
	BarE_CondRetOk,					// Concluiu corretamente
	BarE_CondRetErro,				// Ocorreu um erro durante o processo
	BarE_CondRetNaoExiste,	// Baralho extra passado n�o existe
	BarE_CondRetNaoCriou,		// N�o foi poss�vel criar uma estrutura durante o processo
} BarExtCondRet;

/*
Objetivo: Criar um baralho extra
Par�metros:
	barExt	-> Ponteiro que apontar� para um baralho inicial se a fun��o for bem sucedida
Retorno:
	BarE_CondRetNaoCriou
	BarE_CondRetOk
*/
BarExtCondRet criarBarExtra(BarE_tppBarExtra* barExt);

/*
Objetivo: Destruir um baralho extra
Par�metros:
	barExt	-> O baralho extra que se deseja destruir
Retorno:
	BarE_CondRetNaoExiste
	BarE_CondRetOk
	BarE_CondRetErro
*/
BarExtCondRet destruirBarExtra(BarE_tppBarExtra barExt);

/*
Objetivo: Adiciona ao baralho extra uma carta
Par�metros:
	barExtra	-> O baralho extra que receber� a carta
	carta			-> A carta a ser adicionada ao baralho extra
Retorno:
	BarE_CondRetOk
	BarE_CondRetErro
	BarE_CondRetNaoExiste
*/
BarExtCondRet	adicionarCartaBarExtra(BarE_tppBarExtra barExtra, void* carta);

/*
Objetivo: Retira a carta do topo da pilha e obtem seu valor pro refer�ncia
Par�metros:
	barExtra	-> O baralho extra que a carta ser� retirada
	carta			-> A carta a ser adquirida por refer�ncia
Retorno:
	BarE_CondRetOk
	BarE_CondRetErro
	BarE_CondRetNaoExiste
*/

BarExtCondRet pegarCartaBarExtra(BarE_tppBarExtra barExtra, tppCarta* carta);

// Fun��es usadas no m�dulo

int obterTamanhoBarE(BarE_tppBarExtra barE);
#endif