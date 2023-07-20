#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>
#include "../utils/terminalHelper.hpp"

using std::string;


/**
 * Komponen halaman aplikasi. Berisi pointer menuju fungsi untuk menampilkan halaman
 * atau menu tertentu ke layar.
 */
struct Page {

    /** 
     * Pointer menuju fungsi yang akan ditampilkan ke layar.
     */
    void (*pageElement)();

    /**
     * Konstruktor untuk membuat objek Page.
     * 
     * @param pageElement Pointer menuju fungsi yang akan ditampilkan ke layar.
     */
    Page(void (*pageElement)()) {
        this->pageElement = pageElement;
    }

    /**
     * Konstruktor kosong untuk membuat objek Page placeholder atau forward declaration.
     */
    Page() {}

    /**
     * Menampilkan halaman ke layar.
     */
    void loadPage() {
        clearScreen();
        this->pageElement();
    }
};

#endif