#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "matrizdeEstadoseAcoes.h"

int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];

/***********************************************************************
 iniciaMaquina de Estados
 Carrega a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
************************************************************************/
void iniciaMaquinaEstados(){
   int i;
   int j;

   for (i=0; i < NUM_ESTADOS; i++) {
    for (j=0; j < NUM_EVENTOS; j++) {
       acao_matrizTransicaoEstados[i][j] = NENHUMA_ACAO;
       proximo_estado_matrizTransicaoEstados[i][j] = i;
    }
   }

   // Eventos recebidos pelo estado AGUARDANDO_COMANDO
   proximo_estado_matrizTransicaoEstados[AGUARDANDO_COMANDO][PRODUTO_SELECIONADO] = AGUARDANDO_DINHEIRO;
   acao_matrizTransicaoEstados[AGUARDANDO_COMANDO][PRODUTO_SELECIONADO] = A01;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_COMANDO][TIMEOUT] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[AGUARDANDO_COMANDO][TIMEOUT] = A12;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_COMANDO][ENTRAR_ADMIN] = AGUARDANDO_SENHA;
   acao_matrizTransicaoEstados[AGUARDANDO_COMANDO][ENTRAR_ADMIN] = A14;

   // Eventos recebidos pelo estado AGUARDANDO_DINHEIRO
   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][PRODUTO_INVALIDO] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][PRODUTO_INVALIDO] = A15;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][FALTA_TROCO] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][FALTA_TROCO] = A06;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][FALTA_PRODUTO] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][FALTA_PRODUTO] = A13;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][DESISTENCIA] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][DESISTENCIA] = A05;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][TIMEOUT] = AGUARDANDO_DINHEIRO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][TIMEOUT] = A02;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][CANCELAR] = AGUARDANDO_DINHEIRO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][CANCELAR] = A04;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][DINHEIRO_INSERIDO] = AGUARDANDO_DINHEIRO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][DINHEIRO_INSERIDO] = A03;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][DINHEIRO_TOTAL] = AGUARDANDO_DINHEIRO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][DINHEIRO_TOTAL] = A07;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][COMPRA_VALIDA] = LIBERANDO_PRODUTO;
   acao_matrizTransicaoEstados[AGUARDANDO_DINHEIRO][COMPRA_VALIDA] = A08;

   // Eventos recebidos pelo estado LIBERANDO_PRODUTO
   proximo_estado_matrizTransicaoEstados[LIBERANDO_PRODUTO][TIMEOUT] = LIBERANDO_PRODUTO;
   acao_matrizTransicaoEstados[LIBERANDO_PRODUTO][TIMEOUT] = A09;

   proximo_estado_matrizTransicaoEstados[LIBERANDO_PRODUTO][LIBERAR_TROCO] = LIBERANDO_TROCO;
   acao_matrizTransicaoEstados[LIBERANDO_PRODUTO][LIBERAR_TROCO] = A10;

   proximo_estado_matrizTransicaoEstados[LIBERANDO_PRODUTO][AGUARDAR] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[LIBERANDO_PRODUTO][AGUARDAR] = A12;

   // Eventos recebidos pelo estado LIBERANDO_TROCO
   proximo_estado_matrizTransicaoEstados[LIBERANDO_TROCO][TIMEOUT] = LIBERANDO_TROCO;
   acao_matrizTransicaoEstados[LIBERANDO_TROCO][TIMEOUT] = A11;

   proximo_estado_matrizTransicaoEstados[LIBERANDO_TROCO][AGUARDAR] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[LIBERANDO_TROCO][AGUARDAR] = A12;

   // Eventos recebidos pelo estado AGUARDANDO_SENHA
   proximo_estado_matrizTransicaoEstados[AGUARDANDO_SENHA][CANCELAR] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[AGUARDANDO_SENHA][CANCELAR] = A12;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_SENHA][SENHA_INVALIDA] = AGUARDANDO_SENHA;
   acao_matrizTransicaoEstados[AGUARDANDO_SENHA][SENHA_INVALIDA] = A14;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_SENHA][SENHA_VALIDA] = MODO_ADMIN;
   acao_matrizTransicaoEstados[AGUARDANDO_SENHA][SENHA_VALIDA] = A16;

   // Eventos recebidos pelo estado MODO_ADMIN
   proximo_estado_matrizTransicaoEstados[MODO_ADMIN][CANCELAR] = AGUARDANDO_COMANDO;
   acao_matrizTransicaoEstados[MODO_ADMIN][CANCELAR] = A12;

   proximo_estado_matrizTransicaoEstados[MODO_ADMIN][CADASTRO] = AGUARDANDO_COD_CAD;
   acao_matrizTransicaoEstados[MODO_ADMIN][CADASTRO] = A17;

   proximo_estado_matrizTransicaoEstados[MODO_ADMIN][RECARGA_TROCO] = SELEC_MOEDA;
   acao_matrizTransicaoEstados[MODO_ADMIN][RECARGA_TROCO] = A22;

   proximo_estado_matrizTransicaoEstados[MODO_ADMIN][TIMEOUT] = MODO_ADMIN;
   acao_matrizTransicaoEstados[MODO_ADMIN][TIMEOUT] = A16;

   // Eventos recebidos pelo estado AGUARDANDO_COD_CAD
   proximo_estado_matrizTransicaoEstados[AGUARDANDO_COD_CAD][CANCELAR] = MODO_ADMIN;
   acao_matrizTransicaoEstados[AGUARDANDO_COD_CAD][CANCELAR] = A16;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_COD_CAD][CODIGO] = AGUARDANDO_PREC_CAD;
   acao_matrizTransicaoEstados[AGUARDANDO_COD_CAD][CODIGO] = A18;

   // Eventos recebidos pelo estado AGUARDANDO_PREC_CAD
   proximo_estado_matrizTransicaoEstados[AGUARDANDO_PREC_CAD][CANCELAR] = AGUARDANDO_COD_CAD;
   acao_matrizTransicaoEstados[AGUARDANDO_PREC_CAD][CANCELAR] = A17;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_PREC_CAD][PRECO] = AGUARDANDO_QTD_CAD;
   acao_matrizTransicaoEstados[AGUARDANDO_PREC_CAD][PRECO] = A19;

   // Eventos recebidos pelo estado AGUARDANDO_QTD_CAD
   proximo_estado_matrizTransicaoEstados[AGUARDANDO_QTD_CAD][CANCELAR] = AGUARDANDO_PREC_CAD;
   acao_matrizTransicaoEstados[AGUARDANDO_QTD_CAD][CANCELAR] = A18;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_QTD_CAD][QUANTIDADE] = AGUARDANDO_QTD_CAD;
   acao_matrizTransicaoEstados[AGUARDANDO_QTD_CAD][QUANTIDADE] = A20;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_QTD_CAD][CADASTRO_REALIZADO] = MODO_ADMIN;
   acao_matrizTransicaoEstados[AGUARDANDO_QTD_CAD][CADASTRO_REALIZADO] = A21;

   // Eventos recebidos pelo estado SELEC_MOEDA
   proximo_estado_matrizTransicaoEstados[SELEC_MOEDA][CANCELAR] = MODO_ADMIN;
   acao_matrizTransicaoEstados[SELEC_MOEDA][CANCELAR] = A16;

   proximo_estado_matrizTransicaoEstados[SELEC_MOEDA][TIMEOUT] = SELEC_MOEDA;
   acao_matrizTransicaoEstados[SELEC_MOEDA][TIMEOUT] = A22;

   proximo_estado_matrizTransicaoEstados[SELEC_MOEDA][TIPO_DE_MOEDA] = SELEC_MOEDA;
   acao_matrizTransicaoEstados[SELEC_MOEDA][TIPO_DE_MOEDA] = A23;

   proximo_estado_matrizTransicaoEstados[SELEC_MOEDA][MOEDA] = AGUARDANDO_QTD_MOEDA;
   acao_matrizTransicaoEstados[SELEC_MOEDA][MOEDA] = A24;

   // Eventos recebidos pelo estado SELEC_MOEDA
   proximo_estado_matrizTransicaoEstados[AGUARDANDO_QTD_MOEDA][CANCELAR] = SELEC_MOEDA;
   acao_matrizTransicaoEstados[AGUARDANDO_QTD_MOEDA][CANCELAR] = A22;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_QTD_MOEDA][QUANTIDADE] = AGUARDANDO_QTD_MOEDA;
   acao_matrizTransicaoEstados[AGUARDANDO_QTD_MOEDA][QUANTIDADE] = A25;

   proximo_estado_matrizTransicaoEstados[AGUARDANDO_QTD_MOEDA][REGISTRO_EFETUADO] = SELEC_MOEDA;
   acao_matrizTransicaoEstados[AGUARDANDO_QTD_MOEDA][REGISTRO_EFETUADO] = A26;

} // initStateMachine

/***********************************************************************
 iniciaSistema
 Inicia o sistema ...
 Parametros de entrada: nenhum
 Retorno: nenhum
************************************************************************/
extern void iniciaSistema(){
   iniciaMaquinaEstados();
} // initSystem
