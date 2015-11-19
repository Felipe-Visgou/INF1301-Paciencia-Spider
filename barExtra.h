/* Módulo Baralho Extra: Módulo referente ao baralho extra de compra de cartas

Modificado: 27/05 Ajustes na implementação
			28/05 Testado e ajustado
			03/06 Testado e ajustado
			06/06 ajustes finais
*/
#ifndef BARALHO_EXTRA_H
#define BARALHO_EXTRA_H


#include "pilhaCarta.h"

/* Tipo referência para um baralho extra */
typedef struct barExt* BarE_tppBarExtra;

// Condições de retorno das funções
typedef enum {
	BarE_CondRetOk,					// Concluiu corretamente
	BarE_CondRetErro,				// Ocorreu um erro durante o processo
	BarE_CondRetNaoExiste,	// Baralho extra passado não existe
	BarE_CondRetNaoCriou,		// Não foi possível criar uma estrutura durante o processo
} BarExtCondRet;

/*
Objetivo: Criar um baralho extra
Parâmetros:
	barExt	-> Ponteiro que apontará para um baralho inicial se a função for bem sucedida
Retorno:
	BarE_CondRetNaoCriou
	BarE_CondRetOk
*/
BarExtCondRet criarBarExtra(BarE_tppBarExtra* barExt);

/*
Objetivo: Destruir um baralho extra
Parâmetros:
	barExt	-> O baralho extra que se deseja destruir
Retorno:
	BarE_CondRetNaoExiste
	BarE_CondRetOk
	BarE_CondRetErro
*/
BarExtCondRet destruirBarExtra(BarE_tppBarExtra barExt);

/*
Objetivo: Adiciona ao baralho extra uma carta
Parâmetros:
	barExtra	-> O baralho extra que receberá a carta
	carta			-> A carta a ser adicionada ao baralho extra
Retorno:
	BarE_CondRetOk
	BarE_CondRetErro
	BarE_CondRetNaoExiste
*/
BarExtCondRet	adicionarCartaBarExtra(BarE_tppBarExtra barExtra, void* carta);

/*
Objetivo: Retira a carta do topo da pilha e obtem seu valor pro referência
Parâmetros:
	barExtra	-> O baralho extra que a carta será retirada
	carta			-> A carta a ser adquirida por referência
Retorno:
	BarE_CondRetOk
	BarE_CondRetErro
	BarE_CondRetNaoExiste
*/

BarExtCondRet pegarCartaBarExtra(BarE_tppBarExtra barExtra, tppCarta* carta);

// Funções usadas no módulo

int obterTamanhoBarE(BarE_tppBarExtra barE);
#endif