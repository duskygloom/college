// finding number of committees (by finding nCr)

#include <stdio.h>

int recursive_ncr(int n, int r);
int recursive_ncr_another_method(int n, int r);

int main()
{
	int total_people, committee_size;
	printf("Total number of people: ");
	scanf("%d", &total_people);
	printf("Number of people in each committee: ");
	scanf("%d", &committee_size);
	// considering total_people > committee_size
	printf("Number of committees by using mentioned method: %d\n", 
			recursive_ncr(total_people, committee_size));
	// changing the committee to make the recursion shorter 
	if (committee_size < total_people-committee_size)
		committee_size = total_people - committee_size;
	printf("Number of committees by using alternate method: %d\n", 
			recursive_ncr_another_method(total_people, committee_size));
	return 0;
}

int recursive_ncr(int n, int r)
{
	if (n < r) return 0;
	if (r == 1) return n;
	else if (r == 0) return 1;
	if (n == 0) return 1;
 	return recursive_ncr(n-1, r-1) + recursive_ncr(n-1, r);
}

int recursive_ncr_another_method(int n, int r)
{
	static int result = 1;
	static int counter = 0;
	// using counter to avoid the changing value of n-r
	if (n - counter < 2) return result;
	// n - counter <= n - r
	else if (counter >= r) result /= n - counter;
	else if (n - counter > r) result *= n - counter;
	++counter;
	recursive_ncr_another_method(n, r);
}
