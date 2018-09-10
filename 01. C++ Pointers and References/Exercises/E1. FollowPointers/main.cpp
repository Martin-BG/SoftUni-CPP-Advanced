#include<iostream>

#include "Node.h"

//int getSumFrom(Node* start);

int main() {
  using namespace std;

  Node nodes[]{ Node(0, nullptr), Node(1, nullptr), Node(2, nullptr), Node(3, nullptr), Node(4, nullptr) };

  nodes[0].next = &nodes[3];
  nodes[3].next = &nodes[2];
  nodes[2].next = &nodes[4];

  cout << getSumFrom(&nodes[0]) << endl;

  return 0;
}
