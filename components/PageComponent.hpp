#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>

using std::string;


/**
 * Tipe data ini digunakan untuk menyimpan informasi tentang halaman menu 
 * aplikasi.
 */
struct PageComponent {
    string name;                // Nama halaman
    void (*pageElementPointer)();      // Pointer menuju fungsi utk menampilkan halaman

    /**
     * Konstruktor PageComponent. Digunakan untuk membuat objek PageComponent baru. Pembuatan 
     * objek dilakukan di `main.cpp` karena aplikasi sudah diatur sedemikian
     * rupa agar komponen-komponen aplikasi lebih terstruktur dan mudah dicari.
     * 
     * @param name Nama halaman.
     * @param pageElementPointer Fungsi utk menampilkan halaman.
     */
    PageComponent(string name, void (*pageElementPointer)()) {
        this->name = name;
        this->pageElementPointer = pageElementPointer;
    }

    /**
     * Menampilkan halaman.
     */
    void renderPage() {
        this->pageElementPointer();
    }
};

#endif