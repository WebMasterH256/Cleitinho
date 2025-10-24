#ifndef CLEITINHO_CLIENTE_H
#define CLEITINHO_CLIENTE_H

#define MAX_CLIENTES 100
#define ARQUIVO_CLIENTES "clientes.txt"

struct Cliente
{
  int id; // Chave primária
  char nome[100];
  char telefone[15];
  char email[100];
};

int caClientes(struct Cliente listaDeClientes[], int maxClientes);
void saCliente(struct Cliente listaDeClientes[], int totalClientes);
void adCliente(struct Cliente listaDeClientes[], int *totalClientes);

void listarClientes(struct Cliente listaDeClientes[], int totalClientes);
struct Cliente* buscarClientePorId(struct Cliente listaDeClientes[], int totalClientes, int idBusca);
#endif