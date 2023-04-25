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
vector<int> pairsum2(binaryTreeNode<int>* root,vector<int>& v){
	if(root==NULL){
		return v;
	}
     pairsum2(root->left,v);
     v.push_back(root->data);
     pairsum2(root->right,v);
     return v;

}
void pairsum(binaryTreeNode<int>* root,int k){
	vector<int> g;
	vector<int> v=pairsum2(root,g);
	sort(v.begin(),v.end());
	int s=0,e=v.size()-1;
	for(int i=0;s<e;i++){
		if(v[s]+v[e]==k){
			cout<<v[s]<<" "<<v[e];
			cout<<endl;
		    s++;
		    e--;
		}
		else if(v[s]+v[e]>k){
			e--;
		}
		else{
			s++;
		}
	}
}
int main(){
	binaryTreeNode<int>* root=takeinputlevelwise();
	printTreelevelwise(root);
	pairsum(root,15);

}