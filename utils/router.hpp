#include "../pages/routes.hpp"
#include "../utils/terminalHelper.hpp"

#ifndef USER_H
#define USER_H


/**
 * Pointer menuju objek halaman yang sedang aktif.
 */
Page* currentPagePointer;


/**
 * Pindah ke halaman lain.
 * 
 * @param newPagePointer Pointer menuju komponen halaman yang dituju.
 * 
 * @return `0` jika berhasil, `-1` jika gagal.
 */
int navigate(Page *newPagePointer) {
    try {
        // Ubah pointer halaman aktif menjadi pointer halaman dituju
        currentPagePointer = newPagePointer;

        // Bersihkan layar
        clearScreen();

        // Tampilkan halaman yang dituju
        // (*newPagePointer).loadPage();

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
