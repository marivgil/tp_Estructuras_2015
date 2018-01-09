#include "FSS.h"
#include "../Map/Map.h"
#include "../Disc/Disc.h"


/*INVARIANTES DE REPRESENTACION
- si se crea un archivo, debe agregarse al Map y ocupar el espacio en el disco
- si se elimina un archivo del Map, tambien se debe liberar el espacio en el disco
- tamanoFs representa la cantidad de bloques ocupados del disco
*/



struct FileInfoSt{
    int tamanoFi;
    BlockList bloques;
};


struct FssSt{
    Disc disco;
    Map archivos;
    int tamanoFs;
};


//PROP: genera un disco vacio de tamaño n
FSS montar(int n){
    FSS fs = new FssSt;
    fs->disco = nuevo(n); // O(1)
    fs->archivos = emptyM(); // O(1)
    fs->tamanoFs = 0;
    return fs;
};


//PROP: retorna el tamaño de d
int tamanoDisco(FSS fs){
    return tamano(fs->disco); //O(1)
};


//PROP: decide si el archivo fn ya existe en fs
bool existe(CharList fn, FSS fs){
    return(!isNothing(lookupM(fs->archivos,fn))); // O(fn)
};


//PROP: Crea un archivo de nombre fn y tamaño n en fs.
//PRE: hay espacio suficiente en el disco d del file system.
void crear(CharList fn, int n, FSS &fs){

    if(existe(fn, fs))
        borrar(fn, fs);

    FileInfo fi = new FileInfoSt;
    fi->tamanoFi = n;
    fi->bloques = ocupar(n,fs->disco); // O(log(d))

    assocM(fs->archivos,fn,fi); //O(fn)

    fs->tamanoFs = fs->tamanoFs + n; //O(n)

};


//PROP: Retorna la lista de bloques correspondiente al archivo fn.
//PRE: el archivo fn existe en fs.
BlockList abrir(CharList fn, FSS fs){
    return fromJust(lookupM(fs->archivos,fn))->bloques; // O(fn)
};


//PROP: Elimina el archivo fn de fs.
 //PRE: el archivo fn existe en fs.
void borrar(CharList fn, FSS &fs){
    FileInfo elemEliminar = fromJust(lookupM(fs->archivos,fn)); // O(fn)
    liberar(elemEliminar->bloques, fs->disco); // O(log(d))
    deleteM(fs->archivos,fn); // O(fn)
    fs->tamanoFs = fs->tamanoFs - elemEliminar->tamanoFi; //O(n)
    destroyBlockList(elemEliminar->bloques);
    delete elemEliminar;
};


//PROP: Calcula el espacio libre disponible en fs.
int espacioDisponible(FSS &fs){
    return tamano(fs->disco) - fs->tamanoFs; //O(1)
};
