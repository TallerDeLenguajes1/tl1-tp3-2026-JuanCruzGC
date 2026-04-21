//-----LIBRERIAS-----//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-----CONSTANTES-----//
#define cant_alumnos 5

//-----DECLARACION DE FUNCIONES-----//
void cargarPersonas(char *V[]);
void mostrarPersonas(char *V[]);

//-----MAIN-----//
int main()
{
    char *nombres[cant_alumnos];
    cargarPersonas(nombres);
    mostrarPersonas(nombres);
}

//------FUNCIONES-----//
void cargarPersonas(char *V[])
{
    int i;
    char buff[20];
    int longitud = strlen(buff);
    for (i = 0; i < cant_alumnos; i++)
    {
        printf("Ingrese el nombre %d:\n", (i + 1));
        scanf("%s", buff);
        longitud = strlen(buff);
        V[i] = (char *)malloc(sizeof(char) * longitud);
        strcpy(V[i], buff);
    }
}

void mostrarPersonas(char *V[])
{
    int i;
    for (i = 0; i < cant_alumnos; i++)
    {
        printf("\nNombre %d: %s", (i + 1), V[i]);
    }
}