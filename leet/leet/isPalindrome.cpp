#include <iostream>
using namespace std;
bool isPalindrome(int x) {

	int long val = 0;
	int temp = x;
	if (x < 0)
	{
		return false;

	}
	else if (x < 9)
	{
		return true;
	}
	else
	{
		while (x)
		{
			val = x % 10 + val * 10;
			x /= 10;
		}
	}

	return val == temp;

}