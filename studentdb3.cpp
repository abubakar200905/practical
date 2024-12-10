#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure for Student
struct Student {
    int rollNo;
    string name, division, address;
};

// Function to add a new record
void addRecord() {
    ofstream outFile("students.dat", ios::app | ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore();  // To ignore any leftover newline in the buffer
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    getline(cin, s.division);
    cout << "Enter Address: ";
    getline(cin, s.address);

    outFile.write((char*)&s, sizeof(s));  // Write the record to the file
    outFile.close();

    cout << "Record added successfully!" << endl;
}

// Function to display all records
void displayRecords() {
    ifstream inFile("students.dat", ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
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

// Function to search for a record by roll number
void searchRecord(int rollNo) {
    ifstream inFile("students.dat", ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    Student s;
    bool found = false;
    while (inFile.read((char*)&s, sizeof(s))) {
        if (s.rollNo == rollNo) {
            cout << "\nRecord Found!"
                 << "\nRoll No: " << s.rollNo
                 << "\nName: " << s.name
                 << "\nDivision: " << s.division
                 << "\nAddress: " << s.address << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }

    inFile.close();
}

// Function to delete a record by roll number
void deleteRecord(int rollNo) {
    ifstream inFile("students.dat", ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    ofstream outFile("temp.dat", ios::out | ios::binary);
    if (!outFile) {
        cout << "Error opening temp file for writing!" << endl;
        return;
    }

    Student s;
    bool found = false;
    while (inFile.read((char*)&s, sizeof(s))) {
        if (s.rollNo != rollNo) {
            outFile.write((char*)&s, sizeof(s));  // Write records that don't match the rollNo
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    // Replace the original file with the updated file
    if (found) {
        remove("students.dat");   // Delete original file
        rename("temp.dat", "students.dat");  // Rename temp file to original file name
        cout << "Record with Roll No " << rollNo << " deleted successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
        remove("temp.dat");  // If not found, delete temp file
    }
}

// Main function
int main() {
    int choice, rollNo;

    while (true) {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record by Roll No\n";
        cout << "4. Delete Record by Roll No\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                searchRecord(rollNo);
                break;
            case 4:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteRecord(rollNo);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
