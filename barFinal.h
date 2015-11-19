/* M�dulo Baralho Final: M�dulo referente ao baralho de cartas no final do jogo
*
* Modificado:	27/05 ajustes com os testes de script
*			28/05 Testado e ajustado
*/
#ifndef BARALHO_FINAL_H
#define BARALHO_FINAL_H


#include "pilhaCarta.h"

/* Tipo refer�ncia para um baralho extra */
typedef struct barFinal* BarF_tppBarFinal;

// Condi��es de retorno das fun��es
typedef enum {
	BarF_CondRetOk,					// Concluiu corretamente
	BarF_CondRetErro,				// Ocorreu um erro durante o processo
	BarF_CondRetNaoExiste,	// Baralho final passado n�o existe
	BarF_CondRetNaoCriou,		// N�o foi poss�vel criar uma estrutura durante o processo
} BarFinalCondRet;

/*
Objetivo: Criar um baralho final
Par�metros:
	barFinal	-> Ponteiro, cujo conte�do ser� o baralho final, se a fun��o for bem sucedida
Retorno:
	BarF_CondRetOk
	BarF_CondRetNaoCriou
*/
BarFinalCondRet criarBarFinal(BarF_tppBarFinal* barFinal);

/*
Objetivo: Destruir um baralho final
Par�metros:
	barFinal	-> O baralho final que ser� destruido
Retorno
	BarF_CondRetNaoExiste
	BarF_CondRetOk
	BarF_CondRetErro
*/
BarFinalCondRet destruirBarFinal(BarF_tppBarFinal barFinal);

/*
Objetivo: Adiciona uma carta ao baralho final
Par�metros:
	barFinal	-> O baralho final que receber� a carta
	carta			-> A carta que ser� adicionada
Retorno:
	BarF_CondRetOk
	BarF_CondRetErro
	BarF_CondRetNaoExiste
*/
BarFinalCondRet adicionarCartaBarFinal(BarF_tppBarFinal barFinal, void* carta);

/*
Objetivo: Obtem o tamanho da pilha de cartas no baralho final
Par�metros:
	barFinal	-> O baralho final a ser contado
Retorno:
	BarF_CondRetOk
	BarF_CondRetErro
*/

BarFinalCondRet obterTamanhoBarFinal(BarF_tppBarFinal barFinal, int* tam);

/*
Objetivo: Retira a carta do baralho e obtem seu valor por refer�ncia
Par�metros:
	barFinal	-> O baralho final que ter� a carta retirada
	carta			-> A carta obtida por refer�ncia
Retorno:
	BarF_CondRetOk
	BarF_CondRetErro
*/

BarFinalCondRet pegarCartaBarFinal(BarF_tppBarFinal barF, tppCarta* carta);


#endif