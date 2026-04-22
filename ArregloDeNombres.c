//-----LIBRERIAS-----//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-----CONSTANTES-----//
#define cant_alumnos 5

//-----DECLARACION DE FUNCIONES-----//
void cargarPersonas(char *V[]);
void mostrarPersonas(char *V[]);
void buscarNombre(char *V[],char palabra[]);

//-----MAIN-----//
int main()
{
    char *nombres[cant_alumnos];
    cargarPersonas(nombres);
    //mostrarPersonas(nombres);
    char palabra[20];int result;
    printf("Ingrese un nombre para realizar la busqueda:");
    scanf("%s", palabra);
    buscarNombre(nombres,palabra);
}

//------FUNCIONES-----//
void cargarPersonas(char *V[])
{
    int i;
    char buff[20];
    int longitud;
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

void buscarNombre(char *V[],char palabra[]){
    int i=0;
    int seEncontro=0;
    char *resultado;
    while(seEncontro!=1 && cant_alumnos>i){
        resultado=strstr(V[i],palabra);
        if(resultado!=NULL){
            printf("Coincide con: %s",V[i]);
            seEncontro=1;
        }
        i++;
    }
}