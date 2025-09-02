#include <iostream>
using namespace std;

int binaryFinding(int arr[],int size)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]-mid!=1&&arr[mid-1]==1){
            return arr[mid]-1;
        }
        if(arr[mid-1]-(mid-1)==1)
        s=mid+1;
        else 
        e=mid-1;
    }
}

int main() {
    cout<<"enter size of array"<<endl;
    int size;
    cin>>size;
    cout<<"enter array"<<endl;
    int arr[size];
    binaryFinding(arr,size);
    
    return 0;
}