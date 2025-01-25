#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BSTnode
{
    char word[50], meaning[100];
    //char synonym[50], char antonym[50];
    struct BSTnode *left, *right;
} *root = NULL;

FILE *file;

struct BSTnode * createNode (char *word, char *meaning) {
        struct BSTnode *newnode;
        newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        strcpy(newnode->word, word);
        strcpy(newnode->meaning, meaning);
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
  }

  void insert (char *word, char *meaning) {
        struct BSTnode *parent = NULL, *current = NULL, *newnode = NULL;
        int res = 0;
        if (!root) {
                root = createNode (word, meaning);
                return;
        }
        for (current = root; current !=NULL;
           current = (res > 0) ? current->right : current->left) {
                res = strcasecmp(word, current->word);
                if (res == 0) {
                        printf("Duplicate Entry! \n");
                        return;
                }
                parent = current;
        }
        newnode = createNode(word, meaning);
        res > 0 ? (parent->right = newnode) : (parent->left = newnode);
        return;
  }

  void deleteNode(char *str) {
        struct BSTnode *parent = NULL, *current = NULL, *temp = NULL;
        int flag = 0, res = 0;
        if (!root) {
                printf("D I C T I O N A R Y  IS  E M P T Y ! \n");
                return;
        }
        current = root;
        while (1) {
                res = strcasecmp(current->word, str);
                if (res == 0)
                        break;
                flag = res;
                parent = current;
                current = (res > 0) ? current->left : current->right;
                if (current == NULL)
                        return;
        }
        // for leaf node
        if (current->right == NULL) {
                if (current == root && current->left == NULL) {
                        free(current);
                        root = NULL;
                        return;
                } else if (current == root) {
                        root = current->left;
                        free (current);
                        return;
                }

                flag > 0 ? (parent->left = current->left) :
                                (parent->right = current->left);
        } else {
                // for single child
                temp = current->right;
                if (!temp->left) {
                        temp->left = current->left;
                        if (current == root) {
                                root = temp;
                                free(current);
                                return;
                        }
                        flag > 0 ? (parent->left = temp) :
                                        (parent->right = temp);
                } else {
                        // for double child
                        struct BSTnode *successor = NULL;
                        while (1) {
                                successor = temp->left;
                                if (!successor->left)
                                        break;
                                temp = successor;
                        }
                        temp->left = successor->right;
                        successor->left = current->left;
                        successor->right = current->right;
                        if (current == root) {
                                root = successor;
                                free(current);
                                return;
                        }
                        (flag > 0) ? (parent->left = successor) :
                                        (parent->right = successor);
                }
        }
        free (current);
        return;
  }

  void findElement(char *str) {
        struct BSTnode *temp = NULL;
        int flag = 0, res = 0;
        if (root == NULL) {
                printf("D I C T I O N A R Y  IS  E M P T Y ! \n");
                return;
        }
        temp = root;
        while (temp) {
                if ((res = strcasecmp(temp->word, str)) == 0) {
                        printf("Word   : %s", str);
                        printf("Meaning: %s", temp->meaning);
                        flag = 1;
                        break;
                }
                temp = (res > 0) ? temp->left : temp->right;
        }
        if (!flag)
                printf("Element not found in Dictionary! \n");
        return;
  }

  void inorderTraversal(struct BSTnode *myNode) {
        if (myNode) {
                inorderTraversal(myNode->left);
                printf("Word    : %s", myNode->word);
                printf("Meaning : %s", myNode->meaning);
                printf("\n");
                inorderTraversal(myNode->right);
        }
        else {
            printf("D I C T I O N A R Y  IS  E M P T Y ! \n");
        }
        return;
  }


int main()
{
    printf("                                    =====================================\n");
    printf("                                    | CHITTAGONG INDEPENDENT UNIVERSITY |");
    printf("\n                                    =====================================\n");
    printf("\n                                        Course Name : Data Structure Lab\n");
    printf("                                        Course Code : CSE205L\n");
    printf("                                        Semester : Summer 2023\n\n");

    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("                                      PROJECT NAME:  DICTIONARY USING BST\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");

    printf("\n\tSubmitted By:\t\t\t\t||\t    Submitted To:\n");
    printf("  Name: PIAL PAUL \t\t\t\t||    Name: Habibur Rahaman\n");
    printf("  ID: 22102022\t\t\t\t\t||    Designation: Lecturer\n");
    printf("  Name: SAYANTI CHOUDHRY\t\t\t||    Department of CSE\n");
    printf("  ID: 22102023\t\t\t\t\t||    School of Science & Engineering (SSE)\n");
    printf("  Department Of Computer Science & Engineering\t||    Chittagong Independent University\n");
    //printf("\n\t\t\t\t   Now Its: %s",cdt());

  printf("\n\t\t\t\t     PRESS  [ENTER]  to Continue... ");

  if(getchar() == '\n')
  {
      int choice;
      char str[128], meaning[256];

        printf("\n\n\t\t\t\t! !   W E L C O M E  T O  D I C T I O N A R Y   ! !\t\t\t\t\t\n\n");
        printf("[1] INSERT\n");
        printf("[2] DELETE\n");
        printf("[3] SEARCH \n");
        printf("[4] DISPLAY WHOLE\n");
        printf("[0] EXIT\n");

    while(1)
    {
        printf("\t\t\t\t\t\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
                        case 1:
                                printf("Word to insert:");
                                fgets(str, 100, stdin);
                                printf("Meaning:");
                                fgets(meaning, 256, stdin);
                                insert(str, meaning);
                                break;
                        case 2:
                                printf("Enter the word to delete:");
                                fgets(str, 100, stdin);
                                deleteNode(str);
                                break;
                        case 3:
                                printf("Enter the search word:");
                                fgets(str, 100, stdin);
                                findElement(str);
                                break;
                        case 4:
                                inorderTraversal(root);
                                break;
                        case 0:
                                printf("\n\n===================================================== THANK YOU! ======================================================\n");
                                printf("================================================== EXIT SUCCESFULL! ==================================================\n");
                                exit(0);
                        default:
                                printf("\n!!!!! Wrong CHOICE !!!!!\n");
                                break;
                }
        }
    }
  }

