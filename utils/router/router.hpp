#ifndef USER_H
#define USER_H

#include "PageComponent.hpp"


/**
 * Pointer menuju objek halaman yang sedang aktif.
 */
PageComponent* currentPagePointer;

/**
 * Pindah ke halaman lain.
 * 
 * @param pageComponentPointer Pointer menuju komponen halaman yang dituju.
 * 
 * @return `0` jika berhasil, `-1` jika gagal.
 */
int navigate(PageComponent *pageComponentPointer);

#endif
