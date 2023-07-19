#include <string>
#include "Item.h"

using namespace std;


#ifndef USER_H
#define USER_H

/**
 * Definisi struct Account yang akan digunakan untuk login ke aplikasi.
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
    User(string id, string name, string password);

    /**
     * Validasi apakah id dan password yang dimasukkan sesuai dengan akun ini.
     */
    bool validate(string idInput, string passwordInput);
};

#endif