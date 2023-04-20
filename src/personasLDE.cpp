#include "../include/personasLDE.h"
struct nodo
{
    TPersona persona;
    nodo *anterior;
    nodo *siguiente;
};
typedef nodo *Nodo;
struct rep_personasLDE
{

    Nodo inicio;
    Nodo fin;
};

TPersonasLDE crearTPersonasLDE()
{
    TPersonasLDE personas = new rep_personasLDE;
    personas->inicio = NULL;
    personas->fin = NULL;
    return personas;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos)
{
    Nodo nuevo = new nodo;
    nuevo->persona = persona;

    if (pos == 1)
    {
        if (personas->inicio == NULL)
        {
            personas->inicio = nuevo;
            personas->fin = nuevo;
            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;
        }
        else
        {
            nuevo->siguiente = personas->inicio;
            personas->inicio->anterior = nuevo;
            nuevo->anterior = NULL;
            personas->inicio = nuevo;
        }
    }
    else
    {
        Nodo aux = personas->inicio;
        if (aux != NULL)
        {
            nat i = 1;
            while (aux->siguiente != NULL && pos >= i)
            {
                aux = aux->siguiente;
                i++;
            }
            // insertar al final
            if (pos != i)
            {
                nuevo->anterior = personas->fin;
                personas->fin->siguiente = nuevo;
                personas->fin = nuevo;
                nuevo->siguiente = NULL;
            }
            else
            {
                nuevo->anterior = aux->anterior;
                aux->anterior->siguiente = nuevo;
                nuevo->siguiente = aux;
                aux->anterior = nuevo;
            }
        }
        else
        {
            personas->inicio = nuevo;
            personas->fin = nuevo;
            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;
        }
    }
}

void liberarTPersonasLDE(TPersonasLDE &personasLDE)
{
    Nodo a_borrar;
    while (personasLDE->inicio != NULL)
    {
        a_borrar = personasLDE->inicio;
        personasLDE->inicio = personasLDE->inicio->siguiente;
        liberarTPersona(a_borrar->persona);
        delete (a_borrar);
    }
    delete personasLDE;
    personasLDE = NULL;
}

void imprimirTPersonasLDE(TPersonasLDE personas)
{

    Nodo aux = personas->inicio;
    while (aux != NULL && aux->persona != NULL)
    {
        imprimirTPersona(aux->persona);
        aux = aux->siguiente;
    }
}

nat cantidadTPersonasLDE(TPersonasLDE personas)
{
    nat cant = 0;
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        cant++;
        aux = aux->siguiente;
    }
    return cant;
}

void eliminarInicioTPersonasLDE(TPersonasLDE &personas)
{
    Nodo a_borrar = personas->inicio;
    if (a_borrar != NULL)
    {

        if (a_borrar == personas->fin)
        {
            personas->fin = NULL;
            personas->inicio = NULL;
        }
        else
        {
            personas->inicio = a_borrar->siguiente;
            a_borrar->siguiente->anterior = NULL;
        }

        liberarTPersona(a_borrar->persona);
        delete a_borrar;
    }
}

void eliminarFinalTPersonasLDE(TPersonasLDE &personas)
{

    Nodo a_borrar = personas->fin;
    if (a_borrar != NULL)
    {

        if (a_borrar == personas->inicio)
        {

            personas->fin = NULL;
            personas->inicio = NULL;
            liberarTPersona(a_borrar->persona);
            delete a_borrar;
        }
        else
        {

            personas->fin = a_borrar->anterior;
            a_borrar->anterior->siguiente = NULL;
            liberarTPersona(a_borrar->persona);
            delete a_borrar;
        }
    }
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id)
{
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        if (id == idTPersona(aux->persona))
        {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id)
{
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        if (id == idTPersona(aux->persona))
        {
            return aux->persona;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2)
{
    TPersonasLDE personas = crearTPersonasLDE();
    if (personas1->inicio != NULL && personas2->inicio != NULL)
    {
        personas->inicio = personas1->inicio;
        personas->fin = personas2->fin;
        personas1->fin->siguiente = personas2->inicio;
        personas2->inicio->anterior = personas1->fin;
    }
    else
    {
        if (personas1->inicio != NULL)
        {
            personas->inicio = personas1->inicio;
            personas->fin = personas1->fin;
        }
        else
        {
            personas->inicio = personas2->inicio;
            personas->fin = personas2->fin;
        }
    }
    delete personas1;
    delete personas2;
    return personas;
}