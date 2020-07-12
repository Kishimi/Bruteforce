#include <iostream>

#include "Bruteforce.hpp"

int main()
{
	Bruteforce bf(2, 6, "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz1234567890");
	std::string pw;

	std::cout << "Enter your password (containing letters from A-Z, a-z and numbers from 0-9 and with a size of 2 - 6 characters): ";
	std::getline(std::cin, pw);

	while (bf.in_range())
	{
		// printing out the string really slows down the bruteforce, but it wouldn't be spectactular then
		std::cout << bf.get() << "\n";

		if (pw == bf.get())
		{
			std::cout << "Found your password!\n";

			std::cin.get();
			return 0;
		}
		bf.next();
	}

	std::cout << "Did not find your password :(\n";

	std::cin.get();
	return 0;
}