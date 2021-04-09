/*
CH-231-A
a8_p2c.cpp
Yen Ling Wong
ywong@jacobs-university.de
Convert a Sorted Linked List to Binary Search Tree
*/

#include <iostream>

using namespace std;

struct list_node {
    int data;
    struct list_node* next;
    struct list_node* left;
    struct list_node* right;
};

class create_binary_tree {
    private:
        struct list_node* front;
    public:
        struct list_node* root;
        create_binary_tree(struct list_node* front);
        struct list_node* middle(struct list_node* head);
        struct list_node* List_to_BST(struct list_node* head);
        void display(struct list_node* front);
        void pre_order_traversal(struct list_node* node);

};

create_binary_tree::create_binary_tree(struct list_node* front) {
    this->front = front;
}

struct list_node* create_binary_tree::List_to_BST(struct list_node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    struct list_node* fast = head;
    struct list_node* slow = head;
    struct list_node* mid = slow;

    while(fast != NULL && fast->next != NULL) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    struct list_node* node = slow;
    mid->next = NULL;
    node->left = List_to_BST(head);
    node->right = List_to_BST(slow->next);

    return node;
}

void create_binary_tree::display(struct list_node* front) {
    cout << "Print the Linked List: " << endl;
    struct list_node* cursor_node = this->front;
    while (cursor_node != NULL) {
        cout << cursor_node->data << " -> ";
        cursor_node = cursor_node->next;
    }
    cout << "NULL" << std::endl;
}

void create_binary_tree::pre_order_traversal(struct list_node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << "  " ;
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}
int main() {
    struct list_node* one = new struct list_node;
    struct list_node* two = new struct list_node;
    struct list_node* three = new struct list_node;
    struct list_node* four = new struct list_node;
    struct list_node* five = new struct list_node;
    struct list_node* six = new struct list_node;
    struct list_node* seven = new struct list_node;
    struct list_node* eight = new struct list_node;

    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;
    five->data = 5;
    six->data = 6;
    seven->data = 7;
    eight->data = 8;
    
    one->next=two;
    one->next->next = three;
    one->next->next->next = four;
    one->next->next->next->next= five;
    one->next->next->next->next->next = six;
    one->next->next->next->next->next->next = seven;
    one->next->next->next->next->next->next->next = eight;

    create_binary_tree c(one);
    c.display(one);
    cout << "Presenting binary tree in Pre-order Traversal: " << endl;
    struct list_node* root = c.List_to_BST(one);
    c.pre_order_traversal(root);
    cout << " " << endl;
    return 0;
}