#ifndef CLEITINHO_ORDEM_H
#define CLEITINHO_ORDEM_H

#define MAX_ORDENS 200
#define ARQUIVO_ORDENS "ordens.txt"

#include "Clientes/Cliente.h"

struct OrdemServico
{
  int id;
  int idCliente;
  char equipamento[100];
  char defeito[200];
  char status[50];
};

int caOrdens(struct OrdemServico listaDeOrdens[], int maxOrdens);

void saOrdens(struct OrdemServico listaDeOrdens[], int totalOrdens);

void adOrdem(struct OrdemServico listaDeOrdens[], int *totalOrdens, struct Cliente listaClientes[], int totalClientes);

void liOrdens(struct OrdemServico listaDeOrdens[], int totalOrdens, struct Cliente listaClientes[], int totalClientes);

void atOrdem(struct OrdemServico listaDeOrdens[], int totalOrdens);

#endif