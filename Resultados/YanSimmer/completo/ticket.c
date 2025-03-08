#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket
{
    char id[MAX_TAM_ID];
    char cpfSolicitador[MAX_TAM_CPF];
    void *data;
    char status[11];
    func_ptr_desaloca desaloc;
    func_ptr_notifica notifica;
    func_ptr_tempoEstimado tempo;
    func_ptr_tipo tipagem;
};

/**
 * @brief Aloca uma estrutura Ticket na memória e inicializa os parâmetro necessários
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido
 * @param notifica  Função de callback de notificação  (impressãode um ticket
 * @param desaloca  Função de callback que irá desalocar  um ticket da memória
 * @return  Uma estrutura Ticket inicializada.
 */
Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
    func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca)
    {
        Ticket *created = (Ticket*)malloc(sizeof(Ticket));
        //created->data=(void*)malloc(sizeof(void));
        strcpy(created->cpfSolicitador,cpfSol);
        created->data=dado;
        created->desaloc=desaloca;
        created->notifica=notifica;
        created->tempo=getTempo;
        created->tipagem=getTipo;
        strcpy(created->status,"Aberto");
        return created;
    }

/**
* @brief Atribui um ID a um ticket
* @param d Ticket inicializado
* @param id ID a ser atribuido ao ticket
*/
void setIDTicket(Ticket *d, char *id)
{
    strcpy(d->id,id);
}

/**
* @brief Finaliza um ticket
* @param t Ticket inicializado
*/
void finalizaTicket(Ticket *t)
{
    strcpy(t->status,"Finalizado");
}

/**
* @brief Recupera o CPF de quem solicitou a abertura do ticket
* @param t Ticket inicializado
* @return CPF de quem solicitou a abertura do ticket
*/
char *getCPFSolicitanteTicket(Ticket *t)
{
    return t->cpfSolicitador;
}

/**
* @brief Recupera o tempo estimado para resolver um ticket
* @param t Ticket inicializado
* @return tempo estimado para resolver um ticket
*/
int getTempoEstimadoTicket(Ticket *t)
{
    return t->tempo(t->data);
}

/**
* @brief Recupera o tipo de um ticket
* @param t Ticket inicializado
* @return tipo do Ticket
*/
char getTipoTicket(Ticket *t)
{
    return t->tipagem();
}

/**
* @brief Recupera o status de um ticket
* @param t Ticket inicializado
* @return status do Ticket
*/
char getStatusTicket(Ticket *t)
{
    return t->status[0];
}

/**
* @brief  Desaloca um ticket da memória
* @param doc estrutura do tipo Ticket que deve ser liberada da memória
*/
void desalocaTicket(Ticket *doc)
{
    doc->desaloc(doc->data);
    free(doc);
}

/**
* @brief  Notifica (imprime) um ticket
* @param doc Ticket a ser notificado
*/
void notificaTicket(Ticket *doc)
{
    printf("---------TICKET-----------\n");
    printf("- ID: %s\n",doc->id);
    printf("- Usuario solicitante: %s\n",doc->cpfSolicitador);
    doc->notifica(doc->data);
    printf("- Status: %s\n",doc->status);
    printf("-------------------------\n\n");
}