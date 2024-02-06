#include <iostream>
#include <string>
using namespace std;

class CalculEBill {
    string Name;
    float UnitConsumed, TotalAmount;

public:
    CalculEBill() : Name(""), UnitConsumed(0.0), TotalAmount(0.0) {
  
    }

    CalculEBill(string name, float unitConsumed) : Name(name), UnitConsumed(unitConsumed), TotalAmount(0.0) {
        calculateBill(UnitConsumed);
    }

    void FinalBill(float& totalAmount) {
        if (totalAmount < 50) {
            totalAmount = 50;
        }
        if (totalAmount > 300) {
            totalAmount += (totalAmount * 15 / 100);
        }
    }

    void calculateBill(float unit) {
        if (unit <= 100) {
            TotalAmount = (unit * 0.6);
            FinalBill(TotalAmount);
        } else if (unit > 100 && unit <= 300) {
            TotalAmount = ((100 * 0.6) + ((unit - 100) * 0.8));
            FinalBill(TotalAmount);
        } else if (unit > 300) {
            TotalAmount = (((100 * 0.6) + (200 * 0.8)) + ((unit - 300) * 0.9));
            FinalBill(TotalAmount);
        }
    }

    void Display() {
        cout << "The User name is " << Name << endl;
        cout << "Total Unit Consumed " << UnitConsumed << endl;
        cout << "Total Bill After All Deaduction " << TotalAmount << endl;
    }
};

int main() {
    int UserSize;
    string name;
    float unit;

    cout << "Enter the total Number of user: ";
    cin >> UserSize;
    cin.clear();
    cin.ignore();

    CalculEBill* User = new CalculEBill[UserSize];

    for (int i = 0; i < UserSize; ++i) {
        cout << "Enter the User Name: ";
        getline(cin, name);  

        cout << "Enter the user " << name << " unit: ";
        cin >> unit;

        cin.clear();
        cin.ignore();

        User[i] = CalculEBill(name, unit);
    }

    for (int i = 0; i < UserSize; ++i) {
        User[i].Display();
        cout << "<---------------------->" << endl;
    }

    delete[] User;

    return 0;
}