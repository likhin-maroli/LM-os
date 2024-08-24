#include "gdt.h"


// Declare the GDT entries and pointer
gdt_entry_t gdt_entries[3];
gdt_ptr_t gdt_ptr;

// Helper function to set a GDT entry
void gdt_set_entry(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity) {
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high = (base >> 24) & 0xFF;
    
    gdt_entries[num].limit_low = (limit & 0xFFFF);
    gdt_entries[num].granularity = ((limit >> 16) & 0x0F) | (granularity & 0xF0);
    
    gdt_entries[num].access = access;
}

// Function to install the GDT and update segment registers
void gdt_install() {
    gdt_ptr.limit = (sizeof(gdt_entry_t) * 3) - 1;
    gdt_ptr.base = (uint32_t)&gdt_entries;
    
    
    
    // Set up GDT entries
    gdt_set_entry(0, 0, 0, 0, 0);            // Null Descriptor
    gdt_set_entry(1, 0, 0xFFFFF, 0x9A, 0xCF); // Code Segment
    gdt_set_entry(2, 0, 0xFFFFF, 0x92, 0xCF); // Data Segment

    gdt_flush((uint32_t)&gdt_ptr);

    
}
