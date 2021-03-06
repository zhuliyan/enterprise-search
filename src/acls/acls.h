
/**
 *	CHANGELOG:	25.01.2008	Magnus	La til userToSubname_deletecol() for � slette collections.
 */

#ifndef _ACLS__H_
#define _ACLS__H_

#ifdef BLACK_BOX

#include <inttypes.h>

#include <db.h>

struct userToSubnameDbFormat {
        DB *dbp;
};

// mode : fil retighet, r for read, w for write
int userToSubname_open(struct userToSubnameDbFormat *userToSubnameDb, char mode);

char **userToSubname_getsubnamesList(struct userToSubnameDbFormat *db, char group[], int *num_colls);
void userToSubname_freesubnamesList(char ** subnames, int num_subnames);
int userToSubname_getsubnamesAsString(struct userToSubnameDbFormat *userToSubnameDb,char username[],char subnames[],int subnameslen);
int userToSubname_getsubnamesAsSaa(struct userToSubnameDbFormat *userToSubnameDb,char username[],char ***subnames, int *nr);
void userToSubname_close (struct userToSubnameDbFormat *userToSubnameDb);
int userToSubname_deletecol(struct userToSubnameDbFormat *userToSubnameDb,char subname[]);
void aclElementNormalize (char acl[]);
void userToSubname_add (struct userToSubnameDbFormat *userToSubnameDb,char username[], char subname[]);

#endif

#endif // _ACLS__H_
