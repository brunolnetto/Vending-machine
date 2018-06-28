#ifndef DINHEIRO_H_INCLUDED
#define DINHEIRO_H_INCLUDED

/************************
 dnr_devolveDinheiro
 Devolve determinada quantidade ao cliente
 entradas
   valor: quantidade a ser devolvida
 saidas
   nenhuma
*************************/
extern void dnr_devolveDinheiro(int valor);

/************************
 dnr_valorDinheiroInserido
 Verifica a quantidade dinheiro inserido
 entradas
   nenhuma
 saidas
   dinheiroinserido: valor inserido pelo usuário
*************************/
extern int dnr_valorDinheiroInserido(void);

/************************
 dnr_dinheiroInserido
 Verifica se dinheiro foi inserido
 entradas
   para fins de simulacao, só aceitará o dinheiro
   inserido para o estado AGUARDANDO_DINHEIRO
 saidas
   TRUE: dinheiro foi inserido
   FALSE: dinheiro não foi inserido
*************************/
extern int dnr_dinheiroInserido(int estado);

#endif // DINHEIRO_H_INCLUDED
