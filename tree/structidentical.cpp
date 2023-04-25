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
	while(!pendingnodes.empty()){
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
void printlevelwise(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
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
bool isidentical(TreeNode<int>* root1,TreeNode<int>* root2){
	if(root1->data!=root2->data){
		return false;
	}
	if(root1->children.size()!=root2->children.size()){
		return false;
	}
	bool ans=true;
	for(int i=0;i<root1->children.size();i++){
		bool smallans=isidentical(root1->children[i],root2->children[i]);
		if(smallans==false){
			ans=smallans;
			return ans;
		}
	}
	return ans;
}
int main(){
	TreeNode<int>* root1=takeinputlevelwise();
	printlevelwise(root1);
	TreeNode<int>* root2=takeinputlevelwise();
	printlevelwise(root2);
	if(isidentical(root1,root2)){
		cout<<"True"<<endl;
	}
	else{
		cout<<"False"<<endl;
	}
}