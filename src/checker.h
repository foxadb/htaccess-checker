#ifndef CHECKER_H
#define CHECKER_H

#include "account.h"

#include <cstdlib>

class Checker {
 public:
  Checker(char* url);
  ~Checker();

  bool checkAccount(Account* account);

 private:
  char* url;
};

size_t writeCallback(char* content, size_t size, size_t nmemb, void* userdata);

#endif  // CHECKER_H