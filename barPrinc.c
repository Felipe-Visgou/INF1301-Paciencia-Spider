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
#include <stdlib.h>
#include "barPrinc.h"

// Descritor da estrutura baralho principal
typedef struct barPrn
{
	PIL_tppPilha pilha;
} BarP_tgBarPrinc;

/***************************************************************************
*
*  Fun��o: Criar Baralho Principal
*  ****/
BarPrincCondRet criarBaralhoPrincipal(BarP_tppBarPrinc* barPrinc)
{
	*barPrinc = (BarP_tppBarPrinc)malloc(sizeof(BarP_tgBarPrinc));
	
	// Verifica se foi poss�vel criar o baralho principal
	if (!barPrinc)
		return BarP_CondRetNaoCriou;

	// Cria a pilha utilizada pelo baralho, verificando se foi bem sucedida
	if (criarPilha(&(*barPrinc)->pilha) == PIL_CondRetNaoCriou)
		return BarP_CondRetNaoCriou;
	else
		return BarP_CondRetOk;
} /* Fim Fun��o: Criar Baralho Principal */

/***************************************************************************
*
*  Fun��o: Destruir Baralho
*  ****/

BarPrincCondRet destrBaralhoPrincipal(BarP_tppBarPrinc barPrinc)
{
	// Destr�i a pilha associada ao baralho
	if (destrPilha(barPrinc->pilha) == PIL_CondRetNaoExiste)
		return BarP_CondRetNaoExiste;

	// Destr�i o baralho principal
	free(barPrinc);
	return BarP_CondRetOk;
} /* Fim Fun��o: Destruir Baralho Principal */

/***************************************************************************
*
*  Fun��o: Transferir Cartas pelos Baralhos Principais
*  ****/

BarPrincCondRet transferirCartasBarP(BarP_tppBarPrinc fonte, BarP_tppBarPrinc destino, int qntd)
{
	int i, ultCartaValor = 0, primCartaValor = 0, ultCartaAberta = 0, primCartaAberta = 0, tam;
	char ultCartaNaipe = 0, primCartaNaipe = 0;
	void *CauxD;
	int  valor,aberta,valorAnterior, qtdAberta;
	char naipe, naipeAnterior;
	tppCarta vetAux[12];
	tppCarta ultCarta, primCarta;
	BarP_tppBarPrinc barAux = NULL;

	// Caso n�o exista baralho principal
	if (!fonte && !destino)		return BarP_CondRetNaoExiste;
	tam = obterTamanhoBarP(destino);
	if(contaQtdCartasAbertas(fonte, &qtdAberta)!= BarP_CondRetOk)
		return BarP_CondRetErro;
	// Se a quantidade de cartas a serem movidas for maior do que a quantidade de cartas que podem ser movidas...
	if(qtdAberta < qntd)
		return BarP_CondRetRegra;
	// se o baralho Destino estiver vazio, n�o checa nada e faz a tranfer�ncia
	if(tam == 0)
	{
	for( i = 0; i < qntd ; i++)
		pegarCartaBarP(fonte, &vetAux[i]);
		if(qntd > 1) // se quero mover mais de uma carta, elas tem que ser sequencia de mesmo naipe
		{
		for(i = qntd-1; i > 0; i--)
		{
			obterValorCarta(vetAux[i], &naipe, &valor, &aberta);
			obterValorCarta(vetAux[i-1], &naipeAnterior, &valorAnterior,&aberta);
			if((naipe != naipeAnterior) && valor != (valorAnterior) +1) // se n�o � sequencia, restaura o vetor fonte e retorna
			{
				for(i= qntd-1; i >= 0; i--)
					adicionarCartasBarP(fonte, vetAux[i]);
				return BarP_CondRetRegra;
			}
		}
		}
		// bota as cartas do vetor na pilha destino
		for(i = qntd -1; i >= 0; i--) {
			if(adicionarCartasBarP(destino, vetAux[i])!= BarP_CondRetOk)
				return BarP_CondRetErro;
		}
		return BarP_CondRetOk;
	}
	// Descobre qual a �ltima carta do baralho principal
	if (obterValorPilha(destino->pilha, &CauxD) != PIL_CondRetOk)
		return BarP_CondRetErro;
	else
		ultCarta = (tppCarta)CauxD;
	// descobre o valor da carta no baralho fonte
	for(i = 0; i < qntd; i++)
	{
		pegarCartaBarP(fonte, &vetAux[i]);
		primCarta = vetAux[i]; // primCarta vai acabar apontando pra carta desejada
	}
	if(qntd > 1) // se quero mover mais de uma carta, elas tem que ser sequencia de mesmo naipe
	{
		for(i = qntd -1; i > 0; i--)
		{
			obterValorCarta(vetAux[i], &naipe, &valor, &aberta);
			obterValorCarta(vetAux[i-1], &naipeAnterior, &valorAnterior,&aberta);
			if((naipe != naipeAnterior) || (valor != (valorAnterior) +1)) // se n�o � sequencia, restaura o vetor fonte e retorna
			{
				for(i= qntd-1; i >= 0; i--)
					adicionarCartasBarP(fonte, vetAux[i]);
				return BarP_CondRetRegra;
			}
		}
	}
	// Obtem os valores das duas cartas e verifica a regra de transfer�ncia
	if(obterValorCarta(ultCarta, &ultCartaNaipe, &ultCartaValor, &ultCartaAberta)!= CAR_CondRetOk)
		return BarP_CondRetErro;
	if(obterValorCarta(primCarta, &primCartaNaipe, &primCartaValor, &primCartaAberta)!= CAR_CondRetOk)
		return BarP_CondRetErro;
	if((primCartaValor != (ultCartaValor) -1) || (primCartaAberta == 0 || ultCartaAberta == 0))
	{
		// se n�o estiver na regra, n�o transfere e restaura o vetor fonte
		for(i = qntd-1; i >=0 ; i--)
			adicionarCartasBarP(fonte, vetAux[i]);
		return BarP_CondRetRegra;
	}
	else
	{
		// adiciona as cartas do vetor auxiliar no baralho destino
		for(i = qntd-1; i>=0; i--)
			adicionarCartasBarP(destino, vetAux[i]);
		return BarP_CondRetOk;
	}
} /* Fim Fun��o: Transferir Cartas pelos Baralhos Principais */

