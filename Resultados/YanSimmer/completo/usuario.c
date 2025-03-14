#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Usuario{
    char setor[MAX_TAM_SETOR];
    int ticksSol;
 };

Usuario *criaUsuario(char *setor)
{
    Usuario *created = (Usuario*)malloc(sizeof(Usuario));
    strcpy(created->setor,setor);
    created->ticksSol=0;
    return created;
}

void leUsuario(Pessoa *p)
{
    char atuacao[MAX_TAM_SETOR];
    
    scanf("%[^\n]\n", atuacao);

    Usuario *u = criaUsuario(atuacao);

    
    setDadosPessoa(p, u);
}

void desalocaUsuario(void *u)
{
    free((Usuario*)u);
}

char getTipoUsuario()
{
    return 'U';
}

char *getSetorUsuario(Usuario *u)
{
    return u->setor;
}


void imprimeUsuario(void *u)
{
    Usuario *user = (Usuario*)u;
    printf("- Setor: %s\n",user->setor);
    printf("- Tickets solicitados: %d\n",user->ticksSol);

}

int adicionaTick(Usuario* t)
{
    t->ticksSol++;
}