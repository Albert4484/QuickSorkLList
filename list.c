#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"
#include "QuickSort_list.h"
#include<time.h>


/*****************************
*	�������ܣ�	�����Ӽ��������������������У�
*			  	��-1 ��ʾ������-1 ��������У���
*	��ڲ�����	�ޡ� 
*	return: List
******************************/
	
List Create_List()
{
	List Cre_List;
	Data indata;
	
	Cre_List.count = 0;
	Cre_List.front = Cre_List.rear = NULL;
	
	Node *p_Node;

	int i;
	
	srand(time(NULL));
	for(i=0;i<Data_Length;++i)
	{
		
		indata.x = rand()%10000000+1;
		p_Node = Create_Node(indata);
		
		Link_Node(&Cre_List, p_Node);
		
	}

	/***********
	int n,m;
	scanf("%d%d", &n, &m);
	while(getchar() != '\n');
	int i;
	for (i=0; i<m; i++)
	{
		
		scanf("%d",&indata.x);
		//if (indata.x == -1)break;
		p_Node = Create_Node(indata);
		
		Link_Node( &Cre_List, p_Node);
	}
	*****************/
	return Cre_List;
}

/*************************************
�����е��б�����ϴ����б� 
************************************/
List Creat_on_Now(Node* pStart, Node* pLast, int count)
{
	List Cre_List;
	Cre_List.front = pStart;
	Cre_List.rear = pLast;
	Cre_List.count = count;
	Cre_List.front->P_Last = Cre_List.rear->p_Next = NULL;
	return Cre_List;
} 


List List_Init(void)
{
	List NewList;
	NewList.count = 0;
	NewList.front = NewList.rear = NULL;
	return NewList;
}
/*************************
������㿪ʼ��num��node 
**************************/
Node* P_Data(List *list2find, unsigned int num)
{
	if (list2find->count-1 < num)return (Node*)NULL;
	
	Node* p;
	if (list2find->count > num*2)
	{
		p = list2find->front;
		int i;
		for (i=0; i<num; i++)
		{
			p = p->p_Next;
		}
		
	}
	else
	{
		p = list2find->rear;
		int i;
		for (i=0; i<list2find->count-num-1; i++)
		{
			p = p->P_Last;
		}
				
	}
	return p;
}

List Link_List(List* Head,List* Tail)
{
	List Sum_List = List_Init();
	//if (Head == NULL || Tail == NULL)return *(Head^Tail);
	if (!Head->count || Head == NULL)return *Tail;
	if (!Tail->count || Tail == NULL)return *Head;
	Sum_List.count = Head->count + Tail->count;
	Sum_List.front = Head->front;
	Sum_List.rear = Tail->rear;
	
	Head->rear->p_Next = Tail->front;
	Tail->front->P_Last = Head->rear;
	return Sum_List;
}

/************************************************
*	�������ܣ�������� 
*	��ڲ�����Out_List��Ҫ����ı� 
*	return:�ޡ� 
*************************************************/
void Output_List(List Out_List)
{
	if (Out_List.count == 0)return;
	int i;
	Node* p;
	p = Out_List.front;
	for( i=0; i<Out_List.count; i++)
	{	
		/*********************
		if (i%5 == 0)printf("\n");
		printf("L%-3d:%-4d\t",i,p->data.x);
		***********************/
		/******************/
		printf("%d ",p->data.x);
		/****************/
		//if (p->p_Next == NULL)break;
		p = p->p_Next;
	}
	printf("\n");
}

