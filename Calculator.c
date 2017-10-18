#include "Calculator.h"
//#include "RDP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(Tree toCalc)
{
  return E_Handler(toCalc);
}

int concatenate_two(int one,int two)
{
  char str1[100];
  char str2[100];
  printf(str1,"%d",one);
  printf(str2,"%d",two);
  strcat(str1,str2);
  return atoi(str1);
}

/*
* Production Handlers - returns a value for each production
*/

int E_Handler(Tree toCalc)
{
  if(A_Handler(toCalc->LMC->RS) == -1){ // If A is epsilon
  return T_Handler(toCalc->LMC);//Return calc of <T>

} else if (toCalc->LMC->RS->LMC->label == '+'){//If the sub-A first terminal is a +
  return (T_Handler(toCalc->LMC)+A_Handler(toCalc->LMC->RS));//Return T + A

} else { //If sub-A first termina is a -
  return (T_Handler(toCalc->LMC)-A_Handler(toCalc->LMC->RS));
  }
}

int A_Handler(Tree toCalc)
{
  switch(toCalc->LMC->label)
  {
    case 'e':
      return -1;
      break;
    case '+':
      if (A_Handler(toCalc->LMC->RS->RS) != -1)//If the sub A is not epsilon
        return (concatenate_two(T_Handler(toCalc->LMC->RS),A_Handler(toCalc->LMC->RS->RS)));//Return T concatenated with A
      else return (T_Handler(toCalc->LMC->RS));//if A is epsilon, return just T
      break;
    case '-':
      if (A_Handler(toCalc->LMC->RS->RS) != -1)//If the sub A is not epsilon
        return (concatenate_two(T_Handler(toCalc->LMC->RS),A_Handler(toCalc->LMC->RS->RS)));//Return T concatenated with A
      else return (T_Handler(toCalc->LMC->RS));//if A is epsilon, return just T
      break;
  }
  return -1;
}

int T_Handler(Tree toCalc)
{
    if(B_Handler(toCalc->LMC->RS) == -1){ // If A is epsilon
    return F_Handler(toCalc->LMC);//Return calc of <F>

  } else if (toCalc->LMC->RS->LMC->label == '*'){//If the sub-B first terminal is a *
    return (F_Handler(toCalc->LMC)*B_Handler(toCalc->LMC->RS));//Return T + A

  } else { //If sub-B first termina is a /
    return (F_Handler(toCalc->LMC)/B_Handler(toCalc->LMC->RS));
  }
}

int B_Handler(Tree toCalc)
{
  switch(toCalc->LMC->label)
  {
    case 'e'://If epsilon, return (int)NULL
      return -1;
      break;
    case '*':
      if (B_Handler(toCalc->LMC->RS->RS) != -1)//If the sub B is not epsilon
        return (concatenate_two(F_Handler(toCalc->LMC->RS),B_Handler(toCalc->LMC->RS->RS)));//Return F concatenated with B
      else return (F_Handler(toCalc->LMC->RS));//if B is epsilon, return just F
      break;
    case '/':
      if (B_Handler(toCalc->LMC->RS->RS) != -1)//If the sub A is not epsilon
        return (concatenate_two(F_Handler(toCalc->LMC->RS),B_Handler(toCalc->LMC->RS->RS)));//Return F concatenated with B
      else return (F_Handler(toCalc->LMC->RS));//if B is epsilon, return just F
      break;
  }
  return -1;
}

int F_Handler(Tree toCalc)
{
  if(toCalc->LMC->label == 'E')//If it's E
  {
    return E_Handler(toCalc->LMC);//Eval E
  } else {//Must my N
    return N_Handler(toCalc->LMC);
  }
}

int N_Handler(Tree toCalc)
{
  if (C_Handler(toCalc->LMC->RS) != -1)//If the C isn't epsilon
    return concatenate_two(D_Handler(toCalc->LMC),C_Handler(toCalc->LMC->RS));//Concatenate
  else return D_Handler(toCalc->LMC);
}

int C_Handler(Tree toCalc)
{
  if (toCalc->LMC->label == 'e'){
    return -1;
  } else { //Must be <N>
    return N_Handler(toCalc->LMC);
  }
}

int D_Handler(Tree toCalc)
{
  switch (toCalc->LMC->label)
  {
    case '0':
      return 0;
      break;
    case '1':
      return 1;
      break;
    case '2':
      return 2;
      break;
    case '3':
      return 3;
      break;
    case '4':
      return 4;
      break;
    case '5':
      return 5;
      break;
    case '6':
      return 6;
      break;
    case '7':
      return 7;
      break;
    case '8':
      return 8;
      break;
    case '9':
      return 9;
      break;
  }
  return -1;
}
