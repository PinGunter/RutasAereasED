/**
 * @file test.cpp
 * @brief archivo para probar los métodos de las clases @e Punto @e Ruta y @e Almacen_Rutas
 * @author Salvador Romero Cortés
 * @author Abel Ríos González
 */

#include <iostream>
#include <fstream>
#include <Almacen_Rutas.h>  //incluye a Ruta y Punto
using namespace std;

int main(int argc, char *argv[]){

                                                        /* CLASE PUNTO */
    cout << endl << "==== CLASE PUNTO ==== " << endl << endl;
    // CONSTRUCTORES
    Punto p1;
    Punto p2(1,2);
    Punto p3(p2);
    Punto p4;

    // Aqui se prueba tambien los getters
    cout << "P1: (" << p1.getLongitud() << "," << p1.getLatitud() << ")" <<endl;
    cout << "P2: (" << p2.getLongitud() << "," << p2.getLatitud() << ")" << endl;    
    cout << "P3: (" << p3.getLongitud() << "," << p3.getLatitud() << ")" <<endl;

    // Probamos los setters
    p1.setLongitud(0);      p1.setLatitud(423);
    p2.setLongitud(0);      p2.setLatitud(423);
    p3.setLongitud(2.456);  p3.setLatitud(0.234);

    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;
    cout << "P3: " << p3 << endl;
    Punto puntos[3] = {p1,p2,p3};
    // Probamos operador de igualdad

    for (int i=1; i <= 3; i++){
        for (int j=i+1; j <= 3; j++){
            if(i != j){
                cout << "P" << i << " y " << "P" << j << " son " << ((puntos[i-1] == puntos[j-1]) ? "iguales " : "distintos") << endl;
            }
        }
    }

    //operadores de flujo
    // cout << "Inserta un punto con la sintaxis (x,y) : ";
    // cin >> p4;
    // cout << "El punto insertado es " << p4 << endl;

                                                            /* CLASE RUTA */
                                                            
    cout << endl << "==== CLASE RUTA ==== " << endl << endl;
    // CONSTRUCTORES
    Ruta r1; //nombre vacio
    Ruta r2("Barcelona-Roma"); //nombre: Ruta 2
    r2.insertarPunto(p1); r2.insertarPunto(p3); r2.insertarPunto(Punto(123.455, 12.324)); //aqui se prueba tambien el metodo insertarPunto
    Ruta r3(r2);
    Ruta r4;
    
    // Operador de asignacion
    r3 = r2;
    // Operador de salida
    cout << "R1: " << endl << r1 << endl; // vacio
    cout << "R2: " << endl << r2 << endl;
    cout << "R3: " << endl << r3 << endl;
    // Operador de igualdad ==
    Ruta rutas [] ={r1, r2, r3};
    for (int i=1; i <= 3; i++){
        for (int j=i+1; j <= 3; j++){
            if(i != j){
                cout << "R" << i << " y " << "R" << j << " son " << ((rutas[i-1] == rutas[j-1]) ? "iguales " : "distintos") << endl;
            }
        }
    }
    // Metodo setnombre y getnombre
    cout << "Nombre de la ruta r2: " << r2.getNombre() << endl;
    r2.setNombre("Madrid-Kampala");
    cout << "Nuevo nombre de r2: " << r2.getNombre() << endl;
    
    //metodo eliminarpunto
    cout << "Borramos el segundo punto de la ruta 3.\nRuta actual: " << r3;
    r3.eliminarPunto(p2);
    cout << "\nCon el punto borrado: " << r3 << endl;

    if(r1 == "Barcelona-Roma"){
        cout << "r1 sí es la ruta Barcelona-Roma" << endl;
    }
    else{
        cout << "r1 no es la ruta Barcelona-Roma" << endl;
    }
    
    if(r2 == "Barcelona-Roma"){
        cout << "r2 sí es la ruta Barcelona-Roma" << endl;
    }
    else{
        cout << "r2 no es la ruta Barcelona-Roma" << endl;
    }

    // operadores de flujo
    // abrimos un txt con una ruta y lo sacamos por pantalla
    ifstream archivo_rutas("datos/prueba_ruta.txt");
    archivo_rutas >> r4;
    cout << "Ruta leída:" << endl;
    cout << r4 << endl;

    /* Iteradores: los metodos se usan en la clase ruta, el buen funcionamiento de los anteriores implica el buen funcionamiento del de los iteradores */
    cout << "Los métodos de los iteradores se usan en los métodos de Ruta, por lo que funcionan bien" << endl;

                                                            /* CLASE ALMACEN_RUTAS */                                                        
    cout << endl << "==== CLASE ALMACEN_RUTAS==== " << endl << endl;

    // CONSTRUCTORES
    Almacen_Rutas a1;
    Almacen_Rutas a2;
    a2.insertarRuta(r2);a2.insertarRuta(r3);a2.insertarRuta(r4); // Probamos el metodo insertarRuta
    Almacen_Rutas a3(a2);
    Almacen_Rutas a4;
    cout << "Almacenes de rutas: " << endl;
    cout << "A1: " << endl << a1;
    cout << "A2: " << endl << a2;
    cout << "A3: " << endl << a3;
    //Operador de asignacion
    a4 = a3;
    cout << "A4: " << endl << a4;

    //eliminarRuta()
    cout <<"Borramos la ruta " << r2.getNombre() << " del almacen 2" << endl;
    a2.eliminarRuta(r2.getNombre()); 
    cout << "Ahora almacen 2 queda como: " << endl << a2 << endl;

    //getNumRutas()
    cout << "El tamaño del almacen a2 es: " << a2.getNumRutas() << endl;
    cout << "El tamaño del almacen a3 es: " << a3.getNumRutas() << endl;

    //Operadores de igualdad
    Almacen_Rutas almacen [] ={a1, a2, a3, a4};
    for (int i=1; i <= 4; i++){
        for (int j=i+1; j <= 4; j++){
            if(i != j){
                cout << "A" << i << " y " << "A" << j << " son " << ((almacen[i-1] == almacen[j-1]) ? "iguales " : "distintos") << endl;
            }
        }
    }

    //operadores de flujo
    Almacen_Rutas a5;
    ifstream archivo_almacen("datos/prueba_almacen.txt");
    archivo_almacen >> a5; 
    cout << "El almacen leido es:" << endl;
    cout << a5 << endl;


    /* Iteradores: los metodos se usan en la clase Almacen_Rutas, el buen funcionamiento de los anteriores implica el buen funcionamiento del de los iteradores */
    cout << "Los métodos de los iteradores se usan en los métodos de Almacen_Rutas, por lo que funcionan bien" << endl;

    archivo_almacen.close();
    archivo_rutas.close();
    return 0;
}








