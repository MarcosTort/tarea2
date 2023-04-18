#include "../include/personasABB.h"

struct rep_personasAbb
{
    TPersona persona;
    TPersonasABB izq;
    TPersonasABB der;
};

TPersonasABB crearTPersonasABB()
{
    return NULL;
}

bool esVacioTPersonasABB(TPersonasABB personasABB)
{
    return personasABB == NULL;
}

void insertarTPersonasABB(TPersonasABB &personasABB, TPersona p)
{
    if (esVacioTPersonasABB(personasABB))
    {
        personasABB = new rep_personasAbb;
        personasABB->persona = p;
        personasABB->izq = NULL;
        personasABB->der = NULL;
    }
    else
    {
        if (idTPersona(p) < idTPersona(personasABB->persona))
        {
            insertarTPersonasABB(personasABB->izq, p);
        }
        else
        {
            insertarTPersonasABB(personasABB->der, p);
        }
    }
}

void liberarTPersonasABB(TPersonasABB &personasABB)
{
    if (!esVacioTPersonasABB(personasABB))
    {
        liberarTPersonasABB(personasABB->izq);
        liberarTPersonasABB(personasABB->der);
        liberarTPersona(personasABB->persona);
        delete personasABB;
        personasABB = NULL;
    }
}

void imprimirTPersonasABB(TPersonasABB personasABB)
{
    if (!esVacioTPersonasABB(personasABB))
    {
        imprimirTPersonasABB(personasABB->izq);
        imprimirTPersona(personasABB->persona);
        imprimirTPersonasABB(personasABB->der);
    }
}

nat cantidadTPersonasABB(TPersonasABB personasABB)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return 0;
    }
    else
    {
        return 1 + cantidadTPersonasABB(personasABB->izq) + cantidadTPersonasABB(personasABB->der);
    }
}

TPersona maxIdPersona(TPersonasABB personasABB)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return NULL;
    }
    if (esVacioTPersonasABB(personasABB->der))
    {
        return personasABB->persona;
    }
    return maxIdPersona(personasABB->der);
}

void removerTPersonasABB(TPersonasABB &personasABB, nat id)
{
    if (!esVacioTPersonasABB(personasABB))
    {
        if (idTPersona(personasABB->persona) == id)
        {
            if (esVacioTPersonasABB(personasABB->izq) && esVacioTPersonasABB(personasABB->der))
            {
                liberarTPersona(personasABB->persona);
                delete personasABB;
                personasABB = NULL;
            }
            else if (esVacioTPersonasABB(personasABB->izq))
            {
                TPersonasABB aux = personasABB;
                personasABB = personasABB->der;
                liberarTPersona(aux->persona);
                delete aux;
            }
            else if (esVacioTPersonasABB(personasABB->der))
            {
                TPersonasABB aux = personasABB;
                personasABB = personasABB->izq;
                liberarTPersona(aux->persona);
                delete aux;
            }
            else
            {
                TPersonasABB aux = personasABB;
                personasABB->persona = maxIdPersona(personasABB->izq);
                liberarTPersona(aux->persona);
                delete aux;
                removerTPersonasABB(personasABB->izq, idTPersona(personasABB->persona));
            
                
            }
        }
        else if (id < idTPersona(personasABB->persona))
        {
            removerTPersonasABB(personasABB->izq, id);
        }
        else
        {
            removerTPersonasABB(personasABB->der, id);
        }
    }
}

bool estaTPersonasABB(TPersonasABB personasABB, nat id)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return false;
    }
    if (idTPersona(personasABB->persona) == id)
    {
        return true;
    }
    else if (id < idTPersona(personasABB->persona))
    {
        return estaTPersonasABB(personasABB->izq, id);
    }
    else
        return estaTPersonasABB(personasABB->der, id);
}

TPersona obtenerDeTPersonasABB(TPersonasABB personasABB, nat id)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return NULL;
    }
    if (idTPersona(personasABB->persona) == id)
    {
        return personasABB->persona;
    }
    else if (id < idTPersona(personasABB->persona))
    {
        return obtenerDeTPersonasABB(personasABB->izq, id);
    }
    else
        return obtenerDeTPersonasABB(personasABB->der, id);
}

nat alturaTPersonasABB(TPersonasABB personasABB)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return 0;
    }
    else
    {
        nat alturaIzq = alturaTPersonasABB(personasABB->izq);
        nat alturaDer = alturaTPersonasABB(personasABB->der);
        if (alturaIzq > alturaDer)
        {
            return 1 + alturaIzq;
        }
        else
        {
            return 1 + alturaDer;
        }
    }
}

bool esPerfectoTPersonasABB(TPersonasABB personasABB)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return true;
    }
    else
    {
        nat alturaIzq = alturaTPersonasABB(personasABB->izq);
        nat alturaDer = alturaTPersonasABB(personasABB->der);
        if (alturaIzq == alturaDer)
        {
            return esPerfectoTPersonasABB(personasABB->izq) && esPerfectoTPersonasABB(personasABB->der);
        }
        else
        {
            return false;
        }
    }
}

TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad)
{
    return NULL;
}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB)
{
    return NULL;
}
