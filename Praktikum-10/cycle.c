#include "cycle.h"
#include "listlinier.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * I.S. List l terdefinisi
 * F.S. Mengembalikan address node yang merupakan entrypoint dari cycle
 * Jika tidak ada cycle, kembalikan NULL
 */
Address findCycleEntryPoint(List l) {
    // Jika list kosong atau hanya ada satu elemen
    if (l == NULL || NEXT(l) == NULL) {
        return NULL;
    }
    
    // Phase 1: Deteksi apakah ada cycle menggunakan Floyd's Algorithm
    Address slow = l;
    Address fast = l;
    bool hasCycle = false;
    
    // Tortoise and Hare algorithm
    while (fast != NULL && NEXT(fast) != NULL) {
        slow = NEXT(slow);
        fast = NEXT(NEXT(fast));
        
        // Jika slow dan fast bertemu, ada cycle
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    
    // Jika tidak ada cycle
    if (!hasCycle) {
        return NULL;
    }
    
    // Phase 2: Mencari entry point dari cycle
    // Reset slow ke head, biarkan fast di meeting point
    slow = l;
    
    // Gerakkan kedua pointer dengan kecepatan sama
    // Mereka akan bertemu di entry point cycle
    while (slow != fast) {
        slow = NEXT(slow);
        fast = NEXT(fast);
    }
    
    // slow (atau fast) sekarang menunjuk ke entry point cycle
    return slow;
}