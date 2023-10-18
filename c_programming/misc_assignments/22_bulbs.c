// bulb industry data

#include <stdio.h>

#define MAX_BRANDLEN 20
#define BRANDS_LEN 6
#define WATTS_LEN 5

enum {GEC, Philips, Crompton, Surya, Mysore, Bajaj};
enum {W15, W25, W40, W60, W100};

struct Bulb
{
	int stock;
	float cost;
};

typedef struct Bulb Bulb;

int main()
{
	int brand, watt;
	double total_cost = 0.0;
	// creating the bulb matrix
	char *brands[] = {"GEC", "Philips", "Crompton", "Surya", "Mysore", 
		"Bajaj"};
	int watts[] = {15, 25, 40, 60, 100};
	Bulb bulb_matrix[BRANDS_LEN][WATTS_LEN] = {
		{{20, 5.5F}, {15, 6.0F}, {0, 4.5F}, {25, 5.0F}, {60, 6.0F}},
		{{0, 6.0F}, {22, 7.0F}, {34, 7.5F}, {62, 8.0F}, {0, 8.5F}},
		{{10, 5.5F}, {0, 5.0F}, {25, 6.0F}, {14, 6.5F}, {18, 7.0F}},
		{{28, 6.5F}, {32, 6.0F}, {0, 7.0F}, {48, 7.5F}, {60, 8.0F}},
		{{43, 5.0F}, {25, 7.5F}, {25, 8.0F}, {34, 7.5F}, {68, 8.0F}},
		{{22, 6.0F}, {30, 5.0F}, {41, 5.5F}, {0, 6.5F}, {25, 7.5F}}
	};
	printf("Out of stock:");
	for (brand=GEC; brand<=Bajaj; ++brand) {
		for (watt=W15; watt<=W100; ++watt) {
			// adding the cost of all the bulbs
			total_cost += bulb_matrix[brand][watt].stock *
				bulb_matrix[brand][watt].cost;
			// printing all bulbs where stock = 0
			if (bulb_matrix[brand][watt].stock == 0)
				printf(" (%s, %dW)", brands[brand], watts[watt]);
		}
	}
	putchar('\n');
	printf("Total cost of bulbs: %.2lf\n", total_cost);
	return 0;
}

