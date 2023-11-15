#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "node.h"

Node* Create_Node(Data Indata)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data.x = Indata.x;
	p->p_Next = NULL;
	p->P_Last = NULL;
	return p;
}

void Link_Node( List* Cre_List, Node* p_Node)
{
	if (Cre_List == NULL || p_Node == NULL)return;
	
	Cre_List->count++;
	if (Cre_List->count == 1)
	{
		Cre_List->front = Cre_List->rear = p_Node;		
		return;
	}
	
	Node* pLast_rear = Cre_List->rear;
	Cre_List->rear = p_Node;
	p_Node->P_Last = pLast_rear;
	pLast_rear->p_Next = Cre_List->rear;

}

void Link_Node_Head(List* Cre_List, Node* p_Node) 
{
	if (Cre_List == NULL || p_Node == NULL)return;
	
	Cre_List->count++;
	if (Cre_List->count == 1)
	{
		Cre_List->front = Cre_List->rear = p_Node;
		Cre_List->count++;
		return;
	}
	
	Node* pLast_Front = Cre_List->front;
	Cre_List->front = p_Node;
	Cre_List->front->p_Next = pLast_Front;
	pLast_Front->P_Last = Cre_List->front;
	
}

void Get_Node(List* Change_list, Node* p_GetNode)
{
	if (Change_list == NULL || p_GetNode == NULL)return;
	Change_list->count--;
	if (p_GetNode != Change_list->front && p_GetNode != Change_list->rear)
	{
		p_GetNode->P_Last->p_Next = p_GetNode->p_Next;
		p_GetNode->p_Next->P_Last = p_GetNode->P_Last;
		
		p_GetNode->P_Last = p_GetNode->p_Next = NULL;
	}
	else
	{
		if (p_GetNode == Change_list->front)
		{
			Change_list->front = p_GetNode->p_Next;
			p_GetNode->p_Next->P_Last = NULL;
			
			p_GetNode->p_Next = NULL;
		}
		else
		{
			Change_list->rear = p_GetNode->P_Last;
			p_GetNode->P_Last->p_Next = NULL;
			
			p_GetNode->P_Last = NULL;
		}
	}
	
}



