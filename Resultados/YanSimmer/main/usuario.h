#ifndef _USUARIO_H
#define _USUARIO_H
#include "pessoa.h"
#define MAX_TAM_SETOR 10

typedef struct Usuario Usuario;

Usuario *criaUsuario(char *setor);

void leUsuario(Pessoa *p);

void desalocaUsuario(void *t);

char getTipoUsuario();

char *getSetorUsuario(Usuario *t);

int adicionaTick(Usuario* t);

void imprimeUsuario(void *t);

#endif