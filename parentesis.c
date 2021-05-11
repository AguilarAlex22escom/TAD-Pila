//LIBRERAS
#include <stdio.h>
#include <stdlib.h>	//Para usar exit()
#include <string.h> //Para usar strlen()
#include "TADPilaEst.h" //Inclusion de la libreria del TAD Pila Estatica (Si se desea usar una pila estatica)
//#include "TADPilaDin.h" //Inclusion de la libreria del TAD Pila Dinamica (Si se desea usar una pila dinamica)

//DEFINICIONES
#define TAM_CADENA 100 //Tamaño maximo de la cadena a evaluar considerando el '\0'

//PROGRAMA PRINCIPAL
int main(void)
{
	int tam_cadena;
	int i,j;
	char cadena[TAM_CADENA];

	//Se declara una pila "mi_pila"
	pila mi_pila;
	//Declaro un elemento "e1"
	elemento e1;
	//InicializaciOn de "mi_pila"
	Initialize(&mi_pila);

	//Leer cadena a evaluar sus parentesis
    printf("Escribe una cadena de parentesis: ");
	scanf("%s",cadena);

	//Medir el tamaño de la cadena
	tam_cadena=strlen(cadena);

	//Recorrer cada caracter de la cadena
	for(i=0;i<tam_cadena;i++)
	{
		//Si el caracter es ( introducirlo a la pila
		if(cadena[i]=='(')
			{
				e1.c='(';
				Push(&mi_pila,e1);
			}

		//Si el caracter es ) realizar un Pop a la pila
		else if(cadena[i]==')')
			{
				//Si se intenta extraer un elemento y la pila es vacia Error: P.g. (a+b)*c)
				if(Empty(&mi_pila))
				{
					printf("ERROR: Existen mas parentesis que cierran de los que abren");
					exit(1); //Salir del programa con error
				}
				e1=Pop(&mi_pila);
			}
	}

	//Si al terminar de revisar la expresion aun hay elementos en la pila Error: P.g. (a+b)*c(a-c
	if(!Empty(&mi_pila))
	{
		printf("ERROR: Existen mas parentesis que abren de los que cierran");
		exit(1); //Salir del programa con error
	}

	//Si la ejecucion termina de manera correcta
	printf("EXCELENTE: Expresion correcta");

	//Destruir los elementos de la pila
	Destroy(&mi_pila);
	exit(0); //Terminar el programa sin errores
	
	system("pause");
}
