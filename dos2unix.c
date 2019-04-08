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

    for (int i = 0; i < argc; i++){
    	if ((strcmp(argv[i], "-i") == 0)){
    		if (argc > i+1){
                if (strcmp(argv[i], "-") != 0){
                    entrada = fopen(argv[i+1], "r");
                    entradaEstandar = false;
                }

    		}
    	}

    	if ((strcmp(argv[i], "-o") == 0)){
    		if (argc > i+1){
    			if (strcmp(argv[i], "-") != 0){
                    entrada = fopen(argv[i+1], "r");
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

    while((caracter = fgetc(entrada)) != EOF)
        {
            if(caracter != '\r'){
                fputc(caracter,salida);
            }
        }

    



    fclose(entrada);
    fclose(salida);


}