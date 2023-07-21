#include <iostream>
#include "inputHandler.hpp"
// #include "router.hpp"
#include "terminalHelper.hpp"
#include "../config.hpp"
#include "../components/LinkedList.hpp"

using std::cout;
using std::endl;
using std::string;

#ifndef MENUSELECT_HPP
#define MENUSELECT_HPP


/**
 * Pilihan yang dipilih oleh user. Nilai awalnya adalah 0.
*/
int menuChoice = 0;

/**
 * Daftar pilihan yang dapat dipilih oleh user dan diproses oleh
 * menuSelect()
 */
LinkedList<string> options = LinkedList<string>();

/**
 * Memungkinkan user untuk memilih opsi dari daftar opsi yang diberikan
 * menggunakan tombol tanda panah di keyboard.
 */
void menuSelect() {

    // Variable utk menentukan kapan loop berhenti
    MenuKey key;

    // Cetak semua opsi
    for (int i = 0; i < options.length(); i++) {

        // Style utk opsi yang dipilih
        if (i == menuChoice) {
            cout << STYLE::HIGHLIGHT << options.get(i) << STYLE::RESET << endl;
        } 
        
        // Style utk opsi-opsi lain
        else {
            cout << options.get(i) << endl;
        }
    }

    // Menerima input tombol keyboard dari user
    key = getMenuKeyPress();

    // Handle inputan user
    if (key == UP && menuChoice > 0) {
        (menuChoice)--;
    } else if (key == DOWN && menuChoice < options.length() - 1) {
        (menuChoice)++;
    } else if (key == ENTER) {
        resetMenuChoice();
        return;
    }

    // Muat ulang halaman  agar menu menampilkan opsi yg sekarang dipilih
    options.clear();
    reloadPage();
}

/**
 * Setel ulang pilihan menuChoice menjadi 0 dan menghapus semua opsi.
 */
void resetMenuChoice() {
    menuChoice = 0;
    options.clear();
}

#endif