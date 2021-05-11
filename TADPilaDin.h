/*
LIBRERIA: Cabecera de el TAD PILA DINAMICA
AUTOR: LMSG 2021
VERSION: 1.0

DESCRIPCION: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se a�aden y se remueven por un solo extremo.
Este extremo es llamado tope� de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinamica
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecucion del programa. En este caso la memoria
no queda fija durante la compilacion y se lograra este dinamismo
a travez del modelo "nodo" el cual se reservara dinamicamente logrando
modelar una pila.
*/

//DEFINICIONES DE CONSTANTES
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

/*Definir un nodo que sera utilizado para almacenar una posicion de la pila (Nodo),
lo que incluira a un elemento y a un apuntador al siguiente nodo*/
typedef struct nodo
{
	//Elemento a almacenar en cada nodo de la pila	
	elemento e;	
	//Apuntador al elemento de debajo (Requerido por ser una implementacion dinamica -Usuario: No modificar)
	struct nodo *abajo;
}nodo;

//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila
{		
	nodo *tope;
}pila;

//DECLARACION DE FUNCIONES
void Initialize(pila *s);			//Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e);		//Empilar (Introducir un elemento a la pila)
elemento Pop (pila *s);				//Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s);				//Vacia (Preguntar si la pila esta vacia)
elemento Top(pila *s);				//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
int Size(pila *s);					//Tama�o de la pila (Obtener el numero de elementos en la pila)
void Destroy(pila *s);				//Elimina pila (Borra a todos los elementos y a la pila de memoria)
