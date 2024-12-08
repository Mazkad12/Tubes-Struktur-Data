#include <iostream>
#include "tbs.h"

using namespace std;

int main()
{
    infotypeAtlet u; // parent
    infotypeKlub b;
    ListAtlet LA; // parent
    ListKlub LK;
    ListRelasi LR;
    address_Atlet x; // parent
    address_Klub Q;
    address_Relasi t;
    int Klik;
    int IDKlub;
    int IDAtlet;
    int idNama;
    address_Atlet parent;
    address_Klub child;
    int idNamaBaru;
    int IdKlubBaru;
    address_Relasi r;
    bool Exit = false ;
    createListAtlet(LA);
    createListKlub(LK);
    createList_Relasi(LR);

    while(Exit != true){
         menuUtama(Klik);
         cin >> Klik;

            if (Klik == 1){
                cout << "Silahkan Masukkan ID Atlet: "  ;
                cin>> u.ID ;
                cout << "Silahkan Masukkan Nama Atlet: "  ;
                cin >> u.NamaAtlet;
                cout << "Silahkan Masukkan Jenis Kelamin: " ;
                cin >> u.JenisKelamin;
                cout << "Silahkan Masukkan Usia: " ;
                cin >> u.Usia;
                cout << endl;
                x =  allocateAtlet(u);
                insertAtlet(LA, x);
                cout << endl;
                cout << "====================Data Ditambahkan===================" << endl;
                cout << endl;

            } else if (Klik == 2){
                cout << "Silahkan Masukkan ID Klub: " ;
                cin >> b.ID ;
                cout << "Silahkan Masukkan Nama Klub: " ;
                cin >> b.NamaKlub;
                cout << "Silahkan Masukkan Nama Pelatih: ";
                cin >> b.Pelatih;
                Q =  allocateKlub(b);
                insertKlub(LK, Q);
                cout << "====================Data Ditambahkan===================" << endl;
                cout << endl;

            } else if (Klik == 3){
                cout << endl;
                showAtlet(LA);
                cout << endl;
                cout << "Silkahkan Masukkan ID Atlet yang ingin dihapus: ";
                cin  >> IDAtlet;
                    if (IDAtlet != 0) {
                        address_Atlet Q = findAtlet(LA,IDAtlet);
                        deleteAtlet(LA,Q);
                    } else {
                        cout << "====================Data Gagal Ditemukan===================";
                }
                showAtlet(LA);
            } else if (Klik == 4){
                cout << endl;
                showKlub(LK);
                cout << endl;
                cout << "Silkahkan Masukkan ID Klub yang ingin dihapus: ";
                cin  >> IDKlub;
                    if (IDKlub != 0) {
                        address_Klub o = findKlub(LK,IDKlub);
                        deleteKlub(LK,o);
                }  else {
                        cout << "====================Data Gagal Ditemukan===================";
                    }
                showKlub(LK);

            } else if (Klik == 5){
                cout << endl;
                cout << "================List Atlet================" << endl;
                cout << endl;
                showAtlet(LA);

            } else if (Klik == 6){

                cout << endl;
                cout << "================List Klub================" << endl;
                cout << endl;
                showKlub(LK);
           } else if (Klik == 7) { // sambungkan list dan parent
                cout << endl;
                cout << endl;
                showAtlet(LA);
                showKlub(LK);
                t = allocateRelasi();
                cout << "Silahkan Masukkan ID Atlet: ";
                cin >> IDKlub;
                cout << "Silakan masukkan ID Klub tempat Atlet akan bergabung.: ";
                cin >> idNama;
                parent = findAtlet(LA,IDKlub);
                child = findKlub(LK,idNama);
                if (parent != NULL && child != NULL) {
                connect(LR,parent,child,t);
                cout << "Data Berhasil Ditambahkan" << endl;
                } else {
                cout << endl;
                }

           } else if (Klik == 8){
              showInfoRelation(LA,LK,LR);
           } else if (Klik == 9){
                int CariIDAtlet;
                cout << "Masukkan ID Atlet untuk melihat jumlah Klub yang diikutinya: ";
                cin >> CariIDAtlet;
                countJumlahChildFromSpecificParent(LR,CariIDAtlet);

           } else if(Klik == 10){
                int cariIDKlub;
                cout << "Masukkan ID Klub untuk melihat jumlah Atlet yang diikutinya: ";
                cin >> cariIDKlub;
                countJumlahParentFromSpecificChild(LR,cariIDKlub);
           } else if(Klik == 11){
                 Hitung_Jumlah_Klub_Tidak_Punya_Atlet(LK,LR);

           } else if(Klik == 12){
                 Hitung_Jumlah_Atlet_Tidak_Bergabung_Dalam_Klub(LA,LR);

           } else if(Klik == 13){

                 cout << "Silahkan Masukkan ID Atlet ingin di cari: ";
                cin >>  IDKlub;
                cout << "Silahkan Masukkan ID Klub yang ingin di cari: ";
                  cin >> idNama;
                cout << "Silahkan Masukkan ID Klub yang ingin di ganti dengan yang baru: ";
                cin >>  idNamaBaru;
                 Ubah_Klub_yang_Telah_Diikuti_Atlet(LK,LR,IDKlub,idNama,idNamaBaru);

           } else if(Klik == 14){
                cout << "Silahkan Masukkan ID Klub yang ingin di cari: ";
                cin >> idNama;
                cout << "Silahkan Masukkan ID Atlet yang ingin di cari: ";
                cin >> IDKlub;
                cout << "Silahkan Masukkan ID Atlet yang ingin di ganti dengan yang baru: ";
                cin >> IdKlubBaru;

                  Ubah_Atlet_yang_Didalam_Klub(LA,LR,IDKlub,idNama,IdKlubBaru);

           } else if(Klik == 15){

    cout << "   =============================================================   " << endl;
    cout << "   |               TERIMA KASIH!                               |   " << endl;
    cout << "   |                                                           |  " << endl;
    cout << "   |  Anda telah menggunakan aplikasi kami.                    | " << endl;
    cout << "   |  Semoga hari Anda menyenangkan!                           |   " << endl;
    cout << "   =============================================================    " << endl;
    cout << endl;

    cout << "   Dibuat oleh:" << endl;
    cout << "   - MUHAMMAD AZKA DARMAWAN" << endl;
    cout << "   - ALIF RIZQI ASY-SYIFA EFFENDIE" << endl;
    cout << "     Kelas: IT-47-04" << endl;
    cout << endl;
            Exit = true;


           }

            }

    }
