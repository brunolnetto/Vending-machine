#ifndef MATRIZDEESTADOSEACOES_H_INCLUDED
#define MATRIZDEESTADOSEACOES_H_INCLUDED

extern int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
extern int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];

/***********************************************************************
 iniciaMaquina de Estados
 Carrega a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
************************************************************************/
extern void iniciaMaquinaEstados(void);

/***********************************************************************
 iniciaSistema
 Inicia o sistema ...
 Parametros de entrada: nenhum
 Retorno: nenhum
************************************************************************/
extern void iniciaSistema(void);

#endif // MATRIZDEESTADOSEACOES_H_INCLUDED
