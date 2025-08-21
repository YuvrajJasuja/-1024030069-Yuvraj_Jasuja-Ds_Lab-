#include<iostream>
using namespace std;

void deldup(int arr[],int size){

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                for(int k=j;k<size;k++)
            {
            arr[k]=arr[k+1];
            }
                 j--;
                size--;
            }
        }
}  //print
    for(int i=0;i<size;i++)
   {
    cout<<arr[i]<<" ";
   }}


int main(){
    int n;
    cout<<"enter the size of arr";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
   {
    cout<<"enter value at position"<<i<<endl;
    cin>>arr[i];
   }
deldup(arr,n);
return 0;
}
