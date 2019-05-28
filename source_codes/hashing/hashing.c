#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 3

typedef struct student_node student_node;

struct student_node {
    char name[128];
    char AM[128];
    double grade;
    student_node* next;
};


int hash_function(char* AM) {
  
  int i=0, counter=0;
  while( AM[i] != '\0' )
    counter += (int)AM[i++];
  
  return counter%N;
}



void insert_node(student_node* hash_array[], student_node* new_student) {
  
  int index = hash_function(new_student->AM);
  
  student_node* temp_next = hash_array[index];
  hash_array[index] = new_student;
  new_student->next = temp_next;
}



void print_node(student_node* node) {
  printf("\n%-30s%-15s%-15.1lf%-15d", node->name, node->AM, node->grade, hash_function(node->AM));
}


void print(student_node* hash_array[]) {
  printf("\n%-30s%-15s%-15s%-15s\n", "Name", "AM", "Grade", "Index");    //print header
  
  int i;
  for(i=0;i<N;i++)
    if(hash_array[i])
    {
      student_node* node = hash_array[i];
      while(node) {
        print_node(node);
        node = node->next;
      }
      
    }
  
}



student_node* create_custom_node() {

    student_node* new_student;
    new_student = (student_node* ) malloc(sizeof(student_node));

    scanf("%s", new_student->AM);

    char temp[128];
    scanf("%s", new_student->name);
    scanf("%s", temp);

    strcat(new_student->name, " ");
    strcat(new_student->name, temp);

    scanf("%lf", &(new_student->grade));
    new_student->next = NULL;

  
    return new_student;
}



student_node* search(student_node* hash_array[], char* AM) {
  
  int index = hash_function(AM);
  student_node* node = hash_array[index];
  
  while(node && strcmp(node->AM, AM) != 0)
    node = node->next;
  
  return node;
}


// AM
// ONOMATEPONYMO
// GRADE


void modify(student_node* hash_array[], char* my_AM) {

    student_node* node = search(hash_array, my_AM);
  
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


void delete(student_node* hash_array[], char* AM) {
  
  int index = hash_function(AM);
  student_node* node = hash_array[index];
  
  // 1. no chain
  if(!node)
    return;
  
  // 2. the first node of the chain is the one we search for
  if(strcmp(node->AM, AM) == 0) {
    hash_array[index] = node->next;
    free(node);
    return;
  }
  
  
  // 3. the node we search for is in the chain
  while(node->next && strcmp(node->next->AM, AM) != 0)
      node = node->next;
  
  
  // end of chain - not found
  if(!node->next)
    return;
  
  // found
  student_node* temp = node->next;
  node->next = node->next->next;
  free(temp);
}





int main() {
  
  student_node* hash_array[N];
  int i;
  for(i=0;i<N;i++)
    hash_array[i] = NULL;
  
  for(i=0;i<10;i++) {
    student_node* new_student = create_custom_node();
    insert_node(hash_array, new_student);
  }

  //print(hash_array);
  
  
  // SEARCH
  /*student_node* found = search(hash_array, my_AM); // Makris
  if(!found)
    printf("NOT FOUND");
  else
    print_node(found);*/
  
  // MODIFY
  //modify(hash_array, my_AM);
  
  print(hash_array);
  // DELETE
  
  char my_AM[128];
  while(1) {
    scanf("%s", my_AM);
    delete(hash_array, my_AM);
    print(hash_array);
  }
  
  return 0;
}
