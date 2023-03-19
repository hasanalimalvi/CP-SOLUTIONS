#include<bits/stdc++.h> 
using namespace std;
class TrieNode{ 

public:
TrieNode* children[26]; 
bool isWord; 
TrieNode(){ 
  isWord = false; 
  for(int i=0;i<26;i++){
      children[i] = NULL;
  }
}

};

class WordDictionary {
public: 
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root; 
        for(int i=0;i<word.size();i++){
          if(curr->children[word[i]-'a']==NULL){
            curr->children[word[i]-'a'] = new TrieNode();
          } 

          curr = curr -> children[word[i]-'a'];
        } 

        curr -> isWord = true;
    }
    
    bool search(string word) {  

        

        

        return recursive(root,word,0);
        
        }  

    bool recursive(TrieNode* node, string word, int index){
        if(index==word.size()){
            return node->isWord;
        } 

        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i] != NULL && recursive(node->children[i],word,index+1)){
                    return true;
                } 

            }

            return false;
        } 

        else{

            if(node->children[word[index]-'a']==NULL){
                return false;
            } 

         
        } 

        TrieNode* child = node->children[word[index]-'a'];
        return recursive(child, word, index + 1);
    }

     
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */