#include <stdio.h>
#include <stdlib.h> // biblioteca para funções de alocação de memória e controle de processos etc
#include <string.h> // biblioteca para manipulação de strings

int main() {
    // comando para abrir o documento csv e armazená-lo na variável "arquivo"
	FILE* arquivo = fopen("sistemaestoque.csv", "a+");

    // variáveis para armazenar dados dos produtos
	char nomeProduto[50], tipoProduto[50], fornecedor[50];
	int quantidadeDisponivel; 
	double precoUnitario;

    // tratamento de erro, caso o arquivo não seja encontrado
	if (!arquivo) {
			printf("Não foi possível abrir o arquivo!\n");
			return 0;
	}

    // comandos para pegar input do user e armazenar os dados dos produtos
	printf("\nInforme o nome do produto: ");
	scanf("%[^\n]%*c", &nomeProduto);
	printf("\nInforme a quantidade disponível: ");
	scanf("%d", &quantidadeDisponivel);
	printf("\nInforme o preço unitário: ");
	scanf("%lf", &precoUnitario);
	printf("\nInforme o tipo de produto: ");
	scanf("%s", &tipoProduto);
	printf("\nInforme o fornecedor: ");
	scanf("%s", &fornecedor);

    // comando para passar os dados inseridos para o arquivo csv
	fprintf(arquivo, "%s, %d, %lf, %s, %s\n", nomeProduto, quantidadeDisponivel, precoUnitario, tipoProduto, fornecedor);

    // retorno ao usuário
	printf("\nNovo produto adicionado!");

    // comando para fechar o arquivo
	fclose(arquivo);

	return 0;
}
