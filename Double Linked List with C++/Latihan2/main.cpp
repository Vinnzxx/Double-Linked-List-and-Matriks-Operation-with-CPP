#include <iostream>

using namespace std;

struct dll{
    int kode;
    string nama;
    string pengarang;
    string penerbit;
    int halaman;
    int tahun;
    dll * next;
    dll * prev;
};

dll * head = NULL;
dll * tail = NULL;

void inputBuku(){
    dll * baru;
    baru = new dll;
    cout << "Inputkan kode      : "; cin >> baru -> kode;
    cout << "Inputkan nama buku : "; cin >> baru -> nama;
    cout << "Inputkan pengarang : "; cin >> baru -> pengarang;
    cout << "Inputkan penerbit  : "; cin >> baru -> penerbit;
    cout << "Inputkan halaman   : "; cin >> baru -> halaman;
    cout << "Inputkan tahun     : "; cin >> baru -> tahun;
    cout << endl;

    baru -> next = NULL;
    baru -> prev = NULL;

    if(head==NULL){ //jika list kosong
        head = baru;
        tail = baru;
        head -> next = tail;
        head -> prev = tail;
    }
    else{ //jika list sudah ada isinya
        baru -> next = head;
        head -> prev = baru;
        head = baru;
        tail -> next = head;
        head -> prev = tail;
    }
}

void tampilBuku(){
    dll * bantu;
    bantu = tail;
    if(tail==NULL){
        cout << "Data Masih Kosong" << endl;
    }
    else{
        cout << "Data Buku  : " << endl;
        do{
            cout << bantu -> kode << " " << bantu -> nama << " " << bantu -> pengarang << " " << bantu -> penerbit << " " << bantu -> halaman << " " << bantu->tahun << endl;
            bantu = bantu -> prev;
        }while(bantu!=tail);
    }cout << endl;
}

void hapusBukuBaru(){
    dll * hapus;
    if(head==NULL){
        cout << "Data Masih Kosong" << endl;
    }
    else if(head==tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        hapus = head;
        head = head -> next;
        delete hapus;
        tail -> next = head;
        head -> prev = tail;
    }
}

void hapusBukuLama(){
    dll *hapus;
    if(head==NULL){
        cout << "Data Masih Kosong" << endl;
    }
    else if(head==tail){
        delete head;
        head=NULL;
        tail=NULL;
    }
    else{
        hapus=tail;
        tail=tail->prev;
        delete hapus;
        tail->next=head;
        head->prev=tail;
    }
}

void hapusBuku(){
    dll *bantu;
    dll *hapus;
    bantu = head;
    if(head==NULL){
        cout << "Data Masih Kosong" << endl;
    }
    else{
        int kode;
        cout << "Masukkan kode buku: "; cin>>kode;
        do{
            if(kode == bantu->kode){
                if(head == tail){
                    head = NULL;
                    tail = NULL;
                    break;
                }
                else{
                   hapus=bantu;
                   bantu->prev->next = bantu->next;
                   bantu->next->prev = bantu->prev;
                   delete hapus;
                   tail->next = head;
                   head->prev = tail;
                   break;
                }
            }
            bantu = bantu->next;
        }while(bantu!=head);
    }cout << endl;
}

void sorting(){
    dll *bantu1, *bantu2;
    int kodetemp;
    string namatemp;
    string pengarangtemp;
    string penerbittemp;
    int halamantemp;
    int tahuntemp;

    bantu1 = head;
    if(head == NULL){
        cout << "Data kosong" << endl;
    }
    else{
        do{
            bantu2 = bantu1->next;
            do{
                if(bantu1->tahun > bantu2->tahun){
                    tahuntemp = bantu2->tahun;
                    bantu2->tahun = bantu1->tahun;
                    bantu1->tahun = tahuntemp;

                    kodetemp = bantu2->kode;
                    bantu2->kode = bantu1->kode;
                    bantu1->kode = kodetemp;

                    namatemp = bantu2->nama;
                    bantu2->nama = bantu1->nama;
                    bantu1->nama = namatemp;

                    pengarangtemp = bantu2->pengarang;
                    bantu2->pengarang = bantu1->pengarang;
                    bantu1->pengarang = pengarangtemp;

                    penerbittemp = bantu2->penerbit;
                    bantu2->penerbit = bantu1->penerbit;
                    bantu1->penerbit = penerbittemp;

                    halamantemp = bantu2->halaman;
                    bantu2->halaman = bantu1->halaman;
                    bantu1->halaman = halamantemp;
                }
                bantu2 = bantu2->next;
            }while(bantu2 != head);
            bantu1 = bantu1->next;
        }while(bantu1 != head->prev);
    }cout << endl;
}

