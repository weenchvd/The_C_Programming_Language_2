#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof (keytab[0]))
#define DEFAULTQTY 6

enum {FALSE, TRUE};

struct tnode {
	struct tnode* left;
	struct tnode* right;
	char* word;
	int ismatch;
};