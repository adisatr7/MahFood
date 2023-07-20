#ifndef USER_H
#define USER_H

#include <iostream>
#include <ncurses.h>
#include "router.hpp"
#include "PageComponent.hpp"

using std::cout;
using std::endl;


/**
 * Pointer menuju objek halaman yang sedang aktif.
 */
PageComponent* currentPagePointer;


/**
 * Pindah ke halaman lain.
 * 
 * @param pageComponentPointer Pointer menuju komponen halaman yang dituju.
 * 
 * @return `0` jika berhasil, `-1` jika gagal.
 */
int navigate(PageComponent *pageComponentPointer) {
    try {
        // Bersihkan layar
        clear();

        // Ubah pointer manjadi objek PageComponent
        PageComponent pageComponent = *pageComponentPointer;

        // Tampilkan halaman yang dituju
        pageComponent.renderPage();

        // Ubah pointer halaman aktif menjadi pointer halaman dituju
        currentPagePointer = pageComponentPointer;

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

    // Bersihkan layar
    clear();

    // Tampilkan halaman yang sedang aktif
    currentPagePointer->renderPage();
}

#endif
