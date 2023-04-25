#include<bits/stdc++.h>
#include<vector>
#include<queue>
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
TreeNode<int>* takeinput(){
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	   TreeNode<int>* child=takeinput();
	   root->children.push_back(child);
	}
	return root;

}
void printTreelevel(TreeNode<int>* root){
    if(root==NULL){
    return;
    }
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++){
	    cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printTreelevel(root->children[i]);
	}
}
int countnodes(TreeNode<int>* root){
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans=ans+countnodes(root->children[i]);
	}
	return ans;
}
int main(){
	TreeNode<int>* root=takeinput();
	printTreelevel(root);
	cout<<countnodes(root)<<endl;
}