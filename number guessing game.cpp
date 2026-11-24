
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int gizliSayi = rand() % 100 + 1;
    int tahmin;
    int deneme = 0;

    cout << "1-100 arasinda bir sayi tahmin edin." << endl;

    do {
        cout << "Tahmininiz: ";
        cin >> tahmin;

        deneme++;

        if (tahmin > gizliSayi) {
            cout << "Daha kucuk bir sayi girin." << endl;
        }
        else if (tahmin < gizliSayi) {
            cout << "Daha buyuk bir sayi girin." << endl;
        }
        else {
            cout << "Tebrikler! Dogru tahmin." << endl;
            cout << "Deneme sayisi: " << deneme << endl;
        }

    } while (tahmin != gizliSayi);

    return 0;
}
