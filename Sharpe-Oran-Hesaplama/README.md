# 📊 Sharpe Oranı Hesaplayıcı – C Projesi

## ✨ Giriş

Bu proje, finansal performansı değerlendirmede kullanılan önemli bir metrik olan **Sharpe Oranı**’nı hesaplamak üzere geliştirilmiş basit ve etkili bir C programıdır. Üniversite ödevi kapsamında hazırlanmıştır ve yatırımın risk-getiri dengesini analiz etmeye yönelik pratik bir araç sunar.

---

## 🧐 Sharpe Oranı Nedir?

**Sharpe Oranı**, bir yatırımın risksiz bir varlığa göre ne kadar fazla getiri sağladığını ve bu getirinin ne kadar riskle elde edildiğini ölçen bir performans göstergesidir.

### 📐 Matematiksel Formül

**Düz Metin Formatında:**  
Sharpe Oranı = (Portföy Getirisi - Risksiz Faiz Oranı) / Standart Sapma

| Sembol | Açıklama |
|--------|----------|
| Rp     | Portföy Getirisi |
| Rf     | Risksiz Getiri Oranı (örneğin devlet tahvili faizi) |
| σp     | Standart Sapma (yatırımın volatilitesi/risk düzeyi) |

---

## 🎯 Neden Önemlidir?

- **Yüksek Sharpe Oranı** → Daha iyi risk ayarlamalı getiri  
- **Düşük Sharpe Oranı** → Risk fazla, getiri yetersiz

Bu oran, yatırım kararlarında riskin ne kadar “karşılık bulduğunu” gösterir ve portföy karşılaştırmalarında sıkça kullanılır.

---

## 💻 Program Özellikleri

Bu C programı, kullanıcıdan aldığı üç temel girdi ile Sharpe Oranı’nı hesaplar ve sonucu yorumlar.

### 🔧 Temel Fonksiyonlar

- **Girdi Alma:**  
  Portföy Getirisi, Risksiz Faiz Oranı ve Standart Sapma değerleri yüzde (%) cinsinden alınır.

- **Veri Doğrulama:**  
  Girdilerin 0–100 aralığında olup olmadığı kontrol edilir.

- **Hesaplama:**  
  Sharpe Oranı formülü uygulanarak sonuç elde edilir.

- **Yorumlama:**  
  Hesaplanan oran aşağıdaki aralıklara göre değerlendirilir:

| Sharpe Oranı | Yorum |
|--------------|-------|
| 0 < S ≤ 1     | Kötü – Risk fazla, getiri yetersiz |
| 1 < S ≤ 2     | İyi Yatırım |
| 2 < S ≤ 3     | Çok İyi Yatırım |
| S > 3         | Mükemmel – Harika Yatırım! |

---

## 🧪 Kullanılan Teknolojiler

- **Programlama Dili:** C  
- **Kütüphaneler:**  
  - `stdio.h` – Girdi/Çıktı işlemleri  
  - `stdlib.h` – Yardımcı fonksiyonlar

---

## 📌 Sonuç

Bu proje, Sharpe Oranı’nın finansal analizdeki uygulamasını sade ve anlaşılır bir şekilde sunar. Öğrenci dostu yapısıyla hem akademik hem de pratik kullanım için uygundur. Risk ve getiri arasındaki ilişkiyi hızlıca değerlendirmek isteyenler için ideal bir araçtır.
