#include <stdio.h>  // Standart giris/cikis (printf, scanf)
#include <stdlib.h> // Genel araclar (rand, srand, system)
#include <time.h>   // Rastgele sayi uretimi icin zaman kutuphanesi

// --- RENK KODLARI (MAKRO) ---
// Konsol ciktilarini renklendirmek icin kullanilan ANSI kodlari.OPO
// Kodun okunabilirligini artirmak icin #define ile isimlendirdik.
#define HASAR "\033[31m"      // Kirmizi (Olumsuz durumlar)
#define BASARI "\033[32m"     // Yesil (Olumlu durumlar)
#define VARSAYILAN "\033[0m"  // Beyaz (Rengi sifirla)
#define BILGI "\033[34m"      // Mavi (Bilgilendirme)
#define UYARI "\033[33m"      // Sari (Uyari)

// --- PLATFORM KONTROLU ---
// Kodun Windows ve Linux/Mac sistemlerde sorunsuz calismasi icin
// on islemci (preprocessor) komutlari.
#ifdef _WIN32
    #include <windows.h>
    #define BEKLE(ms) Sleep(ms) // Windows icin bekleme fonksiyonu
#else
    #include <unistd.h>
    #define BEKLE(ms) sleep((ms) / 1000) // Linux icin bekleme fonksiyonu
#endif


// =========================================================
// YARDIMCI FONKSIYONLAR
// =========================================================

/*
 * Fonksiyon: panel_ciz
 * Amac: Oyuncunun anlik durumunu tablo seklinde gosterir.
 * Detay: %-17d formatini kullanarak metinleri sola hizalar ve duzenli gorunmesini saglar.
 */
void panel_ciz(int en, int sag, int yemek, int siginak) {
    printf("\n+-----------------------------------+\n");
    printf("| Enerji       : %-17d|\n", en);
    printf("| Saglik       : %-17d|\n", sag);
    printf("| Yemek Sayisi : %-17d|\n", yemek);
    
    // Siginak durumu 1 ise "VAR", 0 ise "YOK" yazdiralim
    if (siginak == 1){
        printf("| Siginak      : %-17s|\n", BASARI "VAR (Guvenli)" VARSAYILAN);
    }else{
        printf("| Siginak      : %-17s|\n", HASAR "YOK" VARSAYILAN);
    }
    printf("+-----------------------------------+\n");
}

/*
 * Fonksiyon: ekran_temizle
 * Amac: Konsoldaki eski yazilari silerek temiz bir sayfa acar.
 */
void ekran_temizle() {
    #ifdef _WIN32 
        system("cls");   // Windows komutu
    #else 
        system("clear"); // Unix komutu
    #endif
}

// Oyuncuya yapabilecegi hamleleri listeleyen menu fonksiyonu
void sonrakiadim(){
    printf("\n%s--- HAMLE SECIMI ---%s\n", BILGI, VARSAYILAN);
    printf("[A] -> Avlan (Yemek bul)\n");
    printf("[S] -> Siginak insa et\n");
    printf("[E] -> Durumuna bak ve YEMEK YE\n");
    printf("[R] -> Dinlen (Can/Enerji yenile)\n");
    printf("[F] -> Bolge Kesfi (Riskli!)\n");
    printf("[P] -> Antik Kapi (Sifre Coz)\n");
    printf("[X] -> Oyunu Kapat\n");
    printf("Ne yapacaksin?: ");
}


// =========================================================
// OYUN MEKANIKLERI (POINTER KULLANIMI)
// =========================================================

/*
 * ONEMLI NOT:
 * Asagidaki tum fonksiyonlarda degiskenlerin degerini degil,
 * ADRESLERINI (Pointer) parametre olarak aliyoruz.
 * Boylece fonksiyon icinde yapilan degisiklikler ana programi (main) etkiliyor.
 */

