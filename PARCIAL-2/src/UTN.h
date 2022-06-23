/*
 * UTN.h
 *
 *  Created on: 21 abr. 2022
 *      Author: Rivoira
 */

#ifndef UTN_H_
#define UTN_H_


#endif /* UTN_H_ */

/**
 * @param ARRAY A INICIALIZAR
 * @param TAMAÑO DEL ARRAY
 * @return 0 = BIEN | -1 = NO SE PUDO EJECUTAR
 */
int inicializarArray(int array[], int tam, int inicializador);

/**
 * @param ARRAY A MOSTRAR
 * @param TAMAÑO DEL ARRAY
 * @return 0 = BIEN | -1 = NO SE PUDO EJECUTAR
 */
int mostrarArray(int array[], int tam);

/**
 *
 * @param ARRAY A MOSTRAR
 * @param TAMAÑO DEL ARRAY
 * @return 0 = BIEN | -1 = NO SE PUDO EJECUTAR
 *
 */
int mostrarParesArray(int array[], int tam);

int llenarString(char array[], char texto[]);

int llenarInt(int* variable, char texto[], char textoError[], int maximo, int minimo);

float llenarFloat(float* variable, char texto[], char textoError[], int maximo, int minimo);

char deseaContinuar();
