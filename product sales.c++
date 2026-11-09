
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;

// Ürün veri yapısı
struct Urun {
    string urun;
    string kategori;
    double fiyat;
    int adet;
    double toplam_kazanc;
};

int main() {

    // --- VERİ OLUŞTURMA ---

    vector<Urun> df = {
        {"Laptop", "Teknoloji", 25000, 3, 0},
        {"Kulaklik", "Teknoloji", 2000, 10, 0},
        {"Masa", "Mobilya", 5000, 2, 0},
        {"Sandalye", "Mobilya", 1500, 8, 0},
        {"Telefon", "Teknoloji", 18000, 5, 0}
    };

    cout << "--- ORIJINAL VERI ---\n";

    // Tablo başlığı
    cout << left << setw(15) << "Urun"
         << setw(15) << "Kategori"
         << setw(12) << "Fiyat"
         << setw(10) << "Adet" << endl;

    for (auto &u : df) {
        cout << left << setw(15) << u.urun
             << setw(15) << u.kategori
             << setw(12) << u.fiyat
             << setw(10) << u.adet << endl;
    }

    // 1. Yeni sütun: toplam_kazanc = fiyat * adet

    for (auto &u : df) {
        u.toplam_kazanc = u.fiyat * u.adet;
    }

    // 2. En çok gelir getiren ürün

    auto en_cok = max_element(
        df.begin(), df.end(),
        [](const Urun &a, const Urun &b) {
            return a.toplam_kazanc < b.toplam_kazanc;
        }
    );

    cout << "\nEn cok gelir getiren urun: "
         << en_cok->urun
         << " (Kazanc: "
         << en_cok->toplam_kazanc << " TL)" << endl;

    // 3. Kategori bazlı toplam kazanç

    map<string, double> kategori_kazanc;

    for (const auto &u : df) {
        kategori_kazanc[u.kategori] += u.toplam_kazanc;
    }

    cout << "\nKategori bazli toplam kazanc:\n";

    for (const auto &k : kategori_kazanc) {
        cout << k.first << ": "
             << k.second << " TL" << endl;
    }

    // 4. Ortalama ürün fiyatı

    double toplam_fiyat = 0;

    for (const auto &u : df) {
        toplam_fiyat += u.fiyat;
    }

    double ortalama_fiyat = toplam_fiyat / df.size();

    cout << fixed << setprecision(2);
    cout << "\nOrtalama urun fiyati: "
         << ortalama_fiyat << " TL" << endl;

    // 5. 10.000 TL üstü ürünleri filtrele

    cout << "\n10.000 TL ustu urunler:\n";

    for (const auto &u : df) {
        if (u.fiyat > 10000) {
            cout << u.urun << " - "
                 << u.fiyat << " TL" << endl;
        }
    }

    // 6. Veriyi kazanca göre sırala (azalan)

    sort(df.begin(), df.end(),
         [](const Urun &a, const Urun &b) {
             return a.toplam_kazanc > b.toplam_kazanc;
         });

    cout << "\nKazanca gore siralanmis veri:\n";

    for (const auto &u : df) {
        cout << u.urun << " - "
             << u.toplam_kazanc << " TL" << endl;
    }

    cout << "\n" << string(50, '=') << endl;
    cout << "--- NUMPY KISMI ---" << endl;
    cout << string(50, '=') << endl;

    // Fiyat sütununu vector'e çevir

    vector<double> fiyat_array;

    for (const auto &u : df) {
        fiyat_array.push_back(u.fiyat);
    }

    cout << "Fiyat array'i: ";

    for (double f : fiyat_array) {
        cout << f << " ";
    }

    cout << endl;

    // Minimum, maksimum ve medyan fiyat

    double min_fiyat = *min_element(
        fiyat_array.begin(), fiyat_array.end()
    );

    double max_fiyat = *max_element(
        fiyat_array.begin(), fiyat_array.end()
    );

    vector<double> sirali_fiyatlar = fiyat_array;

    sort(sirali_fiyatlar.begin(), sirali_fiyatlar.end());

    double medyan_fiyat = sirali_fiyatlar[
        sirali_fiyatlar.size() / 2
    ];

    cout << "Minimum fiyat: " << min_fiyat << endl;
    cout << "Maksimum fiyat: " << max_fiyat << endl;
    cout << "Medyan fiyat: " << medyan_fiyat << endl;

    // --- RASTGELE 100 SATIS VERISI ---

    mt19937 gen(42);

    vector<string> urun_listesi = {
        "Laptop", "Kulaklik", "Masa", "Sandalye",
        "Telefon", "Monitor", "Klavye", "Kitap", "Dolap"
    };

    vector<string> kategori_listesi = {
        "Teknoloji", "Mobilya", "Diger"
    };

    uniform_int_distribution<int> urun_dist(0, 8);
    uniform_int_distribution<int> kategori_dist(0, 2);
    uniform_int_distribution<int> fiyat_dist(100, 49999);
    uniform_int_distribution<int> adet_dist(1, 20);

    vector<Urun> rastgele_veri;

    for (int i = 0; i < 100; i++) {

        Urun u;

        u.urun = urun_listesi[urun_dist(gen)];
        u.kategori = kategori_listesi[kategori_dist(gen)];
        u.fiyat = fiyat_dist(gen);
        u.adet = adet_dist(gen);
        u.toplam_kazanc = u.fiyat * u.adet;

        rastgele_veri.push_back(u);
    }

    // İlk 5 satırı göster

    cout << "\nRastgele 100 satis verisinden ilk 5 satir:\n";

    for (int i = 0; i < 5; i++) {
        const auto &u = rastgele_veri[i];

        cout << u.urun << " | "
             << u.kategori << " | "
             << u.fiyat << " TL | "
             << u.adet << " adet | "
             << u.toplam_kazanc << " TL" << endl;
    }

    // --- HISTOGRAM ---

    int histogram[10] = {0};

    double bin_genisligi = 49999.0 / 10;

    for (const auto &u : rastgele_veri) {

        int bin = static_cast<int>(
            (u.fiyat - 100) / bin_genisligi
        );

        if (bin >= 10) {
            bin = 9;
        }

        histogram[bin]++;
    }

    cout << "\nFiyat dagilimi histogrami (10 bolge):\n";

    for (int i = 0; i < 10; i++) {

        double alt_sinir = 100 + i * bin_genisligi;
        double ust_sinir = 100 + (i + 1) * bin_genisligi;

        cout << "Bolge " << i + 1 << ": "
             << fixed << setprecision(0)
             << alt_sinir << " - "
             << ust_sinir << " TL arasi -> "
             << histogram[i] << " urun" << endl;
    }

    return 0;
}
