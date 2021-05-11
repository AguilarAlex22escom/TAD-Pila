/*
LIBRERIA: Cabecera de el TAD PILA ESTATICA
AUTOR: LMSG 2021
VERSION: 1.0

DESCRIPCION: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se aÒaden y se remueven por un solo extremo.
Este extremo es llamado topeù de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos estatica cuando se le
asigna una cantidad fija de memoria para esa estructura 
antes de la ejecucion del programa.
*/

//DEFINICIONES DE CONSTANTES
#define MAX_ELEMENT 1000
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	char c;
	//***
	//***
	//***
}elemento;

//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila
{		
	elemento arreglo[MAX_ELEMENT];		//La pila es un arreglo estatico de MAX_ELEMET
	int tope; 							//El tope es un entero (Indice del arreglo de elementos)
}pila;

//DECLARACION DE FUNCIONES
void Initialize(pila *s);			//Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e);		//Empilar (Introducir un elemento a la pila)
elemento Pop (pila *s);				//Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s);				//Vacia (Preguntar si la pila esta vacia)
elemento Top(pila *s);				//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
int Size(pila *s);					//TamaÒo de la pila (Obtener el numero de elementos en la pila)
void Destroy(pila *s);				//Elimina pila (Borra a todos los elementos y a la pila de memoria)
