#include <stdio.h>
#include <stdlib.h>

#include "dinheiro.h"
#include "definicoes_sistema.h"

/************************
 dnr_devolveDinheiro
 Devolve determinada quantidade ao cliente
 entradas
   valor: quantidade a ser devolvida
 saidas
   nenhuma
*************************/
extern void dnr_devolveDinheiro(int valor)
{
    // Esta fun��o deve efetuar a libera��o
    //  de dinheiro armazenado na m�quina.
    //  Na falta de um reposit�rio de dinheiro,
    //  foi colocado apenas uma impress�o na tela
    printf("Devolvendo dinheiro...\n");
}

/************************
 dnr_valorDinheiroInserido
 Verifica a quantidade dinheiro inserido
 entradas
   nenhuma
 saidas
   dinheiroinserido: valor inserido pelo usu�rio
*************************/
extern int dnr_valorDinheiroInserido(void)
{
   // Na falta de verificador de quantidade de dinheiro,
   //    que ficaria junto ao dispositivo de
   //    dinheiro, quando esta fun��o � chamada,
   //    o usu�rio da simula��o o valor que teria
   //    inserido na m�quina
   int valorDinheiroInserido;

   printf("Quantidade inserida: ");
   scanf("%d",&valorDinheiroInserido);

   return valorDinheiroInserido;
}

/************************
 dnr_dinheiroInserido
 Verifica se dinheiro foi inserido
 entradas
   para fins de simulacao, s� aceitar� o dinheiro
   inserido para o estado AGUARDANDO_DINHEIRO
 saidas
   TRUE: dinheiro foi inserido
   FALSE: dinheiro n�o foi inserido
*************************/
extern int dnr_dinheiroInserido(int estado)
{
   // Na falta de verificador de dinheiro,
   //    que ficaria junto ao dispositivo de
   //    dinheiro, quando esta fun��o � chamada,
   //    devolve-se true apenas quando se estiver
   //    no estado AGUARDANDO_DINHEIRO
   if(estado == AGUARDANDO_DINHEIRO)
      return true;
   else
      return false;
}
