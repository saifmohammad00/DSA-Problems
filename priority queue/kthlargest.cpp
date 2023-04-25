#include<bits/stdc++.h>
using namespace std;
void kthlargest(int arr[],int k, int n){
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}
	for(int i=0;i<k-1;i++){
		pq.pop();
	}
		cout<<pq.top()<<" ";
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	kthlargest(arr,4,n);
}