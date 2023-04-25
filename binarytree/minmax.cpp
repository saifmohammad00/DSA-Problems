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
class pairans{
public:
	int minn;
	int maxx;
	pairans(){
		minn=INT_MAX;
		maxx=INT_MIN;
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
binaryTreeNode<int>* takeinput(){
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
	}
	binaryTreeNode<int>* root=new binaryTreeNode<int>(rootdata);
	binaryTreeNode<int>* leftchild=takeinput();
	binaryTreeNode<int>* rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}
void print(binaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left){
		cout<<root->left->data<<",";
	}
	if(root->right){
		cout<<root->right->data<<",";
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
void findsol(binaryTreeNode<int>* root,int& minum,int& maxum){
	if(root==NULL){
		return;
	}
    minum=min(minum,root->data);
    maxum=max(maxum,root->data);
    findsol(root->left,minum,maxum);
    findsol(root->right,minum,maxum);
}
pairans minmax(binaryTreeNode<int>* root){
	int min=INT_MAX;
	int max=INT_MIN;
	findsol(root,min,max);
	pairans s;
	s.minn=min;
	s.maxx=max;
	return s;
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	pairans p=minmax(root);
	cout<<p.minn<<" "<<p.maxx;
}