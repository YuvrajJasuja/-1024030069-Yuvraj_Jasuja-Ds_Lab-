using namespace std;
#include<iostream>
#include <stack>
#include <string>

void reverse(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++)
    st.push(s[i]);
    while(!st.empty())
    {cout<<st.top();
    st.pop();}
}

int main()
{
string ss= "yuvraj";
reverse(ss);
return 0;
}