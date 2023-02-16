#include <sstream>
#include <string>

typedef	struct s_Data
{
	std::string	string_data;
	int			int_data;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(Serializer& copy);
	Serializer&	operator=(Serializer& copy);
	~Serializer();
public:
	static	uintptr_t	serialize(Data* ptr);
	static	Data*		deserialize(uintptr_t raw);
};

std::ostream&	operator<<(std::ostream& stream, Data& data);