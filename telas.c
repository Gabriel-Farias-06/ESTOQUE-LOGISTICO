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

}

void menu_adm()
{

}

void menu_cadastro_e_exclusao_funcionario()
{

}

void menu_cadastro_e_exclusao_produto()
{
    
}