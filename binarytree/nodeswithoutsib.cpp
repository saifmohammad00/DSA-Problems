#include<bits/stdc++.h>
using namespace std;
template <typename T>
class binaryTreeNode{
public:
	int data;
	binaryTreeNode<int>* left;
	binaryTreeNode<int>* right;
	binaryTreeNode(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
binaryTreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
	}
	binaryTreeNode<int>* root=new binaryTreeNode<int>(rootdata);
	queue<binaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()){
		binaryTreeNode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1){
			binaryTreeNode<int>* child=new binaryTreeNode<int>(leftchild);
			front->left=child;
	        pendingnodes.push(child);
	    }
	    int rightchild;
		cin>>rightchild;
		if(rightchild!=-1){
			binaryTreeNode<int>* child=new binaryTreeNode<int>(rightchild);
			front->right=child;
	        pendingnodes.push(child);
		}
	}
	return root;
}
void printTree(binaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	if(root->left){
		if(root->right==NULL){
			cout<<root->left->data<<" ";
		}
	}
	if(root->right){
		if(root->left==NULL){
			cout<<root->right->data<<" ";
		}
		
	}
	printTree(root->left);
	printTree(root->right);

}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTree(root);
}	