// 1. AVLANMA FONKSIYONU
void avlan(int *saglik_ptr, int *enerji_ptr, int *yemek_sayisi_ptr) {
    int enerji_kaybi = 20; 
    
    // Yetersiz enerji kontrolu
    if (*enerji_ptr < enerji_kaybi) { 
        printf("%sAvlanmak icin cok yorgunsun! (Min 20 Enerji)%s\n", UYARI, VARSAYILAN);
        return; // Fonksiyondan cikis
    }
    
    // Pointer ile ana bellek adresindeki enerjiyi azaltiyoruz
    *enerji_ptr -= enerji_kaybi; 
    printf("%sIz suruyorsun... (Enerji -%d)%s\n", BILGI, enerji_kaybi, VARSAYILAN);
    BEKLE(500); // Kullanici okuyabilsin diye kisa bekleme

    // 1 ile 100 arasinda rastgele bir sayi uret
    int sans = rand() % 100 + 1; 
    int yemek_basarisi = 35; 
    int yaralanma_basarisi = 80; 

    // Olasilik Kontrolu (If - Else If - Else Yapisisi)
    if (sans <= yemek_basarisi) { 
        *yemek_sayisi_ptr += 1; // Basarili: Yemek artir
        printf("%sHARIKA! Bir geyik avladin! (+1 Yemek)%s\n", BASARI, VARSAYILAN);
    } 
    else if (sans > yaralanma_basarisi) { 
        int can_kaybi = 15; 
        *saglik_ptr -= can_kaybi; // Basarisiz: Hasar al
        printf("%sAKSIYLIK! Avlanirken dustun ve yaralandin. (-%d Saglik)%s\n", HASAR, can_kaybi, VARSAYILAN);
    }
    else { 
        printf("Uzun sure aradin ama elin bos donuyorsun.\n");
    }
}


// 2. SIGINAK BULMA FONKSIYONU
// Mantiksal Operatorlerin (&& ve ||) karmasik kullanim ornegi.
void siginak_bul(int *saglik_ptr, int *enerji_ptr, int *siginak_var_mi_ptr){
    // Zaten siginak varsa tekrar yapmasina gerek yok
    if (*siginak_var_mi_ptr == 1) {
        printf("Zaten guvenli bir kamp alanin var.\n");
        return;
    }

    if (*enerji_ptr < 25) {
        printf("%sSiginak insa etmek agir istir. En az 25 Enerji lazim.%s\n", UYARI, VARSAYILAN);
        return;
    }
    
    printf("Siginak icin uygun yer ve malzeme araniyor...\n");
    *enerji_ptr -= 15; 
    BEKLE(500);

    // Iki farkli sans faktoru
    int yer_bulma_sans = rand() % 100 + 1;
    int malzeme_sans = rand() % 100 + 1;

    // KOSUL: (Yer iyi VE Malzeme var) VEYA (Sans cok yuksek)
    if ((yer_bulma_sans > 45 && malzeme_sans > 45) || (yer_bulma_sans > 95)) {
        
        printf("%sUygun bir magara ve kuru odunlar buldun! Insaat basliyor...%s\n", BILGI, VARSAYILAN);
        BEKLE(500);
        *enerji_ptr -= 10; 
        *siginak_var_mi_ptr = 1; // Siginak durumunu 'Var' yap
        printf("%sBASARI! Artik firtinalardan korunabilecegin bir siginagin var.%s\n", BASARI, VARSAYILAN);

    } else {
        printf("%sBasarisiz oldun. Enerjin bosa gitti.%s\n", UYARI, VARSAYILAN);
    }
}


