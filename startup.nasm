
section .multiboot              ; startup code for multiboot kernel


MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; calculate the checksum
                                ; (magic number + checksum + flags should equal 0)


multiboot_header:
             
align 4                         ; the code must be 4 byte aligned
    dd MAGIC_NUMBER             ; write the magic number to the machine code,
    dd FLAGS                    ; the flags,
    dd CHECKSUM                 ; and the checksum


section .text
global _start
_start:
    mov esp, statck_top          ; setup stack
    extern kernel_main
    call kernel_main             ; jump to kernel_main()

halt:
    cli
    hlt 
    jmp halt

section .bss
    align 16
    stack_top:
        resb 1024*1024            ;1MB memory allocation for stack
    stack_bottom:


    


