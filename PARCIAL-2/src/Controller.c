#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "UTN.h"
#include "parser.h"
#include "eServicios.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* this){
	int retorno = -1;
		if(this != NULL && path != NULL){
			FILE* pArchivo;
			pArchivo = fopen (path, "r");
			if(pArchivo != NULL){
				if(parser_PassengerFromText(pArchivo, this) == 0){
					retorno = 0;
				}
			}
			fclose(pArchivo);
		}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* this){
	int retorno = -1;
	if(this != NULL && path != NULL){
		FILE* pArchivo;
		pArchivo = fopen (path, "w");
		if(pArchivo != NULL){
			retorno = saveAsText(pArchivo, this);
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListService(LinkedList* this){
	int retorno = -1;
	if(this != NULL){
		eServicio* servicio;
		printf("╔════╦════════════════════════════════╦════════════╦═════════════╦═══════╦════════════════╗\n");
		for(int i = 0; i < ll_len(this); i++){
			servicio = (eServicio*) ll_get(this, i);
			retorno = servicio_printOne(servicio);
		}
	}
    return retorno;
}

int controller_AsingTotales(LinkedList* this){
	int retorno = -1;
	if(this != NULL){
		eServicio* servicio;
		for(int i = 0; i < ll_len(this);i++){
			servicio = (eServicio*) ll_get(this, i);
			ll_map(this, calcularPrecioFinal(servicio));
			retorno = 0;
		}
	}
	return retorno;
}

LinkedList* controller_Filter(LinkedList* this){
	LinkedList* retorno = NULL;
	if(this != NULL){
		int option;
		llenarInt(&option,"\n ▂▂▂▂▃▃▅▅▆▆█ MENU FILTRADOR █▆▆▅▅▃▃▂▂▂▂\n"
						  "  1- Filtrar minoristas\n"
						  "  2- Filtrar mayorista.\n"
						  "  3- Filtrar exportar.\n"
						  "  4- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 4, 1);
		switch(option){
			case 1:
				retorno = ll_filter(this, filtrarTipo1);
				break;
			case 2:
				retorno = ll_filter(this, filtrarTipo2);
				break;
			case 3:
				retorno = ll_filter(this, filtrarTipo3);
				break;
			case 4:
				retorno = 0;
				break;
		}
	}
	return retorno;
}

LinkedList* controller_MostrarServicios(LinkedList* this){
	LinkedList* listAux = NULL;
	if(this != NULL){
		listAux = ll_clone(this);
		int sentido;
		if(listAux != NULL){
			llenarInt(&sentido, "Ingrese 1- PARA CRECIENTE, 0- DECRECIENTE", "ERROR, opcion no valida, vuelva a intentarlo ب(ﾉ◕╭╮◕),)", 1, 0);
			if(ll_sort(listAux, sortByDescription, sentido) == 0){
				controller_ListService(listAux);
			}
		}
	}
	return listAux;
}

