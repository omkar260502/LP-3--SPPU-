#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// Function to merge two sorted subarrays
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Single-threaded Merge Sort
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Multithreaded Merge Sort
void threadedMergeSort(vector<int> &arr, int left, int right, int depth)
{
    if (depth == 0)
    {
        mergeSort(arr, left, right);
        return;
    }

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        thread leftThread(threadedMergeSort, ref(arr), left, mid, depth - 1);
        thread rightThread(threadedMergeSort, ref(arr), mid + 1, right, depth - 1);

        leftThread.join();
        rightThread.join();

        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    // Single-threaded Merge Sort
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array using single-threaded merge sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Reset the array for multithreaded merge sort
    arr = {12, 11, 13, 5, 6, 7};

    // Multithreaded Merge Sort (2 threads)
    threadedMergeSort(arr, 0, n - 1, 2);

    cout << "Sorted array using multithreaded merge sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
