//
// Created by marconcz on 02/04/19.
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <stdio.h>
#include <stdbool.h>




int main(int argc, char *argv[]) {
    FILE *archivo;
    int caracter;
    FILE *salida;

   
    bool entradaEstandar = true;
    bool salidaEstandar = true;
    int indice = 0;

    
    while(argc >= indice) {
        indice++;

        if ((strcmp(argv[indice], "-i") == 0)) {
            if (argc > indice + 1) {
              
                indice = indice +1;
                archivo = fopen(argv[indice], "r");
                entradaEstandar = false;
            }
        }
        if ((strcmp(argv[indice], "-d") == 0)) {
            
            indice = indice +1;
            if (argc > indice + 1) {
                salida = fopen(argv[indice], "w");
                salidaEstandar = false;
            }
        }

    }

    if(entradaEstandar){
        archivo = stdin;
    }
    if(salidaEstandar){
        salida = stdout;
    }








   /*Pruebas iniciales para leer argumentos
    if (argc >= 1) {
        if ((strcmp(argv[1], "-i")!=0)){
            archivo = stdin;
        } else {
            printf("-i");
            archivo = fopen(argv[2], "r");
        }
    }
    salida = fopen(argv[1],"w");*/

    if (archivo == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }
    else
    {
        while((caracter = fgetc(archivo)) != EOF)
        {
            if(caracter == '\n'){
                fputc('\r',salida);
                fputc('\n',salida);
            }else{
                fputc(caracter,salida);
            }
        }
    }
    fclose(archivo);
    fclose(salida);
    return 0;

}



