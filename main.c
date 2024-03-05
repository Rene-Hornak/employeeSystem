/*
	C program to create employee management system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct employeeDetails {
	char name[50];
	long int code;
	char designation[50];
	int experience;
	int age;
};

int number;

struct employeeDetails employee[MAX];

// Function prototypes
void build();
void insert();
void deleteIndex(int i);
void deleteRecord();
void searchRecord();

// Show menu
int main()
{
	int option;

	printf("--------------------------\n");
	printf("Employee Management System\n");	
	printf("--------------------------\n\n");

	printf("Build Table		[1]\n");
	printf("Insert New Entry	[2]\n");
	printf("Delete Entry		[3]\n");
	printf("Search a Record		[4]\n");
	printf("Exit			[5]\n");

	printf("\n\nEnter option... ");
	scanf("%d", &option);

	switch(option)
	{
		case 1:
			build();
			break;
		
		case 2:
			insert();
			break;

		case 3:
			deleteRecord();
			break;

		case 4:
			searchRecord();
			break;

		case 5:
			exit(0);
			break;

		default:
			printf("Error: Expected Options are 1/2/3/4/5\n");
			main();
	}

	return 0;
}

// Function to build the given datatype
void build() 
{
	printf("\n\tBuild The Table\n\n");
	printf("Maximum Entries can be %d\n", MAX);

	printf("Enter the number of Entries required: ");
	scanf("%d", &number);

	if(number > MAX)
	{
		printf("\n\nMaximum number of Entries is %d\n", MAX);
		number = MAX;
	}
	
	printf("Enter the following data:\n");
	for(int i = 0; i < number; i++)
	{
		printf("Name: ");
		scanf("%s", employee[i].name);

		printf("Employee ID: ");
		scanf("%ld", &employee[i].code);

		printf("Designation: ");
		scanf("%s", employee[i].designation);

		printf("Experience: ");
		scanf("%d", &employee[i].experience);

		printf("Age: ");
		scanf("%d", &employee[i].age);

		printf("\n");
	}

	main();
}

// Function to insert the data into given data type
void insert() 
{
	if(number < MAX)
	{
		int i = number;
		number++;

		printf("Enter the information of the Employee\n");
		
		printf("Name: ");
		scanf("%s", employee[i].name);

		printf("Employee ID: ");
		scanf("%ld", &employee[i].code);

		printf("Designation: ");
		scanf("%s", employee[i].designation);

		printf("Experience: ");
		scanf("%d", &employee[i].experience);

		printf("Age: ");
		scanf("%d", &employee[i].age);
	}
	else
	{
		printf("Employee Table Full\n");
	}

	main();
}

// Function to delete record at index 1
void deleteIndex(int i)
{
	for(int j = i; j < number - 1; j++)
	{
		strcpy(employee[j].name, employee[j + 1].name);
		employee[j].code = employee[j + 1].code;
		strcpy(employee[j].designation, employee[j + 1].designation);
		employee[j].experience = employee[j + 1].experience;
		employee[j].age = employee[j + 1].age;
	}
	return;
}

// Function to delete record
void deleteRecord()
{
	printf("Enter the Employee ID to Delete Record: ");

	long int code;
	scanf("%ld", &code);

	for(int i = 0; i < number; i++)
	{
		if(employee[i].code == code)
		{
			deleteIndex(i);
			number--;
			break;
		}
	}

	main();
}

void searchRecord()
{
	printf("Enter the Employee ID to Search Record: ");

	long int code;
	scanf("%ld", &code);

	for(int i = 0; i < number; i++)
	{
		// If the data is found
		if(employee[i].code == code)
		{
			printf("Name: %s\n", employee[i].name);
			printf("Employee ID: %ld\n", employee[i].code);
			printf("Designation: %s\n", employee[i].designation);
			printf("Experience: %d\n", employee[i].experience);
			printf("Age: %d\n", employee[i].age);
			break;
		}
	}

	main();
}
