
#include <iostream>
using namespace std;

int main() {
    double bakiye = 10000;
    double miktar;
    int secim;

    do {
        cout << "\n===== ATM SISTEMI =====" << endl;
        cout << "1 - Bakiye Goruntule" << endl;
        cout << "2 - Para Yatir" << endl;
        cout << "3 - Para Cek" << endl;
        cout << "4 - Cikis" << endl;

        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {

            case 1:
                cout << "Bakiyeniz: " << bakiye << " TL" << endl;
                break;

            case 2:
                cout << "Yatirilacak miktar: ";
                cin >> miktar;

                if (miktar > 0) {
                    bakiye += miktar;
                    cout << "Yeni bakiye: " << bakiye << " TL" << endl;
                }
                else {
                    cout << "Gecersiz miktar!" << endl;
                }
                break;

            case 3:
                cout << "Cekilecek miktar: ";
                cin >> miktar;

                if (miktar <= 0) {
                    cout << "Gecersiz miktar!" << endl;
                }
                else if (miktar > bakiye) {
                    cout << "Yetersiz bakiye!" << endl;
                }
                else {
                    bakiye -= miktar;
                    cout << "Yeni bakiye: " << bakiye << " TL" << endl;
                }
                break;

            case 4:
                cout << "Iyi gunler!" << endl;
                break;

            default:
                cout << "Gecersiz secim!" << endl;
        }

    } while (secim != 4);

    return 0;
}
