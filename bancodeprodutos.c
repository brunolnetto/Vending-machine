#include <stdio.h>
#include <stdlib.h>

#include "bancodeprodutos.h"

#define numeroProdutos 9
#define SLOT_INEXISTENTE -1

//  Definição de um produto
struct produto{
   int preco;
   int quantidade;
};

// Matriz que contem os produtos armazenados
//    Na ausência de uma memória não-volátil
//    inicia-se a vending machine com produtos
struct produto vetorProdutos[numeroProdutos] = {{100,10},
                                                {100,10},
                                                {100,10},
                                                {100,10},
                                                {100,10},
                                                {100,10},
                                                {100,10},
                                                {100,10},
                                                {100,10}};

/*******************************
 prd_preco
 Obtem o preco de um produto
 entradas
   codigo: posicao do produto no
   banco de dados.
 saidas
   Preco do produto ou
   SLOT_INEXISTENTE
********************************/
int prd_preco(int codigo)
{
    if((codigo>0) && (codigo<=numeroProdutos)){
        return vetorProdutos[codigo-1].preco;
    }
    return SLOT_INEXISTENTE;
}

/*******************************
 prd_quantidade
 Obtem a quantidade de um produto
 entradas
   codigo: posicao do produto no
   banco de dados.
 saidas
   quantidade do produto ou
   SLOT_INEXISTENTE
********************************/
int prd_quantidade(int codigo)
{
   if((codigo>0) && (codigo<=numeroProdutos)){
      return vetorProdutos[codigo-1].quantidade;
   }
   return SLOT_INEXISTENTE;
}

/*******************************
 prd_decrementaQtd
 Decrementa quantidade de um produto
 entradas
   codigo: posicao do produto no
   banco de dados.
 saidas
   nenhuma
********************************/
extern void prd_decrementaQtd(int codigo)
{
   (vetorProdutos[codigo-1].quantidade)--;
}

/*******************************
 prd_deleta
 Deleta um produto no banco de dados
 entradas
   codigo: posicao do produto no
   banco de dados.
 saidas
   nenhuma
********************************/
extern void prd_deleta(int codigo)
{
   prd_cadastra(codigo,0,0);
}

/*******************************
 prd_cadastra
 Cadastra um produto no banco de dados
 entradas
   codigo: posicao do produto no
   banco de dados.
   Preco: preco do produto
   qtd: quantidade do produto
 saidas
   nenhuma
********************************/
extern void prd_cadastra(int codigo, int Preco, int qtd)
{
   vetorProdutos[codigo-1].preco = Preco;
   vetorProdutos[codigo-1].quantidade = qtd;
}
