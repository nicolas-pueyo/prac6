/*********************************************************************************************\
 * Programación 1. Trabajo obligatorio
 * Autores: Nicolás Pueyo Soria y Yago Torres García
 * Ultima revisión: ¡¡¡!!!
 * Resumen: Fichero de implementación del módulo principal que implementa el trabajo
 *          obligatorio de Programación 1 del curso 2022-23.
\*********************************************************************************************/
#include <fstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include "nombres-ficheros.hpp"
#include "uso.hpp"
#include "usuarios.hpp"
#include "usos-usuario.hpp"
using namespace std;


/*
* Pre: --
*
* Post: El procedimiento se encarga de mostrar que opciones tiene disponible el usuario para 
* la selección de el fichero con el que trabajará
*/
void mostrarOpciones() {
    cout << "Elección de ficheros de usos y usuarios. Opciones disponibles: " << endl;
    //vamos a copiar el contenido del fichero "opciones.txt" mediante flujos
    //abrimos el flujo
    ifstream fich("res/opciones.txt");
        //comprobamos que esta bien abierto
        if(fich.is_open()) {
            //Escribimos el contenido en pantalla
            string linea;
            while(getline(fich, linea)) {
            cout << linea << endl;
            }
        //Cerramos el flujo
        fich.close();    
        }
        //Si no se abre bien, damos un mensaje de error
        else {
            cout << "No se ha podido abrir el fichero opciones.txt";
        }
}


/*
* Pre: --
*
* Post: La función se encarga de pedir una opción al usuario sobre el fichero que quiere abrir, 
* y tras esto comprueba si este existe y se puede abrir. En caso contrario, repetira la petición
* hasta recibir un fichero válido
*/
string opcionElegida () {
    string opcion;
    cout << "Elija una opción: "; 
    // guarda la opción que nos ha dado el usuario
    cin >> opcion;
    // abre un flujo con la opción que el usuario ha dado
    ifstream fichero(construirNombreFicheroUsos(opcion));
    // comprueba si el fichero se ha abierto, y en otro caso, vuelve a pedirlo hasta que se
    // de un fichero correcto
    if (fichero.is_open()) {
        cout << "El fichero " << "\"" << construirNombreFicheroUsos(opcion) << "\"" << " existe y ha sido seleccionado" << endl << endl;
        fichero.close();
    }
    else {
        while (!fichero.is_open()) {
            // da un mensaje de error
            cerr << "No se ha podido abrir el fichero " << "\"" + construirNombreFicheroUsos(opcion) + "\"" << endl << endl;
            // vuelve a mostrar el menu, y a pedir una opcion
            mostrarOpciones();
            cout << "Elija una opción: ";
            cin >> opcion;
            ifstream fichero(construirNombreFicheroUsos(opcion));
        }
    }
    return construirNombreFicheroUsos(opcion);
}

/*
* Pre: --
*
* Post: El procedimiento se encarga de mostrar el menu que se encuentra en ayuda/txt, y dar
* un mensaje de error en caso de que este no se pueda abrir
*/
void escribirMenuAcciones() {
    ifstream menu("res/ayuda.txt");
        //comprobamos que esta bien abierto
        if(menu.is_open()) {
            //Escribimos el contenido en pantalla
            string linea;
            while(getline(menu, linea)) {
            cout << linea << endl;
            }
        //Cerramos el flujo
        menu.close();    
        }
        //Si no se abre bien, damos un mensaje de error
        else {
            cout << "No se ha podido abrir el fichero menu.txt";
        }
}


/*
*Pre: "nombreFichero" es un nombre valido de fichero
*Post: devuelve el numero de lineas de ese fichero, sin contar la inicial
*/
bool contarLineas(const string nombreFichero, unsigned& cuenta) {
    ifstream f(nombreFichero);
    if(f.is_open()) {
    string linea;
    cuenta = 0;
    while(getline(f,linea)) {
        cuenta++;
    }
    f.close();
    return true;
    }
    else {return false;}
}
/*
* Pre: --
*
* Post: El procedimiento se encarga de recibir la opción, tanto si tiene un solo dato como si 
* es de las que cuentan con una segunda entrada. También transforma el primer dato recibido
* a un formato general, para el correcto funcionamiento posterior del programa
*/
void elegirOrdenMenu(string& opcionMenu, unsigned& dato) {
    for(unsigned i = 0; i < opcionMenu.length(); i++) {
        // recibe el dato como un vector de chars, en vez de como string, para convertirlo a upper
        opcionMenu.at(i) = toupper(opcionMenu.at(i));
    }
    // en el caso de que el primer dato sea uno de estos, habrá un segundo campo que recibir 
    if(opcionMenu == "USUARIO" || opcionMenu == "MAYORES" || opcionMenu == "INFORME") {
        cin >> dato;
    }
}



