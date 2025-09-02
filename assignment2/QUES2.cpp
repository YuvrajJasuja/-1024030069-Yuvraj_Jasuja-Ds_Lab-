#include<iostream>
using namespace std;

int main(){
    int arr[]={64,34,25,12,22,11,90};
    int e1=0,e2=1;
    int Swap=1;

    while(Swap!=0)
    {
        Swap=0;
        e1=0;
        e2=1;
        int count=1;
        while(count!=0&&(e2<7)){
        if(arr[e1]>arr[e2])
        {
            Swap++;
            int temp=arr[e1];
            arr[e1]=arr[e2];
            arr[e2]=temp;
        }
            e1++;
            e2++;
            if(e2==7)
            {count=0;}
        
    }
    }
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}