#include "QuickSort_list.h"



void Quick_Sort_List(List* Data_list)
{
	if (Data_list->count<2)return;
	int count,i,j=0,k,buf;
	int Pivot = Data_list->front->data.x;
	List Left_List,Right_List;
	Right_List = Left_List = List_Init();
	Node* p = Data_list->front->p_Next;
	Node* p_BeGot; 
	
	count = Data_list->count;
	for (i=1; i < count; i++)
	{
		if (p == NULL)break;
		//p=p->p_Next;
		if (p->data.x < Pivot)
		{
			p_BeGot = p;
			p=p->p_Next;
			Get_Node(Data_list, p_BeGot);
			//printf("left:%d\n",p->data.x);
			Link_Node(&Left_List, p_BeGot);
			//Output_List(Left_List);
		}
		else if (p->data.x > Pivot)
		{
			p_BeGot = p;
			p=p->p_Next;
			Get_Node(Data_list, p_BeGot);
			Link_Node(&Right_List, p_BeGot);
		}
		else
		{
			p=p->p_Next;
		}
	}
	Quick_Sort_List(&Left_List);
	Quick_Sort_List(&Right_List);
	
	*Data_list = Link_List(&Left_List, Data_list);
	*Data_list = Link_List(Data_list, &Right_List);
	/*
	if (0)
		return;
	//Output_List(*Data_list);
	int temp,i,j=0,k,buf;
	int Pivot = Data_list->front->data.x;
	Node* p_Pivot = Data_list->front;
	Node* p = Data_list->front;
	for (i=1 ;i < (Data_list->count); i++)
	{
		p=p->p_Next;
		if (p->data.x < Pivot)
		{
			Link_Node_Head(Data_list, Get_Node(Data_list, p));
			j++;
		}
	}
	
	List Left_List,Right_List;
	if (j > 1)
	{
		Node* Left = Data_list->front->P_Last;
		
		Left_List = Creat_on_Now(Data_list->front, p_Pivot->P_Last, j);
		Quick_Sort_List(&Left_List);
		Left_List.rear->p_Next = p_Pivot;
		p_Pivot->P_Last = Left_List.rear;
		
		if (Left != NULL)
		{
			Left->p_Next = Left_List.front;
			Left_List.front->P_Last = Left;
		}
	}
	
	if (Data_list->count - j - 1> 1)
	{
		Node* Right = Data_list->rear->p_Next;
		
		Right_List = Creat_on_Now(p_Pivot->p_Next, Data_list->rear, Data_list->count - j - 1);
		Quick_Sort_List(&Right_List);
		Right_List.front->P_Last = p_Pivot;
		p_Pivot->p_Next = Right_List.front;
		
		if (Right != NULL)
		{
			Right->P_Last = Right_List.rear;
			Right_List.rear->p_Next = Right;
		}
	}
	*/
	
}

void maopao(int* a)
{
	int buf,i,j;
	for(i=0;i<Data_Length-1;++i)
	{
		for(j=0;j<Data_Length-i-1;++j)
		{
			if(a[j]>a[j+1])
			{
				buf=a[j];
				a[j]=a[j+1];
				a[j+1]=buf;
			}
			
		}
	}
}
/*
int check(int* a,int* b,int* Start_Data)
{
	int i;
	for(i=0;i<Data_Length;++i)
	{
		if (a[i] != b[i])
		{
			printf("´íÎóÁË\n");
			i = -100;
			break;
		}
	}
	
	if (i == -100)
	{
		for(i=0;i<Data_Length;++i)
		{
			printf("%d ",a[i]);
			printf("%d\n",b[i]);
		}
		printf("ÅÅÐòÇ°£º"); 
		for(i=0;i<Data_Length;++i)
		{
			printf("%d ",Start_Data[i]);
		}
		printf("\nÔÙÅÅ£º"); 
		Quick_Sort_List(a,0,Data_Length-1);
		
		for(i=0;i<Data_Length;++i)
		{
			printf("%d ",a[i]);
		}
		
		return 1;
	}
	return 0;
	
}
*/

int Check(List* Data_list)
{
	int i,flag=0;
	Node* p = Data_list->front;
	for(i=0;i<Data_list->count-1;++i)
	{
		
		if (NodeData(p) > NodeData(p->p_Next))
		{
			printf("´íÎóÁË%d\n",i);
			flag = 1;
		}
		p = p->p_Next;
	}
	return flag;
}

int NodeData(Node* node2find)
{
	if (node2find != NULL)return node2find->data.x;
	else 
	{
		return -1;
	}
	
}
