#include "lib.h"

void recuperar_senha_adm()
{
    FILE * arq = fopen("senha_adm.txt", "r");

    fscanf(arq, "%[^\n]", senha_adm);


    fclose(arq);

}

void recuperar_funcionario()
{
    FILE * arq = fopen("funcionarios.txt", "r");

    while (fscanf(arq, "Nome: %[^\n]\nCodigo: %[^\n]\nCPF: %[^\n]\nData de nascimento: %d/%d/%d\nSenha: %[^\n]\nTelefone: %[^\n]\n\n", funcionario[funcionarios_existentes].nome, funcionario[funcionarios_existentes].codigo, funcionario[funcionarios_existentes].cpf, &funcionario[funcionarios_existentes].nascimento.dia, &funcionario[funcionarios_existentes].nascimento.mes, &funcionario[funcionarios_existentes].nascimento.ano, funcionario[funcionarios_existentes].senha, funcionario[funcionarios_existentes].contato) == 8) funcionarios_existentes++;

    fclose(arq);
}

void recuperar_produto()
{
    FILE * arq = fopen("produtos.txt", "r");

    while (fscanf(arq, "Nome: %[^\n]\nCodigo: %[^\n]\nPreco de compra: %f\n\n", produto[produtos_existentes].nome, produto[produtos_existentes].codigo, &produto[produtos_existentes].preco) == 3) produtos_existentes++;

    fclose(arq);
}

void recuperar_entrada_produto()
{
    FILE * arq = fopen("entrada_produto.txt", "r");

    while (fscanf(arq,"Nome: %[^\n]\nQuantidade: %d\nPreco de compra: %f\n\n", produto_entrada[produtos_comprados].nome, &produto_entrada[produtos_comprados].quantidade, &produto_entrada[produtos_comprados].preco_de_compra) == 3) produtos_comprados++;

    fclose(arq);
}

void recuperar_venda_produto()
{
    FILE *arq = fopen("venda_produto.txt", "r");

    while (3 == fscanf(arq, 
    "Nome do produto: %100[^\n]\n"
    "Quantidade de produtos vendidos: %d\n"
    "Preco esperado de venda: %f\n\n",
    produto[produtos_existentes].nome, &produto_venda[produtos_existentes].quantidade, &produto[produtos_existentes].preco)) produtos_existentes++;
    
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

    fprintf(arq, "Nome: %s\nCodigo: %s\nCPF: %s\nData de nascimento: %d/%d/%d\nSenha: %s\nTelefone: %s\n\n", funcionario[funcionarios_existentes].nome, funcionario[funcionarios_existentes].codigo, funcionario[funcionarios_existentes].cpf, funcionario[funcionarios_existentes].nascimento.dia, funcionario[funcionarios_existentes].nascimento.mes, funcionario[funcionarios_existentes].nascimento.ano, funcionario[funcionarios_existentes].senha, funcionario[funcionarios_existentes].contato);

    fclose(arq);

}

void exclusao_funcionario()
{
    char codigoDig[7];
    printf("Digite o codigo do funcionario que voce quer excluir: ");
    
    fflush(stdin);
    gets(codigoDig);

    for(int i = 0; i < funcionarios_existentes; i++)
    {
        if(strcmp(codigoDig, funcionario[i].codigo) == 0)
        {
            funcionarios_existentes--;

            for(int j = i; j < funcionarios_existentes; j++) funcionario[j] = funcionario[j + 1];

            FILE *arq = fopen ("funcionario.txt", "w");
            if (arq == NULL)
            {
                printf("Erro ao abrir o arquivo produtos.txt. \n");
                system("pause");
                system("cls");
                return;
            }

            for (int i = 0; i < funcionarios_existentes; i++) fprintf(arq, "Nome: %s\nCodigo: %s\nCPF: %s\nData de nascimento: %d/%d/%d\nSenha: %s\nTelefone: %s\n\n", funcionario[funcionarios_existentes].nome, funcionario[funcionarios_existentes].codigo, funcionario[funcionarios_existentes].cpf, funcionario[funcionarios_existentes].nascimento.dia, funcionario[funcionarios_existentes].nascimento.mes, funcionario[funcionarios_existentes].nascimento.ano, funcionario[funcionarios_existentes].senha, funcionario[funcionarios_existentes].contato);

            fclose(arq);

            printf("             Funcionario deletado com sucesso\n");
            return;
        }
        
    }
    printf("             Funcionario nao registrada\n");
    system("pause");
    system("cls");
}

