/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_

#include "LinkedList.h"

typedef struct{
	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
} eServicio;

eServicio* servicios_new();
eServicio* servicio_newParametros(char* idStr, char* descripcion,char* tipo, char* precioUnitario, char* cantidad, char* totalServicios);

int servicio_setId(eServicio* this,int id);
int servicio_getId(eServicio* this,int* id);
int servicio_getLastId(LinkedList* this,int* id);

int servicio_setDescripcion(eServicio* this,char* descripcion);
int servicio_getDescripcion(eServicio* this,char* descripcion);

int servicio_setTipo(eServicio* this, int tipo);
int servicio_getTipo(eServicio* this, int* tipo);

int servicio_setPrecioUnitario(eServicio* this,float precio);
int servicio_getPrecioUnitario(eServicio* this,float* precio);

int servicio_setCantidad(eServicio* this, int cantidad);
int servicio_getCantidad(eServicio* this, int* cantidad);

int servicio_setTotalServicio(eServicio* this,float precioFinal);
int servicio_getTotalServicio(eServicio* this,float* precioFinal);

int servicio_printOne(eServicio* this);
void printservicio(eServicio* servicio);

int saveAsText(FILE* pArchivo, LinkedList* pArrayListPassenger);
int saveAsBinary(FILE* pArchivo, LinkedList* pArrayListPassenger);

int sortById(void* servicio, void* servicio2);
int sortByPriceTotal(void* servicio, void* servicio2);
int sortByDescription(void* servicio, void* servicio2);

void* calcularPrecioFinal(void* servicio);

int filtrarTipo1(void* servicio);
int filtrarTipo2(void* servicio);
int filtrarTipo3(void* servicio);
#endif /* ESERVICIOS_H_ */
