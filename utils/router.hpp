#ifndef USER_H
#define USER_H

#include <iostream>
#include "router.hpp"
#include "../components/Page.hpp"
#include "../utils/terminalHelper.hpp"

using std::cout;
using std::endl;


/**
 * Pointer menuju objek halaman yang sedang aktif.
 */
Page* currentPagePointer;


/**
 * Pindah ke halaman lain.
 * 
 * @param pagePointer Pointer menuju komponen halaman yang dituju.
 * 
 * @return `0` jika berhasil, `-1` jika gagal.
 */
int navigate(Page *pagePointer) {
    try {
        // Bersihkan layar
        clearScreen();

        // Tampilkan halaman yang dituju
        (*pagePointer).loadPage();

        // Ubah pointer halaman aktif menjadi pointer halaman dituju
        currentPagePointer = pagePointer;

        // Kembalikan 0 sebagai penanda operasi berhasil
        return 0;
    }

    // Jika terjadi error, tampilkan pesan error
    catch (const char* message) {
        cout << message << endl;

        // Kembalikan -1 sebagai penanda operasi gagal
        return -1;
    }
}


/**
 * Refresh halaman yang sedang aktif.
 */
void reloadPage() {
    currentPagePointer->loadPage();
}

#endif
