// This program encrypts plaintext with RSA
// Written for hp48-50g by Quinn Shultz

#include <hpgcc49.h>

char buf[128];

// Pads input with ASCII codons
// Instead of adding 100, I am deliminating with pipes ("|")
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
	}

	return(buf);
}

int main(void)
{
	char* ptr;

	ptr = sat_stack_pop_string_alloc();
	sat_stack_push_string(pad(ptr));
	return(0);
}
