#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "memory.h"

typedef enum OPERATION {
  opMUL,
  opDIV,
  opADD,
  opSUB,
  opNEGNUM, // negative number
  opGRTH,
  opLSTH,
  opGREQ,
  opLSEQ,
  opNEQ,
  opEQ
} Operation;

typedef struct expression_node {
  struct EXPRESSION *value;
  struct expression_node *next;
} expression_node_t;

typedef struct EXPRESSION {
  void *expression;
  void* (*get)(struct EXPRESSION*);
} Expression;
// expressions
typedef struct EXPRESSION_VARIABLE {
  char *name;
} ExpressionVariable;
typedef struct EXPRESSION_INTEGER {
  int number;
} ExpressionInteger;
typedef struct EXPRESSION_NUMBER {
  double number;
} ExpressionNumber;
typedef struct EXPRESSION_STRING {
  char *string;
} ExpressionString;
typedef struct EXPRESSION_BOOLEAN {
  bool boolean;
} ExpressionBoolean;
typedef struct EXPRESSION_NIL {

} ExpressionNil;
typedef struct EXPRESSION_UNARY {
  Operation operation;
  Expression *expr;
} ExpressionUnary;
typedef struct EXPRESSION_BINARY {
  Operation operation;
  Expression *expr1;
  Expression *expr2;
} ExpressionBinary;
typedef struct EXPRESSION_CONDITIONAL {
  Operation operation;
  Expression *expr1;
  Expression *expr2;
} ExpressionConditional;
typedef struct EXPRESSION_FUNCTION {
  char *name;
  expression_node_t *args;
} ExpressionFunction;
typedef struct EXPRESSION_LIST {
  expression_node_t *elements;
} ExpressionList;
typedef struct EXPRESSION_ELEMENT {
  char *name;
  expression_node_t *indices;
} ExpressionElement;

memory_node_t *expression_memory_node;

Expression* variableExpression(char*);
Expression* integerExpression(int);
Expression* floatExpression(double);
Expression* stringExpression(char*);
Expression* boolExpression(bool);
Expression* nilExpression();
Expression* unaryExpression(Operation, Expression*);
Expression* binaryExpression(Operation, Expression*, Expression*);
Expression* conditionalExpression(Operation, Expression*, Expression*);
Expression* functionExpression(char*, expression_node_t*);
Expression* listExpression(expression_node_t*);
Expression* elementExpression(char*, expression_node_t*);

expression_value_t *valueInteger(int);
expression_value_t *valueFloat(float);
expression_value_t *valueBoolean(bool);
expression_value_t *valueString(char*);
expression_value_t *valueNil();
expression_value_t *valueTable(memory_node_t*);
expression_value_t *valueList(list_node_t*);
expression_value_t *valueFunction(struct FUNCTION*);
expression_value_t *getValueExpression(Expression*);
// list
void expression_push(expression_node_t**, Expression*);
int expression_length(expression_node_t*);

#endif EXPRESSION_H
