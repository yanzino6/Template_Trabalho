#include "software.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Software {
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categ[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    int tempoRes;
};

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo)
{
    Software *created = (Software*)malloc(sizeof(Software));
    strcpy(created->categ,categoria);
    strcpy(created->motivo,motivo);
    strcpy(created->nome,nome);
    created->impacto=impacto;
    return created;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
/* 
OUTLOOK
BUG
4
EMAILS NAO ESTAO SENDO ENVIADOS
 */
Software *lerSoftware()
{   
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categ[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    scanf("%[^\n]\n",nome);
    scanf("%[^\n]\n",categ);
    scanf("%d\n",&impacto);
    scanf("%[^\n]\n",motivo);

    Software *read=criaSoftware(nome,categ,impacto,motivo);
    return read;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s)
{
    if (strcmp(s->categ,"BUG")==0)
    {
        s->tempoRes=s->impacto+TEMPO_ESTIMADO_BUG;
    }
    if (strcmp(s->categ,"OUTROS")==0)
    {
        s->tempoRes=s->impacto+TEMPO_ESTIMADO_OUTROS;
    }
    if (strcmp(s->categ,"DUVIDA")==0)
    {
        s->tempoRes=s->impacto+TEMPO_ESTIMADO_DUVIDA;
    }
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado)
{
    Software *retornaSoft = (Software*)dado;
    return retornaSoft->tempoRes;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware()
{
    return 'S';
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s)
{
    Software *destroiSoftware = (Software*)s;
    free(destroiSoftware);
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */

 /* - Tipo: Software
    - Nome do software: EXCEL
    - Categoria: DUVIDA
    - Nível do impacto: 2
    - Motivo: NAO CONSIGO ORDENAR COLUNA DE DADOS
    - Tempo estimado: 3h */
void notificaSoftware(void *dado)
{
    Software *printaSoft=(Software*)dado;
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n",printaSoft->nome);
    printf("- Categoria: %s\n",printaSoft->categ);
    printf("- Nível do impacto: %d\n",printaSoft->impacto);
    printf("- Motivo: %s\n",printaSoft->motivo);
    printf("- Tempo estimado: %dh\n",printaSoft->tempoRes);
}