/* Módulo Pilha de Carta: Módulo referente a uma Pilha de Cartas
* Autor: Felipe Vieira Côrtes, Klaus Fischer
* Modificado 27/05 teste com scripts
*		   28/05 ajustes com teste de scripts
*		   29/05  debugs com teste com scripts
*		   01/06  debugs com teste com scripts
*		   02/06  Implementação
*		   06/06 Ajustes finais
*/
#ifndef PILHA_CARTA_H
#define PILHA_CARTA_H

#include "LISTA.H"
#include "carta.h"


/* Tipo referência para uma pilha */
typedef struct PIL_pilha* PIL_tppPilha;

// Condições de retorno das funções
typedef enum {
	PIL_CondRetOk,				// Concluiu corretamente
	PIL_CondRetErro,			// Ocorreu um erro
	PIL_CondRetNaoExiste,	// Pilha passada não existe
	PIL_CondRetNaoCriou,	// Não foi possível alocar espaço para a pilha
} PilhaCondRet;

// Funções de Acesso

/*
Objetivo: Cria uma pilha
Parâmetros:
	pilha				 -> Ponteiro que apontará para uma pilha se a função for bem sucedida
	excluirValor -> Ponteiro para a função responsável por destroir os elementos da pilha
Retorno:
	PIL_CondRetOk
	PIL_CondRetNaoCriou
*/
PilhaCondRet criarPilha(PIL_tppPilha* pilha);

/*
Objetivo: Destruir uma pilha
Parâmetros:
	pilha -> A pilha que será destruída
Retorno:
	PIL_CondRetNaoExiste
	PIL_CondRetOk
*/
PilhaCondRet destrPilha(PIL_tppPilha pilha);

/*
Objetivo: Adicionar um elemento à pilha
Parâmetros:
	pilha			-> A pilha que receberá um elemento
	conteudo	-> O conteúdo do elemento que será adicionado à pilha
Retorno:
	PIL_CondRetOk
	PIL_CondRetErro
	PIL_CondRetNaoExiste
*/
PilhaCondRet	adicionarElementoPilha(PIL_tppPilha pilha, void* conteudo);

/*
Objetivo: Remover um elemento da pilha
Parâmetros:
	pilha			-> A pilha que terá o seu elemento removido
Retorno:
	PIL_CondRetOk
	PIL_CondRetErro
	PIL_CondRetNaoExiste
*/
PilhaCondRet	removerElementoPilha(PIL_tppPilha pilha);

/*
Objetivo: Obter o valor de um elemento da pilha
Parâmetros:
	pilha			-> A pilha que terá o seu elemento consultado
	valor			-> O valor do elemento da pilha
Retorno:
	PIL_CondRetOk
	PIL_CondRetNaoExiste
*/
PilhaCondRet	obterValorPilha(PIL_tppPilha pilha, void** valor);

/*
Objetivo : Obtem a quantidade de elementos na pilha
Parâmetros:
	pilha -> A pilha a se obter o tamanho
Retorno:
	PIL_CondRetNaoExiste
	PIL_CondRetOk
*/
PilhaCondRet obterTamanhoPilha(PIL_tppPilha pilha, int* qtd);

/* Objetivo: Exibe o conteúdo das cartas da pilha, se a carta está fechada
			 exibe '#' se nao, exibe  seus valores
   Parâmetros:
		pilha-> A pilha a ser exibida
	Retorno
		PIL_CondRetErro
		PIL_CondRetOk
*/
PilhaCondRet exibePilha(PIL_tppPilha pilha);

#endif