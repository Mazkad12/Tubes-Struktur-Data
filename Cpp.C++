#include "tubeskel15.h"

void createListAtlet (ListAtlet &A){
    first(A) = NULL;
}
void createListClub (ListClub &C) {
    first(C) == NULL;
    Last(C) == NULL;
}
adr_Atlet createElemenAtlet (infotype a){
    adr_Atlet P = new elmAtlet;
    info(P) = a;
    next(P) = NULL;
    nextAtlet(P) = NULL;
    return P;
}
adr_Club createElemenClub (infotype c) {
    adr_Club P = new elmClub;
    info(P) = c;
    next(P) = NULL;
    prev(P) = NULL;
    return p;
}
void InsertElemenAtlet (ListAtlet &A, adr_Atlet P){
..............
}

void InsertElemenClub (ListClub &C, adr_Club P) {
    prev(P) = last(C);
    next(last(C)) = P;
    last(C) = P;
}
void InsertElemenRelation (adr_relation R, ListClub &C){
................
}

void DeleteElemenAtlet (ListAtlet &A, adr_Atlet P){
............
}

void DeleteElemenClub (ListClub &C, adr_Club P) {
    P = last(C);
    last(C) = prev(last(C));
    prev(P) = NULL;
    next(last(C)) = NULL;
}
void DeleterElemenRelation (adr_relation R, ListClub &C){
.........
}
