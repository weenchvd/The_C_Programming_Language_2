#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof (keytab[0]))

enum {FALSE, TRUE};

struct tnode {
	struct tnode* pleft;
	struct tnode* pright;
	struct numstr* pnumstr;
	char* pword;
};

struct numstr {
	struct numstr* pnextnumstr;
	int number;
};