#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> 

using namespace std;

int main() {
    char choice = 'Y';

    int order = 1;

    int num1 = 0, num2 = 0;
    int sentinel = 0;
    const double UnitPrice1 = 65.0;
    const double UnitPrice2 = 65.0;
    double AmountofSale1 = 0, AmountofSale2 = 0;

    string date, time, buyerName, buyerAddress;

    cout << "--------------------------------------- Am bagal pag papel talaga hahahahaah ----------------------------------------\n";
    cout << "1.) Laing 65 Pesos each \n";
    cout << "2.) Bicol Express 65 Pesos each \n";

    while (order != sentinel) {
        cout << "\nPlease choose your order! (Enter 0 to finish):\n";
        cin >> order;

        switch (order) {
            case 0:
                break;

            case 1:
                cout << "\nHow many orders of Laing?:\n";
                cin >> num1;
                AmountofSale1 = UnitPrice1 * num1;

                
                cout << "Enter today's date (YYYY-MM-DD): ";
                cin.ignore();
                getline(cin, date);
                cout << "Enter the current time (HH:MM): ";
                getline(cin, time);
                cout << "Enter buyer's name: ";
                getline(cin, buyerName);
                cout << "Enter buyer's address: ";
                getline(cin, buyerAddress);
                break;

            case 2:
                cout << "\nHow many orders of Bicol Express?:\n";
                cin >> num2;
                AmountofSale2 = UnitPrice2 * num2;

                
                cout << "Enter today's date (YYYY-MM-DD): ";
                cin.ignore();
                getline(cin, date);
                cout << "Enter the current time (HH:MM): ";
                getline(cin, time);
                cout << "Enter buyer's name: ";
                getline(cin, buyerName);
                cout << "Enter buyer's address: ";
                getline(cin, buyerAddress);
                break;

            default:
                cout << "Please Choose An Item From Our List\n";
        }
    }

    // Summary to lods
    cout << "\nYou Have Ordered:\n\n";
    cout << "===================================================================\n";
    cout << left << setw(15) << "ITEM" << right << setw(10) << "\tQUANTITY" << right << setw(15) << "UNIT PRICE" << right << setw(20) << "AMOUNT\n";
    cout << "===================================================================\n";
    if (num1 > 0) {
        cout << "Laing : \t" << setw(6) << left << num1 << setw(16) << right << UnitPrice1 << setw(20) << right << AmountofSale1 << endl;
    }
    if (num2 > 0) {
        cout << "Bicol Express : \t" << setw(6) << left << num2 << setw(16) << right << UnitPrice2 << setw(20) << right << AmountofSale2 << endl;
    }

    // Display of buyer details
    if (num1 > 0 || num2 > 0) {
        cout << "\nBuyer Details:\n";
        cout << "===================================================================\n";
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Buyer Name: " << buyerName << endl;
        cout << "Buyer Address: " << buyerAddress << endl;
        cout << "===================================================================\n";
    }

    // Eto yung problemang matagal append mode pala dapat pag mag sasave
    ofstream outFile("order_summary.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "#################### ORDERING SYSTEM ####################\n\n";
        outFile << "You Have Ordered:\n\n";
        outFile << "===================================================================\n";
        outFile << left << setw(15) << "ITEM" << right << setw(10) << "\tQUANTITY" << right << setw(15) << "UNIT PRICE" << right << setw(20) << "AMOUNT\n";
        outFile << "===================================================================\n";
        if (num1 > 0) {
            outFile << "Laing : \t" << setw(6) << left << num1 << setw(16) << right << UnitPrice1 << setw(20) << right << AmountofSale1 << endl;
        }
        if (num2 > 0) {
            outFile << "Bicol Express : \t" << setw(6) << left << num2 << setw(16) << right << UnitPrice2 << setw(20) << right << AmountofSale2 << endl;
        }
        if (num1 > 0 || num2 > 0) {
            outFile << "\nBuyer Details:\n";
            outFile << "===================================================================\n";
            outFile << "Date: " << date << endl;
            outFile << "Time: " << time << endl;
            outFile << "Buyer Name: " << buyerName << endl;
            outFile << "Buyer Address: " << buyerAddress << endl;
            outFile << "===================================================================\n";
        }
        outFile.close();
        cout << "\nOrder summary saved to order_summary.txt\n";
    } else {
        cout << "Unable to open file to save order summary.\n";
    }

    system("PAUSE");
    return 0;
}