// 3. ENVANTER FONKSIYONU
// Bu fonksiyonda FOR dongusu ile grafik cizdiriyoruz.
void envanter(int *yemek_ptr, int *enerji_ptr, int *saglik_ptr){
    printf("\n========= KARAKTER DURUMU =========\n");
    
    // SAGLIK BARI CIZIMI:
    // Degeri 10'a bolerek kac tane kare (#) cizecegimizi buluyoruz.
    printf("Saglik : [");
    int saglik_bar = *saglik_ptr / 10; 
    
    for(int i=0; i<10; i++) { 
        if(i < saglik_bar) printf("#"); // Dolu kisim
        else printf(".");               // Bos kisim
    }
    printf("] %% %d\n", *saglik_ptr);

    // ENERJI BARI CIZIMI:
    printf("Enerji : [");
    int enerji_bar = *enerji_ptr / 10;
    for(int i=0; i<10; i++) {
        if(i < enerji_bar) printf("@");
        else printf(".");
    }
    printf("] %% %d\n", *enerji_ptr);

    printf("Canta  : %d Adet Konserve Yemek\n", *yemek_ptr);
    printf("===================================\n");

    // YEMEK YEME ETKILESIMI
    if (*yemek_ptr > 0) {
        
        // Eger her sey zaten 100 ise bosuna yemek harcatma
        if (*saglik_ptr == 100 && *enerji_ptr == 100) {
            printf("Karnin tok, sagligin yerinde.\n");
            return;
        }

        printf("\nBir adet yemek yemek ister misin? (+20 Saglik, +15 Enerji)\n");
        printf("(E)vet / (H)ayir: ");
        
        char secim;
        // BUFFER TEMIZLIGI: Onceki islemlerden kalan 'Enter' tusunu hafizadan siliyoruz.
        // Bunu yapmazsak scanf otomatik olarak enter'i okur ve gecer.
        char temp;
        while ((temp = getchar()) != '\n' && temp != EOF); 
        
        scanf("%c", &secim);

        if (secim == 'e' || secim == 'E') {
            // Pointerlar ile degerleri guncelliyoruz
            *yemek_ptr -= 1;   
            *saglik_ptr += 20; 
            *enerji_ptr += 15;
            
            // SINIR KONTROLU: Degerler 100'u asmamali
            if (*saglik_ptr > 100) *saglik_ptr = 100;
            if (*enerji_ptr > 100) *enerji_ptr = 100;

            printf("%sLezzetliydi! Kendine geldin.%s\n", BASARI, VARSAYILAN);
            BEKLE(800);
        } else {
            printf("Yemegi sonraya sakladin.\n");
        }
    } else {
        printf("%sCantanda yiyecek yok! Avlanman lazim.%s\n", HASAR, VARSAYILAN);
    }
}


// 4. DINLENME FONKSIYONU
void dinlen(int *saglik_ptr, int *enerji_ptr, int *siginak_var_mi_ptr) {
    // Saglik ve enerji tamsa dinlenmeye gerek yok
    if (*enerji_ptr >= 100 && *saglik_ptr >= 100) {
        printf("%sDinlenmeye ihtiyacin yok.%s\n", UYARI, VARSAYILAN);
        return;
    }

    printf("Kamp atesi yakildi, dinleniliyor...\n");
    int e_artis = 25;
    int s_artis = 15;

    // Eger siginak varsa daha verimli dinlenilir (Bonus)
    if (*siginak_var_mi_ptr == 1) {
        printf("%s(Siginak Bonusu Aktif)%s\n", BASARI, VARSAYILAN);
        e_artis += 15; 
        s_artis += 10; 
    } else {
        printf("Disarida uyumak tehlikeli ve konforsuz...\n");
    }

    // Ana degerleri artiriyoruz
    *enerji_ptr += e_artis;
    *saglik_ptr += s_artis;
}


