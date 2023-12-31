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
#include "./data/items.hpp"         // Daftar item yang dapat dibeli
#include "./pages/WelcomePage.hpp"  // Halaman awal aplikasi
#include "./pages/LoginPage.hpp"    // Halaman login
#include "./pages/RegisterPage.hpp" // Halaman register
#include "./pages/HomePage.hpp"     // Halaman home
#include "./pages/ShopPage.hpp"     // Halaman shop
#include "./pages/CheckoutPage.hpp" // Halaman checkout


//-----------------------------------------------------------------------------
// int main() berisi kode yang akan pertama kali dijalankan saat program
// dijalankan.
//-----------------------------------------------------------------------------

int main() {

    //-------------------------------------------------------------------------
    // Daftar item yang dapat user beli oleh user melalui aplikasi.
    //-------------------------------------------------------------------------
    // --> items.push(Item("nama", harga, "kategori"))
    //-------------------------------------------------------------------------

    items.push(Item("Mendoan", 1000, "Gorengan"));
    items.push(Item("Tahu", 1000, "Gorengan"));
    items.push(Item("Es Teh", 3000, "Minuman"));
    items.push(Item("Kopi", 4000, "Minuman"));

    //-------------------------------------------------------------------------
    // Daftar akun yang sudah terdaftar di aplikasi secara default untuk
    // keperluan testing.
    //-------------------------------------------------------------------------
    // --> registeredUsers.push(User*("username", "nama", "password")))
    //-------------------------------------------------------------------------

    registeredUsers.push(User("admin", "Miguel Harvey", "123456"));
    registeredUsers.push(User("alex", "Alexander Lloyd", "123456"));
    registeredUsers.push(User("peter", "Peter Wheeler", "123456"));

    //-------------------------------------------------------------------------
    // Komponen halaman yang sudah dideklarasikan di `routes.hpp` dan 
    // diimplementasikan di file .hpp-nya sendiri di folder `pages`  harus 
    // kemudian diinisialisasi disini.
    //-------------------------------------------------------------------------

    welcomePage = Page(&WelcomePage);
    loginPage = Page(&LoginPage);
    registerPage = Page(&RegisterPage);
    homePage = Page(&HomePage);
    shopPage = Page(&ShopPage);
    checkoutPage = Page(&CheckoutPage);

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
        currentPagePointer->loadPage();
        resetMenuChoice();
    }

    //-------------------------------------------------------------------------

    return 0;
}

//-----------------------------------------------------------------------------
