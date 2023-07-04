#include <bits/stdc++.h>
using namespace std;

#define Nbucket 20

void bucketSort(vector<int>&arr,int n){
    int maxi = *max_element(arr.begin(),arr.begin()+n);
    int range = maxi;
    int bucketRange = (int) ceil((double)(range+1)/Nbucket);

    vector<vector<int > > bucket(Nbucket);

    for(int i=0 ; i<n ; i++){
        int num = arr[i];
        int j = (int)floor((double)num / bucketRange);
        bucket[j].push_back(num);
    }
    int i=0;
    vector<int>out;
    int idx = 0;
    for(auto vec : bucket){
        sort(vec.begin(),vec.end());
        for(auto num : vec){
            arr[idx++] = num;
        }
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
    bucketSort(A, n);

    cout << endl << "Array after After Sorting..." << endl;
    // display(A, n);
    
    clock_t endTime = clock();
    cout<<fixed;cout<<setprecision(11);
    cout <<endl << endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
