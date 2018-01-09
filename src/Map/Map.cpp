#include "Map.h"
#include "../Maybe/Maybe.h"


/*INVARIANTES DE REPRESENTACION
- No puede haber hojas con valor Nothing
- LETRAS es un array donde cada valor es una letra del alfabeto de la A a la Z (sin contar la Ñ)
*/


struct MapNodeSt{
    Map* letras;
    Maybe valor;
};


//PROP: retorna un map vacio
Map emptyM(){
    return NULL;
};


// PROP: funcion de Hash, retorna la posicion del array
int hashM(char c){
	return c - 'a';
};


//PROP: retorna verdadero si el map es vacio
bool isEmptyM(Map m){
    return (m == NULL);
}

//PROP: busca el elemento k en m
Maybe lookupM(Map m, CharList k){

    Maybe retorno;
    char primerChar;

    if(isNilCL(k))
        if (!isEmptyM(m)) //si la clave es vacia y el arbol NO es vacio
            return m->valor;
        else //si la clave es vacia y el arbol es vacio
            return Nothing();

    else{
        if (isEmptyM(m)) //si la clave NO son vacia y el arbol es vacio
            return Nothing();
        else{ //si la clave NO son vacia y el arbol NO es vacio
            while(!isNilCL(k)){
                primerChar = headCL(k);
                if (isEmptyM(m->letras[hashM(primerChar)])){
                    return Nothing();
                }
                m = m->letras[hashM(primerChar)];
                k = tailCL(k);
                retorno = m->valor;
            }
            return retorno;
        }
    }

};


//PROP: recibe un valor y crea un nodo con ese valor
Map crearNodo(Maybe v){
    Map nodo = new MapNodeSt;
    nodo->valor = v;
    nodo->letras = new Map[26];
    for(int i = 0; i<=25;i++){
        nodo->letras[i] = NULL;
    }
    return nodo;
}

//PROP: agrega el valor v para la clave k en el map m
void assocM(Map &m, CharList k, MAP_ELEM_TYPE v){

    char primerChar;
    Map current;
    Map aux;

    if(isEmptyM(m))
        m = crearNodo(NULL);
    current = m;
    while(!isNilCL(k)){
        primerChar = headCL(k);
        k = tailCL(k);
        if (isEmptyM(current->letras[hashM(primerChar)])){ //si el hijo que busco NO existe, lo creo
            aux = crearNodo(NULL);
            current->letras[hashM(primerChar)] = aux;
            current = aux;
        }else
            current = current->letras[hashM(primerChar)]; //baje por el hijo que ya existe
    }

    destroyMaybe(current->valor);

    current->valor = Just(v);
    current = NULL;
    aux = NULL;
};

//PROP: recibe un nodo, lo elimina
//PRE: nodo no tiene hijos
void eliminarNodo(Map &nodo){
    delete[] nodo->letras;
    destroyMaybe(nodo->valor);
    delete nodo;
    nodo = NULL;
}

//PROP: valida si el primer nodo del map que recibe tiene hijos
//PRE: el nodo m existe
bool tieneHijos(Map m){

    bool retorno = false;

    for(int i = 0; i<=25; i++){
        if (m->letras[i] != NULL){
            retorno = true;
            break;
        }
    }
    return retorno;
};


//PROP: primero se elimina el valor
//PRE: se asume que la palabra buscada se encuentra en el arbol
void deleteM(Map &m, CharList k){

    if(isNilCL(k)){ // caso base
        if(!tieneHijos(m))
            eliminarNodo(m);
        else{
            destroyMaybe(m->valor);
            m->valor = Nothing();
        }
    }
    else{ // recursion
        deleteM(m->letras[hashM(headCL(k))],tailCL(k));
        if(!tieneHijos(m) && isNothing(m->valor))
            eliminarNodo(m);
    }
};
