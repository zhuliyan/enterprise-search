/*
 * March 2007
 * Eirik A. Nygaard
 */

%#include "../suggest/suggest.h"

typedef string wordtype<>; /* a word */

typedef struct namenode *namelist; /* link in the listing */

/* A node in the directory listing */


struct namenode {
	wordtype name;
	int frequency;
	namelist next; /* next entry */
};

union numbest_res switch (int _errno) {
	case 0:
		namelist list; /* no error: return directory listing */
	default:
		void; /* error occurred: nothing else to return */
};


program SUGGEST {
	version SUGGESTVERS {
		numbest_res get_best_results(string) = 1;
	} = 1;
} = 0x200ff013;
