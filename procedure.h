#include "lib.h"
void recuperar_entrada_produto()
{
    FILE * arq = fopen("produtos.txt", "r");

    if (arq == NULL)
    {
        printf("Erro ao recuperar informaacoes do arquivo produtod.txt.\n");
        system("pause");
        system("cls");
        return;
    }

    while (fscanf (arq, "Nome: %[^\n]\nCodigo: %[^\n]\nPreco de compra: %f\n\n", produto[i].nome, produto[i].codigo, &produto[i].preco) == 3)
    {
        i++;
        produtos_existentes++;
    };

    fclose(arq);
}

void salvar_produtos(int i) // o numero que vai receber sera o indice do novo produto cadastrado
{
    FILE * arq = fopen("produtos.txt", "a");
    
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }

    fprintf("Nome: %s\nCodigo: %s\nPreco de compra: %f\n\n", produto[i].nome, produto[i].codigo, produto[i].preco);

    fclose(arq);
}

