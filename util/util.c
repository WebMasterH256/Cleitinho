#include <stdio.h>
#include <stdlib.h> // Para system() e strtol
#include <string.h> // Para strchr e strlen
#include "util.h"

// Função para limpar o buffer de entrada (stdin)
void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

// Lê uma string de forma segura
void lerString(char *buffer, int tamanho) {
  if (fgets(buffer, tamanho, stdin) != NULL) {
    // Remove o '\n' (nova linha) que o fgets deixa
    char *newline = strchr(buffer, '\n');
    if (newline) {
      *newline = '\0';
    } else {
      // Se não encontrou '\n', o usuário digitou mais que o limite
      // Limpa o resto do buffer
      limparBuffer();
    }
  }
}

// Lê um inteiro de forma segura
int lerInteiro() {
  char buffer[50];
  char *endptr;

  while (1) {
    lerString(buffer, sizeof(buffer));
    long valor = strtol(buffer, &endptr, 10); // Converte string para long (base 10)

    // strtol é seguro:
    // Se a conversão foi válida E não sobrou lixo no buffer (ex: "123abc")
    if (endptr != buffer && (*endptr == '\0' || *endptr == '\n')) {
      return (int)valor; // Conversão bem-sucedida
    } else {
      printf("Entrada inválida. Digite apenas números: ");
    }
  }
}

void limparTela() {
#ifdef _WIN32 // Se estiver no Windows
  system("cls");
#else // Para Linux/Mac
  system("clear");
#endif
}

void pausar() {
  printf("\nPressione Enter para continuar...");
  limparBuffer(); // Limpa qualquer '\n' pendente
  getchar(); // Espera o Enter
}