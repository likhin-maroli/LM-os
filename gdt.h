// gdt.h
#ifndef GDT_H
#define GDT_H

#include <stdint.h>

// GDT Entry Structure
typedef struct {
    uint16_t limit_low;    // Lower 16 bits of the segment limit
    uint16_t base_low;     // Lower 16 bits of the base address
    uint8_t  base_middle;  // Middle 8 bits of the base address
    uint8_t  access;       // Access flags
    uint8_t  granularity;  // Granularity and upper 4 bits of segment limit
    uint8_t  base_high;    // Upper 8 bits of the base address
} __attribute__((packed)) gdt_entry_t;

// GDT Pointer Structure
typedef struct {
    uint16_t limit;         // Size of the GDT in bytes
    uint32_t base;          // Base address of the GDT
} __attribute__((packed)) gdt_ptr_t;

// Function prototypes
void gdt_install();
void gdt_flush();

#endif // GDT_H
