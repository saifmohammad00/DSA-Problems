#include<bits/stdc++.h>
using namespace std;
bool checkmaxheap(int arr[], int n){
	for(int i=1;i<n;i++){
		int parent=(i-1)/2;
		if(arr[parent]<arr[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	cout<<checkmaxheap(arr,n);
}