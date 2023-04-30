//  Copyright 2023 Semenova Veronika

#include <iostream>
#include <string>

#include "include/priority_queue_application.h"

int main(int argc, const char** argv) {
  AppPQ app;
  std::string output = app(argc, argv);
  std::cout << output;
  return 0;
}

