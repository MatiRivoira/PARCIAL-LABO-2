/*
 * eServicios.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eServicios.h"
#include "LinkedList.h"


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
eServicio* servicios_new(){
	eServicio* servicio;
	servicio = (eServicio*) malloc(sizeof(eServicio));
	return servicio;
}

eServicio* servicio_newParametros(char* idStr, char* descripcion,char* tipo, char* precioUnitario, char* cantidad, char* totalServicios){
	eServicio* servicio;
	servicio = servicios_new();
	if(servicio != NULL){
		servicio_setId(servicio, atoi(idStr));
		servicio_setDescripcion(servicio, descripcion);
		servicio_setTipo(servicio, atoi(tipo));
		servicio_setPrecioUnitario(servicio, atof(precioUnitario));
		servicio_setCantidad(servicio, atoi(cantidad));
		servicio_setTotalServicio(servicio, atof(totalServicios));
		return servicio;
	}
	return NULL;
}

int servicio_setId(eServicio* this, int id){
	int retorno = -1;
	if(this != NULL && id > 0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int servicio_getId(eServicio* this, int* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int servicio_getLastId(LinkedList* this, int* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		int tam = ll_len(this);
		int idMax = 0;
		int idAux;
		eServicio* aux;
		for(int i = 0; i < tam ; i++){
			aux = ll_get(this, i);
			servicio_getId(aux, &idAux);
			if(idAux > idMax){
				idMax = idAux;
			}
		}
		*id = idMax + 1;
		retorno = 0;
	}
	return retorno;
}

int servicio_setDescripcion(eServicio* this, char* descripcion){
	int retorno = -1;
	if(this != NULL && descripcion != NULL){
		strcpy(this->descripcion, descripcion);
		retorno = 0;
	}
	return retorno;
}

int servicio_getDescripcion(eServicio* this, char* descripcion){
	int retorno = -1;
	if(this != NULL && descripcion != NULL){
		strcpy(descripcion,this->descripcion);
		retorno = 0;
	}
	return retorno;
}

int servicio_setTipo(eServicio* this, int tipo){
	int retorno = -1;
	if(this != NULL && tipo >= 0 && tipo <= 3){
		this->tipo = tipo;
		retorno = 0;
	}
	return retorno;
}

int servicio_getTipo(eServicio* this,int* tipo){
	int retorno = -1;
	if(this != NULL && tipo != NULL){
		*tipo = this->tipo;
		retorno = 0;
	}
	return retorno;
}

int servicio_setPrecioUnitario(eServicio* this, float precioUnitario){
	int retorno = -1;
	if(this != NULL && precioUnitario >= 0){
		this->precioUnitario = precioUnitario;
		retorno = 0;
	}
	return retorno;
}

int servicio_getPrecioUnitario(eServicio* this, float* precioUnitario){
	int retorno = -1;
	if(this != NULL && precioUnitario != NULL){
		*precioUnitario = this->precioUnitario;
		retorno = 0;
	}
	return retorno;
}

int servicio_setCantidad(eServicio* this, int cantidad){
	int retorno = -1;
	if(this != NULL && cantidad > 0){
		this->cantidad = cantidad;
		retorno = 0;
	}
	return retorno;
}

int servicio_getCantidad(eServicio* this, int* cantidad){
	int retorno = -1;
	if(this != NULL && cantidad != NULL){
		*cantidad = this->cantidad;
		retorno = 0;
	}
	return retorno;
}

int servicio_setTotalServicio(eServicio* this, float precioTotal){
	int retorno = -1;
	if(this != NULL && precioTotal >= 0){
		this->totalServicio = precioTotal;
		retorno = 0;
	}
	return retorno;
}

int servicio_getTotalServicio(eServicio* this, float* precioTotal){
	int retorno = -1;
	if(this != NULL){
		*precioTotal = this->totalServicio;
		retorno = 0;
	}
	return retorno;
}

int servicio_printOne(eServicio* this){
int retorno = -1;
	if(this != NULL){

		int id;
		char descripcion[50];
		int tipo;
		char tipoStr[20];
		float precioUnitario;
		int cantidad;
		float totalServicio;

		servicio_getId(this, &id);
		servicio_getDescripcion(this, descripcion);
		servicio_getTipo(this, &tipo);
		switch(tipo){
			case 1:
				strcpy(tipoStr, "Minorista");
				break;
			case 2:
				strcpy(tipoStr, "Mayorista");
				break;
			case 3:
				strcpy(tipoStr, "Exportar");
				break;
		}
		servicio_getPrecioUnitario(this, &precioUnitario);
		servicio_getCantidad(this, &cantidad);
		servicio_getTotalServicio(this, &totalServicio);


		printf("║ %-2d ║ %-30s ║ %-10s ║ %-11f ║ %-5d ║ %-15f ║\n"
			   "╠════╬════════════════════════════════╬════════════╬═════════════╬═══════╬════════════════╣\n", id, descripcion, tipoStr, precioUnitario, cantidad, totalServicio);
		retorno = 0;
	}
 return retorno;
}

void printServicio(eServicio* servicio){
	if(servicio != NULL){
		printf("EL SERVICIO ES:\n%-4d | %-20s | %-20d | %-20f | %-20d | %-20f\n", servicio->id, servicio->descripcion, servicio->tipo, servicio->precioUnitario, servicio->cantidad, servicio->totalServicio);
	}
}

int saveAsText(FILE* pArchivo, LinkedList* pArrayListPassenger){
	int retorno = -1;
	eServicio* servicio;

	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	if(pArchivo != NULL && pArrayListPassenger != NULL){
		if(ll_len(pArrayListPassenger) > 0){
			fprintf(pArchivo,"id_servicio,descripción,tipo,precioUnitario,cantidad,totalServicio\n");
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				servicio = (eServicio*) ll_get(pArrayListPassenger, i);
				if(servicio != NULL){
					servicio_getId(servicio, &id);
					servicio_getDescripcion(servicio, descripcion);
					servicio_getTipo(servicio, &tipo);
					servicio_getPrecioUnitario(servicio, &precioUnitario);
					servicio_getCantidad(servicio, &cantidad);
					servicio_getTotalServicio(servicio, &totalServicio);

					fprintf(pArchivo, "%d,%s,%d,%f,%d,%f\n", id, descripcion, tipo, precioUnitario, cantidad, totalServicio);

					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int sortById(void* pasajero, void* pasajero2){
	int retorno = -1;
	int id;
	int id2;
	if(pasajero != NULL && pasajero2 != NULL){
		if(servicio_getId(pasajero, &id) == 0 && servicio_getId(pasajero2, &id2) == 0){
			if(id > id2){
				retorno = 1;
			} else {
				retorno = -1;
			}

		}
	}
	return retorno;
}

int sortByPriceTotal(void* servicio, void* servicio2){
	int retorno;
	float precio;
	float precio2;
	if(servicio != NULL && servicio2 != NULL){
		if(servicio_getTotalServicio(servicio, &precio) == 0 && servicio_getTotalServicio(servicio2, &precio2) == 0){
			if(precio > precio2){
				retorno = 2;
			} else if(precio < precio2){
				retorno = -1;
			} else {
				retorno = 0;
			}
		}
	}
	return retorno;
}

int sortByDescription(void* servicio, void* servicio2){
	int retorno;
	char descripcion[50];
	char descripcion2[50];
	if(servicio != NULL && servicio2 != NULL){
		if(servicio_getDescripcion(servicio, descripcion) == 0 && servicio_getDescripcion(servicio2, descripcion2) == 0){
			retorno = strcmp(descripcion, descripcion2);
			if(retorno == 0){
				retorno = sortById(servicio, servicio2);
			}
		}
	}
	return retorno;
}

void* calcularPrecioFinal(void* servicio){
	void* retorno = NULL;
	if(servicio != NULL){
		float precioUnidad;
		int cantidad;
		float precioTotal;
    	if(servicio_getPrecioUnitario(servicio, &precioUnidad) == 0 && servicio_getCantidad(servicio, &cantidad) == 0){
    		precioTotal = precioUnidad * cantidad;
    		if(servicio_setTotalServicio(servicio, precioTotal) == 0){
    			retorno = 0;
    		}
    	}
    }
    return retorno;
}

int filtrarTipo1(void* servicio){
    int retorno = -1;
    if(servicio != NULL){
		int tipo;
		if(servicio_getTipo(servicio, &tipo) == 0){
			if(tipo == 1){
				retorno = 0;
			}
		}
    }
    return retorno;
}

int filtrarTipo2(void* servicio){
	int retorno = -1;
    if(servicio != NULL){
		int tipo;
		if(servicio_getTipo(servicio, &tipo) == 0){
			if(tipo == 2){
				retorno = 0;
			}
		}
    }
    return retorno;
}

int filtrarTipo3(void* servicio){
    int retorno = -1;
    if(servicio != NULL){
		int tipo;
		if(servicio_getTipo(servicio, &tipo) == 0){
			if(tipo == 3){
				retorno = 0;
			}
		}
    }
    return retorno;
}
