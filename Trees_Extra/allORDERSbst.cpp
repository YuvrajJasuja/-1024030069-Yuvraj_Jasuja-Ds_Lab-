#include<iostream>
using namespace std;

class node{
    public:
int data;
node *left=NULL;
node *right=NULL;
};
node(int data){
    node->data=data;
    left = 
}
void buildTree(int arr[],int i=0){

    if(arr[i]==arr[0]){
        node n1 = new node(arr[0]);
        n1->data=arr[0];
    }

    int n;
    bool res {true};
    
while(res==true){
    cout<<"what order you want pre in post"<<endl;
    cin>>n;

    switch(n){
        case 1:
        preorder(arr);
        case 2:
        inorder(arr);
        case 3:
        postorder(arr);
    }
    cout<<"do you want to continue"<<endl;
    cin>>res;
}
}

void preorder(int arr[],int i=0){
    //root left right 
    cout<<" "<<arr[i];
    if(arr[i]==NULL){
        return;}
        i++;
        cout<< " " << preorder(arr);
        i++;
        cout << " " << preorder(arr);
}

int main()
{
    int arr[5]={1,2,3,4,5};
    buildTree(arr);

    
    return 0;
}