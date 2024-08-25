#include "account.h"
#include <vector>
int main() {

	
	std::vector<account *> accountList;

	accountList.push_back(new deposit(1000,"depositAccount1"));
	accountList.push_back(new deposit(2000, "depositAccount2"));
	accountList.push_back(new deposit(3000, "depositAccount3"));
	accountList.push_back(new saving(4000, "savingAccount1"));

	saving dstSaving(0, "dstSaving");
	deposit dstDeposit(0, "dstDeposit");


	for (auto e : accountList)
		e->moneyPrint();

	for (auto e : accountList)
		e->moneyWitdraw(300);

	for (auto e : accountList)
		e->moneyPrint();

	for (auto e : accountList) {
		if (dynamic_cast<deposit*>(e)) {
			e->moneyTransfer(500,dstSaving);
			e->moneyTransfer(300,dstDeposit);
		}
	}

	dstSaving.moneyPrint();
	dstDeposit.moneyPrint();

	for (auto e : accountList) 
		delete e;
	
	accountList.clear();

	return 0;
}