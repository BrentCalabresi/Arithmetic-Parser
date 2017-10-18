#ifndef _RDPH_
#define _RDPH_

typedef struct Node* Tree;

struct Node{
  char label;
  Tree LMC, RS;
};

//Global variables:
  char *look_ahead;
  //Final Parse Tree
  Tree parseTree;

/**********************************************************
*These are all the functions that return parsed subtrees
*(if they parse successfully)
***********************************************************/

 Tree ExpressionE();

 Tree ExpressionA();

 Tree TermT();

 Tree TermB();

 Tree NumberN();

 Tree NumberC();

 Tree Factor();

 Tree Digit();

/*************************************************************
*These functions create subTrees with set amounts of children
*************************************************************/
 Tree newTree_zero(char x);

 Tree newTree_one(char x,Tree tree);

 Tree newTree_two(char x,Tree tree1, Tree tree2);

 Tree newTree_three(char x, Tree tree1, Tree tree2, Tree tree3);

//*********************************************************

//Prints the tree horizontally in the console
 void Tree_print(Tree treeToPrint, int start, int numIndented);//int start is a boolean val of if on the root node
#endif
