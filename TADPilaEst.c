/*
IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA ESTATICA (TADPilaEst.h)
AUTOR: LMSG 2021
VERSION: 1.0

DESCRIPCION: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se aÒaden y se remueven por un solo extremo.
Este extremo es llamado topeùde la pila.

OBSERVACIONES: Estructura de datos estatica es cuando se le asigna
una cantidad fija de memoria para esa estructura antes de la ejecucion del programa.

COMPILACION PARA GENERAR EL CODIGO OBJETO: gcc TADPilaEst.c -c
*/

//LIBRERAS
#include<stdio.h>
#include<stdlib.h>
#include "TADPilaEst.h"

//DEFINICION DE FUNCIONES

/*
void Initialize(pila *s);
Descripcion: Inicializar pila (Iniciar una pila para su uso)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pila *s)
{
	(*s).tope=-1; //s->tope=-1; 
	return;
}

/*
void Push(pila *s, elemento e);
Descripcion: Empilar (Introducir un elemento a la pila)
Recibe: pila *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida el indice del arreglo (tope) esta fuera del arreglo es decir hay desbordamiento
y se causara en error.
*/
void Push(pila *s, elemento e)
{
	s->tope++;
	
	//Si el tope alcanzo a MAX_ELEMENT, ya no hay mas espacio para elementos en el arreglo
	if(s->tope==MAX_ELEMENT)
	{
		printf("\nERROR-Push(&s,e): Desbordamiento de la pila, no hay mas espacio en la pila");
		exit(1);
	}
	
	//Insertar el elemento si no hubo error
	s->arreglo[s->tope]=e;
	return;
}

/*
elemento Pop(pila *s);
Descripcion: Desempilar (Extraer un elemento de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento e extraido de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia (tope == -1) antes de desempilar (causa error desempilar si esta esta vacia)
*/
elemento Pop (pila *s)
{
	elemento r;
	
	//Si el tope es -1, se intenta Pop de pila vacia 
	if(s->tope==-1)
	{
		printf("\nERROR-e=Pop(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	//Si no hubo error retornar el elemento indexado por tope
	r=s->arreglo[s->tope];
	s->tope--;
	return r; 	
}

/*
boolean Empy(pila *s);
Descripcion: //Vacia (Preguntar si la pila esta vacia)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE segun sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pila *s)
{
	boolean r;	
	if(s->tope==-1)
	{
		r= TRUE;	
	}	
	else
	{
		r= FALSE;
	}	
	return r;	
}

/*
elemento Top(pila *s);
Descripcion: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de consultar al elemento del tope (causa error si esta esta vacia).
*/
elemento Top(pila *s)
{
	//Si el tope es -1, se intenta Pop de pila vacia 
	if(s->tope==-1)
	{
		printf("\nERROR-e=Top(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	//Si no hubo error retornar el elemento indexado por tope
	return s->arreglo[s->tope];	
}

/*
int Size(pila *s);
Descripcion: TamaÒo de la pila (Obtener el numero de elementos en la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: int (TamaÒo de la pila -1->Vacia, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pila *s)
{
	return s->tope+1;
}

/*
void Destroy(pila *s);
Descripcion: Elimina pila (Borra a todos los elementos en a la pila de memoria* Memoria estatica (No se puede eleminar realmente)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pila y s tiene la referencia a ella.
*/
void Destroy(pila *s)
{
	//s->tope=-1;
	Initialize(s);
	return;
}
