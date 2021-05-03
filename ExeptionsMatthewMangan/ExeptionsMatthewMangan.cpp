/*
* Matthew Mangan
* CIS 1202 501
* May 2, 2021
*/

#include <iostream>

using namespace std;

// Structures

struct invalidCharacterException : public exception {
	const char* what() const throw () {
		return "invalid character";
	}
};

struct invalidRangeException : public exception {
	const char* what() const throw () {
		return "invalid range";
	}
};

// Test the variables

char character(char start, int offset)
{
	if (!isalpha(start))
	{
		throw invalidCharacterException();
	}
	else
	{
		if ((start + offset < 'a'+26 && start + offset >= 'a') || (start + offset < 'A'+26 && start + offset >= 'A'))
		{
			start = start + offset;
			return start;
		}
		throw invalidRangeException();
	}
}

int main()
{
	char start = 'a';
	int offset = 1;

	// Try the variables and catch errors

	try
	{
		cout << character(start, offset);
	}
	catch (invalidCharacterException invalidCharacter)
	{
		cout << "Invalid character";
	}
	catch (invalidRangeException invalidRange)
	{
		cout << "Invalid range";
	}
}

