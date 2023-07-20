//=============================================================================
// > Kelompok __
//----------------------------------------------------------------------------
// Anggota:
//  1. __________ (NIM: __________)
//  2. __________ (NIM: __________)
//  3. __________ (NIM: __________)
//=============================================================================

//----------------------------------------------------------------------------
// # Import
//----------------------------------------------------------------------------
// Import kode-kode dari file lain yang diperlukan.
//----------------------------------------------------------------------------

#include "./global/states.hpp"              // Global variables
#include "./utils/router.hpp"               // Untuk navigasi antar halaman
#include "./components/PageComponent.hpp"   // Komponen halaman aplikasi
#include "./pages/LoginPage.hpp"            // Halaman login


//----------------------------------------------------------------------------
// # Page Components
//----------------------------------------------------------------------------
// Deklarasikan objek PageComponent yang terdapat di dalam program ini
// disini.
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// # Page Components
//----------------------------------------------------------------------------
// Deklarasikan objek PageComponent yang terdapat di dalam program ini
// disini.
//----------------------------------------------------------------------------

PageComponent loginPage = PageComponent("Login", &LoginPage);


//----------------------------------------------------------------------------
// int main() berisi kode yang akan pertama kali dijalankan saat program
// dijalankan.
//----------------------------------------------------------------------------

int main() {
    do {

        //---------------------------------------------------------------------
        // Tulis halaman yang ingin ditampilkan saat program pertama kali 
        // dijalankan disini.
        //---------------------------------------------------------------------

        navigate(&loginPage);

    //-------------------------------------------------------------------------
    // Selama `global::keepRunning` bernilai `true`, maka program akan terus
    // berjalan. Jika bernilai `false`, maka program akan berhenti/keluar.
    //-------------------------------------------------------------------------

    } while (global::keepRunning);

    //-------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------
