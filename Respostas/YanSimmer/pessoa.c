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
    func_ptr_leitura leituraPessoa;
};

Pessoa *criaPessoa(char *nome, char *cpf, char *genero, char *telefone)
{
    Pessoa *created = (Pessoa*)malloc(sizeof(Pessoa));
    strcpy(created->cpf,cpf);
    strcpy(created->genero,genero);
    strcpy(created->nome,nome);
    strcpy(created->tel,telefone);
    return created;
    
}


 //- Nome: JAYCE BARBOSA 
 //- CPF: 854.632.894-20 
 //- Data de Nascimento: 22/2/1990 
 //- Telefone: (37)9938-3382 
 //- Genero: MASCULINO

void imprimePessoa(Pessoa *p)
{   
    printf("--------------------\n");
    printf("- Nome: %s\n",p->nome);
    printf("- CPF: %s\n",p->cpf);
    printf("- Data de Nascimento: ");
    imprimeData(p->dataNasc);
    printf("- Telefone: %s\n",p->tel);
    printf("- Genero: %s\n",p->genero);
    p->printaPessoa(p);
}

//TAHM KENCH
//123.932.250-46
//01/09/1955
//(34)96373-7004
//OUTROS

Pessoa *lePessoa()
{   char nome[MAX_TAM_NOMEPESSOA];
    char cpf[MAX_TAM_CPF_E_TEL];
    char tel[MAX_TAM_CPF_E_TEL];
    Data *dataNasc;
    char genero[MAX_TAM_GEN];
    
    scanf("%[ˆ\n]\n",nome);
    scanf("%[ˆ\n]\n",cpf);
    dataNasc=leData();
    scanf("%[ˆ\n]\n",tel);
    scanf("%[ˆ\n]\n",genero);
    
    Pessoa *p=criaPessoa(nome,cpf,genero,tel);
    p->dataNasc=dataNasc;
    return p;
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

void setaFuncsPessoa(Pessoa *p,func_ptr_desaloca desaloca,func_ptr_imprime imprime,func_ptr_tipo tipo)
{
    p->desalocaPessoa=desaloca;
    p->printaPessoa=imprime;
    p->tipoPessoa=tipo;
}

void leDadosPessoa(Pessoa *p)
{
    p->leituraPessoa();
}