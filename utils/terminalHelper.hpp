#ifndef TERMINALHELPER_HPP
#define TERMINALHELPER_HPP

#include <iostream>
#include <termios.h>
#include <unistd.h>


/**
 * Menghandle input tombol keyboard dari user.
 * 
 * @return Karakter yang dimasukkan user dalam tipe data `char`.
 */
char getch() {

    // Variable untuk menyimpan karakter yang dimasukkan user
    char ch;

    // Buat struct untuk menyimpan pengaturan terminal lama dan baru
    struct termios oldSettings, newSettings;
    
    // Dapatkan pengaturan terminal saat ini
    tcgetattr(STDIN_FILENO, &oldSettings);
    
    // Salin pengaturan terminal saat ini ke pengaturan baru
    newSettings = oldSettings;
    
    // Nonaktifkan mode kanonik dan echo untuk pembacaan karakter tunggal untuk sementara
    newSettings.c_lflag &= ~(ICANON | ECHO);
    
    // Atur pengaturan terminal baru
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    // Baca karakter dari input tanpa menunggu Enter
    ch = getchar();
    
    // Kembalikan pengaturan terminal ke semula
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    
    // Kembalikan karakter yang dibaca
    return ch;
}


/**
 * Menghandle input tombol keyboard dari user.
 * 
 * @return Karakter yang dimasukkan user dalam tipe data `int`.
 */
int getKeyPress() {
    return getch();
}


/**
 * Membersihkan layar terminal menggunakan ANSI escape code.
 */
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

#endif