#include <iostream>
using namespace std;

int main() {

    double total_revenue = 0;
    int discounted_customers = 0;

    while (true) {

        int choice;

        cout << "Enter 1 for car entry, 0 to finish the day: ";
        cin >> choice;

        if (choice == 0) {

            cout << "\n--- DAILY REPORT ---" << endl;
            cout << "Total revenue: " << total_revenue << " TL" << endl;
            cout << "Discounted customers: " << discounted_customers << endl;

            break;
        }

        else if (choice == 1) {

            int entry_hour, entry_minute;
            int exit_hour, exit_minute;
            int premium;

            // Get entry time
            cout << "Entry hour: ";
            cin >> entry_hour;

            cout << "Entry minute: ";
            cin >> entry_minute;

            // Get exit time
            cout << "Exit hour: ";
            cin >> exit_hour;

            cout << "Exit minute: ";
            cin >> exit_minute;

            // Check premium membership
            cout << "Premium member? (1=Yes, 0=No): ";
            cin >> premium;

            // Convert time into minutes
            int entry_time = entry_hour * 60 + entry_minute;
            int exit_time = exit_hour * 60 + exit_minute;

            // Calculate parking duration
            int duration = (exit_time - entry_time + 1440) % 1440;

            // Calculate parking fee
            double fee = duration * 5;

            // Apply 10% discount
            if (premium == 1) {

                fee = fee * 0.90;
                discounted_customers++;

            }

            // Update total revenue
            total_revenue += fee;

            cout << "Parking duration: " << duration << " minutes" << endl;
            cout << "Parking fee: " << fee << " TL" << endl;

        }

        else {

            cout << "Invalid choice! Enter 1 or 0." << endl;

        }

    }

    return 0;
}
