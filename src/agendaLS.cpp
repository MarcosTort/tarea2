#include "../include/agendaLS.h"

struct rep_agendaLS
{
    TEvento evento;
    rep_agendaLS *sig;
};

TAgendaLS crearAgendaLS()
{
    return NULL;
}

void agregarEnAgendaLS(TAgendaLS &agenda, TEvento evento)
{
    if (agenda == NULL)
    {
        agenda = new rep_agendaLS;
        agenda->evento = evento;
        agenda->sig = NULL;
    }
    else
    {
        if (compararTFechas(fechaTEvento(evento), fechaTEvento(agenda->evento)) == 0)
        {
            TAgendaLS aux = new rep_agendaLS;
            aux->evento = evento;
            aux->sig = agenda;
            agenda = aux;
        }
        else if (compararTFechas(fechaTEvento(evento), fechaTEvento(agenda->evento)) == 1)
        {
            TAgendaLS aux = agenda;
            while (aux->sig != NULL && compararTFechas(fechaTEvento(evento), fechaTEvento(aux->sig->evento)) == -1)
            {
                aux = aux->sig;
            }
            TAgendaLS nuevo = new rep_agendaLS;
            nuevo->evento = evento;
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
        }
        else
        {
            TAgendaLS nuevoInicio = new rep_agendaLS;
            nuevoInicio->evento = evento;
            nuevoInicio->sig = agenda;
            agenda = nuevoInicio;
        }
    }
}

void imprimirAgendaLS(TAgendaLS agenda)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        imprimirTEvento(aux->evento);
        aux = aux->sig;
    }
}

void liberarAgendaLS(TAgendaLS &agenda)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        TAgendaLS aux2 = aux;
        aux = aux->sig;
        liberarTEvento(aux2->evento);
        delete aux2;
    }
    agenda = NULL;
}

bool esVaciaAgendaLS(TAgendaLS agenda)
{
    return agenda == NULL;
}

TAgendaLS copiarAgendaLS(TAgendaLS agenda)
{

    TAgendaLS copia = crearAgendaLS();
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        agregarEnAgendaLS(copia, copiarTEvento(aux->evento));
        aux = aux->sig;
    }
    return copia;
}

bool estaEnAgendaLS(TAgendaLS agenda, int id)
{

    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (idTEvento(aux->evento) == id)
        {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (idTEvento(aux->evento) == id)
        {
            return aux->evento;
        }
        aux = aux->sig;
    }
    return aux->evento;
}

void posponerEnAgendaLS(TAgendaLS &agenda, int id, nat n)
{
    TAgendaLS aux = agenda;
    TEvento evento = NULL;
    while (aux->evento != NULL && idTEvento(aux->evento) == id)
    {
        // la lista

        aux = aux->sig;
    };
    evento = aux->evento;
    TEvento nuevoEvento = copiarTEvento(evento);
    posponerTEvento(nuevoEvento, n);
    agregarEnAgendaLS(agenda, nuevoEvento);
    removerDeAgendaLS(agenda, id);
}

void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (compararTFechas(fechaTEvento(aux->evento), fecha) == 0)
        {
            imprimirTEvento(aux->evento);
        }
        aux = aux->sig;
    }
}

bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (compararTFechas(fechaTEvento(aux->evento), fecha) == 0)
        {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

void removerDeAgendaLS(TAgendaLS &agenda, int id)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (idTEvento(aux->sig->evento) == id)
        {
            TAgendaLS aux2 = aux->sig;
            aux->sig = aux->sig->sig;
            liberarTEvento(aux2->evento);
            delete aux2;
            break;
        }
        aux = aux->sig;
    }
}