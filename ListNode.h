#ifndef SDIZO1_LISTNODE_H
#define SDIZO1_LISTNODE_H


class ListNode {

public:
    int val;
    ListNode *prev;
    ListNode *next;

    ListNode(int val, ListNode *prev, ListNode *next);
};


#endif //SDIZO1_LISTNODE_H
