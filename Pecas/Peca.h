#ifndef CLEITINHO_PECA_H
#define CLEITINHO_PECA_H

#define MAX_PECAS 100
#define ARQUIVO_PECAS "pecas.txt"

struct Peca
{
  int id;
  char nome[100];
  int quantidadeEstoque;
};

int caPecas(struct Peca listaDePecas[], int maxPecas);
void saPeca(struct Peca listaDePecas[], int totalPecas);
void adPeca(struct Peca listaDePecas[], int *totalPecas);
void liPecas(struct Peca listaDePecas[], int totalPecas);

#endif //CLEITINHO_PECA_H