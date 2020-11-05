#ifndef  ARREGLODINAMICO_H
#define  ARREGLODINAMICO_H

#include <iostream>
using namespace std;

template <class T>

class  ArregloDinamico
{
    T * arreglodinamico;
    size_t tam;
    size_t cont;
    const static size_t MAX = 100;
public:
     ArregloDinamico();
    ~ ArregloDinamico();

    void insertar_final(const T& v);
    void insertar_inicio(const T& v);
    void insertar(const T& v, size_t p);

    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);

    T* buscar (const T& v);
    ArregloDinamico<T*> buscar_todos(const T& v);

    void mostrar();

    size_t size();
    T operator[](size_t p)
    {
        return  arreglodinamico[p];
    }

    friend ArregloDinamico<T>& operator<<(ArregloDinamico<T> &a, const T& v)
    {
        a.insertar_final(v);
        
        return a;
    }

private:
    void expandir();
};

template <class T>
ArregloDinamico<T>::ArregloDinamico()
{
    arreglodinamico = new T [MAX];
    cont = 0;
    tam = MAX;
} 

template <class T>
ArregloDinamico<T>::~ArregloDinamico()
{
    delete[] arreglodinamico;
} 

template <class T>
void ArregloDinamico<T>::insertar_final(const T& v)
{
    if (cont == tam){
        expandir();
    }
    arreglodinamico[cont] = v;
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar_inicio(const T& v)
{
    if (cont == tam){
        expandir();
    }
    for (size_t i = cont; i > 0; i--){
         arreglodinamico[i] =  arreglodinamico[i-1];
    }
     arreglodinamico [0] = v;
    cont ++;
}

template <class T>
void ArregloDinamico<T>::insertar(const T& v, size_t p)
{
    if (p >= cont){
        cout << "Posicion no valida" << endl;
        return;
    }
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > p; i--){
        arreglodinamico[i] = arreglodinamico[i-1];
    }
    arreglodinamico[p] = v;
    cont ++;
}

template <class T>
void ArregloDinamico<T>::eliminar_final()
{
    if (cont == 0){
        cout << "Arreglo vacio"<< endl;
        return;
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar_inicio(){
    for (size_t i = 0; i < cont; i++)
    {
        arreglodinamico[i] = arreglodinamico[i+1];
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar(size_t p){
    
    if (cont == 0){
        cout << "Arreglo Vacio" << endl;
        return;
        }
    for (size_t i = p; i < cont - 1; i++)
    {
    arreglodinamico[i] = arreglodinamico [i+1];
    }
    cont--;    
}

template <class T>
T* ArregloDinamico<T>::buscar(const T& v){
    for (size_t i = 0; i < cont; i++)
    {
        if(v == arreglodinamico[i]){
            return &arreglodinamico[i];
        }
    }
    return nullptr;
}

template <class T>
ArregloDinamico<T*> ArregloDinamico<T>::buscar_todos(const T& v){

    ArregloDinamico<T*> ptrs;

    for (size_t i = 0; i < cont; i++)
    {
        if(v == arreglodinamico[i]){
            ptrs.insertar_final (&arreglodinamico[i]);
        }
    }

    return ptrs;

}

template <class T>
size_t ArregloDinamico<T>::size()
{
    return cont;
}

template <class T>
void ArregloDinamico<T>::expandir()
{
    T *nuevo = new T [tam+MAX];
    for (size_t i = 0; i < cont; i++)
    {
        nuevo [i] =  arreglodinamico[i];
    }
    delete[]  arreglodinamico;
    arreglodinamico = nuevo;
    tam = tam + MAX;

}

template <class T>
void ArregloDinamico<T>::mostrar(){
    for (size_t i = 0; i < cont ;i++)
    {
        cout << arreglodinamico[i] << " ";
    }
    cout << endl;
}


#endif 
