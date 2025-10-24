#include <stdio.h>
#include <stdlib.h>
#include "cliente.h" // Inclui nossas definições
#include "util/util.h"    // Inclui nossas funções seguras

int caClientes(struct Cliente listaDeClientes[], int maxClientes) {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "r");
    if (arquivo == NULL) {
        return 0; // 0 clientes carregados
    }

    int totalCarregados = 0;
    while (totalCarregados < maxClientes &&
           fscanf(arquivo, "%d;%99[^;];%19[^\n]\n",
                  &listaDeClientes[totalCarregados].id,
                  listaDeClientes[totalCarregados].nome,
                  listaDeClientes[totalCarregados].telefone) == 3)
    {
        totalCarregados++;
    }

    fclose(arquivo);
    return totalCarregados;
}

void saCliente(struct Cliente listaDeClientes[], int totalClientes) {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "w");
    if (arquivo == NULL) {
        perror("Erro grave: Nao foi possivel salvar os dados dos clientes.");
        exit(1);
    }

    for (int i = 0; i < totalClientes; i++) {
        fprintf(arquivo, "%d;%s;%s\n",
                listaDeClientes[i].id,
                listaDeClientes[i].nome,
                listaDeClientes[i].telefone);
    }

    fclose(arquivo);
}

// Gera um ID único baseado no último cliente
int obterProximoIdCliente(struct Cliente listaDeClientes[], int totalClientes) {
    if (totalClientes == 0) {
        return 1; // Primeiro cliente
    }
    // Pega o ID do último cliente no array e soma 1
    return listaDeClientes[totalClientes - 1].id + 1;
}

void adCliente(struct Cliente listaDeClientes[], int *totalClientes) {
    if (*totalClientes >= MAX_CLIENTES) {
        printf("Erro: Limite maximo de clientes atingido.\n");
        return;
    }

    struct Cliente *novoCliente = &listaDeClientes[*totalClientes];

    // Gera o novo ID
    novoCliente->id = obterProximoIdCliente(listaDeClientes, *totalClientes);

    printf("--- Cadastro de Novo Cliente (ID: %d) ---\n", novoCliente->id);
    printf("Nome: ");
    lerString(novoCliente->nome, 100);

    printf("Telefone: ");
    lerString(novoCliente->telefone, 20);

    (*totalClientes)++; // Incrementa o contador de clientes

    printf("\nCliente cadastrado com sucesso!\n");
}

void listarClientes(struct Cliente listaDeClientes[], int totalClientes) {
    printf("--- Lista de Clientes (%d) ---\n", totalClientes);
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("ID   | Nome                  | Telefone\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < totalClientes; i++) {
        printf("%-4d | %-21s | %s\n",
               listaDeClientes[i].id,
               listaDeClientes[i].nome,
               listaDeClientes[i].telefone);
    }
}

struct Cliente* buscarClientePorId(struct Cliente listaDeClientes[], int totalClientes, int idBusca) {
    for (int i = 0; i < totalClientes; i++) {
        if (listaDeClientes[i].id == idBusca) {
            return &listaDeClientes[i]; // Retorna o endereço do cliente encontrado
        }
    }
    return NULL; // Não encontrado
}