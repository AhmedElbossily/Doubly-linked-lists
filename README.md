# Doubly linked lists
Doubly linked list is a type of data structure that is made up of so called objects that are created using self referential structures. Each of these nodes contain three attributes, namely the value and the reference to the next list object and the reference to the previous list object.

Because the list is linked in both directions, any node has the ability to access any other node. That means that the user of a doubly linked list need only keep track of a single node.

The last node in the list points forward to nothing, which can be represented by `nullptr`. The same is true for the first node in the list, which points backward to nothing.

In this exercise you will create a doubly linked list, which exposes 4 methods: 
* **`push_back()`**: add values to the end of the list
* **`push_front()`**: add values to the beginning to the list
* **`pop_back()`**: delete values from the end of the list
* **`pop_front()`**: delete values from the front of the list

Also, you will implement a helper function, `empty()`, which returns whether or not the list has any nodes.

## Steps
1. Declare `class List` to represent the doubly linked list
2. Declare `struct Node` to represent the nodes in the list
3. Declare a constructor for `struct Node`
4. Declare a member variable `head` that belongs to `class List` and points to the first node in the list
5. Declare a member variable `tail` that belongs to `class List` and points to the first node in the list
6. Declare a constructor for the doubly linked list
7. Declare a destructor for `class List`
8. Implement the `class List` destructor to `delete` all of the nodes in the list
9. Declare `List::PushFront()` to push nodes onto the front of the list
10. Declare `List::PushBack()` to push nodes onto the back of the list
11. Declare `List::PopFront()` to delete nodes from the front of the list
12. Declare `List::PopBack()` to delete nodes from the back of the list
13. Declare `List::Size()` to count the number of nodes in the list
14. Test that all member functions in `class List` behave properly, even if the list is empty
