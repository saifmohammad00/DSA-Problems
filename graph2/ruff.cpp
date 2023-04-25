#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int result=1;
	if(n==1){
            cout<<1;
            return 0;
     }
     for(int i=2;i<=n;i++){
         result+=4*(i-1);
     }
     cout<<result;
}