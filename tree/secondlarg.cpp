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
TreeNode<int>* seconlarg(TreeNode<int>* root,TreeNode<int>** larg,TreeNode<int>** seco){
    if(*larg==NULL){
        *larg=root;
    }
    else if(*seco==NULL && root->data<(*larg)->data){
        *seco=root;
    }
    else if(root->data>(*larg)->data){
        *seco=*larg;
        *larg=root;
    }
    else if(root->data<(*larg)->data && root->data>(*seco)->data){
        *seco=root;
    }
    for(int i=0;i<root->children.size();i++){
        seconlarg(root->children[i],larg,seco);
    }
}
int main(){
    TreeNode<int>* root=takeinputlevelwise();
    printlevelwise(root);
    TreeNode<int>* larg=NULL;
    TreeNode<int>* seco=NULL;
    seconlarg(root,&larg,&seco);
    cout<<seco->data<<endl;
}