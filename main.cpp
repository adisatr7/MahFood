//=============================================================================
// > Program Utama
//----------------------------------------------------------------------------
// File program utama. Untuk menjalankan program, cukup jalankan file ini.
// Abaikan semua file lainnya yang berada di dalam subfolder. Adapun file
// config.hpp yang terletak berdampingan dengan main.cpp ini yang dapat
// Anda cek dan ubah isinya sesuai kebutuhan.
//=============================================================================

//----------------------------------------------------------------------------
// # Import
//----------------------------------------------------------------------------
// Import kode-kode dari file lain yang diperlukan.
//----------------------------------------------------------------------------

#include "./components/PageComponent.hpp"
#include "./pages/LoginPage.hpp"


//----------------------------------------------------------------------------
// # Page Components
//----------------------------------------------------------------------------
// Deklarasikan objek PageComponent yang terdapat di dalam program ini
// disini.
//----------------------------------------------------------------------------

PageComponent loginPage = PageComponent("Login", LoginPage);


//----------------------------------------------------------------------------
// int main() berisi halaman yang pertama kali ditampilkan kepada user
// ketika program dijalankan. Ubah seesuka hati, tetapi jangan sentuh
// bagian `renderPage()`-nya!
//----------------------------------------------------------------------------

int main() {
    loginPage.renderPage();

    return 0;
}

//----------------------------------------------------------------------------
