/*
Kullan�c�y� say� girmeye zorlar ve girilen say�y� geri d�nd�r�r.
*/

#ifndef SAYIGIR_H
#define SAYIGIR_H
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include "../lib/matematik.h" // https://github.com/seymenkonuk/Matematik-C

int sayiGirAralik(int min, int maks);
int sayiGir();                        // INT limitleri i�erisinde istedi�i de�eri girebilir

int sayiGirAralik(int min, int maks) {
    int sayi = 0;
    int i = 1, isaret = 0; char k;
    while (1) {
        k = getch();
        if (i==1 && isaret == 0 && (k=='+' || k=='-')) { // ilk karakter i�aret olabilir
            if (k=='+') isaret = 1;
            else isaret = -1;
            printf("%c", k);
        } else if (k>='0' && k<='9' && (sayi != 0 || i==1)) { // rakama bas�ld�ysa
            int yeniSayi = sayi*10 + (k-48);
            if (sayi == 0 || basamak(sayi) + 1 == basamak(yeniSayi) && yeniSayi/10 == sayi) { // INT limitleri i�erisindeyse
                int yeniIsaret = isaret;
                if (isaret == 0) yeniIsaret = 1;
                sayi = yeniSayi;
                i++;
                printf("%c", k);
            }
        } else if (i==1 && isaret != 0 && k==8) { // isareti silmek
            isaret = 0;
            printf("%c %c", k, k);
        } else if (i>1 && k==8) { // say�y� silmek
            i--;
            sayi = sayi / 10;
            printf("%c %c", k, k);
        } else if (k == '\r' && i>1) {// entera bas�ld�ysa
            int yeniIsaret = isaret;
            if (isaret == 0) yeniIsaret = 1;
            if (sayi*yeniIsaret >= min && sayi*yeniIsaret <= maks) { // limitler i�erisindeyse
                if (isaret == 0) isaret = 1;
                break;
            }
        }
    }
    printf("\n");
    return isaret*sayi;
}

int sayiGir() {
    return sayiGirAralik(INT_MIN, INT_MAX);
}
#endif
