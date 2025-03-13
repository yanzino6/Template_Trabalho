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
    func_ptr_desaloca desalocaP;
    func_ptr_tipo tipoPessoa;
    
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
    p->printaPessoa(p->data);
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
    
    scanf("%[^\n]\n", nome);  
    scanf("%[^\n]\n", cpf);   
    dataNasc = leData();      
    scanf("%[^\n]\n", tel);   
    scanf("%[^\n]\n", genero); 
    
    Pessoa *p=criaPessoa(nome,cpf,genero,tel);
    p->dataNasc=dataNasc;
    return p;
}

void desalocaPessoa(Pessoa *p)
{
    desalocaData(p->dataNasc);
    p->desalocaP(p->data);
    free(p);
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
    p->desalocaP=desaloca;
    p->printaPessoa=imprime;
    p->tipoPessoa=tipo;
}

void *getDadosPessoa(Pessoa *p)
{
    return p->data;
}

void setDadosPessoa(Pessoa *p, void *dados) {
    if (p != NULL) {
        p->data = dados; // Atribui os dados específicos ao campo interno
    }
}