//-----LIBRERIAS-----//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-----CONSTANTES-----//
#define cant_alumnos 5

//-----DECLARACION DE FUNCIONES-----//
void cargarPersonas(char *V[]);
void mostrarPersonas(char *V[]);
void buscarNombrePorPalabra(char *V[],char palabra[]);
void buscarNombrePorId(char *V[],int id);

//-----MAIN-----//
int main()
{
    char *nombres[cant_alumnos];
    int menu=2;
    char palabra[20];
    cargarPersonas(nombres);
    while(menu==1 || menu==2){
        printf("-----MENU INTERACTIVO-----\n");
        printf("1: Buscar una persona por id\n");
        printf("2: Buscar una persona por palabra clave\n");
        printf("0: Salir del menu\n");
        scanf("%d",&menu);
        switch(menu){
            case 1:
                printf("Ingrese el id\n");
                int id;
                scanf("%d",&id);
                buscarNombrePorId(nombres,id);
            break;
            case 2:
                printf("Ingrese la palabra a buscar\n");
                scanf("%s",palabra);
                buscarNombrePorPalabra(nombres,palabra);
            break;
            default:
                printf("-----TERMINANDO PROGRAMA-----\n");
        }
    }
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
        printf("Nombre %d: %s\n", (i + 1), V[i]);
    }
}

void buscarNombrePorId(char *V[],int id){
    if(cant_alumnos>=id){
        printf("Nombre del alumno: %s\n", V[id-1]);
    }else{
        printf("No se encontró el valor buscado\n");
    }
}

void buscarNombrePorPalabra(char *V[],char palabra[]){
    int i=0;
    int seEncontro=0;
    char *resultado;
    while(seEncontro!=1 && cant_alumnos>i){
        resultado=strstr(V[i],palabra);
        if(resultado!=NULL){
            printf("Coincide con: %s\n",V[i]);
            seEncontro=1;
        }
        i++;
    }
    if(seEncontro==0){
        printf("No se encontro la palabra...\n");
    }
}