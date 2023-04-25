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
class Node{
	public:
	int value;
	Node*next;
	Node(int value){
		this->value=value;
		this->next=NULL;
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
void printlist(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
vector<Node*> levellinkedlist(binaryTreeNode<int>* root){
     queue<binaryTreeNode<int>*> p;
     p.push(root);
     vector<Node*> v;
       while(p.size()){
       	       int l=p.size();
       	       Node* head=NULL;
       	       Node* tail=NULL;
                while(l--){
                	binaryTreeNode<int>* front=p.front();
                	p.pop();
                	Node* s=new Node(front->data);
                	if(head==NULL){
                   		head=s;
                		tail=s;

                	}
                	else{
                		tail->next=s;
                		tail=tail->next;
                	}
                      if(front->left){
                	      p.push(front->left);
                      }
                      if(front->right){
                          p.push(front->right);
                      }
           }
           v.push_back(head);
     }        
     	return v;
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	vector<Node*> s=levellinkedlist(root);
	for(int i=0;i<s.size();i++){
		printlist(s[i]);
	}
}