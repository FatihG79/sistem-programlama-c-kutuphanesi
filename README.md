# Sistem Programlama Ödev-3: Çok Dosyalı C Kütüphanesi ve Makefile

## 1. Projenin Amacı
Bu ödev kapsamında, Linux ortamında C programlama dilini kullanarak çok dosyalı bir yapı kurmayı hedefledim. Yazdığım kaynak kodlardan dinamik (paylaşılan) bir kütüphane oluşturdum ve projeyi derleme, bağlama, temizleme gibi işlemleri tek bir Makefile üzerinden otomatik hale getirdim[cite: 3].

## 2. Proje Klasör Yapısı
[cite_start]Projedeki dosyaların birbirine karışmaması ve düzenli olması için kaynak kodları, başlık dosyalarını ve diğer bileşenleri ayrı klasörlerde organize ettim[cite: 15, 22]. Klasör ağacım şu şekilde:

.
├── include/
│   └── math_lib.h
├── src/
│   ├── asal_mi.c
│   ├── faktoriyel.c
│   ├── kare.c
│   └── kup.c
├── main.c
├── Makefile
└── README.md

## 3. Her Dosyanın Görevi
* [cite_start]**include/math_lib.h**: Kütüphanemde kullandığım fonksiyonların prototiplerini (imzalarını) tuttuğum başlık dosyası[cite: 13, 27].
* **src/*.c**: Matematiksel işlemlerin her birini ayrı ayrı yazdığım kaynak kod dosyalarım[cite: 13, 28].
* **main.c**: Oluşturduğum paylaşılan kütüphaneyi (`libmath.so`) test etmek amacıyla yazdığım ana program[cite: 35].
* [cite_start]**Makefile**: Kütüphane oluşturma, derleme ve ortamı temizleme adımlarını benim yerime otomatikleştiren yapılandırma dosyam[cite: 33, 45, 46, 47].

## 4. Kütüphanede Yer Alan Fonksiyonların Açıklaması
[cite_start]Kütüphanem, en az dört farklı işlevi yerine getiren şu fonksiyonlardan oluşuyor[cite: 8]:
* `karesini_al(int sayi)`: İçine gönderilen sayının karesini hesaplıyor[cite: 9].
* [cite_start]`kupunu_al(int sayi)`: Parametre olarak aldığı sayının küpünü hesaplıyor[cite: 10].
* `faktoriyel_hesapla(int sayi)`: Verilen sayının faktöriyel değerini buluyor[cite: 11].
* [cite_start]`asal_mi(int sayi)`: Sayının asal olup olmadığını kontrol ediyor (asalsa 1, değilse 0 değerini üretiyor)[cite: 12].

## 5. Makefile Hedeflerinin Görevleri
[cite_start]Süreci yönetmek için Makefile içinde tanımladığım hedefler ve görevleri şunlar[cite: 44]:
* [cite_start]**all**: `lib` ve `main` hedeflerini sırayla tetikleyerek projenin tamamını derliyor[cite: 39].
* **lib**: `src/` klasöründeki kodları `-fPIC` bayrağıyla nesne dosyalarına çeviriyor, ardından `-shared` parametresiyle `libmath.so` adındaki paylaşılan kütüphanemi üretiyor[cite: 40].
* [cite_start]**main**: `main.c` dosyamı derliyor ve `-L.` ile `-lmath` parametrelerini kullanarak ana programı oluşturduğum kütüphaneye bağlıyor[cite: 41].
* **run**: Programı çalıştırıyor. [cite_start]Kütüphanem standart sistem klasörlerinde olmadığı için `LD_LIBRARY_PATH=.` ataması yaparak sistemin kütüphaneyi anlık dizinde bulmasını sağlıyor[cite: 42].
* **clean**: Derleme sırasında ortaya çıkan `.o` uzantılı nesne dosyalarını, `.so` kütüphane dosyasını ve çalıştırılabilir programı sistemden temizleyip klasörü ilk haline döndürüyor[cite: 43, 47].

## 6. Projenin Nasıl Derleneceği
Projeyi derlemek için terminalde ana dizindeyken şu komutu girmek yeterlidir:
\`\`\`bash
make all
\`\`\`

## 7. Programın Nasıl Çalıştırılacağı
Derleme işlemi tamamlandıktan sonra programı çalıştırmak için aşağıdaki komutu kullanıyoruz[cite: 84]:
\`\`\`bash
make run
\`\`\`

## 8. Programdan Beklenen Örnek Çıktı
\`\`\`text
LD_LIBRARY_PATH=. ./ana_program
=== Matematik Kutuphanesi Test Sonuclari ===
5 sayisinin karesi: 25
4 sayisinin kupu: 64
5 sayisinin faktoriyeli: 120
17 sayisi bir asal sayidir.
\`\`\`