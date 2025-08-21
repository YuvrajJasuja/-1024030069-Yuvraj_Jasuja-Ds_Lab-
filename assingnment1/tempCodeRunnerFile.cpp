#include<iostream>
using namespace std;
#define max 100
void columnSum(int r,int c,int arr[][max]){
    int sum = 0;
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++)
        {
            sum += arr[i][j];
        }
        cout<<"sum for column "<<i<<"is :"<<sum<<endl;
        sum=0;
    }
}

void rowSum(int r,int c,int arr[][max]){
int sum = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        {
            sum += arr[i][j];
        }
        cout<<"sum for row "<<i<<"is :"<<sum<<endl;
        sum=0;
    }
}

int main(){
    int r,c;
    cout<<"for  2d array enter in this seq row column";
    cin>>r>>c;
   int  arr[max][max];
   
    cout<<"enter elements in array";
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        cin>>arr[i][j];
         columnSum(r,c,arr);
    rowSum(r,c,arr);
    return 0;
}