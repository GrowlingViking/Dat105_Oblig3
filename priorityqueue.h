#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "edge.h"
#include <vector>

class priorityQueue {
public:
    /* Empty constructor */
    priorityQueue();

    /* Destructor */
    ~priorityQueue();

    /* Add an Edge object */
    void add(Edge* e);

    /* Remove the edge with highest priority */
    void remove();

    /* Checks if the queue is empty */
    bool isEmpty();

    /* Returns the top element in the queue */
    Edge* top();

    /* Overload the += operator */
    void operator +=(Edge* e);

    /* Container */
    vector<Edge> container;
};

/* Empty constructor */
priorityQueue::priorityQueue() {
    vector<Edge> container;
}

/* Destructor */
priorityQueue::~priorityQueue() {
    cout << "Priority Queue is being destroyed!" << endl;
}

/* Add an Edge object */
void priorityQueue::add(Edge *e) {
    if (isEmpty()) {
        container.push_back(e);
    } else if (e->weight < container.end()->weight) {
        container.push_back(e);
    } else {
        int i = 0;
        while (e->weight < container.at(i)->weight) {
            i ++;
        }
        container.insert(i + 1, e);
    }
}

/* Remove the edge with the highest priority */
void priorityQueue::remove() {
    if (isEmpty()) {
        cout << "The queue is empty" << endl;
    } else {
        container.pop_back();
    }
}

/* Checks if the queue is empty */
bool priorityQueue::isEmpty() {
    return container.empty();
}

/* Returns the top element of the queue */
Edge* priorityQueue::top() {
    return container.back();
}

/* Overload the += operator */
void priorityQueue::operator +=(Edge* e) {
    add(e);
}

#endif // PRIORITYQUEUE_H
