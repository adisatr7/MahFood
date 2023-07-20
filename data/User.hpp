#ifndef USER_HPP
#define USER_HPP

#include "Item.hpp"


/**
 * Akun yang akan digunakan untuk login ke aplikasi.
 */ 
struct User {
    string id;          /** ID yang digunakan untuk login. */
    string name;        /** Nama lengkap user. */
    string password;    /** Password yang digunakan untuk login. */


    /**
     * Konstruktor Account.
     * 
     * @param id ID yang digunakan untuk login.
     * @param name Nama lengkap user.
     * @param password Password yang digunakan untuk login.
     */
    User(string id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
};

#endif