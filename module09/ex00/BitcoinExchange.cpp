#include "BitcoinExchange.hpp"

static bool isLeap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

static double 
BitcoinExchange::BitcoinExchange(std::string db_file)
{
	if (db_file.empty() || db_file.size() < 5 || !(db_file.substr(db_file.size() - 4) == ".csv"))
		throw WrongFileFormatExp();
	std::ifstream my_file(db_file);
	if (!my_file.is_open())
		throw CouldNotOpenFile();
	std::string	line;
	double last_value = -1;
	while (!my_file.eof())
	{
		std::getline(my_file, line);
		if (_db.empty() && line == "date,exchange_rate")
			continue;
		if (line.empty())
			continue;
		std::istringstream ss(line);
		std::tm date = {};
		double	value;
		ss >> std::get_time(&date, "%y-%m-%d");
		if (ss.fail())
			throw CorruptedDataFile();
		if (date.tm_mon == 1)
		{
			if (date.tm_mday > 29)
				throw CorruptedDataFile();
			if (!isLeap(date.tm_year) && date.tm_mday > 28)
				throw CorruptedDataFile();
		}
		char delim;
		std::cout << ss.str() << std::endl;
		ss >> delim >> value;
		if (ss.fail() || delim != ',' || value < 0)
			throw CorruptedDataFile();
		if (value != last_value)
		_db.insert(std::make_pair(std::mktime(&date), value));
	}
	my_file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::exchange(std::string input)
{
	std::ifstream my_file(input);
	if (!my_file.is_open())
		throw CouldNotOpenFile();
	std::string line;
	while (!my_file.eof())
	{
		std::getline(my_file, line);
		if (line.empty() || line == "date | value")
			continue;
		std::istringstream	ss(line);
		std::tm	date = {};
		int		nb;
		ss >> std::get_time(&date, "%y-%m-%d");
		if (ss.fail())
		{
			std::cout << "Error: bad date => " << line << std::endl;
			continue;
		}
		char delim;
		ss >> delim;
		if (ss.fail() || delim != '|')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		ss >> nb;
		if (ss.fail())
		{
			std::cout << "Error: number to large" << std::endl;
			continue;
		}
		if (nb < 0)
		{
			std::cout << "Error: number negative" << std::endl;
			continue;
		}

	}
}

void	BitcoinExchange::print_db(void) const
{
	std::map<std::time_t, double>::const_iterator	it;
	for (it = _db.begin(); it != _db.end(); ++it)
	{
		std::cout << std::asctime(std::localtime(&it->first)) << ", " << it->second << std::endl;
	}
}


const char* BitcoinExchange::WrongFileFormatExp::what() const throw()
{
	return "Wrong file format for data base *.csv";
}

const char* BitcoinExchange::CouldNotOpenFile::what() const throw()
{
	return "Could not open file (check file location)";
}

const char* BitcoinExchange::CorruptedDataFile::what() const throw()
{
	return "Data base file corrupted";
}
