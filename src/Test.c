#include<stdio.h>
#include "LinkedList.c"

Node* root;
int numbers [20];
int num = 22;
int num2 = 33;
int num3 = 23;

void print_list()
{
	printf("\n\n--");
	Node* m_root = root;
	int counter = 0;
	while(m_root != NULL)
	{
		printf("-->%d element is  %d",counter,(*(int*)(m_root->item)));
		counter++;
		m_root = (Node*)m_root->next;
	}
	printf("\n\n--");
}

int main()
{

	printf("Hello World");
	for(int i = 0; i< 20; i++)
	{
		numbers[i] = i;
	}
	int start = 0;

	root = create_node(numbers);

	for(int i = 1; i< 20; i++)
	{
		push_back(root, &numbers[i]);
	}

	pop_first(&root);
	pop_back(root);
	push_back(root, &num);
	push_first(&root, &num2);
	insert_by_index(&root, &num3, 8);
	inverse_list(&root);
	print_list();
	swap_elements_by_id(&root, 3,4);
	print_list();
	swap_elements_by_id(&root, 5,9);
	print_list();
	swap_elements_by_id(&root, 0,2);
	print_list();
	swap_elements_by_id(&root, 20,0);
	print_list();
	getchar( );
	return 0;

}


