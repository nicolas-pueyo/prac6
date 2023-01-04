/*********************************************************************************************\
 * Programación 1. Trabajo obligatorio
 * Autores: Nicolás Pueyo Soria y Yago Torres García
 * Ultima revisión: ¡¡¡!!!
 * Resumen: Fichero de interfaz «usos-usuario.hpp» de un módulo para trabajar con registros que
 *          permiten contabilizar el número de usos que cada usuario hace del sistema Bizi.
\*********************************************************************************************/

#pragma once 

#include <string>
using namespace std;

struct UsosUsuario {
    string id;
    unsigned traslados;
    unsigned circular;
};


/*
 * Pre:  ---
 * Post: Devuelve el número total de usos del sistema Bizi correspondiente a «usuario».
 */
unsigned numUsosTotales(const UsosUsuario usuario);


/*
 * Pre:  «nombreFicheroUsos» contiene la ruta y nombre de un fichero de texto con información
 *       sobre usos del sistema Bizi Zaragoza y con el formato establecido en el enunciado.
 *       El vector «usuarios» tiene al menos tantas componentes como número de usuarios
 *       distintos aparecen  en el fichero de nombre «nombreFicheroUsos». El valor del
 *       parámetro «numUsuarios» no está definido.
 * Post: Si se puede leer del fichero «nombreFicheroUsos», el vector «usuarios» almacena, en
 *       sus primeras «numUsuarios» componentes, la información relativa a identificadores de
 *       usuario y número de usos (entre estaciones distintas y entre la misma estación)
 *       extraída del fichero «nombreFicheroUsos» de acuerdo con las consideraciones
 *       establecidas en el enunciado. No es necesario que los registros del vector estén
 *       ordenados por ningún criterio en concreto. Devuelve «true» si el fichero puede ser
 *       leído sin problemas y «false» en caso contrario.
 */
bool obtenerUsosPorUsuario(const string nombreFicheroUsos,
                           UsosUsuario usuarios[], unsigned& numUsuarios);

/*
 * Pre:  numUsuarios > 0; numOrdenar > 0
 * Post: El vector usuarios[0..numUsuarios-1] es una permutación de los datos iniciales del
 *       vector, de forma que los «numOrdenar» primeros son los usuarios de mayor número de
 *       usos y están ordenados por número de usos decreciente.
 */
void ordenar(UsosUsuario usuarios[], const unsigned numUsuarios, 
             const unsigned numOrdenar);


void permutar(UsosUsuario& a, UsosUsuario& b);


/*
 * Pre:  La función recibe un nombre válido de fichero
 *
 * Post: La función cuenta el número de usuarios distintos que hay en el fichero que se 
 * ha seleccionado, contando las líneas que hay ignorando la cabecera.
 */
unsigned usuariosDistintos (ifstream& f, string listaUsuarios[]);

