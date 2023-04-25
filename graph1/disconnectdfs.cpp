#include<bits/stdc++.h>
using namespace std;
void dfs(int** edges,int sv,int n,bool* visited){
	  cout<<sv<<endl;
	  visited[sv]=true;
      for(int i=0;i<n;i++){
      	if(i==sv){
      		continue;
      	}
      	if(edges[sv][i]==1){
      		if(visited[i]){
      			continue;
      		}
      		dfs(edges,i,n,visited);
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
		int f,l;
		cin>>f>>l;
		edges[f][l]=1;
		edges[f][l]=1;
	}
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
    	visited[i]=false;
    }
	for(int i=0;i<n;i++){
		if(!visited[i]){
		dfs(edges,i,n,visited);

		}
	}
}