#include<bits/stdc++.h>
using namespace std;
int yes(char e[],string s,int n)
{
    if(n==0)
    {
        return 0;
    }
    if(e[n]==s)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return yes(e,s,n-1);
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        char e[9]={'yes','Yes','yEs','yeS','YEs','yES','YeS','YES','\0'};
        string s;
        cin>>s;
        yes(e,s,7);
        return 0;
            
    }
}
