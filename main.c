#include <stdio.h>
#include <stdlib.h>

/*
    VENDING MACHINE
    Autor: Bruno Peixoto
    Data: Abril 2013
*/

#include "definicoes_sistema.h"
#include "ihm.h"
#include "senhas.h"
#include "timer.h"
#include "dispenser.h"
#include "bancodeprodutos.h"
#include "dinheiro.h"
#include "troco.h"
#include "matrizdeEstadoseAcoes.h"

/***********************************************************************
 Estaticos
 ***********************************************************************/
  int codigoEvento;
  int codigoAcao;
  int estado;

/**********************************************************************
 Variaveis Globais
 **********************************************************************/

/******************* Variaveis da maquina de estados ******************/

// Codigo correspondente ao evento em execucao
int codigoEvento;

// Codigo correpondente a Acao em execucao
int codigoAcao;

// Estado atual da maquina
int estado;

// Evento Interno de determinada acao
int eventoInterno;

/********** Vari�veis para decodificacao e execucao de acoes **********/

// Teclas digitadas pelo usuario do simulador
char* teclas;

// Vari�vel que conta quantas vezes a maquina
//    j� solicitou que o cliente colocasse mais
//    dinheiro na m�quina
int pedeDinheiroAoCliente;

// Valor de dinheiro ja inserido pelo usuario
int dinheiroAtual;

// Quando est� sendo efetuado uma compra de produto,
//    esta variavel guarda o c�digo do produto
int codigoMaquina;

// Valor de troco a devolver ao cliente
int troco;

// Codigo do produto para manipulacao no banco de dados
//    (cadastro, exclusao, alteracao)
int codigo_manip;

// Preco do c�digo para manipulacao no banco de dados
//    (cadastro, exclusao, alteracao)
int preco_manip;

// Quantidade do codigo para manipulacao no banco de dados
//    (cadastro, exclusao, alteracao)
int qtdade_manip;

// tipo de moeda a ser inserida
int tipo_moeda;

// Quantidade de determinada moeda
int qtdade_moeda;

