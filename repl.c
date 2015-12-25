/**
 * Main REPL entry point.
 **/
#include "dbg.h"     // debugging library
#include "core.h"    // REPL types
#include <stdio.h>   // standard libraries
#include <stdlib.h>
#include <unistd.h>

/**
 * Main entry point.
 *
 * @return 0 on success, 1 on failure
 **/
int main(int argc, char *argv[]) {
  char buf[BUFLENGTH]; // buffer to hold current REPL input
  Expr* form; // the result of 'read'
  Val*  val;  // the result of 'eval'

  printf("Welcome to the REPL!\n");
  while(1) {
    printf("=> ");

    // Get a line from the user
    check(gets(buf), "End of file, exiting REPL");

    // Read string into a expression.
    form = read_string(buf);
    if(!form) {
      printf("Error detected in read\n");
      continue; // skip back to the beginning of the loop
    }

    // Evaluate the expression to a value.
    val = eval(form);
    if(!val) {
      printf("Error detected eval\n");
      continue; // skip back to the beginning of the loop
    }

    // Print the value to the REPL.
    if(-1 == print_val(val)) {
      printf("Error detected while printing value\n");
      continue; // skip back to the beginning of the loop
    }

    printf("\n");
  }

  return 0;

error:
  return 1;
}
