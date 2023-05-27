#include <iostream>
#include <conio.h>
using namespace std;

int baris, kolom, baris1, kolom1, baris2, kolom2, baris3, kolom3;
int area1, area2, area3, area4, area11, area21, area31, area41;
float MatriksA[10][10], MatriksB[10][10];
int matriks[50][50], transpose[50][50], transpose1[50][50];
int hasil[10][10] = {0};
int ordo, det, det1, det2, det3;
float angka;
float skalar;
float a1[10][10];
float b1[10][10];
float invers[10][10], invers1[10][10];

void penjumlahan();
void pengurangan();
void perkalian();
void determinan();
void transposeMatriks();
void skalarMatriks();
void operasi();
void inversA();

int main()
{
    int pilih;
    lompat:
    do{
        system("cls");
        cout << "============================================" << endl;
        cout << "===               MENU                   ===" << endl;
        cout << "===           A11.2021.13456             ===" << endl;
        cout << "============================================" << endl;
        cout << "= 1. Penjumlahan Matriks                   =" << endl;
        cout << "= 2. Pengurangan Matriks                   =" << endl;
        cout << "= 3. Perkalian Matriks                     =" << endl;
        cout << "= 4. Determinan Matriks                    =" << endl;
        cout << "= 5. Transpose Matriks                     =" << endl;
        cout << "= 6. Perkalian Matriks dengan Skalar       =" << endl;
        cout << "= 7. Invers Matriks Ordo 2                 =" << endl;
        cout << "= 8. Semua Operasi                         =" << endl;
        cout << "= 9. Keluar                                =" << endl;
        cout << "============================================" << endl;
        cout << "Masukkan pilihan: "; cin>>pilih;

        if(pilih==1){
            system("cls");
            penjumlahan();
            goto lompat;
        }

        if(pilih==2){
            system("cls");
            pengurangan();
            goto lompat;
        }

        if(pilih==3){
            system("cls");
            perkalian();
            goto lompat;
        }

        if(pilih==4){
            system("cls");
            determinan();
            goto lompat;
        }

        if(pilih==5){
            system("cls");
            transposeMatriks();
            goto lompat;
        }
        if(pilih==6){
            system("cls");
            skalarMatriks();
            goto lompat;
        }
        if(pilih==7){
            system("cls");
            inversA();
            goto lompat;
        }
        if(pilih==8){
            system("cls");
            operasi();
            goto lompat;
        }
    }while(pilih!=9);
    cout << "Hello world!" << endl;
    return 0;
}

void penjumlahan(){
    cout << "Masukkan baris: "; cin>>baris;
    cout << "Masukkan kolom: "; cin>>kolom;
    cout << "Input Matriks A: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksA[i][j];
        }
    }
    cout << "Input Matriks B: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksB[i][j];
        }
    }
    cout << "Matriks A: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << MatriksA[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Matriks B: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << MatriksB[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Hasil Penjumlahan Matriks A dan Matriks B: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            hasil[i][j] = MatriksA[i][j] + MatriksB[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    getch();
}

void pengurangan(){
    cout << "Masukkan baris: "; cin>>baris;
    cout << "Masukkan kolom: "; cin>>kolom;

    cout << "Input Matriks A: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksA[i][j];
        }
    }
    cout << "Input Matriks B: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksB[i][j];
        }
    }
    cout << "Matriks A: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << MatriksA[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Matriks B: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << MatriksB[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Hasil Pengurangan Matriks A dan Matriks B: " << endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            hasil[i][j] = MatriksA[i][j] - MatriksB[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    getch();
}

