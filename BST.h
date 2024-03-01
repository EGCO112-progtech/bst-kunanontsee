// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

//void insertNode( BST *b, int value);

void insertNode_R(TreeNodePtr * t,int value)
{
  if(*t==NULL)
  {
      *t = malloc(sizeof(struct TreeNode));
	   if(t)
      {
		   (*t)->leftPtr=NULL;
		   (*t)->rightPtr=NULL;
		   (*t)->data=value;
      }
  }
  else
  {
     if((*t)->data>=value) //left
     {
      return insertNode_R(&(*t)->leftPtr, value);
     }
        
     else //right
     {
      return insertNode_R(&(*t)->rightPtr, value);
     }
      
   }
}


void insertNode( BST *b, int value )
{
	 TreeNodePtr t = b->root,newnode;
	 int inserted=0;
	newnode =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(newnode)
   {
		newnode->leftPtr=NULL;
		newnode->rightPtr=NULL;
		newnode->data=value;
		/*First Node*/
		if(!b->root) b->root=newnode;
		else 
      {
         while(!inserted)
         {
            if(t->data >=value)
            {
               if(!t->leftPtr)
               {
                  t->leftPtr = newnode;
                  inserted = 1;
               }
               else
               {
                  t = t->leftPtr;
               }
               
            /* move/insert to the left*/
            }
            else
            {
               if(!t->rightPtr)
               {
                  t->rightPtr = newnode;
                  inserted = 1;
               }
               else
               {
                  t = t->rightPtr;
               }
            }
            /* move insert to the right*/
         }
	   }
   }
   b->size++;//end while		
}//end else;
  
  //end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL)
   {
      printf("%3d",treePtr->data) ;

      preOrder(treePtr->leftPtr);

      preOrder(treePtr->rightPtr);
   }
}

void postOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL)
   {
      postOrder(treePtr->leftPtr);

      postOrder(treePtr->rightPtr);

      printf("%3d",treePtr->data) ;
   }
}


void PaintTree(TreeNodePtr treePtr, int l)
{
   if(treePtr)
   {
      l++;
      PaintTree(treePtr->rightPtr, l);

      for(int i=0; i<l; i++)
      {
         printf("   ");
      }

      printf("%d\n", treePtr->data);
      
      PaintTree(treePtr->leftPtr, l);
   }

   
}