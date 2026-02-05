🔢 Karakterleri Sayıya Çevirme ve Toplama Projesi (C Dili)

Bu proje, C dilini kullanarak konsol ortamında temel veri işleme ve hata kontrolü becerilerini sergiler. Uygulama, kullanıcıdan girilen iki adet tek haneli rakam karakterini okur ve bu karakterleri güvenli bir şekilde tamsayı (integer) değerlerine dönüştürerek toplama işlemini gerçekleştirir.

✨ Projenin Ana Fikri: ASCII Kodu Farkı

Uygulamanın en önemli kısmı, kullanıcıdan alınan rakam karakterlerinin (Örn: '6') nasıl matematiksel bir sayıya (6) dönüştürüldüğüdür. Bu dönüşüm, C'nin ASCII karakter kodlama sistemine dayanır.

Bildiğiniz gibi, rakam karakterleri ASCII tablosunda sıralı olarak yer alır. Bu bilgiyi kullanarak, bir karakterin sayısal değerini bulmak için şu basit işlemi yaparız:
Sayısal Deg˘​er=Girilen Rakam Karakteri−’0’ Karakteri

Bu çıkarma işlemi, bilgisayarın yalnızca karakterleri değil, onların temsil ettiği gerçek matematiksel değerleri kullanmasını ve doğru toplama sonucunu vermesini sağlar.

🛡️ Giriş Kontrolleri ve Güvenlik

Projenin sağlamlığını artırmak için iki temel kontrol mekanizması kullanılmıştır:

    Tek Rakam Garantisi: Kullanıcının 5 yerine 53 gibi birden fazla karakter girmesi durumunu engeller. getchar() fonksiyonunun tekrar kullanımıyla, yalnızca ilk karakterin alındığından emin olunur.

    Rakam Doğrulama: Girilen karakterin gerçekten ′0′ ile ′9′ arasında bir rakam olup olmadığı kontrol edilir. Bu sayede 'a' veya '@' gibi geçersiz karakterler hemen tespit edilir ve programın hata vermesi engellenir.

Bu kontroller, uygulamanın beklenmeyen veya hatalı kullanıcı girdilerine karşı dayanıklı çalışmasını garanti eder.
