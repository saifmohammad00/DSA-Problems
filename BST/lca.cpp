#include<bits/stdc++.h>
using namespace std;
template <typename T>
class binaryTreeNode{
public:
	T data;
	binaryTreeNode<T>* left;
	binaryTreeNode<T>* right;
	binaryTreeNode(T data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~binaryTreeNode(){
		delete left;
		delete right;
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
void printTreelevelwise(binaryTreeNode<int>* root){
	queue<binaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()){
		binaryTreeNode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		if(front->left!=NULL){
			cout<<"L"<<front->left->data<<",";
			pendingnodes.push(front->left);
		}
		if(front->right!=NULL){
			cout<<"R"<<front->right->data<<",";
			pendingnodes.push(front->right);
		}
		cout<<endl;

	}
}
int lca(binaryTreeNode<int>* root,int n1,int n2){
	if(root==NULL){
		return -1;
	}
	if(root->data==n1 || root->data==n2){
		return root->data;
	}
	int l=lca(root->left,n1,n2);
	int r=lca(root->right,n1,n2);
	if(l==-1 && r==-1){
		return -1;
	}
	else if(l==-1 && r!=-1){
            return r;
	}
	else if(l!=-1 && r==-1){
		return l;
	}
	else{
		return root->data;
	}
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	cout<<lca(root,12,78);
}