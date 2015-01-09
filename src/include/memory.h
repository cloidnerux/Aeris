//memory.h
//by cloidnerux
//Paging -> Speicherschutz

#ifndef MEMORY_H_
#define MEMORY_H_

#define PAGE_SIZE 0x1000
#define FRAME_SIZE 0x1000

///einige Fehler-defines
#define NO_FREE_FRAME -1
#define NO_FREE_PAGE -1
#define ALLOC_ERROR -1

///wichtige BITS in der pageDir oder pageTable
///Das P steht für Paging
#define PPRESENT 0x01
#define PWRITE 0x02
#define PUSER_ACCESS 0x04
#define PKERNEL_ACCESS 0

///unwichtigere Bits
#define PWRITE_THROUGH_CACHING 0x08
#define PNOCACHE 0x10
#define PCPU_ACCESS 0x20
#define PSIZE_4MB 0x40

#define NO 0
#define YES 1

struct pageDirStruct
{
	u32int present:1;
	u32int write:1;
	u32int usermode:1;
	u32int cache:1;
	u32int noCache:1;
	u32int accessed:1;
	u32int zero:1;
	u32int size:1;
	u32int ignore:1;
	u32int optoins:3;
	u32int pageTable:20;
}__attribute__((packed));

struct pageTableStruct
{
	u32int present:1;
	u32int write:1;
	u32int usermode:1;
	u32int cache:1;
	u32int noCache:1;
	u32int accessed:1;
	u32int writed:1;
	u32int zero:1;
	u32int noTLBRefresh:1;
	u32int optoins:3;
	u32int frame:20;
}__attribute__((packed));

void InitMemoryBitmap(u32int* kernelEnd, u32int memorySize);
void InitPaging(u32int *kernelEnd);
u32int AllocFrame();
void SwitchPageDirectory(u32int *pageDirectory);
void PageFaultHandler(struct regs *r);
void* SimpleMalloc(u32int size);
void* SimpleMalloc(u32int size);

extern int ReadCR0();
extern void WriteCR0(int value);
extern int ReadCR3();
extern void WriteCR3(int value);
extern int ReadCR2();
extern void WriteCR2(int value);

///
///invalidiert den TLB
///ist nötig um beim wecheln der pagdir Fehler zu vermeiden
///
//extern void InvalidateTLB(int address);

#endif