/***********************************************************************
 executarAcao
 Executa uma acao
 Parametros de entrada:
    (int) codigo da acao a ser executada
 Retorno: (int) codigo do evento interno ou NENHUM_EVENTO
************************************************************************/
int executarAcao(int codigoAcao){
   int retval;

   retval = NENHUM_EVENTO;
   if (codigoAcao == NENHUMA_ACAO)
       return retval;

   switch(codigoAcao){
   case A01:
   {
      teclas++;
      codigoMaquina = atoi(teclas);
      teclas[0] = 0x0;
      if (prd_quantidade(codigoMaquina) != -1){ // SLOT_INEXISTENTE
         if(prd_quantidade(codigoMaquina) == 0)
            retval = FALTA_PRODUTO;
         else
         {
            tmr_iniciar(true);
            pedeDinheiroAoCliente = 0;
            dinheiroAtual = 0;
            ihm_exibirMsg("Insira o dinheiro");
         }
      }
      else{
         retval = PRODUTO_INVALIDO;
      }
   break;
   }

   case A02:
      if(++pedeDinheiroAoCliente >= 4)
      {
         retval = DESISTENCIA;
         tmr_iniciar(true);
         ihm_exibirMsg("Compra Cancelada");
      }
   break;

   case A03:
   {
      int dinheiroinserido;
      dinheiroinserido = dnr_valorDinheiroInserido();
      dinheiroAtual += dinheiroinserido;
      if(dinheiroAtual < prd_preco(codigoMaquina))
         ihm_exibirMsg("Insira o dinheiro");
      else
      {
         tmr_iniciar(false);
         retval = DINHEIRO_TOTAL;
      }
   break;
   }

   case A04:
       retval = DESISTENCIA;
       ihm_exibirMsg("Compra Cancelada");
   break;

   case A05:
      if(dinheiroAtual > 0)
         dnr_devolveDinheiro(dinheiroAtual);
      tmr_iniciar(true);
   break;

   case A06:
      ihm_exibirMsg("Troco indisponivel no momento.");
      tmr_iniciar(true);
      dnr_devolveDinheiro(dinheiroAtual);
   break;

   case A07:
      troco = dinheiroAtual - prd_preco(codigoMaquina);
      if(trc_verificaTroco(troco))
         retval = COMPRA_VALIDA;
      else
         retval = FALTA_TROCO;
   break;

   case A08:
      ihm_exibirMsg("Aguarde o produto ser liberado");
      dsr_liberaProduto(codigoMaquina);
      tmr_iniciar(true);
   break;

   case A09:
      if(troco > 0)
         retval = LIBERAR_TROCO;
      else
         retval = AGUARDAR;
   break;

   case A10:
      ihm_exibirMsg("Aguarde o troco ser liberado");
      trc_liberarTroco(troco);
      tmr_iniciar(true);
   break;

   case A11:
      retval = AGUARDAR;
   break;

   case A12:
      ihm_exibirMsg("Selecione o produto");
      teclas = ihm_obterTeclas();
   break;

   case A13:
      tmr_iniciar(true);
      ihm_exibirMsg("Produto indisponivel");
   break;

   case A14:
      ihm_exibirMsg("Insira a senha");
      teclas = ihm_obterTeclas();
   break;

   case A15:
      ihm_exibirMsg("Produto Invalido");
      tmr_iniciar(true);
   break;

   case A16:
      ihm_exibirMsg("Selecione uma opcao a ser executada:\n\t1 - Cadastrar\n\t2 - Recarregar\n\tccl - Cancelar");
      tmr_iniciar(true);
      teclas = ihm_obterTeclas();
   break;

   case A17:
      ihm_exibirMsg("Insira o codigo do produto a ser cadastrado");
      teclas = ihm_obterTeclas();
   break;

   case A18:
      teclas++;
      codigo_manip = atoi(teclas);
      teclas[0] = 0x0;
      ihm_exibirMsg("Insira o preco do produto a ser cadastrado:");
      teclas = ihm_obterTeclas();
   break;

   case A19:
      teclas++;
      preco_manip = atoi(teclas);
      teclas[0] = 0x0;
      ihm_exibirMsg("Insira a quantidade do produto a ser cadastrado:");
      teclas = ihm_obterTeclas();
   break;

   case A20:
      teclas++;
      qtdade_manip = atoi(teclas);
      teclas[0] = 0x0;
      prd_cadastra(codigo_manip,preco_manip,qtdade_manip);
      retval = CADASTRO_REALIZADO;
   break;

   case A21:
      tmr_iniciar(true);
      ihm_exibirMsg("Cadastro realizado com sucesso");
   break;

   case A22:
      ihm_exibirMsg("Selecione qual tipo de moeda deseja recarregar (m10 / m25 / m50 / m100)");
      teclas = ihm_obterTeclas();
   break;

   case A23:
      teclas++;
      tipo_moeda = atoi(teclas);
      teclas[0] = 0x0;
      retval = MOEDA ;
   break;

   case A24:
      ihm_exibirMsg("Insira a quantidade que deseja recarregar");
      teclas = ihm_obterTeclas();
   break;

   case A25:
      teclas++;
      qtdade_moeda = atoi(teclas);
      teclas[0] = 0x0;
      trc_registraMoeda(tipo_moeda,qtdade_moeda);
      retval = REGISTRO_EFETUADO;
   break;

   case A26:
      tmr_iniciar(true);
      ihm_exibirMsg("Registro realizado com sucesso");
   break;

   } // switch

   return retval;
} // executarAcao

/***********************************************************************
 obterEvento
 Obtem um evento, que pode ser da IHM ou do alarme
 Parametros de entrada: nenhum
 Retorno: codigo do evento
************************************************************************/
int decodificarProdutoSelecionado(){
   if (teclas[0] == 'p')
   {
   return true;
   }
   return false;
}// decodificarProdutoSelecionado

int decodificarTimeout(){
   return tmr_timeout();
}// decodificarTimeout

int decodificarDinheiroInserido(){
   return dnr_dinheiroInserido(estado);
}// decodificarDinheiroInserido

int decodificarCancelar(){
    if ((teclas[0] == 'c') &&
        (teclas[1] == 'c') &&
        (teclas[2] == 'l'))
    {
        return true;
    }
    return false;
}// decodificarCancelar

