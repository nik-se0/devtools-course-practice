//  Copyright 2023 Semenova Veronika

#include <gtest/gtest.h>

#include "include/binary_tree.h"

Node::Node(const int V, Node* P,
  Node* L, Node* R) : Value(V), Left(L),
  Right(R), Parent(P) {}
Node::Node(const Node& n) :
  Value(n.Value), Left(nullptr),
  Right(nullptr), Parent(nullptr) {}


BinaryTree::BinaryTree():root(nullptr),curr(nullptr){}
BinaryTree::BinaryTree(int v) {
  root = new Node(v);
  curr = nullptr;
}
Node* BinaryTree::FindMin(Node* node) const{
  Node* tmp = node;
  while (tmp->Left != nullptr)	{
  tmp = tmp->Left;
}
  return tmp;
}
void BinaryTree::Reset() {
  if (root != nullptr) {
    curr = FindMin(root);
  }
  else {
  throw std::exception("Ñan't resert");
	}
}
int BinaryTree::GetValue() const {
  if (curr != nullptr) {
    return curr->Value;
  }
  else {
    throw std::exception("Ñan't extract a value");
  }
}
