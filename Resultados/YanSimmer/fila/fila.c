#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
    int nTickets;
    Ticket **filaTickets;
    int cap;
};

/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila()
{
    Fila *created = (Fila*)malloc(sizeof(Fila));
    
    created->nTickets=0;
    created->cap=4;
    created->filaTickets=(Ticket**)malloc(created->cap*sizeof(Ticket*));
    return created;
}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
void desalocaFila(Fila *f)
{
    for (int i = 0; i < f->nTickets; i++)
    {
        desalocaTicket(f->filaTickets[i]);
    }
    free(f->filaTickets);
    free(f);
}

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                      func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca)
                      {
                        char id[7];
                        sprintf(id,"Tick-%d",f->nTickets+1);
                        if (f->nTickets==f->cap)
                        {
                            f->cap*=2;
                            f->filaTickets=(Ticket**)realloc(f->filaTickets,f->cap*sizeof(Ticket*));
                        }
                        f->filaTickets[f->nTickets]=criaTicket(cpfSol,dado,getTempo,getTipo,notifica,desaloca);
                        setIDTicket(f->filaTickets[f->nTickets],id);
                        f->nTickets++;
                      }

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f)
{
    return f->nTickets;
}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status)
{   int stats=0;
    if (status=='A')
    {
        for (int i = 0; i < f->nTickets; i++)
        {
            if (getStatusTicket(f->filaTickets[i])=='A')
            {
                stats++;
            }
            
        }
        
    }
    if (status=='F')
    {
        for (int i = 0; i < f->nTickets; i++)
        {
            if (getStatusTicket(f->filaTickets[i])=='F')
            {
                stats++;
            }
            
        }
    }
    return stats;
}

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i)
{
    return f->filaTickets[i];
}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f)
{
    for (int i = 0; i < f->nTickets; i++)
    {
        notificaTicket(f->filaTickets[i]);
    }
    
}
