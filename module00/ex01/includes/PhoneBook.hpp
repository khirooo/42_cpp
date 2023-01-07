#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:

	Contact	_contacts[8];
	int		_index;
	int		_count;

public:

	PhoneBook();
	~PhoneBook();

	//getters
	Contact	getContact(int index) const;
	int		getCount()	const;
	//setters
	void	setContact(Contact contact);
};

#endif
