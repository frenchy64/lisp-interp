#include "minunit.h"
#include "dbg.h"
#include "core.h"
#include <unistd.h>

/**
 * Tests for subtraction.
 **/
char *check_eval() {
  Val* v;

  v = eval(read_string("null"));

  mu_assert(equiv(v, make_null()),
      "null should eval to null");

  // TODO add more eval tests here, can reuse `v`

  return (char*) NULL;
}

/**
 * Tests for addition.
 **/
char *check_read() {
  Expr* e;

  e = read_string("null");

  mu_assert(EXPR_VALUE == e->type,
      "null should read to null");
  mu_assert(equiv(e->p, make_null()),
      "null should read to null");

  // TODO add more read tests here, can reuse `e`

  return (char*) NULL;
}

/**
 * Tests for structural equivalence.
 **/
char *check_equiv() {
  mu_assert(equiv(make_null(), make_null()),
      "null should be equivalent to null");

  //TODO negative tests once we have more than
  //     just null values.
  return (char*) NULL;
}

/**
 * Main test suite.
 **/
char *all_tests() {
  mu_suite_start();

  mu_run_test(check_read);
  mu_run_test(check_eval);
  mu_run_test(check_equiv);

  return (char*)NULL;
}

/**
 * Runs the test suite.
 **/
RUN_TESTS(all_tests);
