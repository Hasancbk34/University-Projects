#include <stdio.h>
#include <stdlib.h>




int main(){
    float yatirimgetirisi, risksizfaizorani, standartsapma;
    float sharpeOrani;
    printf("yatirim getirisi ne kadar ?"); scanf("%f" , &yatirimgetirisi);
    if(!(yatirimgetirisi >= 0  && yatirimgetirisi <=100)){
        printf("Lutfen 0 ile 100 arasinda bir sayi giriniz !!!");
        getchar();getchar();    
        return 1;
    }
    printf("risk faiz orani ne kadar ?"); scanf("%f" , &risksizfaizorani);
    if(!(risksizfaizorani >= 0  && risksizfaizorani <=100)){
        printf("Lutfen 0 ile 100 arasinda bir sayi giriniz !!!");
        getchar();getchar();
        return 1;
    }
    printf("standart sapma ne kadar ?"); scanf("%f" , &standartsapma);
    if(!(standartsapma > 0  && standartsapma <=100)){
        printf("Lutfen 1 ile 100 arasinda bir sayi giriniz !!!");
        getchar();getchar();
        return 1;
    }
    sharpeOrani = (yatirimgetirisi - risksizfaizorani) / standartsapma;
    printf("\n\nYatirim Getirisi: %.2f%%\n", yatirimgetirisi);
    printf("Risksiz Faiz Orani: %.2f%%\n", risksizfaizorani);
    printf("Standart Sapma: %.2f\n\n", standartsapma);
    printf("\nSharpe Orani : %.2f\n", sharpeOrani);
    
    
    
    printf("=>  DEGERLENDIRME SONUCU  <=\n");
    if(sharpeOrani > 0 && sharpeOrani <= 1){
        printf("Kotu. Risk fazla getiri yetersiz");
    }else if(sharpeOrani > 1 && sharpeOrani <= 2){
        printf("IyI yatirim");
    }else if(sharpeOrani > 2 && sharpeOrani <= 3){
        printf("Cok iyi yatirim");
    }else if(sharpeOrani > 3 ){
        printf("Mukemmel. Harika yatirim! Risk basina çok yuksek getiri.");
    }else{
        printf("Hata ! ! ! Sharpe orani hesaplanamadi.");
    }

    getchar();getchar();
    return 0;
}