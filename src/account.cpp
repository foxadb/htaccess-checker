#include "account.h"

#include <cstdio>
#include <cstring>

Account::Account(char* username, char* password) {
  this->username = new char[strlen(username) + 1];
  strcpy(this->username, username);

  this->password = new char[strlen(password) + 1];
  strcpy(this->password, password);
}

Account::~Account() {
  delete[] username;
  delete[] password;
}

void Account::print() {
  printf("User: %s, Password: %s\n", this->username, this->password);
}

char* Account::getUsername() { return this->username; }

char* Account::getPassword() { return this->password; }

bool Account::isValid() { return this->valid; }

void Account::setValid(bool valid) { this->valid = valid; }