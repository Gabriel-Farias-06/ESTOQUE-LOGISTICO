#include "lib.h"
void salvar_funcionario(int i) //o numero que vai receber sera o indice do novo funcionario cadastrado
{
    FILE * arq = fopen("funcionario", "a");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }
    fprintf("Nome: %s\nCodigo: %d\nCpf: %s\nData de nascimento: %d/%d/%d\nSenha: %s\nContato: %s\n", funcionario[i].nome, funcionario[i].codigo, funcionario[i].cpf, funcionario[i].nascimento.dia , funcionario[i].nascimento.mes, funcionario[i].nascimento.ano, funcionario[i].senha, funcionario[i].contato);
    fclose(arq);
}