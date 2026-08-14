/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        // Pass 1: interweave clones
        Node* curr = head;
        while(curr != nullptr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Pass 2: assign random pointers
        curr = head;
        while(curr != nullptr) {
            if(curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Pass 3: unweave into two separate lists
        curr = head;
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;

        while(curr != nullptr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            copyCurr->next = copy;
            copyCurr = copy;
            curr = curr->next;
        }

        return dummy->next;
    }
};