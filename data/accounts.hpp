#include "../models/User.hpp"
#include "../components/LinkedList.hpp"

#ifndef ACCOUNTS_HPP
#define ACCOUNTS_HPP


/**
 * Linked List utk menyimpan data user yang sudah terdaftar.
 */
LinkedList<User> registeredUsers = LinkedList<User>();

#endif