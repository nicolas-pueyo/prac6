#include <iostream>
#include <string>
#include "nombres-ficheros.hpp"
using namespace std;



/* Pre:  ---
 * Post: Devuelve una ruta de acceso relativa a un fichero de usos partiendo del valor del 
 *       parámetro «opcion», concatenando la ruta relativa de acceso al directorio de datos con
 *       el prefijo común a los ficheros de usos, la opción y la extensión de los fichero de
 *       usos.
 *       Por ejemplo, si «opcion» tiene el valor "16", devuelve la ruta "datos/usos-16.csv".
 *       Si «opcion» tiene el valor "t2", devuelve la ruta "datos/usos-t2.csv".
 */
string construirNombreFicheroUsos(const string opcion) {
string cadena = RUTA_DATOS + PREFIJO_USOS + opcion + EXTENSION;
return cadena;
}