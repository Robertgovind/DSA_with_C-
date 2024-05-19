#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 30, 20, 40, 50, 90};

    // Making max heap
    for (int i = 6 / 2; i > 0; i--)
    {
        heapify(arr, 6, i);
    }
    heapSort(arr, 5);
    cout << "ans" << endl;
    for (int i = 1; i < 6; i++)
        cout << arr[i] << " ";
}