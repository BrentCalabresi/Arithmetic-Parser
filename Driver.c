#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Calculator.c"
#include "TableParser.c"
#include "RDP.c"

int main(){

  //Expression Storage
	char expression[100];
  //Menu Readout
	printf("Recursive Decent Parser for Arithmetic Expressions\n");
  printf("--------------------------------------------------\n");
  printf("Enter an Arithmetic Expression with no spaces: \n\n");
	scanf("%s", expression);
	printf("Parsing on: %s \n", expression);
  printf("--------------------------------------------------\n");
  printf("----------------------|Tree|----------------------\n");
  printf("--------------------------------------------------\n");

	look_ahead = expression;
	parseTree = ExpressionE();
  Tree_print(parseTree,1,0);
	printf("\n");

	printf("Parsed by table: %d\n\n",Table_run(strcat(expression,"$")));
	printf("----------------------Answer----------------------\n");
	//printf("%d\n",calculate(parseTree));
}
