#define MAXLENGTH 100
#define HASHSIZE 101

struct nlist {					/* table entry: */
	struct nlist* pnext;		/* next entry in chain */
	char* pname;				/* defined name */
	char* pdefn;				/* replacement text */
};