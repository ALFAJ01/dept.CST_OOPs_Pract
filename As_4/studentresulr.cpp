#include <iostream>
using namespace std ;
class Student {
private:
    int studId;
    string name;
    float marks[5] , mark;
    float percentage;
    string sub[5]={"Bengali" , "English" , "Computer Science " , "Mathemathics" , "Physices"};
    

    void calculatePercentage() {
        float totalMarks = 0.0;
        for (int i = 0; i < 5; ++i) {
            totalMarks += marks[i];
        }
        percentage = totalMarks / 5.0;
    }

public:
    void getData() {
        cout << "Enter Student ID: ";
        cin >> studId;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks for 5 subjects:\n";
        for (int i = 0; i < 5; ++i) {
            cout << sub[i] << ": ";
            cin >> mark;
            cin.ignore();
            if (mark<= 100){
                marks[i]=mark;
            }
            else{
                cout<< " You Enter the Wrong Value . Pls Enter The Mark < = 100 ";
                cin >> mark;
                marks[i]=mark;
            }

        }

        calculatePercentage();
    }

    void show() const {
        cout << "Student ID: " << studId <<endl;
        cout << "Name: " << name <<endl;
        cout << "Marks for 5 subjects:\n";
        for (int i = 0; i < 5; ++i) {
            cout << sub[i] << ": " << marks[i] <<endl;
        }
        
        cout << "Percentage: " << percentage << "%" << endl;
    }

    // Getter function for percentage
    float getPercentage() const {
        return percentage;
    }
};

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;
    Student students[N];
    for (int i = 0; i < N; ++i) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].getData();
    }
    float highestPercentage = 0.0;
    int indexHighestPercentage = 0;
    for (int i = 0; i < N; ++i) {
        if (students[i].getPercentage() > highestPercentage) {
            highestPercentage = students[i].getPercentage();
            indexHighestPercentage = i;
        }
    }

    cout << "\nDetails of the student with the highest percentage:\n";
    students[indexHighestPercentage].show();

    return 0;
}
