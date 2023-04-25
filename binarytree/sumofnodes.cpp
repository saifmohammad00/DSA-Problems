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
int sumofnodes(binaryTreeNode<int>* root,int sum){
	if(root==NULL){
		return 0;
	}
	sum=sum+root->data;
	if(root->left){
          sum=sumofnodes(root->left,sum);
	}
	if(root->right){
        sum=sumofnodes(root->right,sum);
	}
	return sum;
	
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	cout<<sumofnodes(root,0)<<endl;
}