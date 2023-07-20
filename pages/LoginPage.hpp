#ifndef LOGINPAGE_HPP
#define LOGINPAGE_HPP

#include <iostream>
#include <ncurses.h>
#include "LoginPage.hpp"
#include "auth.hpp"
#include "config.hpp"
#include "input.hpp"
#include "router.hpp"

using std::cout;
using std::endl;
using std::string;


/**
 * Menghandle login user.
 * 
 * @param idInput ID yang diinput user.
 * @param passwordInput Password yang diinput user.
 */
void handleLogin(string idInput, string passwordInput) {

    // Jika login berhasil, tampilkan pesan berhasil dan redirect ke main menu
    if (login(idInput, passwordInput)) {
        cout << "Login berhasil!" << endl;
        cout << "Tekan sembarang tombol untuk melanjutkan... " << endl;
        getch();
        // TODO: Redirect to main menu
    } 
    
    // Jika login gagal, tampilkan pesan gagal dan reload halaman login
    else {
        cout << "Login gagal. ID atau password salah." << endl;
        cout << "Tekan sembarang tombol untuk mencoba lagi... " << endl;
        getch();
        reloadPage();
    }
}


/**
 * Halaman login yang akan ditampilkan ke user.
 */
void LoginPage() {
    // Variable utk menyimpan input user
    string idInput, passwordInput;

    cout << "==============================================" << endl;
    cout << "   Selamat datang di " << RESTAURANT_NAME << endl;
    cout << "==============================================" << endl;
    cout << endl;
    idInput = inputString("Masukkan ID: ");
    passwordInput = inputString("Masukkan password: ");
    cout << endl;
}

#endif