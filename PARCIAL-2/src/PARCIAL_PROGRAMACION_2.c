/*
 ============================================================================
 Name        : PARCIAL_PROGRAMACION_2.c
 Author      : Matias Rivoira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"
#include "LinkedList.h"
#include "Controller.h"


int main(void) {
	setbuf(stdout, NULL);
	int option;
	int optionAux;
	char nombreArchivo[50];

	int serviciosCargados = 0;
	int serviciosActuales = 0;

	int guardo = 0;
	int filtro = 0;

	LinkedList* listaServicios = ll_newLinkedList();
	LinkedList* listaServiciosFiltrados = NULL;
	LinkedList* listaServiciosOrdenados = NULL;
	do{
		llenarInt(&option,"\n ▂▂▂▂▃▃▅▅▆▆█ MENU PRINCIPAL █▆▆▅▅▃▃▂▂▂▂\n"
							"  1- Cargar archivo\n"
							"  2- Imprimir lista.\n"
							"  3- Asignar totales.\n"
							"  4- Filtrar por tipo.\n"
							"  5- Mostrar servicios.\n"
							"  6- Guardar servicios.\n"
							"  7- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 7, 1);
		switch(option){
			case 1:
				llenarString(nombreArchivo, "Ingrese el nombre del archivo: ");
				if(controller_loadFromText(nombreArchivo, listaServicios) == 0){
					serviciosCargados = ll_len(listaServicios);
					serviciosCargados = serviciosCargados - serviciosActuales;
					guardo = -1;
					printf("\n %d servicios cargados exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
					system("pause");
				} else {
					printf("\n ERROR, no se pudo cargar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
					system("pause");
				}
				break;
			case 2:
				if(filtro == 0){
					if(controller_ListService(listaServicios) == 0){
						system("pause");
					} else{
						printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
						system("pause");
					}
				} else {
					do{
						llenarInt(&optionAux,"\n ▂▂▂▂▃▃▅▅▆▆█ MENU LISTADOR █▆▆▅▅▃▃▂▂▂▂\n"
										  "  1- Mostrar toda la lista \n"
										  "  2- Mostrar lista filtrada.\n"
								 	 	  "  3- Mostrar lista ordenada.\n"
										  "  4- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 4, 1);
						switch(optionAux){
							case 1:
								if(controller_ListService(listaServicios) == 0){
									system("pause");
								} else {
									printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 2:
								if(controller_ListService(listaServiciosFiltrados) == 0){
									system("pause");
								} else {
									printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 3:
								if(listaServiciosOrdenados != NULL){
									if(controller_ListService(listaServiciosOrdenados) == 0){
										system("pause");
									} else {
										printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
										system("pause");
									}
								} else {
									printf("\n ERROR, primero ordene una LinkedList vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
						}
					}while(optionAux != 4);
				}
				break;
			case 3:
				if(filtro == 0){
					if(controller_AsingTotales(listaServicios) == 0){
						printf("\n %d Asignaciones totales cargadas exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
						system("pause");
					} else {
						printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
						system("pause");
					}
				} else {
					do{
						llenarInt(&optionAux,"\n ▂▂▂▂▃▃▅▅▆▆█ MENU ASIGNADOR █▆▆▅▅▃▃▂▂▂▂\n"
										  "  1- Asignar toda la lista \n"
										  "  2- Asignar lista filtrada.\n"
										  "  3- Asignar lista ordenada.\n"
										  "  4- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 4, 1);
						switch(optionAux){
							case 1:
								if(controller_AsingTotales(listaServicios) == 0){
									printf("\n %d Asignaciones totales cargadas exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
									system("pause");
								} else {
									printf("\n ERROR, no se pudo asignar los totales de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 2:
								if(controller_AsingTotales(listaServiciosFiltrados) == 0){
									printf("\n %d Asignaciones totales cargadas exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
									system("pause");
								} else {
									printf("\n ERROR, no se pudo asignar los totales de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 3:
								if(listaServiciosOrdenados != NULL){
									if(controller_AsingTotales(listaServiciosOrdenados) == 0){
										printf("\n %d Asignaciones totales cargadas exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
										system("pause");
									} else {
										printf("\n ERROR, no se pudo asignar los totales de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
										system("pause");
									}
								} else {
									printf("\n ERROR, primero ordene una LinkedList vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
						}
					}while(optionAux != 4);
				}
				break;
			case 4:
				listaServiciosFiltrados = controller_Filter(listaServicios);
				if(listaServiciosFiltrados != NULL){
					printf("\n Servicios filtrados exitosamente (ɔ◔‿◔)ɔ ♥, ");
					filtro = 1;
					system("pause");
				} else {
					printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
					system("pause");
				}
				break;
			case 5:
				if(filtro == 0){
					if(controller_MostrarServicios(listaServicios) == 0){
						system("pause");
					} else {
						printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
						system("pause");
					}
				} else {
						llenarInt(&optionAux,"\n ▂▂▂▂▃▃▅▅▆▆█ MENU ORDENADOR █▆▆▅▅▃▃▂▂▂▂\n"
										  "  1- Ordenar servicios de toda la lista \n"
										  "  2- Ordenar servicios de la lista filtrada.\n"
										  "  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 4, 1);
						switch(optionAux){
							case 1:
								listaServiciosOrdenados = controller_MostrarServicios(listaServicios);
								if(listaServiciosOrdenados != NULL){
									system("pause");
								} else {
									printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 2:
								listaServiciosOrdenados = controller_MostrarServicios(listaServiciosFiltrados);
								if(listaServiciosOrdenados != NULL){
									system("pause");
								} else {
									printf("\n ERROR, no se pudo listar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
						}
				}
				break;
			case 6:
				if(filtro == 0){
					if(controller_saveAsText("data.csv", listaServicios)){
						printf("\n %d Guardado exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
						guardo = 0;
						system("pause");
						guardo = 1;
					} else {
						printf("\n ERROR, no se pudo guardar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
						system("pause");
					}
				} else {
					llenarInt(&optionAux,"\n ▂▂▂▂▃▃▅▅▆▆█ MENU GUARDADOR █▆▆▅▅▃▃▂▂▂▂\n"
									  "  1- Guardar servicios de toda la lista \n"
									  "  2- Guardar servicios de la lista filtrada.\n"
									  "  3- Guardar lista ordenada.\n"
									  "  4- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 4, 1);
					switch(optionAux){
						case 1:
							if(controller_saveAsText("data.csv", listaServicios) == 0){
								printf("\n %d Guardado exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
								guardo = 0;
								system("pause");
							} else {
								printf("\n ERROR, no se pudo guardar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_saveAsText("dataFiltrada.csv",listaServiciosFiltrados) == 0){
								printf("\n %d Guardado exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
								guardo = 0;
								system("pause");
							} else {
								printf("\n ERROR, no se pudo guardar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 3:
							if(listaServiciosOrdenados != NULL){
								if(controller_saveAsText("data.csv",listaServiciosOrdenados) == 0){
									printf("\n %d Guardado exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
									guardo = 0;
									system("pause");
								} else {
									printf("\n ERROR, no se pudo guardar los totales de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
							} else {
								printf("\n ERROR, primero ordene una LinkedList vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}
				break;
		}
		if(guardo == -1 && option == 7){
			 llenarInt(&option,"\nEsta intentando salir sin guardar, ¿Desea guardar los cambios? \n"
								 "╔═════════════╦═══════════════╦═════════════╗\n"
								 "║ 1 = GUARDAR ║ 2= NO GUARDAR ║ 3= CANCELAR ║\n"
								 "╚═════════════╩═══════════════╩═════════════╝\n", "ERROR, Opcion no valida, vuelva a intentarlo, ", 3, 1);
			 switch(option){
				 case 1:
					do{
						llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU GUARDAR █▆▆▅▅▃▃▂▂▂\n"
											"  1- Guardar en lista.\n"
											"  2- Guardar en lista filtrada.\n"
											"  3- Guardar en lista ordenada.\n"
											"  4- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 4, 1);
						switch(optionAux){
							case 1:
								if(controller_saveAsText("data.csv",listaServicios) == 0){
									guardo = 0;
									printf("\n %d servicios guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
									system("pause");
								} else {
									printf("\n ERROR, no se pudo guardar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 2:
								if(controller_saveAsText("dataFiltrada.csv",listaServiciosFiltrados) == 0){
									guardo = 0;
									printf("\n %d servicios guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
									system("pause");
								} else {
									printf("\n ERROR, no se pudo guardar los datos de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 3:
								if(listaServiciosOrdenados != NULL){
									if(controller_saveAsText("data.csv",listaServiciosOrdenados) == 0){
										printf("\n %d Guardado exitosamente (ɔ◔‿◔)ɔ ♥, ", serviciosCargados);
										guardo = 0;
										system("pause");
									} else {
										printf("\n ERROR, no se pudo guardar los totales de los servicios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
										system("pause");
									}
								} else {
									printf("\n ERROR, primero ordene una LinkedList vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
						}
					}while(optionAux != 3);
					break;
				 case 2:
					 guardo = 0;
					 option = 7;
					 break;
				 }
			}
	}while(option != 7 || guardo == -1);
	return EXIT_SUCCESS;
}
