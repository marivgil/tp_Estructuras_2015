#ifndef MAYBE_H
#define MAYBE_H

// Definir FileInfo e incluirlo si es necesario
struct FileInfoSt;
typedef FileInfoSt* FileInfo;

#define MAYBE_ELEM_TYPE FileInfo


struct MaybeSt;
typedef MaybeSt* Maybe;


Maybe Nothing();

Maybe Just(MAYBE_ELEM_TYPE e);

MAYBE_ELEM_TYPE fromJust(Maybe m);

bool isNothing(Maybe m);

void destroyMaybe(Maybe &m);

void printMaybe(Maybe m);

#endif /* MAYBE_H */

