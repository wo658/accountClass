#pragma once
#include <iostream>
#include <string>

/**
* @brief accountAbstractClass 
* @details An account defines attributes that it has in common.
*/
class account {
private:
	int money;
	std::string accountName;
public:
	account(int moneyAmout,std::string Name);
	virtual void moneyTransfer(int moneyAmount, account& recivePerson);
	void moneyPrint() const;
	virtual void moneyWitdraw(int moneyAmount) = 0;
	int getMoney() const;
	void setMoney(int addMoney);
};

/**
* @brief depositClass
* @details It is a deposit account and is an account class in the form of the most common account.
*/
class deposit : public account {
public:
	deposit(int moneyAmount,std::string name);
	void moneyTransfer(int moneyAmount, account& recivePerson) override;
	void moneyWitdraw(int moneyAmount) override;
};

/**
* @brief savingClass
* @details The saving class has limited functionality compared to regular accounts.
*/
class saving : public account {
public:
	saving(int moneyAmount, std::string name);
	void moneyWitdraw(int moneyAmount) override;
};

