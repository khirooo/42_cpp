#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor is called." << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = "No ideas here!";
}

Brain::Brain(Brain& brain)
{
	std::cout << "Brain copy constructor is called." << std::endl;

	for(int i=0; i < 100; i++)
		this->_ideas[i] = brain._ideas[i];
}

Brain&	Brain::operator=(Brain& brain)
{
	std::cout << "Brain copy assign operator is called." << std::endl;

	for(int i=0; i < 100; i++)
		this->_ideas[i] = brain._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called." << std::endl;
}

std::string	Brain::getIdea(unsigned int index) const
{
	if (index > 99)
	{
		std::cout << "Index out of range" << std::endl;//better to raise an exception but it's cpp04 ;)
		return ("");
	}
	return (_ideas[index]);
}

void	Brain::setIdea(unsigned int index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	_ideas[index] = idea;
}
