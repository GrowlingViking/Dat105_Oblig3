#include <iostream>
#include "graph.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Edge* e){
    os << "(" << e->endpoint[0]->data << ", " <<  e->endpoint[1]->data << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Node* n){
    char previous = ' ';
    if(n->previous != NULL)
            previous = n->previous->data;
    os << "(" << n->data << ", " <<  n->distance << ", " << previous << ")";
    return os;
}

template <typename T>
void printVector(const vector<T>& v){
    for(typename vector<T>::const_iterator i = v.begin(); i != v.end(); i++){
        cout << *i << endl;
    }
}

int main()
{
    Graph graf;
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');

    graf.insertVertex(a);
    graf.insertVertex(b);
    graf.insertVertex(c);
    graf.insertVertex(d);
    graf.insertVertex(e);
    graf.insertVertex(f);

    graf.insertEdge(a,b,1);
    graf.insertEdge(b,c,2);
    graf.insertEdge(b,d,3);
    graf.insertEdge(c,e,4);
    graf.insertEdge(d,e,5);
    graf.insertEdge(b,c,2);
    graf.insertEdge(e,f,1);

    graf.removeVertex(b);
    graf.depthFirstTraversal(f);
    graf.breadthFirstTraversal(f);
    vector<Edge*> v = graf.primsAlgorithm();
    printVector(v);
    graf.dijkstrasAlgorithm(e);
    printVector(graf.vertices());
    printVector(graf.approxVertexCover());
    cout << graf.checkVertexCover(graf.approxVertexCover()) << endl;

    return 0;
}

