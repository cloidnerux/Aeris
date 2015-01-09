//memory.c
//by cloidnerux
//stellt die Speicherverwaltungsfunktionen zur verfügung

#include "include/system.h"


/// <summary>
/// Ein Pointer, der an das Ende des Kernels gestzt wird und die Reele Belgung des Speicher enthält
/// Dabei wird der Speicher in 4LB Blöcke ,genannt Frames, unterteilt
/// $KB desswegen, das man später einfach eine Page allokieren kann
/// </summary>
u32int *memoryBitmap;
/// <summary>
/// Die größe der Bitmap, ist für die verwaltung von Dynamischen Speicher wichtig
/// </summary>
u32int bitmapSize;
/// <summary>
/// Der Index eines freien Frame
/// Wird durch die Dealokierung gesetzt
/// </summary>
u32int freeFrame;
/// Ein Speicherbereich hinter dem Kenrel um dort Speicher zu allokieren.
void* allocSpace = (void*)0x100000;

extern u8int kernelHeap;

/// Allokiert einen Bestimmten Speicherbereich der 4K-page Aligned sein muss
/// Es werden immer 4K allokiert.
/// \return Ein Pointer auf den Anfang des Speicherbereichs
void* AllocPageAlignedRam()
{
	u32int tempMemPointer;
	tempMemPointer = AllocFrame();
	if((((u32int)tempMemPointer % 0x1000) != 0) && ((u32int)tempMemPointer == ALLOC_ERROR))
	{
		return (void*)ALLOC_ERROR;
	}
	return (void*)tempMemPointer;
}

/// Allokiert auf Simple Weise Speicher und gibt die Startaddresse zurück.
/// \param size Die Größe das zu Allokierenden Speichers
/// \return Ein Pointer auf den Anfangsbereich das Speichers.
void* SimpleMalloc(u32int size)
{
	if(!kernelHeap)
	{
		if(size == 0)
		{
			return (void*)ALLOC_ERROR;
		}
		void* tempPointer;
		tempPointer = allocSpace;
		allocSpace += size;
		return tempPointer;
	}
	return malloc(size);
}

/// Gibt einen Pointer auf einen freien Speicherbereich zurück.
/// \param size Die Größe des Speicherbereichs
/// \return Ein Pointer zum Anfang des Speicherbereichs
void* SimpleMalloc(u32int size)
{
	if(size == 0)
	{
		return (void*)ALLOC_ERROR;
	}
	void* speicher = allocSpace;
	allocSpace += size;
	return speicher;
}

/// Durchsucht die memoryBitmap solange bis sie einen Freien Frame gefunden hat.
/// \return Der index eines freien Frames
u32int FindFreeFrame()
{
	u32int index;
	u32int i,a;
	if(freeFrame != -1)
	{
		index = freeFrame;
		freeFrame = -1;
		return index;
	}
	else
	{
		for(i = 0; i < bitmapSize; i++)
		{
			if(memoryBitmap[i] != 0xffffffff)
			{
				index = i * 32;
				for(a = 0; a < sizeof(u32int); a++)
				{
					if(!(memoryBitmap[i] & (1 << a)))
					{
						index += a;
						return index;
					}
				}
			}
		}
	}
	return NO_FREE_FRAME;
}

/// Allokiert den Frame an der Adresse "addresse".
/// \param Die Addresse die Allokiert werden soll
/// \return Gibt die Addresse des Allkoierten frames zurück
u32int AllocFrame()
{
	u32int index;
	index = FindFreeFrame();
	if(index == NO_FREE_FRAME)
	{
		return ALLOC_ERROR;
	}
	memoryBitmap[index / 32] |= 1 << (index % 32);
	return (index * 4096);
}

/// Deallokiert einen Frame wieder.
/// \param addresse Die speicheraddresse des zu dealokierenden Bereichs
void DeAllocFrame(u32int addresse)
{
	u32int index;
	index = addresse / 4096;
	freeFrame = index;
	memoryBitmap[index / 32] &= ~(1 << (index % 32));
}

/// Initalisiert die Physische Speicherverwaltung .
/// \param kernelEnd Eine Speicheraddresse die am Ende des vom Kenrel genutzen Rams liegt
/// \param memorySize Die speichergröße in MB
void InitMemoryBitmap(u32int* kernelEnd, u32int memorySize)
{
	Printk("Init Memory Bitmap\n");
	u32int i;
	freeFrame = -1;
	//Die Bitmap anlegen und auf 0 Initialisieren
	memoryBitmap = (u32int*)kernelEnd + 10;
	bitmapSize = memorySize / 4;
	PrintDebug("   setting the Memory Bitmap to 0\n");
	Printf("   Groesse Speicher: %d\n", memorySize);
	Printf("   Groesse Bitmap: %d\n", bitmapSize);
	for(i=0; i < bitmapSize; i++)
	{
		memoryBitmap[i] = 0;
	}
	PrintDebug("   done\n");
	// Den Bereich den der Kernel, Grub und die Bitmap an sich verbrauchen als belegt markieren.
	memoryBitmap[0] = ((((u32int)kernelEnd / 1024) / 4) + 1) | 0x01;
	freeFrame = FindFreeFrame();
	PrintSuccessful("   Done\n");
}

