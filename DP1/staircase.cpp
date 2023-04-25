#include<bits/stdc++.h>
using namespace std;
int dpstaircase(int n){
	int arr[n+1];
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<n+1;i++){
    	arr[i]=arr[i-3]+arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int staircase(int n){
	if(n<=1){
		return 1;
	}
	int a=staircase(n-1);
	int b=0,c=0;
	if(n>1){
      b=staircase(n-2);
	}
	if(n>2){
	c=staircase(n-3);
	}
	return a+b+c;
}
int memostaircase(int arr[], int n){
	if(n<=1){
		return 1;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int a=staircase(n-1);
	int b=0,c=0;
	if(n>1){
      b=staircase(n-2);
	}
	if(n>2){
	c=staircase(n-3);
	}
	arr[n]=a+b+c;
	return arr[n];

}
int memostaircase(int n){
	int* arr=new int(n+1);
	for(int i=0;i<n+1;i++){
		arr[i]=-1;
	}
	return memostaircase(arr,n);
}
int main(){
	int n;
	cin>>n;
	cout<<staircase(n)<<endl;
	cout<<memostaircase(n)<<endl;
	cout<<dpstaircase(n)<<endl;
}