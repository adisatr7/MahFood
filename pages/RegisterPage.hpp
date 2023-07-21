#ifndef REGISTERPAGE_HPP
#define REGISTERPAGE_HPP

#include "../utils/auth.hpp"
#include "../utils/inputHandler.hpp"
#include "../utils/router.hpp"


/**
 * Validasi user ID, cek apakah panjangnya sebanyak 3-20 karakter.
 * 
 * @param id ID yang diinputkan user.
 * 
 * @return `true` jika valid, `false` jika tidak.
 */
bool validateId(string id) {
    if (id.length() <= 3) {
        cout << "ID minimal 3 karakter." << endl;
        return false;
    } else if (id.length() > 32) {
        cout << "ID maksimal 32 karakter." << endl;
        return false;
    } else {
        return true;
    }
}


/**
 * Validasi nama lengkap user.
 * 
 * @param name Nama lengkap user.
 * 
 * @return `true` jika valid, `false` jika tidak.
 *  
 * ! @warning Sejauh ini belum jelas apa yang mau divalidasi, 
 * ! tapi utk jaga-jaga, fungsi ini dibiarkan disini saja.
*/
bool validateName(string name) {
    // if (name.length() < 2) {
    //     cout << "Nama minimal 3 karakter." << endl;
    //     return false;
    // } else if (name.length() > 20) {
    //     cout << "Nama maksimal 20 karakter." << endl;
    //     return false;
    // } else {
        return true;
    // }
}

/**
 * Cek digit password. Digit yang valid adalah 6-20 karakter.
 * 
 * @param password Password yang diinputkan user.
 * 
 * @return `true` jika valid, `false` jika tidak.
*/
bool validatePassword(string password) {
    if (password.length() <= 6) {
        cout << "Kata sandi minimal 6 karakter." << endl;
        return false;
    } else if (password.length() > 20) {
        cout << "Kata sandi maksimal 20 karakter." << endl;
        return false;
    } else {
        return true;
    }
}


/**
 * Cek apakah kedua password yang dimasukkan sama.
 * 
 * @param password Password yang diinputkan user.
 * @param confirmPassword Konfirmasi password yang diinputkan user.
 * 
 * @return `true` jika valid, `false` jika tidak.
 */
bool validateConfirmPassword(string password, string confirmPassword) {
    if (password != confirmPassword) {
        cout << "Kata sandi tidak sama." << endl;
        return false;
    } else {
        return true;
    }
}


/**
 * Halaman registrasi yang akan ditampilkan ke user.
 */
void RegisterPage() {
    string id, name, password, confirmPassword;
    // bool isIdValid, isNameValid, isPasswordValid, isConfirmPasswordValid;

    cout << "=================" << endl;
    cout << "   Daftar Akun   " << endl;
    cout << "=================" << endl;
    cout << endl;

    id = inputString("Masukkan ID: ");
    name = inputString("Masukkan nama lengkap: ");
    password = inputPassword("Masukkan kata sandi: ");
    confirmPassword = inputPassword("Ulangi kata sandi: ");
    cout << endl;
    
    if (validateId(id) && 
        validateName(name) && 
        validatePassword(password) && 
        validateConfirmPassword(password, confirmPassword)) {

        bool success = registerUser(id, name, password);

        if (success) {
            cout << "Registrasi akun baru berhasil!" << endl;
            cout << "Silakan login dengan ID dan password yang sudah didaftarkan!" << endl;
            cout << endl;
            cout << "Tekan enter untuk kembali ke halaman login...";
            getch();
            navigate(&loginPage);
            return;
        }
    } 

    cout << "Registrasi gagal!" << endl;
    
    cout << endl;
    cout << "Tekan sembarang tombol untuk kembali ke halaman awal...";
    getch();
    navigate(&welcomePage);
}

#endif