#include<bits/stdc++.h>
using namespace std;
void runningmedian(int arr[],int n){
	priority_queue<int> max;
	priority_queue<int,vector<int>, greater<int>> min;
	for(int i=0;i<n;i++){
        if(i==0){
        	max.push(arr[i]);
        }
        else{
        	if(arr[i]<max.top()){
        		max.push(arr[i]);
        	}
        	else{
        		min.push(arr[i]);
        	}
        }

        if(int(max.size()-min.size())>1){
        	int c=max.top();
        	max.pop();
        	min.push(c);
        }
        else if(int(min.size()-max.size())>1){
        	int c=min.size();
        	min.pop();
        	max.push(c);
        }
        int c=max.size()+min.size();
        	if(c%2==0){
        		cout<<(max.top()+min.top())/2<<" ";
        	}
        	else{
        		if(max.size()>min.size())
        		cout<<max.top()<<" ";
        	    else{
        	    	cout<<min.top()<<" ";
        	    }
        	}

    }
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	runningmedian(arr,n);
}