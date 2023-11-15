#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "QuickSort_list.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() //int argc, char *argv[]
{
	List List_1;
	
	List_1 = Create_List();
	/*
	Output_List(List_1);
	Add_to_List(&List_1);
	
	Del_List_Data(&List_1);
	
	Invert_List(&List_1);
	*/
	Quick_Sort_List(&List_1);
	printf("END\n");
	//Output_List(List_1);
	//Check(&List_1);
	
	
	Free_List(&List_1);
	return 0;
}
