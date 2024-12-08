#include "tbs.h"

void createListAtlet(ListAtlet &LA){
    first(LA) = Nil;
}

void createListKlub(ListKlub &LK){
    first(LK) = Nil;
    last(LK) = Nil;

}

void createList_Relasi(ListRelasi &LR){
      first(LR) = NULL;
}


address_Atlet allocateAtlet(infotypeAtlet InfoAtlet){
    address_Atlet P = new ElmAtlet;
    info(P) = InfoAtlet;
    next(P) = Nil;

    return P;
}

address_Klub allocateKlub(infotypeKlub InfoKlub){
    address_Klub P = new ElmKlub;
    info(P) =InfoKlub;
    next(P) = Nil;
    prev(P) = Nil;

    return P;
}

address_Relasi allocateRelasi(){
    address_Relasi P = new ElmRelasi;
    nextParent(P) = Nil;
    nextChild(P) = Nil;
    next(P) = Nil;
    return P;
}

void insertAtlet(ListAtlet &LA, address_Atlet P){
    if(first(LA) != Nil){
        next(P) = first(LA);
        first(LA) = P;
    } else{
        first(LA) = P;
    }

}

void insertKlub(ListKlub &LK, address_Klub P){
    if(first(LK) != Nil){
        next(P) = first(LK);
        prev(first(LK)) = P;
        first(LK) = P;
    } else {
        first(LK) = P;
        last(LK) = P;
    }
}

void insertFirstR(ListRelasi &LR, address_Relasi p) {
  address_Relasi q;
  q = first(LR);
  if (first(LR) == NULL) {
    first(LR) = p;
  } else {
    next(p) = first(LR);
    first(LR) = p;
  }
}

void insertAfterR(ListRelasi &LR, address_Relasi prec, address_Relasi P) {
    if(next(prec) == NULL) {
        next(prec) = P;
    } else {
        next(P) = next(prec);
        next(prec) = P;
    }
}

void insertLastR(ListRelasi &LR, address_Relasi p) {
    address_Relasi q;
    q = first(LR);
    if (first(LR) == NULL) {
        first(LR) = p;
    } else {
        while(next(q) != NULL ) {
            q = next(q);
        }
        next(q) = p;
    }
}

void deleteFirstParent(ListAtlet &LA, address_Atlet P) {
    if (first(LA) == NULL) {
        cout << "List Gagal Ditemukan" << endl;
    } else if (next(first(LA)) == NULL) {
        P = first(LA);
        first(LA) = NULL;
    } else {
        P = first(LA);
        first(LA) = next(first(LA));
        next(P) = NULL;
    }
}

void deleteLastA(ListAtlet &LA, address_Atlet p) {
    address_Atlet q;
    q = first(LA);
    if (first(LA) == NULL) {
        cout << "List Gagal Ditemukan."<< endl;
    } else if (next(first(LA)) == NULL) {
        p = first(LA);
        first(LA) = NULL;
    } else {
        while (next(next(q)) != NULL) {
            q = next(q);
        }
        p = next(q);
        next(q) = NULL;
    }
}

void deleteAtlet(ListAtlet &LA, address_Atlet p) {
    address_Atlet q;
    if (first(LA) == NULL) {
        cout << "List Gagal Ditemukan" << endl;
    } else if (p == first(LA)) {
        deleteFirstParent(LA,p);
    } else if (next(p) == NULL) {
        deleteLastA(LA,p);
    } else {
        q = first(LA);
        while (next(q) != p) {
            q = next(q);
        }
        next(q) = next(p);
        p = NULL;
        }
}

void deleteFirstK(ListKlub &LK, address_Klub p) {
    if (first(LK) == NULL) {
        cout << "List Gagal Ditemukan" << endl;
    } else if (LK.first == LK.last) {
        p = first(LK);
        first(LK) = NULL;
        last(LK) = NULL;
    } else {
        p = first(LK);
        first(LK) = next(first(LK));
        prev(first(LK)) = NULL;
        next(p) = NULL;
    }
}

