// Name: Martyn van Dijke
// Student number: 0887668

#include <iostream>

#include "list.h"
#include "item.h"


using namespace std;

List::List()
    : _head(nullptr)
{ }

List::~List()
{
    clear();
}

Node* List::head()
{
    return _head;
}

void List::clear()
{
	//there is nothing to clear
	if (!_head) {
		return;
	}

	Node* nextNode = _head;
	do {
		Node* currentNode = nextNode;
		nextNode = currentNode->next;
		delete currentNode;
	} while (nextNode != _head);
	_head = nullptr;

}


void List::remove(Node* node) {
	cout << "\n \n \n Going to remove a node" << endl;
	
	Node* next = node->next;
	Node* previous = node->prev;
	node->prev->next = next;
	node->next->prev = previous;
	//node->item->id() = nullptr;
	delete node;
	//delete node;
	
	
	
	//if ( node->item->id() == nullptr	) {
		//cout << "That id is not possible" << endl;
	//}
	
	//Node* before = node->next ;
	//Node* after = node->prev ;
	//node->item->print();
	//before->item->print();
	//after->item->print();

	//if (after == before) {
	//	_head = nullptr;
	//	cout << "Nothing to delete" << endl;
	//	return;
	//}

	////delete node;

	//before->next = after;
	//after->prev = before;
	//
	////delete node->item;
	//cout << "Ik kom tot hiero" << endl;
	//int delId = node->item->id();
	//cout << delId << endl;
	//node->item->id()
	//delete &delId;
	//delete node->item = nullptr;
	//delete node; 

	//remove node;
	//idcounter--;
	//delete node;
}



Node* findItemById(List* list, int id) {
	//cout << list << " the id you are looking for is " <<id << endl ;
	//cout << list << endl;
	//cout << list->head() << endl;
	Node* list_needed = list->head();	
	Node* store_list = list_needed;
	//cout << listh << endl;
	//cout << listhead->item->id() << endl;
	if ( id > list->highest_id() ) {
		cout << "That id is not even possible" << endl;
		return nullptr;
	}
	//if the next of listhead is not eqaul to the listhead (meaning it has not reached 1 )
	while( (list_needed->next) != list_needed){
		//if the listhead item id is the id you are looking for
		if (list_needed->item->id() == id) {
			cout << "I have foudnd id " << list_needed->item->id() << endl;
			// return the pointer to the head of the list
			return* &list_needed;
		}
			//increment the list head with the 
			list_needed = list_needed->next;
			//if the list is the list to begin with (meaning it has looped around and has founded nothing)
			if (list_needed == store_list){
				// i have found completly nothing 
				return nullptr;
			}

		
	} 
	
	return nullptr;
	
	 




	//list->print();
	//listhead->
	//Node* node = listhead;
	
	//cout << listhead << endl;
	//cout << listhead->item->id() << endl;

	//while ((listhead->next) != listhead)
	//{
	//	nextlist:
	//	if (listhead->item->id() == id) {
	//		int returnid = listhead->item->id();
	//		cout << "Founded the item" << endl;
	//		//listhead = listhead->next;
	//		return* &listhead;


	//	}

	//	//if (listhead->next->item->id() == id) {
	//	//	int returnid = listhead->item->id();
	//	//	cout << "Founded the item 2" << endl;
	//	//	listhead = listhead->next;
	//	//	return* &listhead;

	//	//}

	//	//hiero klopt de logica niet 
	//	else
	//	{
	//		listhead = listhead->next;
	//		if(	listhead->prev->item->id() != id	)
	//			{
	//				cout << "Nothing Found for real" << endl;
	//				return nullptr;
	//			}
	//		
	//		goto nextlist;
	//		//cout << "Nothing Found" << endl;
	//		//return nullptr;
	//	}
	//	//listhead = listhead->next;

	//} 
	
	//while ( (listhead->next) != listhead );




	//do {
	//	if(	listhead->item->id() == id) {
	//		int returnid = listhead->item->id();
	//		cout << "Founded the item" << endl;
	//		return*  &listhead ;
	//}
	//	if (listhead->next->item->id() == id) {

	//		int returnid = listhead->item->id();
	//		cout << "Founded the item 2" << endl;
	//		return*&listhead;

	//	}

	//	else {
	//		//item is not in the list
	//		cout << "Nothing is found" << endl;
	//		return nullptr;
	//}
	//	
	//} while( (listhead = listhead->next ) != listhead );

	//return 0;
}



