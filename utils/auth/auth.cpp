#include "auth.hpp"

using std::cout;
using std::endl;


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


bool login(string id, string password) {
    return isUserExist(id, password);
}


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