void sorting1(){
    dll *bantu1, *bantu2;
    int kodetemp;
    string namatemp;
    string pengarangtemp;
    string penerbittemp;
    int halamantemp;
    int tahuntemp;

    bantu1 = head;
    if(head == NULL){
        cout << "Data kosong" << endl;
    }
    else{
        do{
            bantu2 = bantu1->next;
            do{
                if(bantu1->tahun < bantu2->tahun){
                    tahuntemp = bantu2->tahun;
                    bantu2->tahun = bantu1->tahun;
                    bantu1->tahun = tahuntemp;

                    kodetemp = bantu2->kode;
                    bantu2->kode = bantu1->kode;
                    bantu1->kode = kodetemp;

                    namatemp = bantu2->nama;
                    bantu2->nama = bantu1->nama;
                    bantu1->nama = namatemp;

                    pengarangtemp = bantu2->pengarang;
                    bantu2->pengarang = bantu1->pengarang;
                    bantu1->pengarang = pengarangtemp;

                    penerbittemp = bantu2->penerbit;
                    bantu2->penerbit = bantu1->penerbit;
                    bantu1->penerbit = penerbittemp;

                    halamantemp = bantu2->halaman;
                    bantu2->halaman = bantu1->halaman;
                    bantu1->halaman = halamantemp;
                }
                bantu2 = bantu2->next;
            }while(bantu2 != head);
            bantu1 = bantu1->next;
        }while(bantu1 != head->prev);
    }cout << endl;
}

void lihatbuku(){
    int lihat;

    dll *bantu;
    bantu = head;
    if (head==NULL){
        cout << "Data Kosong" << endl;
    }
    else{
        do{
            lompat:
            cout << "1. Lihat Buku" << endl;
            cout << "2. Sebelumnya" << endl;
            cout << "3. Selanjutnya" << endl;
            cout << "4. Keluar" << endl;
            cout << "pilih : "; cin >> lihat;
            switch(lihat){
                case 1: system("cls");{
                    cout << "Data Buku: " << endl;
                    cout << bantu -> kode << " " << bantu -> nama << " " << bantu -> pengarang << " " << bantu -> penerbit << " " << bantu -> halaman << " " << bantu->tahun << endl;
                    cout << endl;
                break;
                }
                case 2: system("cls");{
                    cout << "Data Buku: " << endl;
                    bantu = bantu->prev;
                    cout << bantu -> kode << " " << bantu -> nama << " " << bantu -> pengarang << " " << bantu -> penerbit << " " << bantu -> halaman << " " << bantu->tahun << endl;
                    cout << endl;
                    break;
                }
                case 3: system("cls");{
                    cout << "Data Buku: " << endl;
                    bantu = bantu->next;
                    cout << bantu -> kode << " " << bantu -> nama << " " << bantu -> pengarang << " " << bantu -> penerbit << " " << bantu -> halaman << " " << bantu->tahun << endl;
                    cout << endl;
                    break;
                }
            }
        }while(lihat!=4);
    }cout << endl;
}

void cariBuku(){
    dll *bantu;
    string cari;
    int ketemu = 0;
    if (head == NULL){
        cout << "Data Kosong" << endl;
    }
    else{
        cout << "Inputkan Nama Buku: ";cin >> cari;
        bantu = head;
        do{
            if (bantu->nama == cari){
                ketemu = 1;
                cout << "Data Buku yang Dicari: " << endl;
                cout << bantu->kode << " " << bantu->nama << " " << bantu->pengarang << " " << bantu->penerbit << " " << bantu->halaman << " " << bantu->tahun << endl;
            }
            bantu = bantu->next;
        } while (bantu != head);
        if (ketemu == 0){
            cout << "Data Buku " << cari << " Tidak Ditemukan" << endl;
        }cout << endl;
    }
}

int main()
{
    int pilih;
    do{
        //tampilbelakang();
        cout << "Online Book" << endl;
        cout << "1. Tambah Data Buku" << endl;
        cout << "2. Tampil Data Buku Urut Berdasarkan Tahun Terbaru" << endl;
        cout << "3. Tampil Data Buku Urut Berdasarkan Tahun Terlama" << endl;
        cout << "4. Hapus Buku Terbaru" << endl;
        cout << "5. Hapus Buku Terlama" << endl;
        cout << "6. Hapus Buku" << endl;
        cout << "7. Lihat Daftar Buku" << endl;
        cout << "8. Cari Buku" << endl;
        cout << "9. Keluar" << endl;
        cout << endl;
        cout << "Masukan Pilihan Anda (1-9) : "; cin>>pilih;

        switch(pilih){
            case 1: system("cls");{
                inputBuku();
                break;
            }
            case 2: system("cls");{
                sorting(); //desceding
                tampilBuku();
                break;
            }
            case 3: system("cls");{
                sorting1(); //ascending
                tampilBuku();
                break;
            }
            case 4: system("cls");{
                sorting1();
                hapusBukuBaru();
                tampilBuku();
                break;
            }
            case 5: system("cls");{
                sorting1();
                hapusBukuLama();
                tampilBuku();
                break;
            }
            case 6: system("cls");{
                sorting();
                hapusBuku();
                tampilBuku();
                break;
            }
            case 7: system("cls");{
                sorting();
                lihatbuku();
                break;
            }
            case 8: system("cls");{
                sorting();
                cariBuku();
                break;
            }
        }
    }while(pilih!=9);
    return 0;
}
