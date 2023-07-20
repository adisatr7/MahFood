#ifndef TERMINALHELPER_HPP
#define TERMINALHELPER_HPP

#include <iostream>
#include <termios.h>
#include <unistd.h>


/**
 * Matikan mode kanonik dan echo pada terminal.
 */
void __disableCanonicalMode() {
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

    // Bug fix agar tombol yang ditekan sebelumnya tidak ikut terbaca
    newSettings.c_cc[VMIN] = 1;     // Set jumlah karakter minimum yang harus dibaca
    newSettings.c_cc[VTIME] = 0;    // Set waktu tunggu pembacaan karakter
}


/**
 * Aktifkan mode kanonik dan echo pada terminal.
 */
void __enableCanonicalMode() {
    // Buat struct untuk menyimpan pengaturan terminal lama dan baru
    struct termios oldSettings, newSettings;
    
    // Dapatkan pengaturan terminal saat ini
    tcgetattr(STDIN_FILENO, &oldSettings);
    
    // Salin pengaturan terminal saat ini ke pengaturan baru
    newSettings = oldSettings;
    
    // Aktifkan mode kanonik dan echo untuk pembacaan karakter tunggal untuk sementara
    newSettings.c_lflag |= (ICANON | ECHO);
    
    // Atur pengaturan terminal baru
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}


/**
 * Menghandle input tombol keyboard dari user.
 * 
 * @return Karakter yang dimasukkan user dalam tipe data `char`.
 */
int getch() {

    // Matikan mode kanonik dan echo pada terminal
    __disableCanonicalMode();

    // Variable untuk menyimpan karakter yang dimasukkan user
    int ch;

    // Baca karakter dari input tanpa menunggu Enter
    ch = getchar();
    
    // Kembalikan pengaturan terminal ke semula
    __enableCanonicalMode();
    // tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    
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