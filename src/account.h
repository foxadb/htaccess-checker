#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
 public:
  Account(char* username, char* password);
  ~Account();

  void print();
  char* getUsername();
  char* getPassword();
  bool isValid();

  void setValid(bool valid);

 private:
  char* username;
  char* password;
  bool valid;
};

#endif  // ACCOUNT_H