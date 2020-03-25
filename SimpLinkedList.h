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

template <typename T>
struct Node
{
    T item;
    Node<T>* next;
};

template <class T>
class LinkedList
{
private:

    Node<T> *head, *tail;

public:

    LinkedList();
    
    /*
    Inserts an element at the begining of the list
    */
	
	void insertFirst(T newItem);

    /*
    Inserts an element at the end of the list
    */
    void insertLast(T newItem);

    /*
    Deletes an element at the begining of the list
    */
    void delFirst();
	
	/*
	 * Deletes the entire list
	 */
	void deleteList();
	
    /*
    Displays the complete list in the console
    */
    void printList();

    /*
    returns an element using a given key
    */
    T searchItem(int key);

    /*
    Deletes an element using a given key
    */
    void deleteItem(int key);
	
	/*
	 * Reverse the list
	 */
	void reverse();
	
	/*
	 * Returns the size of the list
	 */
	int size();
	
	/*
	 * Returns true if it is empty
	 */
	bool isEmpty();
};

//Class implementation

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
}

template <class T>
void LinkedList<T>::insertLast(T newItem)
{
    Node<T> *tmp = new Node<T>;
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
template <class T>
void LinkedList<T>::insertFirst(T newItem)
{
    Node<T> *tmp = new Node<T>;
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
template <class T>
void LinkedList<T>::delFirst()
{
	Node<T> *tmp = nullptr;
	
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

template <class T>
void LinkedList<T>::printList()
{

    Node<T>* tmp = nullptr;
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
template <class T>
T LinkedList<T>::searchItem(int key)
{
	Node<T>* tmp = nullptr;
    tmp = head;
	int tmpCount = 0;
	
	if (key < 0)
	{
		std::cout << "ERROR: The key is a negative number" << std::endl;
		return tmp->item;
	}
	
	while (key > tmpCount)
	{
		tmp = tmp->next;
		tmpCount++;
		
		if (tmp == NULL)
		{
			std::cout << "ERROR: The given key does not exist in the list" << std::endl;
			return tmp->item;
		}
	}
	
	return (tmp->item);
}
template <class T>
void LinkedList<T>::deleteItem(int key)
{
	Node<T>* tmp = nullptr;
	Node<T>* tmpAnt = nullptr;
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
			//Saves the previous position
			tmpAnt = tmp;
			
			tmp = tmp->next;
			tmpCount++;
			
			if (tmp == NULL)
			{
				std::cout << "ERROR: The given key does not exist in the list" << std::endl;
			}
		}
		//Conects the previous location to the next next location
		tmpAnt->next = tmp->next;
	}

}
template <class T>
void LinkedList<T>::reverse()
{
	Node<T> *next_   = nullptr;
	Node<T> *current = nullptr;
	Node<T> *prev_ = nullptr;
	
	current = head;
	
	while (current != NULL)
	{
		//saves next node
		next_ = current->next;
		//points to previous node
		current->next = prev_;
		//saves previous node
		prev_ = current;
		//Update current node
		current = next_;
	}
	//Update head to last previous node wich is the las correct current
	head = prev_;
}
template <class T>
int LinkedList<T>::size()
{
	Node<T>* tmp = nullptr;
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
template <class T>
void LinkedList<T>::deleteList()
{
	head = NULL;
	tail = NULL;
}
template <class T>
bool LinkedList<T>::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}