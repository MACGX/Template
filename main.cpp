#include <iostream>
#include "arreglodinamico.h"

using namespace std;

int main()
{
    ArregloDinamico<string> arreglodinamico;
    arreglodinamico.insertar_inicio("Elefante");
    arreglodinamico.insertar_inicio("Un");
    arreglodinamico.insertar_final("Columpiaba");
    arreglodinamico.insertar_final("Sobre");    
    arreglodinamico.mostrar();
    arreglodinamico.insertar("Se",2);
    arreglodinamico.mostrar();
    arreglodinamico.eliminar_inicio();
    arreglodinamico.eliminar_final();
    arreglodinamico.eliminar(1);
    arreglodinamico.mostrar();
    return 0;
}