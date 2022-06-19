#include "monty.h"

/**
 * moddy - mods the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void moddy(stack_t **stack, unsigned int line_number)
{
  int modd;

  if ((*stack) == NULL || (*stack)->next == NULL)
    {
      fprintf(stdout, "L%d: can't mod, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  if ((*stack)->n == 0)
    {
      fprintf(stdout, "L%d: division by zero\n", line_number);
      exit(EXIT_FAILURE);
    }

  modd = (*stack)->next->n % (*stack)->n;
  pop(stack, line_number);
  (*stack)->n = modd;
}

/**
 * pchar - prints the char at a the top
 * @stack: monty stack
 * @line_number: line number to grab
 */
void pchar(stack_t **stack, unsigned int line_number)
{
  if ((*stack) == NULL)
    {
      fprintf(stdout, "L%d: can't pchar, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  if (!isprint((*stack)->n))
    {
      fprintf(stdout, "L%d: can't pchar, value out of range\n", line_number);
      exit(EXIT_FAILURE);
    }
  fprintf(stdout, "%c\n", (*stack)->n);
}

#include "monty.h"

/**
 * is_int - checks if a string is valid for atoi
 * @str: the string
 *
 * Return: 1 for true, 0 for false
 */
int is_int(char *str)
{
  int i = 0;

  if (str == NULL)
    return (0);
  if (*str == '-')
    i++;
  for (; str[i]; i++)
    {
      if (!isdigit(str[i]))
	return (0);
    }
  return (1);
}
