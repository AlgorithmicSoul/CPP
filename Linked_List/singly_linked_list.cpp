#include <iostream>

using namespace std;

// Basic structure of a NODE
struct NODE {
    int data;
    NODE *next;
};

class singly_linked_list {
    NODE *head; int top;
    public:
    singly_linked_list ();                      // make an empty linked list
    void push(int);                             // push a value at the end of the linked list
    void push_beg(int);                         // push a value at the start of the linked list
    void push_pos(int, int);                    // push a value at the specified position
    void push_after(int, int);                  // push the node after the specified position
    void push_before(int, int);                 // push the node before the specified position
    void pop();                                 // delete a node at the end of the linked list
    void pop_beg();                             // delete a node at the start of the linked list
    void pop_pos(int);                          // delete a node at the specified position
    void pop_after(int);                        // pop the node after the specified position
    void pop_before(int);                       // pop the node before the specified position
    bool isEmpty();                             // check if linked list is empty
    int size();                                 // return total number of elements in the linked list
    void display();                             // print all the elements of the linked list
};

int main (void) {
    singly_linked_list sll;
    sll.push_beg(5); sll.display();
    sll.push(10); sll.display();
    sll.push_beg(15); sll.display();
    sll.pop(); sll.display();
    sll.pop_beg(); sll.display();
    sll.pop_beg(); sll.display();
    sll.push_pos(10, 58); sll.display();
    sll.push_pos(11, 25); sll.display();
    sll.push_pos(-11, 30); sll.display();
    sll.push_pos(0, 0); sll.display();
    sll.push_pos(1, 1); sll.display();
    sll.push_pos(2, 2); sll.display();
    sll.push_pos(3, 3); sll.display();
    sll.push_pos(4, 4); sll.display();
    sll.pop_pos(3); sll.display();
    sll.pop_pos(3); sll.display();
    sll.pop_pos(3); sll.display();
    sll.pop_pos(5); sll.display();
    sll.pop_pos(1); sll.display();
    return 0;
}

singly_linked_list::singly_linked_list() {
    this->head = NULL;
    this->top = -1;
}

void singly_linked_list::push(int data) {
    NODE *temp = new NODE;
    temp->data = data; temp->next = NULL;
    if (isEmpty()) {
        head = temp;
        ++top;
    } else {
        NODE *h = head;
        while (h->next != NULL) h = h->next;
        h->next = temp;
        ++top;
    }
}

void singly_linked_list::push_beg(int data) {
    NODE *temp = new NODE;
    temp->data = data;
    if (isEmpty()) {
        temp->next = NULL;
        head = temp;
        ++top;
    } else {
        temp->next = head;
        head = temp;
        ++top;
    }
}

void singly_linked_list::push_pos(int pos, int data) {
    if(isEmpty() || pos>top+1) {
        printf("Either the Linked list is empty or the position you asked is more than the total elements in the list, therefore inserting this value as the last node of the linked list!!!\n");
        push(data);
    } else if (pos <= 1) {
        printf("Value of position entered is either negative or zero therefore inserting at the start of the linked list!!!\n");
        push_beg(data);
    }
    else {
        NODE *temp = new NODE; NODE *prev = new NODE; NODE *next = head;
        temp->data = data;
        while(--pos) {
            prev = next;
            next = next->next;
        }
        // cout << prev->data << " " << next->data << endl;
        temp->next = next;
        prev->next = temp;
        ++top;
    }
}

void singly_linked_list::push_after(int pos, int data) {
    push_pos(pos+1, data);
}

void singly_linked_list::push_before(int pos, int data) {
    push_pos(pos-1, data);
}

void singly_linked_list::pop() {
    if (isEmpty()) {
        printf("Empty linked list!!!\nNothing to pop here.");
    } else {
        NODE *h = head; NODE *prev;
        if (top==0) head = NULL;
        else {
            while (h->next != NULL) {
            prev = h;
            h = h->next;
        }
        delete h;
        prev->next = NULL;
        }
        --top;
    }
}

void singly_linked_list::pop_beg() {
    if (isEmpty()) {
        printf("Empty linked list!!!\nNothing to pop here.");
    } else {
        NODE *temp = head;
        delete head;
        head = temp->next;
        --top;
    }
}

void singly_linked_list::pop_pos(int pos) {
    if (isEmpty()) cout << "Nothing to pop here as linked list is empty!!!" << endl;
    else if (pos>top+1) {
        cout << "asked position value larger than size of liked list hence removing the last node!!!" << endl;
        pop();
    }
    else if (pos <= 1) {
        printf("Value of position entered is either negative or zero therefore removing the first element of the linked list!!!\n");
        pop_beg();
    }
    else {
        NODE *prev = new NODE; NODE *next = head;
        while (--pos) {
            prev = next;
            next = next->next;
        }
        // cout << prev->data << " " << next->data << endl;
        prev->next = next->next;
        delete next;
        --top;
    }
}

void singly_linked_list::pop_after(int pos) {
    pop_pos(pos+1);
}

void singly_linked_list::pop_before(int pos) {
    pop_pos(pos-1);
}

bool singly_linked_list::isEmpty() {
    return top == -1;
}

int singly_linked_list::size() {
    return top+1;
}

void singly_linked_list::display() {
    if (isEmpty()) printf("Empty Linked List!!!\n");
    else {
        NODE *h = head;
        while (h != NULL) {
            printf("%d ", h->data);
            h = h->next;
        }
        cout << endl;
    }
}
