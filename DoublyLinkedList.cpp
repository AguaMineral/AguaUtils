/*Copyright [2020] [Mario Villa Lore]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

This is a simple implementation of various data structures in C++ for learning pourposes
At 21-feb-2020 there is:
 * Simple Linked List

*/

#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	_head = NULL;
}

void DoublyLinkedList::insertFirst(int item)
{
	DbNode *tmp = new DbNode;
	tmp->_item = item;
	tmp->_prev = NULL;
	tmp->_next = NULL;
	
	if (_head == NULL) // List is empty
	{
		_head = tmp;
	}
	else 
	{
		tmp->_next = _head; //new node _next points to the head
		_head->_prev = tmp; //head _prev points to the new node
		_head = tmp;        //new node is now the head
	}
}

void DoublyLinkedList::removeFirst()
{
	DbNode *tmp = nullptr;
	tmp = _head->_next;
	tmp->_prev = NULL;
	_head = tmp;
}

void DoublyLinkedList::removeLast()
{
	DbNode *previous = nullptr;
	DbNode *current = nullptr;
	current = _head;
	
	if(_head == NULL)
	{
		std::cout << "ERROR: List is empty" << std::endl;
	}
	else
	{
		while (current->_next != NULL)
		{
			previous = current;
			current = current->_next;
		}
		previous->_next = NULL;
	}
}

void DoublyLinkedList::insertLast(int item)
{
	DbNode *tmp = new DbNode;
	DbNode *current = nullptr;
	current = _head;
	tmp->_item = item;
	tmp->_next = NULL;
	tmp->_prev = NULL;
	
	if (_head == NULL) // List is empty
	{
		_head = tmp;
	}
	else 
	{
		while (current->_next != NULL)
		{
			current = current->_next;
		}
		tmp->_prev = current;
		current->_next = tmp;
		
	}
}

void DoublyLinkedList::insertAfter(int key, int item)
{
	DbNode *tmp = new DbNode;
	DbNode *current = nullptr;
	DbNode *previous = nullptr;
	tmp->_item = item;
	tmp->_next = NULL;
	tmp->_prev = NULL;
	current = _head;
	
	std::cout << current->_item << std::endl;
	
	int cont = 1;
	
	if (_head == NULL)
	{
		std::cout << "ERROR: List is empty" << std::endl;
	}
	else if(key == 1) // pos in head
	{
		insertFirst(item);
	}
	else if(key < 1)
	{
		std::cout << "ERROR: That position doenst exist in the list. List positioning begins in 1" << std::endl;
	}
	else if(key < cont)
	{
		std::cout << "ERROR: The list is shorter" << std::endl;
	}
	else
	{
		
		while ( key > cont )
		{
			previous = current;
			current = current->_next;
			cont++;
		}
		
		current->_prev = tmp;
		previous->_next = tmp;
		tmp->_prev = previous;
		tmp->_next = current;
	}
}
void DoublyLinkedList::deleteList()
{
	if (_head == NULL)
	{
		std::cout << "ERROR: The list is already empty" << std::endl;
	}
	else
	{
		_head = NULL;
	}
}

void DoublyLinkedList::removeElement(int key)
{
	DbNode *current = nullptr;
	DbNode *next = nullptr;
	DbNode *previous = nullptr;
	int cont = 1;
	
	if (_head == NULL)
	{
		std::cout << "ERROR: the list is empty" << std::endl;
	}
	else if(key < 1)
	{
		std::cout << "ERROR: That position doenst exist in the list. List positioning begins in 1" << std::endl;
	}
	else if(key < cont)
	{
		std::cout << "ERROR: The list is shorter" << std::endl;
	}
	else if(key == 1)
	{
		removeFirst();
	}
	else
	{
		current = _head;
		
		while ( key > cont )
		{
			previous = current;
			current = current->_next;
			next = current->_next;
			cont++;
		}
		if(next != NULL)
		{
			previous->_next = next;
			next->_prev = previous;
		}
		else
		{
			previous->_next = NULL;
		}
	}
}

void DoublyLinkedList::printForw()
{
	DbNode *tmp = nullptr;
	tmp = _head;
	
	if (_head == NULL)
	{
		std::cout << "ERROR: The list is empty" << std::endl;
	}
	else
	{
		std::cout << "{" << tmp->_item;
		
		while(tmp->_next != NULL)
		{
			tmp = tmp->_next;
			std::cout << ", " << tmp->_item;
		}
		std::cout << "}" << std::endl;
	}
}

void DoublyLinkedList::printBackw()
{
	DbNode *tmp = nullptr;
	tmp = _head;
	
	if (_head == NULL)
	{
		std::cout << "ERROR: The list is empty" << std::endl;
	}
	else
	{
		while (tmp->_next != NULL)
		{
			tmp = tmp->_next;
		}
		
		std::cout << "{" << tmp->_item;
		
		while(tmp->_prev != NULL)
		{
			tmp = tmp->_prev;
			std::cout << ", " << tmp->_item;
		}
		std::cout << "}" << std::endl;
	}
}

bool DoublyLinkedList::isEmpty()
{
	if(_head == NULL)
		return true;
	else
		return false;
}

int DoublyLinkedList::size()
{
	DbNode *current = nullptr;
	int count = 1;
	current = _head;
	
	if(_head == NULL)
	{
		std::cout << "ERROR: List is empty" << std::endl;
		return -1;
	}
	else
	{
		while(current->_next != NULL)
		{
			current = current->_next;
			count++;
		}
		return count;
	}
}

void DoublyLinkedList::reverse()
{
	DbNode *current  = nullptr;
	DbNode *previous = nullptr;
	DbNode *next_ 	 = nullptr;
	
	current = _head;
	
	if (_head == NULL)
	{
		std::cout << "ERROR: List cannot be reversed, its empty" << std::endl;
	}
	else
	{
		while (current != NULL)
		{
			//saves next node
			next_ = current->_next;
			//inverts pointers
			current->_next = previous;
			current->_prev = next_;
			//saves previous node
			previous = current;
			//Update current node
			current = next_;
			
		}
		_head = previous;
	}
}

int DoublyLinkedList::searchItem(int key)
{
	DbNode *current = nullptr;
	current = _head;
	int count = 1;
	if(current == NULL)
	{
		std::cout << "ERROR: List is empty" << std::endl;
		return -1;
	}
	else if(key < 1)
	{
		std::cout << "ERROR: That position doenst exist in the list. List positioning begins in 1" << std::endl;
		return -1;
	}
	else if(key < count)
	{
		std::cout << "ERROR: The list is shorter" << std::endl;
		return -1;
	}
	else if(key == 1)
	{
		return (current->_item);
	}
	else
	{
		while(key > count)
		{
			current = current->_next;
			count++;
		}
		return(current->_item);
	}
}