// 5. TEHLIKE ARA FONKSIYONU
// FOR Dongusu kullanilarak "Olay Serisi" simule ediliyor.
void tehlikeAra(int *saglik_ptr, int *enerji_ptr, int *yemek_sayisi_ptr) {
    int bolge_sayisi = 4; // Toplam taranacak bolge sayisi
    
    printf("\n%s!!! BILINMEYEN BOLGEDE KESIF BASLADI !!!%s\n", BILGI, VARSAYILAN);
    
    // ZORUNLU: FOR Dongusu (1'den 4'e kadar doner)
    for (int i = 1; i <= bolge_sayisi; i++) {
        
        printf("\n--- %d. Bolge Taraniyor ---\n", i);
        BEKLE(600); 
        
        *enerji_ptr -= 5; 
        int olay_zari = rand() % 100 + 1;

        // COKLU SECIM YAPISI (ELSE-IF LADDER)
        
        // Senaryo 1: Tuzak (%25 ihtimal)
        if (olay_zari <= 25) { 
            printf("%sDIKKAT! Ayagin bir ayi kapanina takildi!%s\n", HASAR, VARSAYILAN);
            int hasar = 20; 
            *saglik_ptr -= hasar;
            printf("Can Kaybi: -%d\n", hasar);
        }
        // Senaryo 2: Yemek Bulma (Odul)
        else if (olay_zari > 25 && olay_zari <= 45) {
            printf("%sSanslisin! Terk edilmis bir cantada yemek buldun.%s\n", BASARI, VARSAYILAN);
            *yemek_sayisi_ptr += 1; 
            printf("Envanter Guncellendi: +1 Yemek\n");
        }
        // Senaryo 3: Saldiri
        else if (olay_zari > 45 && olay_zari <= 75) { 
            // Enerjiye bagli kacis kontrolu
            if (*enerji_ptr > 50) { 
                printf("Vahsi hayvan saldirdi ama hizla kacmayi basardin.\n");
                *enerji_ptr -= 15; 
            } else {
                printf("%sYorgun oldugun icin kacamadin ve isirildin!%s\n", HASAR, VARSAYILAN);
                *saglik_ptr -= 25; 
            }
        }
        // Senaryo 4: Bos bolge
        else {
            printf("Ruzgar sesinden baska bir sey yok. Temiz.\n");
        }

        // ARA KONTROL: Dongu icinde olum gerceklesirse donguyu kir (BREAK)
        if (*saglik_ptr <= 0) {
            printf("\n%sKesif sirasinda oldunuz...%s\n", HASAR, VARSAYILAN);
            break; // Donguyu sonlandir
        }
    } 

    // Dongu bittiginde hala hayattaysa tecrube puani ver
    if (*saglik_ptr > 0) {
        printf("\n%sKesif bitti. Tecrube kazandin.%s\n", BILGI, VARSAYILAN);
        *enerji_ptr += 5; 
    }
}


// 6. SIFRELI ILERLEME FONKSIYONU
// DO-WHILE Dongusu kullanilarak kullanici girisi dogrulama.
void sifreli_ilerleme(int *enerji_ptr){
    char cevap;
    char dogru_cevap = '&'; // C dilinde Bitwise AND operatoru
    
    printf("\n%sKarsinda antik bir kapi var. Sifreyi cozmelisin.%s\n", BILGI, VARSAYILAN);
    printf("SORU: C dilinde 'Bitwise AND' (Bitsel VE) operatoru hangisidir?\n");
    printf("(Cevap tek bir karakterdir, cikis icin 'X' basin)\n");

    // ZORUNLU: DO-WHILE Dongusu
    // Kullanici en az bir kere cevap girmek zorunda oldugu icin bu donguyu sectim.
    do {
        printf("Sembolu Giriniz: ");
        
        // Tampon temizligi (Enter karakterini temizle)
        char temp;
        while ((temp = getchar()) != '\n' && temp != EOF); 
        scanf("%c", &cevap);

        // Kullanici X'e basarsa donguden manuel cik
        if (cevap == 'x' || cevap == 'X') {
            printf("Vazgectin.\n");
            break;
        }

        // Yanlis cevap kontrolu
        if (cevap != dogru_cevap) {
            printf("%sKapi sana elektrik carpti! (Yanlis Cevap)%s\n", HASAR, VARSAYILAN);
            *enerji_ptr -= 8; // Enerji cezasi
            printf("Kalan Enerji: %d\n", *enerji_ptr);
        }

    // Cevap yanlis oldugu surece VE enerji bitmedigi surece tekrar sor
    } while (cevap != dogru_cevap && *enerji_ptr > 0);

    // Dogru cevap durumunda odul ver
    if (cevap == dogru_cevap) {
        printf("\n%sDogru! Kapi acildi ve iceride eski bir enerji kaynagi buldun!%s\n", BASARI, VARSAYILAN);
        *enerji_ptr += 40; 
        if(*enerji_ptr > 100) *enerji_ptr = 100;
    }
}


