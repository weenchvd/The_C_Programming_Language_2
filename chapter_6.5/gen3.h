#define MAXWORD 100
#define FREEWORD 1
#define DONTFREEWORD 0

enum {FALSE, TRUE};

struct tnode {
	struct tnode* pleft;
	struct tnode* pright;
	struct llword* pnextword;
	char* pword;
	int count;
};

struct llword {
	struct llword* pnextword;
	char* pword;
};