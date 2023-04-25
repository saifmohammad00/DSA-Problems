#include<iostream>
using namespace std;
#include<cmath>

// code correct compiler issue for h>5

int dpnoofbinarytree(int h){
     int arr[h+1];
     arr[0]=1;
     arr[1]=1;
     int mod=(int)(pow(10,9)+7);
     for(int i=2;i<=h;i++){
          arr[i]=(int)(((((long)(arr[i-1])*arr[i-1])%mod)+(2*(long)(arr[i-1])*arr[i-2])%mod)%mod);
     }
     return arr[h];
}
int noofbinarytree(int h){
     if(h<=1){
     	return 1;
     }
     int a=noofbinarytree(h-1);
     int b=noofbinarytree(h-2);
     int mod=(int)(pow(10,9)+7);
     int temp1=(int)(((long)(a)*a)%mod);
     int temp2=(int)((2* (long)(a)*b)%mod);
     int ans=(temp1+temp2)%mod;
     return ans;
}
int main(){
	int h;
	cin>>h;
	cout<<noofbinarytree(h)<<endl;
     cout<<dpnoofbinarytree(h)<<endl;
}