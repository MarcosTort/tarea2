#include "../include/personasLDE.h"

struct rep_personasLDE
{
    TPersonasLDE ant;
    TPersona persona;
    TPersonasLDE sig;
    TPersonasLDE inicio;
    TPersonasLDE fin;
};

TPersonasLDE crearTPersonasLDE()
{
    TPersonasLDE personas = new rep_personasLDE;
    personas->ant = NULL;
    personas->persona = NULL;
    personas->sig = NULL;
    personas->inicio = NULL;
    personas->fin = NULL;
    personas = NULL;
    
    return personas;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos)
{

    if (pos == 1)
    {
        TPersonasLDE nuevo = new rep_personasLDE;
        nuevo->persona = persona;
        nuevo->sig = personas;
        nuevo->ant = NULL;
        personas = nuevo;
        personas->inicio = nuevo;
    }
    else
    {
        TPersonasLDE aux = personas;
        while (aux->sig != NULL && pos > 1)
        {
            aux = aux->sig;
            pos--;
        }
        TPersonasLDE nuevo = new rep_personasLDE;
        nuevo->persona = persona;
        nuevo->sig = aux->sig;
        nuevo->ant = aux;
        aux->sig = nuevo;
        nuevo->sig->ant = nuevo;
    }
}

void liberarTPersonasLDE(TPersonasLDE &personasLDE)
{
       
        TPersonasLDE aux = personasLDE;
        if (aux != NULL)
        {
           personasLDE = NULL;
        }
        while (aux != NULL)
        {
            TPersonasLDE aux2 = aux;
            aux = aux->sig;
            liberarTPersona(aux2->persona);
            delete aux2;
        }
        delete personasLDE;
        personasLDE = NULL;
    
}

void imprimirTPersonasLDE(TPersonasLDE personas)
{
}

nat cantidadTPersonasLDE(TPersonasLDE personas)
{
    return 0;
}

void eliminarInicioTPersonasLDE(TPersonasLDE &personas)
{
}

void eliminarFinalTPersonasLDE(TPersonasLDE &personas)
{
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id)
{
    return false;
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id)
{
    return NULL;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2)
{
    return NULL;
}