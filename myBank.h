#ifndef _MYBANK_H_
	#define _MYBANK_H_
	void open_account (double amount);
	void account_amount (int account_num);
	void deposit (int account_num, double amount);
	void withdraw (int account_num, double amount);
	void close_account (int account_num);
	void update_interest (double rate);
	void print();
	void finish();
#endif