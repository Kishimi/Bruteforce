#pragma once

#include <string>

using uint32 = unsigned int;

class Bruteforce
{
public:
	// @brief construct this class with a range, where the range defines the length of the string
	// @param start - the start of the range
	// @param end - the end of the range
	Bruteforce(const uint32 start, const uint32 end);

	// @brief construct this class with a range, where the range defines the length of the string
	// @param start - the start of the range
	// @param end - the end of the range
	// @param charset - the set of characters to use
	Bruteforce(const uint32 start, const uint32 end, const std::string charset);

	// @return true - if the string is still in the range
	bool in_range() const;

	// @return the string that is being "bruteforced"
	std::string get() const;

	// @brief execute one iteration of this algorithm
	void next();

private:
	std::string string;
	const std::string charset;

	const uint32 start, end;
};