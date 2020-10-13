#include <iostream>
#include <vector>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        /* Convert Linked List to Vector */
        std::vector<Node*> list;
        Node* p = head;
        while (p != nullptr) {
            list.push_back(p);
            p = p->next;
        }
        
        /* Build a map<nodePtr, idx> */
        std::map<Node*, int> p2i;
        p2i[nullptr] = -1;
        for (int i=0; i<list.size(); i++) {
            p2i[list[i]] = i;
        }
        
        /* Build a copy of list (copy value first)*/
        std::vector<Node*> copyList(list.size(), nullptr);
        for (int i=0; i<list.size(); i++) {
            copyList[i] = new Node(list[i]->val);
        }
        
        /* Connect the nodes in copy list */
        for (int i=0; i<list.size(); i++) {
            if (i < list.size()-1)
                copyList[i]->next = copyList[i+1];
            int randIdx = p2i[list[i]->random];
            copyList[i]->random = (randIdx==-1)?nullptr:copyList[randIdx];
        }
        return copyList[0];
}
    
int main() {

}
