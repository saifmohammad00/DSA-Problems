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
class BST{
	binaryTreeNode<int>* root;
public:
     BST(){
     	root=NULL;
     }
     ~BST(){
     	delete root;
     }
 private:
 	binaryTreeNode<int>* deletedata(int data,binaryTreeNode<int>* node){
 		if(node==NULL){
 			return NULL;
 		}
 		if(data<node->data){
 			node->left=deletedata(data,node->left);
 			return node;
 		}
 		else if(data>node->data){
 			node->right=deletedata(data,node->right);
 			return node;
 		}
 		else{
             if(!node->left && !node->right){
             	delete node;
             	return NULL;
             }
             else if(!node->left){
             	binaryTreeNode<int>* temp=node->right;
             	node->right=NULL;
             	delete node;
             	return temp;

             }
             else if(!node->right){
             	binaryTreeNode<int>* temp=node->left;
             	node->left=NULL;
             	delete node;
             	return temp;
             }
             else{
             	binaryTreeNode<int>* minnode=node->right;
             	while(minnode->left!=NULL){
             		minnode=minnode->left;
             	}
             	int rightmin=minnode->data;
             	node->data=rightmin;
             	node->right=deletedata(rightmin,node->right);
             	return node;
             }
 		}
 	}
 	void printTree(binaryTreeNode<int>* node){
         if(node==NULL){
         	return;
         }
         cout<<node->data<<":";
         if(node->left){
         	cout<<"L"<<root->left->data<<",";
         }
         if(node->right){
         	cout<<"R"<<root->right->data<<",";
         }
         cout<<endl;
         printTree(node->left);
         printTree(node->right);
 	}
 public:
 	void deletedata(int data){
          root=deletedata(data,root);
 	}
 	void printTree(){
 		printTree(root);

 	}
 private:
 	binaryTreeNode<int>* insert2(int data,binaryTreeNode<int>* node){
        if(node==NULL){
            binaryTreeNode<int>* newnode=new binaryTreeNode<int>(data);
        	return newnode;
        }

        if(node->data>data){
        	node->left=insert2(data,node->left);
        }
        if(root->data<node->data){
        	node->right=insert2(data,node->right);
        }
        return node;
 	}
 public:
 	void insert(int data){
 		this->root=insert2(data,this->root);
 	}
 private:
 	bool hasData2(int data,binaryTreeNode<int>* node){
 		if(node==NULL){
 			return false;
 		}
 		if(node->data==data){
 			return true;
 		}
 		if(node->data>data){
 			return hasData2(data,node->left);
 		}
 		if(node->data<data){
 			return hasData2(data,node->right);
 		}
 	}
 public:
 	bool hasData(int data,binaryTreeNode<int>* root){
 		return hasData2(data,root);
 	}
};
int main(){
}