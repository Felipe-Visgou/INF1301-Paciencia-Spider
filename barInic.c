/* Módulo Baralho Inicial: Módulo referente ao baralho Inicial com as 104 cartas
*
* Modificado: 27/05 Ajustes na implementação
*			28/05 Preenche o baralho já embaralhado
*			28/05 Testado e ajustado
*			06/06 ajustes finais
*/
#include <stdlib.h>
#include "barInic.h"


#define A 1
#define K 13

// Descritor da estrutura baralho inicial
typedef struct barIni
{
	PIL_tppPilha pilha;
} BarI_tpBarInicial;

/***************************************************************************
*
*  Função: Criar Baralho Inicial
*  ****/
BarIniCondRet criarBarIni(BarI_tppBarInicial* barIni)
{
	*barIni = (BarI_tppBarInicial)malloc(sizeof(BarI_tpBarInicial));

	// Verifica se conseguiu criar o baralho inicial
	if (!barIni)
		return BarI_CondRetNaoCriou;

	// Cria a pilha usada pelo baralho
	 if ((criarPilha(&(*barIni)->pilha)) == PIL_CondRetNaoCriou)
	 {
		 destruirBarIni((*barIni));
		 return BarI_CondRetNaoCriou;
	 }
	 else
		 return BarI_CondRetOk;
} /* Fim Função: Criar Baralho Inicial */

/***************************************************************************
*
*  Função: Destruir Baralho Inicial
*  ****/

BarIniCondRet destruirBarIni(BarI_tppBarInicial barIni)
{
	// Destrói a pilha usada pelo baralho inicial
	if (destrPilha(barIni->pilha) != PIL_CondRetOk)
		return BarI_CondRetNaoExiste;

	// Destrói o baralho
	free(barIni);
	return BarI_CondRetOk;
} /* Fim Função: Destruir Baralho Inicial */

/***************************************************************************
*
*  Função: Preencher Baralho Inicial 
*  ****/

