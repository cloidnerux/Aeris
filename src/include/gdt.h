//gdt.h
//Heir werden alle Funktionen von gdt.c bereitgestellt
#ifndef GTD_H_
#define GDT_H_

#define BASE_0 0
#define LIMIT_4G 0xFFFFFFFF
#define SIZE_1K 0
#define SIZE_4K 0x80
#define OPERAND_SIZE_16 0
#define OPERAND_SIZE_32 0x40
#define SEG_LENGTH 0x0F

#define NON_PRESENT 0
#define PRESENT 0x80
#define RING_0 0
#define RING_3 0x60
#define DESKRIPTOR_TYPE_1 0x10
#define DESKRIPTOR_TYPE_0 0
#define TYPE_0 0
#define TYPE_CODE 0x0A
#define TYPE_DATA 0x02

struct gdtEntry
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed));

struct gdtPtr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));


void GDTInstall();
extern void GDTFlush();

#endif
