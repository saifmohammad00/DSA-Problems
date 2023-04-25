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
class Node{
public:
	int value;
	Node* next;
	Node(int value){
		this->value=value;
		next=NULL;
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
void print(Node* head){
	Node* temp=head;
	while(temp){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
pair<Node*,Node*> constructbstLL(binaryTreeNode<int>* root){
	if(root==NULL){
		pair<Node*,Node*> s;
		return s;
	}
    Node* s=new Node(root->data);
	pair<Node*,Node*> l=constructbstLL(root->left);
	pair<Node*,Node*> r=constructbstLL(root->right);
	pair<Node*,Node*> ans;
	if(!l.first && !r.first){
		ans.first=s;
		ans.second=s;
	}
	else if(r.first && !l.first){
		ans.first=s;
		s->next=r.first;
		ans.second=r.first;
	}
	else if(l.first && !r.first){
		ans.first=l.first;
		l.second->next=s;
		ans.second=s;
	}
	else{
		ans.first=l.first;
		l.second->next=s;
		s->next=r.first;
		ans.second=r.second;
	}
	return ans;
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	// pair<Node*,Node*> ht=
	pair<Node*,Node*> head=constructbstLL(root);
	print(head.first);
	delete root;
}