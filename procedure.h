#include "lib.h"

void salvar_venda_produto(){}//FAZER DEPOIS

void venda_produto()//FAZER PRIMEIRO
{
    /*FILE * arq = fopen("venda_produto.txt", "a");
    if (arq == NULL)
    {
        printf("Erro ao registrar informacoes de venda no arquivo venda_produto.txt.\n");
        system("pause");
        system("cls");
        return;
    }
    printf ("Digite o nome do produto:\n");
    fflush(stdin);
    gets(Produto_venda.nome);
    printf ("Digite a quantidade vendida:\n");
    fflush(stdin);
    gets(Produto_venda.quantidade);
    */
}

void recuperar_venda_produto(){}//FAZER POR ULTIMO

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

    fscanf(arq, "Ola admnistrador, digite sua senha a seguir (maximo de 6 digitos) : %[^\n]", senha_adm);

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
        printf("Erro ao salvar novo produto no arquivo funcionarios.txt.\n");
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

void recuperar_entrada_produto()
{
    FILE * arq = fopen("produtos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao recuperar irformacoes no arquivo produtos.txt. \n");
        system("pause");
        system("cls");
        return;
    }
    while (fscanf(arq,"Nome: %[^\n]\nCodigo: %[^\n]\nPreco de compra: %f\n\n", produto_entrada[i].nome, produto_entrada[i].codigo, &produto_entrada[i].preco) == 3);
    {
        i++;
        produtos_existentes++;
    }
    fclose(arq);
}

void entrada_produto()
{
    FILE * arq = fopen("produtos.txt", "a");

    printf("Digite o nome do produto:");

    fflush(stdin);
    gets(produto_entrada[produtos_existentes].nome);

    printf("Digite a quantidade de produtos:");

    scanf("%i", &produto_entrada[produtos_existentes].quantidade);

    printf("Digite o preco de compra:"):

    scanf("%f", &produto_entrada[produtos_existentes].preco_de_compra);

    system("cls");

    salvar_entrada_produto();
    
    produtos_existentes++;
}

void salvar_entrada_produto()
{
    FILE * arq = fopen("produtos.txt", "a");
    if(arq == NULL)
    {
        printf("Erro ao salvar novo produto no produtos.txt.\n");
        system("pause");
        system("cls");
        return;
    }
    
    fprintf("Nome: %s\nQuantidade: %i\nPreco do produto:%f.", produto_entrada[produtos_existentes].nome, produto_entrada[produtos_existentes].quantidade, produto_entrada[produtos_existentes].preco_de_compra);

    fclose(arq);
}

void exclusao_funcionario()
{
    boolean ver = 1;
    int funcionarios_existentes;
    if(login_adm()) 
    {
        printf("Digite o codigo do funcionario que voce quer excluir: ");
        scanf("%d", &); // tentado descobrir oque é equivalente a contadig nesse codigo
        for(int i = 0; i <= LIM; i++)
        {
            if(contaDig == funcionarios_existentes[i].codigo)
            {
                funcionarios_existentes--;
                for(int j = i; j < LIM; j++) salvar_funcionario[j] = salvar_funcionario[j + 1];
                salvar_funcionario(funcionarios_existentes);
                printf("             Funcionario deletado com sucesso\n");
                ver = 0;
                break;
            }
            
        }
    if(ver) printf("             Funcionario nao registrada\n");
    system("pause");
    system("cls");
    }
}