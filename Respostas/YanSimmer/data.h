#ifndef _DATA_H
#define _DATA_H

typedef struct Data Data;

Data *criaData(int dia, int mes, int ano);

Data *leData();

int calculaDiffAnos(Data *inicio);

void imprimeData(Data *d);

void desalocaData(Data *d);

#endif