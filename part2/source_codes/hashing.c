#include "hashing.h"

#define N 97 // prime and odd


typedef struct student_node student_node;

struct student_node {
    char name[128];
    char AM[128];
    double grade;
    student_node *next;
};

static int hash_function(char *AM) {

    int i = 0, counter = 0;
    while (AM[i] != '\0')
        counter += (int) AM[i++];

    return counter % N;
}

static void insert_node(student_node *hash_array[], student_node *new_student) {

    int index = hash_function(new_student->AM);

    student_node *temp_next = hash_array[index];
    hash_array[index] = new_student;
    new_student->next = temp_next;
}

static void print_node(student_node *node) {
    printf("\n%-30s%-15s%-15.1lf%-15d", node->name, node->AM, node->grade, hash_function(node->AM));
}

static void print(student_node *hash_array[]) {
    printf("\n%-30s%-15s%-15s%-15s\n", "Name", "AM", "Grade", "Index"); //print header

    int i;
    for (i = 0; i < N; i++)
        if (hash_array[i]) {
            student_node *node = hash_array[i];
            while (node) {
                print_node(node);
                node = node->next;
            }

        }
}

static student_node *create_custom_node() {

    student_node *new_student;
    new_student = (student_node *) malloc(sizeof(student_node));

	printf("Give AM: ");
    scanf("%s", new_student->AM);

    char temp[128];
	printf("Give first name: ");
    scanf("%s", new_student->name);
	printf("Give last name: ");
    scanf("%s", temp);

    strcat(new_student->name, " ");
    strcat(new_student->name, temp);
	
	printf("Give grade: ");
    scanf("%lf", & (new_student->grade));
    new_student->next = NULL;

    return new_student;
}

static student_node *search(student_node *hash_array[], char *AM) {

    int index = hash_function(AM);
    student_node *node = hash_array[index];

    while (node && strcmp(node->AM, AM) != 0)
        node = node->next;

    return node;
}

static void modify(student_node *hash_array[], char *my_AM) {

    student_node *node = search(hash_array, my_AM);

    if (!node)
        printf("Not Found!");
    else {
        char ans;
        scanf("%c", & ans);
        printf("Do you want to change name? | y/n\n");
        scanf("%c", & ans);
        if (ans == 'y') {
            printf("Give new name\n");
            char temp[128];
            scanf("%s", node->name);
            scanf("%s", temp);

            strcat(node->name, " ");
            strcat(node->name, temp);
        }
        scanf("%c", & ans);
        printf("Do you want to change grade? | y/n\n");
        scanf("%c", & ans);
        if (ans == 'y') {
            printf("Give new grade\n");
            scanf("%lf", & node->grade);
        }
    }

}

static void delete(student_node *hash_array[], char *AM) {

    int index = hash_function(AM);
    student_node *node = hash_array[index];

    // 1. no chain
    if (!node)
        return;

    // 2. the first node of the chain is the one we search for
    if (strcmp(node->AM, AM) == 0) {
        hash_array[index] = node->next;
        free(node);
        return;
    }

    // 3. the node we search for is in the chain
    while (node->next && strcmp(node->next->AM, AM) != 0)
        node = node->next;

    // end of chain - not found
    if (!node->next)
        return;

    // found
    student_node *temp = node->next;
    node->next = node->next->next;
    free(temp);
}


static void create_students(FILE *fp, student_node *hash_array[]) {


    while (!feof(fp)) {
		student_node *new_student;
		new_student = (student_node *) malloc(sizeof(student_node));

		fscanf(fp, "%s", new_student->AM);

		char temp[128];
		fscanf(fp, "%s", new_student->name);
		fscanf(fp, "%s", temp);

		strcat(new_student->name, " ");
		strcat(new_student->name, temp);

		fscanf(fp, "%lf", &(new_student->grade));
		new_student->next = NULL;
		
		insert_node(hash_array, new_student);
    }
}


int menu3(int argc, char *argv[]) {

    if (argc != 2) { // no file selected
        printf("\n---\nplease give file location!!!\n---\n");
        return -1;
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (!fp) {
        printf("ERROR READING FROM FILE!\n");
        return -1;
    }
	
    student_node *hash_array[N];
	int i;
	for (i = 0; i < N; i++)
        hash_array[i] = NULL;

    create_students(fp,  hash_array);
    fclose(fp);
	
    int choice = -1;
    char key[128];
	
	student_node *temp = NULL;

	
    while (1) {
        printf("\nOptions:\n-------\n0.Search\n1.Insert\n2.Delete\n3.Modify\n4.Print Table\n5.Back to menu\n");
        scanf("%d", &choice);

		switch (choice) {
			case 0:
				// search
				printf("---\nInsert AM to search: ");
				scanf("%s", key);
				temp = search(hash_array, key);
				if (temp == NULL)
					printf("Not Found!");
				else
					print_node(temp);
				break;
			case 1:
				// insert
				temp = create_custom_node();
				insert_node(hash_array, temp);
				break;
			case 2:
				// delete
				printf("---\nInsert AM to delete: ");
				scanf("%s", key);
				delete(hash_array, key);
				break;
			case 3:
				// modify
				printf("---\nInsert AM to modify: ");
				scanf("%s", key);
				modify(hash_array, key);
				break;
			case 4:
				// print hash table
				print(hash_array);
				break;
			case 5:
				// exit
				return 0;
				break;
			default:
				printf("Invalid Option!\n");
				break;
        }
    }
	
    printf("Tree is Empty!\n");
	
	return 0;
}
