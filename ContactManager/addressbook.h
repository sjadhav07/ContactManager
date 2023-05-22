#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <string>

constexpr auto Max = 1000;

struct Contacts
{
	std::string cName;
	int cGender = 1;
	int cAge = 0;
	std::string cPhone;
	std::string cAdd;
};

struct AddressBooks
{
	Contacts contactsArray[Max];
	int aCount = 0;
};

void showMenu();
void AddContacts(AddressBooks* abs);
void ShowContacts(AddressBooks* abs);
void DeleteContact(AddressBooks* abs);
void SearchContact(AddressBooks* abs);
void ModifyContact(AddressBooks* abs);
void ClearContacts(AddressBooks* abs);

#endif