void ejecutarOpcionMenu(string opcion, unsigned dato, string& ficheroSel) {
    if (opcion == "AYUDA") {
        escribirMenuAcciones();   
    }
    else if (opcion == "FICHERO") {
        mostrarOpciones();
        ficheroSel = opcionElegida();
    }
    else if (opcion == "USOS") {
        unsigned usosCirculares = 0, traslados = 0;
        if(contarUsos(ficheroSel, traslados, usosCirculares)) {
            cout << "Fichero de usos seleccionado actualmente: " << ficheroSel << endl;
            cout << "Numero de traslados: " << traslados << endl;
            cout << "Numero de usos circulares: " << usosCirculares << endl;
            cout << "Numero de usos totales: " << traslados + usosCirculares << endl;
        }


    }
    else if (opcion == "ESTADISTICAS") {
        unsigned estadisticas[NUM_EDADES][NUM_GENEROS];
        //inicializacion de la matriz a 0
        for (unsigned i = 0; i < NUM_EDADES; i++) {
            for (unsigned j = 0; j < NUM_GENEROS; j++) {
                estadisticas[i][j] = 0;
            }
        }
        obtenerEstadisticas("datos/usuarios.csv", estadisticas);
        cout  << right << setw(7) << "|" << setw(7) << "M" << setw(7) << "F" << endl;
        cout << "------+--------------" << endl;
        for (unsigned i = 0; i < NUM_EDADES; i++) {
            cout << setw(6) << left << RANGO_EDADES[i] << "|"; // escribe la cabecera de cada fila recorriendo el vector de edades
            for(unsigned j = 0; j < NUM_GENEROS; j++) {
                cout << setw(7) << right << estadisticas[i][j];
            }
            cout << endl;
        }
    }
    else if (opcion == "USUARIO") {
        string edad, genero;
        if(buscarUsuario("datos/usuarios.csv", dato, genero, edad)) {
            if(genero == "") {
                cout << "El/la usuario/a ";
            }
            else if(genero == "M") {
                cout << "El usuario ";
            }
            else {
                cout << "La usuaria ";
            }
            cout << dato << " esta en el rango de edad \"" << edad << "\"." << endl;
        }
        else {
            cout << "El/la usuario/a " << dato << " no aparece en el fichero \"datos/usuarios.csv\"." << endl;
        
        }
    } 
    else if (opcion == "MAYORES") {
        unsigned lineas = 0;
        contarLineas("datos/usuarios.csv",lineas);
        UsosUsuario usuarios[lineas];
        for (unsigned i = 0; i < lineas-1; i++) {
            usuarios[i].id = "";
            usuarios[i].traslados = 0;
            usuarios[i].circular = 0;
        }
        unsigned numUsuarios;
        obtenerUsosPorUsuario(ficheroSel,usuarios, numUsuarios);
        ordenar(usuarios, numUsuarios, dato+1);
        ifstream f(ficheroSel);
        f.close();
        cout << "Numero de usuarios distintos: " << numUsuarios-1 << endl;
        cout << right << setw(10) << "Usuario" 
             << setw(10) << "Traslados" 
             << setw(10) << "Circular" 
             << setw(10) << "Total" 
             << endl;
        for (unsigned i = 0; i < 4; i++) {
            cout << setw(10) << " =========";
        }
        cout << endl;
        for(unsigned i = 0; i < dato; i++) {
            cout << setw(10) << usuarios[i].id 
                 << setw(10)<< usuarios[i].traslados 
                 << setw(10) << usuarios[i].circular 
                 << setw(10) << numUsosTotales(usuarios[i]) 
                 << endl;
        }
    }
    else if (opcion == "INFORME") {
        
    }
    else if (opcion == "DESTINOS") {
        //ejecutarDESTINOS(dato);
    }
    else if (opcion == "FIN");
    else {
        cerr << "Orden desconocida";
    }
}


/*
 * Programa que se encarga de pedir al usuario el fichero con el que desea trabajar, y muestra
 * un menú de opciones con las que el usuario podrá interactuar
 *
 */
int main(){
    string opcionDelMenuUsada, opcionMenu = "", ficheroSel;
    unsigned dato;
    mostrarOpciones();
    ficheroSel = opcionElegida();
    escribirMenuAcciones();
    while (opcionMenu != "FIN") {
        cout << endl << "Orden: ";
        cin >> opcionMenu;
        elegirOrdenMenu(opcionMenu, dato);
        ejecutarOpcionMenu(opcionMenu, dato, ficheroSel);
    }
    
    return 0;
}
