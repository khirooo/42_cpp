#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:

	std::string	_ideas[100];
public:

	Brain();
	Brain(Brain& brain);
	Brain& operator=(Brain& brain);
	~Brain();

	std::string*	getIdeas(void);
	std::string		getIdea(int index);

	void			setIdea(int index, std::string idea);
};

#endif