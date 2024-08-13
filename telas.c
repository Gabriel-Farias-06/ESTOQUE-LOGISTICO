#include "procedure.h"

void menu_login()
{
    int forma_login;

    while(forma_login != 3)
    {
        printf("        Bem vindo a central de estoque logistico\n\nQual a forma de login desejada?\n\n1- Logar como administrador\n2- Logar como funcionario\n3- Encerrar o programa\nDigite sua opcao: ");
        scanf("%d", &forma_login);
        switch (forma_login)
        {
            case 1:
                login_adm();
                break;
            case 2:
                login_funcionario();
                break;
            case 3:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
        }
        system("pause");
        system("cls");
    }
}

void menu_funcionario()
{

    boolean ver = 0;
    int forma_funcionario = 0, formaDeLogin; // opcao do Menu Funcionario 
    printf("            Bem-vindo ao menu do funcionario\n Escolha a forma de login:\n\n");
    printf("1- Logar pela senha de administrador\n2- Logar como funcionario\nDigite sua opcao: ");
    scanf("%d", &formaDeLogin);
    if (formaDeLogin == 1) if (login_adm()) ver = 1; else return;
    else if (formaDeLogin == 2)
    {
        printf("Digite seu codigo de funcionario: ");
        scanf("%d", &codigoFuncionario);
        printf("Digite sua senha de funcionario: ");
        scanf("%d", &senhafuncionario);
        system("cls");
        for(int i = 0; i < funcionarios_existentes; i++) if (codigoFuncionario == funcionario[i].codigo && senhafuncionario == funcionario[i].senha)
        {
            ver = 1;
            printf("Codigo e senha corretos\n");
        }
        else printf("Codigo de funcionario e/ou senha incorreto(s)\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("Digite uma opcao valida\n");
        system("pause");
        system("cls");
        return;

}
}

void menu_adm()
{
    int forma_adm;

    while(forma_adm != 3)
    {
        printf("        Bem vindo ao Menu do Adminstrador\n\nQual acao desejada?\n\n1- Cadastrar novo funcionario\n2- Exluir funcionario existente\n3- Encerrar o programa\nDigite sua opcao: ");
        scanf("%d", &forma_adm);
        switch (forma_adm)
        {
            case 1:
                cadastro_funcionario();
                break;
            case 2:
                exclusao_funcionario();
                break;
            case 3:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
        }
        system("pause");
        system("cls");
    }

}

void menu_cadastro_e_exclusao_funcionario()
{
// BIXO ISSO AQUI NAO FAZ SENTINDO 
}

void menu_cadastro_e_exclusao_produto()
{
    int forma_produto;

    while(forma_produto != 3)
    {
        printf("        Bem vindo ao Menu Cadastro e Exclusao de produtos \n\nQual acao desejada?\n\n1- Cadastrar novo produto\n2- Exluir produto existente\n3- Encerrar o programa\nDigite sua opcao: ");
        scanf("%d", &forma_produto);
        switch (forma_produto)
        {
            case 1:
                cadastro_produto();
                break;
            case 2:
                exclusao_produto();
                break;
            case 3:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
        }
        system("pause");
        system("cls");
    }
}