#include<bits/stdc++.h>
using namespace std;
int getvalues(int a,int b,int base,int sum){
	int res=0;
	int p=pow(base,b);
	while(p+sum<a){
		res+=getvalues(a,b,base+1,sum+p);
		base++;
		p=pow(base,b);
	}
	if(p+sum==a)
		res++;
	return res;
}
int allways(int a,int b){
	return getvalues(a,b,1,0);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<allways(a,b);
}