#include "addressbook.h"
#include <iostream>

int main()
{
	AddressBooks* abs = new AddressBooks;  // Allocate memory dynamically

	int select = 0;
	while (true)
	{
		showMenu();
		std::cin >> select;

		switch (select)
		{
		case 1:
			AddContacts(abs);
			break;
		case 2:
			ShowContacts(abs);
			break;
		case 3:
			DeleteContact(abs);
			break;
		case 4:
			SearchContact(abs);
			break;
		case 5:
			ModifyContact(abs);
			break;
		case 6:
			ClearContacts(abs);
			break;
		case 0:
			std::cout << "Thank you for using AddressBook. Goodbye!" << '\n';
			system("pause");
			return 0;
		default:
			std::cout << "Invalid input. Please try again." << '\n';
			system("pause");
			system("cls");
		}
	}
	delete abs;

	return 0;
}