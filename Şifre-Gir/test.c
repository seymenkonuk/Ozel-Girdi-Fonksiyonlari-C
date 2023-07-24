#include <stdio.h>
#include "sifreGir.h"
#include "../lib/metin.h"

main() {
    char sifre[100];
    esitle(sifre, sifreGir(NULL, NULL));
    printf("%s", sifre);
    while(1);
}