void deleteLastK(ListKlub &LK, address_Klub p) {
    if (first(LK) == NULL) {
        p = NULL;
        cout << "List Gagal Ditemukan" << endl;
    } else if (first(LK) == last(LK)) {
        p = first(LK);
        first(LK) = NULL;
        last(LK) = NULL;
    } else {
        p = last(LK);
        last(LK) = prev(last(LK));
        next(last(LK)) = NULL;
        prev(p) = NULL;
    }
}

void deleteKlub(ListKlub &LK,address_Klub p) {
    address_Klub q;
    if(p == NULL){
        cout << "Gagal" << endl;

    } else if (first(LK) == NULL) {
        cout << "List Gagal Ditemukan" << endl;
    } else if (p == first(LK)) {
        deleteFirstK(LK,p);
    } else if (p == last(LK)) {
        deleteLastK(LK,p);
    } else {
        q = first(LK);
        while (next(q) != p) {
            q = next(q);
        }
        next(q) = next(p);
        p = NULL;
    }
}

void deleteFirstR(ListRelasi &LR, address_Relasi p) {
    if (first(LR) == NULL) {
        cout << "List Gagal Ditemukan" << endl;
    } else if (next(first(LR)) == NULL) {
        p = first(LR);
        first(LR) = NULL;
    } else {
        p = first(LR);
        first(LR) = next(first(LR));
        next(p) = NULL;
    }
}

void deleteLastR(ListRelasi &LR, address_Relasi p) {
    address_Relasi q;
    q = first(LR);
    if (first(LR) == NULL) {
        cout << "List Gagal Ditemukan"<< endl;
    } else if (next(first(LR)) == NULL) {
        p = first(LR);
        first(LR) = NULL;
    } else {
        while (next(next(q)) != NULL) {
            q = next(q);
        }
        p = next(q);
        next(q) = NULL;
    }
}

void deleteConnection(ListRelasi &LR,address_Relasi prec) {
    address_Relasi q;
    if (first(LR) == NULL) {
    cout << "List Gagal Ditemukan" << endl;
    } else if (prec == first(LR)) {
        deleteFirstR(LR,prec);
    } else if (next(prec) == NULL) {
        deleteLastR(LR,prec);
    } else {
        q = first(LR);
        while (next(q) != prec) {
            q = next(q);
        }
        next(q) = next(prec);
        prec = NULL;
    }
}

address_Atlet findAtlet(ListAtlet LA, int ID) {
    address_Atlet p;
    p = first(LA);
    cout << "Sedang mencari informasi terkait ID Atlet yang dimaksud..." << endl;
    cout << "............................................................" << endl;
    cout << endl;
    while ( p != NULL) {
        if (info(p).ID == ID) {
            cout << "Data Atlet Berhasil Ditemukan" << endl;
            cout << endl;
            return p;
        } else {
            p = next(p);
        }

    }
    cout << "ID Atlet Tidak ditemukan!" << endl;
    cout << "Silahkan Masukkan Data Ulang" << endl;

}

address_Klub findKlub(ListKlub LK, int ID) { // Find Klub
    address_Klub p;
    p = first(LK);
    cout << "Sedang mencari informasi terkait ID Atlet yang dimaksud....." << endl;
    cout << "............................................................" << endl;
    cout << endl;
    while ( p != NULL) {
        if (info(p).ID == ID) {
            cout << "Data Klub Berhasil Ditemukan" << endl;
            cout << endl;
            return p;
        } else {
            p = next(p);
        }

    }
     cout << "ID Atlet Tidak ditemukan!" << endl;
    cout << "Silahkan Masukkan Data Ulang" << endl;
    return NULL;
}

void showAtlet(ListAtlet LA) { // Show Parent
    address_Atlet P;
    P = first(LA);
    int i = 1;
    while ( P != NULL) {

      cout << "ID Atlet     :" << info(P).ID << endl;
      cout << "Nama Atlet   :" << info(P).NamaAtlet << endl;
      cout << "Jenis Kelamin:" << info(P).JenisKelamin << endl;
      cout << "Usia         :" << info(P).Usia << endl;
    cout << endl;
      i++;
      P = next(P);

    }
}

