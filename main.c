#include <stdio.h>
#include "myBank.h"
int main()
{
	char input[2] = {'X','\0'};
	double amount;
	int account_num;
	while (1)
	{
		printf("\nPlease choose a transaction type:");
		printf("\nO - Open account");
		printf("\nB - Balance Inquiry");
		printf("\nD - Deposit");
		printf("\nW - Withdrawal");
		printf("\nC - Close Account");
		printf("\nI - Interest");
		printf("\nP - Print");
		printf("\nE - Exit\n");
		scanf("%s",&input[0]);
		if (input[0] == 'O')
		{
			printf("\nInitial deposit?:");
			scanf("%lf",&amount);
			open_account(amount);
		}
		else if (input[0] == 'B')
		{
			printf("\nAccount number?:");
			scanf("%d",&account_num);
			account_amount(account_num);
		}
		else if (input[0] == 'D')
		{
			printf("\nAccount number?:");
			scanf("%d",&account_num);
			printf("\nAmount:");
			scanf("%lf",&amount);
			deposit(account_num,amount);
		}
		else if (input[0] == 'W')
		{
			printf("\nAccount number?:");
			scanf("%d",&account_num);
			printf("\nAmount:");
			scanf("%lf",&amount);
			withdraw(account_num,amount);
		}
		else if (input[0] == 'C')
		{
			printf("\nAccount number?:");
			scanf("%d",&account_num);
			close_account(account_num);
		}
		else if (input[0] == 'I')
		{
			printf("\nInterest rate?:");
			scanf("%lf",&amount);
			update_interest(amount);
		}
		else if (input[0] == 'P')
		{
			print();
		}
		else if (input[0] == 'E')
		{
			finish();
			break;
		}
		else
		{
			printf("Invalid Transaction type");
		}
	}
		return 0;
}