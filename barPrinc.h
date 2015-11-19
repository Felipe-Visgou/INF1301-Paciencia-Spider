/* Módulo Baralho Principal: Módulo referente aos 10 baralho principais do jogo Paciência Spider

Modificado 27/05 Implementação
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

/* Tipo referência para um baralho principal */
typedef struct barPrn* BarP_tppBarPrinc;

// Condições de retorno da função
typedef enum {
	BarP_CondRetOk,					// Concluiu corretamente
	BarP_CondRetErro,				// Ocorreu um erro durante a transferência
	BarP_CondRetRegra,			// Não respeitou a regra de transferir carta
	BarP_CondRetNaoExiste,	// Baralho principal passado não existe
	BarP_CondRetNaoCriou, // Não foi possivel criar o baralho principal
	BarP_CondRetNaoSeq,
} BarPrincCondRet;


/*********** Funcões de acesso ********************/

/*
Objetivo: Criar um baralho principal
Parâmetros:
	barPrinc -> Ponteiro que apontará para um baralho principal se a função for bem sucedida
Retorno:
	BarP_CondRetOk
	BarP_CondRetNaoCriou
*/
BarPrincCondRet criarBaralhoPrincipal(BarP_tppBarPrinc* barPrinc);

/*
Objetivo: Destroir um baralho principal
Parâmetros:
	barPrinc -> O baralho principal que será destroido
Retorno:
	BarP_CondRetNaoExiste
	BarP_CondRetOk
*/
BarPrincCondRet destrBaralhoPrincipal(BarP_tppBarPrinc barPrinc);

/*
Objetivo: Retira cartas de um dos baralhos principais
					e adiciona as cartas removidas em outro baralho qualquer
Parâmetros:
	fonte		-> O baralho principal (obrigatoriamente) que terá suas cartas removidas
	destino	-> O baralho receberá as cartas removidas de fonte
	qntd		-> A quantidade de cartas que serã transferidas
Retorno:
	BarP_CondRetOk
	BarP_CondRetErro
	BarP_CondRetRegra
	BarP_CondRetNaoExiste
*/
BarPrincCondRet transferirCartasBarP(BarP_tppBarPrinc fonte, BarP_tppBarPrinc destino, int qntd);

/*
Objetivo: Adiciona uma carta ao baralho principal sem abrir a mesma e sem seguir nenhuma regra
Parâmetros:
	barPrinc	-> O baralho que receberá a carta
	carta			-> A carta a ser adicionada ao baralho principal
Retorno:
	BarP_CondRetOk
	BarP_CondRetErro
	BarP_CondRetNaoExiste
*/
BarPrincCondRet adicionarCartasBarP(BarP_tppBarPrinc barP, tppCarta carta);

/*
Objetivo: Exibe as cartas do baralho principal
Parâmetros
	barP -> o baralho principal a ser exibido
Retorno
	BarP_CondRetErro
	BarP_CondRetOk
*/

/************** Novas Funções de Acesso *********************/

BarPrincCondRet exibeCartasBarPrinc(BarP_tppBarPrinc barP);
/*
Objetivo: Abre a ultima carta do barallho se ela estiver fechada, se já estiver aberta não faz nada
Parâmetros;
	barP -> O baralho que se deseja abrir a ultima carta
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet abreUltCarta(BarP_tppBarPrinc barP);
/*
Objetivo: Conta quantas cartas abertas tem no baralho
Parâmetros;
	barP -> O baralho que se deseja contar
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet contaQtdCartasAbertas(BarP_tppBarPrinc barP, int* qtd);
/*
Objetivo: Obtem os valores da ultima carta do baralho
Parâmetros;
	barP -> O baralho principal que se deseja obter a carta
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet obterValoresUltCarta(BarP_tppBarPrinc barP, int* valor, char* naipe);
/*
Objetivo: Verifica se as cartas abertas são uma sequência de A's a Reis
Parâmetros;
	barP -> O baralho que se deseja consultar
Retorno:
	BarP_CondRetOk		Se for Sequencia completa
	BarP_CondRetNaoSeq  Quando não é sequencia
	BarP_CondRetErro
*/
BarPrincCondRet verificaSequenciaFormada(BarP_tppBarPrinc barP);
/*
Objetivo: Retira a carta no topo da pilha e adquire o seu valor por referência
Parâmetros;
	barP -> O baralho que se deseja tirar a carta
Retorno:
	BarP_CondRetOk
	BarP_CondRetEro
*/
BarPrincCondRet pegarCartaBarP(BarP_tppBarPrinc barP, tppCarta* carta);

// Funcão usada no módulo

/*
Objetivo: Obtem o tamanho do baralho
Parâmetros;
	barP -> O baralho a ser contado
Retorno:
	int tamanho
*/

/******* Função usada pelo módulo *********/
int obterTamanhoBarP(BarP_tppBarPrinc barP);

#endif
