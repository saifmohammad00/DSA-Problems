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
bool searchelement(binaryTreeNode<int>* root,int k){
	if(root==NULL){
		return false;
	}
	cout<<root->data<<endl;
	if(root->data==k){
		return true;
	}
	if(root->data>k){
		 return searchelement(root->left,k);
	}
	if(root->data<k){
		 return searchelement(root->right,k);
	}
}
void printrange(binaryTreeNode<int>* root,int k1,int k2){
	if(root==NULL){
		return;
	}
	if(root->data>k1){
           printrange(root->left,k1,k2);
	}
	if(root->data>=k1 && root->data<=k2 ){
		cout<<root->data<<" ";
	}
	if(root->data<k2){
          printrange(root->right,k1,k2);
	}
}
bool checkbst(binaryTreeNode<int>* root,int min=INT_MIN,int max=INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data>max || root->data<min){
		return false;
	}
	bool l=checkbst(root->left,min,root->data-1);
	bool r=checkbst(root->right,root->data,max);
	return l&&r;
}
int main(){
     binaryTreeNode<int>* root=takeinputlevelwise();
     printTreelevelwise(root);
     if(searchelement(root,5)){
     	cout<<"true"<<endl;
     }
     else{
     	cout<<"false"<<endl;
     }
     printrange(root,1,3);
     cout<<checkbst(root);
     delete root;
}