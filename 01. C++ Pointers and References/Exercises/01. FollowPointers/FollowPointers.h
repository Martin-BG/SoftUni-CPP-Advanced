#ifndef FOLLOWPOINTERS_H
#define FOLLOWPOINTERS_H

#include "Node.h"

int getSumFrom(const Node* node) {
  int sum = 0;
  auto current = node;
  while (current) {
    sum += current->value;
    current = current->next;
  }
  return sum;
}

#endif //FOLLOWPOINTERS_H
