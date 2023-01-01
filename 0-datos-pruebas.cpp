/*
* Programa que, a partir de los ficheros "usos" ubicados en el directorio datos,
* crea dos ficheros más pequeños y manejables con 10 o 2000 líneas según qué
* fichero sea el que se quiere simplificar.
* Autor/es: Nicolás Pueyo Soria y Yago Torres García
* Última fecha acceso: 12/12/2022
*/

#include <string>
#include <fstream>
#include <iostream>
using namespace std;


//Pre: ---
//Post: Crea un fichero en el cual se ha reducido el numero de lineas del original, a 10 en el caso de 2016 y 2000 en el caso de 2017.
bool crearTests(const string ficheroEntrada, const string ficheroSalida) {
    //1. Asociar el flujo de entrada con el fichero
    ifstream e(ficheroEntrada);
    //2. Comprobar que está bien abierto
    if (e.is_open()) {
        //2.1 Hacer cosas
            string linea;
            //Abrir el flujo de salida
            ofstream s(ficheroSalida);
            //comprobar que está bien abierto
            if (s.is_open()) {
                if(ficheroEntrada == "datos/usos-16.csv") {
                 for(unsigned i = 0; i < 10; i++) {
                    getline(e, linea);
                    s << linea << endl;
                }
                }
                else {
                for(unsigned i = 0; i < 2000; i++) {
                    getline(e, linea);
                    s << linea << endl;
                }
                }
                //Cerrar el flujo
                s.close();
            } else {
                cerr << "ERROR al abrir el fichero \"" << ficheroSalida << "\"." << endl;
                return false;
            }
        //2.2 Cerrar el fichero
        e.close();
        return true;
    }
    else {
        cerr << "ERROR al abrir el fichero \""<<ficheroEntrada<<"\"." << endl;
        return false;
    }
}

int main() {
    crearTests("datos/usos-16.csv", "datos/usos-t1.csv");
    crearTests("datos/usos-17.csv", "datos/usos-t2.csv");
    return 0;
}