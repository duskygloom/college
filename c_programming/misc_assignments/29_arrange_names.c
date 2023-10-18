// arrange names based on first and second characters

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAMELEN 128

char *getstring(int maxlength);

int main()
{
	int n, i, j, k;
	printf("Number of names: ");
	scanf("%d", &n);
	getchar();
	char *name_array[n], *temp;
	putchar('\n');
	for (i=0; i<n; ++i) {
		printf("Name %d: ", i+1);
		temp = getstring(MAX_NAMELEN);
		for (j=0; j<i; ++j) {
			// checking if value is smaller
			if (temp[0] < name_array[j][0] || 
					(temp[0] == name_array[j][0] && 
					temp[1] < name_array[j][1])) {
				// shifting values
				for (k=i-1; k>=j; --k)
					name_array[k+1] = name_array[k];
				break;
			}
		}
		name_array[j] = temp;
	}
	// printing
	printf("\nSorted names:\n");
	for (i=0; i<n; ++i)
		printf("%s\n", name_array[i]);
	return 0;
}

char *getstring(int maxlength)
{
	char ch, *string = malloc(maxlength * sizeof(char));
	int length = 0;
	while ((ch=getchar()) != '\n' && length < maxlength) {
		*(string + length) = ch;
		++length;
	}
	*(string + length) = '\0';
	return string;
}

