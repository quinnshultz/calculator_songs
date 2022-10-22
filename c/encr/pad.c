// This program pads a character string with ASCII codons
// Written for hp48-50g by Quinn Shultz

#include <hpgcc49.h>

char buf[128];

// Pads input with ASCII codons
char* pad(char string[])
{
	char newChar[3];
	int messLen = strlen(string);

	int i;
	for (i = 0; i < messLen; i++)
	{
		sprintf(newChar, "%d", string[i]);
		int newInt = atoi(newChar);
		newInt += 100;
		sprintf(newChar, "%d", newInt);
		strcat(buf, newChar);

		// Leave an out
		if (keyb_isAnyKeyPressed())
			break;
	}

	return(buf);
}

int main(void)
{
	char* ptr;

	ptr = sat_stack_pop_string_alloc();

	sat_stack_push_string(pad(ptr));
	free(ptr);
	return(0);
}