BarIniCondRet preencherBarInic(BarI_tppBarInicial barInic, int dificuldade)
{
	int seq, valor, n, R, i = 0;
	int F = 103;
	tppCarta vc[104];


	// Se não for uma dificuldade válida
	if (dificuldade < 1 || dificuldade > 4)
		return BarI_CondRetErro;

	// Verifica a existência do baralho inicial
	if (!barInic)
		return BarI_CondRetNaoExiste;

	// Preenche o baralho com as cartas
	switch(dificuldade)
	{
	case 1:
		// Em cada baralho, se tem 4 sequências de 13 cartas
		// Como estamos trabalhando com 2 baralhos e 1 naipe,
		// dá um total de 8 sequências de 13 cartas de espadas
		for (seq = 0; seq < 8; seq++)
		{
			for (valor = 1; valor <= 13; valor++)
			{
				// Cria uma carta e valida
				tppCarta carta = NULL;
				if (criarCarta('e', valor, &carta) != CAR_CondRetOk)
					return BarI_CondRetNaoCriou;
				vc[i++] = carta;
			}
		}
		for(;F > 0; F--)
		{
			R = (rand() % F);
			if (adicionarElementoPilha(barInic->pilha, (void*)vc[R]) != PIL_CondRetOk)
					return BarI_CondRetErro;
			vc[R] = vc[F];
		}
		if (adicionarElementoPilha(barInic->pilha, (void*)vc[F]) != PIL_CondRetOk)
					return BarI_CondRetErro;
		break;

	case 2:
		// Em cada baralho, se tem 4 sequências de 13 cartas
		// Como estamos trabalhando com 2 baralhos e 2 naipes,
		// dá um total de 4 sequências de 13 cartas de espadas
		// e 4 sequências de 13 cartas de paus
		for (n = 0; n < 2; n++)
		{
			char naipe;

			// Definindo o naipe
			if (n == 0)
				naipe = 'e';
			else if (n == 1)
				naipe = 'p';

			for (seq = 0; seq < 4; seq++)
			{
				for (valor = A; valor <= K; valor++)
				{
					// Cria uma carta e valida
					tppCarta carta = NULL;
					if (criarCarta(naipe, valor, &carta) != CAR_CondRetOk)
						return BarI_CondRetNaoCriou;
					vc[i++] = carta;
				}
			}
		}
		for(;F > 0; F--)
		{
			R = (rand() % F);
			if (adicionarElementoPilha(barInic->pilha, (void*)vc[R]) != PIL_CondRetOk)
					return BarI_CondRetErro;
			vc[R] = vc[F];
		}
		if (adicionarElementoPilha(barInic->pilha, (void*)vc[F]) != PIL_CondRetOk)
						return BarI_CondRetErro;
		break;

	case 3:
		// Em cada baralho, se tem 4 sequências de 13 cartas
		// Como estamos trabalhando com 2 baralhos e 3 naipes,
		// dá um total de 2 sequências de 13 cartas de espadas,
		// 3 sequências de 13 cartas de paus e 3 sequências de
		// 13 cartas de ouros
		for (n = 0; n < 2; n++)
		{
			char naipe;

			// Definindo o naipe
			if (n == 0)
				naipe = 'e';
			else if (n == 1)
				naipe = 'p';
			for (seq = 0; seq < 3; seq++)
			{
				for (valor = A; valor <= K; valor++)
				{
					// Cria uma carta e valida
					tppCarta carta = NULL;
					if (criarCarta(naipe, valor, &carta) != CAR_CondRetOk)
						return BarI_CondRetNaoCriou;
					vc[i++] = carta;
				}
			}
		}
		for (seq = 0; seq < 2; seq++)
			{
				for (valor = A; valor <= K; valor++)
				{
					// Cria uma carta e valida
					tppCarta carta = NULL;
					if (criarCarta('o', valor, &carta) != CAR_CondRetOk)
						return BarI_CondRetNaoCriou;
					vc[i++] = carta;
				}
			}
		for(;F > 0; F--)
		{
			R = (rand() % F);
			if (adicionarElementoPilha(barInic->pilha, (void*)vc[R]) != PIL_CondRetOk)
					return BarI_CondRetErro;
			vc[R] = vc[F];
		}
		if (adicionarElementoPilha(barInic->pilha, (void*)vc[F]) != PIL_CondRetOk)
					return BarI_CondRetErro;
		break;

	case 4:
		// Em cada baralho, se tem 4 sequências de 13 cartas
		// Como estamos trabalhando com 2 baralhos e 4 naipes,
		// dá um total de 2 sequências de 13 cartas para cada naipe
		for (n = 0; n < 4; n++)
		{
			char naipe;

			// Definindo o naipe
			if (n == 0)
				naipe = 'e';
			else if (n == 1)
				naipe = 'p';
			else if (n == 2)
				naipe = 'o';
			else
				naipe = 'c';

			for (seq = 0; seq < 2; seq++)
			{
				for (valor = A; valor <= K; valor++)
				{
					// Cria uma carta e valida
					tppCarta carta = NULL;
					if (criarCarta(naipe, valor, &carta) != CAR_CondRetOk)
						return BarI_CondRetNaoCriou;
					vc[i++] = carta;
				}
			}
		}
		for(;F > 0; F--)
		{
			R = (rand() % F);
			if (adicionarElementoPilha(barInic->pilha, (void*)vc[R]) != PIL_CondRetOk)
					return BarI_CondRetErro;
			vc[R] = vc[F];
		}
		if (adicionarElementoPilha(barInic->pilha, (void*)vc[F]) != PIL_CondRetOk)
					return BarI_CondRetErro;
		break;

	default:
		return BarI_CondRetErro;
	}

	return BarI_CondRetOk;
} /* Fim Função: Preencher Baralho Inicial  */

/***************************************************************************
*
*  Função: Pegar carta do topo
*  ****/

BarIniCondRet pegarCartaBarInic(BarI_tppBarInicial barInic, tppCarta* carta)
{
	// Verifica a existência do baralho
	if (!barInic)
		return BarI_CondRetNaoExiste;

	// Obtém o valor da carta
	if (obterValorPilha(barInic->pilha, (void**)carta) == PIL_CondRetNaoExiste)
		return BarI_CondRetErro;

	// Retira carta do baralho
	if (removerElementoPilha(barInic->pilha) != PIL_CondRetOk)
		return BarI_CondRetErro;

	return BarI_CondRetOk;
} /* Fim Função:  Pegar carta do topo */