#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eServicios.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
	int retorno = -1;
		if(pFile != NULL && pArrayListPassenger != NULL){
			eServicio* newServicio;

			int id;
			char idStr[10];
			char *idptr;
			char descripcion[50];
			char tipoStr[10];
			char precioUnitarioStr[30];
			char cantidadStr[10];
			char totalServicioStr[20];

			int tam = ll_len(pArrayListPassenger);

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, descripcion, tipoStr, precioUnitarioStr, cantidadStr, totalServicioStr);

			while(1){
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, descripcion, tipoStr, precioUnitarioStr, cantidadStr, totalServicioStr) == 6){
					if(tam > 0){
						id = strtol(idStr,&idptr, 10);
						id = id + tam;
						itoa(id, idStr, 10);
					}
					newServicio = servicio_newParametros(idStr, descripcion, tipoStr, precioUnitarioStr, cantidadStr, totalServicioStr);
					if(newServicio != NULL){
						ll_add(pArrayListPassenger, newServicio);
						retorno = 0;
					}
				}
				if(feof(pFile) != 0){
					break;
				}
			}
		}
	return retorno;
}