/***************************************************************************
*
*  Fun��o: Adicionar Carta
*  ****/

BarPrincCondRet adicionarCartasBarP(BarP_tppBarPrinc barP, tppCarta carta)
{
	// Verifica a exist�ncia da carta e do baralho
	if (!barP || !carta)
		return BarP_CondRetNaoExiste;
	else if (adicionarElementoPilha(barP->pilha, carta) != PIL_CondRetOk)
		return BarP_CondRetErro;
	else
		return BarP_CondRetOk;
} /* Fim Fun��o: Adicionar Cartas no Baralho Principal */

/***************************************************************************
*
*  Fun��o: Exibe Baralho Principal
*  ****/

BarPrincCondRet exibeCartasBarPrinc(BarP_tppBarPrinc barP)
{
	if(exibePilha(barP->pilha) != PIL_CondRetOk)
		return BarP_CondRetErro;
	return BarP_CondRetOk;
}/* Fim Fun��o: Exibe Baralho Principal */

/***************************************************************************
*
*  Fun��o: Abre a carta do topo
*  ****/

BarPrincCondRet abreUltCarta(BarP_tppBarPrinc barP)
{
	void* Caux;
	char Cnaipe;
	int Cvalor, Caberta, tam;
	if(obterTamanhoPilha(barP->pilha, &tam)!= PIL_CondRetOk) 
		return BarP_CondRetErro;
	if(tam == 0) // Se a pilha estiver vazia ent�o n�o faz nada
		return BarP_CondRetOk;
	obterValorPilha(barP->pilha, &Caux);
	obterValorCarta((tppCarta)Caux, &Cnaipe, &Cvalor, &Caberta);
	if(!Caberta) // Se a carta est� fechada... ent�o abre
		if(abreCarta((tppCarta)Caux) != CAR_CondRetOk)
			return BarP_CondRetErro;
	return BarP_CondRetOk;
} /* Fim Fun��o: Abre a carta do topo do Baralho Principal */

/***************************************************************************
*
*  Fun��o: Conta quantas cartas abertas possui o Baralho Principal 
*  ****/

