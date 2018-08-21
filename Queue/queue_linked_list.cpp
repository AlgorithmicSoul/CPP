/*
    Queue is FIFO (First In First Out)
*/

#include <iostream>

using namespace std;

struct NODE {
    int data;
    NODE *next;
};

class queue_linked_list {
    NODE *head; int top;
    public:
    queue_linked_list();              // initialize an empty queue
    void enqueue(int);                  // add a node to the queue
    void dequeue();                     // remove a node from the queue
    int front();                        // return the first node of the queue
    int size();                         // return total nodes in the queue
    bool isEmpty();                     // check if the queue is empty or not
    void display();                     // display all the nodes of the queue
};

int main(void) {
    queue_linked_list qll;
    qll.enqueue(5); qll.display();
    qll.enqueue(10); qll.display();
    qll.enqueue(15); qll.display();
    qll.enqueue(20); qll.display();
    qll.dequeue(); qll.display();
    qll.dequeue(); qll.display();
    qll.dequeue(); qll.display();
    qll.dequeue(); qll.display();
    qll.enqueue(20); qll.display();
    return 0;
}

queue_linked_list::queue_linked_list() {
    this->head = NULL;
    this->top  = -1;
}

void queue_linked_list::enqueue(int data) {
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

void queue_linked_list::dequeue() {
    if (isEmpty()) {
        printf("Empty Queue!!!, Nothing to pop here.\n");
    } else {
        NODE *temp = head;
        delete head;
        head = temp->next;
        --top;
    }
}

int queue_linked_list::front() {
    if(isEmpty()){
        printf("Empty Queue!!!. Nothing to show here.\n");
        return 0;
    }
    else {
        return head->data;
    }
}

int queue_linked_list::size() {
    return top+1;
}

bool queue_linked_list::isEmpty() {
    return top == -1;
}

void queue_linked_list::display() {
    if (isEmpty()) printf("Empty Queue!!!\n");
    else {
        NODE *h = head;
        while (h != NULL) {
            printf("%d ", h->data);
            h = h->next;
        }
        cout << endl;
    }
}
