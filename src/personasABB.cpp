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
        if (personasABB->persona != NULL)
        {
            imprimirTPersona(personasABB->persona);
        }
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
    else if (esVacioTPersonasABB(personasABB->der))
    {
        return personasABB->persona;
    }
    else
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

                TPersona maxIzq = maxIdPersona(personasABB->izq);

                liberarTPersona(personasABB->persona);
                personasABB->persona = copiarTPersona(maxIzq);
                removerTPersonasABB(personasABB->izq, idTPersona(maxIzq));
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

// TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad)
// {
//     if (esVacioTPersonasABB(personasABB))
//     {
//         return NULL;
//     }
//     else
//     {
//         TPersonasABB nueva = new rep_personasAbb;
//         TPersonasABB mayoresIzq = mayoresTPersonasABB(personasABB->izq, edad);
//         TPersonasABB mayoresDer = mayoresTPersonasABB(personasABB->der, edad);
//         if (edadTPersona(personasABB->persona) > edad)
//         {

//             nueva->persona = copiarTPersona(personasABB->persona);
//             nueva->der = mayoresIzq;
//             nueva->izq = mayoresDer;
//         }
//         else
//         {
//             if (mayoresDer == NULL)
//             {
//                 nueva = mayoresIzq;
//             }
//             else if (mayoresIzq == NULL)
//             {
//                 nueva = mayoresDer;
//             }
//             else
//             {
//                 return NULL;
//             }
//         }
//         return nueva;
//     }
// }
TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return NULL;
    }
    else
    {
        TPersonasABB mayoresIzq = mayoresTPersonasABB(personasABB->izq, edad);
        TPersonasABB mayoresDer = mayoresTPersonasABB(personasABB->der, edad);
        if (edadTPersona(personasABB->persona) > edad)
        {
            TPersonasABB nueva = new rep_personasAbb;

            nueva->persona = copiarTPersona(personasABB->persona);
            nueva->der = mayoresDer;
            nueva->izq = mayoresIzq;
            return nueva;
        }
        else
        {

            if (mayoresDer == NULL)
            {
                TPersonasABB nueva = new rep_personasAbb;

                nueva = mayoresIzq;
                return nueva;
            }
            else if (mayoresIzq == NULL)
            {
                TPersonasABB nueva = new rep_personasAbb;

                nueva = mayoresDer;
                return nueva;
            }
            else
            {
                return NULL;
            }
        }
    }
}
TPersonasLDE aux(TPersonasLDE cad, TPersonasABB personasABB)
{
    if (esVacioTPersonasABB(personasABB))
    {
        return cad;
    }
    else
    {
        cad = aux(cad, personasABB->izq);
        insertarTPersonasLDE(cad, copiarTPersona(personasABB->persona), 1);
        cad = aux(cad, personasABB->der);
        return cad;
    }
}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB)
{
    TPersonasLDE cad = crearTPersonasLDE();
    cad = aux(cad, personasABB);
    return cad;
}
