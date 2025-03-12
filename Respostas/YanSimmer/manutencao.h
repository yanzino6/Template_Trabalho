#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H
#define MAX_TAM_NOME 100
#define MAX_TAM_LOC 100
#define MAX_ESTADO 8
#define MAX_SETORUSER 11

typedef struct Manutencao Manutencao;

Manutencao *criaManutencao(char *local, char*estado, char *nome,char *setorSol);

Manutencao *leManutencao();

int getTempoEstimadoManutencao(void *dado);

char getTipoManutencao();

void desalocaManutencao(void *s);

void notificaManutencao(void *dado);

#endif