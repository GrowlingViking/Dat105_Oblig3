#ifndef GRAPH_H
#define GRAPH_H

#include "graphadt.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

class Graph : public GraphADT {

public:
    // General graph methods
    Node* aVertex();
    void insertVertex(Node* n);
    void insertEdge(Node* v, Node* w, int i = 0);
    void removeVertex(Node* n);
    void removeEdge(Edge *e);
    std::vector<Edge*>& incidentEdges(Node* n);
    Node** endVertices(Edge* e);
    Node* opposite(Node* n, Edge* e);
    bool areAdjacent(Node* v, Node* w);

    // Methods for directed edges
    bool isDirected(Edge* e);
    void insertDirectedEdge(Node* v, Node* w, int i = 0);
    Node* origin(Edge* e);
    Node* destination(Edge* e);

    // Generic methods
    int numVertices();
    int numEdges();
    std::vector<Node*>& vertices();
    std::vector<Edge*>& edges();

    // Algorithms
    void depthFirstTraversal(Node* n);
    void breadthFirstTraversal(Node* n);
    std::vector<Edge*> primsAlgorithm();
    void dijkstrasAlgorithm(Node* n);
    std::vector<Node*> approxVertexCover();    
    bool checkVertexCover(std::vector<Node *> cover);

private:
    void setAllUnvisited();
    std::vector<Node*> verticeList;
    std::vector<Edge*> edgeList;
};


Node* Graph::aVertex()
{
    if(verticeList.size() > 0)
        return verticeList.at(0);
    else
        return nullptr;
}

void Graph::insertVertex(Node* n)
{
    verticeList.push_back(n);
}

void Graph::insertEdge(Node *v, Node *w, int i)
{
    Edge* e = new Edge(v, w, i);
    edgeList.push_back(e);
    v->edgeList.push_back(e);
    w->edgeList.push_back(e);

}

void Graph::removeEdge(Edge *e)
{
    Edge* x;
    int pos = -1;
    for (int i = 0; i < edgeList.size(); i ++) {
        if (e == edgeList[i]) {
            pos = i;
        }
    }
    if (pos == -1) {
        cout << "Edge not found" << endl;
    } else {
        x = edgeList[pos];
        for (Node* n : x->endpoint) {
            for (int j = 0; j < n->edgeList.size(); j ++) {
                if (e == n->edgeList[j]) {
                    n->edgeList.erase(edgeList.begin() + j);
                }
            }
        }
        edgeList.erase(edgeList.begin() + pos);
    }
}

void Graph::removeVertex(Node *n)
{
    Node* x;
    int pos = -1;
    for (int i = 0; i < verticeList.size(); i ++) {
        if (n == verticeList[i]) {
            pos = i;
        }
    }
    if (pos == -1) {
        cout << "Node not found" << endl;
    } else {
        x = verticeList[pos];
        for (Edge* e : x->edgeList) {
            if (e->endpoint[0] == n) {
                e->endpoint[0] = 0;
            } else if (e->endpoint[1] == n) {
                e->endpoint[1] = 0;
            }
        }
        verticeList.erase(verticeList.begin() + pos);
    }
}

std::vector<Edge*>& Graph::incidentEdges(Node *n)
{
    return n->edgeList;
}

Node** Graph::endVertices(Edge *e)
{
    return e->endpoint;
}

Node* Graph::opposite(Node *n, Edge *e)
{
    if(e->endpoint[0] == n)
        return e->endpoint[1];
    else
        return e->endpoint[0];
}

bool Graph::areAdjacent(Node *v, Node *w)
{
    std::vector<Edge*>::iterator i = v->edgeList.begin();
    while(i != v->edgeList.end()){
        if((*i)->endpoint[0] == w || (*i)->endpoint[1] == w){
            return true;
        }
    }
    return false;
}

bool Graph::isDirected(Edge *e)
{
    return e->isDirected;
}

void Graph::insertDirectedEdge(Node *v, Node *w, int i)
{
    Edge* e = new Edge(v, w, i, true);
    edgeList.push_back(e);
    v->edgeList.push_back(e);
    w->edgeList.push_back(e);
}

Node *Graph::origin(Edge *e)
{
    if(e->isDirected)
        return e->endpoint[0];
    else
        return nullptr;
}

Node *Graph::destination(Edge *e)
{
    if(e->isDirected)
        return e->endpoint[1];
    else
        return nullptr;
}

int Graph::numVertices()
{
    return verticeList.size();
}

int Graph::numEdges()
{
    return edgeList.size();
}

std::vector<Node*>& Graph::vertices()
{
    return verticeList;
}

