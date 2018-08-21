/*
    Stack is LIFO (last In First Out)
*/

#include <iostream>

using namespace std;

struct NODE {
    int data;
    NODE *next;
};

class stack_linked_list {
    NODE *head; int top;
    public:
    stack_linked_list();
    void push(int);                         // insert an element in the stack
    void pop();                             // remove an element from the stack
    int peek();                             // returns the last element without any modification to stack
    int size();                             // return the size of stack
    bool isEmpty();                         // check if stack is empty
    void display();                         // print the whole stack
};

int main (void) {
    stack_linked_list sll;
    sll.push(5); sll.display();
    sll.push(10); sll.display();
    sll.push(15); sll.display();
    sll.push(20); sll.display();
    sll.pop(); sll.display();
    sll.pop(); sll.display();
    sll.pop(); sll.display();
    cout << sll.peek() << endl;
    sll.pop(); sll.display();
    cout << sll.peek() << endl;
    return 0;
}

stack_linked_list::stack_linked_list() {
    this->head = NULL;
    this->top  = -1;
}

void stack_linked_list::push(int data) {
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

void stack_linked_list::pop() {
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

int stack_linked_list::peek() {
    if (isEmpty()) {
        printf("Empty linked list!!!\nNothing to peek here.");
        return 0;
    } else {
        NODE *h = head;
        if (top == 0) return head->data;
        while (h != NULL) h = h->next;
        return h->data;
    }
}

int stack_linked_list::size() {
    return top+1;
}

bool stack_linked_list::isEmpty() {
    return top == -1;
}

void stack_linked_list::display() {
    if (isEmpty()) printf("Empty Stack!!!\n");
    else {
        NODE *h = head;
        while (h != NULL) {
            printf("%d ", h->data);
            h = h->next;
        }
        cout << endl;
    }
}
