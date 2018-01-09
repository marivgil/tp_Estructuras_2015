#include "FSS/FSS.h"
#include "Map/Map.h"
#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[]) {

//TEST BASICO

    //creo un fileSystem
    FSS fs = montar(100);
    cout<< "Tamaño del mismo en el fs: "<< tamanoDisco(fs) <<endl;
/*
    //creo un archivo
    cout << "Creo archivo : "<< endl;
    CharList archivo = ConsCL('h',ConsCL('o',ConsCL('l',ConsCL('a',NilCL()))));
    printCharList(archivo);
    printf("\n");

    // verifico si existe el archivo en el fs
    if (existe(archivo,fs))
        cout << "existe" << endl;
    else
        cout << "NO existe" << endl;
    printCharList(archivo);
    printf("\n");

    //agrego el archivo al fs
    crear(archivo,10,fs);

    //valido nuevamente que exista el archivo en el fs
    if (existe(archivo,fs))
        cout << "existe" << endl;
    else
        cout << "NO existe" << endl;
    printCharList(archivo);
    printf("\n");

    cout<< "espacio disponible  en fs: "<< espacioDisponible(fs) <<endl;

*/

//TEST mas copado
/*

ARBOL PARA TESTEAR

        |0,1|
       /  |  \
      a   d    j
    /     |     \
  |2,3|  |4,5|  |  |
  /  \           |
 b   c           a
/     \          |
|6,7| |8,9|    |10,11|


*/

    CharList arch = NilCL();
    crear(arch,2,fs);
    cout << "Agrego arch al fs" << endl;
    printCharList(arch);
    printf("\n");
    cout << "Bloque : " << endl;
    BlockList bloque = abrir(arch, fs);
    printBlockList(bloque);
    printf("\n");
    printf("\n");

    CharList archA = ConsCL('a',NilCL());
    crear(archA,2,fs);
    cout << "Agrego archA al fs" << endl;
    printCharList(archA);
    printf("\n");
    cout << "Bloque : " << endl;
    BlockList bloqueA = abrir(archA, fs);
    printBlockList(bloqueA);
    printf("\n");
    printf("\n");

    CharList archD = ConsCL('d',NilCL());
    crear(archD,2,fs);
    cout << "Agrego arch al fs" << endl;
    printCharList(archD);
    printf("\n");
    cout << "Bloque : " << endl;
    BlockList bloqueD = abrir(archD, fs);
    printBlockList(bloqueD);
    printf("\n");
    printf("\n");

    CharList archAB = ConsCL('a',ConsCL('b',NilCL()));
    crear(archAB,2,fs);
    cout << "Agrego arch al fs" << endl;
    printCharList(archAB);
    printf("\n");
    cout << "BloqueAB : " << endl;
    BlockList bloqueAB = abrir(archAB, fs);
    printBlockList(bloqueAB);
    printf("\n");
    printf("\n");

    CharList archAC = ConsCL('a',ConsCL('c',NilCL()));
    crear(archAC,2,fs);
    cout << "Agrego arch al fs" << endl;
    printCharList(archAC);
    printf("\n");
    cout << "BloqueAC : " << endl;
    BlockList bloqueAC = abrir(archAC, fs);
    printBlockList(bloqueAC);
    printf("\n");
    printf("\n");

    CharList archJAC = ConsCL('j',ConsCL('a',ConsCL('c',NilCL())));
    crear(archJAC,2,fs);
    cout << "Agrego arch al fs" << endl;
    printCharList(archJAC);
    printf("\n");
    cout << "BloqueJAC : " << endl;
    BlockList bloqueJAC = abrir(archJAC, fs);
    printBlockList(bloqueJAC);
    printf("\n");
    printf("\n");

    //esta bien que rompa porque el abrir tiene una precondicion que dice que el archivo tiene que existir
    //BlockList bloqueAAA = abrir(archAAA, fs);

    cout << "ahora quiero que vaya a buscar uno que no existe : " << endl;
    CharList archAAA = ConsCL('a',ConsCL('a',ConsCL('a',NilCL())));
    if (existe(archAAA,fs))
        cout << "existe" << endl;
    else
        cout << "NO existe" << endl;
    printCharList(archAAA);
    printf("\n");


    cout<< "espacio disponible  en fs: "<< espacioDisponible(fs) <<endl;

    cout<< "Voy a eliminar 'AB': " <<endl;
    borrar(archAB,fs);

    cout<< "espacio disponible  en fs: "<< espacioDisponible(fs) <<endl;
    printf("\n");
    printf("\n");

    //IMPRIMO LOS BLOQUES DEL ARBOL

    cout << "Bloque nil: " << endl;
    printBlockList(abrir(arch, fs));
    printf("\n");

    cout << "Bloque A: " << endl;
    printBlockList(abrir(archA, fs));
    printf("\n");

    cout << "Bloque AC: " << endl;
    printBlockList(abrir(archAC, fs));
    printf("\n");

    cout << "Bloque D : " << endl;
    printBlockList(abrir(archD, fs));
    printf("\n");

    cout << "Bloque JAC : " << endl;
    printBlockList(abrir(archJAC, fs));
    printf("\n");

    printCharList(archAB);
    if (existe(archAB,fs))
        cout << "existe AB" << endl;
    else
        cout << "NO existe AB" << endl;
    printf("\n");

    cout<< "AHORA VOY A ELIMINAR 'A': " <<endl;
    borrar(archA,fs);

    cout<< "espacio disponible  en fs: "<< espacioDisponible(fs) <<endl;
    printf("\n");
    printf("\n");

    //IMPRIMO LOS BLOQUES DEL ARBOL

    cout << "Bloque nil: " << endl;
    printBlockList(abrir(arch, fs));
    printf("\n");

    cout << "Bloque AC: " << endl;
    printBlockList(abrir(archAC, fs));
    printf("\n");

    cout << "Bloque D : " << endl;
    printBlockList(abrir(archD, fs));
    printf("\n");

    cout << "Bloque JAC : " << endl;
    printBlockList(abrir(archJAC, fs));
    printf("\n");

    printCharList(archA);
    if (existe(archA,fs))
        cout << "existe A" << endl;
    else
        cout << "NO existe A" << endl;
    printf("\n");

  return 0;
}

