/* M�dulo Baralho Principal: M�dulo referente aos 10 baralho principais do jogo Paci�ncia Spider

Modificado 27/05 Implementa��o
		   28/05 ajustes com teste de scripts
		   29/05 ...
		   30/05 ...
		   01/06 ...
		   02/06 ...
		   03/06 ...
		   04/06 ...
		   05/06 ...
		   06/06 Ajustes finais
*/
#ifndef BARALHO_PRINCIPAL_H
#define BARALHO_PRINCIPAL_H

#include "pilhaCarta.h"
#include "carta.h"

/* Tipo refer�ncia para um baralho principal */
typedef struct barPrn* BarP_tppBarPrinc;

// Condi��es de retorno da fun��o
typedef enum {
	BarP_CondRetOk,					// Concluiu corretamente
	BarP_CondRetErro,				// Ocorreu um erro durante a transfer�ncia
	BarP_CondRetRegra,			// N�o respeitou a regra de transferir carta
	BarP_CondRetNaoExiste,	// Baralho principal passado n�o existe
	BarP_CondRetNaoCriou, // N�o foi possivel criar o baralho principal
	BarP_CondRetNaoSeq,
} BarPrincCondRet;


/*********** Func�es de acesso ********************/

/*
Objetivo: Criar um baralho principal
Par�metros:
	barPrinc -> Ponteiro que apontar� para um baralho principal se a fun��o for bem sucedida
Retorno:
	BarP_CondRetOk
	BarP_CondRetNaoCriou
*/
BarPrincCondRet criarBaralhoPrincipal(BarP_tppBarPrinc* barPrinc);

/*
Objetivo: Destroir um baralho principal
Par�metros:
	barPrinc -> O baralho principal que ser� destroido
Retorno:
	BarP_CondRetNaoExiste
	BarP_CondRetOk
*/
BarPrincCondRet destrBaralhoPrincipal(BarP_tppBarPrinc barPrinc);

/*
Objetivo: Retira cartas de um dos baralhos principais
					e adiciona as cartas removidas em outro baralho qualquer
Par�metros:
	fonte		-> O baralho principal (obrigatoriamente) que ter� suas cartas removidas
	destino	-> O baralho receber� as cartas removidas de fonte
	qntd		-> A quantidade de cartas que ser� transferidas
Retorno:
	BarP_CondRetOk
	BarP_CondRetErro
	BarP_CondRetRegra
	BarP_CondRetNaoExiste
*/
BarPrincCondRet transferirCartasBarP(BarP_tppBarPrinc fonte, BarP_tppBarPrinc destino, int qntd);

/*
Objetivo: Adiciona uma carta ao baralho principal sem abrir a mesma e sem seguir nenhuma regra
Par�metros:
	barPrinc	-> O baralho que receber� a carta
	carta			-> A carta a ser adicionada ao baralho principal
Retorno:
	BarP_CondRetOk
	BarP_CondRetErro
	BarP_CondRetNaoExiste
*/
BarPrincCondRet adicionarCartasBarP(BarP_tppBarPrinc barP, tppCarta carta);

/*
Objetivo: Exibe as cartas do baralho principal
Par�metros
	barP -> o baralho principal a ser exibido
Retorno
	BarP_CondRetErro
	BarP_CondRetOk
*/

/************** Novas Fun��es de Acesso *********************/

BarPrincCondRet exibeCartasBarPrinc(BarP_tppBarPrinc barP);
/*
Objetivo: Abre a ultima carta do barallho se ela estiver fechada, se j� estiver aberta n�o faz nada
Par�metros;
	barP -> O baralho que se deseja abrir a ultima carta
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet abreUltCarta(BarP_tppBarPrinc barP);
/*
Objetivo: Conta quantas cartas abertas tem no baralho
Par�metros;
	barP -> O baralho que se deseja contar
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet contaQtdCartasAbertas(BarP_tppBarPrinc barP, int* qtd);
/*
Objetivo: Obtem os valores da ultima carta do baralho
Par�metros;
	barP -> O baralho principal que se deseja obter a carta
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet obterValoresUltCarta(BarP_tppBarPrinc barP, int* valor, char* naipe);
/*
Objetivo: Verifica se as cartas abertas s�o uma sequ�ncia de A's a Reis
Par�metros;
	barP -> O baralho que se deseja consultar
Retorno:
	BarP_CondRetOk		Se for Sequencia completa
	BarP_CondRetNaoSeq  Quando n�o � sequencia
	BarP_CondRetErro
*/
BarPrincCondRet verificaSequenciaFormada(BarP_tppBarPrinc barP);
/*
Objetivo: Retira a carta no topo da pilha e adquire o seu valor por refer�ncia
Par�metros;
	barP -> O baralho que se deseja tirar a carta
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet pegarCartaBarP(BarP_tppBarPrinc barP, tppCarta* carta);

// Func�o usada no m�dulo

/*
Objetivo: Obtem o tamanho do baralho
Par�metros;
	barP -> O baralho a ser contado
Retorno:
	int tamanho
*/

/******* Fun��o usada pelo m�dulo *********/
int obterTamanhoBarP(BarP_tppBarPrinc barP);

#endif
