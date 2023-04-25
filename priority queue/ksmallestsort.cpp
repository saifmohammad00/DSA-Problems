#include<bits/stdc++.h>
using namespace std;
void ksmallestsort(int input[], int n, int k){
	priority_queue<int> pq;
	for(int i=0;i<k;i++){
		pq.push(input[i]);
	}
	int j=0;
	for(int i=k;i<n;i++){
		if(pq.top()>input[i]){
            input[j]=pq.top();
		    pq.pop();
		    pq.push(input[i]);
		    j++;
		}
	}
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
int main(){
	int input[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
	ksmallestsort(input,13,3);
}