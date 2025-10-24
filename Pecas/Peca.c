#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "util/util.h"

int caPecas(struct Peca listaDePecas[], int maxPecas) {
    FILE *arquivo = fopen(ARQUIVO_PECAS, "r");
    if (arquivo == NULL) {
        return 0;
    }

    int totalCarregadas = 0;
    // Formato: ID;Nome;Quantidade
    while (totalCarregadas < maxPecas &&
           fscanf(arquivo, "%d;%99[^;];%d\n",
                  &listaDePecas[totalCarregadas].id,
                  listaDePecas[totalCarregadas].nome,
                  &listaDePecas[totalCarregadas].quantidadeEstoque) == 3)
    {
        totalCarregadas++;
    }

    fclose(arquivo);
    return totalCarregadas;
}

void saPecas(struct Peca listaDePecas[], int totalPecas) {
    FILE *arquivo = fopen(ARQUIVO_PECAS, "w");
    if (arquivo == NULL) {
        perror("Erro grave: Nao foi possivel salvar os dados das pecas.");
        exit(1);
    }

    for (int i = 0; i < totalPecas; i++) {
        fprintf(arquivo, "%d;%s;%d\n",
                listaDePecas[i].id,
                listaDePecas[i].nome,
                listaDePecas[i].quantidadeEstoque);
    }

    fclose(arquivo);
}

int obterProximoIdPeca(struct  Peca listaDePecas[], int totalPecas) {
    if (totalPecas == 0) return 1;
    return listaDePecas[totalPecas - 1].id + 1;
}

void adPeca(struct Peca listaDePecas[], int *totalPecas) {
    if (*totalPecas >= MAX_PECAS) {
        printf("Erro: Limite maximo de pecas atingido.\n");
        return;
    }

    struct Peca *novaPeca = &listaDePecas[*totalPecas];
    novaPeca->id = obterProximoIdPeca(listaDePecas, *totalPecas);

    printf("--- Cadastro de Nova Peca (ID: %d) ---\n", novaPeca->id);
    printf("Nome da Peca: ");
    lerString(novaPeca->nome, 100);

    printf("Quantidade em Estoque: ");
    novaPeca->quantidadeEstoque = lerInteiro();

    (*totalPecas)++;

    printf("\nPeca cadastrada com sucesso!\n");
}

void listarPecas(struct Peca listaDePecas[], int totalPecas) {
    printf("--- Lista de Pecas em Estoque (%d) ---\n", totalPecas);
    if (totalPecas == 0) {
        printf("Nenhuma peca cadastrada.\n");
        return;
    }

    printf("ID   | Nome                  | Qtd.\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < totalPecas; i++) {
        printf("%-4d | %-21s | %d\n",
               listaDePecas[i].id,
               listaDePecas[i].nome,
               listaDePecas[i].quantidadeEstoque);
    }
}