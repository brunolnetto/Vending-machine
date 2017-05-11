#ifndef BANCODEPRODUTOS_H_INCLUDED
#define BANCODEPRODUTOS_H_INCLUDED

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
extern int prd_preco(int codigo);

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
extern int prd_quantidade(int codigo);

/*******************************
 prd_decrementaQtd
 Decrementa quantidade de um produto
 entradas
   codigo: posicao do produto no
   banco de dados.
 saidas
   nenhuma
********************************/
extern void prd_decrementaQtd(int codigo);

/*******************************
 prd_deleta
 Deleta um produto no banco de dados
 entradas
   codigo: posicao do produto no
   banco de dados.
 saidas
   nenhuma
********************************/
extern void prd_deleta(int codigo);

/*******************************
 prd_cadastra
 Cadastra um produto no banco de dados
 entradas
   codigo: posicao do produto no
   banco de dados.
   preco: preco do produto
   qtd: quantidade do produto
 saidas
   nenhuma
********************************/
extern void prd_cadastra(int codigo, int preco, int qtd);

#endif // BANCODEPRODUTOS_H_INCLUDED
