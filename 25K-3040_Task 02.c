#include<stdio.h>
#include<conio.h>
#include<string.h>

void customer_info(char name[], char cnic[], int name_size, int cnic_size)
{
	printf("Enter Your Name: ");
	fgets(name, name_size, stdin);
	name[strcspn(name, "\n")] = '\0';
	printf("Enter Your CNIC Number: ");
	fgets(cnic, cnic_size, stdin);
	cnic[strcspn(cnic, "\n")] = '\0';
	printf("Name & CNIC Entered Successfully!\n\n");
}

void display_inventory(int product_code[], int quantity[], float price[], int count)
{
	int i;
	printf("\nProduct Code\tQuantity in Stock\tPrice per Product\n");
	for(i=0; i<count; i++)
	{
		printf("%03d\t\t%d\t\t\t%.2f\n", product_code[i], quantity[i], price[i]);
	}
	printf("\n");
}

void update_inventory(int product_code[], int quantity[], int count, int cart_code[], int cart_quant[], int cart_count)
{
	int i, j;
	for(i=0; i<cart_count; i++)
	{
		for(j=0; j<count; j++)
		{
			if(cart_code[i] == product_code[j])
			{
				quantity[j] -= cart_quant[i];
			}
		}
	}
	printf("Inventory Updated Successfully!\n\n");
}

void add_item(int product_code[], int quantity[], float price[], int count, int cart_code[], int cart_quant[], float cart_price[], int *cart_count)
{
	int code, quant, found = 0;
	printf("Enter the Code of the Product to Add to Cart: ");
	scanf("%d", &code);
	printf("Enter the Quantity of the Product to Add to Cart: ");
	scanf("%d", &quant);
	getchar();
	int i;
	for(i=0; i<count; i++)
	{
		if(product_code[i] == code)
		{
			found = 1;
			if(quant > quantity[i])
			{
				printf("Not Enough Stock Available!\n\n");
				return;
			}
			cart_code[*cart_count] = code;
			cart_quant[*cart_count] = quant;
			cart_price[*cart_count] = price[i];
			(*cart_count)++;
			printf("Item Added to Cart Successfully!\n\n");
			update_inventory(product_code, quantity, count, cart_code, cart_quant, *cart_count);
			return;		
		}
	}
	if(!found)
	{
		printf("Product Not Found!\n\n");
	}
}

float total_bill(int cart_quant[], float cart_price[], int cart_count, int *voucher_used)
{
	char voucher;
    float total_price = 0, discount = 0;
    int i;
    for (i = 0; i < cart_count; i++)
    {
        total_price += cart_price[i] * cart_quant[i];
    }
    printf("We Are Offering a Promocode of Eid2025. Do You Have a Voucher? (Y.Yes | N.No)\n");
    scanf(" %c", &voucher);
    getchar();
    if(voucher == 'Y' || voucher == 'y')
    {
        discount = total_price * 0.25;
        total_price -= discount;
    	*voucher_used = 1;
    }
    else
    {
    	*voucher_used = 0;
    }
    printf("Your Total Bill = %.2f\n\n", total_price);
    return total_price;
}

void invoice(char name[], char cnic[], int cart_quant[], float cart_price[], int cart_count, int voucher_used)
{
    int i;
    float total = 0, discount = 0;
    printf("Customer Name: %s\n", name);
    printf("Customer CNIC: %s\n", cnic);
    for (i = 0; i < cart_count; i++)
    {
        total += cart_price[i] * cart_quant[i];
    }
    printf("\nYour Total Bill Without Discount = %.2f\n", total);
    if (voucher_used)
    {
        discount = total * 0.25;
        total -= discount;
        printf("Your Total Bill With Discount = %.2f\n\n", total);
    }
    else
    {
        printf("No Discount Applied.\n\n");
    }	
}

int main()
{
	char name[100];
	char cnic[100];
	int product_code[100] = {001, 002, 003, 004};
	int quantity[100] = {50, 10, 20, 8};
	float price[100] = {100, 200, 300, 150};
	int count = 4;
	
	int cart_code[100];
	int cart_quant[100];
	float cart_price[100];
	int cart_count = 0;
	
	char choice;
	int info_entered = 0;
	int voucher_used = 0;
	do
	{
		printf("Press 1 for Customer Information\n");
		printf("Press 2 for Displaying Inventory \n");
		printf("Press 3 for Updating Inventory\n");
		printf("Press 4 for Adding Item\n");
		printf("Press 5 for Displaying Total Bill\n");
		printf("Press 6 for Showing Invoice\n");
		printf("Press 7 to Exit\n\n");
		scanf(" %c", &choice);
		getchar();
		switch(choice)
		{
			case '1':
				customer_info(name, cnic, sizeof(name), sizeof(cnic));
				info_entered = 1;
				break;
			case '2':
				display_inventory(product_code, quantity, price, count);
				break;
			case '3':
				update_inventory(product_code, quantity, count, cart_code, cart_quant, cart_count);
				break;
			case '4':
				if(!info_entered)
				{
					printf("Enter Customer Info First!\n\n");
					break;
				}
				add_item(product_code, quantity, price, count, cart_code, cart_quant, cart_price, &cart_count);
				break;
			case '5':
				total_bill(cart_quant, cart_price, cart_count, &voucher_used);
				break;
			case '6':
				invoice(name, cnic, cart_quant, cart_price, cart_count, voucher_used);
				break;
			case '7':
				break;
		}
	} while(choice != '7');
	return 0;
}