// =========================================================
// ANA PROGRAM (MAIN)
// =========================================================

int main(){
    char hamle;
    int okunan_sayisi;
    
    // YEREL DEGISKENLER (Local Variables)
    // Bu degiskenler pointerlar ile diger fonksiyonlara gonderilir.
    int saglik = 50;
    int energy = 50;
    int yemek_sayisi = 0; 
    int siginak_var_mi = 0;
    
    // Rastgele sayi ureticisi icin tohum atiyoruz (Seed)
    srand(time(NULL)); 

    printf("HAYATTA KALMA SIMULATORU\n");
    panel_ciz(energy, saglik, yemek_sayisi, siginak_var_mi);

    // ANA OYUN DONGUSU (DO-WHILE)
    // Oyun "cikis" denilene kadar veya olum gerceklesene kadar surekli doner.
    do
    {
        // 1. SINIR KONTROLLERINI (Clamping)
        // Degiskenlerin mantik disi (negatif veya >100) olmasini engeller.
        if (energy < 0) energy = 0;
        if (saglik > 100) saglik = 100;
        if (energy > 100) energy = 100;
        
        // 2. OLUM KONTROLU
        if (saglik <= 0) {
            saglik = 0;
            panel_ciz(energy, saglik, yemek_sayisi, siginak_var_mi); 
            
            printf("\n%s==================================%s\n", HASAR, VARSAYILAN);
            printf("%s      OYUN BITTI - OLDUNUZ        %s\n", HASAR, VARSAYILAN);
            printf("%s==================================%s\n", HASAR, VARSAYILAN);
            
            // Kullanici enter tusuna basana kadar programi beklet
            printf("\nCikmak icin ENTER tusuna basin...");
            char temp;
            while ((temp = getchar()) != '\n' && temp != EOF); 
            getchar(); 

            break; // Ana donguyu kirar ve program sonlanir
        }

        sonrakiadim(); // Menu seceneklerini goster
        
        // Kullanicidan komut al (" %c" basindaki bosluk onceki enter'i yutar)
        okunan_sayisi = scanf(" %c", &hamle); 
        
        if(okunan_sayisi == 1){
            
            ekran_temizle(); 
            
            // KOMUT YONETIMI (SWITCH-CASE)
            // Coklu secenek yapisi icin en uygun kontrol blogu.
            switch (hamle)
            {
            case 'a': case 'A':
                // Degiskenlerin adreslerini (&) fonksiyona gonderiyoruz
                avlan(&saglik, &energy, &yemek_sayisi); 
                break;

            case 's': case 'S':
                siginak_bul(&saglik, &energy, &siginak_var_mi);
                break;

            case 'e': case 'E':
                envanter(&yemek_sayisi, &energy, &saglik);
                break;

            case 'r': case 'R':
                dinlen(&saglik, &energy, &siginak_var_mi);
                break;

            case 'f': case 'F':
                tehlikeAra(&saglik, &energy, &yemek_sayisi);
                break;

            case 'p': case 'P':
                sifreli_ilerleme(&energy);
                break;

            case 'x': case 'X':
                printf("Oyundan cikiliyor...\n");
                return 0; // Programi basariyla sonlandir

            default:
                printf("Gecersiz komut! Listeden seciniz.\n");
                break;
            }
            
            // Gorsel duzeltme: Negatif degerleri panelde 0 gostermek icin
            if (energy < 0) energy = 0; 
            if (saglik < 0) saglik = 0;
            
            // Envanter haricinde paneli guncelle (Envanter kendi panelini ciziyor)
            if (hamle != 'e' && hamle != 'E') {
                panel_ciz(energy, saglik, yemek_sayisi, siginak_var_mi);
            }

        } else {
            // Hatali giris durumunda buffer temizligi
            char temp;
            while ((temp = getchar()) != '\n' && temp != EOF);
        }

    } while (1); // 1 = True (Sonsuz Dongu)
    
    return 0;

}
