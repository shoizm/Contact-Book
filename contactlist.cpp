#include <iostream>

class contact {
private:
  std::string name;
  std::string email;
  std::string number;

public:
  void setName(std::string n) {
     name = n; 
    }

    std::string getName(){
        return name;
    }
};

int main() {
  contact cname;

  std::cout << "Set a name: " << std::endl;
  cname.setName = 
}
