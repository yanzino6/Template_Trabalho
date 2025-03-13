#ifndef _PESSOA_H
#define _PESSOA_H

#define MAX_TAM_NOMEPESSOA 100
#define MAX_TAM_CPF_E_TEL 15
#define MAX_TAM_GEN 9
#include "data.h"

typedef struct Pessoa Pessoa;


typedef void (*func_ptr_desaloca)(void *dado);
typedef void (*func_ptr_imprime)(void *dado);
typedef char (*func_ptr_tipo)();
typedef void (*func_ptr_leitura)();

Pessoa *criaPessoa(char *nome, char *cpf, char *genero, char *telefone);

Pessoa *lePessoa();

void leDadosPessoa(Pessoa *p);

void imprimePessoa(Pessoa *p);

void desalocaPessoa(Pessoa *p);

char *getCPFPessoa(Pessoa *p);

char *getNomePessoa(Pessoa *p);

char *getGeneroPessoa(Pessoa *p);

int getidadepessoa(Pessoa *p);

char getTipoPessoa(Pessoa *p);

void setaFuncsPessoa(Pessoa *p,func_ptr_desaloca desaloca,func_ptr_imprime imprime,func_ptr_tipo tipo);

#endif