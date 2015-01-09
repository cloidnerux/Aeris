/// orderdList.c
/// by cloidnerux

#include <system.h>

/// Initialisiert eine neue Liste und gibt einen Pointer auf ein orderdList Struct zurück.
/// \param SortationAlgorithm Eine Funktion die zwei Elemente vergeleicht und dementsprechend einen Wert zurückgibt.
/// \return Ein Pointer auf das Generietre orderdList Struct.
struct orderdList* InitOrderdList(int (*SortationAlgorithm)(void*, void*))
{
	struct orderdList* this = SimpleMalloc(sizeof(struct orderdList));
	this->header = SimpleMalloc(sizeof(struct orderdListHeader));
	/// hier dier Funtkionen Hizufügen
	this->GetElementByID = GetElementByID;
	this->GetElementByValue = GetElementByValue;
	this->GetIDByValue = GetIDByValue;
	this->InsertElement = InsertElement;
	this->DeleteElement = DeleteElement;
	this->DeleteElementByID = DeleteElementByID;
	this->header->firstElement = 0;
	this->header->lastElement = 0;
	this->header->SortationAlgorithm = SortationAlgorithm;
	this->header->elements = 0;
	return this;
}

/// Sucht den Eintrag mit dem Wert Value.
/// \param value Der Wert nach dem gesucht werden soll.
/// \param this Der Pointer zu dem Betreffenden orderdList struct.
/// \return Das orderdListElement das "value" enthält oder 0.
void* GetElementByValue(void* value, struct orderdList* this)
{
    struct orderdListElement* element = 0;
	if(value == 0)
	{
		return 0;
	}
	else
	{
	    element = this->header->firstElement;
	    while(this->header->SortationAlgorithm(value, element->value) != 0 && element != 0)
	    {
	        element = element->nextElement;
	    }
	}
	return element;
}

/// Sucht das Elemnt mit einer Entsprechenden ID.
/// \param id Die ID des Elements das gesucht werden soll.
/// \param this Der Pointer zu dem Betreffenden orderdList struct.
/// \return Das orderdListElement das "value" enthält oder 0.
void* GetElementByID(int id, struct orderdList* this)
{
    struct orderdListElement* element = 0;
    if(id > this->header->elements)
    {
        return 0;
    }
    else
    {
        element = this->header->firstElement;
	    while(element->id != id && element != 0)
	    {
	        element = element->nextElement;
	    }
    }
    return element;
}

/// Gibt die ID des ELments mit einem Bestimmten Wert an.
/// \param value Der Wert des Elments dessen ID man suchen soll.
/// \param this Der Pointer zu dem Betreffenden orderdList struct.
/// \return Die ID des Elments.
int GetIDByValue(void* value, struct orderdList* this)
{
    struct orderdListElement* element = 0;
	if(value == 0)
	{
		return -1;
	}
	else
	{
	    element = this->header->firstElement;
	    while(this->header->SortationAlgorithm(value, element->value) != 0 && element != 0)
	    {
	        element = element->nextElement;
	    }
	}
	if(element == 0)
	{
	    return -1;
    }
	return element->id;
}

/// Fügt ein Elment in die Liste ein.
/// \param value Den Wert die das Element haben soll.
/// \param this Der Pointer zu dem Betreffenden orderdList struct.
void InsertElement(void* value, struct orderdList* this)
{
    struct orderdListElement* element = 0;
    struct orderdListElement* tempElement = 0;
    if(this->header->elements == 0)
    {
        this->header->firstElement = SimpleMalloc(sizeof(struct orderdListElement));
        this->header->lastElement = this->header->firstElement;
        memset(this->header->firstElement, 0, sizeof(struct orderdListElement));
        this->header->firstElement->value = value;
        this->header->elements++;
    }
    else
    {
        element = SimpleMalloc(sizeof(struct orderdListElement));
        memset(element, 0, sizeof(struct orderdListElement));
        element->value = value;
        this->header->elements++;
        element->id = this->header->elements;
        tempElement = this->header->firstElement;
        while(this->header->SortationAlgorithm(element, tempElement) < 0 && tempElement != 0)
        {
            tempElement = tempElement->nextElement;
        }
        if(tempElement == 0)
        {
            return;
        }
        tempElement->previousElement->nextElement = element;
        tempElement->previousElement->nextElement->nextElement = tempElement;
        tempElement->previousElement->nextElement->previousElement = tempElement->previousElement;
        tempElement->previousElement = element;
    }
}

/// Löschte das Element mit dem Wert value.
/// \param value Den Wert des Elements.
/// \param this Der Pointer zu dem Betreffenden orderdList struct.
void DeleteElement(void* value, struct orderdList* this)
{
    struct orderdListElement* element;
    element = GetElementByValue(value, this);
    element->previousElement->nextElement = element->nextElement;
    element->nextElement->previousElement = element->previousElement;
    this->header->elements--;
}

/// Löschte das Element mit der ID id.
/// \param value Die ID des Elements.
/// \param this Der Pointer zu dem Betreffenden orderdList struct.
void DeleteElementByID(int id, struct orderdList* this)
{
    struct orderdListElement* element;
    element = GetElementByID(id, this);
    element->previousElement->nextElement = element->nextElement;
    element->nextElement->previousElement = element->previousElement;
    this->header->elements--;
}
