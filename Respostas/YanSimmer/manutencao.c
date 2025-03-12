#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Manutencao{
    char nome[MAX_TAM_NOME];
    char local[MAX_TAM_LOC];
    char estado[MAX_ESTADO];
    char setorSol[MAX_SETORUSER];
};

Manutencao *criaManutencao(char *local, char*estado, char *nome,char *setorSol)
{
    Manutencao *created= (Manutencao*)malloc(sizeof(Manutencao));
    strcpy(created->nome,nome);
    strcpy(created->local,local);
    strcpy(created->estado,estado);
    strcpy(created->setorSol,setorSol);
    return created;
}

Manutencao *leManutencao()
{
    char nome[MAX_TAM_NOME];
    char local[MAX_TAM_LOC];
    char estado[MAX_ESTADO];
    
    scanf("%[^\n]\n",nome);
    scanf("%[^\n]\n",estado);
    scanf("%[^\n]\n",local);
    
    Manutencao *read=criaManutencao(local,estado,nome,"FINANCEIRO");
    return read;
}

int getTempoEstimadoManutencao(void *dado)
{   Manutencao *m=(Manutencao*)dado;
    
    int fatorSetor;
    int fatorEstado;
    if (strcmp(m->setorSol,"MARKETING")==0||strcmp(m->setorSol,"VENDAS")==0||strcmp(m->setorSol,"P&D")==0)
    {
        fatorSetor=1;
    }
    else if (strcmp(m->setorSol,"FINANCEIRO")==0)
    {
        fatorSetor=3;
    }
    else
    {
        fatorSetor=2;
    }

    

    if (strcmp(m->estado,"RUIM")==0)
    {
        fatorEstado=3;
    }
    else if (strcmp(m->estado,"REGULAR")==0)
    {
        fatorEstado=2;
    }
    else
    {
        fatorEstado=1;
    }
    return fatorEstado*fatorSetor;
}

char getTipoManutencao()
{
    return 'M';
}

void desalocaManutencao(void *s)
{
    Manutencao *m=(Manutencao*)s;
    free(m);
}
/* 
- Nome do item: AR CONDICIONADO
- Estado de conservacao: RUIM
- Local: SALA 15 BLOCO A
- Tempo estimado: 3h
 */
void notificaManutencao(void *dado)
{
    Manutencao *m=(Manutencao*)dado;
    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n",m->nome);
    printf("- Estado de conservacao: %s\n",m->estado);
    printf("- Local: %s\n",m->local);
    printf("- Tempo Estimado: %dh\n",getTempoEstimadoManutencao(m));
}