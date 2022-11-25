#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *dosya;
    int sayi;
    char kelime[50];

    dosya = fopen("merhaba.txt", "r");

    while(!feof(dosya)){

    fscanf(dosya, "%d", &sayi);
    printf("%d ", sayi);
    }

    fclose(dosya);



}
