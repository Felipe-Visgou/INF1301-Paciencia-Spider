/* Módulo Baralho Inicial: Módulo referente ao baralho Inicial com as 104 cartas
*
* Modificado: 27/05 Ajustes na implementação
*			28/05 Preenche o baralho já embaralhado
*			28/05 Testado e ajustado
*			06/06 ajustes finais
*/
#ifndef BARALHO_INICIAL_H
#define BARALHO_INICIAL_H


#include "pilhaCarta.h"
#include "carta.h"

/* Tipo referência para um baralho inicial */
typedef struct barIni* BarI_tppBarInicial;

// Condições de retorno da função
typedef enum {
	BarI_CondRetOk,					// Concluiu corretamente
	BarI_CondRetErro,				// Ocorreu um erro durante o processo
	BarI_CondRetNaoExiste,	// Baralho inicial passada não existe
	BarI_CondRetNaoCriou,		// Não foi possível criar uma estrutura durante o processo
} BarIniCondRet;

// Funções de Acesso

/*
Objetivo: Criar um baralho inicial
Parâmetros:
	barIni	-> Ponteiro que apontará para um baralho inicial se a função for bem sucedida
Retorno:
	BarI_CondRetNaoCriou
	BarI_CondRetOk
*/
BarIniCondRet criarBarIni(BarI_tppBarInicial* barIni);

/*
Objetivo: Destruir um baralho inicial
Parâmetros:
	barIni	-> O baralho inicial que se deseja destruir
Retorno:
	BarI_CondRetNaoExiste
	BarI_CondRetOk
*/
BarIniCondRet destruirBarIni(BarI_tppBarInicial barIni);

/*
Objetivo: Embaralhar as cartas do baralho inicial
Parâmetros:
	barInic	-> O baralho inicial que será embaralhado
Retorno:
	
BarIniCondRet		embaralhar(Pilha* barInic);
	BarI_CondRetOk
	BarI_CondRetErro
	BarI_CondRetNaoExiste
*/
BarIniCondRet	embaralharBarIni(BarI_tppBarInicial barInic);

/*
Objetivo: Preenche o baralho inicial com cartas, de acordo com a dificuldade do jogo
Parâmetros:
	barInic			-> O baralho inicial que será preenchido com as cartas
	dificuldade	-> A dificuldade do jogo definida pelo usuário
Retorno:
	BarI_CondRetOk
	BarI_CondRetErro
	BarI_CondRetNaoExiste
	BarI_CondRetSemMemoria
*/
BarIniCondRet preencherBarInic(BarI_tppBarInicial barInic, int dificuldade);

/*
Objetivo: Retirar uma carta do baralho inicial
Parâmetros:
	barInic	-> O baralho inicial que perderá uma carta
	carta		-> Ponteiro para a carta retirada se a função for bem sucedida
Retorno:
	BarI_CondRetNaoExiste
	BarI_CondRetErro
	BarI_CondRetOk
*/
BarIniCondRet pegarCartaBarInic(BarI_tppBarInicial barInic, tppCarta* carta);

#endif