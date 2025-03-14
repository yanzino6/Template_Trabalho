#include "tecnico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tecnico{
    int horasDisp;
    int horasTrab;
    char atuacao[6];
    float salario;
};

Tecnico *criaTecnico(char *atuacao,int horasDisp,float salario)
{
    Tecnico *created=(Tecnico*)malloc(sizeof(Tecnico));
    created->horasDisp=horasDisp;
    created->horasTrab=0;
    created->salario=salario;
    strcpy(created->atuacao,atuacao);
    return created;
}

void leTecnico(Pessoa *p)
{   
    

    char atuacao[6];
    float salario;
    int horasDisp;
    
    scanf("%[^\n]\n", atuacao);
    scanf("%d\n",&horasDisp);
    scanf("%f\n",&salario);

    Tecnico *t = criaTecnico(atuacao, horasDisp, salario);

    
    setDadosPessoa(p, t);
    
    
}

void desalocaTecnico(void *t)
{
    Tecnico *libera= (Tecnico*)t;
    free(libera);
}

char getTipoTecnico()
{
    return 'T';
}

int getHorasDispTecnico(Tecnico *t)
{
    return t->horasDisp;
}

char *getAtuacaoTecnico(Tecnico *t)
{
    return t->atuacao;
}

int getHorasTrabTecnico(Tecnico *t)
{
    return t->horasTrab;
}

void atualizaHorasTecnico(Tecnico *t,int horas)
{
    t->horasDisp-=horas;
    t->horasTrab+=horas;
}

//- Area de Atuacao: GERAL 
//- Salario: 2000.00 
//- Disponibilidade: 2h 
//- Tempo Trabalhado: 5h 

void imprimeTecnico(void *t)
{
    Tecnico *imprime= (Tecnico*)t;
    printf("- Area de Atuacao: %s\n",imprime->atuacao);
    printf("- Salario: %.2f\n",imprime->salario);
    printf("- Disponibilidade: %d\n",imprime->horasDisp);
    printf("- Tempo Trabalhado: %d\n",imprime->horasTrab);
}