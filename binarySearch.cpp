#include <bits/stdc++.h>
using namespace std; 
int binarySearch(int *arr , int s , int e , int key){
    int mid;
    while (s <= e)
    {
        mid = s + (e-s)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            s = mid+1;
        else
            e = mid-1;
    }
    return -1;
}
int main()
{
    int arr[100000];
    int key;
    int size;
    struct timespec start,stop; 
    cout<<"Enter size of the array : ";
    cin>>size; 
    for(int i=0 ; i<size ; i++){
        arr[i] = rand()%1000;
    }
    cout<<"Enter key element to search for : ";
    cin>>key; 
    sort(arr , arr + size); 
    // Start the timer
    clock_t startTime = clock();
    int res = binarySearch(arr , 0 , size-1 , key);
    clock_t endTime = clock();
    if(res == -1)
        cout<<"Not Found"<<endl;
    else
        cout<<"Found at index "<<res<<endl; 
    cout<<fixed;cout<<setprecision(11);
    cout << endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl; 
    return 0;
}
