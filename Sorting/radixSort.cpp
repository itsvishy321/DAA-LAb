#include <bits/stdc++.h>
using namespace std;

void countsort(vector<int>& arr, int exp , int n)
{

    vector<int> farr(10, 0);

    // Creating frequency array

    for (int i = 0; i < n; i++)
    {
        farr[(arr[i] / exp) % 10]++;
    }

    // Making prefix sum array

    for (int i = 1; i < farr.size(); i++)
    {
        farr[i] += farr[i - 1];
    }

    // Creating array for storing sorted elements
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int val = (arr[i] / exp) % 10;
        int pos = farr[val];
        int idx = pos - 1;
        ans[idx] = arr[i];
        farr[val]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }

}

void radixsort(vector<int>& arr , int n)
{
    int max = *max_element(arr.begin(), arr.begin() + n);
    int exp = 1;
    while (exp <= max)
    {
        // Have to declare countsort() before using
        countsort(arr, exp , n);
        exp = exp * 10;
    }

}

void display(vector<int>& arr , int size)
{
    for (int i = 0; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> A(100000);
    int n;
    cout<<endl<<"Enter size of the array between 1 to 100000 : ";
    cin>>n;
    
    for(int i=0 ; i<n ; i++){
        A[i] = rand()%1000;
    }

    
    // Start the timer
    clock_t startTime = clock();
    radixsort(A, n);

    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n);
    
    clock_t endTime = clock();
    cout<<fixed;cout<<setprecision(11);
    cout <<endl << endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
