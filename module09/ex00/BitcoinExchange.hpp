#ifndef BT_EXH_HPP
#define BT_EXH_HPP
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <exception>


class CostumExp: public std::exception
{
	virtual const char* what() const throw();
};

class BitcoinExchange
{
private:
	std::map<std::time_t, double>	_db;
public:
	BitcoinExchange(std::string	db_file);
	~BitcoinExchange();

	void	exchange(std::string input);
	void	print_db(void) const;
	class WrongFileFormatExp : public std::exception
	{
		const char* what() const throw();
	};
	class CouldNotOpenFile : public CostumExp
	{
		private:
			std::string _fname;
		public:
			CouldNotOpenFile(const std::string& name);
		virtual const char* what() const throw();
	};
	class CorruptedDataFile : public std::exception
	{
		const char* what() const throw();
	};
};


#endif