/// <summary>
/// Die PageDirectory des Kernels
/// </summary>
u32int *kernelPageDirectory;
/// <summary>
/// Die aktuell benutze Page Directory, wird für Multitasking benötigt.
/// </sumary>
u32int *currentPageDirectory;

/// Initialisiert Paging
/// \param kernelEnd Das Ende des vom Kernel genutzen Rams,
/// wird benötigt um alle vom Kenrel benutzen Speicherbereiche zu Allkoieren.
void InitPaging(u32int *kernelEnd)
{
	Printk("Initialisiere Paging\n");
	u32int i;
	u32int *tempPageTable;

	//Speicher Reservieren
	kernelPageDirectory = (u32int*)AllocPageAlignedRam();
	kernelPageDirectory = (u32int*)AllocPageAlignedRam();
	ASSERT(((u32int)kernelPageDirectory % 0x1000) == 0);
	tempPageTable = (u32int*)AllocPageAlignedRam();
	memset(kernelPageDirectory, 0, 0x1000);
	memset(tempPageTable, 0, 0x1000);

	Printf("   Addresse Page Directory: %d\n", kernelPageDirectory);
	Printf("   Addresse Page table: %d\n", tempPageTable);
	for(i = 0; i < 1024; i++)
	{
		tempPageTable[i] = (i * 4096) | 3;
		ASSERT(tempPageTable[i] != 0);
	}
	kernelPageDirectory[0] = ((u32int)tempPageTable | PPRESENT | PWRITE | PKERNEL_ACCESS);
	for( i = 1; i< 1024; i++)
	{
		kernelPageDirectory[i] = PKERNEL_ACCESS | PWRITE;
	}
	kernelPageDirectory[1023] = ((u32int)kernelPageDirectory | PPRESENT | PWRITE | PKERNEL_ACCESS);

	Printk("   Aktivieren\n");
	ASSERT(tempPageTable[0] != 0);
	ASSERT(kernelPageDirectory[0] != 0);

	SwitchPageDirectory(kernelPageDirectory);
	PrintSuccessful("   Done\n");
}

/// Wechelt zu der anegegeben PageDirectory
/// \param pageDirectory ein Pointer zu der neuen Page Directory
void SwitchPageDirectory(u32int *pageDirectory)
{
	currentPageDirectory = pageDirectory;
	WriteCR3((u32int)currentPageDirectory);
	WriteCR0(ReadCR0() | 0x80000000);
}

/// Gibt den Pointer zu der entsprechenden Page unter Addresse zurück.
/// \param addresse Die Virtuele Addresse auf die die Page verweißt.
/// \param make Wenn die Pagetable nihct exsitiert, anlegen?.
/// \param pageDirectory Die Aktuelle Page Directory.
/// \return Gibt den Pointer der entsprechenden Page zurück oder 0 für fehler.
u32int* GetPage(u32int addresse, char make, u32int* pageDirectory)
{
	int index = addresse / 0x1000;
	u32int* tempPageTable = 0;
	u32int flags;
	if(pageDirectory[index / 1024] != 0)
	{
		tempPageTable = (u32int*)(pageDirectory[index / 1024] & ~0xfff);
		if(tempPageTable[index % 1024] != 0)
		{
			return (u32int*)tempPageTable[index % 1024];
		}
		else if(make == 1)
		{
			flags = tempPageTable[index % 1024 - 1] & 0xfff;
			tempPageTable[index % 1024] = addresse | flags;
			return (u32int*)tempPageTable[index % 1024];
		}
	}
	else if(make == TRUE)
	{
		tempPageTable = AllocPageAlignedRam();
		memset(tempPageTable, 0, 1024 * sizeof(u32int));
		tempPageTable[0] = (u32int)tempPageTable | PPRESENT | PWRITE | PUSER_ACCESS;
		flags = pageDirectory[index / 1024 - 1] & 0xFFF;
		pageDirectory[index / 1024] = (u32int)tempPageTable | flags;
		tempPageTable[index % 1024] = addresse | flags;
		return (u32int*)tempPageTable[index % 1024];
	}
	return 0;
}

/// Der Page Fault Handler zum behandeln von Page Faults.
/// \param r Ein Struct mit Informationen über Interrupt und Register zustand.
void PageFaultHandler(struct regs *r)
{
	int faultingAddress = 0;
	faultingAddress = ReadCR2();
	Printf("Page fault: %s %s %s %s", (r->err_code & 0x1)?(""):("Not Present"),
									  (r->err_code & 0x2)?(""):("No Write Access"),
									  (r->err_code & 0x4)?(""):("Wrong Access mode"),
									  (r->err_code & 0x8)?(""):("Bit Violation"));
	Printf(" at %x\n", faultingAddress);
	for(;;);
}
