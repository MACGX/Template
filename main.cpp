#include <iostream>
#include "arreglodinamico.h"
#include "computadora.h"
using namespace std;

int main()
{
    ArregloDinamico<Computadora> computadoras;

    Computadora c1("Windows",16,"Intel","Nvida");
    Computadora c2("Windows",1,"Ryzen","Radeon");
    Computadora c3("Windows",6,"Gamefactor","EVGA");
    Computadora c4("Ubuntu",14,"Yeyiam","Sapphire");
    Computadora c5("Debian",32,"Generico","Sumsum");
    Computadora c6("Debia",3,"Generic","Sumsu");

    computadoras << c1 << c2 << c3 << c4 << c5;

    Computadora *ptr = computadoras.buscar(c3);

    if( ptr != nullptr){
        cout << "Esta es la computadora que buscas: " << endl; 
        cout << *ptr << endl;   
    }
    else{
         cout << "No existe " << endl;
    }

    Computadora *ptr1 = computadoras.buscar(c6);

    if( ptr1 != nullptr){
         cout << *ptr1 << endl;   
    }
    else{
         cout << "No existe la computadora c6 " << endl << endl;
    }
    cout << "Estas son todas las computadoras que tienen Windows: " << endl << endl;
    ArregloDinamico<Computadora*> ptrs = computadoras.buscar_todos(c3);

    if(ptrs.size() > 0){
        for (size_t i = 0; i < ptrs.size(); i++)
        {
            Computadora *p = ptrs[i];
            cout << *p << endl;
        }
    }

    // ArregloDinamico<string> arreglodinamico;
    // arreglodinamico.insertar_inicio("Elefante");
    // arreglodinamico.insertar_inicio("Un");
    // arreglodinamico.insertar_final("Columpiaba");
    // arreglodinamico.insertar_final("Sobre");    
    // arreglodinamico.mostrar();
    // arreglodinamico.insertar("Se",2);
    // arreglodinamico.mostrar();
    // arreglodinamico.eliminar_inicio();
    // arreglodinamico.eliminar_final();
    // arreglodinamico.eliminar(1);
    // arreglodinamico.mostrar();
    // cout << endl;
    // string *v = arreglodinamico.buscar("Sobre");
    // cout << v << " " << endl;
    // *v = "Elefanton";
    // // arreglodinamico.mostrar();
    return 0;
}