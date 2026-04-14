//-----LIBRERIAS-----//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-----CONSTANTES-----//
#define cant_alumnos 5

//-----FUNCIONES-----//

int main(){
    char * V[cant_alumnos];
    int i;
    char buff[50];
    int longitud;
    for(i=0;i<cant_alumnos;i++){
        printf("Ingrese el nombre %d:",(i+1));
        scanf("%s",buff);
        longitud=strlen(buff);
        V[i]=(char *)malloc(sizeof(char)*longitud);
        strcpy(V[i],buff);
    }
}