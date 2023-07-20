#include <iostream>
#include <ncurses.h>
#include "router.hpp"

using std::cout;
using std::endl;


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


void reloadPage() {
    // Bersihkan layar
    clear();

    // Tampilkan halaman yang sedang aktif
    currentPagePointer->renderPage();
}