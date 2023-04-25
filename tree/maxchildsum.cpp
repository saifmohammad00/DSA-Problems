#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode{
	public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data){
	this->data=data;
	}
};
TreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
	     TreeNode<int>* front=pendingnodes.front();
	     pendingnodes.pop();
	     int n;
	     cin>>n;
	     for(int i=0;i<n;i++){
	             int childdata;
	             cin>>childdata;
	             TreeNode<int>* child=new TreeNode<int>(childdata);
                 front->children.push_back(child);
                 pendingnodes.push(child);
	     }
	}
	return root;
}
void printlevelwise(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
	    TreeNode<int>* front=pendingnodes.front();
	    pendingnodes.pop();
	    cout<<front->data<<":";
	    for(int i=0;i<front->children.size();i++){
	          cout<<front->children[i]->data<<",";
	          pendingnodes.push(front->children[i]);
	    }
	    cout<<endl;
	}
}
TreeNode<int>* maxchildsum(TreeNode<int>* root){
	TreeNode<int>* ans=root;
	int sum=root->data;
	for(int i=0;i<root->children.size();i++){
		sum+=root->children[i]->data;
	}
	for(int i=0;i<root->children.size();i++){
       TreeNode<int>* sans=maxchildsum(root->children[i]);
       int ssum=sans->data;
       for(int i=0;i<sans->children.size();i++){
       	ssum+=sans->children[i]->data;
       }
       if(sum<ssum){
		sum=ssum;
		ans=sans;
	   }
	}
	return ans;
}
int main(){
	TreeNode<int>* root=takeinputlevelwise();
	printlevelwise(root);
	cout<<maxchildsum(root)->data<<endl;

}