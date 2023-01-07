#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
	_count = 0;
}

PhoneBook::~PhoneBook()
{
}

Contact	PhoneBook::getContact(int index) const
{
	return this->_contacts[index];
}

int		PhoneBook::getCount() const
{
	return this->_count;
}

void	PhoneBook::setContact(Contact contact)
{
	this->_contacts[this->_index] = contact;
	_index++;
	if (_count != 8)
		_count++;
	if (_index == 8)
		_index = 0;
}

