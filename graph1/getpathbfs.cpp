#include<bits/stdc++.h>
using namespace std;

void print(int** edges,int n,int fst,int lst,bool* visited){
       queue<int> pendingnodes;
       pendingnodes.push(fst);
       visited[fst]=true;
       unordered_map<int,int> m;
       while(!pendingnodes.empty()){
           int currentvertex=pendingnodes.front();
           pendingnodes.pop();
           for(int i=0;i<n;i++){
           	  if(i==currentvertex){
           	  	continue;
           	}
           	  if(edges[currentvertex][i]==1 && !visited[i]){
           	  	pendingnodes.push(i);
           	  	visited[i]=true;
                m[i]=currentvertex;
                if(i==lst){
                     int x=lst;
                     while(x!=fst){
                     cout<<x<<" ";
                     x=m[x];
                    }
                    cout<<x<<" ";
                    return;
                }
           	  }
           }
       }
      
}       

int main(){
	int n,e;
	cin>>n>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
        	edges[i][j]=0;
        }
	}
	for(int i=0;i<e;i++){
      int s,f;
      cin>>s>>f;
      edges[s][f]=1;
      edges[f][s]=1;
	}
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
    int fst,lst;
    cin>>fst>>lst;
	print(edges,n,fst,lst,visited);
}