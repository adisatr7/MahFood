#ifndef AUTH_HPP
#define AUTH_HPP

#include "../models/User.hpp"
#include "../data/accounts.hpp"


/**
 * Cek apakah user dengan id tertentu sudah terdaftar.
 * 
 * @param id ID User.
 * 
 * @return `true` jika user sudah terdaftar, `false` jika belum.
 */
bool isUserIdExist(string id) {

    // Buat pointer baru yang menunjuk ke head dari Linked List.
    Node<User>* current = registeredUsers.head;

    // Cari user yang sesuai dengan id.
    while (current != nullptr) {
        if (current->data.id == id)
            return true;

        // Jika data yang ditunjuk oleh pointer bukan yang dicari, maju ke data berikutnya.
        current = current->next;
    }

    // Jika tidak ditemukan, kembalikan `false`.
    return false;
}


/**
 * Cek apakah user dengan id dan password tertentu sudah terdaftar.
 * 
 * @param id ID User.
 * @param password Password User.
 * 
 * @return `true` jika user sudah terdaftar, `false` jika belum.
 */
bool isUserExist(string id, string password) {

    // Buat pointer baru yang menunjuk ke head dari Linked List.
    Node<User>* current = registeredUsers.head;

    // Cari user yang sesuai dengan id dan password.
    while (current != nullptr) {
        if (current->data.id == id && current->data.password == password)
            return true;

        // Jika data yang ditunjuk oleh pointer bukan yang dicari, maju ke data berikutnya.
        current = current->next;
    }

    // Jika tidak ditemukan, kembalikan `false`.
    return false;
}


/**
 * Login ke aplikasi.
 * 
 * @param id ID User.
 * @param password Password User.
 * 
 * @return `true` jika login berhasil, `false` jika gagal.
 */
bool login(string id, string password) {

    // Buat pointer baru yang menunjuk ke head dari Linked List.
    Node<User>* current = registeredUsers.head;

    // Cari user yang sesuai dengan id dan password.
    while (current != nullptr) {
        if (current->data.id == id && current->data.password == password) {
            currentUser = current->data;
            return true;
        }

        // Jika data yang ditunjuk oleh pointer bukan yang dicari, maju ke data berikutnya.
        current = current->next;
    }
    return false;
}


/**
 * Mendaftarkan User baru.
 * 
 * @param id ID User.
 * @param name Nama User.
 * @param password Password User.
 * 
 * @return `true` jika berhasil, `false` jika gagal.
 */
bool registerUser(string id, string name, string password) {

    // Buat pointer baru yang menunjuk ke head dari Linked List.
    Node<User>* current = registeredUsers.head;

    // Cari apakah id sudah pernah didaftarkan sebelumnya.
    if (isUserExist(id, password)) {

        // Jika sudah, tampilkan peringatan dan kembalikan `false`.
        cout << "Username sudah terdaftar!" << endl;
        return false;
    }

    // Jika belum, tambahkan user baru ke Linked List.
    User newUser = User(id, name, password);
    registeredUsers.push(newUser);

    return true;
}

#endif