BarPrincCondRet contaQtdCartasAbertas(BarP_tppBarPrinc barP, int* qtd)
{
	tppCarta Caux[54]; // Vetor de Carta Auxiliar
	int tam, i=0,j;
	int ValorObt, AbertaObt, cont = 0;
	char NaipeObt;
	tppCarta car;
	obterTamanhoPilha(barP->pilha, &tam); // cont possui o tamanho da pilha
	if(tam == 0) {
		*qtd = 0;
		return BarP_CondRetOk;
	}
	else {
	if(tam == 1) {
		// verifica se a carta est� aberta
		pegarCartaBarP(barP, &car); // Retira a carta do barlho principal e guarda num vetor
		if(obterValorCarta(car, &NaipeObt, &ValorObt, &AbertaObt)!= CAR_CondRetOk)
			return BarP_CondRetErro;
		if(AbertaObt == 0) {
			*qtd = 0;
		} else
			*qtd = 1;
	   // Restaura o baralho principal com a carta que foi retirada
		adicionarCartasBarP(barP, car);
		return BarP_CondRetOk;
	}
	}
	for(j = 0; j < tam; j++)
		pegarCartaBarP(barP, &Caux[j]); // Retira a carta do barlho principal e guarda num vetor
	if(obterValorCarta(Caux[0], &NaipeObt, &ValorObt, &AbertaObt)!= CAR_CondRetOk)
		return BarP_CondRetErro;
	while (AbertaObt != 0 && cont < tam) {
		cont++;
		if(obterValorCarta(Caux[cont], &NaipeObt, &ValorObt, &AbertaObt)!= CAR_CondRetOk)
			return BarP_CondRetErro;
	}
		for(i = tam -1 ; i >= 0; i--) // Restaura o baralho principal com as cartas que foram retiradas
			adicionarCartasBarP(barP, Caux[i]);
		*qtd = cont;
	return BarP_CondRetOk;
} /* Fim Fun��o: Conta quantas cartas abertas possui o Baralho Principal */

/***************************************************************************
*
*  Fun��o: Obtem Valores da carta do topo
*  ****/

BarPrincCondRet obterValoresUltCarta(BarP_tppBarPrinc barP, int* valor, char* naipe)
{
	int aberta, v;
	char n;
	void* Caux;
	if(obterValorPilha(barP->pilha, &Caux)!= PIL_CondRetOk) // obtem o elemento no topo da pilha
		return BarP_CondRetErro;
	if(obterValorCarta((tppCarta)Caux, &n, &v, &aberta)!= CAR_CondRetOk) // obtem os valores da carta
		return BarP_CondRetErro;
	*valor = v;
	*naipe = n;
	return BarP_CondRetOk;
} /* Fim Fun��o: Obtem Valores do topo */

/***************************************************************************
*
*  Fun��o: Pegar Carta do topo
*  ****/
BarPrincCondRet pegarCartaBarP(BarP_tppBarPrinc barP, tppCarta* carta)
{
	if(obterValorPilha(barP->pilha, (void**)carta)!= PIL_CondRetOk) // obtem o elemento no topo da pilha
		return BarP_CondRetErro;

	if(removerElementoPilha(barP->pilha) != PIL_CondRetOk) // Retira do baralho o elemento obtido
		return BarP_CondRetErro;

	return BarP_CondRetOk;
} /* Fim Fun��o: Pegar Carta do topo */

/***************************************************************************
*
*  Fun��o: Verifica Sequencia Formada
*  ****/
	
BarPrincCondRet verificaSequenciaFormada(BarP_tppBarPrinc barP)
{
	tppCarta vetAux[13];
	int qtdCarta, valor1,valor2, tam;
	char naipe1, naipe2;
	int l, i = 0;
	void *Caux1, *Caux2;
	if(contaQtdCartasAbertas(barP, &qtdCarta)!= BarP_CondRetOk)
		return BarP_CondRetErro;
	if(qtdCarta < 13)
		return BarP_CondRetNaoSeq;
	else
	{
		while(i < 13 )
		{
			obterValorPilha(barP->pilha, &Caux1); // obtem o elemento no topo do baralho
			obterValorCarta((tppCarta)Caux1, &naipe1, &valor1, &l); // obtem seus valores
			pegarCartaBarP(barP, &vetAux[i]); // retira do baralho a carta
			obterValorPilha(barP->pilha, &Caux2); // obtem o porximo elemento da pilha
			obterValorCarta((tppCarta)Caux2, &naipe2, &valor2, &l); // obtem seus valores
			i++;
			if(valor1 != (valor2 - 1) && naipe1 != naipe2) { // checa se � sequencia de mesmo naipe, se n�o for
				for(tam = i-1; tam >= 0; tam--)  // restaura o vetor original com as cartas que foram retiradas
					adicionarCartasBarP(barP, vetAux[tam]);
			return BarP_CondRetNaoSeq;
			}		
		}
	}
	// restaura o baralho principal
	for(tam = 12; tam >= 0; tam--) // restaura o vetor original com as cartas que foram retiradas
		adicionarCartasBarP(barP, vetAux[tam]);
		return BarP_CondRetOk;
} /* Fim Fun��o: Verifica Sequencia Formada */

int obterTamanhoBarP(BarP_tppBarPrinc barP)
{
	int tam;
	if(obterTamanhoPilha(barP->pilha, &tam)!= PIL_CondRetOk)
		return -1;
	return tam;
}






