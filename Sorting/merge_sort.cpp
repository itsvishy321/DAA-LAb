#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values in first

    int mainarrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainarrayIndex++];
    }

    // copy values in second

    mainarrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainarrayIndex++];
    }

    // merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainarrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainarrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainarrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainarrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainarrayIndex++] = second[index2++];
    }

    // clearing heap memory
    delete[] first;
    delete[] second;
}

void mergesort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // left side sort krna
    mergesort(arr, s, mid);

    // right side sort krna
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

void display(vector<int> &arr , int n)
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

    mergesort(A, 0 , n-1);
    
    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n);
    clock_t endTime = clock();
    cout << fixed;
    cout << setprecision(11);
    cout << endl << endl << "Time Taken : " << (double)(endTime-startTime) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}