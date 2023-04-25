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
void zigzagprint(binaryTreeNode<int>* root){
	stack<binaryTreeNode<int>*> s1;
	stack<binaryTreeNode<int>*> s2;
	s1.push(root);
	while(s1.size() || s2.size()){
          while(s1.size()){
          	binaryTreeNode<int>* front=s1.top();
          	s1.pop();
          	cout<<front->data<<" ";
          	if(front->left){
          		s2.push(front->left);
          	}
          	if(front->right){
          		s2.push(front->right);
          	}
          }
          cout<<endl;
          while(s2.size()){
          	binaryTreeNode<int>* front=s2.top();
          	s2.pop();
          	cout<<front->data<<" ";
          	if(front->right){
          		s1.push(front->right);
          	}
          	if(front->left){
          		s1.push(front->left);
          	}
          }
          cout<<endl;
}
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	zigzagprint(root);
}