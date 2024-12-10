#include <iostream>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to display the list of students
void display(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Roll No: " << students[i].rollNo 
             << ", Name: " << students[i].name 
             << ", SGPA: " << students[i].sgpa << endl;
    }
}
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}
void insertionSort(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}
int binarySearch(Student students[], int n, string target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (students[mid].name == target)
            return mid;

        if (students[mid].name < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main() {
    const int n = 15;
    Student students[n] = {
        {101, "Alice", 8.7}, {105, "Bob", 7.8}, {103, "Charlie", 9.1},
        {108, "David", 6.8}, {102, "Eva", 8.5}, {104, "Frank", 7.9},
        {106, "Grace", 8.2}, {107, "Hank", 8.0}, {110, "Ivy", 9.0},
        {111, "Jack", 7.5}, {109, "Kate", 8.1}, {112, "Liam", 7.6},
        {113, "Mona", 8.3}, {114, "Nina", 8.8}, {115, "Oscar", 8.6}
    };

    cout << "Original List:" << endl;
    display(students, n);

    cout << "\nSorted by Roll No (Bubble Sort):" << endl;
    bubbleSort(students, n);
    display(students, n);

    cout << "\nSorted by Name (Insertion Sort):" << endl;
    insertionSort(students, n);
    display(students, n);

    string target;
    cout << "\nEnter the name to search: ";
    cin >> target;

    int result = binarySearch(students, n, target);
    if (result != -1)
        cout << "Student Found: " << students[result].rollNo << ", " 
             << students[result].name << ", " << students[result].sgpa << endl;
    else
        cout << "Student not found!" << endl;

    return 0;
}
