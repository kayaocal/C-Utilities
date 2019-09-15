/*
 * Author: Enes Kaya ÖCAL
 * Purpose: Dynamic linked list operations
 * Date : 24.02.2018
 * Language:  C
 */
#include "LinkedList.h"

Node* create_node(void* item)
{
	linked_list_log("LinkedList::create_node - started");
	if(item == NULL)
	{
		linked_list_log("Error : LinkedList::create_node - item is null");
		return NULL;
	}

	Node* m_node = (Node*) malloc(sizeof(Node));
	m_node->item = item;
	m_node->next = NULL;
	m_node->prev = NULL;

	linked_list_log("LinkedList::create_node - finished");
	return m_node;
}

void push_back(Node* root, void* item)
{
	linked_list_log("LinkedList::push_back_node - started");

	if(root == NULL)
	{
		linked_list_log("LinkedList::push_back_node - root is null");
		return;
	}

	Node* m_node = create_node(item);
	
	if(m_node == NULL)
	{
		linked_list_log("LinkedList::push_back_node - m_node is null");
		return;
	}

	Node* m_last_node = get_last_node(root);

	if(m_last_node == NULL)
	{
		linked_list_log("LinkedList::push_back_node - m_last_node is null");
		return;
	}

	m_last_node->next = (void*)m_node;
	m_node->prev = (void*)m_last_node;

	linked_list_log("LinkedList::push_back_node - finished");
}

Node* get_last_node(Node* root)
{
	linked_list_log("LinkedList::get_last_node - started");

	if(root == NULL)
	{
		linked_list_log("LinkedList::get_last_node - root is null");		
		return NULL;
	}

	while(root->next != NULL)
	{
		root = root->next;
	}
	
	linked_list_log("LinkedList::get_last_node - finished");
	return root;
}

/*
		This method extracts last node and deletes node.
*/
void pop_back(Node* root )
{
	linked_list_log("LinkedList::pop_back - started");

	Node* m_last_node = get_last_node(root);

	if(m_last_node == NULL)
	{
		linked_list_log("LinkedList::pop_back - m_last_node is null");
		return;
	}

	Node* m_last_prev =  m_last_node->prev;
	m_last_prev->next = NULL;

	free_ptr((void**)&m_last_node);

	linked_list_log("LinkedList::pop_back - finished");
}

/*
		This method extracts first node and deletes node.
*/
void pop_first(Node** root)
{
	linked_list_log("LinkedList::pop_first - started");

	if(root == NULL)
	{
		linked_list_log("LinkedList::pop_first - root is null");
		return;
	}

	Node* m_second =((*root)->next);
	free_ptr((void**)root);
	
	if(m_second != NULL)
	{
		m_second->prev = NULL;
		*root = m_second;
	}

	linked_list_log("LinkedList::pop_first - finished");
}

/*
		This method extracts node at given index from list and deletes node.
*/
void pop_by_index(Node** root, int index)
{
	linked_list_log("LinkedList::pop_by_index - started");

	Node* m_node = extract_node_by_index(root, index);
	free_ptr((void**)&m_node);
	
	linked_list_log("LinkedList::pop_by_index - finished");
}

/*
		This method extracts node with given pointer from list and deletes node.
*/
void pop_by_ptr(Node** root,  Node* ptr)
{
	linked_list_log("LinkedList::pop_by_ptr - started");

	Node* m_node = extract_node_by_ptr(root, ptr);
	free_ptr((void**)&m_node);
	
	linked_list_log("LinkedList::pop_by_ptr - finished");
}


Node* get_node_by_index(Node* root, int index)
{
	linked_list_log("LinkedList::get_node_by_index - started");
	if(index < 0)
	{
		linked_list_log("Error : LinkedList::get_node_by_index -  Index is smaller than zero");
		return NULL;
	}
	
	int m_index = 0;

	while(m_index < index && root != NULL)
	{
		root = root->next;
		m_index++;
	}

	if(root == NULL)
	{
		linked_list_log("Error : LinkedList::get_node_by_index -  Index is bigger than list size");
		return NULL;
	}

	linked_list_log("LinkedList::get_node_by_index - finished");

	return root;
}

Node* get_node_by_ptr(Node* root, Node* ptr)
{
	linked_list_log("LinkedList::get_node_by_ptr - started");

	if(ptr == NULL || root == NULL)
	{
		linked_list_log("Error : LinkedList::get_node_by_ptr -Searched ptr is not exist");
		return NULL;
	}

	while(root != ptr && root != NULL)
	{
		root = root->next;
	}

	if(root == NULL)
	{
		linked_list_log("Error : LinkedList::get_node_by_ptr - Searched ptr is not exist");
		return NULL;
	}

	linked_list_log("LinkedList::get_node_by_ptr - finished");
	
	return root;
}

/*
		This method extracts node at given index from list and returns node.
*/
Node* extract_node_by_index(Node** root, int index)
{
	linked_list_log("LinkedList::extract_node_by_index - started");
	Node* elem = get_node_by_index(*root, index);

	if(elem == NULL)
	{
		linked_list_log(" Error : LinkedList::extract_node_by_index - elem is null.");
		return NULL;
	}

	Node* m_prev = elem->prev;
	Node* m_next = elem->next;

	if(m_prev != NULL)
	{
		elem->prev->next = elem->next;
	}else// means that  elem is firt item
	{
		linked_list_log(" ==>>-  elem is firt item");
		*root = (*root)->next;
		(*root)->prev = NULL;
	}

	if(m_next != NULL)
	{
		elem->next->prev = elem->prev;
	}


	linked_list_log("LinkedList::extract_node_by_index - finished");
	return elem;
}

