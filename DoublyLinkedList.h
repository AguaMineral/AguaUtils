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

struct DbNode
{
	int _item;
	DbNode *_prev;
	DbNode *_next;
};

class DoublyLinkedList
{
private:

	DbNode *_head;
public:

	DoublyLinkedList();
	
	void insertFirst(int item);
	void insertLast(int item);
	void insertAfter(int key, int item);
	void removeFirst();
	void removeLast();
	void removeElement(int key);
	void deleteList();
	void printForw();
	void printBackw();
	int  size();
	void reverse();
	int  searchItem(int key);
	bool isEmpty();

};