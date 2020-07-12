#include "Bruteforce.hpp"

Bruteforce::Bruteforce(const uint32 start, const uint32 end) :
	start(start), end(end),
	charset("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
{
	for (uint32 i = 0; i < start; i++)
	{
		string += charset[0];
	}
}

Bruteforce::Bruteforce(const uint32 start, const uint32 end, const std::string charset) :
	start(start), end(end),
	charset(charset)
{
	for (uint32 i = 0; i < start; i++)
	{
		string += charset[0];
	}
}

bool Bruteforce::in_range() const
{
	return string.size() >= start && string.size() <= end;
}

std::string Bruteforce::get() const
{
	return string;
}

void Bruteforce::next()
{
	// update the last char
	char& str_last = string[string.size() - 1];

	str_last = charset[charset.find(str_last) + 1];

	// if the position of string[i + 1] in charset is bigger then the total size of charset,
	// the character either doesn't exist, or it is the last char of charset, we update string[i], and set string[i + 1] to the last char of charset
	for (uint32 i = 0; i < string.size() - 1; i++)
	{
		if (charset.find(string[i + 1]) >= charset.size())
		{
			string[i] = charset[charset.find(string[i]) + 1];
			string[i + 1] = charset[0];
		}
	}

	// update the first charh
	if (charset.find(string[0]) >= charset.size())
	{
		string[0] = charset[0];
		// when the first character reaches the last of charset, we need to add a new character to the string
		string += charset[0];
	}
}