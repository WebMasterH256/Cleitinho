#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	printf("Olá!");
	
	return 0;
	
}
