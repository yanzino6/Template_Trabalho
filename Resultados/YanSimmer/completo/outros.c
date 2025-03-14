#include "outros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Outros{
    int dificuldade;
    char local[MAX_TAM_LOC];
    char descricao[MAX_TAM_DESC];
};

Outros *criaOutros(char *local, char*descricao, int dificuldade)
{
    Outros *created= (Outros*)malloc(sizeof(Outros));
    created->dificuldade=dificuldade;
    strcpy(created->local,local);
    strcpy(created->descricao,descricao);
    return created;
}
/* 
RECOLHER COBRA QUE APARECEU NA ENTRADA DO PREDIO (descrição) 
PASSARELA DE ENTRADA (local) 
5 (dificuldade estimada pelo usuário)
 */
Outros *leOutros()
{
    char desc[MAX_TAM_DESC];
    char local[MAX_TAM_LOC];
    
    int dif;
    scanf("%[^\n]\n",desc);
    scanf("%[^\n]\n",local);
    scanf("%d\n",&dif);
    Outros *read=criaOutros(local,desc,dif);
    return read;
}

int getTempoEstimadoOutros(void *dado)
{
    Outros *tempoOutros = (Outros*)dado;
    return tempoOutros->dificuldade;
}

char getTipoOutros()
{
    return 'O';
}

void desalocaOutros(void *s)
{
    
    Outros *destroiOutros = (Outros*)s;
    free(destroiOutros);
    
}
/* 
- Tipo: Outros 
- Descricao: RECOLHER COBRA QUE APARECEU NA ENTRADA DO PREDIO 
- Local: PASSARELA DA INFORMATICA 
- Nivel de Dificuldade: 5 
- Tempo Estimado: 5h
 */
void notificaOutros(void *dado)
{
    Outros *imprimeOutros= (Outros*)dado;
    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n",imprimeOutros->descricao);
    printf("- Local: %s\n",imprimeOutros->local);
    printf("- Nível de dificuldade: %d\n",imprimeOutros->dificuldade);
    printf("- Tempo Estimado: %dh\n",imprimeOutros->dificuldade);

}