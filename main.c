#include <stdio.h>
#include <stdlib.h> // biblioteca para funções de alocação de memória e controle de processos etc
#include <string.h> // biblioteca para manipulação de strings
#include <locale.h>

int main() {
	setlocale (LC_ALL, "portuguese");
	
    // comando para abrir o documento csv e armazená-lo na variável "arquivo"
	FILE* arquivo = fopen("sistemaestoque.csv", "a+");

    // variáveis para armazenar dados dos produtos
	char nomeProduto[50], tipoProduto[50], fornecedor[50], linha[50]; // array "linha" armazena temporariamente as strings que o user digita
	int quantidadeDisponivel; 
	double precoUnitario;

    // tratamento de erro, caso o arquivo não seja encontrado
	if (!arquivo) {
		printf("Não foi possível abrir o arquivo!\n");
		return 0;
	}

    // comandos para pegar input do user e armazenar os dados dos produtos
	printf("\nInforme o nome do produto: ");
	fgets(linha, sizeof(linha), stdin);
    	sscanf(linha, "%49[^\n]", nomeProduto);

    	printf("\nInforme a quantidade disponível: ");
    	fgets(linha, sizeof(linha), stdin);
    	sscanf(linha, "%d", &quantidadeDisponivel);

    	printf("\nInforme o preço unitário: ");
    	fgets(linha, sizeof(linha), stdin);
    	sscanf(linha, "%lf", &precoUnitario);

    	printf("\nInforme o tipo de produto: ");
    	fgets(linha, sizeof(linha), stdin);
    	sscanf(linha, "%49[^\n]", tipoProduto);

    	printf("\nInforme o fornecedor: ");
    	fgets(linha, sizeof(linha), stdin);
    	sscanf(linha, "%49[^\n]", fornecedor);

    // comando para passar os dados inseridos para o arquivo csv
	fprintf(arquivo, "%s, %d, %lf, %s, %s\n", nomeProduto, quantidadeDisponivel, precoUnitario, tipoProduto, fornecedor);

    // retorno ao usuário
	printf("\nNovo produto adicionado!");

    // comando para fechar o arquivo
	fclose(arquivo);

	return 0;
}
