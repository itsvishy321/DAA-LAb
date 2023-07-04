#include<bits/stdc++.h>
using namespace std; 
int linearSearch(int *arr , int size , int key){
    for(int i=0 ; i<size ; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}
int main()
{
    int arr[100000];
    int key;
    int size; 
    cout<<"Enter size of the array : ";
    cin>>size; 
    for(int i=0 ; i<size ; i++){
        arr[i] = rand()%1000;
    }
    cout<<"Enter key element to search for : ";
    cin>>key; 
    // Start the timer
    clock_t startTime = clock();
    int res = linearSearch(arr , size , key);
    clock_t endTime = clock();
    if(res == -1)
        cout<<"Not Found"<<endl;
    else
        cout<<"Found at index "<<res<<endl; 
    cout<<fixed;cout<<setprecision(11);
    cout << endl<<"Time Taken : " << (double)(endTime-startTime)/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
