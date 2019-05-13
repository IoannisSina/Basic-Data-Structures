#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct student_node student_node;


struct student_node{
    char name[128];
    int AM;
    float grade;
    student_node *left;
    student_node *right;
};


// returns root
void insert_node(student_node* root, student_node* new_student) {

    if(new_student->AM < root->AM) {
        if(root->left == NULL)
            root->left = new_student;
        else
            insert_node(root->left, new_student);
    }
    else{
        if(root->right == NULL)
            root->right = new_student;
        else
            insert_node(root->right, new_student);
    }

}



student_node* create_students() {

    student_node* root = NULL;

    int i = 0;
    for(i=0;i<N;i++) {
        student_node *new_student;
        new_student = (student_node*)malloc(sizeof(student_node));

        scanf("%s", (new_student->name));
        scanf("%d", &(new_student->AM));
        scanf("%f", &(new_student->grade));
        new_student->left = NULL;
        new_student->right = NULL;

        printf("--------\n");

        if(root == NULL)
            root = new_student;
        else
            insert_node(root, new_student);
    }
  
  return root;

}


/*
student_node* find(student_node* root, int key){ // returns node with this AM
  
  while(root && key != root->AM)
  {
    if(key < root->AM)
      root = root->left;
    else if(key > root->AM)
      root = root->right;
  }
  
  return root;
}
*/

student_node* find(student_node *root, int key)
{
    if(!root || root->AM == key)
        return root;
    else if(key > root->AM)
        return find(root->right, key);
    else
        return find(root->left, key);
}




void search(student_node* root, int key){
  
  student_node* node = find(root, key);
  
  if(node == NULL)
    printf("Not Found!");
  else {
    printf("Name:%s\n", node->name);
    printf("AM:%d\n", node->AM);
    printf("Grade:%f\n", node->grade);
  }
  
}

void modify(student_node* root, int key){
  
  student_node* node = find(root, key);
  
  if(!node)
    printf("Not Found!");
  else {
    char ans;
    scanf("%c", &ans);
    printf("Do you want to change name? | y/n\n");
    scanf("%c", &ans);
    if(ans == 'y'){
      printf("Give new name\n");
      scanf("%s", node->name);
    }
    scanf("%c", &ans);
    printf("Do you want to change grade? | y/n\n");
    scanf("%c", &ans);
    if(ans == 'y'){
      printf("Give new grade\n");
      scanf("%f", &node->grade);
    }
  }
  
}



void in_order_print(student_node* root){

    if(root->left){
        //printf("l");
        in_order_print(root->left);
    }

    printf("Name: %s | AM: %d | Grade: %f\n", root->name, root->AM, root->grade);

    if(root->right){
        //printf("r");
        in_order_print(root->right);
    }
}

// call with root->left
student_node* rightmost_node(student_node* root){
    
	if(!root->right)
		return root;
	
	return rightmost_node(root->right);
}


student_node* delete(student_node* root, int key){
  
  if(!root)
    return NULL;
  
  if(key > root->AM)
    root->right = delete(root->right, key);
  else if(key < root->AM)
    root->left = delete(root->left, key);
  else // key == root->AM
  {
    // 0 children
    if(!root->left && !root->right)
    {
      free(root);
      return NULL;
    }
    
    // 1 childer
    else if(!root->left || !root->right)
    {
      student_node* to_return = root->left ? root->left : root->right;
      
      free(root);
      
      return to_return;
    }
    
    else  // 2 children
    {
      student_node* temp = rightmost_node(root->left);

      int AM = temp->AM;
      float grade = temp->grade;
      //char name[128] = temp->name;
      
      delete(root, temp->AM);  // 0 or 1 children	---  ANTI GIA delete(root, AM);
      
      root->AM = AM;
      root->grade = grade;
      //root->name = name;
	  
	  //return root...
    }
    
  }
  
  return root;
  
}



// 6 -> 7 -> 10-|> 10 -> 65





/*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /     \    \
               /       \    \
              9        29   45
            /   \          /
           /     \        /
          7      12      42
*/




int main()
{
    student_node* root;
    root = create_students();
  
    in_order_print(root);
  
    int key;
    //search(root, key);
  
    printf("\n---\nInsert key to modify: ");
    scanf("%d", &key);
    modify(root, key);
  
    printf("\n---\nInsert key to delete: ");
    scanf("%d", &key);
    delete(root, key);
  
    in_order_print(root);

    return 0;
}
