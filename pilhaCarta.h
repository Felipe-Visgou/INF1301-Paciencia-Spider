/* M�dulo Pilha de Carta: M�dulo referente a uma Pilha de Cartas
* Autor: Felipe Vieira C�rtes, Klaus Fischer
* Modificado 27/05 teste com scripts
*		   28/05 ajustes com teste de scripts
*		   29/05  debugs com teste com scripts
*		   01/06  debugs com teste com scripts
*		   02/06  Implementa��o
*		   06/06 Ajustes finais
*/
#ifndef PILHA_CARTA_H
#define PILHA_CARTA_H

#include "LISTA.H"
#include "carta.h"


/* Tipo refer�ncia para uma pilha */
typedef struct PIL_pilha* PIL_tppPilha;

// Condi��es de retorno das fun��es
typedef enum {
	PIL_CondRetOk,				// Concluiu corretamente
	PIL_CondRetErro,			// Ocorreu um erro
	PIL_CondRetNaoExiste,	// Pilha passada n�o existe
	PIL_CondRetNaoCriou,	// N�o foi poss�vel alocar espa�o para a pilha
} PilhaCondRet;

// Fun��es de Acesso

/*
Objetivo: Cria uma pilha
Par�metros:
	pilha				 -> Ponteiro que apontar� para uma pilha se a fun��o for bem sucedida
	excluirValor -> Ponteiro para a fun��o respons�vel por destroir os elementos da pilha
Retorno:
	PIL_CondRetOk
	PIL_CondRetNaoCriou
*/
PilhaCondRet criarPilha(PIL_tppPilha* pilha);

/*
Objetivo: Destruir uma pilha
Par�metros:
	pilha -> A pilha que ser� destru�da
Retorno:
	PIL_CondRetNaoExiste
	PIL_CondRetOk
*/
PilhaCondRet destrPilha(PIL_tppPilha pilha);

/*
Objetivo: Adicionar um elemento � pilha
Par�metros:
	pilha			-> A pilha que receber� um elemento
	conteudo	-> O conte�do do elemento que ser� adicionado � pilha
Retorno:
	PIL_CondRetOk
	PIL_CondRetErro
	PIL_CondRetNaoExiste
*/
PilhaCondRet	adicionarElementoPilha(PIL_tppPilha pilha, void* conteudo);

/*
Objetivo: Remover um elemento da pilha
Par�metros:
	pilha			-> A pilha que ter� o seu elemento removido
Retorno:
	PIL_CondRetOk
	PIL_CondRetErro
	PIL_CondRetNaoExiste
*/
PilhaCondRet	removerElementoPilha(PIL_tppPilha pilha);

/*
Objetivo: Obter o valor de um elemento da pilha
Par�metros:
	pilha			-> A pilha que ter� o seu elemento consultado
	valor			-> O valor do elemento da pilha
Retorno:
	PIL_CondRetOk
	PIL_CondRetNaoExiste
*/
PilhaCondRet	obterValorPilha(PIL_tppPilha pilha, void** valor);

/*
Objetivo : Obtem a quantidade de elementos na pilha
Par�metros:
	pilha -> A pilha a se obter o tamanho
Retorno:
	PIL_CondRetNaoExiste
	PIL_CondRetOk
*/
PilhaCondRet obterTamanhoPilha(PIL_tppPilha pilha, int* qtd);

/* Objetivo: Exibe o conte�do das cartas da pilha, se a carta est� fechada
			 exibe '#' se nao, exibe  seus valores
   Par�metros:
		pilha-> A pilha a ser exibida
	Retorno
		PIL_CondRetErro
		PIL_CondRetOk
*/
PilhaCondRet exibePilha(PIL_tppPilha pilha);

#endif