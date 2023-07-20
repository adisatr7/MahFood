#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <iostream>
#include "router.hpp"
#include "../utils/terminalHelper.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::getline;     // TODO: Implement this <-
using std::invalid_argument;
using std::string;


/**
 * Meminta input string dari user.
 * 
 * @param prompt Pesan yang akan ditampilkan sebelum meminta input dari user.
 * 
 * @return string yang dimasukkan user.
 */
string inputString(string prompt) {

    // Variable untuk menyimpan input user
    string input;

    // Tampilkan pesan yang meminta user memasukan sesuatu
    cout << prompt;

    // Reset buffer cin utk mencegah bug inputan sebelumnya ikut terbaca
    cin.ignore();

    // Minta input user
    getline(cin, input);

    // Kembalikan inputan user sebagai tipe data string
    return input;
}


/**
 * Meminta input bilangan bulat dari user. Jika input yang dimasukkan bukan integer, maka akan
 * meminta input ulang dari user.
 * 
 * @param prompt Pesan yang akan ditampilkan sebelum meminta input dari user.
 * 
 * @return integer yang dimasukkan user.
 */
int inputInteger(string prompt) {
    
    // Ulangi terus menerus sampai input yang dimasukkan adalah bilangan bulat
    while (true) {

        // Minta input user. Utk menghindari error, input disimpan dalam string utk sementara
        string input = inputString(prompt);

        // Coba konversi string ke integer. Jika berhasil, return integer tersebut
        try {
            return stoi(input);
        } 
        
        // Jika gagal, berarti input yang dimasukkan bukan bilangan bulat. Tampilkan pesan error
        catch (invalid_argument) {
            cout << "Input yang dimasukkan bukan bilangan bulat. Silakan coba lagi." << endl;
        }
    }
}


/**
 * Menerima input tombol keyboard dari user.
 * 
 * @param prompt Pesan yang akan ditampilkan sebelum meminta input dari user.
 * 
 * @return karakter yang dimasukkan user.
 */
char keyPress(string prompt) {
    cout << prompt;
    return getch();
}


/**
 * Handles menu selection with arrow keys and enter key
 * 
 * @param options Array of options
 * @param length Length of options array
 * @param choice Selected option
 * 
 * @return Selected option
 */
int menuSelect(string options[], int length) {

    int choice = 0;     // Variable utk  menyimpan pilihan user
    MenuKey key;        // Variable utk menentukan kapan loop berhenti

    // Ulangi hingga user menekan tombol Enter
    while (key != ENTER) {

        // Cetak semua opsi
        for (int i = 0; i < length; i++) {

            // Style utk opsi yang dipilih
            if (i == choice) {
                cout << STYLE::HIGHLIGHT << options[i] << STYLE::RESET << endl;
            } 
            
            // Style utk opsi-opsi lain
            else {
                cout << options[i] << endl;
            }
        }

        // Menerima input tombol keyboard dari user
        key = getMenuKeyPress();

        // Handle inputan user
        if (key == UP && choice > 0) {
            choice--;
        } else if (key == DOWN && choice < length - 1) {
            choice++;
        }
        reloadPage();
    }
    return choice;
}

#endif
