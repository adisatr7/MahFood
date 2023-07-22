#include "../models/Transaction.hpp"
#include "../components/LinkedList.hpp"

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP


/**
 * Linked List utk menyimpan data user yang sudah terdaftar.
 */
LinkedList<Transaction> shoppingCart = LinkedList<Transaction>();

#endif