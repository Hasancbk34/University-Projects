#include <stdio.h>    // printf ve getchar gibi temel giriş/çıkış fonksiyonları için
#include <stdlib.h>
int main() {
    /* Kullanıcının girdiği '0' ile '9' arasındaki rakam karakterlerini tutar. */
    char ascii1, ascii2;
    
    /* getchar() fonksiyonunun dönüş değerini (veya tampon kontrolünü) tutmak için int kullanırız. 
       Çünkü getchar() özel bir değer olan EOF'u (dosya sonu) da döndürebilir. */
    int ch;
    
    
    // BİRİNCİ RAKAM GİRİŞİ
    // ===================================

    /* Kullanıcıya ne yapması gerektiğini söyle */
    printf("ilk rakami (0-9) girin: ");
    
    /* Konsoldan tek bir karakteri oku ve ascii1'e kaydet. */
    ascii1 = (char)getchar();
    
    /* Kullanıcı rakamı girip Enter'a bastığında oluşan '\n' (satır sonu) karakterini oku. */
    ch = getchar();
    
    /* Eğer okunan ikinci karakter '\n' değilse, kullanıcı tek rakamdan fazlasını girmiştir. */
    if (ch != '\n') {
        printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi tek rakam girin.\n");
        getchar();getchar();
        return 1;    // Hata olduğunu belirten çıkış kodu
    }


    // İKİNCİ RAKAM GİRİŞİ
    // ===================================

    /* Kullanıcıdan ikinci rakamı iste */
    printf("ikinci rakami (0-9) girin: ");
    
    /* İkinci karakteri oku */
    ascii2 = (char)getchar();
    
    /* İkinci girişten kalan '\n' karakterini oku */
    ch = getchar();
    
    /* İkinci girişte de birden fazla karakter varsa hata ver */
    if (ch != '\n') {
        printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi tek rakam girin.\n");
        getchar();getchar();
        return 1;    // Hata çıkış kodu
    }


    // KONTROL VE TOPLAMA
    // ===================================

    /* Karakteri sayısal değerine çevir. 
       Örneğin, '7' karakteri (ASCII 55), '0' karakteri (ASCII 48) çıkarılarak 7 olur. */
    int num1 = ascii1 - '0';
    int num2 = ascii2 - '0';

    /* Çevrilen sayıların 0 ile 9 aralığında olup olmadığını kontrol et. */
    if (num1 >= 0 && num1 <= 9 && num2 >= 0 && num2 <= 9) {
             
        
        /* Eğer her şey doğruysa, sayısal toplamı hesapla. */
        int toplam = num1 + num2;
        
        /* Sonucu yazdır */
        printf("Birinci girdinin ascii degeri %d => %d rakamina cevirildi.\n" , ascii1, num1);
        printf("Ikinci girdinin ascii degeri %d => %d rakamina cevirildi.\n" , ascii2, num2);
        printf("\nToplam (sayisal deger): %d\n ", toplam);
        getchar();
        return 0;    // Program hatasız bitti
    }
    
    // YANLIŞ KARAKTER GİRİŞ HATASI
    // ===================================

    /* Eğer yukarıdaki kontrol başarısız olursa (Örn: kullanıcı 'a' veya '@' girerse) */
    printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi rakam girin.\n ");
    getchar();
    return 1;    // Hata ile sonlan
}

