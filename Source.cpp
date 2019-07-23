#include <assert.h>
#include <iostream>
#include <stdexcept>

// Define class List
template<typename T>
class List{
private:
	struct Node {T data; Node* next; Node* prev;};
	Node * head;
	Node * tail;
	Node * n;
	size_t listSize;
public:
	List(){    
		head = nullptr;
		tail = nullptr;
		listSize = 0;
	}

	void PushFront(T);
	void PushBack(T);
	T PopFront();
	T PopBack();
	size_t Size();
	~List();

};

template<typename T>
void List<T>::PushBack(T back_node){

	//create new node to store the data and connection
	n = new Node;

	// save the data
	n->data = back_node;

	// assign previous to the tail. if it is the firstone in the lisr so prev will be null
	n->prev = tail;

	//the next node is unknow till now so it will be null
	n->next = nullptr;

	// assign the head to be the n incase if head equal null and that is happen only after initiation 
	if (head == nullptr)
	{
		head = n;
	}

	// tail pointer till this line points to the previous n
	// So as long as the tail is not null (happens only at the initiation) next of previous n to equal the current n
	// this line simply assign next of n
	if(tail !=  nullptr) 
		tail->next = n ;

	// change pointer tail to point to the last Node has been added 
	tail = n;

	//increase size by 
	++listSize;

}

template<typename T>
void List<T>::PushFront(T front_node){
	n = new Node;

	//save data
	n->data = front_node;

	//there is nothing to the left to this node. so prev will be null
	n->prev = nullptr;

	// the right to this node was the head 
	n->next = head;

	//initiate tail if not exist 
	if (tail == nullptr)
		tail = n;

	//head now is pointing to the last node NOT to the current node thar we are now initiating
	// so when we add this node to the list the prev of last node will equal the current node n
	if(head != nullptr)
		head->prev = n;

	// reassign the head to the current node 
	head = n;

	//increase list size by 1
	++listSize;
}

template <typename T>
T List<T>::PopFront(){

	if (head != nullptr){
		T currentData = head->data;
		n = head ;
		if (head == tail)
		{
			head= nullptr;
			tail = nullptr;
			delete n;
			--listSize;
			return currentData;
		}else{
			head = head->next;
			if(head ==tail)
				tail->prev =nullptr;
			head->prev =nullptr;
			delete n;
			--listSize;
			return currentData;
		}

	}
	throw std::runtime_error("List is empty");
	return 0;

}

template<typename T>
T List<T>::PopBack(){

	if (tail != nullptr)
	{
		// get the current data that you want to return 
		T currentData = tail->data;

		// save the address of the current tail to n
		n=tail;

		// is head equal tail now so it's the last element and we need to assign the head and tail to null pointer
		if (head == tail)
		{
			head= nullptr;
			tail = nullptr;

			//delete the last element
			delete n;

			// decrease list size by 1.
			--listSize;
			return currentData;

		}else{
			//assing the tail to the node before the the cuurent tail 
			tail = tail->prev;

			// if the new tail equals the head so we need to change head->next to null
			if (tail == head)
			{
				head->next =nullptr;
			}

			//change the the current tail->next to point to null 
			tail->next = nullptr;

			//delete the content in the memory address
			delete n;

			//decrease list size by 1
			--listSize;

			//return the value that has beeb poped up
			return currentData;
		}	
	}
	// throw a runtime error if the user tries to pop up an enmpty list
	throw std::runtime_error("List is empty");	 
}

template<typename T>
size_t List<T>::Size(){
	return listSize;
}

template <typename T>
List<T>::~List(){
	while(head!=nullptr){
		PopFront();
	}
}


// Design a doubly linked list to pass these tests
int main() {
	// Sanity test
	List<int> list1;
	list1.PushBack(9);
	assert(list1.Size() == 1);

	// Deeper test
	List<int> list2;
	list2.PushFront(9);
	list2.PushBack(10);
	assert(list2.Size() == 2);
	assert(list2.PopBack() == 10);
	assert(list2.PopFront() == 9);
	assert(list2.Size() == 0);
	return 0;
}