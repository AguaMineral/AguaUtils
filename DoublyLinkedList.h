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

template<typename T>
struct DbNode
{
	T _item;
	DbNode<T> *_prev;
	DbNode<T> *_next;
};

template<class T>
class DoublyLinkedList
{
private:

	DbNode<T> *_head;
public:

	DoublyLinkedList();
	
	/*
    Inserts an element at the begining of the list
    */
	void insertFirst(T item);
	
	/*
    Inserts an element at the end of the list
    */
	void insertLast(T item);
	void insertAfter(int key, T item);
	void removeFirst();
	void removeLast();
	/*
	 * Removes an element in a given position sended as int >= 0
	 */
	void removeElement(int key);
	void deleteList();
	void printForw();
	void printBackw();
	/*
	 * Returns the size of the list in int
	 */
	int  size();
	void reverse();
	/*
	 * Searchs an item in a given position sended as int >= 0
	 */
	T  searchItem(int key);
	/*
	 * Returns true if the list is empty, false if is not
	 */
	bool isEmpty();

};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	_head = NULL;
}

template<class T>
void DoublyLinkedList<T>::insertFirst(T item)
{
	DbNode<T> *tmp = new DbNode<T>;
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

template<class T>
void DoublyLinkedList<T>::removeFirst()
{
	DbNode<T> *tmp = nullptr;
	tmp = _head->_next;
	tmp->_prev = NULL;
	_head = tmp;
}

template<class T>
void DoublyLinkedList<T>::removeLast()
{
	DbNode<T> *previous = nullptr;
	DbNode<T> *current = nullptr;
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

template<class T>
void DoublyLinkedList<T>::insertLast(T item)
{
	DbNode<T> *tmp = new DbNode<T>;
	DbNode<T> *current = nullptr;
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

template<class T>
void DoublyLinkedList<T>::insertAfter(int key, T item)
{
	DbNode<T> *tmp = new DbNode<T>;
	DbNode<T> *current = nullptr;
	DbNode<T> *previous = nullptr;
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

template<class T>
void DoublyLinkedList<T>::deleteList()
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

template<class T>
void DoublyLinkedList<T>::removeElement(int key)
{
	DbNode<T> *current = nullptr;
	DbNode<T> *next = nullptr;
	DbNode<T> *previous = nullptr;
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

template<class T>
void DoublyLinkedList<T>::printForw()
{
	DbNode<T> *tmp = nullptr;
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

template<class T>
void DoublyLinkedList<T>::printBackw()
{
	DbNode<T> *tmp = nullptr;
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

template<class T>
bool DoublyLinkedList<T>::isEmpty()
{
	if(_head == NULL)
		return true;
	else
		return false;
}

template<class T>
int DoublyLinkedList<T>::size()
{
	DbNode<T> *current = nullptr;
	int count = 1;
	current = _head;
	
	if(_head == NULL)
	{
		std::cout << "ERROR: List is empty" << std::endl;
		return count;
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

template<class T>
void DoublyLinkedList<T>::reverse()
{
	DbNode<T> *current  = nullptr;
	DbNode<T> *previous = nullptr;
	DbNode<T> *next_ 	 = nullptr;
	
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

template<class T>
T DoublyLinkedList<T>::searchItem(int key)
{
	DbNode<T> *current = nullptr;
	current = _head;
	int count = 1;
	if(current == NULL)
	{
		std::cout << "ERROR: List is empty" << std::endl;
		return current->_item;
	}
	else if(key < 1)
	{
		std::cout << "ERROR: That position doenst exist in the list. List positioning begins in 1" << std::endl;
		return current->_item;
	}
	else if(key < count)
	{
		std::cout << "ERROR: The list is shorter" << std::endl;
		return current->_item;
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