#include "uso.hpp"
#include <fstream>
#include <string>



/*
 * Pre:  El flujo «f» está asociado con un fichero de texto con el formato de usos del sistema
 *       Bizi establecido en el enunciado y en disposición de leer desde el principio de una
 *       línea distinta a la de la cabecera.
 * Post: Intenta leer la línea mencionada en la precondición y, si esta línea existe, almacena
 *       en los campos del parámetro «uso» el identificador del usuario al que corresponde el
 *       uso Bizi de la línea leída y los códigos de las estaciones de retirada y devolución de
 *       la bicicleta. Devuelve «true» si no se han terminado los datos del fichero en el
 *       intento de lectura descrito y y «false» en caso contrario.
 */
bool leerUso(istream& f, UsoBizi& uso) {
    string linea;
    if(getline(f,uso.userID,';')) {
        getline(f, linea, ';');
        getline(f,uso.estacionRecogida,';');
        getline(f, linea, ';');
        getline(f,uso.estacionDejada);
        if(uso.estacionRecogida == uso.estacionDejada) {
            uso.circular = true;
        }
        else {uso.circular = false;}
        return true;
    }
    else {
        return false;
    }

}



/*
 * Pre:  La cadena de caracteres «nombreFicheroUsos» representa la ruta de acceso y el nombre
 *       de un fichero de texto con el formato de usos del sistema Bizi establecido en el
 *       enunciado.
 * Post: Si el fichero de nombre «nombreFicheroUsos» se puede abrir y leer correctamente,
 *       «traslados» es el número de usos entre estaciones distintas del sistema Bizi Zaragoza
 *       contenidos en el fichero de nombre «nombreFicheroUsos» y «usosCirculares» es el número
 *       de usos contenidos en dicho fichero que tienen como origen y destino la misma 
 *      estación.  En ese caso, devuelve «true» y en el caso contrario, «false».
 */
bool contarUsos(const string nombreFicheroUsos, unsigned& traslados, unsigned& usosCirculares) {
    string linea;
    ifstream f(nombreFicheroUsos);
    if(f.is_open()) {
        getline(f, linea);
        UsoBizi uso;
        while(leerUso(f, uso)) {
            if(uso.circular) {
                usosCirculares++;
            }
            else {
                traslados++;
            }

        }
        f.close();
        return true;
    }
    else {
        return false;
    }
}