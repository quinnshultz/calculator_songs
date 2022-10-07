// This program encrypts plaintext with RSA
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
	}

	return(buf);
}

// Encrypts a string with encryption exponent and encryption modulus.
char* rsaencrypt(char string[], long encrexp, long encrmod)
{
	char newChar[128];

	int newInt = atoi(pad(string));
	newInt = newInt ^ encrexp % encrmod;	// Do the encryption!
	sprintf(newChar, "%d", newInt);
	sprintf(buf, "%s", newChar);
	
	return(buf);
}

int main(void)
{
	char* ptr;
	long encrexp;
	long encrmod;

	ptr = sat_stack_pop_string_alloc();
	encrexp = sat_pop_real();
	encrmod = sat_pop_real();

	sat_stack_push_string(rsaencrypt(ptr, encrexp, encrmod));
	free(ptr);
	return(0);
}
