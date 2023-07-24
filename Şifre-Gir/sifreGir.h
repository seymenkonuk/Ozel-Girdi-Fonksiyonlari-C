/*
Kullanýcýdan Þifre Ýster, Þifre Gizlenir ve Kurallara Uygun Þifre Girildiðinde 
Þifreyi Geriye Döndürür
*/

#ifndef SIFREGIR_H
#define SIFREGIR_H
#include <stdio.h>
#include <conio.h>
#include "../lib/metin.h" // https://github.com/seymenkonuk/Metin-C

const char* sifreGir(int kural[5], const char ozelKarakter[]); // Kullanýcýyý Kurallara Uygun Þifre Girmeye Zorlar
                                                               // Girilen Metin Ekranda Yýldýzlý Olarak Görünür.
                                                               // Girilen Þifre geriye döndürülür.
                                                               // Geriye döndürülen deðer "metin.h" dosyasýndaki esitle fonksiyonuyla bir diziye alýnabilir ve kullanýlabilir.

const char* sifreGir(int kural[5], const char ozelKarakter[]) {
    int kurallar[5], i;
    char ozelKarakterler[500];
    // Varsayýlan Kurallar
    if (kural == NULL) {
        kurallar[0] = 1; // En Az Büyük Harf Sayýsý
        kurallar[1] = 1; // En Az Küçük Harf Sayýsý
        kurallar[2] = 1; // En Az Rakam Sayýsý
        kurallar[3] = 1; // En Az Özel Harf Sayýsý
        kurallar[4] = 8; // En Az Uzunluk
    } else {
        for (i=0; i<5; i++) 
            kurallar[i] = kural[i];
    }
    
    // Varsayýlan Özel Karakterler
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
        
        if (karakter >= '0' && karakter <= '9') { // Rakama basýldýysa
            sifre[uzunluk] = karakter;
            uzunluk++;
            rakam++;
            printf("*");
        } else if (karakter >= 'a' && karakter <= 'z') { // Küçük Harfe Basýldýysa
            sifre[uzunluk] = karakter;
            uzunluk++;
            kucukharf++;
            printf("*");
        } else if (karakter >= 'A' && karakter <= 'Z') { // Büyük Harfe Basýldýysa
            sifre[uzunluk] = karakter;
            uzunluk++;
            buyukharf++;
            printf("*");
        } else if (karakter == '\r') { // Entera Basýldýysa
            // Herhangi Bir Kural Saðlanmýyorsa
            if (buyukharf < kurallar[0]);
            else if (kucukharf < kurallar[1]);
            else if (rakam < kurallar[2]);
            else if (ozelkarakter < kurallar[3]);
            else if (uzunluk < kurallar[4]);
            else break; // Tüm Kurallar Saðlanýyorsa
        } else if (karakter == 8) { // Backspace Tuþuna Basýldýysa
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
        } else { // Baþka Bir Tuþa Basýldýysa
            int i;
            for (i=0; ozelKarakterler[i] != '\0'; i++)
                if (ozelKarakterler[i] == karakter)
                    break;
            
            if (ozelKarakterler[i] != '\0') { // Özel Karaktere Basýldýysa
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