std::vector<Edge*>& Graph::edges()
{
    return edgeList;
}

void Graph::depthFirstTraversal(Node* n){
    setAllUnvisited();
    std::stack<Node*> verticeStack;
    verticeStack.push(n);
    while(!verticeStack.empty()){
        Node* v = verticeStack.top();
        verticeStack.pop();
        if(!v->visited){
            for(std::vector<Edge*>::iterator i = v->edgeList.begin(); i != v->edgeList.end(); i++){
                verticeStack.push(opposite(v, *i));
            }
            std::cout << v->data << " ";
            v->visited = true;
        }
    }
    std::cout << std::endl;
}

void Graph::breadthFirstTraversal(Node* n){
    setAllUnvisited();
    queue<Node*> verticeQueue;
    verticeQueue.push(n);
    while(!verticeQueue.empty()) {
        Node* v = verticeQueue.front();
        verticeQueue.pop();
        if (!v->visited) {
            for(vector<Edge*>::iterator i = v->edgeList.begin(); i != v->edgeList.end(); i ++) {
                Node* x = opposite(v, *i);
                if (!x->visited) {
                    verticeQueue.push(x);
                }
            }
            cout << v->data << " ";
            v->visited = true;
        }
    }
    cout << endl;
}

void Graph::setAllUnvisited()
{
    for(std::vector<Node*>::iterator i = verticeList.begin(); i != verticeList.end(); i++){
        (*i)->visited = false;
    }
}

/*
 *  Here we create a functor class that we can use to create a priority queue for Edges
 */
class CompareEdges
{
public:
    bool operator()(const Edge* e, const Edge* f)
    {
        /* Returns true if edge e has higher weight than edge f */
        return e->weight > f->weight;
    }
};

std::vector<Edge*> Graph::primsAlgorithm(){
    // TODO
}

/*
 *  Here we create a functor class that we can use to create a priority queue for Nodes
 */
class CompareNodeDistance
{
public:
    bool operator()(const Node* v, const Node* w)
    {
        /* Returns true if node v has longer path than node w */
        return v->distance > w->distance;
    }
};

void Graph::dijkstrasAlgorithm(Node *n)
{
    n->distance = 0;
    std::deque<Node*> unvisitedNodes(verticeList.begin(), verticeList.end());

    while(!unvisitedNodes.empty()){
        // Find min distance node
        std::make_heap(unvisitedNodes.begin(), unvisitedNodes.end(), CompareNodeDistance());
        Node* v = unvisitedNodes.front();
        unvisitedNodes.pop_front();
        for(std::vector<Edge*>::iterator i = v->edgeList.begin(); i != v->edgeList.end(); i++){
            Node* w = opposite(v,*i);
            int dist = v->distance + (*i)->weight;
            if( dist < w->distance ){
                w->distance = dist;
                w->previous = v;
            }
        }
    }
}

std::vector<Node*> Graph::approxVertexCover(){
    std::vector<Node*> c;
    std::vector<Edge*> e(edgeList.begin(), edgeList.end());

    while(!e.empty()){
        // Randomly choose an edge (u,v) in E’, put u and v into C;
        Edge* tmpEdge = e.back();
        e.pop_back();
        Node* u = tmpEdge->endpoint[0];
        Node* v = tmpEdge->endpoint[1];
        c.push_back(u);
        c.push_back(v);

        // Remove all the edges that are covered by u or v from E’
        for(std::vector<Edge*>::iterator it = u->edgeList.begin(); it != u->edgeList.end(); it++){
            std::vector<Edge*>::iterator pos = std::find(e.begin(), e.end(),*it);
            if(pos != e.end())
                e.erase(pos);
        }

        for(std::vector<Edge*>::iterator it = v->edgeList.begin(); it != v->edgeList.end(); it++){
            std::vector<Edge*>::iterator pos = std::find(e.begin(), e.end(),*it);
            if(pos != e.end())
                e.erase(pos);
        }
    }
    return c;
}

bool Graph::checkVertexCover(std::vector<Node*> cover){
    std::vector<Edge*> e(edgeList.begin(), edgeList.end());

    while(!cover.empty()){
        Node* v = cover.back();
        cover.pop_back();

        // Remove all the edges that are covered by v from E’
        for(std::vector<Edge*>::iterator it = v->edgeList.begin(); it != v->edgeList.end(); it++){
            std::vector<Edge*>::iterator pos = std::find(e.begin(), e.end(),*it);
            if(pos != e.end())
                e.erase(pos);
        }
    }
    return e.empty();
}

#endif // GRAPH_H
