/*
Baz� Matematiksel ��levleri Bar�nd�r�r
*/

#ifndef MATEMATIK_H
#define MATEMATIK_H
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

int usAlma(int taban, int us);                                    // "taban" �zeri "us" i�leminin sonucunu d�nd�r�r.
int faktoriyel(int sayi);                                         // "sayi"nin fakt�riyelini d�nd�r�r.
int fibonacci(int terimNo);                                       // fibonacci dizisinin n. terimini d�nd�r�r.
bool asalMi(int sayi);                                            // "sayi"nin asal olup olmad���n� d�nd�r�r.
int mutlak(int sayi);                                             // "sayi"nin mutlak de�erini d�nd�r�r.
int tersi(int sayi);                                              // "sayi"nin tersten yaz�lm���n� d�nd�r�r. 123 -> 321
int basamak(int sayi);                                            // "sayi"nin basamak say�s�n� d�nd�r�r.
float karekok(float sayi);                                        // "sayi"nin karek�k�n� d�nd�r�r.
int yuvarla(int sayi, int kat);                                   // say�y�; "sayi"ya en yak�n, "kat" de�i�kenin tam kat�na yuvarlar.
int yuvarlaBasamak(int sayi, int basamak);                        // say�y�, sa�dan n basamak 0 olacak �ekilde yuvarlar.
void metneDonustur(int sayi, char sonuc[]);                       // "sayi"yi metin format�nda "sonuc" dizisine yazar.
void sirala1(int adet, int sayilar[adet], bool kucuktenBuyugeMi); // diziyi "kucuktenBuyugeMi" de�erine g�re s�ralar.
void sirala2(int adet, int sayilar[adet], bool kucuktenBuyugeMi); // diziyi "kucuktenBuyugeMi" de�erine g�re s�ralar.
int sayiAra(int aranan, int adet, int siralanmisSayilar[adet]);   // k���kten b�y��e s�ralanm�� bir say� dizisinde bir say�n�n index numaras�n� d�nd�r�r, yoksa -1 d�nd�r�r.
int ebob(int s1, int s2);                                         // iki say�n�n en b�y�k ortak b�lenini d�nd�r�r.
int ekok(int s1, int s2);                                         // iki say�n�n en k���k ortak kat�n� d�nd�r�r
int cokEbob(int adet, int sayilar[adet]);                         // say�lar dizisindeki say�lar�n ebobunu d�nd�r�r.
int cokEkok(int adet, int sayilar[adet]);                         // say�lar dizisindeki say�lar�n ekokunu d�nd�r�r.
int enBuyukAsalBolen(int sayi);                                   // "sayi"nin en b�y�k asal b�lenini d�nd�r�r.

int usAlma(int taban, int us) {
    if (us < 0) return -1;
    if (us == 0) return 1;
    if (us == 1) return taban;
    if (us % 2 == 0)
        return usAlma(taban*taban, us/2);
    else
        return taban*usAlma(taban, us-1);
}

int faktoriyel(int sayi) {
    if (sayi < 0) return -1;
    if (sayi == 0 || sayi == 1) return 1;
    return sayi*faktoriyel(sayi-1);
}

int fibonacci(int terimNo) {
    if (terimNo <= 0) return -1;
    if (terimNo == 1) return 0;
    if (terimNo == 2) return 1;
    return fibonacci(terimNo-1) + fibonacci(terimNo-2);
}

bool asalMi(int sayi) {
    if (sayi == 2) return true;
    if (sayi % 2 == 0 || sayi < 2) return false;
    int bolen;
    for (bolen = 3; bolen <= karekok(sayi); bolen += 2)
        if (sayi % bolen == 0)
            return false;
    return true;
}

int mutlak(int sayi) {
    return (sayi < 0) ? -sayi : sayi;
}

int tersi(int sayi) {
    int isaret = (sayi >= 0);
    if (isaret == 0) isaret = -1;
    int sonuc = 0;
    for (sayi = mutlak(sayi); sayi > 0; sayi /= 10) sonuc = sonuc*10 + sayi%10;
    return sonuc*isaret;
}