int decodificarAdmin(){
    if ((teclas[0] == 'a') &&
        (teclas[1] == 'd') &&
        (teclas[2] == 'm') &&
        (teclas[3] == 'i') &&
        (teclas[4] == 'n'))
    {
        return true;
    }
    return false;
}// decodificarAdmin

int decodificarDesligar(){
    if ((teclas[0] == 'o') &&
        (teclas[1] == 'f') &&
        (teclas[2] == 'f'))
    {
        return true;
    }
    return false;
}// decodificarDesligar

int decodificarSenha(){
    return sha_validar(teclas);
}// decodificarSenhaValida

int decodificarCadastro(){
   if(teclas[0] == '1')
      return true;

   return false;
}// decodificarCadastro

int decodificarRecarga(){

   if(teclas[0] == '2')
      return true;
   return false;
}// decodificarRecarga

int decodificarCodigo(){

   if(teclas[0] == 'a')
      return true;
   return false;
}// decodificarCodigo

int decodificarPreco(){
   if(teclas[0] == 'e')
      return true;
   return false;
}// decodificarPreco

int decodificarQuantidade(){
   if(teclas[0] == 'q')
      return true;
   return false;
}// decodificarQuantidade

int decodificarTipoMoeda(){
   if(teclas[0] == 'm')
      return true;
   return false;
}// decodificarTipoMoeda

int decodificarQtdadeMoeda(){
   if(teclas[0] == 'M')
      return true;
   return false;
}// decodificarQtdadeMoeda

int obterEvento(){
   int retval = NENHUM_EVENTO;

   if (decodificarDesligar())
      return DESLIGAR;

   if (decodificarProdutoSelecionado())
      return PRODUTO_SELECIONADO;

   if (decodificarAdmin())
      return ENTRAR_ADMIN;

   if (decodificarDinheiroInserido())
      return DINHEIRO_INSERIDO;

   if (decodificarCancelar())
      return CANCELAR;

   if((estado == AGUARDANDO_COMANDO)||
      (estado == AGUARDANDO_DINHEIRO)||
      (estado == LIBERANDO_PRODUTO)||
      (estado == LIBERANDO_TROCO)||
      (estado == MODO_ADMIN)||
      (estado == SELEC_MOEDA))
   {

      if (decodificarTimeout())
         return TIMEOUT;
   }

   if(estado == AGUARDANDO_SENHA){
      if (!(decodificarSenha()))
         return SENHA_INVALIDA;

      if (decodificarSenha())
         return SENHA_VALIDA;
   }

   if(estado == MODO_ADMIN){
      if (decodificarCadastro())
         return CADASTRO;

      if (decodificarRecarga())
         return RECARGA_TROCO;
   }

   if (decodificarCodigo())
      return CODIGO;

   if (decodificarPreco())
      return PRECO;

   if (decodificarQuantidade())
      return QUANTIDADE;

   if (decodificarTipoMoeda())
      return MOEDA;

   return retval;

} // obterEvento


/***********************************************************************
 obterAcao
 Obtem uma acao da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo da acao
************************************************************************/
int obterAcao(int estado, int codigoEvento){
  return acao_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao

/***********************************************************************
 obterProximoEstado
 Obtem o proximo estado da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo do estado
************************************************************************/
int obterProximoEstado(int estado, int codigoEvento){
  return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


/***********************************************************************
 Main
 Loop principal de controle que executa a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
************************************************************************/
int main(){

   iniciaSistema();
   printf ("Vending Machine Acionada!\n");

   estado = AGUARDANDO_COMANDO;
   eventoInterno = NENHUM_EVENTO;
   printf("Estado: %d Evento: %d Acao:%d\n", estado, codigoEvento, codigoAcao);
   executarAcao(A12);


   while (true) {
      if (eventoInterno == NENHUM_EVENTO){
         codigoEvento = obterEvento();
      } else {
         codigoEvento = eventoInterno;
      }
      if(codigoEvento == DESLIGAR) break;

      if (codigoEvento != NENHUM_EVENTO){
         codigoAcao = obterAcao(estado, codigoEvento);
         estado = obterProximoEstado(estado, codigoEvento);
         printf("Estado: %d Evento: %d Acao:%d\n\n", estado, codigoEvento, codigoAcao);
         eventoInterno = executarAcao(codigoAcao);
      }
   } // while true
   printf("Vending Machine Desacionada");

   return 1;
}
