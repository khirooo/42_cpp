#ifndef BT_EXH_HPP
#define BT_EXH_HPP
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <exception>

class BitcoinExchange
{
private:
	std::map<std::time_t, double>	_db;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	~BitcoinExchange();

	void	exchange(std::string input);
	void	print_db(void) const;
	double	get_price(std::tm& date);
	class WrongFileFormatExp : public std::exception
	{
		const char* what() const throw();
	};
	class CouldNotOpenFile : public std::exception
	{
		virtual const char* what() const throw();
	};
	class CorruptedDataFile : public std::exception
	{
		const char* what() const throw();
	};
};


#endif