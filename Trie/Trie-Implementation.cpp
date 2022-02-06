#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
    TrieNode *children[26];
    bool flag=false;

    bool containsKey(char ch){
        return(children[ch-'a']!=NULL);
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
        struct TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        struct TrieNode *node=root;

        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        if(node->isEnd()){
            return true;
        }
        return false;
    }

    bool startsWith(string prefix){
        struct TrieNode *node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};


int main(){
    int i;
    string word;
    Trie* t = new Trie();
    while(true){
        cout<<"Trie Implementation\n1. Insert\n2. Search\n3. Search with Prefix\n4. End\n";
        cin>>i;
        switch(i){
            case 1: cin>>word;
                    t->insert(word);
                    break;
            case 2: cin>> word;
                    cout<<(t->search(word)==1 ? "true" : "false")<<endl;
                    break;
            case 3: cin>> word;
                    cout<<(t->startsWith(word)==1 ? "true" : "false")<<endl;
                    break;
            case 4: exit(0);
            default:cout<<"Incorrect Input";
        }
    }
    
    return 0;
}