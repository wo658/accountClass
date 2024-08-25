#include "account.h"

account::account(int moneyAmout, std::string Name)
{
	money = moneyAmout;
	accountName = Name;
}

void account::moneyTransfer(int moneyAmount, account& recivePerson) {}

void account::moneyPrint() const
{
	std::cout << accountName << " Money : " << money << std::endl;
}

int account::getMoney() const
{
	return money;
}

void account::setMoney(int addMoney)
{
	money = money + addMoney;
}

deposit::deposit(int moneyAmount,std::string name): account(moneyAmount,name) {}

void deposit::moneyTransfer(int moneyAmount, account& recivePerson)
{
	recivePerson.setMoney(moneyAmount);
	this->setMoney(-moneyAmount);
}

void deposit::moneyWitdraw(int moneyAmount)
{
	this->setMoney(-moneyAmount);
}

saving::saving(int moneyAmount, std::string name) : account(moneyAmount, name) {}

void saving::moneyWitdraw(int moneyAmount)
{
	if (this->getMoney() == moneyAmount)
		this->setMoney(-moneyAmount);
}
