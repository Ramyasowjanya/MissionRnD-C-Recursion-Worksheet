/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"
int factorial(int no, int end)
{
	if (no == end)
		return 1;
	else
	{
		return no*factorial(no - 1, end);
	}
}
void get_step_count(int *result, int step_count, int present_count, int steps, int s)
{
	int temp, res = 0;
	if (present_count == step_count + 1)
		return;
	else
	{
		if (present_count == 1)
		{
			*result = *result + steps;
		}
		else
		{
			temp = s - (present_count * 2);
			if (temp > s)
			{
				res = factorial(steps, temp);
				*result = *result + (res / factorial(present_count, 2));
			}
			else
			{
				if (temp == 0)
					*result = *result + 1;
				else {
					res = factorial(steps, present_count);
					*result = *result + (res / factorial(temp, 1));
				}
			}
		}
		++present_count;
		get_step_count(result, step_count, present_count, --steps, s);
	}
}
int get_steps(int s)
{
	int result = 0, step_2 = 0;
	if (s == 0)
		return 0;
	else if (s == 1)
		return 1;
	else if (s == 2)
		return 2;
	else
	{
		step_2 = s / 2;
		get_step_count(&result, step_2, 1, s - 1, s);
		return result + 1;
	}
}