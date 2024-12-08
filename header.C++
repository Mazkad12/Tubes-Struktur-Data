#ifndef TUBES1_H_INCLADED
#define TUBES1_H_INCLADED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define nextParent(P) P->nextParent
#define nextChild(P) P->nextChild

#define prev(P) P->prev

#define Nil NULL

using namespace std;

struct Atlet{
    int ID;
    string NamaAtlet;
    string JenisKelamin;
    int Usia;
};

struct Klub{
    int ID;
    string NamaKlub;
    string Pelatih;
};

typedef Atlet infotypeAtlet;
typedef Klub infotypeKlub;
typedef struct ElmAtlet *address_Atlet;
typedef struct ElmKlub *address_Klub;
typedef struct ElmRelasi *address_Relasi;

struct ElmRelasi{
    address_Relasi next;
    address_Atlet nextParent;
    address_Klub nextChild;
};

struct ElmAtlet{
    infotypeAtlet info;
    address_Atlet next;
};

struct ElmKlub{
    infotypeKlub info;
    address_Klub next;
    address_Klub prev;
};

struct ListAtlet{
    address_Atlet first;
};

struct ListKlub{
    address_Klub first;
    address_Klub last;
};

struct ListRelasi{
    address_Relasi first;

};

void createListAtlet(ListAtlet &LA);
void createListKlub(ListKlub &LK);
void createList_Relasi(ListRelasi &LR);
address_Atlet allocateAtlet(infotypeAtlet InfoAtlet);
address_Klub allocateKlub(infotypeKlub InfoKlub);
address_Relasi allocateRelasi();
void insertAtlet(ListAtlet &LA, address_Atlet P);
void insertKlub(ListKlub &LK, address_Klub P);
void insertRelasi(ListAtlet &LA, address_Klub P, address_Klub B, address_Relasi R);
void insertFirstR(ListRelasi &LR, address_Relasi p);
void insertAfterR(ListRelasi &LR, address_Relasi P);
void insertLastR(ListRelasi &LR, address_Relasi p);
void deleteRelasi(ListAtlet &LA, address_Atlet P, address_Relasi &R, int ID);
void deleteFirstA(ListAtlet &LA, address_Atlet P) ; 
void deleteLastA(ListAtlet &LA, address_Atlet p);
void deleteAtlet(ListAtlet &LA, address_Atlet p);
void deleteFirstK(ListKlub &LK, address_Klub p);
void deleteLastK(ListKlub &LK, address_Klub p) ;
void deleteKlub(ListKlub &LK,address_Klub prec);
void deleteFirstR(ListRelasi &LR, address_Relasi p);
void deleteLastR(ListRelasi &LR, address_Relasi p);
void deleteConnection(ListRelasi &LR, address_Relasi p);
address_Atlet findAtlet(ListAtlet LA, int ID);
address_Klub findKlub(ListKlub LK, int ID);
address_Relasi findRelasi(ListAtlet LA, address_Atlet P, int ID);
void showKlubDari_Atlet(ListAtlet LA, int IDAtlet);
void showAtletDari_Klub(ListAtlet LA, int IDKlub);
void showKlub(ListKlub LK);
void showAtlet(ListAtlet LA) ;
void showKlubFromAtlet(ListAtlet LA, ListKlub LK, ListRelasi LR);
void showAtletFromKlub(ListAtlet LA, ListKlub LK, ListRelasi LR);
void showInfoRelation(ListAtlet LA, ListKlub LK, ListRelasi LR);
void connect(ListRelasi &LR,address_Atlet parent,address_Klub child, address_Relasi p);
int countJumlahChildFromSpecificParent(ListRelasi LR,int ID);
int countJumlahParentFromSpecificChild(ListRelasi LR, int ID);
int Hitung_Jumlah_Klub_Tidak_Punya_Atlet(ListKlub LK, ListRelasi LR);
int Hitung_Jumlah_Atlet_Tidak_Bergabung_Dalam_Klub(ListAtlet LA, ListRelasi LR);
void Ubah_Klub_yang_Telah_Diikuti_Atlet(ListKlub &LK,ListRelasi &LR,int cariAtletId, int cariKlubId, int idKlubBaru);
void Ubah_Atlet_yang_Didalam_Klub(ListAtlet &LA,ListRelasi &LR,int cariIdKlub, int cariKlubId, int idAtletBaru);
void menuUtama(int &klik);

#endif // TBS_H_INCLADED
