#ifndef List_H

#define List_H


typedef struct Data
{
	int x;
}Data;

typedef struct Node
{
	Data data;
	struct Node* p_Next;
	struct Node* P_Last;
}Node;

typedef struct List
{
	Node* 	front;
	Node* 	rear;
	int 	count;
}List;



List Create_List(void);
List Creat_on_Now(Node* pStart, Node* pLast, int count);
List List_Init(void);
List Link_List(List* Head,List* Tail);

void Output_List(List Out_List);
void Add_to_List(List* Add_List);
void Del_List_Data(List* Del_List);
void Invert_List(List* Inv_List);
Node* P_Data(List *list2find, unsigned int num);

#endif
