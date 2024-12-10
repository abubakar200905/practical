#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not the largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to the end
        swap(arr[0], arr[i]);
        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original Array: ";
    display(arr, n);

    heapSort(arr, n);

    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}
