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
	std::string	*id = brain.getIdeas();

	for(int i=0; i < 100; i++)
		this->_ideas[i] = id[i];
}

Brain&	Brain::operator=(Brain& brain)
{
	std::cout << "Brain copy assign constructor is called." << std::endl;
	std::string	*id = brain.getIdeas();

	for(int i=0; i < 100; i++)
		this->_ideas[i] = id[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called." << std::endl;
}

std::string*	Brain::getIdeas(void)
{
	return _ideas;
}

std::string	Brain::getIdea(int index)
{
	if (index < 0 || index > 99)
		return ("");
	return (_ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 99)
		return ;
	_ideas[index] = idea;
}
