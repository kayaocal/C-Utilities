#ifndef LINKED_LIST
#define LINKED_LIST

#define LINKED_LIST_LOG

#include <stdlib.h>

typedef struct Node
{
	void* item;
	struct Node* next;
	struct Node* prev;
}Node;

Node* create_node(void* item);
void push_back(Node* root, void* item);
void push_first(Node** root, void* item);
void insert_by_index(Node** root, void* item, int index);
Node* get_last_node(Node* root);
Node* get_node_by_index(Node* root, int index);
Node* get_node_by_ptr(Node* root, Node* ptr);
void pop_back(Node* root);
void pop_first(Node** root);
void pop_by_index(Node** root, int index);
void pop_by_ptr(Node** root,  Node* ptr);
Node* extract_node_by_index(Node** root, int index);
Node* extract_node_by_ptr(Node** root,  Node* ptr);
void free_ptr(void** ptr);
void linked_list_log(char* str);
void swap_elements();//TODO:
int count(Node* root);
#endif