void cadastro_produto()
{
    printf("Digite o nome do novo produto: ");

    fflush(stdin);
    gets (produto[produtos_existentes].nome);

    printf("Digite o codigo de identificacao do novo produto (6 digitos): ");

    fflush(stdin);
    gets (produto[produtos_existentes].codigo);

    printf("Digite o preco de venda esperado do novo produto: ");

    scanf("%f", &produto[produtos_existentes].preco);

    salvar_produto();
    produtos_existentes++;
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

    fprintf(arq, "Nome: %s\nCodigo: %s\nPreco de compra: %f\n\n", produto[produtos_existentes].nome, produto[produtos_existentes].codigo, produto[produtos_existentes].preco);

    fclose(arq);
}

void exclusao_produto()
{
    char codigo_digitado[7];
    printf("Digite o codigo do produto a ser excluido: ");

    fflush(stdin);
    gets(codigo_digitado);

    for (int i = 0; i < produtos_existentes; i++)
    {
        if (strcmp(codigo_digitado, produto[i].codigo) == 0)
        {
            produtos_existentes--;

            for (int j = i; j < produtos_existentes; j++) produto[j] = produto[j + 1];

            FILE *arq = fopen ("produtos.txt", "w");
            if (arq == NULL)
            {
                printf("Erro ao abrir o arquivo produtos.txt. \n");
                system("pause");
                system("cls");
                return;
            }

            for (int i = 0; i < produtos_existentes; i++) fprintf(arq, "Nome: %s\nCodigo: %s\nPreco de compra: %f\n\n", produto[produtos_existentes].nome, produto[produtos_existentes].codigo, produto_entrada[produtos_existentes].preco_de_compra);

            fclose(arq);

            printf("            Produto deletado com sucesso\n");
            return;
        }
    }
    printf ("           Codigo de produto nao registrado\n");
    system("pause");
    system("cls");
}


void entrada_produto()
{
    printf("Digite o nome do produto:");

    fflush(stdin);
    gets(produto_entrada[produtos_comprados].nome);

    printf("Digite a quantidade de produtos:");

    scanf("%i", &produto_entrada[produtos_comprados].quantidade);

    printf("Digite o preco de compra:");

    scanf("%f", &produto_entrada[produtos_comprados].preco_de_compra);

    system("cls");

    salvar_entrada_produto();
    
    produtos_comprados++;
}

void salvar_entrada_produto()
{
    FILE * arq = fopen("entrada_produto.txt", "a");
    if(arq == NULL)
    {
        printf("Erro ao salvar novo produto no produtos.txt.\n");
        system("pause");
        system("cls");
        return;
    }
    
    fprintf(arq, "Nome: %s\nQuantidade: %i\nPreco do produto:%f.", produto_entrada[produtos_comprados].nome, produto_entrada[produtos_comprados].quantidade, produto_entrada[produtos_comprados].preco_de_compra);

    fclose(arq);
}

void venda_produto()
{
    printf ("Digite o nome do produto:\n");
    
    fflush(stdin);
    gets(produto_venda[produtos_vendidos].nome);

    printf ("Digite a quantidade vendida:\n");

    scanf("%d", &produto_venda[produtos_vendidos].quantidade);

    float total_produtos_vendidos = 0;
    float total_produtos_comprados = 0;

    for (int i = 0; i < produtos_vendidos; i++)
    {
        if(strcmp(produto_venda[produtos_vendidos].nome, produto_entrada[i].nome) == 0)
        {
            total_produtos_comprados += produto_entrada[i].quantidade;
        }
    }

    for (int i = 0; i < produtos_comprados; i++)
    {
        if(strcmp(produto_venda[produtos_vendidos].nome, produto_venda[i].nome) == 0)
        {
            total_produtos_vendidos += produto_venda[i].quantidade;
        }
    }

    if((total_produtos_comprados - total_produtos_vendidos) < produto_venda[produtos_existentes].quantidade)
    {
        printf("Quantidade maior do que a descrita no estoque, atualmente no estoque ha %.0f unidades.\n", total_produtos_comprados - total_produtos_vendidos);

        system("pause");
        system("cls");

        return;
    }

    char opcao;

    printf("O produto foi vendido pelo preco esperado? (s/n)\n\nDigite sua opcao: ");

    scanf(" %c", &opcao);

    if (opcao == 's') produto_venda[produtos_vendidos].preco_vendido = produto[produtos_existentes].preco;

    else if (opcao == 'n')
    {
        printf("Digite o preco que o produto foi vendido: ");

        scanf("%f", &produto_venda[produtos_vendidos].preco_vendido);
    }
    else
    {
        printf("Digite uma opcao valida!\n");
        system("pause");
        system("cls");
        return;
    }
    salvar_venda_produto();
    printf("            Registro da venda feito com sucesso\n");
    system("pause");
    system("cls");
}

