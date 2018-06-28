#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED

/* NIVEIS LOGICOS */
#define true  1
#define false 0

/* ESCOLHA DE ALTERACAO */
#define SELEC_QTD 0
#define SELEC_PRECO 1

/* MÁQUINA DE ESTADOS */
#define NUM_ESTADOS 11
#define NUM_EVENTOS 25

/* ESTADOS */
#define AGUARDANDO_COMANDO    0
#define AGUARDANDO_DINHEIRO   1
#define LIBERANDO_PRODUTO     2
#define LIBERANDO_TROCO       3
#define AGUARDANDO_SENHA      4
#define MODO_ADMIN            5
#define AGUARDANDO_COD_CAD    6
#define AGUARDANDO_PREC_CAD   7
#define AGUARDANDO_QTD_CAD    8
#define SELEC_MOEDA           9
#define AGUARDANDO_QTD_MOEDA  10


/* EVENTOS */
#define NENHUM_EVENTO       -1
#define DESLIGAR             0
#define PRODUTO_SELECIONADO  1
#define PRODUTO_INVALIDO     2
#define DINHEIRO_TOTAL       3
#define FALTA_PRODUTO        4
#define TIMEOUT              5
#define DINHEIRO_INSERIDO    6
#define CANCELAR             7
#define ENTRAR_ADMIN         8
#define DESISTENCIA          9
#define FALTA_TROCO          10
#define COMPRA_VALIDA        11
#define LIBERAR_TROCO        12
#define AGUARDAR             13
#define SENHA_INVALIDA       14
#define SENHA_VALIDA         15
#define CADASTRO             16
#define RECARGA_TROCO        17
#define CADASTRO_REALIZADO   18
#define CODIGO               19
#define PRECO                20
#define QUANTIDADE           21
#define TIPO_DE_MOEDA        22
#define MOEDA                23
#define REGISTRO_EFETUADO    24

/* ACOES */
#define NENHUMA_ACAO -1
#define A01  0
#define A02  1
#define A03  2
#define A04  3
#define A05  4
#define A06  5
#define A07  6
#define A08  7
#define A09  8
#define A10  9
#define A11  10
#define A12  11
#define A13  12
#define A14  13
#define A15  14
#define A16  15
#define A17  16
#define A18  17
#define A19  18
#define A20  19
#define A21  20
#define A22  21
#define A23  22
#define A24  23
#define A25  24
#define A26  25
#endif // DEFINICOES_SISTEMA_H_INCLUDED
