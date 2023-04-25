#include<bits/stdc++.h>
using namespace std;
void buyticket(int arr[],int k,int n){
     priority_queue<int> pq;
     for(int i=0;i<n;i++){
         pq.push(arr[i]);
     }
     int c=0;
     while(!pq.empty()){
        if(pq.top()!=arr[k]){
        	pq.pop();
        	c++;
        	continue;
        }
        if(pq.top()==arr[k]){
        	pq.pop();
        	if(pq.top()!=arr[k]){
                   break;
        	}
        	else{
        		c++;
        		continue;
        	}
        }
     }
     cout<<c-1<<" ";
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	buyticket(arr,3,n);
}