#include "tubeskel15.h"

void createListAtlet (ListAtlet &A){
    first(A) = NULL;
}
void createListClub (ListClub &C){
    first(C) = NULL;
    last(C) = NULL;
}
adr_Atlet createElemenAtlet (infotype a){
    adr_Atlet P = new elmAtlet;
    info(P) = a;
    next(P) = NULL;
    return P;
}
adr_Club createElemenClub (infotype c){
    adr_Club P = new elmClub;
    info(P) = c;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
adr_Relation createElementRelation (adr_Atlet P, adr_Club Q){
    adr_Relation R = new elmRelation;
    nextA(R) = P;
    nextC(R) = Q;
    return R;
}
void InsertlastAtlet (ListAtlet &A, adr_Atlet P){
    if (first(A) = NULL) {
        first(A) = P;
    } else {
        address Q = first(A);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void InsertlastClub (ListClub &C, adr_Club P){
    prev(P) = last(C);
    next(last(C)) = P;
    last(C) = P;
}
void InsertlastRelation (adr_relation R, ListRelation &R){

}
void DeletefirstElemenAtlet (ListAtlet &A, adr_Atlet &P){
    if (next(first(A)) == NULL) {
        P = first(A);
        first(A) = NULL;
    } else {
        P = first(A);
        first(A) = next(P);
        next(P) = NULL
    }
}
void DeletelastElemenAtlet (ListAtlet &A, adr_Atlet &P);
void DeleteAfterElemenAtlet (ListAtlet &A, adr_Atlet &P, adr_Atlet prec);
void DeletefirstElemenClub (ListClub &C, adr_Club &P);
void DeletelastElemenClub (ListClub &C, adr_Club &P);
void DeleteAfterElemenClub (ListClub &C, adr_Club &P, adr_Club prec);
void DeleterElemenRelation (adr_relation &R, adr_Atlet P, adr_Club Q);
adr_Atlet FindAtlet (ListAtlet L,string ID);
adr_Club FindClub (ListClub L, string ID);
adr_Relation FindAtletClub (ListRelation R, adr_Atlet P, adr_Club Q);
void ShowAtlet (ListAtlet A);
void ShowClub (ListClub C);
void ShowClub_dari_Atlet_tertentu (ListRelation R, adr_Atlet P);
void ShowAtlet_dari_Club tertentu (listRelation R, adr_Club P);
void Show_setiap_data_atlet_beserta_data_club_yang_berelasi (ListAtlet A, ListRelation R);
void Show_setiap_data_club_beserta_data_atlet_yang_berelasi (ListClub C, ListRealation R);
int Count_jumlah_club_element_atlet_tertentu (ListRealation R, adr_Atlet P);
int Count_jumlah_atlet_yang_dimiliki_oleh_club_tertentu (ListRelation R, adr_Club P);
int	Count_element_club_yang_tidak_memiliki_atlet (ListRelation R, adr_Club P);
int	Count_element_atlet_yang_tidak_memiliki_club (ListRelation R, adr_Atlet P);
void Edit_relasi (ListRelation &R);
