/* Módulo Baralho Final: Módulo referente ao baralho de cartas no final do jogo
*
* Modificado:	27/05 ajustes com os testes de script
*			28/05 Testado e ajustado
*/
#ifndef BARALHO_FINAL_H
#define BARALHO_FINAL_H


#include "pilhaCarta.h"

/* Tipo referência para um baralho extra */
typedef struct barFinal* BarF_tppBarFinal;

// Condições de retorno das funções
typedef enum {
	BarF_CondRetOk,					// Concluiu corretamente
	BarF_CondRetErro,				// Ocorreu um erro durante o processo
	BarF_CondRetNaoExiste,	// Baralho final passado não existe
	BarF_CondRetNaoCriou,		// Não foi possível criar uma estrutura durante o processo
} BarFinalCondRet;

/*
Objetivo: Criar um baralho final
Parâmetros:
	barFinal	-> Ponteiro, cujo conteúdo será o baralho final, se a função for bem sucedida
Retorno:
	BarF_CondRetOk
	BarF_CondRetNaoCriou
*/
BarFinalCondRet criarBarFinal(BarF_tppBarFinal* barFinal);

/*
Objetivo: Destruir um baralho final
Parâmetros:
	barFinal	-> O baralho final que será destruido
Retorno
	BarF_CondRetNaoExiste
	BarF_CondRetOk
	BarF_CondRetErro
*/
BarFinalCondRet destruirBarFinal(BarF_tppBarFinal barFinal);

/*
Objetivo: Adiciona uma carta ao baralho final
Parâmetros:
	barFinal	-> O baralho final que receberá a carta
	carta			-> A carta que será adicionada
Retorno:
	BarF_CondRetOk
	BarF_CondRetErro
	BarF_CondRetNaoExiste
*/
BarFinalCondRet adicionarCartaBarFinal(BarF_tppBarFinal barFinal, void* carta);

/*
Objetivo: Obtem o tamanho da pilha de cartas no baralho final
Parâmetros:
	barFinal	-> O baralho final a ser contado
Retorno:
	BarF_CondRetOk
	BarF_CondRetErro
*/

BarFinalCondRet obterTamanhoBarFinal(BarF_tppBarFinal barFinal, int* tam);

/*
Objetivo: Retira a carta do baralho e obtem seu valor por referência
Parâmetros:
	barFinal	-> O baralho final que terá a carta retirada
	carta			-> A carta obtida por referência
Retorno:
	BarF_CondRetOk
	BarF_CondRetErro
*/

BarFinalCondRet pegarCartaBarFinal(BarF_tppBarFinal barF, tppCarta* carta);


#endif