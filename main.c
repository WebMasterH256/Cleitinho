#include <locale.h>
#include <stdio.h>

#include "util/util.h"
#include "Clientes/Cliente.h"
#include "Ordens/Ordem.h"
#include "Pecas/Peca.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

	struct Cliente listaClientes[MAX_CLIENTES];
	struct listaOrdens[MAX_ORDENS];
	struct Peca listaPecas[MAX_PECAS];

	int numClientes = 0;
	int numOrdens = 0;
	int numPecas = 0;

	printf("Carregando dados...\n");
	numClientes = caClientes(listaClientes, MAX_CLIENTES);
	printf("%d clientes carregados.\n", numClientes);
	pausar();

	int opcao = -1;
	while (opcao != 0) {
		limparTela();
		printf("--- Loja de Manutencao do Cleitinho ---\n");
		printf("1. Gerenciar Clientes\n");
		printf("2. Gerenciar Ordens de Servico\n");
		printf("3. Gerenciar Estoque de Pecas\n");
		printf("0. Sair e Salvar\n");
		printf("-----------------------------------------\n");
		printf("Escolha uma opcao: ");

		opcao = lerInteiro(); // Usa nossa função segura!

		switch (opcao) {
		case 1:
			// (Aqui você pode criar um sub-menu para clientes)
			limparTela();
			printf("--- Gerenciar Clientes ---\n");
			printf("1. Adicionar Novo Cliente\n");
			printf("2. Listar Clientes\n"); // Você precisa implementar isso!
			printf("Opcao: ");
			int subOpcao = lerInteiro();
			if (subOpcao == 1) {
				saCliente(listaClientes, numClientes);
			}
			pausar();
			break;

		case 2:
			printf("Modulo de Ordens ainda nao implementado.\n");
			pausar();
			break;

		case 3:
			printf("Modulo de Pecas ainda nao implementado.\n");
			pausar();
			break;

		case 0:
			printf("Salvando dados... Nao desligue.\n");
			// --- Salvamento Final ---
			saCliente(listaClientes, numClientes);
			// (Aqui você chamará as funções para salvar ordens e peças)
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
