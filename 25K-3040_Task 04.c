#include<stdio.h>

void push(int stack[], int *top, int maxSize)
{
	int element;
	printf("Enter the Element to Insert: ");
	scanf("%d", &element);
	if(*top < maxSize)
	{
		stack[*top] = element;
		(*top)++;
		printf("Element %d Inserted Successfully!\n\n", element);
	}
	else
	{
		printf("Stack Overflow!\n\n");
	}
}

void pop(int stack[], int *top)
{
	if(*top != 0)
	{
		(*top)--;
		printf("Element %d Removed Successfully!\n\n", stack[*top]);
	}
	else
	{
		printf("Stack Underflow!\n\n");
	}
}

void peek(int stack[], int *top)
{
	if(*top == 0)
	{
		printf("Stack is Empty!\n\n");
	}
	else
	{
		printf("The Top Element is %d!\n\n", stack[*top - 1]);
	}
}

void display(int stack[], int *top)
{
	int i;
	if(*top == 0)
	{
		printf("Stack is Empty!\n\n");
	}
	else
	{
		printf("All Elements in Stack:\n");
		for(i=*top-1; i>=0; i--)
		{
			printf("Element %d = %d\n", i+1, stack[i]);
		}
	}
}

int main()
{
	int stack[10];
	int top = 0;
	int maxSize = 10;
	int choice;
	do
	{
		printf("\nEnter Your Choice:\n");
		printf("Press 1 to Insert an Element\n");
		printf("Press 2 to Remove Top Element\n");
		printf("Press 3 to View Top Element\n");
		printf("Press 4 to View All Elements\n");
		printf("Press 5 to Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				push(stack, &top, maxSize);
				break;
			case 2:
				pop(stack, &top);
				break;
			case 3:
				peek(stack, &top);
				break;	
			case 4:
				display(stack, &top);
				break;
			case 5:
				break;
			default:
				printf("Invalid Choice!\n");
				break;
		}
	} while(choice != 5);
	return 0;
}
