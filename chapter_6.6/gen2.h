#define MAXWORD 100
#define HASHSIZE 101
#define MAXNAME 100
#define MAXDEFINITION 200
#define ERROR -1

enum getndnl { NLNOTALLOWED, NLALLOWED };		/* symbol of new line allowed or not allowed? */
enum getndtype { NAME, DEFN };
enum getwordtype { SPACE = 512, PREPROCESSOR, CHARACTERCONST, STRINGCONST, COMMENT, SYMBOL, WORD };
enum getcommenttype { OLCOMMENT = 1, MLCOMMENT };	/* one line comment or multi line comment*/
enum bool { FALSE, TRUE };

struct nlist {					/* table entry: */
	struct nlist* pnext;		/* next entry in chain */
	char* pname;				/* defined name */
	char* pdefn;				/* replacement text */
};



enum errcode { ERRMALLOC, ERRREALLOC, ERRSTRCPY, ERRSTRCAT, ERRNULLPNP,
	ERRPPNOINSTALL, ERRPPNOINPUT, ERRPPUNALLOWSYM, ERRPPINPUTGLIM, ERRPPNLFOUND,
	
	CODELENGTH
};