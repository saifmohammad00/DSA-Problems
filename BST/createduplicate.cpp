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
binaryTreeNode<int>* createinsertdupli(binaryTreeNode<int>* root){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL){
		binaryTreeNode<int>* node=new binaryTreeNode<int>(root->data);
		root->left=node;
		createinsertdupli(root->right);
		return root;

	}
	if(root->left){
        createinsertdupli(root->left);
	}
	if(root->right){
		createinsertdupli(root->right);
	}
	binaryTreeNode<int>* node=root->left;
	binaryTreeNode<int>* newnode=new binaryTreeNode<int>(root->data);
	root->left=newnode;
	newnode->left=node;
	return root;
}
void printeachlevel(binaryTreeNode<int>* node){
	queue<binaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(node);
	while(pendingnodes.size()){
		int t=pendingnodes.size();
		while(t){
			binaryTreeNode<int>* newnode=pendingnodes.front();
			pendingnodes.pop();
			cout<<newnode->data<<" ";
			if(newnode->left){
				pendingnodes.push(newnode->left);
			}
			if(newnode->right){
				pendingnodes.push(newnode->right);
			}
			t--;
		}
		cout<<endl;
	}
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	createinsertdupli(root);
	printeachlevel(root);
}