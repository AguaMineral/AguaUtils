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
#include "SimpLinkedList.h"

//Main for testing 
int main()
{  
    LinkedList lista;
	lista.insertFirst(5);
	lista.insertFirst(4);
	lista.insertFirst(3);
	lista.insertFirst(2);
	lista.insertFirst(1);
	lista.delFirst();
	lista.printList();
	lista.reverse();
	std::cout << "-----------------" << std::endl;
	lista.printList();
	lista.deleteList();
	std::cout << "-----------------" << std::endl;
	lista.printList();

}