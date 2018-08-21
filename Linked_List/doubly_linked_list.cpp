#include <iostream>

using namespace std;

struct NODE {
    int data;
    NODE *prev;
    NODE *next;
};

class doubly_linked_list {
    NODE *head; int top;
    public:
    doubly_linked_list();                               // create an empty doubly linked list
    void push(int);                                     // push a node at the end of the doubly linked list
    void push_beg(int);                                 // push a node at the start of the doubly linked list
    void push_pos(int, int);                            // push a node at the given position
    void pop();                                         // pop a node from the end of the doubly linked list
    void pop_beg();                                     // pop a node from the start of the doubly linked list
    void pop_pos(int);                                  // pop a node at the given position
    int size();                                         // return the total nodes in the linked list
    bool isEmpty();                                     // check if the doubly linked list is empty
    void display();                                     // display all the elements of the linked list
};

int main (void) {
    doubly_linked_list dll;
    dll.display();
    dll.push(5); dll.display();
    dll.push(10); dll.display();
    dll.push(15); dll.display();
    dll.push_beg(5); dll.display();
    dll.push_beg(10); dll.display();
    dll.push_beg(15); dll.display();
    dll.pop(); dll.display();
    dll.pop(); dll.display();
    dll.pop(); dll.display();
    dll.pop(); dll.display();
    dll.pop(); dll.display();
    dll.pop(); dll.display();
    dll.pop(); dll.display();
    dll.push_beg(5); dll.display();
    dll.push_beg(10); dll.display();
    dll.push(5); dll.display();
    dll.push(10); dll.display();
    dll.pop_beg(); dll.display();
    dll.pop_beg(); dll.display();
    dll.pop_beg(); dll.display();
    dll.pop_beg(); dll.display();
    dll.push_beg(5); dll.display();
    dll.push_beg(10); dll.display();
    dll.push(1); dll.display();
    dll.push_pos(2,50); dll.display();
    dll.pop_pos(2); dll.display();
    dll.pop_pos(3); dll.display();
    return 0;
}

doubly_linked_list::doubly_linked_list() {
    this->head->prev = NULL;
    this->head->next = NULL;
    this->top  = -1;
}

void doubly_linked_list::push(int data) {
    NODE *temp = new NODE;
    temp->data = data; temp->next = NULL;
    if(isEmpty()) {
        temp->prev = NULL;
        head = temp;
    } else {
        NODE *h = head;
        while(h->next != NULL) h = h->next;
        temp->prev = h;
        h->next = temp;
    }
    ++top;
}

void doubly_linked_list::push_beg(int data) {
    NODE *temp = new NODE;
    temp->data = data; temp->next = NULL;
    if(isEmpty()) {
        temp->prev = NULL;
        head = temp;
    } else {
        temp->prev = NULL;
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    ++top;
}

void doubly_linked_list::push_pos(int pos, int data) {
    if(pos<=1) {
        cout << "Inserting at the start of the linked list because either the position entered is negative or the list is empty\n";
        push_beg(data);
    } else if (pos>size()) {
        cout << "Inserting at the end of the linked list because the position entered is larger than the size of the list\n";
        push(data);
    } else {
        NODE *temp = new NODE; NODE *h = head;
        temp->data = data;
        while(--pos) {
            h = h->next;
        }
        temp->next = h; temp->prev = h->prev;
        // cout << "temp: " << temp->prev->data << " " << temp->next->data << endl;
        // cout << "h: " << h->prev->data << h->prev->next->data << endl;
        h->prev->next = temp;
        // cout << "h: " << h->prev->data;
        h->prev = temp;
        // cout << "h: " << h->prev->data;
        ++top;
    }
}

void doubly_linked_list::pop() {
    if(isEmpty()) printf("Nothing to pop here!!!, its a empty dll\n");
    else {
        if (top == 0) {
            head->next = NULL;
        } else {
            NODE *h = head;
            while(h->next != NULL) h = h->next;
            h->prev->next = NULL;
            delete h;
        }
        --top;
    }
}

void doubly_linked_list::pop_beg() {
    if(isEmpty()) printf("Nothing to pop here!!!, its a empty dll\n");
    else {
        if(top==0) {
            delete head;
        } else {
            NODE *temp = head->next;
            temp->prev = NULL;
            head = temp;
        }
        --top;
    }
}

void doubly_linked_list::pop_pos(int pos) {
    if(pos<=1) {
        cout << "Popping node from the start because either the position entered is negative or the list is empty\n";
        pop_beg();
    } else if (pos>=size()) {
        cout << "Popping node from the end of the linked list because the position entered is larger than or equal to the size of the list\n";
        pop();
    } else {
        NODE *h = head;
        while(--pos) {
            h = h->next;
        }
        h->prev->next = h->next;
        h->next->prev = h->prev;
        delete h;
        --top;
    }
}

int doubly_linked_list::size() {
    return top+1;
}

bool doubly_linked_list::isEmpty() {
    return top == -1;
}

void doubly_linked_list::display() {
    if(isEmpty()) printf("Empty doubly linked list\n");
    else {
        NODE *h = head;
        while (h != NULL) {
            printf("%d ", h->data);
            h = h->next;
        }
        cout << endl;
    }
}
