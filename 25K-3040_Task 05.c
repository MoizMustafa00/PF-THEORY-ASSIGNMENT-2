#include<stdio.h>
#include<string.h>

void encodeMessage(char message[])
{
	int i, length = 0;
	char reverse[100];
	
	message[strcspn(message, "\n")] = '\0';
	while(message[length] != '\0')
	{
		length++;
	}
	
	for(i=0; i<length; i++)
	{
		reverse[i] = message[length - i - 1];
	}
	reverse[i] = '\0';
	
	for(i=0; i<length; i++)
	{
		reverse[i] = reverse[i] ^ ((1 << 1) | (1 << 4));
	}
	
	for(i=0; i<length; i++)
	{
		message[i] = reverse[i];
	}
	message[i] = '\0';
	
	printf("Encoded Message: %s\n\n", message);
}

void decodeMessage(char message[])
{
	int i, length = 0;
	char reverse[100];
	
	message[strcspn(message, "\n")] = '\0';
	while(message[length] != '\0')
	{
		length++;
	}
	
	for(i=0; i<length; i++)
	{
		message[i] = message[i] ^ ((1 << 1) | (1 << 4));
	}
	
	for(i=0; i<length; i++)
	{
		reverse[i] = message[length - i -1];
	}
	reverse[i] = '\0';
	
	for(i=0; i<length; i++)
	{
		message[i] = reverse[i];
	}
	message[i] = '\0';
	
	printf("Decoded Message: %s\n\n", message);
}

int main()
{
	char message[100];
	int choice;
	printf("\nEnter The Message:\n");
	fgets(message, sizeof(message), stdin);
	do
	{	
		printf("\nEnter Your Choice:\n");
		printf("Press 1 to Enter the Message\n");
		printf("Press 2 to Encode the Message\n");
		printf("Press 3 to Decode the Message\n");
		printf("Press 4 to Exit\n");
		scanf("%d", &choice);
		getchar();
		switch(choice)
		{
			case 1:
				printf("\nEnter The Message:\n");
				fgets(message, sizeof(message), stdin);
				break;
			case 2:
				encodeMessage(message);
				break;
			case 3:
				decodeMessage(message);
				break;
			case 4:
				break;
			default:
				printf("Invalid Choice!\n\n");
				break;
		}
	} while(choice != 4);
	return 0;
}
