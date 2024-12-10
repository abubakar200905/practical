#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure for Student
struct Student {
    int rollNo;
    string name, division, address;
};

// Function to add records
void addRecords() {
    ofstream outFile("students.dat", ios::app | ios::binary);
    if (!outFile) {
        cout << "File could not be opened!\n";
        return;
    }

    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore();  // Clear buffer
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    getline(cin, s.division);
    cout << "Enter Address: ";
    getline(cin, s.address);

    outFile.write((char*)&s, sizeof(s));
    outFile.close();
    cout << "Record added successfully!\n";
}

// Function to display all records
void displayRecords() {
    ifstream inFile("students.dat", ios::in | ios::binary);
    if (!inFile) {
        cout << "File could not be opened!\n";
        return;
    }

    Student s;
    cout << "\n--- Student Records ---\n";
    while (inFile.read((char*)&s, sizeof(s))) {
        cout << "\nRoll No: " << s.rollNo
             << "\nName: " << s.name
             << "\nDivision: " << s.division
             << "\nAddress: " << s.address << "\n";
    }
    inFile.close();
}

// Function to update a record
void updateRecord(int rollNo) {
    fstream file("students.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File could not be opened!\n";
        return;
    }

    Student s;
    bool found = false;
    while (file.read((char*)&s, sizeof(s))) {
        if (s.rollNo == rollNo) {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter New Division: ";
            getline(cin, s.division);
            cout << "Enter New Address: ";
            getline(cin, s.address);

            int pos = -1 * static_cast<int>(sizeof(s));
            file.seekp(pos, ios::cur);
            file.write((char*)&s, sizeof(s));
            cout << "Record updated successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found!\n";
    }
    file.close();
}

// Main function
int main() {
    int choice, rollNo;

    while (true) {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Update Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecords();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                cout << "Enter Roll No to Update: ";
                cin >> rollNo;
                updateRecord(rollNo);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
