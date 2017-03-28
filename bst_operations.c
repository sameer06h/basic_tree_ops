#include "tree_api.h"


int main(void) 
{

    int op, item;
    NODE temp = NULL;
    // we shall perform 
    // 1. BST creation
    // 2. BST traversal
    // 3. searching an element in BST
    
    while(1) {
        printf("Please Enter the Opration you want to perform\n");
        printf("1. BST Creation/Insertion     press:1\n");
        printf("2. BST Traversal              press:2\n");
        printf("3. BST Search for an element  press:3\n");
        printf("4. BST height                 press:4\n");
        printf("5. Max Element in  BST        press:5\n");
        printf("6. Min Element in  BST        press:6\n");
        printf("7. Del Element frm BST        press:7\n");
        printf("EXIT                          press:100\n");

        scanf("%d", &op);

        switch(op)  {
            case 1: // Here we enter to insert/Create BST
                printf("Please enter the element to be inserted into BST\n");
                scanf("%d", &item);
                root = insert_into_BST(item, root);
                break;

            case 2: // we use inorder traveral for displaying the elements of a tree
                root = inorder_traversal(root);
                break;
            case 3: 
                printf("Please enter the element you want to search\n");
                scanf("%d", &item);
                temp = search_in_BST(item, root);
                if(temp != NULL) {
                    printf("Hmmmm... Hurry!!! element is found!!\n");
                } else {
                    printf("Ooopsss element is not found, would you like to add it??\n");
                }
                break;
           case 4:
                printf("Your BST has height of %d level\n", height_of_BST(root));
                break;
           case 5:
                temp = max_in_BST(root);
                if(temp != NULL) {
                    printf("Max Element in BST is %d\n", temp->info);
                } else {
                    printf("No Elements in BST, wud u like to add?\n");
                }
                break;
           case 6:
                temp = min_in_BST(root);
                if(temp != NULL) {
                    printf("Min Element in BST is %d\n", temp->info);
                } else {
                    printf("No Elements in BST, wud u like to add?\n");
                }
                break;
           case 7:
                printf("Please enter the element you want to del\n");
                scanf("%d", &item);
                root = delete_frm_BST(item, root); 
                break;
           case 100:
                exit(0);
        }
    }
}
