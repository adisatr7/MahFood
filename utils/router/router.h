#ifndef USER_H
#define USER_H


/**
 * Status aplikasi sedang membuka halaman apa
 */
enum currentPage {
    
};

/**
 * Pindah ke halaman lain.
 * 
 * @param page Fungsi yang akan dipanggil ketika pindah ke halaman lain.
 * @return `0` jika berhasil, `-1` jika gagal.
 */
int navigate(void (*page)());

#endif