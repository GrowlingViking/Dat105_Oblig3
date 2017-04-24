#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "edge.h"

class priorityQueue {
public:
    /* Constructor */
    priorityQueue();

    /* Destructor */
    ~priorityQueue();

    /* Add an Edge object */
    void add(Edge* e);

    /* Remove the edge with highest priority */
    void remove();

    /* Checks if the queue is empty */
    bool isEmpty();
};

#endif // PRIORITYQUEUE_H
