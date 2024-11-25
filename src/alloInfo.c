#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void address_info(void *addr) {
    uint64_t virtual_address = (uint64_t)addr;

    
    uint64_t PML4_index = (virtual_address >> 39) & 0x1FF; // Bits 39–47
    uint64_t PDP_index = (virtual_address >> 30) & 0x1FF;  // Bits 30–38
    uint64_t PD_index = (virtual_address >> 21) & 0x1FF;   // Bits 21–29
    uint64_t PT_index = (virtual_address >> 12) & 0x1FF;   // Bits 12–20
    uint64_t page_offset = virtual_address & 0xFFF;        // Bits 0–11

    
    printf("Virtual Address: 0x%lx\n", virtual_address);
    printf("Index into PML4: 0x%lx (%lu)\n", PML4_index, PML4_index);
    printf("Index into PDP:  0x%lx (%lu)\n", PDP_index, PDP_index);
    printf("Index into PD:   0x%lx (%lu)\n", PD_index, PD_index);
    printf("Index into PT:   0x%lx (%lu)\n", PT_index, PT_index);
    printf("Page Offset:     0x%lx (%lu)\n", page_offset, page_offset);
}