/*
		This method extracts node with given pointer from list and returns node.
*/
Node* extract_node_by_ptr(Node** root, Node* ptr)
{
	linked_list_log("LinkedList::extract_node_by_ptr - started");

	if(*root == NULL)
	{
		linked_list_log("Error : LinkedList::extract_node_by_ptr - given root is null");
		return NULL;
	}

	Node* elem = get_node_by_ptr(*root, ptr);

	if(elem == NULL)
	{
		linked_list_log(" Error : LinkedList::extract_node_by_ptr - elem is null.");
		return NULL;
	}

	Node* m_prev = elem->prev;
	Node* m_next = elem->next;

	if(m_prev != NULL)
	{
		elem->prev->next = elem->next;
	}else// means that  elem is firt item
	{
		*root = (*root)->next;
		(*root)->prev = NULL;
	}

	if(m_next != NULL)
	{
		elem->next->prev = elem->prev;
	}	

	linked_list_log("LinkedList::extract_node_by_ptr - finished");
	return elem;
}

int count(Node* root)
{
	int counter = 0;
	while(root != NULL)
	{
		counter++;
		root = root->next;
	}

	return counter;
}

void push_first(Node** root, void* item)
{
	linked_list_log("LinkedList::push_first - started");

	Node* m_node = create_node(item);
	m_node->next = *root;

	(*root)->prev = m_node;
	*root = m_node;

	linked_list_log("LinkedList::push_first - finished");
}

/*
		creates a node with item pointer and inserts node to list.
*/
void insert_by_index(Node** root, void* item, int index)
{
	linked_list_log("LinkedList::insert_by_index - started");
	Node* elem = get_node_by_index(*root, index);

	if(elem == NULL)
	{
		linked_list_log(" Error : LinkedList::insert_by_index - elem is null.");
		return;
	}

	Node* m_prev = elem->prev;
	Node* m_next = elem->next;

	if(m_prev == NULL)//First item
	{
		push_first(root, item);
		return;
	}

	if(m_next == NULL)
	{
		push_back(*root, item);
		return;
	}

	Node* m_node = create_node(item);

	m_prev->next = m_node;
	elem->prev = m_node;
	m_node->next = elem;
	m_node->prev = m_prev;

	linked_list_log("LinkedList::insert_by_index - finished");
}

void inverse_list(Node** root)
{
	linked_list_log("LinkedList::inverse_list - started");
	Node* m_node = *root;
	Node* temp;
	Node* last;
	Node* tempNode;
	while(m_node != NULL)
	{
		if(m_node->next == NULL)
		 	last = m_node;
		 tempNode = m_node;
		 m_node = m_node->next;

		 temp = tempNode->prev;
		 tempNode->prev = tempNode->next;
		 tempNode->next = temp;
	}

	*root = last;
	linked_list_log("LinkedList::inverse_list - finished");
}

void swap_elements_by_id(Node** root, int a, int b)
{
	linked_list_log("LinkedList::swap_elements_by_id - started");

	if(a == b)
	{
		return;
	}

	int big = b;
	int small = a;

	if(a>b)
	{
		small = b;
		big = a;
	}

	if(b>a)
	{
		small = a;
		big = b;
	}

	Node* a_node = get_node_by_index(*root, small);
	Node* b_node = get_node_by_index(*root, big);

	if(big - small == 1)//sequential
	{
		if(a_node->prev == NULL)//first item
		{
			*root = b_node;
		}else
		{
			a_node->prev->next = b_node;
		}

		if(b_node->next != NULL)
		{
		   b_node->next->prev = a_node;
		}

		Node* t_node = a_node->next;
		a_node->next = b_node->next;
		b_node->prev = a_node->prev;
		b_node->next = a_node;
		a_node->prev = b_node;


	}else
	{
		
		if(a_node->prev == NULL)//first item
		{
			*root = b_node;
		}else
		{
			a_node->prev->next = b_node;
		}

		if(b_node->next != NULL)
		{
			b_node->next->prev = a_node;
		}

		if(b_node->prev != NULL)
		{
			b_node->prev->next = a_node;
		}

		if(a_node->next != NULL)
		{
			a_node->next->prev = b_node;
		}

		Node* t_node = b_node->prev;
		b_node->prev = a_node->prev;
		a_node->prev = t_node;

		t_node = b_node->next;
		b_node->next = a_node->next;
		a_node->next = t_node;
	
	}

	linked_list_log("LinkedList::swap_elements_by_id - started");
}

int get_item_id(Node* root, Node* target_ptr)
{
	int counter = 0;
	while(root != target_ptr && root != NULL)
	{
		root = root->next;
		counter++;
	}
	
	return counter;
}

void free_ptr(void** ptr)
{
	linked_list_log("LinkedList::free_ptr - started");

	free(*ptr);
	*ptr = NULL;

	linked_list_log("LinkedList::free_ptr - finished");
}

void linked_list_log(char* str)
{
#ifdef LINKED_LIST_LOG
	printf("\n");
	printf(str);
#endif
}
