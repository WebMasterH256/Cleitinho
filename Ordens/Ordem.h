#ifndef CLEITINHO_ORDEM_H
#define CLEITINHO_ORDEM_H

#define MAX_ORDENS 200
#define ARQUIVO_ORDENS "ordens.txt"

struct OrdemServico
{
  int id;
  int idCliente; // Chave estrangeira
  char equipamento[100];
  char defeito[200];
  char status[50];
};



#endif