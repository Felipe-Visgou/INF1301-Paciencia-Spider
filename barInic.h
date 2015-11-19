/* M�dulo Baralho Inicial: M�dulo referente ao baralho Inicial com as 104 cartas
*
* Modificado: 27/05 Ajustes na implementa��o
*			28/05 Preenche o baralho j� embaralhado
*			28/05 Testado e ajustado
*			06/06 ajustes finais
*/
#ifndef BARALHO_INICIAL_H
#define BARALHO_INICIAL_H


#include "pilhaCarta.h"
#include "carta.h"

/* Tipo refer�ncia para um baralho inicial */
typedef struct barIni* BarI_tppBarInicial;

// Condi��es de retorno da fun��o
typedef enum {
	BarI_CondRetOk,					// Concluiu corretamente
	BarI_CondRetErro,				// Ocorreu um erro durante o processo
	BarI_CondRetNaoExiste,	// Baralho inicial passada n�o existe
	BarI_CondRetNaoCriou,		// N�o foi poss�vel criar uma estrutura durante o processo
} BarIniCondRet;

// Fun��es de Acesso

/*
Objetivo: Criar um baralho inicial
Par�metros:
	barIni	-> Ponteiro que apontar� para um baralho inicial se a fun��o for bem sucedida
Retorno:
	BarI_CondRetNaoCriou
	BarI_CondRetOk
*/
BarIniCondRet criarBarIni(BarI_tppBarInicial* barIni);

/*
Objetivo: Destruir um baralho inicial
Par�metros:
	barIni	-> O baralho inicial que se deseja destruir
Retorno:
	BarI_CondRetNaoExiste
	BarI_CondRetOk
*/
BarIniCondRet destruirBarIni(BarI_tppBarInicial barIni);

/*
Objetivo: Embaralhar as cartas do baralho inicial
Par�metros:
	barInic	-> O baralho inicial que ser� embaralhado
Retorno:
	
BarIniCondRet		embaralhar(Pilha* barInic);
	BarI_CondRetOk
	BarI_CondRetErro
	BarI_CondRetNaoExiste
*/
BarIniCondRet	embaralharBarIni(BarI_tppBarInicial barInic);

/*
Objetivo: Preenche o baralho inicial com cartas, de acordo com a dificuldade do jogo
Par�metros:
	barInic			-> O baralho inicial que ser� preenchido com as cartas
	dificuldade	-> A dificuldade do jogo definida pelo usu�rio
Retorno:
	BarI_CondRetOk
	BarI_CondRetErro
	BarI_CondRetNaoExiste
	BarI_CondRetSemMemoria
*/
BarIniCondRet preencherBarInic(BarI_tppBarInicial barInic, int dificuldade);

/*
Objetivo: Retirar uma carta do baralho inicial
Par�metros:
	barInic	-> O baralho inicial que perder� uma carta
	carta		-> Ponteiro para a carta retirada se a fun��o for bem sucedida
Retorno:
	BarI_CondRetNaoExiste
	BarI_CondRetErro
	BarI_CondRetOk
*/
BarIniCondRet pegarCartaBarInic(BarI_tppBarInicial barInic, tppCarta* carta);

#endif