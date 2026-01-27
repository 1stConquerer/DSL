#include<iostream>
using namespace std;
int main(){
   // cout<<"hello world";
   int a[2][2];
   for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        cout<<"enter the element a["<<i<<"]["<<j<<"]";
        cin>>a[i][j];

    }
   }
  
   for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        cout<<a[i][j]<<" ";
        
        
    }
    cout<<endl;
   }
}
