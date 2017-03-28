# basic_tree_ops
Baisc tree operations for excercise

Operations supported are:
1. Insertion of elements into BST(Binary Search Tree)
2. inorder traversal of the BST
3. maximum element in the BST
4. minimum element in the BST
5. height of the BST
6. deleting the element from the BST and re-ordering the BST


Deletion: nodes to be keept in mind for deletion
cur: current node being deleted 
parent: parent of the current node being deleted
suc: successor of the node being deleted. this guy inherts the left sub-tree of 
cur(node being deleted)
q: this is the sub-tree of the cur(node being deleted), this we need 
attach to the parent

Case1: for deleting an element from the BST with
       1. no left sub-tree of the node being deleted
       2. no right sub-tree of the node being deleted
      
       if (cur->llink == NULL) {
           q = cur->rlink;
       } else if (cur->rlink == NULL) {
           q = cur->llink;
       }
            

Case2: deleting node having both left and right subtree 


step1:
------
find successor node, which will be the leftmost node of the 
cur->rlink(i.e leftmost node of the right subtree of the current node being 
deleted)


step2:
------
attach the left subtree of the cur to successor found in step1
    suc->llink = cur->llink 

step3: 
------
    now q which points to right subtree, attach it to parent of cur(current node 
being deleted)
if the parent is NULL, then free cur(complete the deletion) and return q as the root
if the cur was on left subtree of parent, attach q to left of parent 
if the cur was on right subtree of parent ,attach q to right of parent

as now we have taken care of both left and right subtree of cur and stiched to 
parent node of cur, free the cur node to complete the deletion
now we have taken care of the left subtree, and attach the right subtree to the 
parent and delete the node


