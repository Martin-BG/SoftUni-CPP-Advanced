#include <sstream>
#include "List.h"

List::Node::Node(int value, List::Node* prev, List::Node* next) : value(value), prev(prev), next(next) { }

int List::Node::getValue() const {
  return this->value;
}

void List::Node::setValue(int value) {
  this->value = value;
}

List::Node* List::Node::getNext() const {
  return this->next;
}

void List::Node::setNext(List::Node* next) {
  this->next = next;
}

List::Node* List::Node::getPrev() const {
  return this->prev;
}

void List::Node::setPrev(List::Node* prev) {
  this->prev = prev;
}

List::List() : head(nullptr), tail(nullptr), size(0) { }

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
  this->addAll(other);
}

List::~List() {
  this->removeAll();
}

int List::first() const {
  return this->head != nullptr ? this->head->getValue() : 0;
}

void List::add(int value) {
  if (this->size == 0) { // First
    Node* node = new Node(value, nullptr, nullptr);
    this->head = node;
    this->tail = node;
  } else if (this->tail->getValue() <= value) { // Push to back
    Node* node = new Node(value, this->tail, nullptr);
    this->tail->setNext(node);
    this->tail = node;
  } else if (this->head->getValue() >= value) { // Insert to start
    Node* node = new Node(value, nullptr, this->head);
    this->head->setPrev(node);
    this->head = node;
  } else { // Find place
    Node* prev = this->head;
    while (prev->getValue() < value && value < prev->getNext()->getValue()) {
      prev = prev->getNext();
    }
    Node* node = new Node(value, prev, prev->getNext());
    prev->getNext()->setPrev(node);
    prev->setNext(node);
  }
  ++this->size;
}

void List::addAll(const List& other) {
  Node* current = other.head;
  while (current != nullptr) {
    this->add(current->getValue());
    current = current->getNext();
  }
}

void List::removeFirst() {
  if (this->head != nullptr) {
    Node* first = this->head;
    if (first->getNext() != nullptr) {
      first->getNext()->setPrev(nullptr);
      this->head = first->getNext();
    } else {
      this->head = nullptr;
      this->tail = nullptr;
    }
    delete first;
    --this->size;
  }
}

void List::removeAll() {
  while (this->head != nullptr) {
    this->removeFirst();
  }
}

size_t List::getSize() const {
  return this->size;
}

bool List::isEmpty() const {
  return this->size == 0;
}

List List::getReversed(List list) {
  List reversed(list);

  Node* head = reversed.head;
  Node* tail = reversed.tail;

  Node* current = reversed.head;

  while (current != tail) {
    Node* next = current->getNext();
    current->setPrev(next);
    next->setNext(current);
    current = next;
  }

  reversed.head = tail;
  reversed.tail = head;

  if (reversed.head != nullptr) {
    reversed.head->setPrev(nullptr);
  }

  if (reversed.tail != nullptr) {
    reversed.tail->setNext(nullptr);
  }

  return reversed;
}

std::string List::toString() const {
  std::ostringstream os;
  Node* current = this->head;
  while (current != nullptr) {
    os << current->getValue() << ' ';
    current = current->getNext();
  }
  return os.str();
}

List& List::operator<<(const int& value) {
  this->add(value);
  return *this;
}

List& List::operator<<(const List& other) {
  this->addAll(other);
  return *this;
}

List& List::operator=(const List& other) {
  if (this != &other) {
    this->removeAll();
    this->addAll(other);
  }
  return *this;
}
