#include<bits/stdc++.h>
using namespace std;
void subset(int x,int sum){
	if(sum==1){
		return;
	}
	cout<<sum<<" ";
	subset(x,sum+1);
	cout<<sum<<" ";
}
int main(){
	
	subset(0,0);
}