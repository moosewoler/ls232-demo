/*******************************************************************************
 * Filename     : hello.c
 * Description  :
 *  This is a simple program that demonstrate the linkage between PMON2000 and a 
 *  loaded program.
 ******************************************************************************/

typedef long long off_t;

struct callvectors {
	int     (*open) (char *, int, int);
	int     (*close) (int);
	int     (*read) (int, void *, int);
	int     (*write) (int, void *, int);
	off_t   (*lseek) (int, off_t, int);
	int     (*printf) (const char *, ...);
	void    (*cacheflush) (void);
	char    *(*gets) (char *);
};

struct callvectors *callvec;

#define	printf (*callvec->printf)
#define	gets   (*callvec->gets)

void __gccmain(void);
void __gccmain(void){}
int
main(int argc, char **argv, char **env, struct callvectors *cv)
{
	char str[256];
	char **ev;
	int i;
	unsigned stat;

	callvec = cv;

	printf("\n\nHello! This is the 'hello' program!\n\n");
	printf("It was invoked with:\n");
	for (i = 0; i < argc; i++) {
		printf("Arg %2d: %s\n", i, argv[i]);
	}
	printf("\nEnvironment setup = \n");
	ev = env;
	while(*ev) {
		printf("\t%s\n", *ev);
		ev++;
	}
	printf("\n\n");

	printf("Type '<ctl>C' to stop the program\n");
	gets(str);
	printf("Ehhh.. you typed '%s'\n", str);
	return(0);
}
