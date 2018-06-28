#include <stdio.h>
#include <stdlib.h>

#include "dispenser.h"
#include "bancodeprodutos.h"

/************************
 ihm_exibirMsg
 Libera o produto
 entradas
   codigo: posicao do produto na maquina
 saidas
   nenhuma
*************************/
extern void dsr_liberaProduto(int codigo)
{
    printf("Liberando produto da posicao %d...\n",codigo);
    prd_decrementaQtd(codigo);
}
