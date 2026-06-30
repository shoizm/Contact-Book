#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class contact {
private:
  std::string name;
  std::string email;
  std::string number;

public:
  void setName(std::string n) { name = n; }

  void setPNum(std::string p) {
    if (p.length() >= 0) {
      number = p;
    } else {
      std::cout << "Invalid phone number." << std::endl;
    }
  }

  void setEmail(std::string e) { email = e; }

  std::string getName() { return name; }
  std::string getPNum() { return number; }
  std::string getEmail() { return email; }
};

std::vector<contact> contactList;

void add(std::vector<contact> &contactList);
void search(std::vector<contact> &contactList);
void remove(std::vector<contact> &contactList);
void edit(std::vector<contact> &contactList);

int main() {

  while (true) {
    std::cout << "\n1. Add Contact\n"
                 "2. Remove Contact\n"
                 "3. Search Contacts\n"
                 "4. Edit Contact\n"
                 "5. Exit\n"
              << std::endl;
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\n[Error]" << std::endl;
      continue;
    }

    switch (choice) {
    case 1:
      add(contactList);
      break;

    case 2:
      remove(contactList);
      break;

    case 3:
      search(contactList);
      break;

    case 4:
      edit(contactList);
      break;

    case 5:
      return 0;
    }
  }
}

void add(std::vector<contact> &contactList) {
  contact con;

  std::cin.ignore(1000, '\n');

  std::cout << "\nName of Contact: " << std::endl;
  std::string name;
  std::getline(std::cin, name);
  con.setName(name);

  std::cout << "Email: " << std::endl;
  std::string email;
  std::getline(std::cin, email);
  con.setEmail(email);

  std::cout << "Phone Number: " << std::endl;
  std::string number;
  std::getline(std::cin, number);
  con.setPNum(number);

  contactList.push_back(con);
}

void remove(std::vector<contact> &contactList) {
  contact con;

  if (contactList.empty()) {
    std::cout << "\n[Error] Add a Contact!" << std::endl;
    return;
  }

  for (int i = 0; i < contactList.size(); i++) {
    std::cout << "\nContact Name: " << contactList[i].getName()
              << "\nEmail: " << contactList[i].getEmail()
              << "\nPhone Number: " << contactList[i].getPNum() << std::endl;
  }

  std::cin.ignore(1000, '\n');
  std::cout << "\nType a contact's name to remove:" << std::endl;
  std::string contactName;

  std::getline(std::cin, contactName);
  contactList.erase(std::remove_if(contactList.begin(), contactList.end(),
                                   [contactName](contact con) {
                                     return con.getName() == contactName;
                                   }),
                    contactList.end());

  std::cout << "\nRemoved Contact: " + contactName << std::endl;
  return;
}

void search(std::vector<contact> &contactList) {

  for (int i = 0; i < contactList.size(); i++) {
    std::cout << "\nContact Name: " << contactList[i].getName()
              << "\nEmail: " << contactList[i].getEmail()
              << "\nPhone Number: " << contactList[i].getPNum() << std::endl;
  }
}

void edit(std::vector<contact> &contactList) {
  contact con;

  if (contactList.empty()) {
    std::cout << "\n[Error] Add a Contact!" << std::endl;
    return;
  }


  for (int i = 0; i < contactList.size(); i++) {
    std::cout << "\nContact Name: " << contactList[i].getName()
              << "\nEmail: " << contactList[i].getEmail()
              << "\nPhone Number: " << contactList[i].getPNum() << std::endl;
  }

  std::cout << "\nSelect Contact to Edit:" << std::endl;
  std::cin.ignore(1000, '\n');

  std::string search;
  std::getline(std::cin, search);

  int index = -1;
  for (int i = 0; i < contactList.size(); i++) {
    if (contactList[i].getName() == search) {
      index = i;
      break;
    }
  }
  
  }
