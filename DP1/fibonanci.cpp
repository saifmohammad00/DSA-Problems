#include<bits/stdc++.h>
using namespace std;
int dpfibonanci(int n){
	int arr[n+1];
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<n+1;i++){
          arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[n];
}
int recursionfibonanci(int n){
	if(n<=1){
		return n;
	}
	return recursionfibonanci(n-1)+recursionfibonanci(n-2);
}
int memoizationfibonanci(int arr[],int n){
	if(n<=1){
		return n;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	return memoizationfibonanci(arr,n-1)+memoizationfibonanci(arr,n-2);
}
int memoizationfibonanci(int n){
	int *arr=new int(n+1);
	for(int i=0;i<n+1;i++){
		arr[i]=-1;
	}
	return memoizationfibonanci(arr,n);
	
}
int main(){
	int n;
	cin>>n;
	cout<<recursionfibonanci(n)<<endl;
	cout<<memoizationfibonanci(n)<<endl;
	cout<<dpfibonanci(n);
}