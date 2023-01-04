#include <fstream>
#include <string>
#include "usos-usuario.hpp"

/*
 * Pre:  ---
 * Post: Devuelve el número total de usos del sistema Bizi correspondiente a «usuario».
 */
unsigned numUsosTotales(const UsosUsuario usuario) {
    return usuario.traslados + usuario.circular;
}



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
                           UsosUsuario usuarios[], unsigned& numUsuarios) {
    ifstream f(nombreFicheroUsos);
    if(f.is_open()) {

        string linea;
        string estacionDejada;
        string estacionRecogida;
        UsosUsuario ejemplo;
        numUsuarios = 1;
        getline(f,linea);
        while(getline(f,ejemplo.id,';')) {
            getline(f,linea,';');
            getline(f,estacionRecogida,';');
            getline(f,linea,';');
            getline(f,estacionDejada);
            unsigned i = 0;
            bool encontrado = false;
            while(i<numUsuarios && !encontrado) {
                if(usuarios[i].id == ejemplo.id) {
                    encontrado = true;
                }
                i++;
            }
            if(!encontrado) {
                usuarios[i].id = ejemplo.id;
                numUsuarios++;
            }
            if(estacionDejada == estacionRecogida) {
                usuarios[i].circular++;
            }
            else {usuarios[i].traslados++;}
        }
        f.close();
        return true;
    }
    else {return false;}
}



void permutar(UsosUsuario& a, UsosUsuario& b) {
    UsosUsuario auxiliar;
    auxiliar = b;
    b = a;
    a = auxiliar;
}

/*
 * Pre:  numUsuarios > 0; numOrdenar > 0
 * Post: El vector usuarios[0..numUsuarios-1] es una permutación de los datos iniciales del
 *       vector, de forma que los «numOrdenar» primeros son los usuarios de mayor número de
 *       usos y están ordenados por número de usos decreciente.
 */
void ordenar(UsosUsuario usuarios[], const unsigned numUsuarios, 
             const unsigned numOrdenar) {
    for(unsigned i = 0; i < numOrdenar-1; i++) {
        unsigned iMayor = i;
        for(unsigned j = i+1; j < numUsuarios; j++) {
            if(numUsosTotales(usuarios[j]) > numUsosTotales(usuarios[iMayor])) {
                iMayor = j;
            }
        }
        permutar(usuarios[i], usuarios[iMayor]);
    }
}