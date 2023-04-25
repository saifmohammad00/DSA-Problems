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
void printkdistancedown(binaryTreeNode<int>* root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<endl;
		return;
	}
	printkdistancedown(root->left,k-1);
	printkdistancedown(root->right,k-1);

}
int printkdistance(binaryTreeNode<int>* root,int k,int target){
	if(root==NULL){
		return -1;
	}
	if(root->data==target){
		printkdistancedown(root,k);
		return 0;
	}
	int l=printkdistance(root->left,k,target);
	if(l!=-1){
		if(l+1==k){
			cout<<root->data<<endl;
		}
		else{
			printkdistancedown(root->right,k-l-2);
		}
		return l+1;

	}
	int r=printkdistance(root->right,k,target);
	if(r!=-1){
		if(r+1==k){
			cout<<root->data<<endl;
		}
		else{
			printkdistancedown(root->left,k-r-2);
		}
		return r+l;

	}
	return -1;
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	printkdistance(root,3,3);
}