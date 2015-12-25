/**
 * Lisp implementation.
 **/
#include "dbg.h"     // debugging library, defined in dbg.h
#include "util.h"    // utility library, defined in util.h
#include "core.h"    // REPL types
#include <stdio.h>   // standard libraries
#include <stdlib.h>
#include <unistd.h>

/**
 * Returns an instance of null.
 **/
Val* make_null() {
  Val* v = malloc(sizeof(Val_Null));

  return v;
}

/**
 * Tests if two values are structurally equivalent.
 *
 * @return 1 if values are equivalent, 0 if they are not.
 **/
int equiv(Val* v1, Val* v2) {
  if (VAL_NULL == v1->type &&
      VAL_NULL == v2->type) {
    return 1;
  }

  return 0;
}

/**
 * Print a value to stdout.
 *
 * @return 0 on success, -1 on failure.
 **/
int print_val(Val* v) {
  if (VAL_NULL == v->type) {
    printf("null");
    return 0;
  }

  check(0, "Don't know how to print this value: %i", v->type);

error:
  return -1;
}

/**
 * Read a form from the string str.
 *
 * @return A form on success, NULL on failure.
 **/
Expr* read_string(char* str) {
  //int start;
  int index;
  Expr* ret  = malloc(sizeof(Expr));     // return value

  check('\0' != str[0],
      "String to read_string terminated unexpectedly");
  
  if (is_alphanumeric(str[0])) {
    index = 0;
    //start = index;
    while (is_alphanumeric(str[index])) {
      index++;
    }

    if (0 == strncmp("null", str, 4)) {
      ret->type = EXPR_VALUE;
      ret->p    = make_null();
      return ret;
    }
  }

  check(NULL, "Failed to read form: %s", str);

error:
  return NULL;
}

/**
 * Evaluate an expression.
 *
 * @return A value on success, NULL on failure.
 **/
Val* eval(Expr* v) {
  Val* out = malloc(sizeof(Val));

  if (EXPR_VALUE == out->type) {
    // already contains the value, we can free the out value.
    free(out);
    return (Val*)v->p;
  }

  check(NULL, "Failed to evaluate form");

error:
  return NULL;
}


