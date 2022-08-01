
// The below program runs fine because NDEBUG is defined
# define NDEBUG // if this is omitted then the progam will abort at assert();
#include <stdio.h>
#include <assert.h>

int main()
{
	int x = 7;

	/* Some big code in between and let's say x
	is accidentally changed to 9 */
	x = 9;

	// Programmer assumes x to be 7 in rest of the code
	assert(x==7);

	/* Rest of the code */
    printf("the value of x = %d\n", x);
    printf("\n\n");
	return 0;// retuns 0 if there are no errors, else returns a 1 if error exsits.
}
