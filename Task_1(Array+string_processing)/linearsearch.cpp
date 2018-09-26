#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"The size of your data:"<<endl;
    int n,num;
    int j=0;
    cin>>n;
    int ara[n];
    cout<<"Input your numbers using space: "<<endl;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    cout<<"Input the number you want to search:"<<endl;
    cin>>num;
    for(int i=0;i<n;i++){
        if(num==ara[i]){
            cout<<"found at position: "<<i+1<<endl;
            j=1;

        }
    }
    if(j==0)
        cout<<"Not Found"<<endl;
    return 0;


}