void connect(ListRelasi &LR ,address_Atlet parent,address_Klub child, address_Relasi p) {

    if (first(LR) == NULL) {
        insertFirstR(LR,p);
    } else {
        insertLastR(LR,p);
    }
    nextParent(p) = parent;
    nextChild(p) = child;
}

void showKlub(ListKlub LK){ // Show Child
     address_Klub P;
     P = first(LK);
     int i = 1;
    while(P!=NULL){
        cout << "ID Klub     : " << info(P).ID << endl;
        cout << "Nama Klub   : " << info(P).NamaKlub<< endl;
        cout << "Pelatih     :" << info(P).Pelatih << endl;
        i++;
        cout << endl;
        P = next(P);
    }

}

void showInfoRelation(ListAtlet LA, ListKlub LK, ListRelasi LR){
    address_Relasi p;
    p = first(LR);
    while (p != NULL) {
        cout << endl;
        cout << "ID Atlet     : " << info(nextParent(p)).ID << endl;
        cout << "Nama         : " << info(nextParent(p)).NamaAtlet << endl;
        cout << "Jenis Kelamin: " << info(nextParent(p)).JenisKelamin << endl;
        cout << "Usia         : " << info(nextParent(p)).Usia << endl;
        cout << endl;

        cout << "Klub yang diikuti Atlet: " << endl;
        cout << endl;
        cout << "ID           : " << info(nextChild(p)).ID << endl;
        cout << "Nama         : " << info(nextChild(p)).NamaKlub<< endl;
        cout << "Pelatih      : " << info(nextChild(p)).Pelatih << endl;
        cout << endl;
        p = next(p);

    }
}

int countJumlahChildFromSpecificParent(ListRelasi LR, int ID){
        address_Relasi p;
        int count = 0;
        p = first(LR);
        while (p != NULL) {
        if (info(nextParent(p)).ID == ID) {
            count++;
            }
            p = next(p);
        }
        cout << endl;
        cout << "Jumlah Klub yang tergabung oleh Atlet dengan ID " << ID << " adalah sebanyak" << " = " << count << " Klub" << endl;
        return count;
}

int countJumlahParentFromSpecificChild(ListRelasi LR, int ID){
    address_Relasi p;
    int count = 0;
    p = first(LR);
    cout << endl;
    while (p != NULL) {
        if (info(nextChild(p)).ID == ID) {
            count++;
        }
        p = next(p);
    }
    cout << "Jumlah Atlet yang tergabung oleh Klub dengan ID " << ID << " adalah sebanyak" << " = " << count << " Atlet" << endl;
    return count;
}

int Hitung_Jumlah_Klub_Tidak_Punya_Atlet(ListKlub LK, ListRelasi LR){
    address_Klub p;
    address_Relasi q;
    int i = 0;
    int x = 0;
    bool hasParent = false;
    p = first(LK);
    while (p != NULL) {
        q = first(LR);
        hasParent = false;
        while (q != NULL) {
            if (nextChild(q) == p){
                hasParent = true;
                q = next(q);
            }
            else {
                q = next(q);
            }
        } if (hasParent) {
            p = next(p);
        } else {
            x = x + 1;
            p = next(p);
        }
    }
    cout << "Jumlah Klub yang Belum Memiliki Atlet adalah sebesar = " << x << " Klub" << endl;
    return x;
}

int Hitung_Jumlah_Atlet_Tidak_Bergabung_Dalam_Klub(ListAtlet LA, ListRelasi LR){
    address_Atlet p;
    address_Relasi q;
    int count = 0;
    int x = 0;
    bool hasChild = false;
    p = first(LA);
    while (p != NULL) {
        q = first(LR);
        hasChild = false;
        while (q != NULL) {
            if (nextParent(q) == p){
                hasChild = true;
                q = next(q);
            }
            else {
                q = next(q);
            }
        } if (hasChild) {
            p = next(p);
        } else {
            x++;
            p = next(p);
        }
    }
    cout << "Jumlah Atlet yang Belum Memiliki Klub adalah sebesar = " << x << " Atlet" << endl;
    return x;
}

