
#include <iostream>
using namespace std;

int main() {
    int sayilar[10];
    int enBuyuk, enKucuk;
    int cift = 0, tek = 0;
    int toplam = 0;

    cout << "10 adet sayi girin:" << endl;

    for (int i = 0; i < 10; i++) {
        cin >> sayilar[i];
    }

    enBuyuk = sayilar[0];
    enKucuk = sayilar[0];

    for (int i = 0; i < 10; i++) {

        toplam += sayilar[i];

        if (sayilar[i] > enBuyuk)
            enBuyuk = sayilar[i];

        if (sayilar[i] < enKucuk)
            enKucuk = sayilar[i];

        if (sayilar[i] % 2 == 0)
            cift++;
        else
            tek++;
    }

    double ortalama = toplam / 10.0;

    cout << "En buyuk: " << enBuyuk << endl;
    cout << "En kucuk: " << enKucuk << endl;
    cout << "Ortalama: " << ortalama << endl;
    cout << "Cift sayi: " << cift << endl;
    cout << "Tek sayi: " << tek << endl;

    cout << "Tersten: ";

    for (int i = 9; i >= 0; i--) {
        cout << sayilar[i] << " ";
    }

    cout << endl;

    return 0;
}
