#include<iostream>
using namespace std;

int arr[100];
int n = 0;

void create()
{
    cout<<"enter no of elements";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter value at index "<<i<<": ";
        cin>>arr[i];
    }

}
void display()
{
    cout<<"your created array "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertE()
{
    cout<<"what you want to insert and what position";
    int pos;
    int what;
    n++;
    cin>>what>>pos;
    for(int i=n-1;i>pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=what;
}

void deleteE()
{
    int del,count=0;
    cout<<"what element you want to delete in arr";
    cin>>del;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==del)
        {
            count++;
            for(int j=i;j<n;j++)
            {
                arr[j]=arr[j+1];
            }
            n--;
            i--; //# in case of dublicates
        }
    }
    if(count==0)
    {
        cout<<"element is not present";
    }
}

void linearSearch()
{
    int ele;
    int count;
    cout<<"tell what element you want to search";
    cin>>ele;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele){
            cout<<"found at the position"<<i+1<<endl;
            count++;
        }
    }
    if(count==0)
        {
            cout<<"element not present in array";
        }
}
int main(){
cout<<" MENU "<<endl<<" 1 CREATE "<<endl<<" 2 DISPLAY "<<endl<<" 3 INSERT "<<endl<<" 4 DELETE "<<endl<<" 5 LINEAR SEARCH "<<endl<<" 6 EXIT "<<endl;

cout<<"enter the choice";
int y;
cin>>y;


while(y!=6)
{
    switch(y)
    {case 1:
    create();
    break;

    case 2:
    display();
    break;

    case 3:
    insertE();
    break;

    case 4:
    deleteE();
    break;

    case 5:
    linearSearch(); 
    break;

    case 6:
    cout<<"THANKYOU";
    break;
}

    cout<<"enter the choice again";
    cin>>y;

}
return 0;
}
