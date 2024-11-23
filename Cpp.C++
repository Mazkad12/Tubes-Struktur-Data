#include "tubeskel15.h"

void createListAtlet (ListAtlet &L){
    first(L) = NULL;
}
void createListClub (ListClub &L) {
    first(L) == NULL;
    Last(L) == NULL;
}
adr_Atlet createElemenAtlet (infotype A){
    adr_Atlet P = new elmAtlet;
    info(P) = A;
    next(P) = NULL;
    nextAtlet(P) = NULL;
    return P;
}
adr_Club createElemenClub (infotype C) {
    adr_Club p = new elmClub;
    info(p) = C;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void InsertElemenAtlet (ListAtlet &L, adr_Atlet P);
void InsertElemenClub (ListClub &L, adr_Club P) {
    prev(P) = last(L);
    next(last(L)) = P;
    last(L) = P;
}
void InsertElemenRelation (adr_relation R, ListClub &L);
void DeleteElemenAtlet (ListAtlet &L, adr_Atlet P);
void DeleteElemenClub (ListClub &L, adr_Club P) {
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = NULL;
}
void DeleterElemenRelation (adr_relation R, ListClub &L);
