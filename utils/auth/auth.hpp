#ifndef AUTH_HPP
#define AUTH_HPP

#include <iostream>
#include "User.hpp"
#include "LinkedList.hpp"

using std::string;


/**
 * Linked List utk menyimpan data user yang sudah terdaftar.
 */
LinkedList<User> registeredUsers = LinkedList<User>();

/**
 * User yang sedang login.
 */
User currentUser = User("", "", "");


/**
 * Cek apakah user dengan id dan password tertentu sudah terdaftar.
 * 
 * @param id ID User.
 * @param password Password User.
 * 
 * @return `true` jika user sudah terdaftar, `false` jika belum.
 */
bool isUserExist(string id, string password);

/**
 * Login ke aplikasi.
 * 
 * @param id ID User.
 * @param password Password User.
 * 
 * @return `true` jika login berhasil, `false` jika gagal.
 */
bool login(string id, string password);

/**
 * Mendaftarkan User baru.
 * 
 * @param id ID User.
 * @param name Nama User.
 * @param password Password User.
 * 
 * @return `true` jika berhasil, `false` jika gagal.
 */
bool registerUser(string id, string name, string password);

#endif