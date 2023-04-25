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
void printTree(binaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left){
		cout<<"L"<<root->left->data<<",";
	}
	if(root->right){
		cout<<"R"<<root->right->data<<",";
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);

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
int countnodes(binaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	return 1+countnodes(root->left)+countnodes(root->right);
}
bool findx(binaryTreeNode<int>* root,int k){
	if(root->data==k){
		return true;
	}
	if(root->left){
		 bool s=findx(root->left,k);
		 if(s)
		 return true;
	}
	// cout<<"hello"<<endl;
	if(root->right){
		bool a=findx(root->right,k);
		if(a)
		return true;
	}
	return false;
}
int height(binaryTreeNode<int>* root){
	int h=0;
	if(root==NULL){
		return h;
	}
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}
void preorder(binaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(binaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main(){
     binaryTreeNode<int>* root=takeinput();
	 // binaryTreeNode<int>* root=takeinputlevelwise();
	 // printTreelevelwise(root);
	 // mirror code question incomplete
	 // mirror(root);
	 // preorder(root);
	 postorder(root);
	 cout<<endl;
	 
     printTree(root);
     cout<<countnodes(root)<<endl;
     int s;
     cin>>s;
     if(findx(root,s))
     	cout<<"true"<<endl;
     else
     	cout<<"false"<<endl;
     cout<<height(root)<<endl;
     

     delete root;
}
