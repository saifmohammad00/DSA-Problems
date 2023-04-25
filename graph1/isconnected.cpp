#include<bits/stdc++.h>
using namespace std;

void print(int** edges,int sv,int n,bool* visited){
       queue<int> pendingnodes;
       pendingnodes.push(sv);
       visited[sv]=true;
       while(!pendingnodes.empty()){
           int currentvertex=pendingnodes.front();
           pendingnodes.pop();
           cout<<currentvertex<<" ";
           for(int i=0;i<n;i++){
           	  if(i==currentvertex){
           	  	continue;
           	  }
           	  if(edges[currentvertex][i]==1 && !visited[i]){
           	  	pendingnodes.push(i);
           	  	visited[i]=true;
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
	print(edges,0,n,visited);
    cout<<endl;
    for(int i=0;i<n;i++){
        if(visited[i]){
          if(i==n){
            cout<<"true"<<endl;
          } 
        }
        else{
            cout<<"false"<<endl;
            break;
        }
    }

}