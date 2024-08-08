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

void salvar_produtos()
{
    FILE * arq = fopen("produtos.txt", "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }

    fprintf("Nome: %s\nCodigo: %s\nPreco de compra: %f\n\n", produto[produtos_existentes].nome, produto[produtos_existentes].codigo, produto[produtos_existentes].preco);

    fclose(arq);
}

void salvar_funcionario()
{
    
}

void cadastro_funcionario()
{
    printf("Digite o nome do novo funcionario: ");
    
    fflush(stdin);
    gets(funcionario[produtos_existentes].nome);

    printf("Digite o codigo do novo funcionario (limite de 6 digitos) : ");
    
    fflush(stdin);
    gets(funcionario[produtos_existentes].codigo);

    printf("Digite o cpf do novo funcionario (inclua os sinais) : ");
    
    fflush(stdin);
    gets(funcionario[produtos_existentes].cpf);

    printf("Digite a data de nascimento do novo funcionario (inclua as barras) : ");

    scanf("%d/%d/%d", &funcionario[produtos_existentes].nascimento.dia, &funcionario[produtos_existentes].nascimento.mes, &funcionario[produtos_existentes].nascimento.ano);

    printf("Digite a senha do novo funcionario (maximo de 25 caracteres) : ");
    
    fflush(stdin);
    gets(funcionario[i].senha);

    printf("Digite o numero de telefone do novo funcionario (apenas os numeros) : ");
    
    fflush(stdin);
    gets(funcionario[i].contato);
    salvar_funcionario();

    produtos_existentes++;

}