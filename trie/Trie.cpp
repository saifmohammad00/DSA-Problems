#include<bits/stdc++.h>
using namespace std;
class TrieNode{
public:
     char data;
     TrieNode** children;
     bool isTerminal;
     TrieNode(char data){
     	this->data=data;
     	children=new TrieNode*[26];
        for(int i=0;i<26;i++){
     	children[i]=NULL;
        }
        isTerminal=false;
     }
};
class Trie{
	TrieNode *root;
public:
	Trie(){
		root=new TrieNode('\0');
	}
	void insertword(TrieNode* root, string word){
         if(word.size()==0){
         	root->isTerminal=true;
         }
         int index=word[0]-'a';
         TrieNode* child;
         if(root->children[index]!=NULL){
            child=root->children[index];
         }
         else{
            child=new TrieNode(word[0]);
            root->children[index]=child; 
         }
         insertword(child,word.substr(1));
	}
         void insertword(string word){
            insertword(root,word);
         }
         bool searchword(TrieNode* root,string word){
               if(root->children[word[0]-'a']==NULL)
                  return false;
               if(word.size()==1){
                  return root->children[word[0]-'a']->isTerminal;
               }
               return searchword(root->children[word[0]-'a'],word.substr(1));
         }
         bool searchword(string word){
            return searchword(root,word);
         }
         void removeword(TrieNode* root,string word){
             if(word.size()==0){
             root->isTerminal=false;
             return;
            }
            TrieNode* child;
            int index=word[0]-'a';
            if(root->children[index]!=NULL){
               child=root->children[index];
            }
            else{
               return;
            }
            removeword(child,word.substr(1));
            if(child->isTerminal==false){
               for(int i=0;i<26;i++){
                  if(child->children[i]!=NULL){
                     return;
                  }
               }
               delete child;
               root->children[index]=NULL;
            }
         }
         void removeword(string word){
            removeword(root, word);
         }
};
int main(){
       
}