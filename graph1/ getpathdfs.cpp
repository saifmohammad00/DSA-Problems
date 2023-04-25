#include<bits/stdc++.h>
using namespace std;
bool dfs(int** edges,int n,int fst,int lst,bool* visited,vector<int>& arr){
    if(fst==lst){
        arr.push_back(fst);
        return true;
    }
    visited[fst]=true;
    bool ans=false;
    for(int i=0;i<n;i++){
      if(i==fst){
        continue;
      }
      if(edges[fst][i]==1){
        if(visited[i]){
            continue;
        }  
        ans=dfs(edges,n,i,lst,visited,arr);
        if(ans==true){
        	arr.push_back(fst);
        	return true;
        }
      }
    }
    return ans;
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
    vector<int> arr;
    bool g=dfs(edges,n,fst,lst,visited,arr);
    for(int i=0;i<arr.size();i++){
    	cout<<arr[i]<<" ";
    }
}