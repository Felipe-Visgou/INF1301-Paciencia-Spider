/* Módulo Principal: Módulo referente à execução correta do jogo de Paciência Spider

Autor: Felipe Vieira Côrtes
Criado 29/05
Modificado 30/05 Implementação
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

// Funções usadas no Módulo Principal

/* Salvar Jogo
*
*	Grava o estado atual do jogo em um arquivo txt
*
*/
void salvarJogo(LIS_tppLista estrutura);

/* Carregar Jogo
*
*	Lê o arquivo txt que possui o jogo salvo e restaura o jogo
*
*/
LIS_tppLista carregaJogo(FILE** Game);

/* Conta quantas cartas estão na mesa */
void countBarPrinc();

/* Exibe os baralhos principais do jogo */
void exibe();

/* Verifica se sempre a última carta dos baralhos estão abertas */
void verify();

#endif