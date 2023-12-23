//
//  main.c
//  Kısa_Sınav_2_Arda_Yigit_1230505022
//
//  Created by Arda Yiğit on 23.12.2023.
//

#include <stdio.h>
#include <string.h>

#define MAX_KATILIMCI 15 // Maksimum katılımcı sayısı

typedef struct {
    char isim[50];
    float teklif;
    int devam_et; // 1 devam etmek istiyor, 0 ise istemiyor
} Katilimci;

int main(void) {
    Katilimci katilimcilar[MAX_KATILIMCI];
    int katilimci_sayisi = 0;
    int devam_etme_istegi = 1; // Devam etmek isteyip istemediğini belirten değişken

    printf("Lutfen Teklif Veren Katilimcilarin Bilgilerini Giriniz:\n");

    // Katılımcıların bilgilerini alma döngüsü
    while (katilimci_sayisi < MAX_KATILIMCI && devam_etme_istegi) {
        printf("Katilimcinin Ismi =");
        scanf("%s", katilimcilar[katilimci_sayisi].isim);

        printf("Katilimcinin Teklifi = ");
        scanf("%f", &katilimcilar[katilimci_sayisi].teklif);

        printf("Devam etmek istiyor musunuz ? (1 = Evet / 0 = Hayir)= ");
        scanf("%d", &devam_etme_istegi);

        katilimcilar[katilimci_sayisi].devam_et = devam_etme_istegi;

        katilimci_sayisi++;
    }

    // Tüm teklifleri ekrana yazdıran kod.
    printf("\n\t   Tum Teklifler\n---------------------------\n");
    for (int i = 0; i < katilimci_sayisi; ++i) {
        printf("%s - %.2f\n", katilimcilar[i].isim, katilimcilar[i].teklif);
    }

    // Kazananı bulan ve ekrana yazdıran kod.
    float en_yuksek_teklif = katilimcilar[0].teklif;
    int kazanan_index = 0;

    for (int i = 1; i < katilimci_sayisi; ++i) {
        if (katilimcilar[i].teklif > en_yuksek_teklif) {
            en_yuksek_teklif = katilimcilar[i].teklif;
            kazanan_index = i;
        }
    }

    printf("\nKazanan: %s = %.2f\n\n", katilimcilar[kazanan_index].isim, katilimcilar[kazanan_index].teklif);

    return 0;
}

