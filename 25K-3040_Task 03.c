#include<stdio.h>
#define rows 3
#define cols 3
#define power_on (1 << 0)
#define overload (1 << 1)
#define maintenance (1 << 2)

void updateSectorStatus(int grid[][cols])
{
	int row, col, flag, action;
	printf("Enter Sector Coordinates (row, col):\n");
	scanf("%d %d", &row, &col);
	
	if(row < 0 || row >= rows || col < 0 || col >=cols)
	{
		printf("Invalid Coordinates!\n\n");
		return;
	}
	
	printf("Select Status to Update:\n");
	printf("1. Power Status\n2. Overload Warning\n3. Maintenance Required\n");
	scanf("%d", &flag);
	printf("Enter Action (1. Set | 0. Clear): ");
	scanf("%d", &action);
	
	int bitMask = 0;
	switch(flag)
	{
		case 1:
			bitMask = power_on;
			break;
		case 2:
			bitMask = overload;
			break;
		case 3:
			bitMask = maintenance;
			break;
		default:
			printf("Invalid Flag!\n\n");
			return;
	}
	if(action == 1)
	{
		grid[row][col] |= bitMask;
	}
	else
	{
		grid[row][col] &= ~bitMask;
	}
	printf("Sector (%d, %d) Updated Successfully!\n\n", row, col);
}

void querySectorStatus(int grid[][cols])
{
	int row, col;
	printf("Enter Sector Coordinates (row, col):\n");
	scanf("%d %d", &row, &col);
	
	if(row < 0 || row >= rows || col < 0 || col >=cols)
	{
		printf("Invalid Coordinates!\n\n");
		return;
	}
	
	int status = grid[rows][cols];
	printf("\nSector (%d, %d) Status Report:\n", row, col);
    printf("Power: %s\n", (status & power_on) ? "On" : "Off");
    printf("Overload: %s\n", (status & overload) ? "Yes" : "No");
    printf("Maintenance Required: %s\n", (status & maintenance) ? "Yes" : "No");
}

void runSystemDiagnostic(int grid[][cols])
{
	int i, j, overloadCount = 0, maintenanceCount = 0;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			if(grid[i][j] & overload)
			{
				overloadCount++;
			}
			if(grid[i][j] & maintenance)
			{
				maintenanceCount++;
			}
		}
	}
	printf("Total Overloaded Sectors: %d\n", overloadCount);
	printf("Total Sectors Requiring Maintenance: %d\n", maintenanceCount);
}

int main()
{
	int grid[rows][cols] = {0};
	int choice;
	do
	{
		printf("\nEnter Your Choice:\n");
		printf("Press 1 to Update Sector Status\n");
		printf("Press 2 to Query Sector Status\n");
		printf("Press 3 to Run System Diagnostic\n");
		printf("Press 4 to Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				updateSectorStatus(grid);
				break;
			case 2:
				querySectorStatus(grid);
				break;
			case 3:
				runSystemDiagnostic(grid);
				break;
			case 4:
				break;
			default:
				printf("Invalid Choice!\n");
				break;
		}
	} while(choice != 4);
	return 0;
}
