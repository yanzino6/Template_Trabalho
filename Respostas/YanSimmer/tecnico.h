#ifndef _TECNICO_H
#define _TECNICO_H
#include "pessoa.h"
typedef struct Tecnico Tecnico;

Tecnico *criaTecnico(char *atuacao,int horasDisp,float salario);

void leTecnico(Pessoa *p);

void desalocaTecnico(void *t);

char getTipoTecnico(void *t);

int getHorasDispTecnico(Tecnico *t);

int getHorasDispTecnico(Tecnico *t);

char *getAtuacaoTecnico(Tecnico *t);

void atualizaHorasTecnico(Tecnico *t,int horas);

void imprimeTecnico(void *t);



#endif