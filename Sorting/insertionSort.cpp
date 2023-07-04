
#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int>& arr , int n)
{
    // base case
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp){
                arr[j + 1] = arr[j];
            }

            else{
                break;
            }
        }
        arr[j + 1] = temp;
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
    insertionsort(A, n);

    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n);
    
    clock_t endTime = clock();
    cout<<fixed;cout<<setprecision(11);
    cout <<endl<< endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}

