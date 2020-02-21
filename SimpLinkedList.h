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

struct Node
{
    int item;
    Node* next;
};

class LinkedList
{
private:

    Node *head, *tail;

public:

    LinkedList();
    
    /*
    Inserts an element at the begining of the list
    */
	
	void insertFirst(int newItem);

    /*
    Inserts an element at the end of the list
    */
    void insertLast(int newItem);

    /*
    Deletes an element at the begining of the list
    */
    void del();
	
    /*
    Displays the complete list in the console
    */
    void printList();

    /*
    returns an element using a given key
    */
    int searchItem(int key);

    /*
    Deletes an element using a given key
    */
    void deleteItem(int key);
	
	/*
	 * Reverse the list
	 */
	void reverseList();
	
	/*
	 * Returns the size of the list
	 */
	int size();
};
