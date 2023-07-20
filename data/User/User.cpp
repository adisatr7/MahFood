#include <iostream>
#include "User.hpp"

using namespace std;


User::User(string id, string name, string password) {
    this->id = id;
    this->name = name;
    this->password = password;
}


bool User::validate(string idInput, string passwordInput) {
    return this->id == idInput && this->password == passwordInput;
}