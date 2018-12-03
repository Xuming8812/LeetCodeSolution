#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
*/
int guess(int num);


//use left closed, right open section [left,right)
int guessNumber(int n)
{
	if (n < 1)
	{
		return n;
	}

	int middle, left{ 1 }, right{n};

	while (left < right)
	{
		middle = left + (right - left) / 2;

		if (guess(middle) == 0)
		{
			return middle;
		}
		else if (guess(middle) == -1)
		{
			right = middle;
		}
		else
		{
			left = middle + 1;
		}
	}
	//left is the smallest value that guess(middle) == -1;
	return left;
}