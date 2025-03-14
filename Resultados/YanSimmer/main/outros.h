#ifndef _OUTROS_H
#define _OUTROS_H

#define MAX_TAM_DESC 500
#define MAX_TAM_LOC 100

typedef struct Outros Outros;


Outros *criaOutros(char *local, char*descricao, int dificuldade);

Outros *leOutros();

int getTempoEstimadoOutros(void *dado);

char getTipoOutros();

void desalocaOutros(void *s);

void notificaOutros(void *dado);

#endif