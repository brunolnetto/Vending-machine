#ifndef TROCO_H_INCLUDED
#define TROCO_H_INCLUDED


/************************
 trc_verificaTroco
 Verifica se h� troco dispon�vel
 entradas
   valor: quantidade de troco a ser verificada
 saidas
   TRUE: H� troco dispon�vel
   FALSE: N�o h� troco dispon�vel
*************************/
extern int trc_verificaTroco(int troco);

/************************
 trc_liberarTroco
 Libera o troco
 entradas
   troco: valor a ser liberado
 saidas
   nenhuma
*************************/
extern void trc_liberarTroco(int troco);

/************************
 trc_registraMoeda
 Cadastra moedas para troco na m�quina
 entradas
   tipoMoeda: tipo de moeda a ser cadastrada
   QtdMoeda: quantidade da referida moeda
 saidas
   nenhuma
*************************/
extern void trc_registraMoeda(int tipoMoeda, int QtdMoeda);

#endif // TROCO_H_INCLUDED
