#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *children[26];
    int countEndWith=0;
    int countPrefix=0;

    bool containsKey(char ch){
        return(children[ch-'a']!=NULL);
    }

    void put(char ch, TrieNode *node){
        children[ch-'a']=node;
    }

    TrieNode* get(char ch){
        return children[ch-'a'];
    }

    int getEnd(){
        return countEndWith;
    }

    int getPrefix(){
        return countPrefix;
    }

    void increaseEnd(){
        countEndWith++;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void reducePrefix(){
        countPrefix--;
    }

    void reduceEnd(){
        countEndWith--;
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
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        struct TrieNode *node=root;

        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            else{
                node=node->get(word[i]);
            }
        }
        return node->getEnd();
    }

    int countWordsStartWith(string word){
        struct TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            else{
                node=node->get(word[i]);
            }
        }
        return node->getPrefix();
    }

    void erase(string word){
        struct TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->reduce1End();
    }

};

int main()
{
    int i;
    string word;
    Trie* t = new Trie();
    while(true){
        cout<<"Trie Implementation\n1. Insert\n2. Count Words\n3. Count Prefix\n4. Erase\n5. End\n";
        cin>>i;
        switch(i){
            case 1: cin>>word;
                    t->insert(word);
                    break;
            case 2: cin>> word;
                    cout<<t->countWordsEqualTo(word)<<endl;
                    break;
            case 3: cin>> word;
                    cout<<t->countWordsStartWith(word)<<endl;
                    break;
            case 4: cin>> word;
                    t->erase(word);
                    break;
            case 5: exit(0);
            default:cout<<"Incorrect Input";
        }
    }
}