#include<bits/stdc++.h>
using namespace std;
int fact(int s)
{
    if(s==0)
    {
        return 1;
    }
    return s*fact(s-1);

}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}