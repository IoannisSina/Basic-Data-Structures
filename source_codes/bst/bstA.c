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
};

// returns root
student_node* insert_node(student_node* root, student_node* new_student) {

    if (!root)
        return new_student;

    if (strcmp(new_student->AM, root->AM) < 0)
        root->left = insert_node(root->left, new_student);
    else
        root->right = insert_node(root->right, new_student);

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

        root = insert_node(root, new_student);
    }

    fclose(fp);

    return root;
}

student_node* search(student_node* root, char* key) {
    if (!root || strcmp(root->AM, key) == 0)
        return root;
    else if (strcmp(key, root->AM) > 0)
        return search(root->right, key);
    else
        return search(root->left, key);
}

void modify(student_node* root, char* key) {

    student_node* node = search(root, key);

    if (!node)
        printf("Not Found!");
    else {
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

}

void print_node(student_node* root) {
	printf("%-30s%-15s%-15.1lf\n", root->name, root->AM, root->grade);
}

void in_order_print(student_node* root) {

    if (root->left)
        in_order_print(root->left);

    print_node(root);

    if (root->right)
        in_order_print(root->right);
}

void print_tree(student_node* root) {
	printf("%-30s%-15s%-15s\n", "Name", "AM", "Grade");		//print header
	printf("%.*s\n", 60, "======================================================================================================================");
	in_order_print(root);
}


// call with root->left
student_node* rightmost_node(student_node* root) {

    if (!root->right)
        return root;

    return rightmost_node(root->right);
}

student_node* delete(student_node* root, char* key) {

    if (!root) {
		printf("Not Found!");
        return NULL;
	}

    if (strcmp(key, root->AM) > 0)
        root->right = delete(root->right, key);
    else if (strcmp(key, root->AM) < 0)
        root->left = delete(root->left, key);
    else // key == root->AM
    {
        // 0 children
        if (!root->left &&!root->right) {
            free(root);
            return NULL;
        }
        // 1 children
        else if (!root->left || !root->right) {
            student_node* to_return = root->left ? root->left : root->right;
            free(root);
            return to_return;
        }
		// 2 children
		else {
            student_node* to_delete_node = rightmost_node(root->left);
			
			// copy all elements of the rightmost root of the left subtree to the root

			strcpy(root->AM, to_delete_node->AM);
            root->grade = to_delete_node->grade;
            strcpy(root->name, to_delete_node->name);

            root->left = delete(to_delete_node, to_delete_node->AM); // 0 or 1 children
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

    root = insert_node(root, new_student);
}

int main(int argc, char* argv[]) {

    if(argc < 1)
		return -1; // no file selected

	FILE* fp;
    fp = fopen(argv[1], "r");

    student_node* root;
    root = create_students(fp);

    int choice = -1;
    char key[128];

    while (root && choice != 5) {
        printf("\nOptions:\n-------\n0.Search\n1.Insert\n2.Delete\n3.Modify\n4.Print Tree\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            // search
            printf("---\nInsert key to search: ");
            scanf("%s", key);
            student_node* node = search(root, key);
            if (node == NULL)
                printf("Not Found!");
            else {
                printf("Name:%s\n", node->name);
                printf("AM:%s\n", node->AM);
                printf("Grade:%lf\n", node->grade);
            }
            break;
        case 1:
            create_custom_node(root);
            break;
        case 2:
            // delete
            printf("---\nInsert key to delete: ");
            scanf("%s", key);
            root = delete(root, key);
            break;
        case 3:
            // modify
            printf("---\nInsert key to modify: ");
            scanf("%s", key);
            modify(root, key);
            break;
        case 4:
            // print tree
            print_tree(root);
            break;
        case 5:
            // exit
            break;
        default:
            printf("Invalid Option!\n");
        }

    }
	
	if(!root)
		printf("Tree is Empty!\n");

    return 0;
}
