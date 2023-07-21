#ifndef ACCOUNTS_HPP
#define ACCOUNTS_HPP

#include "../data/User.hpp"
#include "../components/LinkedList.hpp"


/**
 * Linked List utk menyimpan data user yang sudah terdaftar.
 */
LinkedList<User> registeredUsers = LinkedList<User>();


/**
 * User yang sedang login.
 */
User currentUser = User("", "", "");

#endif