int basamak(int sayi) {
    int sonuc = 1;
    for (; (sayi / 10) != 0; sayi /= 10) sonuc++;
    return sonuc;
}

float karekok(float sayi) {
    if (sayi < 0) return karekok(-sayi);
    float kok = (sayi + 1) / 2;
    while (1) {
        float depo = (kok + sayi / kok) / 2;
        if (depo == kok) return kok;
        kok = depo;
    }
}

int yuvarla(int sayi, int kat) {
    if (kat == 0) return sayi;
    if (kat < 0) return yuvarla(sayi, -kat); 
    int sonuc = sayi - (sayi % kat);
    if (sayi - sonuc >= (sonuc + kat) - sayi) sonuc += kat;
    return sonuc;
}

int yuvarlaBasamak(int sayi, int basamak) {
    if (basamak <= 0) return sayi;
    return yuvarla(sayi, usAlma(10, basamak));
}

void metneDonustur(int sayi, char sonuc[]) {
    int i = 0;
    if (sayi < 0) {
        sonuc[i] = '-';
        i++;
    }
    if (sayi == 0) {
        sonuc[i] = '0'; 
        i++;
    }
    for (sayi = tersi(mutlak(sayi)); sayi > 0; sayi /= 10) {
        sonuc[i] = (sayi % 10) + '0';
        i++;
    }
    sonuc[i] = '\0';
}

void sirala1(int adet, int sayilar[adet], bool kucuktenBuyugeMi) {
    int i, j;
    for (i=0; i<adet-1; i++) {
        for (j=0; j<adet-1; j++) {
            if ((sayilar[j] > sayilar[j+1] && kucuktenBuyugeMi) || (sayilar[j] < sayilar[j+1] && !kucuktenBuyugeMi)) {
                int depo = sayilar[j];
                sayilar[j] = sayilar[j+1];
                sayilar[j+1] = depo;
            }
        }
    }
}

void sirala2(int adet, int sayilar[adet], bool kucuktenBuyugeMi) {
    int i, j;
    for (i=0; i<adet-1; i++) {
        for (j=i+1; j<adet; j++) {
            if ((sayilar[i] > sayilar[j] && kucuktenBuyugeMi) || (sayilar[i] < sayilar[j] && !kucuktenBuyugeMi)) {
                int depo = sayilar[j];
                sayilar[j] = sayilar[i];
                sayilar[i] = depo;
            }
        }
    }
}

int sayiAra(int aranan, int adet, int siralanmisSayilar[adet]) {
    int bas = 0, bit = adet-1;
    while (1) {
        int index = (bit+bas)/2;
        if (aranan == siralanmisSayilar[index]) return index;
        if (bas == bit) return -1;
        if (aranan > siralanmisSayilar[index]) 
            bas = index+1;
        else 
            bit = index-1;
    }
}

int ebob(int s1, int s2) {
    if (s1 < 0) s1 = -s1;
    if (s2 < 0) s2 = -s2;
    if (s1 > s2) return ebob(s2, s1);
    int bolen;
    for (bolen=s1; bolen>=1; bolen--)
        if (s1%bolen==0 && s2%bolen==0)
            return bolen;
}

int ekok(int s1, int s2) {
    if (s1 < 0) s1 = -s1;
    if (s2 < 0) s2 = -s2;
    return (s1*s2)/ebob(s1, s2);
}

int cokEbob(int adet, int sayilar[adet]) {
    int sayi = sayilar[0]; int i;
    for (i=1; i<adet; i++) {
        sayi = ebob(sayi, sayilar[i]);
    }
    return sayi;
}

int cokEkok(int adet, int sayilar[adet]) {
    int sayi = 1, i, ortakBolen = cokEbob(adet, sayilar);
    for (i=0; i<adet; i++) {
        sayi *= (sayilar[i]/ortakBolen);
    }
    return sayi;
}

int enBuyukAsalBolen(int sayi) {
    if (sayi < 0) sayi = -sayi;
    if (sayi == 0 || sayi == 1) return -1;
    int bolen = 2;
    while (sayi > 1) {
        if (sayi % bolen == 0) sayi = sayi / bolen;
        else bolen++;
    }
    return bolen;
}
#endif
