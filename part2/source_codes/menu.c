#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstA.h"
#include "bstB.h"
#include "hashing.h"


int main(int argc, char * argv[]) {
		
	if(argc != 2) { // no file selected
		printf("\n---\nplease give file location!!!\n---\n");
		return -1;
	}
	
	while(1) {
		printf("\n---\nOptions:\n");
		printf("0-> BST\n1-> HASHING\n2-> EXIT\n");
		printf("Your option: ");
		int option;
		scanf("%d", &option);
		
		switch (option) {
			case 0:
			printf("\n---\nOptions:\n");
				printf("0-> AM\n1-> GRADE\n2-> BACK\n");
				printf("Your option: ");
				int option;
				scanf("%d", &option);
				if (option == 0)
					menu1(argc, argv);
				else if (option == 1)
					menu2(argc, argv);
				else if (option != 2)
					printf("Invalid option!\n");
				break;
			case 1:
				menu3(argc, argv);
				break;
			case 2:
				return 0;
				break;
			default:
				printf("Invalid option!\n");
				break;
		}
	}
	
    return 0;
}
