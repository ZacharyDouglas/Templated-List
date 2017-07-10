/*Collection class used to track list
Zach Douglas
2/11/16
*/

#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <iostream>

template<typename T>
class Collection {
public:
	//Initialize next_ and root_ to NULL
	Collection() : next_(nullptr), root_(nullptr) {};

	void addItem(const T& item);
	bool removeItem(const T& item);
	void printCollection();
	T lastItem();

private:
	T item_;
	Collection<T> *next_;
	Collection<T> *root_;
};

/*
Input:  T item  
Output:  N / A
Purpose:  To create a new template node attach it at the beginning of the list.  Then, move root to the new beginning of the list
*/

template <typename T>
void Collection<T>::addItem(const T& item) {
	next_ = 0;	//points next_ to NULL
	Collection<T> *node = new Collection<T>;	
	node->item_ = item;		//set item_ in the new node to the value of the parameter
	node->next_ = root_;	//Make new node root
	root_ = node;


}

/*
Input:  T item
Output:  True / False
Purpose:  To locate a specified item to remove from the linked list.  Once the item is removed, reconnect the two list pieces
*/
template <typename T>
bool Collection<T>::removeItem(const T& item) {
	Collection<T> *current = new Collection<T>;
	current = root_;
	next_ = current->next_;

	//Checks to see if the item is stored in the root node of the list
	//If it is, delete this node
	while (current->item_ == item) {
		delete current;
		current = next_;
		next_ = current->next_;
	}
	
	root_ = current;

	//While next_ is a valid node, check if it's item matches the value that needs deleted.
	//If so, delete the node and reconnect the two pieces of the list
	while (next_ != NULL) {
		if (next_->item_ == item) {
			current->next_ = next_->next_;		//Connecting the previous and next node before deleting the current
			delete next_;
			next_ = current->next_;
		}
		else {
			current = next_;
			next_ = next_->next_;
		}
	}
	return true;
}

/*
Input:  N / A
Output:  N / A
Purpose:  To traverse through the list and output the items that it contains
*/

template <typename T>
void Collection<T>::printCollection() {
	Collection<T> *temp = new Collection<T>;
	temp = root_;
	//While root_ is valid, print the value of the item stored in that node
	while (root_) {

		std::cout << root_->item_ << std::endl;
		root_ = root_->next_;	//traverse to next node in list
	}
	root_ = temp;	//Setting root back to it's original root node from before the traversal
}

/*
Input:  N / A
Output:  N / A
Purpose:  To output the contents of the last inserted item
*/

template <typename T>
T Collection<T>::lastItem() {

	return root_->item_;
}
#endif