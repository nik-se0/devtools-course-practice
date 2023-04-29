// Copyright 2023 Semenova Veronika

#include <gtest/gtest.h>

#include "include/binary_tree.h"

Node::Node(const int V, Node* P, 
	Node* L, Node* R) : Value(V), Left(L), 
	Right(R), Parent(P) {}
Node::Node(const Node& n) : 
	Value(n.Value), Left(nullptr), 
	Right(nullptr), Parent(nullptr) {}
