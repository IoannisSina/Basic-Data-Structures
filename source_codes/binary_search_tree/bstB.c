#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student_node student_node;

struct student_node {
    char name[128];
    char AM[128];
    double grade;
    student_node* left;
    student_node* right;
    student_node* next;
};

// returns root
student_node* insert_node(student_node* root, student_node* new_student) {

    if (!root)
        return new_student;

    if (new_student->grade < root->grade)
        root->left = insert_node(root->left, new_student);
    else if (new_student->grade > root->grade)
        root->right = insert_node(root->right, new_student);
    else
        root->next = insert_node(root->next, new_student);

    return root;
}


student_node* create_students(FILE* fp) {

    student_node* root = NULL;

    while (!feof(fp)) {

        student_node* new_student;
        new_student = (student_node*) malloc(sizeof(student_node));

        fscanf(fp, "%s", new_student->AM);

        char temp[128];
        fscanf(fp, "%s", new_student->name);
        fscanf(fp, "%s", temp);

        strcat(new_student->name, " ");
        strcat(new_student->name, temp);

        fscanf(fp, "%lf", &(new_student->grade));
        new_student->left = NULL;
        new_student->right = NULL;
        new_student->next = NULL;

		// free the left & right
		
        root = insert_node(root, new_student);
    }

    return root;
}

student_node* search(student_node* root, double key) {
    if (!root || root->grade == key)
        return root;
    else if (key > root->grade)
        return search(root->right, key);
    else
        return search(root->left, key);
}


/*void modify(student_node* root, double key) {

    student_node* node = search(root, key);

    if (!node)
        printf("Not Found!");
    else {
    	char AM_to_search[128];
        scanf("%s", AM_to_search);
        char ans;
        scanf("%c", &ans);
        printf("Do you want to change name? | y/n\n");
        scanf("%c", &ans);
        if (ans == 'y') {
            printf("Give new name\n");
            char temp[128];
            scanf("%s", node->name);
            scanf("%s", temp);

            strcat(node->name, " ");
            strcat(node->name, temp);
        }
        scanf("%c", &ans);
        printf("Do you want to change grade? | y/n\n");
        scanf("%c", &ans);
        if (ans == 'y') {
            printf("Give new grade\n");
            scanf("%lf", &node->grade);
        }
    }

}*/

void print_same_nodes(student_node* root) {
	do {
		printf("%-30s%-15s%-15.1lf\n", root->name, root->AM, root->grade);
		root = root->next;
	}while(root);
}

void in_order_print(student_node* root) {

    if (root->left) {
        in_order_print(root->left);
	}

    print_same_nodes(root);

    if (root->right) {
        in_order_print(root->right);
	}
}

void print_tree(student_node* root) {
	printf("%-30s%-15s%-15s\n", "Name", "AM", "Grade");		//print header
	printf("%.*s\n", 60, "======================================================================================================================");
	in_order_print(root);
}


student_node* rightmost_node(student_node* root) {

    if (!root->right)
        return root;

    return rightmost_node(root->right);
}


student_node* leftmost_node(student_node* root) {

    if (!root->left)
        return root;

    return leftmost_node(root->left);
}

void delete_same_grades(student_node* root) {
	
	if(!root)
		return;
	
	delete_same_grades(root->next);

	free(root);
}


student_node* delete(student_node* root, double key) {

    if (!root) {
		printf("Not Found!");
        return NULL;
	}

    if (key > root->grade)
        root->right = delete(root->right, key);
    else if (key < root->grade)
        root->left = delete(root->left, key);
    else // key == root->grade
    {
        // 0 children
        if (!root->left && !root->right) {
			delete_same_grades(root);

            return NULL;
        }
        // 1 children
        else if (!root->left || !root->right) {
            student_node* to_return = root->left ? root->left : root->right;

			delete_same_grades(root);

        return to_return;
    }
	// 2 children
	else {
            student_node* to_delete_node = rightmost_node(root->left);
			
			// copy all elements of the rightmost root of the left subtree to the root
			strcpy(root->AM, to_delete_node->AM);
            root->grade = to_delete_node->grade;
            strcpy(root->name, to_delete_node->name);
			
			// switch the pointers of the two nodes to point at the right siblings
			student_node* temp_next = to_delete_node->next;
			to_delete_node->next = root->next;
			root->next = temp_next;

            root->left = delete(to_delete_node, to_delete_node->grade); // 0 or 1 children
        }

    }

    return root;
}

void create_custom_node(student_node* root) {

    student_node* new_student;
    new_student = (student_node* ) malloc(sizeof(student_node));

    scanf("%s", new_student->AM);

    char temp[128];
    scanf("%s", new_student->name);
    scanf("%s", temp);

    strcat(new_student->name, " ");
    strcat(new_student->name, temp);

    scanf("%lf", &(new_student->grade));
    new_student->left = NULL;
    new_student->right = NULL;
    new_student->next = NULL;

    root = insert_node(root, new_student);
}

int main(int argc, char* argv[]) {

    if(argc < 1)
		return -1; // no file selected

	FILE* fp;
    fp = fopen(argv[1], "r");

    student_node* root;
    root = create_students(fp);
	
	fclose(fp);

    int choice = -1;
    double key;

    while (root && choice != 7) {
        printf("\nOptions:\n-------\n0.Search\n1.Insert\n2.Delete\n3.Modify\n4.Print Tree\n5.Min\n6.Max\n7.Exit\n");
        scanf("%d", &choice);

        if(choice == 0) {
            // search
            printf("---\nInsert key to search: ");
            scanf("%lf", &key);
            student_node* node = search(root, key);
            if (node == NULL)
                printf("Not Found!");
            else
		print_same_nodes(node);
	}
        else if(choice == 1)
	    // insert
            create_custom_node(root);
        else if(choice == 2) {
            // delete
            printf("---\nInsert key to delete: ");
            scanf("%lf", &key);
            root = delete(root, key);
}
        /*if(choice == 3) {
            // modify
            printf("---\nInsert key to modify: ");
            scanf("%s", key);
            modify(root, key);
            break;*/
        else if(choice == 4) {
            // print tree
            print_tree(root);
}
        else if(choice == 5) {
            // min

	    student_node* min = leftmost_node(root);
	    print_same_nodes(min);
}
        else if(choice == 6) {
	    // max

	    student_node* max = rightmost_node(root);
	    print_same_nodes(max);
}
        else if(choice == 7) {
	    // exit
}
        else {
            printf("Invalid Option!\n");
        }
    }
	
	if(!root)
		printf("Tree is Empty!\n");

    return 0;
}
