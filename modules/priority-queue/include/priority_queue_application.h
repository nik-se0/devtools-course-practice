// Copyright 2023 Semenova Veronika

#include <string>
#include "include/priority_queue.h"

class AppPQ {
  std::string message;
  PriorityQueue<int> Q1;
  void Help(const char* appname, const char* message = "");

public:
  AppPQ();
  std::string operator()(int argc, const char** argv);
};
