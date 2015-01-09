// dualOrderdList.h
// by Cloidnerx

#ifndef ORDERD_LIST_H
#define ORDERD_LIST_H

/// Ein Element der Liste.
struct orderdListElement
{
	u32int id;
	void* value;
	struct orderdListElement* nextElement;
	struct orderdListElement* previousElement;
}__attribute__((packed));

/// Der Header der Liste mit den Sortieralgorithmus und den Pointern auf die ersten Elemente.
/// Der Sortieralgorithmus muss für a > b 1 zurückgeben, für a == b 0 und für a < b -1;
struct orderdListHeader
{
	u32int elements;
	struct orderdListElement* firstElement;
	struct orderdListElement* lastElement;
	int (*SortationAlgorithm)(void*, void*);
}__attribute__((packed));

struct orderdList
{
	struct orderdListHeader* header;
	void* (*GetElementByValue)(void*, struct orderdList*);
	void* (*GetElementByID)(int, struct orderdList*);
	int (*GetIDByValue)(void*, struct orderdList*);
	void (*InsertElement)(void*, struct orderdList*);
	void (*DeleteElement)(void*, struct orderdList*);
	void (*DeleteElementByID)(int, struct orderdList*);
}__attribute__((packed));

void DeleteElementByID(int id, struct orderdList* this);
void DeleteElement(void* value, struct orderdList* this);
void InsertElement(void* value, struct orderdList* this);
int GetIDByValue(void* value, struct orderdList* this);
void* GetElementByID(int id, struct orderdList* this);
void* GetElementByValue(void* value, struct orderdList* this);
struct orderdList* InitOrderdList(int (*SortationAlgorithm)(void*, void*));

#endif

