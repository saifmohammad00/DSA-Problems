#include<bits/stdc++.h>
using namespace std;
void inplacesort(int pq[], int n){
       for(int i=1;i<n;i++){
             int childindex=i;
             while(childindex>0){
             	 int parentindex=(childindex-1)/2;
             	 if(pq[childindex]<pq[parentindex]){
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
        int size=n;
        while(size>1){
        int temp=pq[0];
        pq[0]=pq[size-1];
        pq[size-1]=temp;
        size--;
        int parentindex=0;
		int leftindex=2*parentindex+1;
		int rightindex=2*parentindex+2;
		while(leftindex<size){
               int minindex=parentindex;
               if(pq[minindex]>pq[leftindex]){
                       minindex=leftindex;
               }
               if(rightindex<size && pq[minindex]>pq[rightindex]){
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
       }
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	inplacesort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}