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
#include <stdio.h>
#include <stdlib.h>
#include "PRINCIPAL.h"
BarP_tppBarPrinc P1, P2, P3, 
				P4, P5, P6, 
				P7, P8, P9, P10;
BarI_tppBarInicial barI;
BarE_tppBarExtra barE;
BarF_tppBarFinal barF;
BarP_tppBarPrinc PF, PD;

void countBarPrinc() {
	printf("Cartas na mesa = %d \n", obterTamanhoBarP(P1) + obterTamanhoBarP(P2) + obterTamanhoBarP(P3) + obterTamanhoBarP(P4) + obterTamanhoBarP(P5) + obterTamanhoBarP(P6) + obterTamanhoBarP(P7) + obterTamanhoBarP(P8) + obterTamanhoBarP(P9) + obterTamanhoBarP(P10));
}

void exibe() {
					printf(" 1: |");
				if(exibeCartasBarPrinc(P1) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 2: |");
				if(exibeCartasBarPrinc(P2) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 3: |");
				if(exibeCartasBarPrinc(P3) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 4: |");
				if(exibeCartasBarPrinc(P4) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 5: |");
				if(exibeCartasBarPrinc(P5) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 6: |");
				if(exibeCartasBarPrinc(P6) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 7: |");
				if(exibeCartasBarPrinc(P7) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 8: |");
				if(exibeCartasBarPrinc(P8) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 9: |");
				if(exibeCartasBarPrinc(P9) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
				printf(" 10: |");
				if(exibeCartasBarPrinc(P10) != BarP_CondRetOk)
					printf(" ERRO AO EXIBIR O BARALHO \n");
}

void verify()
{
	abreUltCarta(P1);
	abreUltCarta(P2);
	abreUltCarta(P3);
	abreUltCarta(P4);
	abreUltCarta(P5);
	abreUltCarta(P6);
	abreUltCarta(P7);
	abreUltCarta(P8);
	abreUltCarta(P9);
	abreUltCarta(P10);
}
int main (void) {
	FILE* Game;
	int resp, dificuldade, i, j;
	// Variáveis do jogo
	int qtdCartas, baralhoFonte, baralhoDestino, numCartaAberta, rTrans = 0, rConta = 0, dec, contcompra, w1 = 1;
	int jogar = 1;
	BarP_tppBarPrinc Paux;
	int valorCarta;
	int qtdBarFinal;
	char naipeCarta;
	tppCarta cartaAux;
	LIS_tppLista estr = LIS_CriarLista(NULL);
	printf(" \n ________________________________________________________________ \n");
	// MENU
	while(jogar == 1) {
	qtdBarFinal = 0;
	printf(" MENU \n 1: Novo Jogo \n 2: Carregar Jogo \n 0: Sair \n");
	scanf("%d", &resp);
	while(w1)
	{
		if( resp == 0) return 0;
		if(resp == 1)
		{
			// Cria os 10 baralhos principais, o monte extra, e o final
			criarBarIni(&barI);
			criarBaralhoPrincipal(&P1); criarBaralhoPrincipal(&P2);
			criarBaralhoPrincipal(&P3); criarBaralhoPrincipal(&P4);
			criarBaralhoPrincipal(&P5); criarBaralhoPrincipal(&P6);
			criarBaralhoPrincipal(&P7); criarBaralhoPrincipal(&P8);
			criarBaralhoPrincipal(&P9); criarBaralhoPrincipal(&P10);
			criarBarExtra(&barE);
			criarBarFinal(&barF);
			// Insere na lista de listas os 10 baralhos principais, o monte extra e o final
			if((LIS_InserirElementoApos(estr, P1)) != LIS_CondRetOK)
				printf(" \n ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P2)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P3)) != LIS_CondRetOK)
				printf(" \n ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P4)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P5)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P6)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P7)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P8)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P9)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, P10)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, barE)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			if((LIS_InserirElementoApos(estr, barF)) != LIS_CondRetOK)
				printf(" ERRO NA CRIACAO \n");
			// Escolher a dificuldade
			printf(" Escolha a dificuldade \n 1: 1 naipe \n 2: 2 naipes \n 3: 3 naipes \n 4: 4 naipes \n");
			scanf("%d", &dificuldade);
			while (dificuldade < 1 || dificuldade > 4 )
			{
				printf(" dificuldade invalida \n");
				printf(" Escolha a dificuldade \n 1: 1 naipe \n 2: 2 naipes \n 3: 3 naipes \n 4: 4 naipes \n");
				scanf("%d", &dificuldade);
			}
			if(preencherBarInic(barI, dificuldade)!= BarI_CondRetOk)
				printf(" ERRO AO PREENCHER O BARALHO");
			for(i = 0; i < 4; i++)
			{
				if( i == 0) Paux = P1;
				else if( i == 1) Paux = P2;
				else if( i == 2) Paux = P3;
				else Paux = P4;
					
				for(j = 0; j < 6; j++)
				{
					if((pegarCartaBarInic(barI, &cartaAux)) != BarI_CondRetOk)
						printf(" ERRO AO PEGAR A CARTA \n");
					if((adicionarCartasBarP(Paux, cartaAux))!= BarP_CondRetOk)
						printf(" ERRO AO ADICIONAR CARTA \n");
				}
			}
			for( i = 0; i < 6; i++)
			{
				if(i == 0) Paux = P5;
				else if(i == 1) Paux = P6;
				else if(i == 2) Paux = P7;
				else if(i == 3) Paux = P8;
				else if(i == 4) Paux = P9;
				else Paux = P10;
				for(j = 0; j < 5; j++)
				{
					if((pegarCartaBarInic(barI, &cartaAux)) != BarI_CondRetOk)
						printf(" ERRO AO PEGAR A CARTA \n");
					if((adicionarCartasBarP(Paux, cartaAux))!= BarP_CondRetOk)
						printf(" ERRO AO ADICIONAR CARTA NO PRINC \n");
				}
			}
			for(i = 0; i < 50; i++)
			{
				if((pegarCartaBarInic(barI, &cartaAux)) != BarI_CondRetOk)
					printf(" ERRO AO PEGAR A CARTA \n");
				if((adicionarCartaBarExtra(barE, cartaAux))!= BarP_CondRetOk)
					printf(" ERRO AO ADICIONAR CARTA NO EXTRA \n");
			}
			// Verifica se a ultima carta de cada baralho principal está aberta, se não torna a abri-la
			verify();
			w1 = 0;
		} // end if resp == 1
		else
		{
			if(resp == 2)
			{
				estr = carregaJogo(&Game);
				IrInicioLista(estr);
				// Atribui os endereços certos a cada baralho
				P1 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK) 
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P2 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P3 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P4 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P5 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P6 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P7 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P8 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P9 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				P10 = (BarP_tppBarPrinc)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK)
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				barE = (BarE_tppBarExtra)LIS_ObterValor(estr);
				if(LIS_AvancarElementoCorrente(estr, 1)!= LIS_CondRetOK) 
				{
					printf("Erro ao avancar elemento corrente carrega jogo \n");
					return 0;
				}
				barF = (BarF_tppBarFinal)LIS_ObterValor(estr);
				w1 = 0;
			}
			else
			{
				printf(" Nao da pra fazer isso \n");
				printf(" MENU \n 1: Novo Jogo \n 2: Carregar Jogo \n 0: Sair \n");
				scanf("%d", &resp);
			}
		} // end else
	} // end while (resp)
	while (qtdBarFinal < 104)
	{
		contcompra = (obterTamanhoBarE(barE))/10; // quantas vezes pode comprar
		//countBarPrinc();
		verify();
		printf(" \n__________________________________________\n");
		exibe();
		// Fazer uma jogada
		printf("\n ________________________________________ \n");
		printf(" Faca uma jogada! \n");
		printf(" 1: Mover \n");
		printf(" 2: Comprar %dx \n", contcompra);
		printf(" 3: Salvar e Sair \n ");
		scanf("%d", &dec);
		while(dec >= 0)
		{
			while(dec ==2) // enquanto comprar carta
			{
				if(contcompra == 0)
				{
					printf("Nao pode comprar mais cartas \n");
					dec = 1;
				}
				else
				{
				// Pega carta do baralho extra e adiciona uma carta em cada baralho principal
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P1, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P2, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P3, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P4, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
				return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
				printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P5, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P6, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P7, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P8, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P9, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				if(pegarCartaBarExtra(barE, &cartaAux)!= BarE_CondRetOk) {
					printf(" ERRO AO PEGAR A CARTA DO MONTE DE COMPRA");
					return 0;
				}
				if(adicionarCartasBarP(P10, cartaAux)!= BarP_CondRetOk) {
					printf(" ERRO ADICIONAR NO PRINCIPAL 1");
					return 0;
				}
				// Exibe os baralhos com as novas cartas
				contcompra = (obterTamanhoBarE(barE))/10;
				//countBarPrinc();
				verify();
				printf(" \n__________________________________________\n");
				exibe();
				printf("\n ________________________________________ \n");
				printf(" Faca uma jogada! \n");
				printf(" 1: Mover \n");
				printf(" 2: Comprar %dx \n", contcompra);
				printf(" 3: Salvar e Sair \n");
				scanf("%d", &dec);
				}
			}
			if(dec == 1)
			{
				rTrans = 0; rConta = 0;
				while(!rConta && !rTrans)
				{
					printf(" Mover x cartas do baralho y para o baralho z \n");
					scanf(" %d %d %d", &qtdCartas, &baralhoFonte, &baralhoDestino);
					// Controle das variáveis
					while(baralhoFonte == baralhoDestino)
					{
						printf(" Baralho Fonte e Destino Iguais!! \n Tente de novo \n");
						printf(" Mover x cartas do baralho y para o baralho z \n");
						scanf(" %d %d %d", &qtdCartas, &baralhoFonte, &baralhoDestino);	
					}
					while(baralhoFonte <= 0 || baralhoFonte > 10)
					{
						printf(" Baralho Fonte Invalido \n Tente de novo \n");
						printf(" Mover x cartas do baralho y para o baralho z \n");
						scanf(" %d %d %d", &qtdCartas, &baralhoFonte, &baralhoDestino);
					}
					while(baralhoDestino <= 0 || baralhoDestino > 10)
					{
						printf(" Baralho Destino Invalido \n Tente de novo \n");
						printf(" Mover x cartas do baralho y para o baralho z \n");
						scanf(" %d %d %d", &qtdCartas, &baralhoFonte, &baralhoDestino);
					}	
					switch(baralhoFonte) 
					{
					case 1:
						PF = P1;
						break; 
					case 2:
						PF = P2;
						break;
					case 3:
						PF = P3;
						break;
					case 4:
						PF = P4;
						break;
					case 5:
						PF = P5;
						break;
					case 6:
						PF = P6;
						break;
					case 7:
						PF = P7;
						break;
					case 8:
						PF = P8;
						break;
					case 9:
						PF = P9;
						break;
					case 10:
						PF = P10;
						break;
					default:;
					}		
					switch(baralhoDestino) 
					{
					case 1:
						PD = P1;
						break; 
					case 2:
						PD = P2;
						break;
					case 3:
						PD = P3;
						break;
					case 4:
						PD = P4;
						break;
					case 5:
						PD = P5;
						break;
					case 6:
						PD = P6;
						break;
					case 7:
						PD = P7;
						break;
					case 8:
						PD = P8;
						break;
					case 9:
						PD = P9;
						break;
					case 10:
						PD = P10;
						break;
					default:;
					}
					// conta a quantidade de cartas abertas
					numCartaAberta = 0;
						rTrans = transferirCartasBarP(PF, PD, qtdCartas);
						if( rTrans != 0 && rTrans != 2)
						{
							printf(" ERRO AO MOVER AS CARTAS \n");
							printf(" Tente de novo \n");
							rTrans = 0;
						}
						else
						{
							if(rTrans == 2) // se rTrans retronar 2, é contra a regra fazer a jogada
							{
								printf(" E Contra a regra fazer essa jogada \n");
								rTrans = 0;
							}
							else // se estiver na regra...
							{
								verify();
								if(obterValoresUltCarta(PD, &valorCarta, &naipeCarta) != BarP_CondRetOk) 
								{
									printf(" ERRO AO OBTER ULTIMO VALOR DO BARALHO \n");
									return 0;
								}
								if(valorCarta == 1) // verifica se formou uma sequencia
								{
									if(verificaSequenciaFormada(PD) == BarP_CondRetOk) // se for sequencia
									{
										for(i = 0; i < 13; i++) // retira as cartas do baralho e coloca-as no baralho final
										{
											pegarCartaBarP(PD, &cartaAux);
											adicionarCartaBarFinal(barF, (void*)cartaAux);
										}
									}
								}
								rTrans = 1; rConta = 1;
								if(obterTamanhoBarFinal(barF,&qtdBarFinal)!= BarF_CondRetOk){
								printf("Erro ao obter o tamanho do baralho Final \n");
								return 0;
								}	
							} //3
						} //2
				dec = -1;
				}
			}
			else
			{
				if( dec == 3)
				{
					salvarJogo(estr);
					printf(" Jogo Salvo \n");
					return 0;
				}
				else
				{
					printf(" Nao da pra fazer isso \n");
					printf(" Faca uma jogada! \n");
					printf(" 1: Mover \n");
					printf(" 2: Comprar %dx \n", contcompra);
					printf(" 3: Salvar e Sair \n");
					scanf("%d", &dec);
				}
			}
		}
	}
	printf(" Parabens! Voce Completou todas as jogadas! \n");
	printf(" Jogar Novamente ? s/n \n 1: Sim \n 2: Nao");
	scanf("%d", &jogar);
	}
	// destruir os baralhos
	if(destrBaralhoPrincipal(P1)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P2)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P3)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P4)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P5)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P6)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P7)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P8)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P9)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destrBaralhoPrincipal(P10)!=BarP_CondRetOk)
		printf("Erro ao destruir o baralho \n");
	if(destruirBarFinal(barF)!= BarF_CondRetOk)
		printf(" Erro ao destruir o baralho \n");
	if(destruirBarExtra(barE)!= BarE_CondRetOk)
		printf(" Erro ao destruir o baralho \n");
}
void salvarJogo(LIS_tppLista estrutura)
{
	FILE* Game;
	void* princ;
	void* barE;
	void* barF;
	tppCarta Caux;
	int i, tam, qtd, valor, aberta;
	char naipe;
	Game = fopen("Game.txt", "w");
	if(Game == NULL) {
		printf("Erro ao abrir arquivo \n");
		return;
	}
	IrInicioLista(estrutura);
	// Imprime os 10 baralhos principais no arquivo
	for(i = 0; i < 10; i++)
	{
		// obtem o baralho principal
		princ = LIS_ObterValor(estrutura);
		// obtem o seu tamanho
		tam = obterTamanhoBarP((BarP_tppBarPrinc)princ);
		if(tam == 0)
			fprintf(Game, "v\n");
		else {
		while(tam > 0)
		{
		// Pega a carta no topo da pilha
		pegarCartaBarP((BarP_tppBarPrinc)princ, &Caux);
		// pega os valores da carta
		obterValorCarta(Caux, &naipe, &valor, &aberta);
		// imprime a carta
		fprintf(Game,"%c %d %d", naipe, valor, aberta);
		tam--;
		}
		fprintf(Game, "\n");
		}
		// avancar para o proximo baralho principal
		if(LIS_AvancarElementoCorrente(estrutura, 1)!= LIS_CondRetOK)
		{
			printf("Erro ao avancar elemento corrente \n");
			return;
		}
	}
	// Obtem a referencia para o baralho extra
	barE = LIS_ObterValor(estrutura);
	// obtem o tamanho do baralho extra
	tam = obterTamanhoBarE((BarE_tppBarExtra)barE);
	if(tam == 0)
		fprintf(Game, "v\n");
	else
	{
		while(tam > 0)
		{
			// Pega a carta no topo da pilha
		pegarCartaBarExtra((BarE_tppBarExtra)barE, &Caux);
		// pega os valores da carta
		obterValorCarta(Caux, &naipe, &valor, &aberta);
		// imprime a carta
		fprintf(Game,"%c %d %d", naipe, valor, aberta);
		tam--;
		}
		fprintf(Game, "\n");
	}
	if(LIS_AvancarElementoCorrente(estrutura, 1)!= LIS_CondRetOK)
	{
		printf("Erro ao avancar elemento corrente \n");
		return;
	}
	// Obtem a referencia para o baralho Final
	barF = LIS_ObterValor(estrutura);
	// obtem o tamanho do baralho final
	if(obterTamanhoBarFinal((BarF_tppBarFinal)barF, &tam)!= BarF_CondRetOk) {
		printf(" Erro ao obter o tamanho do baralho final");
		return;
	}
	if(tam == 0) {
		fprintf(Game, "v\n");
		return;
	}
	else
	{
		while(tam > 0)
		{
		// Pega a carta no topo da pilha
		pegarCartaBarFinal((BarF_tppBarFinal)barF, &Caux);
		// pega os valores da carta
		obterValorCarta(Caux, &naipe, &valor, &aberta);
		// imprime a carta
		fprintf(Game,"%c %d %d", naipe, valor, aberta);
		tam--;
		}
		fprintf(Game, "\n");
	} 
	fclose(Game);
}

LIS_tppLista carregaJogo(FILE** Game)
{
BarP_tppBarPrinc P1, P2, P3, 
				P4, P5, P6, 
				P7, P8, P9, P10;
BarI_tppBarInicial barI;
BarE_tppBarExtra barE;
BarF_tppBarFinal barF;
void* aux;
	tppCarta  vetAux[103];
	int i, valor, aberta, cont;
	char naipe;
	LIS_tppLista estrutura;
	estrutura = LIS_CriarLista(NULL);
	*Game = fopen("Game.txt", "r");
	if(*Game == NULL)
		printf("Erro ao abrir o arquivo \n");
	// Cria os 10 baralhos principais, o monte extra, e o final
	criarBarIni(&barI);
	criarBaralhoPrincipal(&P1); criarBaralhoPrincipal(&P2);
	criarBaralhoPrincipal(&P3); criarBaralhoPrincipal(&P4);
	criarBaralhoPrincipal(&P5); criarBaralhoPrincipal(&P6);
	criarBaralhoPrincipal(&P7); criarBaralhoPrincipal(&P8);
	criarBaralhoPrincipal(&P9); criarBaralhoPrincipal(&P10);
	criarBarExtra(&barE);
	criarBarFinal(&barF);
	// Insere na lista de listas os 10 baralhos principais, o monte extra e o final
	if((LIS_InserirElementoApos(estrutura, P1)) != LIS_CondRetOK)
		printf(" \n ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P2)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P3)) != LIS_CondRetOK)
		printf(" \n ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P4)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P5)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P6)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P7)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P8)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P9)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, P10)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, barE)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	if((LIS_InserirElementoApos(estrutura, barF)) != LIS_CondRetOK)
		printf(" ERRO NA CRIACAO \n");
	IrInicioLista(estrutura);
	for(i = 0; i < 10; i++)
	{
		cont = 0;
		// Obtem a referencia pro primeiro baralho principal
		aux = LIS_ObterValor(estrutura);
		// obtem os valores do arquivo
		fscanf(*Game, "%c ", &naipe);
		if(naipe == 'v')
		{
			if(LIS_AvancarElementoCorrente(estrutura, 1)!= LIS_CondRetOK) // tem q fechar 
			{
				printf("Erro ao avancar elemento corrente 1 \n");
				return NULL;
			}
		}
		else {
		while(naipe != '\n')
		{
				fscanf(*Game, "%d %d", &valor, &aberta);
				// criar carta com os valores lidos
				if(criarCarta(naipe, valor, &vetAux[cont])!= CAR_CondRetOk)
				{
					printf("Erro ao criar a carta lida \n");
					return NULL;
				}
				// abre a carta se ela já estava aberta
				if(aberta) {
					if(abreCarta(vetAux[cont])!= CAR_CondRetOk)
						printf("Erro ao abrir a carta");
				}
		cont++;
		fscanf(*Game, "%c ", &naipe);
		} 
		cont--;
		// Adiciona as cartas no baralho na ordem certa, obtendo elas do vetor
		while(cont >= 0)
		{
			if(adicionarCartasBarP((BarP_tppBarPrinc)aux, vetAux[cont])!= BarP_CondRetOk)
			{
				printf("Erro ao adicionar carta no baralho principal %d \n", i);
				return NULL;
			}
			cont--;
		}
		if(LIS_AvancarElementoCorrente(estrutura, 1)!= LIS_CondRetOK)
			{
				printf("Erro ao avancar elemento corrente 2 \n");
				return NULL;
			}
	}
	}
	// Obtem a referencia pro  baralho Extra
	aux = LIS_ObterValor(estrutura);
	// obtem os valores do arquivo
	fscanf(*Game, "%c ", &naipe);
	if(naipe == 'v')
	{
		if(LIS_AvancarElementoCorrente(estrutura, 1)!= LIS_CondRetOK)
		{
			printf("Erro ao avancar elemento corrente  3\n");
			return NULL;
		}
	}
	else
	{
	cont = 0;
	while(naipe != '\n')
	{
		// se naipe == v então a pilha está vazia
		if(naipe == 'v')
		{
			if(LIS_AvancarElementoCorrente(estrutura, 1)!= LIS_CondRetOK)
			{
				printf("Erro ao avancar elemento corrente  3\n");
				return NULL;
			}
		}
		else {
				fscanf(*Game, "%d %d", &valor, &aberta);
				// criar carta com os valores lidos
				if(criarCarta(naipe, valor, &vetAux[cont])!= CAR_CondRetOk)
				{
					printf("Erro ao criar a carta lida \n");
					return NULL;
				}
				// abre a carta se ela já estava aberta
				if(aberta) {
					if(abreCarta(vetAux[cont])!= CAR_CondRetOk)
						printf("Erro ao abrir a carta");
				}
			 }
		cont++;
		fscanf(*Game, "%c ", &naipe);
	}
	cont--;
	// Adiciona as cartas na ordem certa, obtendo elas do vetor
		while(cont >= 0)
		{
			if(adicionarCartasBarP((BarE_tppBarExtra)aux, vetAux[cont])!= BarP_CondRetOk)
			{
				printf("Erro ao adicionar carta no baralho principal %d \n", i);
				return NULL;
			}
			cont--;
		}
	// avanca elemento na lista
	if(LIS_AvancarElementoCorrente(estrutura, 1)!= LIS_CondRetOK)
			{
				printf("Erro ao avancar elemento corrente da lista (barFinal) \n");
				return NULL;
			}
		}
	// Obtem a referencia pro primeiro baralho Final
	aux = LIS_ObterValor(estrutura);
	// obtem os valores do arquivo
	fscanf(*Game, "%c ", &naipe);
	cont = 0;
	while(naipe != '\n')
	{
		// se naipe == v então a pilha está vazia e retorna
		if(naipe == 'v') {
			fclose(*Game);
			return estrutura;
		}
		else {
				fscanf(*Game, "%d %d", &valor, &aberta);
				// criar carta com os valores lidos
				if(criarCarta(naipe, valor, &vetAux[cont])!= CAR_CondRetOk)
				{
					printf("Erro ao criar a carta lida \n");
					return NULL;
				}
				// abre a carta se ela já estava aberta
				if(aberta) {
					if(abreCarta(vetAux[cont])!= CAR_CondRetOk)
						printf("Erro ao abrir a carta");
				}
			 }
		cont++;
		fscanf(*Game, "%c ", &naipe);
	}
	cont--;
	// Adiciona as cartas na ordem certa
		while(cont >= 0)
		{
			if(adicionarCartaBarFinal((BarF_tppBarFinal)aux, vetAux[cont])!= BarP_CondRetOk)
			{
				printf("Erro ao adicionar carta no baralho principal %d \n", i);
				return NULL;
			}
			cont--;
		}
	fclose(*Game);
	return estrutura;
	}






		






						











