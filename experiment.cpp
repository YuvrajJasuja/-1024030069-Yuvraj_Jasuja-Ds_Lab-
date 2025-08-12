#include<iostream>
using namespace std;

int insert(int arr[],int m,int pos,int n)
{
    int newSize=n+1;
    cout<<"new size is "<<newSize;
    //shifting
    for(int i=newSize-1;i>pos-1;i--)
    {
          arr[i]=arr[i-1]; 
    }
    arr[pos-1]=m;
    cout<<" your new arr becomes ";
    for(int i=0;i<newSize;i++)
    {
        cout<<" "<<arr[i];
    }
}

int main()
{
int n,m,pos;
cout<< "enter the arr size";
cin>>n;  
int arr[n+1];
for(int i=0;i<n;i++)
{
cout<<"enter value at position"<<i+1<<endl;
cin>>arr[i];
}
cout<<"what you want to add";
cin>>m;
cout<<"At what position";
cin>>pos;
insert(arr,m,pos,n);
return 0;
}