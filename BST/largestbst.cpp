#include<iostream>
#include<climits>
#include<cmath>
#include<queue>
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
class pairs{
public:
	int minimum;
	int maximum;
	bool bst;
	int height;
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
pairs largestbst(binaryTreeNode<int>* root){
           if(root==NULL){
           	pairs s;
           	s.minimum=INT_MAX;
           	s.maximum=INT_MIN;
           	s.bst=true;
           	s.height=0;
           	return s;
           }
           pairs l=largestbst(root->left);
           pairs r=largestbst(root->right);
           int minimum=min(root->data,min(l.minimum,r.minimum));
           int maximum=max(root->data,max(l.maximum,r.maximum));
           bool isbstfinal=(l.bst && r.bst && root->data<r.minimum && root->data>l.maximum);
           pairs obj;
           obj.minimum=minimum;
           obj.maximum=maximum;
           obj.bst=isbstfinal;
           if(isbstfinal){
              obj.height=1+max(l.height,r.height);
           }
           else{
               obj.height=max(l.height,r.height);
           }
           return obj;
       }
           
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	pairs s=largestbst(root);
	cout<<s.height;
}