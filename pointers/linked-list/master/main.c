/* LINKED LIST: EACH NODE HOLDS A VALUE AND THE ADDRESS OF THE NEXT NODE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

struct node
{
	int value;
	struct node *next; /* POINTER TO A NODE OF THE SAME TYPE (NULL = THE END) */
};

int main(void)
{
	struct node *head = NULL; /* THE LIST STARTS EMPTY */
	struct node *tail = NULL; /* LAST NODE, TO ADD AT THE END QUICKLY */
	struct node *p, *next;
	int x = 0;
	int count = 0;

	printf("Enter numbers (0 to stop): ");
	while (scanf("%d", &x) == 1 && x != 0)
	{
		p = malloc(sizeof(struct node)); /* A NEW NODE FOR EVERY NUMBER */
		if (p == NULL)
		{
			printf("Not enough memory\n");
			break;
		}
		p->value = x;
		p->next = NULL;

		if (head == NULL)
		{
			head = p; /* THE FIRST NODE */
		}
		else
		{
			tail->next = p; /* LINK IT AFTER THE LAST ONE */
		}
		tail = p;
		count++;
	}

	printf("The list has %d nodes:", count);
	for (p = head; p != NULL; p = p->next) /* FOLLOW THE LINKS */
	{
		printf(" %d", p->value);
	}
	printf("\n");

	p = head; /* GIVE BACK THE MEMORY, NODE BY NODE */
	while (p != NULL)
	{
		next = p->next; /* REMEMBER THE NEXT ONE BEFORE THIS ONE IS FREED */
		free(p);
		p = next;
	}

	return 0;
}