//Node* findItemById(List* list, int id) {
	
	//if ( _head == nullptr) {
		//return nullptr;
	//}

	//Node* node = list->head;
	//do the next function while there is no next item on the list
	//do {

		//if (node->item->id() == id) {
			//int returnid = &id();
			//cout << "Founded the item" << endl;
			//return ; 
		//}
		//else {
			//item is not in the list
			//return nullptr;
		//}
		
	//} while ((node = node->next) != _head);
	
//}



// function will add new item's to the list
void List::push_back(Item* item) {
	cout << "-> Append item id " << item->id() << endl;
	Node* nodetoadd = new Node();
	nodetoadd->item = item;

	if (_head == nullptr) {
		nodetoadd->next = nodetoadd;
		nodetoadd->prev = nodetoadd;
		_head = nodetoadd;
	}
	else 
	{
		Node* currentNode =	_head->prev;
		currentNode->next = nodetoadd;
		nodetoadd->prev = currentNode;
		nodetoadd->next = _head;
		_head->prev = nodetoadd;
	}
}

//function will
void List::push_front(Item* item) {
	cout << "-> Inserted item id " << item->id() << endl;
	Node* nodetoAdd = new Node();
	nodetoAdd->item = item;

	if (_head == nullptr) {
		nodetoAdd->next = nodetoAdd;
		nodetoAdd->prev = nodetoAdd;
		_head = nodetoAdd;
	}
	else
	{
		Node* currentNode = _head->prev;
		currentNode->next = nodetoAdd;
		nodetoAdd->prev = currentNode;
		nodetoAdd->next = _head;
		_head = nodetoAdd;
	}

}

void List::print() {
	//if there is no head
	if ( _head == nullptr) {
		cout << "List contains no items"<< endl;
		return;
	}
	Node* node = _head;
	//do the next function while there is no next item on the list
	do{
		cout << "-> item id  " << endl;
		node->item->print(); //<< endl;
				//<<end1;
	} while ((node = node->next) != _head);
	//while the next node is not the head node excute this code
}

void List::put_first(Node* node) {
	//definition of the previous and next node's
	Node* next = node->next;
	Node* previous = node->prev;

	previous->next = next;
	next->prev = previous;

	_head->prev->next = node;
	 node->prev = _head->prev;
	_head->prev = node;
	//node->next = _head;
	_head = node; //place the head of the list at the new beginning

	cout << "Node with id "
		<< node->item->id()
		<< " has been put in the front"
		<< endl;
}

int List::highest_id() {
	int highest_id = 0;
	Node* node = _head;
	do
	{
		if (node->item->id() > highest_id)
		{
			highest_id = node->item->id();
		}
	} while ((node = node->next) != _head);
	return highest_id;
}


void sortListById(List* list) {
	int high_id = list->highest_id();
	int store_i;
	int i = high_id;
	cout << "The highest id is :"
		 << high_id << endl;
	cout << list->head() << endl;

	for ( i>0; i--;)
	{
		cout <<" i is "
			 <<i << endl;

		// if the id of the item is not in the list
		if ((findItemById(list, i)) == nullptr)
		{
			cout << "ik ben hiero " << endl;
			//decrement i (contine with  the loop)
			i--;
		}
		
		list->put_first(findItemById(list, i));
		
	}


}