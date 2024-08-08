#include <stdio.h>
#include <stdlib.h>

struct data
{
    int dia;
    int mes;
    int ano;
};

typedef struct Funcionario 
{
    char nome[100];
    char codigo[7];
    char cpf[15];
    data nascimento;
    char senha[25];
    char contato[12];
} funcionario[300];

typedef struct Produto
{
    char nome[100];
    char codigo[7];
    float preco;
} produto[300];

char senha_adm[6]; // senha que ficara num arquivo separado para quando entrarem pela primeira vez nao precisarem de cadastro

int produtos_existentes = 0; //tem a quantidade de produtos já cadastrados, essa quantidade é calculada no recuperar_entrada_produto() e aumentada/diminuida no cadastrar/excluir produto

int funcionarios_existentes = 0; //tem a quantidade de funcionarios já cadastrados, essa quantidade é calculada no recuperar_funcionario() e aumentada/diminuida no cadastrar/excluir funcionario

void recuperar_senha_adm(); // vai procurar a senha de adm no arquivo dela
void recuperar_funcionario(); // vai procurar os funcionarios no arquivo que eles estao cadastrados
void recuperar_produto(); // vai procurar os produtos no arquivo que eles estao cadastrados
void recuperar_entrada_produto(); // vai procurar as entradas de produtos no arquivo que eles estao cadastrados *feito
void recuperar_venda_produto(); // vai procurar as vendas de produtos no arquivo que eles estao cadastrados
void menu_login(); // menu inicial onde voce pode entrar pelo seus dados de funcionario ou senha de adm
void login_funcionario(); // login se quiser entrar como funcionario
void login_adm(); // login se quiser entrar como adm
void menu_funcionario(); // menu se entrar como funcionario (nao pode excluir/cadastrar funcionarios)
void menu_adm(); // menu se entrar como adm (pode excluir/cadastrar funcionarios) 
void menu_cadastro_e_exclusao_funcionario(); // menu que so aparece para adms
void cadastro_funcionario(); // autoexplicativo *feito
void salvar_funcionario(); // funcao para cadastrar os novos funcionarios no arquivo
void exclusao_funcionario(); // autoexplicativo
void menu_cadastro_e_exclusao_produto(); // autoexplicativo
void cadastro_produto(); // autoexplicativo
void salvar_produto(); // funcao para cadastrar os novos produtos no arquivo *feito
void exclusao_produto(); // autoexplicativo
void entrada_produto(); // autoexplicativo
void salvar_entrada_produto(); // funcao para cadastrar a entrada de produtos no arquivo
void venda_produto(); // autoexplicativo
void salvar_venda_produto(); // funcao para cadastrar a venda de produtos no arquivo
void extrato(); // autoexplicativo
