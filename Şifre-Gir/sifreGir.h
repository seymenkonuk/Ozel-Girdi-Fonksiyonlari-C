/*
Kullan�c�dan �ifre �ster, �ifre Gizlenir ve Kurallara Uygun �ifre Girildi�inde 
�ifreyi Geriye D�nd�r�r
*/

#ifndef SIFREGIR_H
#define SIFREGIR_H
#include <stdio.h>
#include <conio.h>
#include "../lib/metin.h" // https://github.com/seymenkonuk/Metin-C

const char* sifreGir(int kural[5], const char ozelKarakter[]); // Kullan�c�y� Kurallara Uygun �ifre Girmeye Zorlar
                                                               // Girilen Metin Ekranda Y�ld�zl� Olarak G�r�n�r.
                                                               // Girilen �ifre geriye d�nd�r�l�r.
                                                               // Geriye d�nd�r�len de�er "metin.h" dosyas�ndaki esitle fonksiyonuyla bir diziye al�nabilir ve kullan�labilir.

const char* sifreGir(int kural[5], const char ozelKarakter[]) {
    int kurallar[5], i;
    char ozelKarakterler[500];
    // Varsay�lan Kurallar
    if (kural == NULL) {
        kurallar[0] = 1; // En Az B�y�k Harf Say�s�
        kurallar[1] = 1; // En Az K���k Harf Say�s�
        kurallar[2] = 1; // En Az Rakam Say�s�
        kurallar[3] = 1; // En Az �zel Harf Say�s�
        kurallar[4] = 8; // En Az Uzunluk
    } else {
        for (i=0; i<5; i++) 
            kurallar[i] = kural[i];
    }
    
    // Varsay�lan �zel Karakterler
    if (ozelKarakter == NULL) {
        ozelKarakterler[0] = '?';
        ozelKarakterler[1] = '@';
        ozelKarakterler[2] = '!';
        ozelKarakterler[3] = '#';
        ozelKarakterler[4] = '%';
        ozelKarakterler[5] = '+';
        ozelKarakterler[6] = '-';
        ozelKarakterler[7] = '*';
        ozelKarakterler[8] = '/';
        ozelKarakterler[9] = '_';
        ozelKarakterler[10] = '\0';
    } else {
        for (i=0; ozelKarakter[i] != '\0'; i++)  
            ozelKarakterler[i] = ozelKarakter[i];
        ozelKarakterler[i] = '\0';
    }
    
    int buyukharf = 0;
    int kucukharf = 0;
    int rakam = 0;
    int ozelkarakter = 0;
    int uzunluk = 0;
    
    char karakter;
    char sifre[100]; sifre[99] = '\0';
    
    while (1) {
        karakter = getch();
        
        if (karakter >= '0' && karakter <= '9') { // Rakama bas�ld�ysa
            sifre[uzunluk] = karakter;
            uzunluk++;
            rakam++;
            printf("*");
        } else if (karakter >= 'a' && karakter <= 'z') { // K���k Harfe Bas�ld�ysa
            sifre[uzunluk] = karakter;
            uzunluk++;
            kucukharf++;
            printf("*");
        } else if (karakter >= 'A' && karakter <= 'Z') { // B�y�k Harfe Bas�ld�ysa
            sifre[uzunluk] = karakter;
            uzunluk++;
            buyukharf++;
            printf("*");
        } else if (karakter == '\r') { // Entera Bas�ld�ysa
            // Herhangi Bir Kural Sa�lanm�yorsa
            if (buyukharf < kurallar[0]);
            else if (kucukharf < kurallar[1]);
            else if (rakam < kurallar[2]);
            else if (ozelkarakter < kurallar[3]);
            else if (uzunluk < kurallar[4]);
            else break; // T�m Kurallar Sa�lan�yorsa
        } else if (karakter == 8) { // Backspace Tu�una Bas�ld�ysa
            if (uzunluk > 0) { // Silinecek Karakter Varsa
                uzunluk--;
                if (sifre[uzunluk] >= 'A' && sifre[uzunluk] <= 'Z')
                    buyukharf--;
                else if (sifre[uzunluk] >= 'a' && sifre[uzunluk] <= 'z')
                    kucukharf--;
                else if (sifre[uzunluk] >= '0' && sifre[uzunluk] <= '9')
                    rakam--;
                else
                    ozelkarakter--;
                printf("%c %c", 8, 8);
            }
        } else { // Ba�ka Bir Tu�a Bas�ld�ysa
            int i;
            for (i=0; ozelKarakterler[i] != '\0'; i++)
                if (ozelKarakterler[i] == karakter)
                    break;
            
            if (ozelKarakterler[i] != '\0') { // �zel Karaktere Bas�ld�ysa
                sifre[uzunluk] = karakter;
                uzunluk++;
                ozelkarakter++;
                printf("*");
            }
        }
    }
    sifre[uzunluk] = '\0';
    printf("\n");
    const char* deger = sifre;
    return deger;
}
#endif
