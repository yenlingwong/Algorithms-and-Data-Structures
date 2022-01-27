/*
CH-231-A
a8_p2b.cpps
Yen Ling Wong
ywong@jacobs-university.de
Convert a Binary Search Tree into a Sorted Linked List
*/

#include <iostream>

using namespace std;

// Reference: https://www.youtube.com/watch?v=0E8Xxu6LV9o

struct tree_node {
    int data;
    struct tree_node* parent;
    struct tree_node* left;
    struct tree_node* right;
    struct tree_node* next;
};

class create_linked_list {
    private:
        struct tree_node* front;
        struct tree_node* root;
    public:
        create_linked_list(struct tree_node* node);
        void BST_to_List();
        struct tree_node* in_order_successor(struct tree_node* node);
        struct tree_node* minimum(struct tree_node* node);
        void display();
        void insert_node(struct tree_node* node);
};

struct tree_node* create_linked_list::minimum(struct tree_node* node)  {
    struct tree_node* current = node;
    while (current->left != NULL) {
        current = current -> left;
    }
    return current;
}

// Reference: Course Slides (Successor Function)
struct tree_node* create_linked_list::in_order_successor(struct tree_node* node) {
    if (node->right != NULL) {
        return minimum(node->right);
    }
    struct tree_node* y = node->parent;
    while (y != NULL && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}

// Method to insert a node into the linked list
void create_linked_list::insert_node(struct tree_node* node) {
    struct tree_node* new_node = new struct tree_node;
    struct tree_node* cursor_node = this->front;
    new_node->data = node->data;
    new_node->next = NULL;

    if (this->front == NULL) {
        this->front = new_node;
        cout << new_node -> data << " has been added to the linked list." << endl;
    } else {
        while (cursor_node->next != NULL) {
            cursor_node = cursor_node -> next;
        }
        cursor_node->next = new_node;
        cout << new_node -> data << " has been added to the linked list." << endl;
    }
}

// Method to print the list by iterating through it
void create_linked_list::display() {
    cout << "Print the Linked List: " << endl;
    struct tree_node* cursor_node = this->front;
    while (cursor_node != NULL) {
        cout << cursor_node->data << " -> ";
        cursor_node = cursor_node->next;
    }
    cout << "NULL" << std::endl;
}

// Constructor to initialize root
create_linked_list::create_linked_list(struct tree_node* root) {
    cout << "A Linked List has been created." << endl;
    this->root = root;
}

// Function to convert binary search tree into linked list
void create_linked_list::BST_to_List() {
    
    this->front = this->minimum(root);
    cout << this->front->data << " has been added to the linked list." << endl;
    // Setting the minimum at the front of the list
    
    struct tree_node* cursor = this->front;
    while (in_order_successor(cursor) != NULL) {
        struct tree_node* temp = in_order_successor(cursor); 
    // Returning successor of current node (cursor)

        this->insert_node(temp);
    // And inserting the node into the linked list
        cursor = temp;
    }  
}


int main() {
    // Visualization of a Binary Search Tree
    /*
                          6
                      /      \
                  4            7
              /       \          \
            2           5          8
        /       \
      1           3
    */
    struct tree_node* six = new struct tree_node;
    struct tree_node* four = new struct tree_node;
    struct tree_node* two = new struct tree_node;
    struct tree_node* five = new struct tree_node;
    struct tree_node* seven = new struct tree_node;
    struct tree_node* eight = new struct tree_node;
    struct tree_node* one = new struct tree_node;
    struct tree_node* three = new struct tree_node;

    six->data = 6;
    four->data = 4;
    two->data = 2;
    five->data = 5;
    seven->data = 7;
    eight->data = 8;
    one->data = 1;
    three->data = 3;

    six->left = four;
    six->right = seven;
    six->left->left = two;
    six->left->left->left = one;
    six->left->right = five;
    six->right->right = eight;
    six->left->left->right = three;

    four->parent = six;
    two->parent = four;
    five->parent = four;
    seven->parent = six;
    eight->parent = seven;
    one->parent = two;
    three->parent = two;

    // Initialization of BST nodes and establishing parent-child relations where the root has the value 6

    create_linked_list c(six);
    
    // Creating a linked list object and passing its root value

    c.BST_to_List();
    // Method to convert BST to linked list

    c.display();
    // Printing the list
    
    return 0;
}
