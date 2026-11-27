
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Ogrenci {
    int numara;
    string isim;
    double vize;
    double final;
    double ortalama;
};

void ogrenciEkle(vector<Ogrenci>& ogrenciler) {
    Ogrenci ogr;

    cout << "Ogrenci numarasi: ";
    cin >> ogr.numara;

    cout << "Isim: ";
    cin >> ogr.isim;

    cout << "Vize: ";
    cin >> ogr.vize;

    cout << "Final: ";
    cin >> ogr.final;

    ogr.ortalama = ogr.vize * 0.4 + ogr.final * 0.6;

    ogrenciler.push_back(ogr);

    cout << "Ogrenci eklendi!" << endl;
}

void ogrencileriListele(const vector<Ogrenci>& ogrenciler) {
    if (ogrenciler.empty()) {
        cout << "Kayitli ogrenci yok." << endl;
        return;
    }

    for (const Ogrenci& ogr : ogrenciler) {
        cout << "\nNumara: " << ogr.numara << endl;
        cout << "Isim: " << ogr.isim << endl;
        cout << "Ortalama: " << ogr.ortalama << endl;
    }
}

void ogrenciAra(const vector<Ogrenci>& ogrenciler) {
    int numara;
    cout << "Aranacak ogrenci numarasi: ";
    cin >> numara;

    for (const Ogrenci& ogr : ogrenciler) {
        if (ogr.numara == numara) {
            cout << "Ogrenci bulundu!" << endl;
            cout << "Isim: " << ogr.isim << endl;
            cout << "Ortalama: " << ogr.ortalama << endl;
            return;
        }
    }

    cout << "Ogrenci bulunamadi." << endl;
}

void enBasariliOgrenci(const vector<Ogrenci>& ogrenciler) {
    if (ogrenciler.empty()) {
        cout << "Ogrenci bulunmuyor." << endl;
        return;
    }

    int indeks = 0;

    for (int i = 1; i < ogrenciler.size(); i++) {
        if (ogrenciler[i].ortalama >
            ogrenciler[indeks].ortalama) {
            indeks = i;
        }
    }

    cout << "En basarili ogrenci: "
         << ogrenciler[indeks].isim << endl;

    cout << "Ortalama: "
         << ogrenciler[indeks].ortalama << endl;
}

void sinifOrtalamasi(const vector<Ogrenci>& ogrenciler) {
    if (ogrenciler.empty()) {
        cout << "Ogrenci bulunmuyor." << endl;
        return;
    }

    double toplam = 0;

    for (const Ogrenci& ogr : ogrenciler) {
        toplam += ogr.ortalama;
    }

    cout << "Sinif ortalamasi: "
         << toplam / ogrenciler.size() << endl;
}

int main() {
    vector<Ogrenci> ogrenciler;
    int secim;

    do {
        cout << "\n===== OGRENCI SISTEMI =====" << endl;
        cout << "1 - Ogrenci Ekle" << endl;
        cout << "2 - Ogrencileri Listele" << endl;
        cout << "3 - Ogrenci Ara" << endl;
        cout << "4 - En Basarili Ogrenci" << endl;
        cout << "5 - Sinif Ortalamasi" << endl;
        cout << "6 - Cikis" << endl;

        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {

            case 1:
                ogrenciEkle(ogrenciler);
                break;

            case 2:
                ogrencileriListele(ogrenciler);
                break;

            case 3:
                ogrenciAra(ogrenciler);
                break;

            case 4:
                enBasariliOgrenci(ogrenciler);
                break;

            case 5:
                sinifOrtalamasi(ogrenciler);
                break;

            case 6:
                cout << "Program kapatiliyor." << endl;
                break;

            default:
                cout << "Gecersiz secim!" << endl;
        }

    } while (secim != 6);

    return 0;
}
