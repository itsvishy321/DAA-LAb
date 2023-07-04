#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // placing pivot at right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    // sorting left hand side
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quicksort(vector<int>& arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    // left side sort
    quicksort(arr, s, p - 1);

    //  right side sort
    quicksort(arr, p + 1, e);
}

void display(vector<int>& arr , int n)
{
    for (int i = 0; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> A(100000);
    int n;
    cout << endl
         << "Enter size of the array between 1 to 100000 : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    // Start the timer
    clock_t startTime = clock();

    quicksort(A, 0 , n-1);
    
    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n);
    clock_t endTime = clock();
    cout << fixed;
    cout << setprecision(11);
    cout << endl << endl << "Time Taken : " << (double)(endTime-startTime) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
