#ifndef TUBESKEL15_H_INCLUDED
#define TUBESKEL15_H_INCLUDED
#include <iostream>
#include <stdio.h>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(A) A.first
#define first(C) C.first
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

typedef Atlet infotype;
typedef Club infotype;

typedef struct elmAtlet *adr_Atlet;
typedef struct elmClub *adr_Club;

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

struct ListAtlet {
    adr_Atlet first;
};

struct ListClub {
    adr_Club last;
    adr_Club first;
};

//prosedur Atlet
void createListAtlet (ListAtlet &A);
void createListClub (ListClub &C);
adr_Atlet createElemenAtlet (infotype a);
adr_Club createElemenClub (infotype c);
void InsertElemenAtlet (ListAtlet &A, adr_Atlet P);
void InsertElemenClub (ListClub &C, adr_Club P);
void InsertElemenRelation (adr_relation R, ListAtlet &A, ListClub &C);
void DeleteElemenAtlet (ListAtlet &A, adr_Atlet P);
void DeleteElemenClub (ListClub &C, adr_Club P);
void DeleterElemenRelation (adr_relation R, ListAtlet &A, ListClub &C);
void FindAtlet (ListAtlet L);
void FindClub (ListClub L);
void FindAtletClub (ListAtlet L, ListClub L);
void ShowAtlet (ListAtlet A);
void ShowClub (ListClub C);
void ShowClub_dari_Atlet_tertentu ();
void ShowAtlet_dari_Club tertentu ();
void Show_setiap_data_atlet_beserta_data_club_yang_berelasi ();
void Show_setiap_data_club_beserta_data_atlet_yang_berelasi ();
int Count_jumlah_club_element_atlet_tertentu ();
int Count_jumlah_atlet_yang_dimiliki_oleh_club_tertentu ();
int	Count_element_club_yang_tidak_memiliki_atlet ();
int	Count_element_atlet_yang_tidak_memiliki_club ();
void Edit_relasi ();

#endif // TUBESKEL15_H_INCLUDED
