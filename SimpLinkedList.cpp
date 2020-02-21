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
*/

#include <iostream>
#include "SimpLinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

void LinkedList::insertLast(int newItem)
{
    Node *tmp = new Node;
    tmp->item = newItem;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void LinkedList::insertFirst(int newItem)
{
    Node *tmp = new Node;
    tmp->item = newItem;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
		tmp->next = head;
        head = tmp;
        
    }
}

void LinkedList::del()
{
	Node *tmp = nullptr;
	
	if (head == NULL)
	{
		head == NULL;
		tail == NULL;
		
		std::cout << "ERROR: The list is empty" << std::endl;
	}
	else
	{
		tmp = head->next; 
		head = tmp;
	}
}


void LinkedList::printList()
{

    Node* tmp = nullptr;
    tmp = head;

    if (head == NULL)
    {
        std::cout << "The SimpLinked list is empty" << std::endl;
    }
    else
    {
        std::cout << "{" << tmp->item;
        
        while(tmp->next != NULL)
        {   
            tmp = tmp->next;
            std::cout << ", " << tmp->item;
            
        }
        std::cout << "}" << std::endl;
    }
}

int LinkedList::searchItem(int key)
{
	Node* tmp = nullptr;
    tmp = head;
	int tmpCount = 0;
	
	if (key < 0)
	{
		std::cout << "ERROR: The key is a negative number" << std::endl;
		return -1;
	}
	
	while (key > tmpCount)
	{
		tmp = tmp->next;
		tmpCount++;
		
		if (tmp == NULL)
		{
			std::cout << "ERROR: The given key does not exist in the list" << std::endl;
			return -1;
		}
	}
	
	return (tmp->item);
}

void LinkedList::deleteItem(int key)
{
	Node* tmp = nullptr;
	Node* tmpAnt = nullptr;
    tmp = head;
	int tmpCount = 0;
	
	if (key < 0)
	{
		std::cout << "ERROR: The key is a negative number" << std::endl;
	}
	
	if (key == 0)
	{
		tmp = head->next; 
		head = tmp;
	}
	else
	{
		while (key > tmpCount)
		{
			tmp = tmp->next;
			tmpCount++;
			
			//Saves the previous location to jump the elemet to delete
			if ( tmpCount == key - 1 )
			{
				tmpAnt = tmp;
			}
		
			if (tmp == NULL)
			{
				std::cout << "ERROR: The given key does not exist in the list" << std::endl;
			}
		}
		//Conects the previous location to the next next location
		tmpAnt->next = tmp->next;
	}

}

void LinkedList::reverseList()
{/*
	Node* tmp = nullptr;
	Node*tmpAnt = nullptr;
	
	tmp = head;
	
	while ( tmp->next != NULL )
	{
		tmpAnt = tmp;
		tmp = tmp->next;
	}
	
	tmp->next = */
}

int LinkedList::size()
{
	Node* tmp = nullptr;
    tmp = head;
	int count = 1;
	
	if (head == NULL)
	{
		std::cout << "ERROR: The list is empty" << std::endl;
		return -1;
	}
	
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	
	return count;
}