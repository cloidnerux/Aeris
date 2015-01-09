// heap.c
// by cloidnerux

#include "include/system.h"

struct heap
{
	u32int startAddress;
	u32int endAddress;
	u32int maxSize;
	struct orderdList holes;
};

struct hole
{
	u32int startAddress;
	u32int size;
	u8int used;
};

extern void* allocSpace;

/// EIne Variable die SIgnalisiert das der Kernel Heap aktiviert ist.
u8int kernelHeap;

/// Gibt an welches von 2 strut holes das größere ist gemessen an der Größe.
/// \param hole1 Das erste "loch".
/// \param hole2 Das zweite "loch".
/// \return 1 für a > b, 0 für a == b und -1 für a < b.
int Sortieren(void* hole1, void* hole2)
{
	if(((struct hole*)hole1)->size < ((struct hole*)hole2)->size)
	{
		return -1;
	}
	else if(((struct hole*)hole1)->size == ((struct hole*)hole2)->size)
	{
		return 0;
	}
	return 1;

}

/// Initialisiert einen neuen Heap
/// \param startAddress die Startaddresse des Heaps + des zu Allokiernden Bereichs
struct heap* InitHeap(int startAddress, int endAddress)
{
	ASSERT((startAddress) & 0x1000 == 0);
	ASSERT((endAddress - startAddress) > 100);
	struct heap* newHeap = startAddress;
	struct hole* firstHole = startAddress + sizeof(struct heap);
	newHeap->startAddress = startAddress + sizeof(struct heap) + sizeof(struct hole);
	newHeap->endAddress = endAddress;
	newHeap->maxSize = endAddress - newHeap->startAddress;
	newHeap->holes = *(InitOrderdList(Sortieren));
	firstHole->startAddress = newHeap->startAddress;
	firstHole->size = endAddress - newHeap->startAddress;
	newHeap->holes->InsertElement(firstHole, newHeap->holes);
	return newHeap;
}

/// Sucht den kleinsten passenden speicherbereich.
/// \param kHeap Der heap in dem gesucht werden soll
/// \return Die Addresse des Speicherbereiches.
u32int FindSmalestHole(u32int size, struct heap* kHeap)
{
	u32int i;
	for(i = size; i < kHeap->maxSize + ; i++)
	{
		if(((struct hole*)(kHeap->holes.GetElementByValue(i, kHeap->holes)))->used == 0)
		{
			return ((struct hole*)(kHeap->holes.GetElementByValue(i, kHeap->holes)))->startAddress;
		}
	}
	return -1;
}

