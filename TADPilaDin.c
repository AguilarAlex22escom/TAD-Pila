/*
IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA DINAMICA (TADPilaDin.h)
AUTOR: LMSG
VERSION: 1.0

DESCRIPCION: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se a�aden y se remueven por un solo extremo.
Este extremo es llamado tope de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinamica
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecucion del programa. En este caso la memoria
no queda fija durante la compilacion.

COMPILACION PARA GENERAR EL CODIGO OBJETO: gcc TADPilaDin.c -c
*/

//LIBRERAS
#include <stdio.h>
#include <stdlib.h>
#include "TADPilaDin.h"

//DEFINICION DE FUNCIONES

/*
void Initialize(pila *s);
Descripcion: Inicializar pila (Iniciar una pila para su uso)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pila *s)
{
	s->tope=NULL; //(*s).tope=NULL;
	return;
}

/*
void Push(pila *s, elemento e);
Descripcion: Empilar (Introducir un elemento a la pila)
Recibe: int *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si el malloc() pudo o no apartar memoria, se idealiza que siempre funciona bien 
y no se acaba la memoria
*/
void Push(pila *s, elemento e)
{
	nodo *aux;
	aux=malloc(sizeof(nodo));
	
	//Si no hay mas memoria dinamica por alguna razon
	if(aux==NULL)
	{
		printf("\nERROR-Push(&s,e): Desbordamiento de la pila, no hay mas memoria disponible");
		exit(1);
	}
	
	//Si se creo el nuevo nodo insertar al elemento
	(*aux).e=e;  //aux->e=e;
	aux->abajo=s->tope;
	s->tope=aux;
	return;
}


/*
void Pop(pila *s);
Descripcion: Desempilar (Extraer un elemento de la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento e extraido de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de desempilar (causa error desempilar si esta esta vacia),
tampoco se valida si free() pudo o no liberar la memoria, se idealiza que siempre funciona bien 
*/
elemento Pop (pila *s)
{
	elemento r;
	nodo *aux;
	
	//Si el tope es NULL, se intenta Pop de pila vacia 
	if(s->tope==NULL)
	{
		printf("\nERROR-e=Pop(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	r=s->tope->e;
	aux=s->tope;
	s->tope=s->tope->abajo;
	free(aux);
	return r;	
}

/*
boolean Empty(pila *s);
Descripcion: //Vacia (Preguntar si la pila esta vacia)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE segun sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pila *s)
{
	boolean r;
	if(s->tope==NULL)
	{
		r=TRUE;
	}	
	else
	{
		r=FALSE;
	}
	return r;	
}

/*
elemento Top(pila *s);
Descripcion: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de consultar al elemnto del tope (causa error si esta esta vacia).
*/
elemento Top(pila *s)
{
	//Si el tope es NULL, se intenta Top de pla vacia 
	if(s->tope==NULL)
	{
		printf("\nERROR-e=Top(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	return s->tope->e;
}

/*
int Size(pila *s);
Descripcion: Tama�o de la pila (Obtener el numero de elementos en la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: int (Tama�o de la pila 0->Vacia, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pila *s)
{
	nodo *aux;
	int tam_pila=0;
	aux=s->tope;
	if(aux!=NULL)
	{
		tam_pila++;
		while(aux->abajo!=NULL)
		{
			tam_pila++;
			aux=aux->abajo;
		}
	}	
	return tam_pila;
}

/*
void Destroy(pila *s);
Descripcion: Elimina pila (Borra a todos los elementos en a la pila de memoria)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
void Destroy(pila *s)
{
	nodo *aux;
	if(s->tope!=NULL)
	{
		while(s->tope!=NULL)
		{				
			aux=s->tope->abajo;
			free(s->tope);
			s->tope=aux;
		}		
	}
	return;
}
