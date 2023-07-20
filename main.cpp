//=============================================================================
// > Kelompok __
//-----------------------------------------------------------------------------
// Anggota:
//  1. __________ (NIM: __________)
//  2. __________ (NIM: __________)
//  3. __________ (NIM: __________)
//=============================================================================

//-----------------------------------------------------------------------------
// # Import
//-----------------------------------------------------------------------------
// Import kode-kode dari file lain yang diperlukan.
//-----------------------------------------------------------------------------

#include "./global/states.hpp"      // Global variables
#include "./global/styles.hpp"      // Global styles
#include "./pages/WelcomePage.hpp"  // Semua halaman aplikasi
#include "./pages/LoginPage.hpp"    // Semua halaman aplikasi


//-----------------------------------------------------------------------------
// int main() berisi kode yang akan pertama kali dijalankan saat program
// dijalankan.
//-----------------------------------------------------------------------------

int main() {

    //-------------------------------------------------------------------------
    // Komponen halaman yang sudah dideklarasikan di `routes.hpp` dan 
    // diimplementasikan di file .hpp-nya sendiri di folder `pages`  harus 
    // kemudian diinisialisasi disini.
    //-------------------------------------------------------------------------

    welcomePage = Page(&WelcomePage);
    loginPage = Page(&LoginPage);

    //-------------------------------------------------------------------------
    // Tulis halaman yang ingin ditampilkan saat program pertama kali 
    // dijalankan disini.
    //-------------------------------------------------------------------------

    currentPagePointer = &welcomePage;

    //-------------------------------------------------------------------------
    // Selama `global::keepRunning` bernilai `true`, maka program akan terus
    // berjalan. Jika bernilai `false`, maka program akan berhenti/keluar.
    //-------------------------------------------------------------------------
    
    while (global::keepRunning) {
        navigate(currentPagePointer);
    }

    //-------------------------------------------------------------------------

    return 0;
}

//-----------------------------------------------------------------------------