/************************************************
*	�������ܣ�	������ָ��λ�ò���һ�����ݣ�����Ľڵ�
*				λ��Ϊ�������룬��������С�			
*	��ڲ�����Add_List��������ı��ָ�롣 
*	return:�ޡ�
*************************************************/
void Add_to_List(List* Add_List)
{
	int site;
	Node* p_node,p;
	Data in_data; 
	printf("\n����λ�ã�");
	scanf("%d",&site);
	if (site < 0 || site > Add_List->count)
	{
		printf("\nλ�ô��󣡣���");
		return;
	}
	printf("\n�������ݣ�");
	scanf("%d",&in_data); 
	p_node = Create_Node(in_data);
	
	if (Add_List->count == 0)
	{
		Add_List->front = Add_List->rear = p_node;
		Add_List->count++;
		Output_List(*Add_List);
		return;
	}
	
	if (site == 0)
	{
		Add_List->front->P_Last = p_node;
		p_node->p_Next = Add_List->front;
		Add_List->front = p_node;
	}
	else if (site == Add_List->count)
	{
		Add_List->rear->p_Next = p_node;
		p_node->P_Last = Add_List->rear;
		Add_List->rear = p_node;
	}
	else
	{
		int i;
		Node *p = Add_List->front;
		for ( i=0; i<site-1; ++i)
		{
			p = p->p_Next;
		}
		p_node->p_Next = p->p_Next;
		p_node->P_Last = p;
		p->p_Next = p_node;
		p_node->p_Next->P_Last = p_node;
	}
	
	Add_List->count++;
	Output_List(*Add_List);
}

/************************************************
*	�������ܣ�	��ɾ���������еĸ������������
*				�ɹ�������Ա����ݡ�			
*	��ڲ�����	Del_List����ɾ���ı��ָ�롣 
*	return:�ޡ�
*************************************************/
void Del_List_Data(List* Del_List)
{
	if (Del_List->count == 0)return;
	Node *p,*p2;
	if (Del_List->count == 1)
	{
		if (Del_List->front->data.x < 0)
		{
			free(Del_List->front);
			Del_List->front = Del_List->rear = NULL;
			Del_List->count--;
		}
		Output_List(*Del_List);
		return;
	}
	
	p = Del_List->front->p_Next;
	
	while(p->p_Next != NULL)
	{
	
		if (p->data.x < 0)
		{
			
			p->P_Last->p_Next = p->p_Next;
			p->p_Next->P_Last = p->P_Last;
			Del_List->count--;
			
			p2 = p;
			p = p->p_Next;
			free(p2);
			
		}
		else p = p->p_Next;
				
		
	}	
	if (Del_List->front->data.x < 0)
	{
		p = Del_List->front;
		Del_List->front->p_Next->P_Last = NULL;
		Del_List->front = Del_List->front->p_Next;
		Del_List->count--;
		
		free(p);
	}
	if (Del_List->rear->data.x < 0)
	{
		p = Del_List->rear;
		Del_List->rear->P_Last->p_Next = NULL;
		Del_List->rear = Del_List->rear->P_Last;
		Del_List->count--;
		
		free(p);
	}
	Output_List(*Del_List);
}

/************************************************
*	�������ܣ�	��ת���Ա��е�Ԫ�أ��������
*				�ɹ�������Ա����ݡ�			
*	��ڲ�����	Inv_List: ����ת�����Ա��ָ�롣
*	return:		�ޡ�
*************************************************/
void Invert_List(List* Inv_List)
{
	if (Inv_List->count == 0  || Inv_List->count == 1)return;
	Node *p,*p_buf;
	
	p = Inv_List->front->p_Next;
	
	while(p->p_Next != NULL)
	{
		
		p_buf = p->p_Next;
		p->p_Next = p->P_Last;
		p->P_Last = p_buf;
		p = p->P_Last;
	}
	
	Inv_List->front->P_Last = Inv_List->front->p_Next;
	Inv_List->front->p_Next = NULL;

	Inv_List->rear->p_Next = Inv_List->rear->P_Last;
	Inv_List->rear->P_Last = NULL;
	
	p_buf = Inv_List->front;
	Inv_List->front = Inv_List->rear;
	Inv_List->rear = p_buf;
	
	Output_List(*Inv_List);
}

void Free_List(List *Free_List)
{
	if (Free_List->count == 0)return;
	Node *p;
	p = Free_List->front;
	while(p->p_Next != NULL)
	{
		p = p->p_Next;
		free(p->P_Last);
	}
	free(Free_List->rear);
	
}