void salvar_venda_produto()
{
    FILE * arq = fopen("venda_produto.txt", "a");
    if (arq == NULL)
    {
        printf("Erro ao registrar informacoes de venda no arquivo venda_produto.txt.\n");
        system("pause");
        system("cls");
        return;
    }

    fprintf(arq, "Nome do produto: %s\nQuantidade de produtos vendidos: %d\nPreco esperado de venda: %f\n\n", produto[produtos_existentes].nome, produto_venda[produtos_existentes].quantidade, produto[produtos_existentes].preco);

    fclose(arq);
}

void consulta_produto()
{
    boolean ver = 0;
    float total_compra = 0;
    float total_venda = 0;
    int total_produtos_vendidos =  0;
    int total_produtos_comprados = 0;
    char produtoDigitado[100];
    printf("Digite o nome do produto para consulta-lo: ");
    
    fflush(stdin);
    gets(produtoDigitado);

    for (int i = 0; i < produtos_comprados; i++)
    {
        if(strcmp(produtoDigitado, produto_entrada[i].nome) == 0)
        {
            total_produtos_comprados += produto_entrada[i].quantidade;
            total_compra += produto_entrada[i].preco_de_compra * produto_entrada[i].quantidade;
            ver = 1;
        }
    }
    for (int i = 0; i < produtos_vendidos; i++)
    {
        if(strcmp(produtoDigitado, produto_venda[i].nome) == 0)
        {
            total_produtos_vendidos += produto_venda[i].quantidade;
            total_venda += produto_venda[i].preco_vendido * produto_venda[i].quantidade;
            ver = 1;
        }
    }
    if(ver) printf("            Informacoes do produto %s\n\n\n1- Total de produtos comprados: %d.\n2- Total de produtos vendidos: %d.\n3- Total de valor gasto: %.2f.\n4- Total de valor ganho: %.2f.\n5- Total de lucro: %.2f.\n", produtoDigitado, total_produtos_comprados, total_produtos_vendidos, total_compra, total_venda, total_compra - total_venda);
    else printf("Este produto ou nao foi cadastrado ou nao foi efetuada nenhuma venda/compra do mesmo.\n");
    system("pause");
    system("cls");
}

void extrato()
{
    int opcao;
    printf("            Extrato\n\n1- Ver extrato geral\n2- Ver extrato de um produto especifico\n\nDigite sua opcao: ");
    scanf("%d", &opcao);
    if(opcao == 1)
    {
        for(int i = 0; i < produtos_vendidos; i++) printf("Nome do produto: %s. Quantidade vendida: %d. Preco vendido: %.2f.\n", produto_venda[i].nome, produto_venda[i].quantidade, produto_venda[i].preco_vendido);

        for(int i = 0; i < produtos_comprados; i++) printf("Nome do produto: %s. Quantidade comprada: %d. Preco de compra: %.2f.\n", produto_entrada[i].nome, produto_entrada[i].quantidade, produto_entrada[i].preco_de_compra);
    }
    else if(opcao == 2)
    {
        char produtoDigitado[100];
        printf("Digite o nome do produto para ver seu extrato: ");
        
        fflush(stdin);
        gets(produtoDigitado);

        for(int i = 0; i < produtos_comprados; i++)
        {
            if(strcmp(produtoDigitado, produto_entrada[i].nome) == 0) printf("Quantidade comprada: %d. Preco vendido: %.2f.\n", produto_entrada[i].quantidade, produto_entrada[i].preco_de_compra);
        }

        for(int i = 0; i < produtos_vendidos; i++)
        {
            if(strcmp(produtoDigitado, produto_venda[i].nome) == 0) printf("Quantidade vendida: %d. Preco vendido: %.2f.\n", produto_venda[i].quantidade, produto_venda[i].preco_vendido);
        }
    }
    system("pause");
    system("cls");
}
