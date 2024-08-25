#pragma once
#include <iostream>
#include <string>

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
class deposit : public account {
public:
	deposit(int moneyAmount,std::string name);
	void moneyTransfer(int moneyAmount, account& recivePerson) override;
	void moneyWitdraw(int moneyAmount) override;
};


class saving : public account {
public:
	saving(int moneyAmount, std::string name);
	void moneyWitdraw(int moneyAmount) override;
};

