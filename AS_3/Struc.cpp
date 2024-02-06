#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int employeeId;
    string name;
    int age;
    string designation;
    float salary;

    // Default constructor for clarity (optional)
    Employee() : employeeId(0), name(""), age(0), designation(""), salary(0.0f) {}
};

int main() {
    int numEmployees;

    cout << "Enter the number of employees you want to create: ";
    cin >> numEmployees;

    // Dynamically allocate an array of Employee objects to avoid stack overflow
    Employee *employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEnter details for employee " << i + 1 << ":" << endl;

        cout << "Employee ID: ";
        cin >> employees[i].employeeId;

        cout << "Name: ";
        cin.ignore(); // Clear input buffer if needed
        getline(cin, employees[i].name);

        cout << "Age: ";
        cin >> employees[i].age;

        cout << "Designation: ";
        cin.ignore(); // Clear input buffer if needed
        getline(cin, employees[i].designation);

        cout << "Salary: ";
        cin >> employees[i].salary;
    }

    // Display a clear menu for user choice
    int choice;
    cout << "\nChoose an action:\n"
         << "1. Show data for all employees\n"
         << "2. Show data for a specific employee by ID\n"
         << "3. Exit\n";
    cin >> choice;

    while (choice != 3) {
        switch (choice) {
            case 1: // Show data for all employees
                cout << "\nEmployee Details:" << endl;
                for (int i = 0; i < numEmployees; ++i) {
                    cout << "Employee " << i + 1 << ":" << endl;
                    cout << "Employee Id: " << employees[i].employeeId << endl;
                    cout << "Name: " << employees[i].name << endl;
                    cout << "Age: " << employees[i].age << endl;
                    cout << "Designation: " << employees[i].designation << endl;
                    cout << "Salary: " << employees[i].salary << endl << endl;
                }
                break;
            case 2: // Show data for a specific employee by ID
                int searchId;
                cout << "\nEnter the employee ID you want to search for: ";
                cin >> searchId;
                for (int i = 0; i < numEmployees; ++i) {
                    if (employees[i].employeeId == searchId) {
                        cout << "\nEmployee Details:" << endl;
                        cout << "Employee ID: " << employees[i].employeeId << endl;
                        cout << "Name: " << employees[i].name << endl;
                        cout << "Age: " << employees[i].age << endl;
                        cout << "Designation: " << employees[i].designation << endl;
                        cout << "Salary: " << employees[i].salary << endl;
                        break; // Exit the loop after finding the employee
                    }
                    else{
                        cout<<"You Enter Wrong Employee Id ";
                    }
                }
                
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "\nChoose an action:\n"
             << "1. Show data for all employees\n"
             << "2. Show data for a specific employee by ID\n"
             << "3. Exit\n";
        cin >> choice;
    }


    delete[] employees;

    return 0;
}