void Ubah_Klub_yang_Telah_Diikuti_Atlet(ListKlub &LK, ListRelasi &LR,int cariAtletId,  int cariKlubId, int idKlubBaru) { // mengganti Klub dari Atlet tertentu
    address_Relasi p = first(LR);
    bool terubah = false;
    while (p != NULL && !terubah) {
        if (info(nextParent(p)).ID == cariAtletId && info(nextChild(p)).ID == cariKlubId) {
            address_Klub q = first(LK);
            while (q != NULL && !terubah) {
                if (info(q).ID == idKlubBaru) {
                    cout << "===============Informasi akan diperbarui===============" << endl;
                    nextChild(p) = q;
                    terubah = true;
                }
                q = next(q);
            }
        }
        p = next(p);
    }

    if (!terubah) {
        cout << "Atlet atau Klub yang dimaksud tidak ditemukan, atau nama baru yang dimasukkan tidak sesuai" << endl;
        cout << "Silahkan Masukkan Data Kembali" << endl;
    }
}

void Ubah_Atlet_yang_Didalam_Klub(ListAtlet &LA, ListRelasi &LR,int cariAtletId,  int cariKlubId, int IdAtletBaru){
    address_Relasi p = first(LR);
    bool terubah = false;
    while (p != NULL && !terubah) {
        if (info(nextParent(p)).ID == cariAtletId && info(nextChild(p)).ID == cariKlubId) {
            address_Atlet q = first(LA);
            while (q != NULL && !terubah) {
                if (info(q).ID == IdAtletBaru) {
                    cout << "Informasi akan diperbarui" << endl;
                    nextParent(p) = q;
                    terubah = true;
                }
                q = next(q);
            }
        }
        p = next(p);
    }

    if (!terubah) {
        cout << "Atlet atau Klub yang dimaksud tidak ditemukan, atau nama baru yang dimasukkan tidak sesuai" << endl;
        cout << "Silahkan Masukkan Data Kembali" << endl;
    }
}

void menuUtama(int &klik) {
    cout << endl;
    cout << "===============================================================================" << endl;
    cout << "Halaman Utama Sistem "<< endl;
    cout << " " << endl;
    cout << "1. Tambah Data Atlet" << endl;
    cout << "2. Tambah Data Klub" << endl;
    cout << "3. Hapus  Data Atlet" << endl;
    cout << "4. Hapus  Data Klub" << endl;
    cout << "5. Tampilkan Daftar Atlet" << endl;
    cout << "6. Tampilkan Daftar Klub " << endl;
    cout << "7. Masukkan Data Atlet yang ingin bergabung ke dalam Klub Tertentu?" << endl; // Connect child and parent
    cout << "8. Tampilkan Atlet yang telah bergabung ke dalam klub" << endl; // Show relation parent and child
    cout << "9. Tampilkan jumlah Atlet dari klub tertentu" << endl; // Count  parent from specific child
    cout << "10.Tampilkan jumlah Klub yang berisikan Atlet tertentu" << endl; // count child from specific parent
    cout << "11.Tampilkan jumlah Klub yang saat ini belum memiliki anggota Atlet" << endl;  // Count child no parent
    cout << "12.Tampilkan jumlah Atlet yang tidak memilih bergabung ke dalam klub" << endl; // count parent no child
    cout << "13.Ubah informasi Atlet dari Klub tertentu" << endl;
    cout << "14.Ubah informasi Klub dari Atlet tertentu" << endl;
    cout << "15.Exit" << endl;
    cout << "===============================================================================" << endl;
    cout << endl;
    cout << "Silahkan Klik Menu  : " ;
}