void perkalian(){
    lompat:
    cout << "Masukkan baris Matriks A: "; cin>>baris1;
    cout << "Masukkan kolom Matriks A: "; cin>>kolom1;
    cout << "Masukkan baris Matriks B: "; cin>>baris2;
    cout << "Masukkan kolom Matriks B: "; cin>>kolom2;

    if(kolom1 != baris2){
        cout << "Matriks tidak dapat dikalikan" << endl;
        goto lompat;
    }
    else{
        cout << "Input Matriks A: " << endl;
        for(int i=0; i<baris1; i++){
            for(int j=0; j<kolom1; j++){
                cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksA[i][j];
            }
        }
        cout << "Input Matriks B: " << endl;
        for(int i=0; i<baris2; i++){
            for(int j=0; j<kolom2; j++){
                cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksB[i][j];
            }
        }

        cout << "Matriks A: " << endl;
        for(int i=0; i<baris1; i++){
            for(int j=0; j<kolom1; j++){
                cout << MatriksA[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "Matriks B: " << endl;
        for(int i=0; i<baris2; i++){
            for(int j=0; j<kolom2; j++){
                cout << MatriksB[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "Hasil Perkalian Matriks A dan Matriks B: " << endl;
        for(int i=0; i<baris1; i++){
            for(int j=0; j<kolom1; j++){
                for(int k=0; k<baris2; k++){
                    hasil[i][j] = hasil[i][j] + MatriksA[i][k] * MatriksB[k][j];
                }
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }
    }
    cout << endl;
    getch();
}

void determinan(){
    cout << "Masukkan ordo (2, 3 atau 4): "; cin>>ordo;
    if((ordo<2) || (ordo>4)){
        cout << "Ordo yang di inputkan merupakan 2, 3 dan 4" << endl;
    }
    else{
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksA[i][j];
            }
        }

        cout << "Matriks: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                cout << MatriksA[i][j] << "\t";
            }
            cout << endl;
        }

        if(ordo==2){
            det = MatriksA[0][0]*MatriksA[1][1] - MatriksA[0][1]*MatriksA[1][0];
            cout << "Determinan matriks " << ordo << " x " << ordo << " adalah " << det << endl;
        }
        if(ordo==3){
            det = MatriksA[0][0]*MatriksA[1][1]*MatriksA[2][2] + MatriksA[0][1]*MatriksA[1][2]*MatriksA[2][0] + MatriksA[0][2]*MatriksA[1][0]*MatriksA[2][1]
             - MatriksA[0][2]*MatriksA[1][1]*MatriksA[2][0] - MatriksA[0][0]*MatriksA[1][2]*MatriksA[2][1] - MatriksA[0][1]*MatriksA[1][0]*MatriksA[2][2];
            cout << "Determinan matriks " << ordo << " x " << ordo << " adalah " << det << endl;
        }
        if(ordo==4){
            area1 = (MatriksA[1][1]*MatriksA[2][2]*MatriksA[3][3])+(MatriksA[1][2]*MatriksA[2][3]*MatriksA[3][1])+(MatriksA[1][3]*MatriksA[2][1]*MatriksA[3][2])
             - (MatriksA[3][1]*MatriksA[2][2]*MatriksA[1][3])-(MatriksA[3][2]*MatriksA[2][3]*MatriksA[1][1])-(MatriksA[3][3]*MatriksA[2][1]*MatriksA[1][2]);

            area2 = (MatriksA[1][0]*MatriksA[2][2]*MatriksA[3][3])+(MatriksA[1][2]*MatriksA[2][3]*MatriksA[3][0])+(MatriksA[1][3]*MatriksA[2][0]*MatriksA[3][2])
             - (MatriksA[3][0]*MatriksA[2][2]*MatriksA[1][3])-(MatriksA[3][2]*MatriksA[2][3]*MatriksA[1][0])-(MatriksA[3][3]*MatriksA[2][0]*MatriksA[1][2]);

            area3 = (MatriksA[1][0]*MatriksA[2][1]*MatriksA[3][3])+(MatriksA[1][1]*MatriksA[2][3]*MatriksA[3][0])+(MatriksA[1][3]*MatriksA[2][0]*MatriksA[3][1])
             - (MatriksA[2][1]*MatriksA[1][3]*MatriksA[3][0])-(MatriksA[3][1]*MatriksA[2][3]*MatriksA[1][0])-(MatriksA[3][3]*MatriksA[2][0]*MatriksA[1][1]);

            area4 = (MatriksA[1][0]*MatriksA[2][1]*MatriksA[3][2])+(MatriksA[1][1]*MatriksA[2][2]*MatriksA[3][0])+(MatriksA[1][2]*MatriksA[2][0]*MatriksA[3][1])
             - (MatriksA[3][0]*MatriksA[2][1]*MatriksA[1][2])-(MatriksA[3][1]*MatriksA[2][2]*MatriksA[1][0])-(MatriksA[3][2]*MatriksA[2][0]*MatriksA[1][1]);

            det = (area1*MatriksA[0][0]*1) + (area2*MatriksA[0][1]*-1) + (area3*MatriksA[0][2]*1) + (area4*MatriksA[0][3]*-1);
            cout << "Determinan matriks: " << ordo << " x " << ordo << " adalah " << det << endl;
        }
    }
    cout << endl;
    getch();
}

void transposeMatriks(){
    cout << "Masukkan jumlah baris : "; cin >> baris3;
    cout << "Masukkan jumlah kolom : "; cin >> kolom3;
    cout << "Masukkan elemen matriks " << endl;
    for (int i = 0; i < baris3; i++){
        for (int j = 0; j < kolom3; j++){
            cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : "; cin>>matriks[i][j];
        }
    }
    cout << "Matriks: " << endl;
    for (int i = 0; i < baris3; i++){
        for (int j = 0; j < kolom3; j++){
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < baris3; i++){
        for (int j = 0; j < kolom3; j++){
            transpose[j][i] = matriks[i][j];
        }
    }
    cout << "Hasil Transpose Matriks: " << endl;
    for (int i = 0; i < kolom3; i++){
        for (int j = 0; j < baris3; j++){
            cout << transpose[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    getch();
}

void skalarMatriks(){
    float hasil1[10][10];
    cout << "Masukkan jumlah baris : "; cin >> baris;
    cout << "Masukkan jumlah kolom : "; cin >> kolom;
    cout << "Masukkan angka: "; cin>>angka;
    cout << "Masukkan elemen matriks " << endl;
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : "; cin>>MatriksA[i][j];
        }
    }
    cout << "Matriks: " << endl;
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            cout << MatriksA[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Hasil perkalian matriks dengan skalar = " << angka << " adalah: " << endl;
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            hasil1[i][j] = angka * MatriksA[i][j];
            cout << hasil1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void operasi(){
    float hasil1[10][10];
    cout << "Masukkan ordo (2, 3 atau 4): "; cin>>ordo;
    if((ordo<2) || (ordo>4)){
        cout << "Ordo yang di inputkan merupakan 2, 3 dan 4" << endl;
    }
    else{
        cout << "Masukkan skalar: "; cin>>skalar;
        cout << "Input Matriks A: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksA[i][j];
            }
        }

        cout << "Input Matriks B: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksB[i][j];
            }
        }

        cout << endl;

        cout << "Matriks A: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                cout << MatriksA[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Matriks B: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                cout << MatriksB[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Hasil Penjumlahan Matriks A dan Matriks B: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                hasil[i][j] = MatriksA[i][j] + MatriksB[i][j];
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Hasil Pengurangan Matriks A dan Matriks B: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                hasil[i][j] = MatriksA[i][j] - MatriksB[i][j];
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Hasil Perkalian Matriks A dan Matriks B: " << endl;
        for(int i=0; i<ordo; i++){
            for(int j=0; j<ordo; j++){
                for(int k=0; k<ordo; k++){
                    hasil[i][j] = hasil[i][j] + MatriksA[i][k] * MatriksB[k][j];
                }
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        if(ordo==2){
            det = MatriksA[0][0]*MatriksA[1][1] - MatriksA[0][1]*MatriksA[1][0];
            cout << "Determinan matriks A: " << ordo << " x " << ordo << " adalah " << det << endl;
            det1 = MatriksB[0][0]*MatriksB[1][1] - MatriksB[0][1]*MatriksB[1][0];
            cout << "Determinan matriks B: " << ordo << " x " << ordo << " adalah " << det1 << endl;
        }
        if(ordo==3){
            det = MatriksA[0][0]*MatriksA[1][1]*MatriksA[2][2] + MatriksA[0][1]*MatriksA[1][2]*MatriksA[2][0] + MatriksA[0][2]*MatriksA[1][0]*MatriksA[2][1] - MatriksA[0][2]*MatriksA[1][1]*MatriksA[2][0] - MatriksA[0][0]*MatriksA[1][2]*MatriksA[2][1] - MatriksA[0][1]*MatriksA[1][0]*MatriksA[2][2];
            cout << "Determinan matriks A: " << ordo << " x " << ordo << " adalah " << det << endl;
            det1 = MatriksB[0][0]*MatriksB[1][1]*MatriksB[2][2] + MatriksB[0][1]*MatriksB[1][2]*MatriksB[2][0] + MatriksB[0][2]*MatriksB[1][0]*MatriksB[2][1] - MatriksB[0][2]*MatriksB[1][1]*MatriksB[2][0] - MatriksB[0][0]*MatriksB[1][2]*MatriksB[2][1] - MatriksB[0][1]*MatriksB[1][0]*MatriksB[2][2];
            cout << "Determinan matriks B: " << ordo << " x " << ordo << " adalah " << det1 << endl;
        }
        if(ordo==4){
            area1 = (MatriksA[1][1]*MatriksA[2][2]*MatriksA[3][3])+(MatriksA[1][2]*MatriksA[2][3]*MatriksA[3][1])+(MatriksA[1][3]*MatriksA[2][1]*MatriksA[3][2]) - (MatriksA[3][1]*MatriksA[2][2]*MatriksA[1][3])-(MatriksA[3][2]*MatriksA[2][3]*MatriksA[1][1])-(MatriksA[3][3]*MatriksA[2][1]*MatriksA[1][2]);
            area2 = (MatriksA[1][0]*MatriksA[2][2]*MatriksA[3][3])+(MatriksA[1][2]*MatriksA[2][3]*MatriksA[3][0])+(MatriksA[1][3]*MatriksA[2][0]*MatriksA[3][2]) - (MatriksA[3][0]*MatriksA[2][2]*MatriksA[1][3])-(MatriksA[3][2]*MatriksA[2][3]*MatriksA[1][0])-(MatriksA[3][3]*MatriksA[2][0]*MatriksA[1][2]);
            area3 = (MatriksA[1][0]*MatriksA[2][1]*MatriksA[3][3])+(MatriksA[1][1]*MatriksA[2][3]*MatriksA[3][0])+(MatriksA[1][3]*MatriksA[2][0]*MatriksA[3][1]) - (MatriksA[2][1]*MatriksA[1][3]*MatriksA[3][0])-(MatriksA[3][1]*MatriksA[2][3]*MatriksA[1][0])-(MatriksA[3][3]*MatriksA[2][0]*MatriksA[1][1]);
            area4 = (MatriksA[1][0]*MatriksA[2][1]*MatriksA[3][2])+(MatriksA[1][1]*MatriksA[2][2]*MatriksA[3][0])+(MatriksA[1][2]*MatriksA[2][0]*MatriksA[3][1]) - (MatriksA[3][0]*MatriksA[2][1]*MatriksA[1][2])-(MatriksA[3][1]*MatriksA[2][2]*MatriksA[1][0])-(MatriksA[3][2]*MatriksA[2][0]*MatriksA[1][1]);

            det = (area1*MatriksA[0][0]*1) + (area2*MatriksA[0][1]*-1) + (area3*MatriksA[0][2]*1) + (area4*MatriksA[0][3]*-1);
            cout << "Determinan matriks A: " << ordo << " x " << ordo << " adalah " << det << endl;

            area11 = (MatriksB[1][1]*MatriksB[2][2]*MatriksB[3][3])+(MatriksB[1][2]*MatriksB[2][3]*MatriksB[3][1])+(MatriksB[1][3]*MatriksB[2][1]*MatriksB[3][2]) - (MatriksB[3][1]*MatriksB[2][2]*MatriksB[1][3])-(MatriksB[3][2]*MatriksB[2][3]*MatriksB[1][1])-(MatriksB[3][3]*MatriksB[2][1]*MatriksB[1][2]);
            area21 = (MatriksB[1][0]*MatriksB[2][2]*MatriksB[3][3])+(MatriksB[1][2]*MatriksB[2][3]*MatriksB[3][0])+(MatriksB[1][3]*MatriksB[2][0]*MatriksB[3][2]) - (MatriksB[3][0]*MatriksB[2][2]*MatriksB[1][3])-(MatriksB[3][2]*MatriksB[2][3]*MatriksB[1][0])-(MatriksB[3][3]*MatriksB[2][0]*MatriksB[1][2]);
            area31 = (MatriksB[1][0]*MatriksB[2][1]*MatriksB[3][3])+(MatriksB[1][1]*MatriksB[2][3]*MatriksB[3][0])+(MatriksB[1][3]*MatriksB[2][0]*MatriksB[3][1]) - (MatriksB[2][1]*MatriksB[1][3]*MatriksB[3][0])-(MatriksB[3][1]*MatriksB[2][3]*MatriksB[1][0])-(MatriksB[3][3]*MatriksB[2][0]*MatriksB[1][1]);
            area41 = (MatriksB[1][0]*MatriksB[2][1]*MatriksB[3][2])+(MatriksB[1][1]*MatriksB[2][2]*MatriksB[3][0])+(MatriksB[1][2]*MatriksB[2][0]*MatriksB[3][1]) - (MatriksB[3][0]*MatriksB[2][1]*MatriksB[1][2])-(MatriksB[3][1]*MatriksB[2][2]*MatriksB[1][0])-(MatriksB[3][2]*MatriksB[2][0]*MatriksB[1][1]);

            det1 = (area11*MatriksB[0][0]*1) + (area21*MatriksB[0][1]*-1) + (area31*MatriksB[0][2]*1) + (area41*MatriksB[0][3]*-1);
            cout << "Determinan matriks B: " << ordo << " x " << ordo << " adalah " << det1 << endl;
        }

        cout << endl;

        for (int i = 0; i < ordo; i++){
            for (int j = 0; j < ordo; j++){
                transpose[j][i] = MatriksA[i][j];
            }
        }
        cout << "Hasil Transpose Matriks A: " << endl;
        for (int i = 0; i < ordo; i++){
            for (int j = 0; j < ordo; j++){
                cout << transpose[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < ordo; i++){
            for (int j = 0; j < ordo; j++){
                transpose1[j][i] = MatriksB[i][j];
            }
        }
        cout << "Hasil Transpose Matriks B: " << endl;
        for (int i = 0; i < ordo; i++){
            for (int j = 0; j < ordo; j++){
                cout << transpose1[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Hasil perkalian matriks A dengan skalar = " << skalar << " adalah: " << endl;
        for (int i = 0; i < ordo; i++){
            for (int j = 0; j < ordo; j++){
                hasil[i][j] = skalar * MatriksA[i][j];
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Hasil perkalian matriks B dengan skalar = " << skalar << " adalah: " << endl;
        for (int i = 0; i < ordo; i++){
            for (int j = 0; j < ordo; j++){
                hasil1[i][j] = skalar * MatriksB[i][j];
                cout << hasil1[i][j] << "\t ";
            }
            cout << endl;
        }

        cout << endl;

        if(ordo == 2){
            det2=(MatriksA[0][0]*MatriksA[1][1])-(MatriksA[0][1]*MatriksA[1][0]);
            cout << "Determinan Matriks A: " << det2 << endl;
            //Pembalikan
            //b1[i][j];
            a1[0][0]=MatriksA[1][1];
            a1[1][1]=MatriksA[0][0];
            a1[0][1]=-1*MatriksA[0][1];
            a1[1][0]=-1*MatriksA[1][0];

            //invers
            for(int i = 0; i < ordo; i++){
                for(int j = 0; j < ordo; j++){
                    invers[i][j]=a1[i][j]/det2;
                }
            }

            //Menampilkan
            cout <<"Hasil Invers Matriks A : " << endl;
            for(int i = 0; i < ordo; i++){
                for(int j = 0; j < ordo; j++){
                    cout << invers[i][j] << "\t";
                }
                cout << endl;
            }

            det3=(MatriksB[0][0]*MatriksB[1][1])-(MatriksB[0][1]*MatriksB[1][0]);
            cout << "Determinan Matriks B: " << det3 << endl;
            //Pembalikan
            //b1[i][j];
            b1[0][0]=MatriksB[1][1];
            b1[1][1]=MatriksB[0][0];
            b1[0][1]=-1*MatriksB[0][1];
            b1[1][0]=-1*MatriksB[1][0];

            //invers
            for(int i = 0; i < ordo; i++){
                for(int j = 0; j < ordo; j++){
                    invers1[i][j]=b1[i][j]/det3;
                }
            }

            //Menampilkan
            cout <<"Hasil Invers Matriks B : " << endl;
            for(int i = 0; i < ordo; i++){
                for(int j = 0; j < ordo; j++){
                    cout << invers1[i][j] << "\t";
                }
                cout << endl;
            }
        }
        else{
            cout << "Invers sekarang hanya untuk 2 x 2 saja :(" << endl;
         }
    }
    getch();
}

void inversA(){
    float b1[10][10];
    int ordo = 2;
    float invers[10][10];
    int det2;

    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            cout << "Input elemen baris ke-" << i << " kolom ke-"<< j << " : ";cin>>MatriksA[i][j];
        }
    }
    det2 = MatriksA[0][0]*MatriksA[1][1]- MatriksA[0][1]*MatriksA[1][0];
    cout << "Determinan Matriks A: " << det2 << endl;

    b1[0][0]=MatriksA[1][1];
    b1[0][1]=-1*MatriksA[0][1];
    b1[1][0]=-1*MatriksA[1][0];
    b1[1][1]=MatriksA[0][0];

    for(int i = 0; i < ordo; i++){
        for(int j = 0; j < ordo; j++){
            invers[i][j]=b1[i][j]/det2;
        }
    }

    cout <<"Hasil Invers Matriks A : " << endl;
    for(int i = 0; i < ordo; i++){
        for(int j = 0; j < ordo; j++){
            cout << invers[i][j] << "\t";
        }
        cout << endl;
    }
    getch();
}
