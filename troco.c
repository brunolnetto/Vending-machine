#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "troco.h"

#define NUM_TIPO_DE_MOEDAS 4
#define MOEDA10  0
#define MOEDA25  1
#define MOEDA50  2
#define MOEDA100 3

int quantidadeMoedas[NUM_TIPO_DE_MOEDAS];

/************************
 trc_verificaTroco
 Verifica se h� troco dispon�vel
 entradas
   valor: quantidade de troco a ser verificada
 saidas
   TRUE: H� troco dispon�vel
   FALSE: N�o h� troco dispon�vel
*************************/
extern int trc_verificaTroco(int troco)
{
    // Na falta de um dep�sito de troco,
    //  para fins de simula��o, ser� poss�vel
    //  verificar transi��o de estados alterando
    //  o return para true ou false
    return true;
}

/************************
 trc_liberarTroco
 Libera o troco
 entradas
   troco: valor a ser liberado
 saidas
   nenhuma
*************************/
extern void trc_liberarTroco(int troco)
{
   printf("Liberando troco de %d...\n",troco);
}

/************************
 trc_registraMoeda
 Cadastra moedas para troco na m�quina
 entradas
   tipoMoeda: tipo de moeda a ser cadastrada
   QtdMoeda: quantidade da referida moeda
 saidas
   nenhuma
*************************/
extern void trc_registraMoeda(int tipoMoeda, int QtdMoeda)
{
   switch(tipoMoeda)
   {
      case 10:
         quantidadeMoedas[MOEDA10]+=QtdMoeda;
      break;

      case 25:
         quantidadeMoedas[MOEDA25]+=QtdMoeda;
      break;

      case 50:
         quantidadeMoedas[MOEDA50]+=QtdMoeda;
      break;

      case 100:
         quantidadeMoedas[MOEDA100]+=QtdMoeda;
      break;
   }
}
