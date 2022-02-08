#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    struct TrieNode *children[26];
    bool flag=false;

    bool containsKey(char ch){
        return children[ch-'a']!=NULL;
    }
    void put(char ch, TrieNode *node){
        children[ch-'a']=node;
    }

    TrieNode* get(char ch){
        return children[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
    struct TrieNode *root;
    public:
    Trie(){
        root=new TrieNode();
    }

    void insert(string word){
        struct TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word){
        struct TrieNode *node=root;
        bool flag=true;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                flag = flag && node->isEnd(); 
            }
        }
        return flag;
    }

};
string completeString(int n, vector<string> &a){
    Trie *trie = new Trie();
    for(auto word : a){
        trie->insert(word);
    }

    string longest="";
    for(auto word : a){
        if(trie->checkIfPrefixExists(word)){
            if(word.size()>longest.size()){
                longest=word;
            }
            else if(word.size()==longest.size() && word<longest){
                longest=word;
            }
        }
    }
    if(longest.length()==0){
        longest="None";
    }
    return longest;
}

int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<completeString(n,a);
    return 0;
}