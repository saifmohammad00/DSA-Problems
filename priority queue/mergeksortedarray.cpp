#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> total;
	while(n--){
		int t;
		cin>>t;
		int arr[t];
		for(int i=0;i<t;i++){
			cin>>arr[i];
		}
		for(int i=0;i<t;i++){
			total.push_back(arr[i]);
		}
	}
	cout<<total[0]<<endl;
	priority_queue<int,vector<int>, greater<int>> pq;
	for(int i=0;i<total.size();i++){
		pq.push(total[i]);
	}
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
}