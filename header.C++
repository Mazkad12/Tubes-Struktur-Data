#ifndef TUBESKEL15_H_INCLUDED
#define TUBESKEL15_H_INCLUDED
#include <iostream>
#include <stdio.h>
#define Nil NULL

#define info(P) (P)->info
#define next(P) (P)->next
#define nextA(P) (P)->nextA
#define nextC(P) (P)->nextC
#define prev(P) (P)->prev

#define first(L) L.first
#define first(L) L.first
#define last(L) L.last
using namespace std;


struct Atlet {
    string ID;
    string NamaA;
    string Tanggal;
    string jeniskelamin;
    string usia;
    int JumlahClub;
};

struct Club {
    string ID;
    string NamaC;
    string pelatih;
    int JumlahAnggota;
};

typedef Atlet infotypeA;
typedef Club infotypeC;

typedef struct elmAtlet *adr_Atlet;
typedef struct elmClub *adr_Club;
typedef struct elmRelation *adr_Relation

struct elmAtlet {
    infotype info;
    adr_Atlet next;
    adr_Club nextClub;
};

struct elmClub {
    infotype info;
    adr_Club next;
    adr_Club prev;
};
struct elmRelation {
    adr_Atlet nextA;
    adr_Relation next;
    adr_Club nextC;
};
struct ListAtlet {
    adr_Atlet first;
};

struct ListClub {
    adr_Club last;
    adr_Club first;
};

struct ListRelation {
    adr_Relation first;
};

//prosedur Atlet
void createListAtlet (ListAtlet &A);
void createListClub (ListClub &C);
adr_Atlet createElemenAtlet (infotype a);
adr_Club createElemenClub (infotype c);
adr_Relation createElementRelation (adr_Atlet P, adr_Club Q);
void InsertlastAtlet (ListAtlet &A, adr_Atlet P);
void InsertlastElemenClub (ListClub &C, adr_Club P);
void InsertlastElemenRelation (adr_relation R, ListRelation R);
void DeletefirstElemenAtlet (ListAtlet &A, adr_Atlet &P);
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

#endif // TUBESKEL15_H_INCLUDED
