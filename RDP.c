#include "RDP.h"
#include <stdlib.h>
#include <stdio.h>

/*************************************************************
*These functions create subTrees with set amounts of children
*************************************************************/

 Tree newTree_zero(char x){
  Tree root;
  root = (Tree)malloc(sizeof(struct Node));
  root->label = x;
  root->LMC = NULL;
  root->RS = NULL;
  return root;
}

 Tree newTree_one(char x,Tree tree){
  Tree root;
  root = newTree_zero(x);
  root->LMC = tree;
  return root;
}

 Tree newTree_two(char x, Tree tree1, Tree tree2){
  Tree root;
  root = newTree_one(x, tree1);
  tree1->RS = tree2;
  return root;
}

 Tree newTree_three(char x, Tree tree1, Tree tree2, Tree tree3){
  Tree root;
  root = newTree_one(x,tree1);
  tree1->RS = tree2;
  tree2->RS = tree3;
  return root;
}


/************************************************************
*These are all the functions that return parsed subtrees
*(if they parse successfully)
*************************************************************
* Each method works by attempting a parse on each of its
* productions. If it fails a production, it tries the next etc.
************************************************************/

 Tree Digit(){
  switch(*look_ahead){
    case '0':
      look_ahead++;
      return newTree_one('D',newTree_zero('0'));
      break;
    case '1':
      look_ahead++;
      return newTree_one('D',newTree_zero('1'));
      break;
    case '2':
      look_ahead++;
      return newTree_one('D',newTree_zero('2'));
      break;
    case '3':
      look_ahead++;
      return newTree_one('D',newTree_zero('3'));
      break;
    case '4':
      look_ahead++;
      return newTree_one('D',newTree_zero('4'));
      break;
    case '5':
      look_ahead++;
      return newTree_one('D',newTree_zero('5'));
      break;
    case '6':
      look_ahead++;
      return newTree_one('D',newTree_zero('6'));
      break;
    case '7':
      look_ahead++;
      return newTree_one('D',newTree_zero('7'));
      break;
    case '8':
      look_ahead++;
      return newTree_one('D',newTree_zero('8'));
      break;
    case '9':
      look_ahead++;
      return newTree_one('D',newTree_zero('9'));
      break;
    default:
      printf("failed with %c\n",*look_ahead);
      return NULL;
  }
}

 Tree NumberC(){
  Tree num;
  if(
    *look_ahead == '\0' || *look_ahead == '*' || *look_ahead == '/' || *look_ahead == ')' ||
    *look_ahead == '+' || *look_ahead == '-' || *look_ahead == '('
  ){
    return newTree_one('C',newTree_zero('e'));
  } else {
    num = NumberN();
    if (num != NULL){//If not failed
      return newTree_one('C',num);
    } else {
      return NULL;
    }
  }
}

 Tree NumberN(){
  Tree d, num;
  d = Digit();
  if (d != NULL){
    num = NumberC();
    if(num != NULL){
      return newTree_two('N',d,num);
    } else {
      return NULL;
    }
  } else {
    return NULL;
  }
}

 Tree factor(){
  Tree exp, num;
  if(*look_ahead == '('){
    look_ahead++;
    exp = ExpressionE();
    if(exp != NULL && *look_ahead == ')'){
      look_ahead++;
      return newTree_three('F',newTree_zero('('),exp,newTree_zero(')'));
    } else {
      return NULL;
    }
  } else {
    num = NumberN();
    if (num == NULL){
      return NULL;
    } else {
      return newTree_one('F',num);
    }
  }
}

 Tree TermB(){
  Tree f, term;
  if(*look_ahead == '*'){
    look_ahead++;
    f = factor();
    if (f != NULL){
      term = TermB();
      if(TermB != NULL){
        return newTree_three('B',newTree_zero('*'),f,term);
      } else {
        return NULL;
      }
    } else {
      return NULL;
    }
  } else if (*look_ahead == '/'){//Production 2
    look_ahead++;
    f = factor();
    if(f != NULL){
      term = TermB();
      if(term != NULL){
        return newTree_three('B', newTree_zero('/'), f, term);
      } else {
        return NULL;
      }
    } else {
      return NULL;
    }
  } else {
    //last productions
    return newTree_one('B', newTree_zero('e'));
  }
}

 Tree TermT(){
  Tree f,term;

  f = factor();
  if (f != NULL){
    term = TermB();

    if(term != NULL){
      return newTree_two('T',f,term);
    } else {
      return NULL;
    }
  } else {
    return NULL;
  }
}

 Tree ExpressionA(){
    Tree term, expression;
    if(*look_ahead == '+') {
        look_ahead++;
        term = TermT();
        if(term != NULL) {
            expression = ExpressionA();
            if(expression != NULL) {
               return newTree_three('A', newTree_zero('+'), term, expression);
            } else {
                return NULL;
            }
        } else {
            return NULL;
        }
    } else if (*look_ahead == '-') {//Production Two
        look_ahead++;
        term = TermT();
        if(term != NULL) {
            expression = ExpressionA();
            if(expression != NULL) {
               return newTree_three('A', newTree_zero('-'), term, expression);
            } else {
                return NULL;
            }
        } else {
            return NULL;
        }
    } else {// Production Three
       return newTree_one('A', newTree_zero('e'));
    }
}

 Tree ExpressionE(){
    Tree term, expression;
    term = TermT();
    if (term != NULL) {
        expression = ExpressionA();
        if(expression != NULL) {
            return newTree_two('E', term, expression);
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

//*********************************************************

//Prints the tree horizontally in the console

 void Tree_print(Tree tree, int i, int currentSpacing) {
    if (tree == NULL && i == 1) {
    } else {
        printf("\n");
        for (int i = 0; i < currentSpacing; i++) {
            printf("  ");
        }
        printf("(%c", tree->label);
        if (tree->LMC != NULL) {
            Tree_print(tree->LMC, 0, currentSpacing+1);
        }
        if (tree->RS != NULL) {
            Tree_print(tree->RS, 0, currentSpacing);
        }
    }
}
