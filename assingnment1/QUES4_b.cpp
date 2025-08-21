#include<iostream>
using namespace std;
#define max 100
void multiply(int a1[][max],int a2[][max],int r1,int c1,int r2,int c2)
{
int result[max][max];
for(int i=0;i<r1;i++){
    for(int j=0;j<c2;j++)
{
    for(int k=0;k<r2;k++)
    result[i][j] += a1[i][k]*a2[k][j];
}
}
for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int r1,r2,c1,c2;
    cout<<"enter in this seq row1 row2 column1 column2"<<endl;
    cin>>r1>>r2>>c1>>c2;
    if(r2!=c1){
        cout<<"multiplication not possible";
    }
    else
    {
        int a1[max][max];
        int a2[max][max];
        cout<<"enter elements in array 1";
        for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
        cin>>a1[i][j];
        cout<<"enter elements in array 2";
        for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
        cin>>a2[i][j];
        
        multiply(a1,a2,r1,c1,r2,c2);
    }
    return 0;
}