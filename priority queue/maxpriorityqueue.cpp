#include<bits/stdc++.h>
using namespace std;
class priorityqueue{
	vector<int> pq;
public:
	priorityqueue(){

	}
	bool isempty(){
		return pq.size()==0;
	}
	int getsize(){
		return pq.size();
	}
	int getmax(){
		if(!pq.size()){
			return 0;
		}
		return pq[0];
	}
	void insert(int element){
        pq.push_back(element);
        int childindex=pq.size()-1;
        while(childindex>0){
        	int parentindex=(childindex-1)/2;
             if(pq[childindex]>pq[parentindex]){
             	int temp=pq[parentindex];
                pq[parentindex]=pq[childindex];
                pq[childindex]=temp;
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
		//down-heapify
		int parentindex=0;
		int leftindex=2*parentindex+1;
		int rightindex=2*parentindex+2;
		while(leftindex<pq.size()){
               int maxindex=parentindex;
               if(pq[maxindex]<pq[leftindex]){
                       maxindex=leftindex;
               }
               if(rightindex<pq.size() && pq[maxindex]<pq[rightindex]){
               	       maxindex=rightindex;
               }
               if(maxindex==parentindex){
               	break;
               }
               int temp=pq[maxindex];
               pq[maxindex]=pq[parentindex];
               pq[parentindex]=temp;
               parentindex=maxindex;
               leftindex=2*parentindex+1;
               rightindex=2*parentindex+2;
		}
		return ans;
	}
};
int main(){
	priorityqueue pq;
	pq.insert(2);
	pq.insert(3);
	pq.insert(4);
	pq.insert(30);
	cout<<pq.getsize()<<endl;
	cout<<pq.getmax()<<endl;
	while(!pq.isempty()){
		cout<<pq.remove()<<" ";
         
	}
}