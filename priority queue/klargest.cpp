#include<bits/stdc++.h>
using namespace std;
void priorityqueue(int arr[],int k, int n){
      priority_queue<int> pq;
      for(int i=0;i<n;i++){
      pq.push(arr[i]);
	  }
	  for(int i=0;i<k;i++){
	  	cout<<pq.top()<<" ";
	  	pq.pop();
	  }

}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	   cin>>arr[i];
	}
	priorityqueue(arr,4, n);

}