#include<bits/stdc++.h>
using namespace std;
template <typename T>
class binaryTreeNode{
public:
	int data;
	binaryTreeNode<T>* left;
	binaryTreeNode<T>* right;
	binaryTreeNode(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
binaryTreeNode<int>* helper(int* pre,int* in,int preS,int preE,int inS,int inE){
	if(inS>inE){
		return NULL;
	}
	int rootdata=pre[preS];
	int rootindex=-1;
	for(int i=inS;i<=inE;i++){
		if(in[i]==rootdata){
			rootindex=i;
			break;
		}
	}
	int linS=inS;
	int linE=rootindex-1;
	int rinS=rootindex+1;
	int rinE=inE;
	int lpreS=preS+1;
	int lpreE=linE-linS+lpreS;
	int rpreS=lpreE+1;
	int rpreE=preE;
	binaryTreeNode<int>* root=new binaryTreeNode<int>(rootdata);
	root->left=helper(pre,in,lpreS,lpreE,linS,linE);
	root->right=helper(pre,in,rpreS,rpreE,rinS,rinE);
	return root;
}
binaryTreeNode<int>* buildtree(int* pre,int* in,int size){
	return helper(pre,in,0,size-1,0,size-1);
}
binaryTreeNode<int>* newhelper(int* post,int* in,int postS,int postE,int inS,int inE){
	if(postS>postE || inS>inE){
		return NULL;
	}
	binaryTreeNode<int>* root=new binaryTreeNode<int>(post[postE]);
	int rootindex=-1;
	for(int i=inS;i<=inE;i++){
	if(in[i]==post[postE]){
			rootindex=i;
			break;
		}
	}
	int linS=inS;
	int linE=rootindex-1;
	int rinS=rootindex+1;
	int rinE=inE;
	int lpostS=postS;
	int lpostE=linE-linS+lpostS;
	int rpostS=lpostE+1;
	int rpostE=postE-1;
	root->left=helper(post,in,lpostS,lpostE,linS,linE);
	root->right=helper(post,in,rpostS,rpostE,rinS,rinE);
	return root;
}
binaryTreeNode<int>* newbuildtree(int* post,int* in,int size){
	return newhelper(post,in,0,size-1,0,size-1);
}

void print(binaryTreeNode<int>* root){
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
	print(root->left);
	print(root->right);
}
int main(){
	int inorder[]={4,2,5,1,6,3,7};
	int postorder[]={4,5,2,6,7,3,1};
	binaryTreeNode<int>* newroot=newbuildtree(postorder,inorder,7);
	print(newroot);
}