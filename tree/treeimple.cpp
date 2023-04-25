#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode{
public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data){
       this->data=data;
    }
};
TreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		TreeNode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int childdata;
			cin>>childdata;
           TreeNode<int>* child=new TreeNode<int>(childdata);
           front->children.push_back(child);
           pendingnodes.push(child);
		}
	}
	return root;
}
TreeNode<int>* takeinput(){
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	TreeNode<int>* child=takeinput();
        root->children.push_back(child);
    }
    return root;
}
void printTreelevel(TreeNode<int>* root){
     queue<TreeNode<int>*> pendingnodes;
     pendingnodes.push(root);
     while(pendingnodes.size()!=0){
     	TreeNode<int>* front=pendingnodes.front();
     	pendingnodes.pop();
     	cout<<front->data<<":";
     	for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
      		pendingnodes.push(front->children[i]);
     	}
     	cout<<endl;
     }
}
void print(TreeNode<int>* root){
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++){
          cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
       print(root->children[i]);
	}
}
int countnodes(TreeNode<int>* root){
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans=ans+countnodes(root->children[i]);
	}
	return ans;
}
int sumofnodes(TreeNode<int>* root){
	int sum=root->data;
	for(int i=0;i<root->children.size();i++){
		sum=sum+sumofnodes(root->children[i]);
	}
	return sum;
}
int largestnode(TreeNode<int>* root){
	int max=root->data;
	for(int i=0;i<root->children.size();i++){
		if(max<root->children[i]->data){
			max=root->children[i]->data;
		}
		largestnode(root->children[i]);
	}
	return max;
}
int heighttree(TreeNode<int>* root){
	int max=0;
	for(int i=0;i<root->children.size();i++){
		int height=heighttree(root->children[i]);
		if(height>max){
			max=height;
		}
	}
	return max+1;
}
void depth(TreeNode<int>* root,int k){
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	for(int i=0;i<root->children.size();i++){
		depth(root->children[i],k-1);
	}
	cout<<endl;
}
int leafnodes(TreeNode<int>* root,int count){
	if(root==NULL){
		return 0;
	}
	if(root->children.size()==0){
		return 1;
	}
	for(int i=0;i<root->children.size();i++){
	    count=count+leafnodes(root->children[i],count);
	}
	return count;
}
bool findx(TreeNode<int>* root,int x){
	if(x==root->data){
       return true;
    }
    bool ans=false;
     for(int i=0;i<root->children.size();i++){
     		bool l=findx(root->children[i],x);
     		if(ans!=l && l==true){
     			ans=l;
     		}
     	}
     return ans;
}
int countgreater(TreeNode<int>* root,int x){
	int ans=0;
	if(x<root->data){
		ans=ans+1;
	}
	for(int i=0;i<root->children.size();i++){
         ans=ans+countgreater(root->children[i],x);
	}
	return ans;
}
int maxnodefam(TreeNode<int>* root){
	int sum=0;
	sum=sum+root->data;
	for(int i=0;i<root->children.size();i++){
		

	}
	return sum;
}
int main(){
	// TreeNode<int>* root=takeinput();
	TreeNode<int>* root=takeinputlevelwise();
	// print(root);
	printTreelevel(root);
	cout<<countnodes(root)<<endl;
	cout<<sumofnodes(root)<<endl;
	cout<<largestnode(root)<<endl;
	cout<<heighttree(root)<<endl;
	depth(root,1);
	cout<<leafnodes(root,0)<<endl;
	cout<<findx(root,40)<<endl;
	cout<<countgreater(root,100)<<endl;
	cout<<maxnodefam(root)<<endl;
}