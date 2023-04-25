#include<bits/stdc++.h>
using namespace std;
bool dfs(int** edges,int n,int fst,int lst,bool* visited){
    if(fst==lst){
        return true;
    }
    visited[fst]=true;
    for(int i=0;i<n;i++){
      if(i==fst){
        continue;
      }
      if(edges[fst][i]==1){
        if(visited[i]){
            continue;
        }
        return dfs(edges,n,i,lst,visited);
      }
    }
    return false;
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
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int fst,lst;
    cin>>fst>>lst;
    if(dfs(edges,n,fst,lst,visited)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}