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
    return id.length() < 2 && id.length() > 20;
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
    return password.length() < 5 && password.length() > 20;
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
    return password != confirmPassword;
}


/**
 * Halaman registrasi yang akan ditampilkan ke user.
 */
void RegisterPage() {
    string id, name, password, confirmPassword;
    bool isIdValid, isNameValid, isPasswordValid, isConfirmPasswordValid;

    cout << "=================" << endl;
    cout << "   Daftar Akun   " << endl;
    cout << "=================" << endl;
    cout << endl;

    id = inputString("Masukkan ID: ");
    isIdValid = validateId(id);

    name = inputString("Masukkan nama lengkap: ");
    isNameValid = validateName(name);

    password = inputPassword("Masukkan kata sandi: ");
    isPasswordValid = validatePassword(password);

    confirmPassword = inputPassword("Ulangi kata sandi: ");
    isConfirmPasswordValid = validateConfirmPassword(password, confirmPassword);

    
    if (isIdValid && isNameValid && isPasswordValid && isConfirmPasswordValid) {
        bool success = registerUser(id, name, password);

        if (success) {
            cout << endl;
            cout << "Register berhasil!" << endl;
            cout << "Silakan login dengan id dan password yang sudah didaftarkan!" << endl;
            cout << endl;
            cout << "Tekan enter untuk kembali ke halaman login...";
            getch();
            navigate(&loginPage);
            return;
        }
    } 
    
    cout << endl;
    cout << "Registrasi gagal!" << endl;
    cout << endl;
    cout << "Tekan sembarang tombol untuk kembali ke halaman awal...";
    getch();
    navigate(&welcomePage);
}

#endif