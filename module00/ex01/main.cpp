#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

void	addContact(PhoneBook *repertoire)
{
	Contact	contact;
	std::string	input("");

	std::cout << "enter contact information" << std::endl;
	while (!input.length())
	{
		std::cout << "first name (not empty): ";
		std::getline(std::cin, input);
	}
	contact.setFirstName(input);
	input.resize(0);
	while (!input.length())
	{
		std::cout << "last name (not empty): ";
		std::getline(std::cin, input);
	}
	contact.setLastName(input);
	input.resize(0);
	while (!input.length())
	{
		std::cout << "nick name (not empty): ";
		std::getline(std::cin, input);
	}
	contact.setNickName(input);
	input.resize(0);
	while (!input.length())
	{
		std::cout << "phone number (not empty): ";
		std::getline(std::cin, input);
	}
	contact.setPhoneNumber(input);
	input.resize(0);
	while (!input.length())
	{
		std::cout << "darkest secret (not empty): ";
		std::getline(std::cin, input);
	}
	contact.setDarkestSecret(input);
	repertoire->setContact(contact);
}

std::string	shrink(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(1, '.');
		return  str;
	}
	return str;
}

bool	isNum(std::string input)
{
	unsigned int i = 0;

	if (input[i] == '-' || input[i] == '+')
		i++;
	while (i < input.length())
	{
		if (std::isdigit(input[i]) == false)
			return false;
		i++;
	}
	return true;
}

void	displayContact(Contact contact)
{
	std::cout << "  --Contact information--" << std::endl << std::endl;
	std::cout << " first name: " << contact.getFirstName() << std::endl;
	std::cout << " last name: " << contact.getLastName() << std::endl;
	std::cout << " nickname: " << contact.getNickName() << std::endl;
	std::cout << " phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << " darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void	searchContact(PhoneBook repertoire)
{
	Contact contact;
	std::string	str;
	int	index = -1;

	std::cout << std::endl << std::string(45,'-') << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "index";
	std::cout << "|" << std::setw(10) << std::right << "first name";
	std::cout << "|" << std::setw(10) << std::right << "last name";
	std::cout << "|" << std::setw(10) << std::right << "nickname" << "|" << std::endl;
	std::cout << std::string(45,'-') << std::endl;
	for(int i = 0; i < repertoire.getCount(); i++)
	{
		contact = repertoire.getContact(i);
		std::cout << "|" << std::setw(10) << std::right << i;
		std::cout << "|" << std::setw(10) << std::right << shrink(contact.getFirstName());
		std::cout << "|" << std::setw(10) << std::right << contact.getLastName();
		std::cout << "|" << std::setw(10) << std::right << contact.getNickName() << "|" << std::endl;
	}

	while (!isNum(str) || index < 0 || index >= repertoire.getCount() || str == "+" || str == "-")
	{
		std::cout << "enter a contact index: ";
		getline(std::cin, str);
		std::stringstream(str) >> index;
		if (!isNum(str) || index < 0 || index >= repertoire.getCount() || str == "+" || str == "-")
			std::cout << "Invalid index" << std::endl;
	}
	displayContact(repertoire.getContact(index));
}

int	main()
{
	PhoneBook	repertoire;
	std::string	command;

	std::cout << "  --Available commands--" << std::endl << std::endl;
	std::cout << " -ADD: save a new contact." << std::endl;
	std::cout << " -SEARCH: display a specific contact." << std::endl;
	std::cout << " -EXIT: quite the program (contacts will be lost)." << std::endl << std::endl;
	while (1)
	{
		std::cout << "enter a command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			addContact(&repertoire);
		else if(command == "SEARCH")
			searchContact(repertoire);
		else if(command == "EXIT")
			break;
	}
	return (0);
}
