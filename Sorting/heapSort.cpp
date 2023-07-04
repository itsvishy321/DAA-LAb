#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int N, int i)
{
    int largest = i;
 
    int left = 2 * i + 1;
 
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(vector<int>&arr, int N)
{
     for (int i = N - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


void display(vector<int> arr , int size)
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
    for (int i = (n/2)-1 ; i >= 0; i--){
        heapify(A,n,i);
    }

    heapSort(A, n);

    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n);
    
    clock_t endTime = clock();
    cout<<fixed;cout<<setprecision(11);
    cout <<endl << endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
