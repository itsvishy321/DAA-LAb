#include <bits/stdc++.h>
using namespace std;

vector<int> countsort(vector<int> arr , int n)
{
    int min = *min_element(arr.begin() , arr.begin() + n);
    int max = *max_element(arr.begin() , arr.begin() + n);

    int range = max - min + 1;
    vector<int> farr(range, 0);

    // Creating frequency array

    for (int i = 0; i < n; i++)
    {
        int findex = arr[i] - min;
        farr[findex]++;
    }

    // Making prefix sum array

    for (int i = 1; i < range; i++)
    {
        farr[i] += farr[i - 1];
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = farr[val - min];
        int idx = pos - 1;
        ans[idx] = val;
        farr[val - min]--;
    }

    return ans;
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
    A = countsort(A, n);

    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n); 2 
    
    clock_t endTime = clock();
    cout<<fixed;cout<<setprecision(11);
    cout <<endl << endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
