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
      std::cout << "\n[ERROR]" << std::endl;
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
  std::cin.ignore(1000, '\n');

  std::cout << "\nName of Contact: " << std::endl;
  std::string name;
  std::getline(std::cin, name);

  bool duplicate1 = false;
  for (int i = 0; i < contactList.size(); i++) {
    if (name == contactList[i].getName()) {
      duplicate1 = true;
      break;
    }

    if (duplicate1) {
      std::cout
          << "\n[ERROR] Duplicate Detected, Please enter a new contact name."
          << std::endl;
          return;
    }
  }

  bool duplicate2 = false;
  std::cout << "Email: " << std::endl;
  std::string email;
  std::getline(std::cin, email);

  for (int i = 0; i < contactList.size(); i++) {
    if (email == contactList[i].getEmail()) {
      duplicate2 = true;
      break;
    }

    if (duplicate2) {
      std::cout
          << "\n[ERROR] Duplicate Detected, Please enter a new contact name."
          << std::endl;
          return;
    }
  }

  bool duplicate3 = false;
  std::cout << "Phone Number: " << std::endl;
  std::string number;
  std::getline(std::cin, number);

  for (int i = 0; i < contactList.size(); i++) {
    if (number == contactList[i].getPNum()) {
      duplicate3 = true;
      break;
    }

    if (duplicate3) {
      std::cout
          << "\n[ERROR] Duplicate Detected, Please enter a new contact name."
          << std::endl;
          return;
    }
  }

  contact con;
  con.setName(name);
  con.setEmail(email);
  con.setPNum(number);
  contactList.push_back(con);

  std::cout << "\nContact: [ " + name << " ] Added" << std::endl;
}

void remove(std::vector<contact> &contactList) {

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

  int index = -1;
  for (int i = 0; i < contactList.size(); i++) {
    if (contactList[i].getName() == contactName) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    std::string erase;
    std::cout << "\n[ERROR] Contact not found. " << std::endl;
  } else {
    contactList.erase(contactList.begin() + index);
    std::cout << "\nRemoved Contact: " + contactName << std::endl;
  }
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

  std::cout << "\nEnter contact name to edit:" << std::endl;
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

  if (index == -1) {
    std::cout << "\n[ERROR] Contact not found." << std::endl;
    return;
  }

  int option;
  std::cout << "\nSelect an option to edit"
            << "\n1: Name"
            << "\n2: Email"
            << "\n3: Phone Number\n"
            << std::endl;
  std::cin >> option;

  switch (option) {
  case 1:

    if (index != -1) {
      std::string editedname;
      std::cin.ignore(1000, '\n');
      std::cout << "\nType a new name: " << std::endl;
      std::getline(std::cin, editedname);

      bool duplicate = false;
      for (int i = 0; i < contactList.size(); i++) {
        if (editedname == contactList[i].getName()) {
          duplicate = true;
          break;
        }
      }

      if (duplicate) {
        std::cout << "\n[ERROR] Name already exists." << std::endl;
      } else {
        contactList[index].setName(editedname);
        std::cout << "\nRenamed to: " + editedname << std::endl;
      }
    } else {
      std::cout << "\nNo contact found." << std::endl;
    }
    break;

  case 2:

    if (index != -1) {
      std::string editedemail;
      std::cin.ignore(1000, '\n');
      std::cout << "\nType a new email: " << std::endl;
      std::getline(std::cin, editedemail);
      bool duplicate = false;
      for (int i = 0; i < contactList.size(); i++) {
        if (editedemail == contactList[i].getEmail()) {
          duplicate = true;
          break;
        }
      }

      if (duplicate) {
        std::cout << "\n[ERROR] Email already exists." << std::endl;
      } else {
        contactList[index].setName(editedemail);
        std::cout << "\nRenamed to: " + editedemail << std::endl;
      }
    } else {
      std::cout << "\nNo contact found." << std::endl;
    }
    break;

  case 3:

    if (index != -1) {
      std::string editednumber;
      std::cin.ignore(1000, '\n');
      std::cout << "\nType a new phone number: " << std::endl;
      std::getline(std::cin, editednumber);
      bool duplicate = false;
      for (int i = 0; i < contactList.size(); i++) {
        if (editednumber == contactList[i].getPNum()) {
          duplicate = true;
          break;
        }
      }

      if (duplicate) {
        std::cout << "\n[ERROR] Number already exists." << std::endl;
      } else {
        contactList[index].setName(editednumber);
        std::cout << "\nRenamed to: " + editednumber << std::endl;
      }
    } else {
      std::cout << "\nNo contact found." << std::endl;
    }
    break;
  }
}
