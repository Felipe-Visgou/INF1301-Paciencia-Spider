/* Módulo Carta: Módulo referente a uma única carta
* Autor: Klaus Fischer
* Modificado 27/05 Teste com scripts e ajustes
*		   28/05 ajustes com teste de scripts
*		   06/06 Ajustes finais
*/
#ifndef CARTA_H
#define CARTA_H


typedef struct tgCarta* tppCarta;

// Condições de retorno das funções
typedef enum {
	CAR_CondRetOk,				// Concluiu corretamente
	CAR_CondRetErro,			// Ocorreu um erro
	CAR_CondRetNaoCriou,	// Não foi possível alocar espaço para carta
	CAR_CondRetNaoExiste,	// A carta passada não existe
} CartaCondRet;

// Funções de Acesso
/*
Objetivo: Cria uma carta
Parâmetros:
	naipe	-> O naipe que a carta terá.
					 Só serão aceito os seguintes valores para naipe:
					 'e' - Espadas
					 'c' - Copas
					 'p' - Paus
					 'o' - Ouro
	valor	-> O valor que uma carta terá.
					 Os possíveis valores que uma carta pode ter são
					 de 1 (A) até 13 (Rei)
Retorno:
	CAR_CondRetNaoCriou
	CAR_CondRetErro
	CAR_CondRetOk
*/
CartaCondRet criarCarta(char naipe, int valor, tppCarta* carta);

/*
Objetivo: Destroir uma carta
Parâmetros:
	carta	-> A carta que será destruida
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
*/
CartaCondRet destrCarta(tppCarta carta);

/*
Objetivo: Altera o naipe da carta
Parâmetros:
	carta			-> A carta que será alterada
	novoNaipe -> O novo naipe da carta
							 Só serão aceito os seguintes valores para naipe:
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
Parâmetros:
	carta			-> A carta que será alterada
	novoValor -> O novo valor da carta, que tem que ser entre 1 e 13
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
	CAR_CondRetErro
*/
CartaCondRet alterarValor(tppCarta carta, int novoValor);

/*
Objetivo: Abre a carta
Parâmetros:
	carta -> A carta que será aberta
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
*/
CartaCondRet abreCarta(tppCarta carta);

/*
Objetivo: Obtém as características da carta
Parâmetros:
	carta		-> A carta a ser consultada
	naipe		-> Ponteiro que terá o valor do naipe se a função for bem sucedida
	valor		-> Ponteiro que terá o valor do valor se a função for bem sucedida
	aberta	-> Ponteiro cujo conteúdo indicará se a carta está aberta ou não (1 = aberta, 0 = fechada)
Retorno:
	CAR_CondRetOk
	CAR_CondRetNaoExiste
*/
CartaCondRet obterValorCarta(tppCarta carta, char* naipe, int* valor, int* aberta);

/* Objetivo: Exibe os conteúdos da carta
Parâmetros:
	carta		-> A carta a ser exibida
*/
void imprimeCarta (tppCarta carta);

#endif