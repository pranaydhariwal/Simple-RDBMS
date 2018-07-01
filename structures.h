#ifndef ParseFunc
#define ParseFunc

#define DOUBLE 1
#define INT 2
#define INTEGER 2
#define NAME 3
#define STRING 4
#define LESS_THAN 5
#define GREATER_THAN 6
#define EQUALS 7
#define GREATER_THAN_EQ 8
#define LESS_THAN_EQ 9
#define NOTEQUAL 10

typedef enum ntype {

	selec, insert, create, del, drop, comparision, operand, orlist, andlist

} nodeType;

struct node {

	nodeType type;
	int code;
	char *value;
	struct node* left;
	struct node* right;
};

struct Gtable {

	char *tablename;
	struct listAttr *attrlist;
	struct Gtable *next;
};

struct f_oper {
	int type;  //type such as FLOAT, INT, STRING: has values 1, 2, 3....
	char *actualOperand; // variable name
};

struct f_opr {
	int operatorUsed;   //operator used +, -, * using numeric values
	struct f_opr *left;
	struct f_oper *operand;
	struct f_opr *right;
};

struct tbl_list {
	char *tableName;
	char *aliasAs;
	struct tbl_list *next;
};

struct n_list {
	char *name;
	struct n_list *next;
};

struct Operand {
    int code;
    char *value;
};

struct cmp_opr {
    int code;
    struct Operand *left;
    struct Operand *right;
};

struct or_list {
    struct cmp_opr *left;
    struct or_list *rightOr;
};

struct and_list {

    struct or_list *left;
    struct and_list *rightAnd;
};

struct listAttr{
	char *name;
	int type;
	struct listAttr *next;
};

#endif
