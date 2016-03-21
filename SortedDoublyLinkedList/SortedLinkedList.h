//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 12-2

/** ADT sorted list: Link-based implementation.
 @file SortedLinkedList.h */

#ifndef _SORTED_LINKED_LIST_H
#define _SORTED_LINKED_LIST_H

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SortedLinkedList : public SortedListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain
   Node<ItemType>* tailPtr; // Pointer to last node in the chain
   int itemCount;           // Current count of list items
   
   // Locates the node that is before the node that should or does
   // contain the given entry.
   // @param anEntry  The entry to find.
   // @return  Either a pointer to the node before the node that contains
   //    or should contain the given entry, or nullptr if no prior node exists.
   Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;
   
   // Locates the node at a given position within the chain.
   Node<ItemType>* getNodeAt(int position) const;
   
   // Returns a pointer to a copy of the chain to which origChainPtr points.
   Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);
   
   // Returns the tail pointer via iteration; not meant to be used after initialization
   Node<ItemType>* iterateToTailPointer();

public:
   SortedLinkedList();
   SortedLinkedList(const SortedLinkedList<ItemType>& aList);
   virtual ~SortedLinkedList();   

   void insertSorted(const ItemType& newEntry);
   bool removeSorted(const ItemType& anEntry);
   int getPosition(const ItemType& newEntry) const;
   
   // The following methods are the same as given in ListInterface:
   bool isEmpty() const;
   int getLength() const;
   bool remove(int position);
   bool pop_front();
   bool pop_back();
   void clear();
   ItemType getEntry(int position) const throw(PrecondViolatedExcep);
}; // end SortedLinkedList

#include "SortedLinkedList.cpp"
#endif