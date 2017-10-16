#include <stdlib.h>
#include <stdio.h>
#include "Stack.c"
#include "TableParser.h"


#define ENDM $

int Table_run(char* input){
  char* productions[12]; //define our language of productions
  productions[0] = NULL;//burn first index
  productions[1] = "$E"; //symbols are written in backward to facillitate later process
  productions[2] = "AT";
  productions[3] = "AT+";
  productions[4] = "AT-";
  productions[5] = "";
  productions[6] = "BF";
  productions[7] = "BF*";
  productions[8] = "BF/";
  productions[9] = "";
  productions[10] = ")E(";
  productions[11] = "N";


  //char* lookahead;
  int table[6][8];
  table[0][0] = 1;
  table[1][0] = 2;
  table[3][0] = 6;
  table[5][0] = 10;
  table[2][1] = 5;
  table[4][1] = 9;
  table[2][2] = 3;
  table[4][2] = 9;
  table[2][3] = 4;
  table[4][3] = 9;
  table[4][4] = 7;
  table[4][5] = 8;
  table[0][6] = 1;
  table[1][6] = 2;
  table[5][6] = 11;
  table[3][6] = 6;
  table[2][7] = 5;
  table[4][7] = 9;
  Stack* stack = Stack_new();

Stack_push(stack,'S');
int action;
//printf("%s\n", "start ----------");
int iter=1;
while (!Stack_is_empty(stack)) {
//printf("loop number: %d\n\n", iter);
iter++;
//printf("current input %c\n", input[0]);
  //for(int p=0;p<10000;p++)
    //for(int j=0;j<10000;j++){}//slow me down boi

  char top = stack->first->data;
  //printf("enter the if block %d\n", !is_terminal(top));
  if (!(is_terminal(top) || top == 'N')) {//boolean non-terminal or n
    //printf("top of stack %c\n", stack->first->data);
    //printf("map prod %d\n", map_production(top));
    //printf("map char %d\n",map_char(input[0]) );
    action = table[map_production(top)][map_char(input[0])];
    //input++;
    //printf("action %d\n", action);
    if(action > 0){//TODO double check logic
      //printf("%s\n", "entered 2nd");
      Stack_pop(stack);
      for(int i=0;productions[action][i] != '\0';i++){
        //printf("pushing this to stack: %c\n", productions[action][i]);
        Stack_push(stack,productions[action][i]);
      }
      //printf("%c\n",stack->first->data );
      }
      else{
        if (top == '$' && input[0] == '$') {//success
          return 1;
        }
        //printf("%s\n","failure - action is less than 0");
        return 0;
      }

    }
    else if (is_operator_terminal(input[0]) ||(is_terminal(input[0]) && top == 'N')){
      //printf("%s\n", "before stack pop");
      Stack_pop(stack);
      //printf("%s\n", "before input++");
      input++;
      //printf("%s\n", input);
      ////printf("stack top: %c\n",stack->first->data);
      //printf("stack is empty? %d\n",Stack_is_empty(stack) );
    }
    else{
      //printf("%s\n", "syntax error");
      return 0;
    }

  }
  return 1;
}

int is_terminal(char c){
  switch (c) {
    case  '0': return 1;
    case  '1': return 1;
    case  '2': return 1;
    case  '3': return 1;
    case  '4': return 1;
    case  '5': return 1;
    case  '6': return 1;
    case  '7': return 1;
    case  '8': return 1;
    case  '9': return 1;
    case  '+': return 1;
    case  '-': return 1;
    case  '*': return 1;
    case  '/': return 1;
    case ')': return 1;
    case '(': return 1;

    default: return 0;
  }
}

int is_operator_terminal(char c){
  switch (c) {
    case  '+': return 1;
    case  '-': return 1;
    case  '*': return 1;
    case  '/': return 1;
    case ')': return 1;
    case '(': return 1;
    default: return 0;
  }
}

int map_production(char c){
  switch(c){
    case 'S': return 0;
    case 'E': return 1;
    case 'A': return 2;
    case 'T': return 3;
    case 'B': return 4;
    case 'F': return 5;
    default: //printf("error");
    return 1;
  }
}

int map_char(char c){
  switch(c){
    case '(': return 0;
    break;
    case ')': return 1;
    break;
    case '+': return 2;
    break;
    case '-': return 3;
    break;
    case '*': return 4;
    break;
    case '/': return 5;
    break;
    case '$': return 7;
    break;
    default: return 6;

  }
}
