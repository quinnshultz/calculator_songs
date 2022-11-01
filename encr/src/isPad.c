// This program checks to see if a character string is padded with ASCII codons
// Written for hp48-50g by Quinn Shultz

#include <hpgcc49.h>

char buf[128];

// Return 1 if the input is padded, 0 otherwise
int isPadded(char string[])
{
	char newChar[4];
	int messLen = strlen(string);

	int i;
	for (i = 0; i < messLen; i=i+3)
	{
		sprintf(newChar, "%c%c%c", string[i], string[i+1], string[i+2]);
		int newInt = atoi(newChar);
		if (newInt < 0)
			return 0;
		if (newInt > 1)
			return 0;

		// Leave an out
		if (keyb_isAnyKeyPressed())
			break;
	}
	return 1;
}

int main(void)
{
	char* ptr;

	ptr = sat_stack_pop_string_alloc();

	sat_push_real(isPadded(ptr));
	free(ptr);
	return(0);
}
