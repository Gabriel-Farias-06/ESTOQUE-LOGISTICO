#include "procedure.h"

void menu_login()
{
    recuperar_senha_adm();
    printf("%s", senha_adm);
    recuperar_funcionario();
    recuperar_produto();
    recuperar_entrada_produto();
    recuperar_venda_produto();

    int opcaoDigitada;

    while(opcaoDigitada != 3)
    {
        printf("        Bem vindo a central de estoque logistico\n\n"
        "Qual a forma de login desejada?\n\n"
        "1- Logar como administrador\n"
        "2- Logar como funcionario\n"
        "3- Encerrar o programa\n"
        "Digite sua opcao: ");
        scanf("%d", &opcaoDigitada);
        switch (opcaoDigitada)
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
    int opcaoDigitada;

    while(opcaoDigitada != 6)
    {
        printf ("1 - Declarar entrada do produto\n"
        "2 - Cadastrar / Excluir produto\n"
        "3 - Declarar venda do produto\n"
        "4 - Consultar produto\n"
        "5 - Extrato\n"
        "6 - Voltar\n"
        "Digite sua opcao: ");
        scanf ("%d", &opcaoDigitada);
        switch (opcaoDigitada)
        {
        case 1:
            entrada_produto();
            break;
        case 2:
            salvar_entrada_produto();
            break;
        case 3:
            venda_produto();
            break;
        case 4:
            consulta_produto();
            break;
        case 5:
            extrato();
        case 6:
            break;
        default:
            printf("Digite uma opcao valida!\n");
            break;
        }
    }
}

void menu_adm()
{
    int opcaoDigitada;

    while (opcaoDigitada != 7)
    {
        printf ("1 - Cadastrar / Excluir funcionario\n"
        "2 - Cadastrar / Excluir produto\n"
        "3 - Declarar venda do produto\n"
        "4 - Declarar entrada do produto\n"
        "5 - Consultar informacoes do produto\n"
        "6 - Extrato\n"
        "7 - Voltar\n"
        "Digite sua opcao: ");
        scanf ("%d", &opcaoDigitada);

        switch (opcaoDigitada)
        {
        case 1:
            menu_cadastro_e_exclusao_funcionario();
            break;
        case 2:
            menu_cadastro_e_exclusao_produto();
            break;
        case 3:
            venda_produto();
            break;
        case 4:
            entrada_produto();
            break;
        case 5:
            consulta_produto();
            break;
        case 6:
            extrato();
            break;
        case 7:
            break;
        default:
            printf("Digite uma opcao valida!\n");
            break;
        }
    }
}

void menu_cadastro_e_exclusao_funcionario()
{
    int opcaoDigitada;
    while (opcaoDigitada != 3)
    {
        printf ("1 - Cadastrar funcionario\n"
        "2 - Excluir funcionario\n"
        "3 - Voltar"
        "Digite sua opcao: ");
        scanf("%d", &opcaoDigitada);

        switch (opcaoDigitada)
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
    }
}

void menu_cadastro_e_exclusao_produto()
{
    int opcaoDigitada;
    while (opcaoDigitada != 3)
    {
        printf ("1 - Cadastrar produto\n"
        "2 - Excluir produto\n"
        "3 - Voltar\n"
        "Digite sua opcao desejada: ");
        scanf ("%d", &opcaoDigitada);

        switch (opcaoDigitada)
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
    }
}
