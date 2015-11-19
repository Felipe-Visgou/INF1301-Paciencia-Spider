/* M�dulo Principal: M�dulo referente � execu��o correta do jogo de Paci�ncia Spider

Autor: Felipe Vieira C�rtes
Criado 29/05
Modificado 30/05 Implementa��o
		   31/05 ...
		   01/06 ...
		   02/06 ...
		   03/06 ...
		   04/06 ...
		   05/06 ...
		   06/06 Ajustes finais
*/
#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "barInic.h"
#include "barPrinc.h"
#include "barExtra.h"
#include "barFinal.h"

// Fun��es usadas no M�dulo Principal

/* Salvar Jogo
*
*	Grava o estado atual do jogo em um arquivo txt
*
*/
void salvarJogo(LIS_tppLista estrutura);

/* Carregar Jogo
*
*	L� o arquivo txt que possui o jogo salvo e restaura o jogo
*
*/
LIS_tppLista carregaJogo(FILE** Game);

/* Conta quantas cartas est�o na mesa */
void countBarPrinc();

/* Exibe os baralhos principais do jogo */
void exibe();

/* Verifica se sempre a �ltima carta dos baralhos est�o abertas */
void verify();

#endif