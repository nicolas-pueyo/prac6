/*
#include <istream>
#include <string>
/*
 * Pre:  La cadena de caracteres «nombreFicheroEstaciones» contiene la ruta de acceso y nombre
 *       de un fichero de estaciones Bizi que sigue la sintaxis de la regla
 *       <fichero-estaciones> establecida en el enunciado y que contiene información de
 *       «NUM_ESTACIONES» estaciones.
 *       El vector «estaciones» tiene «NUM_ESTACIONES» componentes.
 * Post: Si el fichero «nombreFicheroEstaciones» y se puede leer de él, la función devuelve
 *       «true» y lee los datos de las estaciones Bizi contenidos en el fichero indicado por
 *       «nombreFicheroEstaciones» y se han almacenado en el vector «estaciones» de forma tal
 *       que en cada componente «i» se almacena el identificador y el nombre de la estación de
 *       identificador «i» + 1 (es decir, en estaciones[0] se encuentra almacenada la
 *       información de la estación con identificador 1, en estaciones[1] se encuentra
 *       almacenada la estación con identificador 2 y así sucesivamente). La información sobre
 *       el número de usos de cada estación es 0 en todas ellas. Si no se puede leer el
 *       fichero «nombreFicheroEstaciones», se limita a devolver «false».
 */

bool leerEstaciones(const string nombreFicheroEstaciones, Estacion estaciones[]) {
    bool ok = false;
    ifstring f(nombreFicheroEstaciones);
    f.open();
    // compruebo que esté abierto
    if f.is_open() {
        // bool que devolveré ya que he podido abrirlo
        ok = true;
        string linea;
        getline(f, linea);
        unsigned i = 0;
        while (getline(f, linea, ';')) {
            estaciones[i].id = linea;
            getline(f, linea, ';')
            getline(f, linea, ';')
            estaciones[i].name = linea;
            estaciones[i].usos = 0;
            getline(f, linea);
            i++;
        }
    }
return ok;
}


/*
 * Pre:  La cadena «nombreFicheroUsos» representa la ruta de acceso y el nombre de un
 *       fichero de texto con el formato de usos del sistema Bizi establecido en el enunciado.
 *       El vector «estaciones» tiene «NUM_ESTACIONES» componentes que almacenan información
 *       sobre estaciones Bizi de forma tal que en cada componente «i» se almacena la
 *       información de la estación de identificador «i» + 1 (es decir, en estaciones[0] se
 *       encuentra almacenada la información de la estación con identificador 1, en
 *       estaciones[1] se encuentra almacenada la estación con identificador 2 y así
 *       sucesivamente). La información sobre el número de usos de cada estación es 0 en todas
 *       ellas.
 * Post: Si no hay problemas de lectura del fichero «nombreFicheroUsos», la función devuelve
 *       «true» y actualiza el número de usos de cada estación del vector «estaciones» de
 *       acuerdo con el contenido del fichero «nombreFicheroUsos», contabilizando como un uso
 *       tanto la retirada como la devolución de bicicletas. En caso contrario, se limita a
 *       devolver «false».
 */
bool contarUsosEstaciones(const string nombreFicheroUsos, Estacion estaciones[]) {
    bool ok = false;
    ifstring f(nombreFicheroUsos);
    f.open();
    // compruebo que esté abierto
    if f.is_open() {
        // bool que devolveré ya que he podido abrirlo
        ok = true;
        getline(f, linea);
        unsigned i = 0;
        while (getline(f, linea, ';')) {
            estaciones[i].id = linea;
            getline(f, linea, ';')
            getline(f, linea, ';')
            estaciones[i].name = linea;
            estaciones[i].usos = 0;
            getline(f, linea);
            i++;
        }
    
    
    
    }
}