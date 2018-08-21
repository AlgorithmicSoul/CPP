#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
};

class circular_queue_linked_list {
  Node *head, *tail; int top;
  public:
    circular_queue_linked_list();
    void enqueue(int);
    void dequeue();
    bool isEmpty();
    int size();
    void display();
};

int main (void) {
  circular_queue_linked_list cqll;
  cqll.enqueue(5); cqll.display();
  cqll.enqueue(5); cqll.display();
  cqll.enqueue(5); cqll.display();
  cqll.dequeue(); cqll.display();
  cqll.dequeue(); cqll.display();
  cqll.dequeue(); cqll.display();
  cqll.dequeue(); cqll.display();
  cqll.enqueue(5); cqll.display();
  cqll.enqueue(5); cqll.display();
  cqll.enqueue(5); cqll.display();
  return 0;
}

circular_queue_linked_list :: circular_queue_linked_list () {
  this->head = NULL;
  this->tail = NULL;
  this->top = -1;
}

void circular_queue_linked_list :: enqueue (int data) {
  Node *temp = new Node;
  temp->data = data;
  temp->prev = NULL;
  temp->next = temp;
  if (isEmpty()) {
    head = temp;
    tail = temp;
    ++top;
  } else {
    Node *h = head;
    while (h->next != head) h = h->next;
    temp->next = head; temp->prev = h;
    h->next = temp;
    tail = temp;
    ++top;
  }
}

void circular_queue_linked_list :: dequeue () {
  if (isEmpty()) {
    
  } else {
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    tail->next = head;
    delete(temp);
    --top;
  }
}

bool circular_queue_linked_list :: isEmpty() {
  return top == -1;
}

int circular_queue_linked_list :: size () {
  return top+1;
}

void circular_queue_linked_list :: display () {
  if(isEmpty()) {
    cout << "Empty Queue" << endl;
  } else {
    Node *h = head;
    while (h->next != head) {
      cout << h->data << " ";
      h = h->next;
    }
    cout << h->data << endl;
  }
}
