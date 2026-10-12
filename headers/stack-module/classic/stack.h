/* STACK.H: WHAT OTHER FILES MAY USE; THE DATA ITSELF STAYS HIDDEN IN STACK.C */
#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10 /* HOW MANY VALUES FIT */

void push(int value); /* PUT A VALUE ON TOP */
int pop(void);            /* TAKE THE TOP VALUE OFF */
int is_empty(void);       /* 1 IF THERE IS NOTHING TO POP */
int is_full(void);        /* 1 IF THERE IS NO ROOM TO PUSH */

#endif /* STACK_H */
