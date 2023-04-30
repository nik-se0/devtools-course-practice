// Copyright 2023 Semenova Veronika

#include "include/pq_pp.h"

#include <sstream>


AppPQ::AppPQ() : message("") {}

void AppPQ::Help(const char* appname, const char* mes) {
    std::ostringstream stream;
    stream <<
        std::string(mes) <<
        "\tThis is an application for working with a priority queue.\n\n\n" <<
        "\tPlease provide arguments in the following format:\n" <<
        "   $ " << appname << "  <Operation>" << "  <value_or_values>\n\n" <<
        "\tThe arguments for the operations must be integer number,"<<
        " and the operation is one of the following :"
        << "\n\t'put' - \tPut elements in queue."
        << "\n\t'pop' - \tRetrieves the element on the top out of queue"
        << "\n\t'top' - \tReturns element value on the top out of queue"
        << "\n\t'get' - \tRetrieves the element on the top"
        << " and returns its value out of queue "
        << "\n\t'size' - \tReturns the queue size"
        << "\n\t'empty' -  \tChecks if the queue is empty"
        << "\n\t'clear' - \tClears the queue\n\n";
    message = stream.str();
}

int ParseToInt(const char* arg) {
    int result = 0;
    try {
      result = std::stoi(arg);
    }
    catch (...) {
      throw std::string("Wrong number format!");
    }
    return result;
}

int ParseOperation(const char* arg) {
    int operation = 0;
    if (strcmp(arg, "put") == 0) {
        operation = 7;
    } else if (strcmp(arg, "pop") == 0) {
        operation = 4;
    } else if (strcmp(arg, "top") == 0) {
        operation = 5;
    } else if (strcmp(arg, "get") == 0) {
        operation = 6;
    } else if (strcmp(arg, "size") == 0) {
        operation = 3;
    } else if (strcmp(arg, "empty") == 0) {
        operation = 2;
    } else if (strcmp(arg, "clear") == 0) {
        operation = 1;
    } else {
        throw std::string("Wrong operation");
    }
    return operation;
}

std::string AppPQ::operator()(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return message;
    }

    int operation = 0;
    try {
        operation = ParseOperation(argv[1]);
    }
    catch (...) {
        return "Unknown operator. Incorrect input format";
    }
   int tmp;
   if (argc == 2) {
     try {
       switch (operation) {
       case 1:
          message+= "\tThe queue cleared\n";
          Q1.clear();
          break;
       case 3:
           tmp = Q1.size();
           message += "\tA queue size = ";
           message += std::to_string(tmp) + "\n";
           break;
       case 2:
           if (Q1.empty()) {
               message += "\tQueue is empty\n";
           }
           else {
               message += "\tQueue is not empty\n";
           }
           break;
       case 4:
           message += "\tAn insertion was made";
           message += " into the queue\n";
           Q1.pop();
           break;
       case 5:
           message += "\tAt the top of the queue a value of ";
           tmp = Q1.top();
           break;
       case 6:
           message += "\tThe withdrawal was made";
           message += " from the queue a value of ";
           tmp = Q1.get();
           break;
       default:
           throw std::string("Wrong number format!");
       }
     }
     catch (std::string& str) {
         return str;
     }
     if (operation > 4) {
         message += std::to_string(tmp) + "\n";
     }
   } else {
        message+= "\tAn insertion was made from the queue:\n\t";
       try {
           for (int i = 2; i < argc; i++) {
               tmp = ParseToInt(argv[i]);
                message+= " " + std::to_string(tmp);
               Q1.put(tmp);
           }
       }
       catch (std::string& str) {
           return str;
       }
   }
   return message;
}
