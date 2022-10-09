// This program decrypts ciphertext with RSA
// Written for hp48-50g by Quinn Shultz

#include <hpgcc49.h>

char buf[128];

char* depad(char string[])
{
	char newChar[4];
	int messLen = strlen(string);

	int i;
	for (i = 0; i < messLen; i=i+3)
	{
		sprintf(newChar, "%c%c%c", string[i], string[i+1], string[i+2]);
		int newInt = atoi(newChar);
		newInt -= 100;
		char c = newInt;
		char c2[2];
		sprintf(c2, "%c", c);
		strcat(buf, c2);
	}

	return(buf);
}

int main(void)
{
	char* ptr;

	ptr = sat_stack_pop_string_alloc();

	sat_stack_push_string(depad(ptr));
	free(ptr);
	return(0);
}
