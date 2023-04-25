#include<bits/stdc++.h>
using namespace std;
class priorityqueue{
	vector<int> pq;
public:
	priorityqueue(){

	}
	int getsize(){
		return pq.size();
	}
	bool isempty(){
		return pq.size()==0;
	}
	int getmin(){
		if(pq.size()==0){
			return 0;
		}
		return pq[0];
	}
	void insert(int element){
		pq.push_back(element);
		int childindex=pq.size()-1;
		while(childindex>0){
                 int parentindex=(childindex-1)/2;
		if(pq[childindex]<pq[parentindex]){
			int temp=pq[childindex];
			pq[childindex]=pq[parentindex];
			pq[parentindex]=temp;
		}
		else{
			break;
		}
		childindex=parentindex;
		}
	}
	int remove(){
		if(isempty()){
               return 0;
		}
		int ans=pq[0];
		pq[0]=pq[pq.size()-1];
		pq.pop_back();
		//dowm-heapify
		int parentindex=0;
		int leftindex=2*parentindex+1;
		int rightindex=2*parentindex+2;
		while(leftindex<pq.size()){
               int minindex=parentindex;
               if(pq[minindex]>pq[leftindex]){
                       minindex=leftindex;
               }
               if(rightindex<pq.size() && pq[minindex]>pq[rightindex]){
               	       minindex=rightindex;
               }
               if(minindex==parentindex){
               	break;
               }
               int temp=pq[minindex];
               pq[minindex]=pq[parentindex];
               pq[parentindex]=temp;
               parentindex=minindex;
               leftindex=2*parentindex+1;
               rightindex=2*parentindex+2;
		}
		return ans;
	}
};
int main(){
	priorityqueue p;
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(6);
	cout<<p.getsize()<<endl;
	cout<<p.getmin()<<endl;
	while(!p.isempty()){
		cout<<p.remove()<<" ";
	}
	cout<<endl;
}