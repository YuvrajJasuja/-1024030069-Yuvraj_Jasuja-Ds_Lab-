#include<iostream>
using namespace std;

void printMissing(int arr[],int size){
for(int i=0;i<size;i++)
{
    if((arr[i]-i)!=1)
    {cout<<"missing element is : "<<arr[i]-1;
    break;}
}
}

int main(){
    int size;
    cout<<"give array size"<<endl;
    cin>>size;
    cout<<"enter sorted array in the range of 1 to n"<<endl;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    
    printMissing(arr,size);
    
    return 0;
}