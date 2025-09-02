#include<iostream>
using namespace std;

int SIZE(string a)
{
int size=0;
int i=0;
while(a[i]!='\0')
{size++;i++;}
return size;
}

//4a concatinate strings
void concatString(string a,string b)
{
    cout<<a+b<<endl;
}
//4b reverse a string
void reverseString(string a)
{
int size = SIZE(a);
for(int i=size;i>=0;i--)
{cout<<a[i];}cout<<endl;
}

//4c delete all the vowels
void DeleteVowels(string a)
{
    int size = SIZE(a);
    for(int i=0 ; i<size ; i++)
    {
        if(a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='o'&&a[i]!='u')
        cout<<a[i];
    }cout<<endl;
}

//4d sorting in alphabetical order
void SortString(string a)
{
    int size = SIZE(a);
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            if(a[i]>a[j])
            swap(a[i],a[j]);
        }

    }
    cout<<a<<endl;
}

//4e upper to lower case
void lowerCase(string a)
{
    int size = SIZE(a);
    //cout<<int('Z')<<" "<<int('A')<<; // 90 A=65 a=97  97-65=32
    for(int i=0 ; i<size ; i++)
    {
        if(a[i]>=65&&a[i]<=90)
        {
            a[i]=a[i]+32;
        }
    }
    cout<<a<<endl;
}



int main()
{
concatString("yuvraj","jasuja");
reverseString("yuvraj");
DeleteVowels("yuvraj");
SortString("yuvraj");
lowerCase("YUVRaj");
return 0;
}