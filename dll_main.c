#include <errno.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "../include/dll_header.h"

void main() 
{
	int status, option;
	unsigned int data, idx;
	void *temp, *head = NULL;
	FILE *fptr = stdout;

	while(1) {
		printf("\n\n\t\t>>>>> MENU <<<<<\n 0-Exit\n 1-Init the list\n ");
		printf("2-Insert node in specific location\n 3-Delete the list\n ");
		printf("4-Print list\n 5-Retrive data from the position\n 6-Update node ");
		printf("data at position\n 7-Remove the node at positon\n 8-Remove the ");
		printf("nodes with the specific data\n 9-Delete consective duplicate nodes data");
		printf("\nSelect the option : ");
		__fpurge(stdin);
		scanf("%d", &option);

		switch (option) {
		case 0: 
			printf("\n\t\t\n");
			exit(0);
		case 1: 
			printf("\n\nEnter the list size to initialise: ");
			__fpurge(stdin);
			scanf("%u", &data);

			temp = dll_init_list(head, data);
			
			if (temp == NULL) {
				printf("\n\t\t Not initialised, already the list size fixed.\n");
			} else {
				head = temp;
				printf("\n\t\t The list size is intialised\n");
			}

			break;
		case 2:
			printf("\n\nEnter the position : ");
			__fpurge(stdin);
			scanf("%u", &idx);

			printf("\n\nEnter the data : ");
			__fpurge(stdin);
			scanf("%u", &data);

			status = dll_insert_node(head, idx, data);

			if (status == -EIO)
				printf("\n\t\t List not initialised, Init the list first\n");
			else if (status == -ERANGE) 
				printf("\n\t\t Node not inserted, List size is intilaised with zero\n");
			else if (status == -ELNRNG)
				printf("\n\t\t Node not inserted, The nodes in list is upto max\n");
			else if (status == -ENOMEM)
				printf("\n\t\t Node not inserted, Failed to alloc memory\n");
			else if (status == -EINVAL)
				printf("\n\t\t Node not inserted, The position not found\n");
			else
				printf("\n\t\t The node is inserted");

			break;
		case 3:
			status = dll_delete_list(head);

			if (status == -EIO)
				printf("\n\t\t Failed to delete list, List doesn't exist\n");
			else if (status == -ENODATA)
				printf("\n\t\t Failed to delete list, The list is empty\n");
			else
				printf("\n\t\tThe list is Deleted\n");

			break;
		case 4:               
			printf("\nthe data : ");

			status = dll_print_list(head, fptr);

			if (status == -EIO)
				printf("\n\t\t Failed to print list, List doesn't exist\n");
			else if (status == -ENODATA)
				printf("\n\t\t Failed to print, The list is empty\n");
			else
				printf("\n");

			break;
		case 5:
			printf("\n\nEnter the index to find the data : ");
			__fpurge(stdin);
			scanf("%u", &idx);

			status = dll_retrive_data(head, idx, &data);

			if (status == -EIO)
				printf("\n\t\t Failed to retrive data, List doesn't exist\n");
			else if (status == -ENODATA) 
				printf("\n\t\t Failed to retrive data, List is empty\n");
			else if (status == -EINVAL)
				printf("\n\t\t Failed to retrive, Position is not found\n");
			else
				printf("\n\t\t The data is retrived from that index is %u\n",data);

			break;
		case 6:
			printf("\n\nEnter the position : ");
			__fpurge(stdin);
			scanf("%u", &idx);

			printf("\n\nEnter the data : ");
			__fpurge(stdin);
			scanf("%u", &data);

			status = dll_update_data(head, idx, data);

			if (status == -EIO)
				printf("\n\t\t Failed to update data, List doesn't exist\n");
			else if (status == -ENODATA) 
				printf("\n\t\t Failed to update data, The list is empty\n");
			else if (status == -EINVAL)
				printf("\n\t\t Failed to update data, Position not found\n");
			else
				printf("\n\t\t The data is updated in that position\n");

			break;
		case 7:
			printf("\n\nEnter the index to remove the node : ");
			__fpurge(stdin);
			scanf("%u", &idx);

			status = dll_remove_node(head, idx);

			if (status == -EIO)
				printf("\n\t\t Failed to remove node, List doesn't exist\n");
			else if (status == -ENODATA) 
				printf("\n\t\t Failed to remove node, The list is empty\n");
			else if (status == -EINVAL)
				printf("\n\t\t Failed to remove node, Position not found\n");
			else	
				printf("\n\t\t The node is removed from that position\n");

			break;
		case 8:
			printf("\n\nEnter the data to remove the all node with that data : ");
			__fpurge(stdin);
			scanf("%u", &data);

			status = dll_remove_nodes_with_specific_data(head, data);

			if (status == -EIO)
				printf("\n\t\t Failed to remove nodes, List doesn't exist\n");
			else if (status == -ENODATA) 
				printf("\n\t\t Failed to remove nodes, The list is empty\n");
			else if (status == -EINVAL)
				printf("\n\t\t Failed to remove nodes, Data is not found in list\n");
			else 
				printf("\n\t\t Nodes with data : %d is removed from the list\n", data);

			break;
		case 9:
			status = consecutive_duplicates(head);

			if (status == -EIO)
				printf("\n\t\tFailed to remove nodes, List doesn't exist\n");
			else if (status == -ENODATA) 
				printf("\n\t\t Failed to remove nodes, The list is empty\n");
			else if (status == -EINVAL)
				printf("\n\t\t Failed to remove nodes, NO consecutive nodes\n");
			else
				printf("\n\t\t removed nodes\n");

			break;
		default:
			printf("\n\t\t Enter the valid option\n");

		}
	}
}
