/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "parseLib.h"
/* *******************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************
 ******************************************************************************/

 /************************************  parseCmdLine  ***********************************/
int parseCmdLine(int argc, char* argv[], pCallback_t parseCallback, void* userData) {
	int counter = 0, i = 1, parseFSM = INIT;
	for (i = 1; i < argc; i++) {									//Mientras hayan argumentos por analizar
		if (counter == ERR_CODE) {

		}
		else if (argv[i][0] == '-') {								//Si encuentro una posible clave
			if (argv[i][1] == '\0') {								//Si la clave esta vacia
				counter = ERR_CODE;									//ERROR
			}
			else if (i == argc - 1) {								//O si esa clave no tiene valor por ser el ultimo argumento
				counter = ERR_CODE;									//ERROR
			}
			else {													//Si es una clave bien escrita
				if (parseCallback(argv[i] + 1, argv[i + 1], userData) == 0) {	//Se llama al Callback para verificarla
					counter = ERR_CODE;								//Si no es valida, se reporta un error
				}
				else {												//Si no
					i++;											//Se posiciona el puntero en el siguente posible argumento
					counter++;										//Aumenta el contador
				}
			}
		}
		else {														//Si no es una potencial opcion
			if (parseCallback(NULL, argv[i], userData) == 0) {		//Se chequea validez
				counter = ERR_CODE;									//Si el parametro es invalido tira error
			}
			else {													//Si es valido
				counter++;
			}
		}
	}
	return counter;													//Se devuelve el contador
}