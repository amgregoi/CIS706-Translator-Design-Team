#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct STree Tree;
typedef struct STreeNode TreeNode;
Tree* btNewTree();
TreeNode* btNewNode(int value, TreeNode* left, TreeNode* right);
void* btAddNode(Tree* tree, int value);
void* btAddTreeNode(Tree* tree, TreeNode* newNode);
int btCheckSum(TreeNode* treeNode, int multiplier);

NEW_STRUCT (STree, TreeNode* root ;
);

NEW_CONST(Tree, 1, ptr, &(ptr->root));

NEW_STRUCT (STreeNode, int value;TreeNode* leftChild ;
TreeNode* rightChild ;
);

NEW_CONST(TreeNode, 2, ptr, &(ptr->leftChild), &(ptr->rightChild));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Tree* testTree = New_Tree();var_push(&testTree);

   testTree=btNewTree();
   btAddNode(testTree, 5);
   btAddNode(testTree, 3);
   btAddNode(testTree, 7);
   btAddNode(testTree, 10);
   btAddNode(testTree, 2);
   btAddNode(testTree, 4);
   btAddNode(testTree, 6);
   assert((btCheckSum(testTree->root, 1) == 91));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

Tree* btNewTree(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return New_Tree();
}

TreeNode* btNewNode(int value, TreeNode* left, TreeNode* right){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   TreeNode* newNode = New_TreeNode();var_push(&newNode);

   newNode=New_TreeNode();

   newNode->value=value;

   newNode->leftChild=left;

   newNode->rightChild=right;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return newNode;
}

void* btAddNode(Tree* tree, int value){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   bool addedValue;TreeNode* currentNode = New_TreeNode();var_push(&currentNode);
   TreeNode* nodeToAdd = New_TreeNode();var_push(&nodeToAdd);

   addedValue=false;

   currentNode=tree->root;

   nodeToAdd=btNewNode(value, NULL, NULL);

   if((currentNode == NULL)){

      tree->root=nodeToAdd;
      return ;


   }while(!(addedValue)){

      if((currentNode->value < value)){

         if((currentNode->rightChild == NULL)){

            currentNode->rightChild=nodeToAdd;

            addedValue=true;
            return ;


         }else{

            currentNode=currentNode->rightChild;



         }


      }else{

         if((currentNode->value >= value)){

            if((currentNode->leftChild == NULL)){

               currentNode->leftChild=nodeToAdd;

               addedValue=true;
               return ;


            }else{

               currentNode=currentNode->leftChild;



            }


         }


      }


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* btAddTreeNode(Tree* tree, TreeNode* newNode){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   TreeNode* currentNode = New_TreeNode();var_push(&currentNode);

   if((tree->root == NULL)){

      tree->root=newNode;
      return ;


   }
   currentNode=tree->root;
   while((currentNode != NULL)){

      if((currentNode->value >= newNode->value)){

         if((currentNode->rightChild == NULL)){

            currentNode->rightChild=newNode;
            return ;


         }else{

            currentNode=currentNode->rightChild;



         }


      }else{

         if((currentNode->value < newNode->value)){

            if((currentNode->leftChild == NULL)){

               currentNode->leftChild=newNode;
               return ;


            }else{

               currentNode=currentNode->leftChild;



            }


         }


      }


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

int btCheckSum(TreeNode* treeNode, int multiplier){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int returnValue;int leftValue;int rightValue;
   if((treeNode == NULL)){
      return 0;


   }
   returnValue=(multiplier * treeNode->value);
   multiplier++;

   leftValue=btCheckSum(treeNode->leftChild, multiplier);

   rightValue=btCheckSum(treeNode->rightChild, multiplier);
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ((returnValue + leftValue) + rightValue);
}
