
/*
 * Expression.c
 * Implementation of functions used to build the syntax tree.
 */

#include "Expression.h"

#include <stdlib.h>

/**
 * @brief Allocates space for expression
 * @return The expression or NULL if not enough memory
 */
static SExpression *allocateExpression()
{
    SExpression *b = (SExpression *)malloc(sizeof *b);

    if (b == NULL)
        return NULL;

    b->type = eVALUE;
    b->value = 0.0;

    b->left = NULL;
    b->right = NULL;

    return b;
}

SExpression *createNumber(int value)
{
    SExpression *b = allocateExpression();

    if (b == NULL)
        return NULL;

    b->type = eVALUE;
    b->value = value;

    return b;
}
/*
SExpression *createNumber(char* value)
{
  SExpression *b = allocateExpression();
  b->type = eVALUE;  
  if (value == "pi"){
     b->value = 3.14159;
     return b;
  }
  if (value == "e"){
     b->value = 2.717;
     return b;
  }
  return NULL;
}
*/
SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right)
{
    SExpression *b = allocateExpression();

    if (b == NULL)
        return NULL;

    b->type = type;
    b->left = left;
    b->right = right;

    return b;
}

void deleteExpression(SExpression *b)
{
    if (b == NULL)
        return;

    deleteExpression(b->left);
    deleteExpression(b->right);

    free(b);
}
