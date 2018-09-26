#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    string pat;
    cin>>text>>pat;
    int index=0,i,j;
    int tl=text.size();
    int pl=pat.size();
    int max=tl-pl+1;
    for(i=0;i<max;i++){
        for( j=0;j<pl;j++){
            if(pat[j]!=text[i+j])
                break;
        }
        if(j==pl)
        {
            index=i+1;
            break;
        }
    }
    cout<<index;

}
