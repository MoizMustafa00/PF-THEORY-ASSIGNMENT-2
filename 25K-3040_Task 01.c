#include<stdio.h>
#include<conio.h>
#include<string.h>
void add_book(int isbns[], char titles[][50], float prices[], int quantities[], int *count)
{
	int isbnNew, i;
	printf("Enter the isbn: ");
	scanf("%d", &isbnNew);
	for(i=0; i<*count; i++)
	{
		if(isbns[i] == isbnNew)
		{
			printf("Error! Isbn Already Exists\n");
			return;
		}
	}
	isbns[*count] = isbnNew;
	getchar();
	printf("Enter the title: ");
	fgets(titles[*count], sizeof(titles[*count]), stdin);
	titles[*count][strcspn(titles[*count], "\n")] = '\0';
	
	printf("Enter the price: ");
	scanf("%f", &prices[*count]);
	printf("Enter the quantity: ");
	scanf("%d", &quantities[*count]);
	(*count)++;
	printf("Book Added Successfully!\n\n");
}

void sale(int isbns[], int quantities[], int count)
{
	int isbnSearch, copiesSold, i, found = 0;
	printf("Enter the isbn: ");
	scanf("%d", &isbnSearch);
	for(i=0; i<count; i++)
	{
		if(isbns[i] == isbnSearch)
		{
			found = 1;
			printf("Current quantity = %d\n", quantities[i]);
			printf("Enter the no of copies sold: ");
			scanf("%d", &copiesSold);
			if(copiesSold <= 0)
			{
				printf("Invalid No of Copies\n\n");
				return;
			}
			if(quantities[i] == 0)
			{
				printf("Out of Stock");
				return;
			}
			else if(quantities[i] < copiesSold)
			{
				printf("Not Enough Stock Available\n\n");
				return;
			}
			quantities[i] -= copiesSold;
			printf("Sale Processed Successfully!\n");
			printf("Updated Quantity = %d\n\n", quantities[i]);
			break;
		}
	}
	if(!found)
	{
		printf("Book Not Found!\n\n");
	}
}

void stock_report(int isbns[], char titles[][50], float prices[], int quantities[], int count)
{
	int i, found = 0;
	for(i=0; i<count; i++)
	{
		if(quantities[i] < 5)
		{
			printf("Isbn = %d\n", isbns[i]);
			printf("Title = %s\n", titles[i]);
			printf("Price = %.2f\n", prices[i]);
			printf("Quantity = %d\n\n", quantities[i]);
			found = 1;
		}
	}
	if(!found)
	{
		printf("No Low Stock Items!\n\n");
	}
}

int main()
{
	int isbns[100];
	char titles[100][50];
	float prices[100];
	int quantities[100];
	
	int count = 0;
	char choice;
	do
	{
		printf("Enter 1 for Adding a New Book\nEnter 2 for Processing a Sale\nEnter 3 for Generating Low Stock Report\nEnter 4 to Exit\n");
		scanf(" %c", &choice);
		switch(choice)
		{
			case '1':
				add_book(isbns, titles, prices, quantities, &count);
				break;
			case '2':
				sale(isbns, quantities, count);
				break;
			case '3':
				stock_report(isbns, titles, prices, quantities, count);
				break;
			case '4':
				break;
		}
	} while(choice != '4');
	return 0;
}
