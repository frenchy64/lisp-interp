#define BUFLENGTH 64

#define VAL_NULL  0
#define VAL_CONS  1
#define VAL_INT   2
#define VAL_CLOS  3

/**
 * A value is a tagged value with a pointer
 * to the actual data.
 *
 * It is either a:
 *  - null (VAL_NULL)
 *  - cons (VAL_CONS)
 *  - integer (VAL_INT)
 *  - closure (VAL_CLOS)
 **/
typedef struct Val {
  int type;
  void* p;
} Val;

/**
 * The empty list.
 **/
typedef struct Val_Null { } Val_Null;

/**
 * A cons cell has a car and a cdr.
 **/
typedef struct Val_Cons {
  Val* car;
  Val* cdr;
} Val_Cons;

/**
 * A integer value.
 **/
typedef struct Val_Int {
  int v;
} Val_Int;

/**
 * A closure with a known arity and code for a function.
 **/
typedef struct Val_Clos {
  int arity;
  void* f;
} Val_Clos;

#define EXPR_VALUE  0
#define EXPR_INVOKE 1
#define EXPR_LAMBDA 2

/**
 * An expression is a tagged value with a pointer
 * to the actual expression.
 *
 * An expression is one of:
 *  - a value (EXPR_VALUE)
 *  - a function invocation (EXPR_INVOKE)
 *  - a function (EXPR_LAMBDA)
 **/
typedef struct Expr {
  int type;
  void* p;
} Expr;

/**
 * Functions provided by repl.c
 **/
Val* make_null();
int equiv(Val* v1, Val* v2);
int print_val(Val* v);
Expr* read_string(char* str);
Val* eval(Expr* v);
