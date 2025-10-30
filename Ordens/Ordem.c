#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordem.h"
#include "Clientes/Cliente.h" // Para usar buscarClientePorId
#include "util/util.h"

int caOrdens(struct OrdemServico listaDeOrdens[], int maxOrdens) {
    FILE *arquivo = fopen(ARQUIVO_ORDENS, "r");
    if (arquivo == NULL) {
        return 0;
    }

    int totalCarregadas = 0;
    // Formato: ID;IDCliente;Equipamento;Defeito;Status
    while (totalCarregadas < maxOrdens &&
           fscanf(arquivo, "%d;%d;%99[^;];%199[^;];%49[^\n]\n",
                  &listaDeOrdens[totalCarregadas].id,
                  &listaDeOrdens[totalCarregadas].idCliente,
                  listaDeOrdens[totalCarregadas].equipamento,
                  listaDeOrdens[totalCarregadas].defeito,
                  listaDeOrdens[totalCarregadas].status) == 5)
    {
        totalCarregadas++;
    }

    fclose(arquivo);
    return totalCarregadas;
}

void saOrdens(struct OrdemServico listaDeOrdens[], int totalOrdens) {
    FILE *arquivo = fopen(ARQUIVO_ORDENS, "w");
    if (arquivo == NULL) {
        perror("Erro grave: Nao foi possivel salvar os dados das ordens.");
        exit(1);
    }

    for (int i = 0; i < totalOrdens; i++) {
        fprintf(arquivo, "%d;%d;%s;%s;%s\n",
                listaDeOrdens[i].id,
                listaDeOrdens[i].idCliente,
                listaDeOrdens[i].equipamento,
                listaDeOrdens[i].defeito,
                listaDeOrdens[i].status);
    }
    fclose(arquivo);
}

int obOrdem(struct OrdemServico listaDeOrdens[], int totalOrdens) {
    if (totalOrdens == 0) return 1;
    return listaDeOrdens[totalOrdens - 1].id + 1;
}

void adOrdem(struct OrdemServico listaDeOrdens[], int *totalOrdens, struct Cliente listaClientes[], int totalClientes) {
    if (*totalOrdens >= MAX_ORDENS) {
        printf("Erro: Limite maximo de ordens atingido.\n");
        return;
    }

    limparTela();
    printf("--- Cadastro de Nova Ordem de Servico ---\n");

    struct Cliente *clienteDaOrdem = NULL;
    while (clienteDaOrdem == NULL) {
        listarClientes(listaClientes, totalClientes); // Mostra clientes para ajudar
        printf("\nDigite o ID do Cliente para esta ordem (ou 0 para cancelar): ");
        int idBusca = lerInteiro();

        if (idBusca == 0) {
            printf("Cadastro de ordem cancelado.\n");
            return;
        }

        clienteDaOrdem = buscarClientePorId(listaClientes, totalClientes, idBusca);
        if (clienteDaOrdem == NULL) {
            printf("Erro: Cliente com ID %d nao encontrado. Tente novamente.\n", idBusca);
            pausar();
            limparTela();
        }
    }

    // Se chegou aqui, o cliente é válido.
    printf("Cliente selecionado: %s\n", clienteDaOrdem->nome);

    struct OrdemServico *novaOrdem = &listaDeOrdens[*totalOrdens];
    novaOrdem->id = obOrdem(listaDeOrdens, *totalOrdens);
    novaOrdem->idCliente = clienteDaOrdem->id;

    printf("Equipamento (ex: Notebook Dell, PC Gamer): ");
    lerString(novaOrdem->equipamento, 100);

    printf("Defeito relatado: ");
    lerString(novaOrdem->defeito, 200);

    // Define um status inicial padrão
    strcpy(novaOrdem->status, "Aguardando Diagnostico");

    (*totalOrdens)++;
    printf("\nOrdem de servico (ID: %d) registrada com sucesso para %s.\n", novaOrdem->id, clienteDaOrdem->nome);
}

void liOrdens(struct OrdemServico listaDeOrdens[], int totalOrdens, struct Cliente listaClientes[], int totalClientes) {
    printf("--- Lista de Ordens de Servico (%d) ---\n", totalOrdens);
    if (totalOrdens == 0) {
        printf("Nenhuma ordem de servico registrada.\n");
        return;
    }

    printf("OS  | Cliente               | Equipamento           | Status\n");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < totalOrdens; i++) {
        struct OrdemServico *ordem = &listaDeOrdens[i];

        // Busca o nome do cliente usando o idCliente da ordem
        struct Cliente *cliente = buscarClientePorId(listaClientes, totalClientes, ordem->idCliente);
        char nomeCliente[30] = "Cliente nao encontrado";
        if (cliente != NULL) {
            strncpy(nomeCliente, cliente->nome, 29);
            nomeCliente[29] = '\0'; // Garante terminação
        }

        printf("%-3d | %-21s | %-21s | %s\n",
               ordem->id,
               nomeCliente,
               ordem->equipamento,
               ordem->status);
    }
}

// Função para atualizar o status de uma OS
void atOrdem(struct OrdemServico listaDeOrdens[], int totalOrdens) {
    printf("--- Atualizar Status da Ordem ---\n");
    printf("Digite o ID da Ordem de Servico (OS) a atualizar: ");
    int idBusca = lerInteiro();

    struct OrdemServico *ordemParaAtualizar = NULL;
    for (int i = 0; i < totalOrdens; i++) {
        if (listaDeOrdens[i].id == idBusca) {
            ordemParaAtualizar = &listaDeOrdens[i];
            break;
        }
    }

    if (ordemParaAtualizar == NULL) {
        printf("Erro: Ordem de Servico com ID %d nao encontrada.\n", idBusca);
        return;
    }

    printf("Ordem %d selecionada. Status atual: %s\n", ordemParaAtualizar->id, ordemParaAtualizar->status);
    printf("Digite o novo status (ex: Em reparo, Aguardando peca, Pronto): ");

    char novoStatus[50];
    lerString(novoStatus, 50);

    strcpy(ordemParaAtualizar->status, novoStatus);
    printf("Status atualizado com sucesso!\n");
}