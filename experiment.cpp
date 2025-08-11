#include<iostream>
using namespace std;

void insert(int arr[],int m,int pos)
{
    int newSize=5;
    cout<<"new size is "<<newSize;

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
insert(arr,m,pos);
return 0;
}