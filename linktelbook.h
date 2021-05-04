#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXNAME 20
#define MAXTEL 12

struct item {
	char name[MAXNAME];
	char telnum[MAXTEL];
	struct item* next;
};
int length;

struct item* inittelbook(void);
int create(struct item*);
int  get(struct item*);
char* s_gets(char*, int);
void print(struct item*);
int insert(struct item*, int);
void checkpointer(struct item*);
int checkname(struct item*);
int checktel(struct item*);
int revise(struct item*, int);
int delete(struct item*, int);
int getlength(void);
int reverse(struct item*);
int menu(struct item*);
void exitmenu(struct item*);