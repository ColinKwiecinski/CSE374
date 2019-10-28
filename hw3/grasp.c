#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[argc+1] {
	int iflag = 0;
	int cflag = 0;
	char *cvalue = NULL;
	int index;
	int c;
	opterr = 2;

	// from gnu.org getopt example
	while ((c = getopt(argc, argv, "ic:")) != -1) {
		switch (c) {
		case 'i':
			iflag = 1;s = 1;
			break;
		case 'c':
			bflag = 1;
			break;
		case '?':
			if (optopt == 'c')
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint (optopt)
				fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			else 
				fprintf (stderr, Unknown option character `\\x%x'.\n", optopt);
			return 1;
		default:
			abort();
		}

// make sure to terminate with exit success
}
