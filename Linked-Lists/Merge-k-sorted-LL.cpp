#include<bits/stdc++.h>
using namespace std;

ListNode* mergeKLL(vector<ListNode*>& lists){
    if(lists.empty()) return NULL;
    while(lists.size()>1){
        lists.push_back(merge2LL(lists[0],lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    lists.front();
}

ListNode* merge2LL(ListNode *l1, ListNode *l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    
    if(l1->val<=l2->val){
        l1->next=merge2LL(l1->next, l2);
        return l1;
    }
    else{
        l2->next=merge2LL(l1, l2->next);
        return l2;
    }
}