#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    char nome[MAX_TAM_NOMEPESSOA];
    char cpf[MAX_TAM_CPF_E_TEL];
    char tel[MAX_TAM_CPF_E_TEL];
    Data *dataNasc;
    char genero[MAX_TAM_GEN];
    void *data;
    func_ptr_imprime printaPessoa;
    func_ptr_desaloca desalocaPessoa;
    func_ptr_tipo tipoPessoa;
};

Pessoa *criaPessoa(char *nome, char *cpf, char *genero, Data *datanasc, char *telefone)
{

}


 //- Nome: JAYCE BARBOSA 
 //- CPF: 854.632.894-20 
 //- Data de Nascimento: 22/2/1990 
 //- Telefone: (37)9938-3382 
 //- Genero: MASCULINO

void imprimePessoa(Pessoa *p)
{
    printf("- Nome: %s\n",p->nome);
    printf("- CPF: %s\n",p->cpf);
    printf("- Data de Nascimento: ");
    imprimeData(p->dataNasc);
    printf("- Telefone: %s\n",p->tel);
    printf("- Genero: %s\n",p->genero);
    p->printaPessoa(p);
}

void desalocaPessoa(Pessoa *p)
{
    desalocaData(p->dataNasc);
    p->desalocaPessoa(p);
}

char *getCPFPessoa(Pessoa *p)
{
    return p->cpf;
}

char *getNomePessoa(Pessoa *p)
{
    return p->nome;
}

char *getGeneroPessoa(Pessoa *p)
{
    return p->genero;
}

int getidadepessoa(Pessoa *p)
{
    return calculaDiffAnos(p->dataNasc);
}

char getTipoPessoa(Pessoa *p)
{
    return p->tipoPessoa();
}