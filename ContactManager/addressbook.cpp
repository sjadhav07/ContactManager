#include "addressbook.h"
#include <iostream>

using std::cout;
using std::cin;

void showMenu()
{
	cout << "********************************" << '\n';
	cout << "***** Address Book Manager *****" << '\n';
	cout << "********************************" << '\n';
	cout << "*****   1. Add Contact    ******" << '\n';
	cout << "*****   2. Show Contacts  ******" << '\n';
	cout << "*****   3. Delete Contact ******" << '\n';
	cout << "*****   4. Search Contact ******" << '\n';
	cout << "*****   5. Modify Contact ******" << '\n';
	cout << "*****   6. Clear Contacts ******" << '\n';
	cout << "*****   0. Exit AddressBook*****" << '\n';
	cout << "********************************" << '\n';

}

void AddContacts(AddressBooks* abs)
{
	if (abs->aCount == Max)
	{
		cout << "Address book is full. Unable to add more contacts." << '\n';
		return;
	}
	else
	{
		// assigning attributes. Note: Should be made into separate functions if project is continued.
		std::string name;
		cout << "Enter name: " << '\n';
		cin >> name;
		abs->contactsArray[abs->aCount].cName = name;

		int gender;
		cout << "Enter gender: " << '\n';
		cout << "1. Male" << '\n';
		cout << "2. Female" << '\n';

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArray[abs->aCount].cGender = gender;
				break;
			}
			cout << "Invalid input. Please try again." << '\n';
		}

		int age;
		cout << "Enter age: " << '\n';
		cin >> age;
		abs->contactsArray[abs->aCount].cAge = age;

		std::string phone;
		cout << "Enter phone number: " << '\n';
		cin >> phone;
		abs->contactsArray[abs->aCount].cPhone = phone;

		std::string add;
		cout << "Enter address: " << '\n';
		cin >> add;
		abs->contactsArray[abs->aCount].cAdd = add;

		abs->aCount += 1;
		cout << "Contact added successfully!" << '\n';
		system("pause");
		system("cls");
	}
}

void ShowContacts(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "No contacts found. Please add contacts first!" << '\n';
	}
	else
	{
		for (int i = 0; i < abs->aCount; i++)
		{
			cout << "Name: " << abs->contactsArray[i].cName << " Gender: " << (abs->contactsArray[i].cGender != 2 ? "Male" : "Female") << " Age: " << abs->contactsArray[i].cAge << " Phone: " << abs->contactsArray[i].cPhone << " Address: " << abs->contactsArray[i].cAdd << '\n';
		}
	}
	system("pause");
	system("cls");
}

void DeleteContact(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "No contacts found. Please add contacts first!" << '\n';
	}
	else
	{
		std::string name;
		cout << "Enter the name of the contact you want to delete: " << '\n';
		cin >> name;

		int index = -1;

		for (int i = 0; i < abs->aCount; i++)
		{
			if (abs->contactsArray[i].cName == name)
			{
				index = i;
				break;
			}
		}

		if (index != -1)
		{
			for (int i = index; i < abs->aCount - 1; i++)
			{
				abs->contactsArray[i] = abs->contactsArray[i + 1];
			}

			abs->aCount -= 1;
			cout << "Contact deleted successfully!" << '\n';
		}
		else
		{
			cout << "Contact not found!" << '\n';
		}
	}
	system("pause");
	system("cls");
}

void SearchContact(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "No contacts found. Please add contacts first!" << '\n';
	}
	else
	{
		std::string name;
		cout << "Enter the name of the contact you want to search: " << '\n';
		cin >> name;

		bool found = false;

		for (int i = 0; i < abs->aCount; i++)
		{
			if (abs->contactsArray[i].cName == name)
			{
				cout << "Contact found!" << '\n';
				cout << "Name: " << abs->contactsArray[i].cName << " Gender: " << (abs->contactsArray[i].cGender != 2 ? "Male" : "Female") << " Age: " << abs->contactsArray[i].cAge << " Phone: " << abs->contactsArray[i].cPhone << " Address: " << abs->contactsArray[i].cAdd << '\n';
				found = true;
				break;
			}
		}

		if (!found)
		{
			cout << "Contact not found!" << '\n';
		}
	}
	system("pause");
	system("cls");
}

void ModifyContact(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "No contacts found. Please add contacts first!" << '\n';
	}
	else
	{
		std::string name;
		cout << "Enter the name of the contact you want to modify: " << '\n';
		cin >> name;

		bool found = false;

		for (int i = 0; i < abs->aCount; i++)
		{
			if (abs->contactsArray[i].cName == name)
			{
				cout << "Contact found!" << '\n';
				cout << "Enter the modified information for the contact: " << '\n';

				std::string newName;
				cout << "Enter new name: " << '\n';
				cin >> newName;
				abs->contactsArray[i].cName = newName;

				int newGender;
				cout << "Enter new gender: " << '\n';
				cout << "1. Male" << '\n';
				cout << "2. Female" << '\n';

				while (true)
				{
					cin >> newGender;
					if (newGender == 1 || newGender == 2)
					{
						abs->contactsArray[i].cGender = newGender;
						break;
					}
					cout << "Invalid input. Please try again." << '\n';
				}

				int newAge;
				cout << "Enter new age: " << '\n';
				cin >> newAge;
				abs->contactsArray[i].cAge = newAge;

				std::string newPhone;
				cout << "Enter new phone number: " << '\n';
				cin >> newPhone;
				abs->contactsArray[i].cPhone = newPhone;

				std::string newAdd;
				cout << "Enter new address: " << '\n';
				cin >> newAdd;
				abs->contactsArray[i].cAdd = newAdd;

				cout << "Contact modified successfully!" << '\n';
				found = true;
				break;
			}
		}

		if (!found)
		{
			cout << "Contact not found!" << '\n';
		}
	}
	system("pause");
	system("cls");
}

void ClearContacts(AddressBooks* abs)
{
	abs->aCount = 0;
	cout << "All contacts cleared successfully!" << '\n';
	system("pause");
	system("cls");
}