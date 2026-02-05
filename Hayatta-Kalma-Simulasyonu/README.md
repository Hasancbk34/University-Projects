# 🐺 C Survival Simulator (Hayatta Kalma Simülatörü)

Bu proje, temel C programlama dili kavramlarını uygulamalı olarak pekiştirmek amacıyla geliştirilmiş, konsol tabanlı bir hayatta kalma simülasyonudur. Oyun, **Pointerlar** (`Pointers`), **Kontrol Akışı** (`Control Flow`), **Döngüler** (`Loops`) ve **Önişlemci Direktifleri** (`Preprocessor Directives`) gibi temel konuların pratik kullanımını sergilemektedir.

---

## 🧠 Kullanılan Temel Programlama Kavramları (Core Programming Concepts)

| Konsept | Amaç ve Teknik Detay | C Fonksiyonları/Yapıları |
| :--- | :--- | :--- |
| **Dinamik Değer Yönetimi** | `main` fonksiyonunda tanımlanan oyuncu durum değişkenlerinin (`Sağlık`, `Enerji`, `Yemek`) alt fonksiyonlar tarafından kalıcı olarak güncellenmesi sağlanır. | **Pointerlar** (`Pass-by-Reference`) |
| **Karar Mekanizmaları** | Kullanıcı aksiyon seçimlerini ve karmaşık rastgele olay zincirlerini verimli bir şekilde yönetir. | **`switch-case`** ve **`if-else if-else`** |
| **Tekrarlayan İşlemler** | Oyunun ana döngüsünü sürdürmek ve çok adımlı olay serilerini (Keşif, Şifre Denemesi) simüle etmek. | **`do-while`** ve **`for`** Döngüleri |
| **Platform Bağımsızlık** | Kodun Windows ve Unix tabanlı sistemlerde (`Linux`, `macOS`) uyumlu bekleme ve ekran temizleme komutlarını çalıştırması. | **`#ifdef _WIN32`** Önişlemci Direktifleri |
| **Görsel Geri Bildirim** | Konsol çıktısına (başarı/hata) renkli uyarılar ekleyerek kullanıcı deneyimini iyileştirir. | **ANSI Kaçış Kodları** (`ANSI Escape Codes`) ve **`#define` Makroları** |

---

## 🔬 Teknik Uygulama Detayları (Technical Implementation Details)

### 1. Pointer Mimarisi ve Veri Bütünlüğü (Pointer Architecture and Data Integrity)

Tüm ana oyun fonksiyonları (örneğin `avlan`, `dinlen`), karakter özelliklerini **değer** yerine **adres** olarak alır. Bu, C dilinde **referansla çağırma** (`pass-by-reference`) tekniğini kullanarak, fonksiyon içindeki herhangi bir değişikliğin `main` fonksiyonundaki orijinal değişkenin bellek adresini doğrudan etkilemesini sağlar.

* **Örnek İmza:** `void avlan(int *saglik_ptr, int *enerji_ptr, ...)`
* **Değer Ataması:** Adres üzerindeki değere ulaşmak için **dereferans operatörü** (`*`) kullanılır: `*enerji_ptr -= 20;`

### 2. Akış Kontrol Yapıları (Flow Control Structures)

#### A. `for` Döngüsü ile Seri Olay Simülasyonu
`tehlikeAra` fonksiyonunda, dört ardışık keşif adımını simüle etmek için **`for`** döngüsü kullanılmıştır. Bu, bir dizi olayın tekrar eden bir maliyetle (Enerji -5) gerçekleşmesini sağlar. Oyuncunun canı tükenirse, döngü **`break`** komutu ile derhal sonlandırılır.

#### B. `do-while` ile Doğrulama (Validation)
`sifreli_ilerleme` fonksiyonunda, bir şifre deneme mekanizması için **`do-while`** döngüsü tercih edilmiştir. Bu yapı, kullanıcının sorguya **en az bir kez** cevap vermesini zorunlu kılar ve doğru cevap gelene veya enerji tükenene kadar denemeye devam etmesini sağlar.

### 3. Konsol Girdi Yönetimi ve Tampon Temizliği (Console Input Management)

Standart girdi/çıktı kütüphanesini kullanırken yaygın karşılaşılan bir problem olan **girdi tamponu temizliği** (`input buffer flushing`) titizlikle ele alınmıştır. Özellikle `scanf` ile karakter okuma işlemlerinden önce, önceki işlemlerden kalan `\n` (Enter) karakterinin temizlenmesi için aşağıdaki yapı kullanılmıştır:

```c
 Girdi tamponu temizliği
char temp;
while ((temp = getchar()) != '\n' && temp != EOF);
```
---
## 🧑‍💻 Geliştirici (Developer)

Bu proje, C Programlama dilindeki akademik öğrenimimi pekiştirmek amacıyla tarafımca geliştirilmiştir.

* **Ad Soyad:** Hasan Çabuk
* **Üniversite:** Kırklareli Üniversitesi
* **Bölüm:** Yazılım Mühendisliği
* **Sınıf:** 1. Sınıf
