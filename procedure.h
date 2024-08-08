#include "lib.h"

void recuperar_senha_adm()
{
    FILE * arq = fopen("senha_adm.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao recuperar informacoes do arquivo senha_adm.txt.\n");
        system("pause");
        system("cls");
        return;
    }

    fscanf(arq, "Ola admnistrador, digite sua senha a seguir (máximo de 6 digitos) : %[^\n]", senha_adm);

    fclose(arq);

}
void recuperar_funcionario()
{
    FILE * arq = fopen("funcionarios.txt", "r");

    if (arq == NULL)
    {
        printf("Erro ao recuperar informacoes do arquivo funcionarios.txt.\n");
        system("pause");
        system("cls");
        return;
    }

    while (fscanf(arq, "Nome: %[^\n]\nCodigo: %[^\n]\nCPF: %[^\n]\nData de nascimento: %d/%d/%d\nSenha: %[^\n]\nTelefone: %[^\n]\n\n", funcionario[funcionarios_existentes].nome, funcionario[funcionarios_existentes].codigo, &funcionario[funcionarios_existentes].nascimento.dia, &funcionario[funcionarios_existentes].nascimento.mes, &funcionario[funcionarios_existentes].nascimento.ano, funcionario[funcionarios_existentes].senha, funcionario[funcionarios_existentes].contato) == 8)
    {
        i++;
        funcionarios_existentes++;
    };

    fclose(arq);
}

void recuperar_produto()
{
    FILE * arq = fopen("produtos.txt", "r");

    if (arq == NULL)
    {
        printf("Erro ao recuperar informacoes do arquivo produtos.txt.\n");
        system("pause");
        system("cls");
        return;
    }

    while (fscanf(arq, "Nome: %[^\n]\nCodigo: %[^\n]\nPreco de compra: %f\n\n", produto[i].nome, produto[i].codigo, &produto[i].preco) == 3)
    {
        i++;
        produtos_existentes++;
    };

    fclose(arq);
}

void login_funcionario()
{
    char codigo_digitado[7];
    char senha_digitada[25];

    printf("Digite seu codigo de funcionario: ");

    fflush(stdin);
    gets(codigo_digitado);
    system("cls");

    printf("Digite sua senha: ");

    fflush(stdin);
    gets(senha_digitada);

    system("cls");

    for (int i = 0; i < funcionarios_existentes; i++)
    {
        if( strcmp (codigo_digitado, funcionario[i].codigo) == 0 && strcmp (senha_digitada, funcionario[i].senha) == 0) menu_funcionario();

        else 
        {
            printf("Codigo de funcionario ou senha incorreta.\n");
            system("pause");
            system("cls");
        }
    }

}

void login_adm()
{
    char senha_digitada[7];
    printf("Digite a senha de administrador: ");
    
    fflush(stdin);
    gets(senha_digitada);

    if (strcmp (senha_digitada, senha_adm) == 0) menu_adm();

    else
    {
        printf("A senha digitada e a senha de adminstrador nao coincidem.\n");
        system("pause");
        system("cls");
    }
}

void cadastro_funcionario()
{
    printf("Digite o nome do novo funcionario: ");
    
    fflush(stdin);
    gets(funcionario[funcionarios_existentes].nome);

    printf("Digite o codigo do novo funcionario (limite de 6 digitos) : ");
    
    fflush(stdin);
    gets(funcionario[funcionarios_existentes].codigo);

    printf("Digite o cpf do novo funcionario (inclua os sinais) : ");
    
    fflush(stdin);
    gets(funcionario[funcionarios_existentes].cpf);

    printf("Digite a data de nascimento do novo funcionario (inclua as barras) : ");

    scanf("%d/%d/%d", &funcionario[funcionarios_existentes].nascimento.dia, &funcionario[funcionarios_existentes].nascimento.mes, &funcionario[funcionarios_existentes].nascimento.ano);

    printf("Digite a senha do novo funcionario (maximo de 25 caracteres) : ");
    
    fflush(stdin);
    gets(funcionario[funcionarios_existentes].senha);

    printf("Digite o numero de telefone do novo funcionario (apenas os numeros) : ");
    
    fflush(stdin);
    gets(funcionario[funcionarios_existentes].contato);

    system("cls");

    salvar_funcionario();

    funcionarios_existentes++;

}

void salvar_funcionario()
{
    FILE * arq = fopen("funcionarios.txt", "a");

    if (arq == NULL)
    {
        printf("Erro ao salvar novo produto no arquivo produtos.txt.\n");
        system("pause");
        system("cls");
        return;
    }

    fprintf(arq, "Nome: %s\nCodigo: %s\nCPF: %s\nData de nascimento: %d/%d/%d\nSenha: %s\nTelefone: %s\n\n", funcionario[funcionarios_existentes].nome, funcionario[funcionarios_existentes].codigo, funcionario[funcionarios_existentes].nascimento.dia, funcionario[funcionarios_existentes].nascimento.mes, funcionario[funcionarios_existentes].nascimento.ano, funcionario[funcionarios_existentes].senha, funcionario[funcionarios_existentes].contato);

    fclose(arq);

}

void salvar_produto()
{
    FILE * arq = fopen("produtos.txt", "a");

    if (arq == NULL)
    {
        printf("Erro ao salvar novo produto no arquivo produtos.txt.\n");
        system("pause");
        system("cls");
        return;
    }

    fprintf("Nome: %s\nCodigo: %s\nPreco de compra: %f\n\n", produto[produtos_existentes].nome, produto[produtos_existentes].codigo, produto[produtos_existentes].preco);

    fclose(arq);
}