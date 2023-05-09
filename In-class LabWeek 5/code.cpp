#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int partition(vector<int>& arr, int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // Move pivot to end
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]); // Move pivot to its final place
    return storeIndex;
}

void quicksort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int pivotIndex = left + (right - left) / 2;
        int pivotNewIndex = partition(arr, left, right, pivotIndex);
        quicksort(arr, left, pivotNewIndex - 1);
        quicksort(arr, pivotNewIndex + 1, right);
    }
}


double Median(vector<int>& arr)
{
    int n = arr.size();
    if (n % 2 == 0) {
        return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        return (double)arr[n / 2];
    }
}

int main()
{
    vector<int> array;
    int n;

    cout << "Size of the array: ";
    cin >> n;

    cout << "Array elements (space seperated): ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        array.push_back(value);

        quicksort(array, 0, i); 
        cout << "Sorted array: ";
        for (int j = 0; j < i+1; j++) {
            cout << array[j] << " ";
        }
        cout << endl;

        double median = Median(array); 
        cout << "Running median: " << fixed << setprecision(1) <<median << endl;
    }

    return 0;
}
