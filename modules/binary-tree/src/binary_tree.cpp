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
void BinaryTree::Insert(int v){
  if (root == nullptr)  {
    root = new Node(v);
    return;
  }
  if (Find(v) != nullptr) {
    throw std::exception("\tRe-insertion of the element is not possible\n");
  }
  Node* x = root, * y;
  while (x != nullptr) {
    y = x;
    if (v < x->Value) {
	  x = x->Left;
	}
	else{ 
	  x = x->Right;
	}
  }
  if (v < y->Value) {
    y->Left = new Node(v, y);
  }
  else {
    y->Right = new Node(v, y);
  }
}
Node* BinaryTree::Find(int k)  const{
  Node* tmp = root;
  while ((tmp != nullptr) && (tmp->Value != k)) {
    if (k < tmp->Value) {
	  tmp = tmp->Left;
	}
	else { 
	  tmp = tmp->Right;
	}
  }
  return tmp;
}
