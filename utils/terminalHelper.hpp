#include <iostream>
// #include <termios.h>
#include <conio.h>
#include <unistd.h>

using std::cout;

#ifndef TERMINALHELPER_HPP
#define TERMINALHELPER_HPP


/**
 * Matikan mode kanonik dan echo pada terminal.
 */
// void __disableCanonicalMode() {
//     // Buat struct untuk menyimpan pengaturan terminal lama dan baru
//     struct termios oldSettings, newSettings;
    
//     // Dapatkan pengaturan terminal saat ini
//     tcgetattr(STDIN_FILENO, &oldSettings);
    
//     // Salin pengaturan terminal saat ini ke pengaturan baru
//     newSettings = oldSettings;
    
//     // Nonaktifkan mode kanonik dan echo untuk pembacaan karakter tunggal untuk sementara
//     newSettings.c_lflag &= ~(ICANON | ECHO);
    
//     // Atur pengaturan terminal baru
//     tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

//     // Bug fix agar tombol yang ditekan sebelumnya tidak ikut terbaca
//     newSettings.c_cc[VMIN] = 1;     // Set jumlah karakter minimum yang harus dibaca
//     newSettings.c_cc[VTIME] = 0;    // Set waktu tunggu pembacaan karakter
// }


/**
 * Aktifkan mode kanonik dan echo pada terminal.
 */
// void __enableCanonicalMode() {
//     // Buat struct untuk menyimpan pengaturan terminal lama dan baru
//     struct termios oldSettings, newSettings;
    
//     // Dapatkan pengaturan terminal saat ini
//     tcgetattr(STDIN_FILENO, &oldSettings);
    
//     // Salin pengaturan terminal saat ini ke pengaturan baru
//     newSettings = oldSettings;
    
//     // Aktifkan mode kanonik dan echo untuk pembacaan karakter tunggal untuk sementara
//     newSettings.c_lflag |= (ICANON | ECHO);
    
//     // Atur pengaturan terminal baru
//     tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
// }


/**
 * Menyembunyikan kursor terminal.
 */
void __disableCursor() {
    cout << "\033[?25l";
}


/**
 * Menampilkan kursor terminal.
 */
void __enableCursor() {
    cout << "\033[?25h";
}


/**
 * Menghandle input tombol keyboard dari user.
 * 
 * @return Karakter yang dimasukkan user dalam tipe data `int`.
 */
// int getch() {

//     // Matikan mode kanonik dan echo pada terminal
//     __disableCanonicalMode();

//     // Sembunyikan kursor terminal
//     __disableCursor();

//     // Variable untuk menyimpan karakter yang dimasukkan user
//     int ch;

//     // Baca karakter dari input tanpa menunggu Enter
//     ch = getchar();

//     // Tampilkan kursor terminal
//     __enableCursor();
    
//     // Kembalikan pengaturan terminal ke semula
//     __enableCanonicalMode();
    
//     // Kembalikan karakter yang dibaca
//     return ch;
// }


/**
 * Tipe data enum yang berisi tombol-tombol yang dapat ditekan user
 * untuk berinteraksi dengan menu aplikasi. Menggunakan enum karena
 * switch case tidak dapat digunakan dengan tipe data string.
 */
enum MenuKey {
    UP = 256 + 72,
    DOWN = 256 + 80,
    RIGHT = 256 + 77,
    LEFT = 256 + 75,
    ENTER = 256 + 13,
    INVALID
};

/**
 * Menghandle input tombol keyboard dari user.
 * 
 * @return Tombol yang dimasukkan user dalam tipe data `MenuKey`.
 */
MenuKey getMenuKeyPress() {
    // Variable untuk menyimpan karakter yang dimasukkan user
    int ch;

    // Baca karakter dari input tanpa menunggu Enter
    ch = getch();

    // Kembalikan karakter yang dibaca
    if ( ch == 0 || ch == 224 )
        ch = 256 + getch();

    return static_cast<MenuKey>(ch);
}


/**
 * Membersihkan layar terminal menggunakan ANSI escape code.
 */
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}


/**
 * Membersihkan baris terminal menggunakan ANSI escape code.
 */
void clearLine(int line = 1) {
    for (int i = 0; i < line * 2; i++) {
        cout << "\u001b[2K";
    }
}

#endif