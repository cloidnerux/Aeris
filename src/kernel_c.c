//kernel_c.c
//Hauptdatei des Kernels

#include "include/system.h"



int main(unsigned int *multiboot_struct_adress) 
{
	//unsigned int mem_low=multiboot_struct_adress[1];
	unsigned int mem_max=multiboot_struct_adress[2];
	Init(&mem_max);
	Printf("Es Laeuft, aber ohne Speicherverwaltung wird das nichts\n");
	Console();
	for(;;);
	return 0;
}
