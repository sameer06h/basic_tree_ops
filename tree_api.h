#include "def.h"
#include <stdio.h>
#include <stdlib.h>
#include "common_utils.h"

NODE root = NULL;

NODE insert_into_BST(int element, NODE root) 
{
    NODE prev = NULL;
    NODE  cur = NULL;
    NODE temp = (NODE) malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory allocation for the node FAILED exiting\n");
        return root;
    }
    //leaf node it is, keep the child links NULL
    temp->llink = temp->rlink = NULL;
    temp->info = element;

    // if there is no BST, return this node as root
    if(root == NULL) return temp;
    
    cur = root;
    while(cur != NULL) {
        prev = cur;
        
        if(element == cur->info) {
            // duplicate element ignore and return success
            return root;
        }

        if( element < cur->info){
            cur = cur->llink;
        } else {
            cur = cur->rlink;
        }
    }

    if(element < prev->info) {
        prev->llink = temp;
    }else{ 
        prev->rlink = temp;
    }

    return root;
}


// Given an element, Search the element in the 
// BST and return the node if found and NULL otherwise

NODE search_in_BST(int element, NODE root)
{
    NODE cur = NULL;
    // BST doesnt exist, no point in searching return
    if(root == NULL) return root;

    cur = root;

    while(cur != NULL) {
        
        if(element == cur->info) {
            return cur;
        }

        if(element < cur->info) {
            cur = cur->llink;
        } else {
            cur = cur->rlink;
        }
    }


    // if we reach here, element was not found return NULL
    return NULL;

}

// traverse the BST in inorder:
// i.e node, then node left subtree then node right subtree
NODE inorder_traversal(NODE root) 
{
    if(root == NULL) return NULL;

    printf("%d\n", root->info);
    inorder_traversal(root->llink);
    inorder_traversal(root->rlink);

    return root;
}


int height_of_BST(NODE root)
{
    // if root is NULL tree doesnt exist return -1
    // if the actual levels are 4, root level is considered level 0
    // so the height should be returned as 3 and not 4 so when root is NULL 
    // return -1
    if(root == NULL) return -1;

    return 1 + max(height_of_BST(root->llink), height_of_BST(root->rlink));

}
    

NODE max_in_BST(NODE root) 
{
    NODE cur = NULL;

    if(root == NULL) return root;

     cur = root;
     while(cur->rlink != NULL) {
          cur = cur->rlink;
     }

     return cur;
}

NODE min_in_BST(NODE root) 
{
    NODE cur = NULL;

    if(root == NULL) return root;

     cur = root;
     while(cur->llink != NULL) {
          cur = cur->llink;
     }

     return cur;
}


NODE successor(NODE temp) {

    temp = temp->rlink;

    while(temp->llink != NULL) {
        temp = temp->llink;
    }

    return temp;
}

// Delete an element from BST and re-order the BST
// CASE1: no left subtree and no right sub-tree
// CASE2: no right subtree of the node to be deleted
//             or
//        no left subtree of the node to be deleted 
// CASE3: deleting the node with left subtree and right subtree
//
// house-keeping poninters
// 1. parent: pointer to the parent of the node to be deleted
// 2. cur: the currect node to be deleted
// 3. suc: find the successor to inherit the left subtree of the curent node to 
// be deleted
// 4. q: the right node of the cur, which should finally be attached to cur`s 
// parent node 

NODE delete_frm_BST(int element, NODE root) 
{
   NODE parent = NULL, cur = NULL, q = NULL, suc = NULL;

   if(root == NULL) {
       printf("The BST is empty no elements to delete, would you like to add??\n");
       return NULL;
   }


   cur = root;
   while(cur != NULL) {

       // parent of the current node to be deleted

       if(element == cur->info) {
           printf("Element found to be deleted\n");
           break;
       }
       parent = cur;


       if(element < cur->info) {
           cur = cur->llink;
       } else {
           cur = cur->rlink;
       }
   }

   if(cur == NULL) {
       printf(" Element not in BST to be deleted, would like to add ??\n");
       return root;
   }


   //CASE1
   if(cur->llink == NULL) {
       q = cur->rlink;
   }else if(cur->rlink == NULL) {
       q = cur->llink;
   } else {

       //CASE2

       // find successor node of cur 
       suc = successor(cur);
       // suc will inherit the left subtree of current node
       suc->llink = cur->llink;
       q = cur->rlink;
   }

   free(cur);
   // parent is NULL return, q as the new root
   if(parent == NULL) return q;

   if(cur == parent->llink) {
       parent->llink = q;
   } else {
       parent->rlink = q;
   }

   return root;
}
