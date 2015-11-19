/* M�dulo Carta: M�dulo referente a uma �nica carta
* Autor: Klaus Fischer
* Modificado 27/05 Teste com scripts e ajustes
*		   28/05 ajustes com teste de scripts
*		   06/06 Ajustes finais
*/
#ifndef CARTA_H
#define CARTA_H


typedef struct tgCarta* tppCarta;

// Condi��es de retorno das fun��es
typedef enum {
	CAR_CondRetOk,				// Concluiu corretamente
	CAR_CondRetErro,			// Ocorreu um erro
	CAR_CondRetNaoCriou,	// N�o foi poss�vel alocar espa�o para carta
	CAR_CondRetNaoExiste,	// A carta passada n�o existe
} CartaCondRet;

// Fun��es de Acesso
/*
Objetivo: Cria uma carta
Par�metros:
	naipe	-> O naipe que a carta ter�.
					 S� ser�o aceito os seguintes valores para naipe:
					 'e' - Espadas
					 'c' - Copas
					 'p' - Paus
					 'o' - Ouro
	valor	-> O valor que uma carta ter�.
					 Os poss�veis valores que uma carta pode ter s�o
					 de 1 (A) at� 13 (Rei)
Retorno:
	CAR_CondRetNaoCriou
	CAR_CondRetErro
	CAR_CondRetOk
*/
CartaCondRet criarCarta(char naipe, int valor, tppCarta* carta);

/*
Objetivo: Destroir uma carta
Par�metros:
	carta	-> A carta que ser� destruida
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
*/
CartaCondRet destrCarta(tppCarta carta);

/*
Objetivo: Altera o naipe da carta
Par�metros:
	carta			-> A carta que ser� alterada
	novoNaipe -> O novo naipe da carta
							 S� ser�o aceito os seguintes valores para naipe:
							 'e' - Espadas
							 'c' - Copas
							 'p' - Paus
							 'o' - Ouro
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
	CAR_CondRetErro
*/
CartaCondRet alterarNaipe(tppCarta carta, char novoNaipe);

/*
Objetivo: Altera o valor da carta
Par�metros:
	carta			-> A carta que ser� alterada
	novoValor -> O novo valor da carta, que tem que ser entre 1 e 13
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
	CAR_CondRetErro
*/
CartaCondRet alterarValor(tppCarta carta, int novoValor);

/*
Objetivo: Abre a carta
Par�metros:
	carta -> A carta que ser� aberta
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
*/
CartaCondRet abreCarta(tppCarta carta);

/*
Objetivo: Obt�m as caracter�sticas da carta
Par�metros:
	carta		-> A carta a ser consultada
	naipe		-> Ponteiro que ter� o valor do naipe se a fun��o for bem sucedida
	valor		-> Ponteiro que ter� o valor do valor se a fun��o for bem sucedida
	aberta	-> Ponteiro cujo conte�do indicar� se a carta est� aberta ou n�o (1 = aberta, 0 = fechada)
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
*/
CartaCondRet obterValorCarta(tppCarta carta, char* naipe, int* valor, int* aberta);

/* Objetivo: Exibe os conte�dos da carta
Par�metros:
	carta		-> A carta a ser exibida
*/
void imprimeCarta (tppCarta carta);

#endif