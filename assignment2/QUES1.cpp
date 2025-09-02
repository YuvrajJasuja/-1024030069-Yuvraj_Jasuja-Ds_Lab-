#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key)
{
    int s=0;
    int e=size-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            s=mid+1;
        }
        if(arr[mid]>key){
            e=mid-1;
        }
    }
    //return 0; not used since index 0 bhi ho skta
    return -1;
}

int main(){
    cout<<"no of elements?"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"enter sorted elements"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"what element you want to find using binary search"<<endl;
    int key;
    cin>>key;
    int index = binarySearch(arr,size,key);
    if (index==-1)
    {
        cout<<"element not found in ur array";
    }
    else 
    cout<<"found at the position : "<<index+1;
    return 0;
}