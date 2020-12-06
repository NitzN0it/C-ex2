#include <stdio.h>
#include <stdlib.h>
#include "myBank.h"
char bank_accounts[50][12]; // 11 digits for the amount (+/- and 10 digits), and 1 digit for (O)pen / (C)olsed
int accounts_counter = 0;
int account_check (int account_num)
{
		if ((account_num > 949) || (account_num < 900))
	{
		printf("Invalid account number\n");
		return -1;
	}
	account_num -=901;
	if (bank_accounts[account_num][11] != 'O')
	{
			printf("This account is closed\n");
			return -1;
	}
	return account_num;
}
void open_account (double amount)
{
	if (amount < 0)
		return;
	if (accounts_counter != 50)
	{
		sprintf(bank_accounts[accounts_counter],"%lf",amount);
		bank_accounts[accounts_counter][11]='O';
		printf("New account number is:%d",accounts_counter+901);
		accounts_counter++;
	}
	else
	{
		printf("Can't open new account, already has 50 accounts");
	}
}

void account_amount (int account_num)
{
	account_num = account_check(account_num);
	if (account_num == -1)
		return;
	double amount = strtod(bank_accounts[account_num],NULL);
	printf("Current amount is:%.2f",amount);
}
void deposit (int account_num, double amount)
{
	if (amount < 0)
		return;
	account_num = account_check(account_num);
	if (account_num == -1)
		return;
	double current_amount = strtod(bank_accounts[account_num],NULL);
	current_amount+=amount;
	sprintf(bank_accounts[account_num],"%lf",current_amount);
	printf("New amount is:%.2f",current_amount);
}
void withdraw (int account_num, double amount)
{
	if (amount < 0)
		return;
	account_num = account_check(account_num);
	if (account_num == -1)
		return;
	double current_amount = strtod(bank_accounts[account_num],NULL);
	if (current_amount >= amount)
	{
		current_amount-=amount;
		sprintf(bank_accounts[account_num],"%lf",current_amount);
		printf("New amount is:%.2f",current_amount);
	}
	else
		printf("There isn't enough money in your account");
}
void close_account (int account_num)
{
	account_num = account_check(account_num);
	if (account_num == -1)
		return;
	bank_accounts[account_num][11] = 'C';
	printf("Account number:%d is closed now.",account_num);
}
void update_interest (double rate)
{
	if (rate <=0)
	{
		printf("Invalid rate");
		return;
	}
	double current_amount = 0;
	for (int i=0; i<accounts_counter; i++)
	{
		if (bank_accounts[i][11] == 'O')
		{
			current_amount = strtod(bank_accounts[i],NULL);
			current_amount = current_amount * (1+(rate/100));
			sprintf(bank_accounts[i],"%.2lf",current_amount);
		}
	}
	printf("Interest rate has been updated to all open accounts");
}
void print()
{
	double current_amount = 0;
	for (int i=0; i<accounts_counter; i++)
	{
		if (bank_accounts[i][11] == 'O')
		{
			current_amount = strtod(bank_accounts[i],NULL);
			printf("\nAccount number:%d, Current amount:%.2lf",i+901,current_amount);
		}
	}
}
void finish()
{
	for (int i=0; i<accounts_counter; i++)
	{
		bank_accounts[i][11]='O';
	}
	printf("All accounts has been closed, exiting\n");
}