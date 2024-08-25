ENTRY(_start)                /* The name of the entry label */

SECTIONS {
    . = 0x00100000;          /* The code should be loaded at 1 MB */

    .multiboot :
    {

        *(.multiboot)
    }

    .text ALIGN (0x1000) :   /* Align at 4 KB */
    {
        *(.text)             /* All text sections from all files */
    }


    .rodata :                /* For read only data */
    {
         *(.rodata)
    }


    .data :                  /* For data  */
    {
        *.(.data)
    }

    .bss :                   /* Uninitiated data */
    {
        sbss = .;            /* Start of the bss section */
        *(.bss)
        ebss = .;            /* End of bss section */
    }
}

