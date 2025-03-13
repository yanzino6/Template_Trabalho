#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
    int dia;
    int mes;
    int ano;
};

Data *criaData(int dia, int mes, int ano)
{
    Data *created=(Data*)malloc(sizeof(Data));
    created->dia=dia;
    created->ano=ano;
    created->mes=mes;
    return created;
}

Data *leData()
{   int dia,mes,ano;
    scanf("%d/%d/%d\n",&dia,&mes,&ano);
    Data *newData=criaData(dia,mes,ano);
    return newData;
}

int calculaDiffAnos(Data *inicio)
{
    if (2>inicio->mes)
    {
        return 2025-inicio->ano;
    }

    else if (2<inicio->mes)
    {
        return 2025-inicio->ano-1;
    }
    
    else
    {
        if (18>=inicio->dia)
    {
        return 2025-inicio->ano;
    }
    else
    {
        return 2025-inicio->ano-1;
    }
    
    }
    
    
}

void imprimeData(Data *d)
{
    printf("%d/%d/%d\n",d->dia,d->mes,d->ano);
}

void desalocaData(Data *d)
{
    free(d);
}