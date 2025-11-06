#include <stdio.h>

#include "Clientes/cliente.h"
#include "Ordens/ordem.h"
#include "Pecas/peca.h"
#include "util/util.h"

void menuClientes(struct Cliente lista[], int *total);
void menuOrdens(struct OrdemServico listaO[], int *totalO, struct Cliente listaC[], int totalC);
void menuPecas(struct Peca lista[], int *total);

int main() {
    struct Cliente liClientes[MAX_CLIENTES];
    struct OrdemServico liOrden[MAX_ORDENS];
    struct Peca liPeca[MAX_PECAS];

    int numClientes = 0;
    int numOrdens = 0;
    int numPecas = 0;

    limparTela();
    printf("Carregando dados do sistema...\n");
    numClientes = caClientes(liClientes, MAX_CLIENTES);
    numOrdens = caOrdens(liOrden, MAX_ORDENS);
    numPecas = caPecas(liPeca, MAX_PECAS);

    printf("-> %d clientes, %d ordens, %d pecas carregadas.\n", numClientes, numOrdens, numPecas);

    int opcao = -1;
    while (opcao != 0) {
        limparTela();
        printf("--- Loja de Manutencao do Cleitinho ---\n");
        printf("1. Gerenciar Clientes (%d)\n", numClientes);
        printf("2. Gerenciar Ordens de Servico (%d)\n", numOrdens);
        printf("3. Gerenciar Estoque de Pecas (%d)\n", numPecas);
        printf("-----------------------------------------\n");
        printf("0. Sair e Salvar\n");
        printf("-----------------------------------------\n");
        printf("Escolha uma opcao: ");

        opcao = lerInteiro();

        switch (opcao) {
            case 1:
                menuClientes(liClientes, &numClientes);
                break;
            case 2:
                menuOrdens(liOrden, &numOrdens, liClientes, numClientes);
                break;
            case 3:
                menuPecas(liPeca, &numPecas);
                break;
            case 0:
                printf("Salvando dados... Nao desligue.\n");
                saCliente(liClientes, numClientes);
                saOrdens(liOrden, numOrdens);
                saPeca(liPeca, numPecas);
                printf("Dados salvos. Ate logo!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                pausar();
                break;
        }
    }

    return 0;
}

void menuClientes(struct Cliente lista[], int *total) {
    int opcao = -1;
    while (opcao != 0) {
        limparTela();
        printf("--- Gerenciar Clientes (%d) ---\n", *total);
        printf("1. Adicionar Novo Cliente\n");
        printf("2. Listar Clientes\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Opcao: ");
        opcao = lerInteiro();

        switch(opcao) {
            case 1:
                adCliente(lista, total);
                pausar();
                break;
            case 2:
                listarClientes(lista, *total);
                pausar();
                break;
            case 0:
                break; // Sai do loop while e volta pro main
            default:
                printf("Opcao invalida.\n");
                pausar();
        }
    }
}

void menuOrdens(struct OrdemServico listaO[], int *totalO, struct Cliente listaC[], int totalC) {
    int opcao = -1;
    while (opcao != 0) {
        limparTela();
        printf("--- Gerenciar Ordens de Servico (%d) ---\n", *totalO);
        printf("1. Adicionar Nova Ordem\n");
        printf("2. Listar Ordens\n");
        printf("3. Atualizar Status de Ordem\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Opcao: ");
        opcao = lerInteiro();

        switch(opcao) {
            case 1:
                adOrdem(listaO, totalO, listaC, totalC);
                pausar();
                break;
            case 2:
                liOrdens(listaO, *totalO, listaC, totalC);
                pausar();
                break;
            case 3:
                atOrdem(listaO, *totalO);
                pausar();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
                pausar();
        }
    }
}

void menuPecas(struct Peca lista[], int *total) {
    int opcao = -1;
    while (opcao != 0) {
        limparTela();
        printf("--- Gerenciar Estoque de Pecas (%d) ---\n", *total);
        printf("1. Adicionar Nova Peca ao Estoque\n");
        printf("2. Listar Pecas\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Opcao: ");
        opcao = lerInteiro();

        switch(opcao) {
            case 1:
                adPeca(lista, total);
                pausar();
                break;
            case 2:
                liPecas(lista, *total);
                pausar();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
                pausar();
        }
    }
}