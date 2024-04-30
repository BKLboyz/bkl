#include <iostream>
#include <string> // Include <string> for std::string
#define max 20
using namespace std;

// Structure of Employee
struct employee {
    string name; // Use std::string instead of char array
    int code;
    string designation; // Use std::string instead of char array
    int exp;
    int age;
};

int num;

// Array of Employees to store the data in the form of the Structure
employee emp[max];

void showMenu();
void build();
void insert();
void deleteIndex(int i);
void deleteRecord();
void searchRecord();

// Function to build the given datatype
void build() {
    cout << "Build The Table \n";
    cout << "Maximum Entries can be " << max << "\n";
    cout << "Enter the number of Entries required: ";
    cin >> num;
    
    if (num > max) {
        cout << "Maximum number of Entries are " << max << "\n";
        num = max;
    }

    cout << "Enter the following data:\n";
    for (int i = 0; i < num; i++) {
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Employee ID: ";
        cin >> emp[i].code;
        cout << "Designation: ";
        cin >> emp[i].designation;
        cout << "Experience: ";
        cin >> emp[i].exp;
        cout << "Age: ";
        cin >> emp[i].age;
    }
    showMenu();
}

// Function to insert the data into given data type
void insert() {
    if (num < max) {
        cout << "Enter the information of the Employee\n";
        cout << "Name: ";
        cin >> emp[num].name;
        cout << "Employee ID: ";
        cin >> emp[num].code;
        cout << "Designation: ";
        cin >> emp[num].designation;
        cout << "Experience: ";
        cin >> emp[num].exp;
        cout << "Age: ";
        cin >> emp[num].age;
        num++;
    } else {
        cout << "Employee Table Full\n";
    }
    showMenu();
}

// Function to delete record at index i
void deleteIndex(int i) {
    for (int j = i; j < num - 1; j++) {
        emp[j] = emp[j + 1];
    }
    num--;
}

// Function to delete record
void deleteRecord() {
    cout << "Enter the Employee ID to Delete Record: ";
    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            deleteIndex(i);
            break;
        }
    }
    showMenu();
}

void searchRecord() {
    cout << "Enter the Employee ID to Search Record: ";
    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            cout << "Name: " << emp[i].name << "\n";
            cout << "Employee ID: " << emp[i].code << "\n";
            cout << "Designation: " << emp[i].designation << "\n";
            cout << "Experience: " << emp[i].exp << "\n";
            cout << "Age: " << emp[i].age << "\n";
            break;
        }
    }
    showMenu();
}

// Function to show menu
void showMenu() {
    cout << "Available Options:\n\n";
    cout << "Build Table (1)\n";
    cout << "Insert New Entry (2)\n";
    cout << "Delete Entry (3)\n";
    cout << "Search a Record (4)\n";
    cout << "Exit (5)\n";

    int option;
    // Input Options
    cin >> option;

    // Call function based on the above option
    switch (option) {
        case 1:
            build();
            break;
        case 2:
            insert();
            break;
        case 3:
            deleteRecord();
            break;
        case 4:
            searchRecord();
            break;
        case 5:
            return;
        default:
            cout << "Expected Options are 1/2/3/4/5\n";
            showMenu();
    }
}

// Driver Code
int main() {
    showMenu();
    return 0;
}
