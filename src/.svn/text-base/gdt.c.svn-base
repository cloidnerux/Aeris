//gdt.c

//Defines um den Aufruf der Dunktion gdt_set_gate einfacher zu verstehen
#include "include/system.h"



struct gdtEntry gdt[3];
struct gdtPtr gp;

void GDTSetGate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void GDTInstall()
{
    Printk("Initialisiere GDT\n");
    gp.limit = (sizeof(struct gdtEntry) * 3) - 1;
    gp.base = (unsigned)&gdt;
	//NULL- Deskriptor
    Printk("   Initialisiere Null-Deskriptor\n");
    GDTSetGate(0, 0, 0, 0, 0);
	//CODE Deskriptor
    Printk("   Initialisiere Code-Deskriptor\n");
    GDTSetGate(1, 0, 0x000FFFFF, PRESENT | RING_0 | DESKRIPTOR_TYPE_1 | TYPE_CODE, SIZE_4K | OPERAND_SIZE_32 | SEG_LENGTH);
	//DATA Deskriptor
    Printk("   Initialisiere Data-Deskriptor\n");
    GDTSetGate(2, 0, 0x000FFFFF, PRESENT | RING_0 | DESKRIPTOR_TYPE_1 | TYPE_DATA, SIZE_4K | OPERAND_SIZE_32 | SEG_LENGTH);
	//GDT Einloggen
    Printk("   Lade GDT\n");
    GDTFlush();
}


