#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	FILE *entrada;
	FILE *salida;

	char caracter;
	bool entradaEstandar = true;
    bool salidaEstandar = true;

    int i;
    for (i = 0; i < argc; i++){
    	if ((strcmp(argv[i], "-i") == 0)){
    		if (argc > i+1){
                if (strcmp(argv[i+1], "-") != 0){
                    entrada = fopen(argv[i+1], "r");
                    entradaEstandar = false;
                }

    		}
    	}

    	if ((strcmp(argv[i], "-o") == 0)){
    		if (argc > i+1){
    			if (strcmp(argv[i+1], "-") != 0){
                    salida = fopen(argv[i+1], "r");
                    entradaEstandar = false;
                }
    		}
    	}
    }

    if(entradaEstandar){
        entrada = stdin;
    }
    if(salidaEstandar){
        salida = stdout;
    }

    if (entrada == NULL){
        fprintf(stderr,"Error al cargar el archivo");
        return 0;
    }

    while((caracter = fgetc(entrada)) != EOF)
        {
            if(caracter != '\r'){
                fputc(caracter,salida);
            }
        }

    



    fclose(entrada);
    fclose(salida);
    return 0;

}
