#ifndef LOGINPAGE_HPP
#define LOGINPAGE_HPP

#include "../utils/auth.hpp"
#include "../utils/inputHandler.hpp"
#include "../utils/router.hpp"


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
        navigate(&mainMenuPage);
    }
    
    // Jika login gagal, tampilkan pesan gagal dan reload halaman login
    else {
        cout << "Login gagal. ID atau password salah." << endl;
        cout << "Tekan sembarang tombol untuk kembali ke menu awal... " << endl;
        getch();
        navigate(&welcomePage);
    }
}


/**
 * Halaman login yang akan ditampilkan ke user.
 */
void LoginPage() {
    // Variable utk menyimpan input user
    string idInput, passwordInput;

    cout << "=========================================" << endl;
    cout << "   Silakan masuk menggunakan akun Anda   " << endl;
    cout << "=========================================" << endl;
    cout << endl;
    idInput = inputString("Masukkan ID: ");
    passwordInput = inputPassword("Masukkan password: ");
    cout << endl;

    handleLogin(idInput, passwordInput);
}

#endif