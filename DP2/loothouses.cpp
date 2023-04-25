#include<bits/stdc++.h>
using namespace std;
int loothouses(int arr[],int n){
	if(n<0){
		return 0;
	}
	if(n==0){
        return arr[0];
	}
	int pick=arr[n]+loothouses(arr,n-2);
	int notpick=loothouses(arr,n-1);
	return max(pick,notpick);
}
int dploothouses(int arr[],int n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return arr[0];
	}
	int dp[n];
	dp[0]=arr[0];
	dp[1]=max(arr[0],arr[1]);
	for(int i=2;i<n;i++){
           	 dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
           }
 	return dp[n-1];

}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<loothouses(arr,n-1)<<endl;
	cout<<dploothouses(arr,n)<<endl;
}