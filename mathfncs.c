#include "monty.h"

/**
 * pall - prints all values on the stack, starting from the top of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp;

  UNUSED(line_number);

  tmp = *stack;
  while (tmp != NULL)
    {
      printf("%d\n", tmp->n);
      tmp = tmp->next;
    }
}

/**
 * push - pushes an element to the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
  stack_t *new, *tmp;
  char *push_arg = strtok(NULL, "\n \t");
  int pVal;
  /*if push, tests if the push_arg was valid or not */
  if (!is_int(push_arg))
    {
      fprintf(stdout, "L%u: usage: push integer\n", line_number);
      exit(EXIT_FAILURE);
    }


  pVal = atoi(push_arg);
  new = malloc(sizeof(stack_t));
  if (new == NULL)
    {
      fprintf(stdout, "Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }
  new->n = pVal;
  new->prev = NULL;
  new->next = NULL;
  /** checks if stack is empty **/
  if ((*stack) == NULL)
    *stack = new;
  else if (SQ)
    {
      /** puts new node on top if not empty **/
      (*stack)->prev = new;
      new->next = *stack;
      *stack = new;
    }
  else
    {
      /**puts new node on the bottom **/
      tmp = *stack;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      new->prev = tmp;
    }

}

/**
 * add - adds the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
  int summ;

  if ((*stack) == NULL || (*stack)->next == NULL)
    {
      fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  summ = (*stack)->next->n + (*stack)->n;
  pop(stack, line_number);
  (*stack)->n = summ;
}

/**
 * pop - removes the top element of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp;

  if ((*stack) == NULL)
    {
      fprintf(stdout, "L%d: can't pop an empty stack\n", line_number);
      exit(EXIT_FAILURE);
    }

  tmp = *stack;
  *stack = (*stack)->next;
  free(tmp);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
  if (*stack == NULL)
    {
      fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  printf("%d\n", (*stack)->n);
}

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
