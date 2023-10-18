#include <stdio.h>

typedef struct GenericType
{
	char type;
	union content {
		int integer;					// type = i
		float floating;					// type = f
		double doublefloating;			// type = d
		char character;					// type = c
	};
} GenericType;

int initType(GenericType *typeobj, char type);

int main()
{
	GenericType num;
	initType(&type, 'i');
	num.content.integer = 12;
	GenericType frac;
	initType(&frac, 'f');

	return 0;
}

int initType(GenericType *typeobj, char type)
{
	switch (type) {
		case 'i':
		case 'f':
		case 'd':
		case 'c':
			typeobj->type = type;
			break;
		default:
			printf("Type '%c' not recongnized.\n", type);
			break;
	}
}

