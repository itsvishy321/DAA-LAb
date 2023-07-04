#include <bits/stdc++.h>
using namespace std;

void bubblesort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (swapped = false)
        {
            break;
        }
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{

    int A[100000];
    int n;
    cout<<endl<<"Enter size of the array between 1 to 100000 : ";
    cin>>n;
    
    for(int i=0 ; i<n ; i++){
        A[i] = rand()%1000;
    }

    
    // Start the timer
    clock_t startTime = clock();
    bubblesort(A, n);

    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n);
    
    clock_t endTime = clock();
    cout<<fixed;cout<<setprecision(11);
    cout <<endl << endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
