%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
    #include "structures.h"

	char filenumber = '0';
	int firstfile_flag = 1;

	struct listAttr *newattrs;
    nodeType statement_type;
	int d_attr;
	int d_func;
	char *new_table;
	char *new_file;
	char *old_table;
    struct f_opr *finalFunction;
	struct tbl_list *tables;
    struct Gtable *head = NULL;
	struct node *boolean;
	struct n_list *groupingAtts;
	struct n_list *attsToSelect;

    struct node* makeboolcomp(int code);
    struct node* makeliteral(int code, char* value);
    struct node* make_or(struct node *l, struct node *r);
    struct node* make_and(struct node *l, struct node *r);
    void addtables(char *name, struct listAttr *list);
    void eval();
    void merge(char *file1, char *file2);
    FILE* merge_removedup(FILE* fp1, FILE* fp2);
	FILE* rec_eval(struct node *p, FILE *fp);
	FILE* eval_condition(int code, struct node* p, FILE *fp);
	void finalprint_select();
%}

%union {
    struct or_list *myor_list;
	struct and_list *myand_list;
	struct n_list *myNames;
	struct listAttr *myAttrList;
	struct n_list *mysortattrs;
	char *actualChars;
	char whichOne;	
    struct f_oper *myOperand;
    struct f_opr *myOperator;
	struct tbl_list *myTables;
	struct cmp_opr *myComparison;
	struct Operand *myBoolOperand;
    struct node *nodeptr;
}

%token <actualChars> Name Float Int String
%token SELECT GROUP DISTINCT BY FROM WHERE SUM
%token AS AND OR CREATE TABLE HEAP INSERT INTO
%token SET OUTPUT DROP SORTED ON LE NE GE EXIT

%type <nodeptr> BoolComp
%type <nodeptr> Condition
%type <myTables> Tables
%type <nodeptr> Literal
%type <myNames> Atts
%type <myAttrList> NewAtts
%type <nodeptr> booleanConditions1
%type <nodeptr> booleanConditions
%type <myOperand> SimpleExp
%type <myOperator> CompoundExp
%type <whichOne> Op

%start SQLQueries

%%

SQLQueries : SQL                {}
           | SQL SQLQueries     {}
           ;

SQL: SELECT argsAndFunc FROM Tables WHERE booleanConditions ';'                 { tables = $4; boolean = $6; groupingAtts = NULL; statement_type = selec; eval();}

    | SELECT argsAndFunc FROM Tables WHERE booleanConditions GROUP BY Atts ';'  { tables = $4; boolean = $6; groupingAtts = $9; statement_type = selec; eval();}

    | CREATE TABLE Name '(' NewAtts ')' ';'                                     { new_table = $3; newattrs = $5; addtables($3, $5); statement_type = create; eval();}

    | INSERT String INTO Name ';'                                               { new_file = $2; old_table = $4; statement_type = insert; eval();}

    | DROP TABLE Name ';'                                                       { old_table = $3; statement_type = drop; eval();}

    | EXIT ';'																	{ exit(0); }
    ;

NewAtts: Name Name {$$ = (struct listAttr *) malloc (sizeof (struct listAttr));
                    $$->name = $1;
                    if(strcmp($2,"STRING") == 0) $$->type = 2;
                    else if(strcmp($2,"INTEGER") == 0) $$->type = 0;
                    else if(strcmp($2,"DOUBLE") == 0) $$->type = 1;
                    $$->next = NULL; }

        | Name Name ',' NewAtts     {$$ = (struct listAttr *) malloc (sizeof (struct listAttr));
                                    $$->name = $1;
                                    if(strcmp($2,"STRING") == 0) $$->type = 2;
                                    else if(strcmp($2,"INTEGER") == 0) $$->type = 0;
                                    else if(strcmp($2,"DOUBLE") == 0) $$->type = 1;
                                    $$->next = $4;}
        ;

argsAndFunc: Function ',' Atts      {attsToSelect = $3; d_attr = 0;}

        | Function                  {attsToSelect = NULL;}

        | Atts                      {d_attr = 0; finalFunction = NULL; attsToSelect = $1;}

        | DISTINCT Atts             {d_attr = 1; finalFunction = NULL; attsToSelect = $2;}
        ;

Function: SUM '(' CompoundExp ')'           {d_func = 0; finalFunction = $3;}

        | SUM DISTINCT '(' CompoundExp ')'  {d_func = 1; finalFunction = $4;}
        ;

Atts: Name                          {$$ = (struct n_list *)malloc(sizeof(struct n_list));
                                    $$->name = $1;
                                    $$->next = NULL;}

        | Atts ',' Name             {$$ = (struct n_list *)malloc(sizeof(struct n_list));
                                    $$->name = $3;
                                    $$->next = $1;}
        ;

Tables: Name AS Name                {$$ = (struct tbl_list *) malloc (sizeof (struct tbl_list));
                                    $$->tableName = $1;
                                    $$->aliasAs = $3;
                                    $$->next = NULL;}

        | Tables ',' Name AS Name   {$$ = (struct tbl_list *) malloc (sizeof (struct tbl_list));
                                    $$->tableName = $3;
                                    $$->aliasAs = $5;
                                    $$->next = $1;}
        ;

CompoundExp: SimpleExp Op CompoundExp {$$ = (struct f_opr *) malloc (sizeof (struct f_opr));
                                      $$->left = (struct f_opr *) malloc (sizeof (struct f_opr));
                                      $$->left->left = NULL;
                                      $$->left->operand = $1;
                                      $$->left->right = NULL;
                                      $$->operand = NULL;
                                      $$->right = $3;
                                      $$->operatorUsed = $2;}

        | '(' CompoundExp ')' Op CompoundExp {$$ = (struct f_opr *) malloc (sizeof (struct f_opr));
                                             $$->left = $2;
                                             $$->operand = NULL;
                                             $$->right = $5;
                                             $$->operatorUsed = $4;}

        | '(' CompoundExp ')'        {$$ = $2;}

        | SimpleExp                  {$$ = (struct f_opr *) malloc (sizeof (struct f_opr));
                                     $$->left = NULL;
                                     $$->operand = $1;
                                     $$->right = NULL;}

        | '-' CompoundExp            {$$ = (struct f_opr *) malloc (sizeof (struct f_opr));
                                     $$->left = $2;
                                     $$->operand = NULL;
                                     $$->right = NULL;
                                     $$->operatorUsed = '-';}
        ;

Op: '-'                              {$$ = '-';}
    | '+'                            {$$ = '+';}
    | '*'                            {$$ = '*';}
    | '/'                            {$$ = '/';}
    ;

booleanConditions: '(' booleanConditions1 ')' AND booleanConditions  {$$ = make_and($2, $5);}

   		| booleanConditions1 AND booleanConditions  {$$ = make_and($1, $3);}
        | '(' booleanConditions1 ')'                                 {$$ = make_and($2, NULL);  }
        |  booleanConditions1  		                             {$$ = make_and($1, NULL);  }
        ;

booleanConditions1: Condition OR booleanConditions1                {$$ = make_or($1, $3); }

        | Condition                                                  {$$ = make_or($1, NULL); }
        ;

Condition: Literal BoolComp Literal  {$$ = $2; $$->left = $1; $$->right = $3;}
        ;

BoolComp: '<'                        {$$ = makeboolcomp(LESS_THAN); }
        | '>'                        {$$ = makeboolcomp(GREATER_THAN); }
        | '='                        {$$ = makeboolcomp(EQUALS); }
        | NE                         {$$ = makeboolcomp(NOTEQUAL); }
        | GE                      	 {$$ = makeboolcomp(GREATER_THAN_EQ); }
        | LE                       	 {$$ = makeboolcomp(LESS_THAN_EQ); }
        ;

Literal : String                     {$$ = makeliteral(STRING, $1); }

        | Float                      {$$ = makeliteral(DOUBLE, $1); }

        | Int                        {$$ = makeliteral(INT, $1); }

        | Name                       {$$ = makeliteral(NAME, $1); }
        ;

SimpleExp: Float                     {$$ = (struct f_oper *) malloc (sizeof (struct f_oper));
                                     $$->type = DOUBLE;
                                     $$->actualOperand = $1;}

        | Int                        {$$ = (struct f_oper *) malloc (sizeof (struct f_oper));
                                     $$->type = INT;
                                     $$->actualOperand = $1;}

        | Name                       {$$ = (struct f_oper *) malloc (sizeof (struct f_oper));
                                     $$->type = NAME;
                                     $$->actualOperand = $1;}
        ;

%%

struct node* makeboolcomp(int code) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->code = code;
    p->type = comparision;
    p->left = p->right = NULL;
    p->value =  NULL;

    return p;

}


struct node* makeliteral(int code, char* value) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->type = operand;
    p->code = code;
    p->value = value;

    p->left = p->right =  NULL;

    return p;
}

struct node* make_or(struct node *l, struct node *r) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->type = orlist;
    p->code = 0;
    p->value = NULL;
    p->left = l;
    p->right = r;

    return p;
}

struct node* make_and(struct node *l, struct node *r) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->type = andlist;
    p->code = 0;
    p->value = NULL;
    p->left = l;
    p->right = r;

    return p;
}

void addtables(char *name, struct listAttr *list) {

    struct Gtable *p = (struct Gtable *)malloc(sizeof(struct Gtable));
    p->tablename = name;
    p->attrlist = list;
    p->next = NULL;

    if(head == NULL) {
        head = p;
        return;
    }

    p->next = head;
    head = p;
}

int main(int argc, char *argv) {


    head = NULL;

    printf("-------------------------------------------------------------------\n");
    printf("Welcome to SQL.\n");
    printf("-------------------------------------------------------------------\n");
    printf("Enter exit; to EXIT from SQL\n");
    yyparse();

    return 0;
}

// evaluation


void eval() {

	struct n_list *list = attsToSelect;
	struct tbl_list *tlist = tables;

    char *fname; FILE *fp, *fp1, *fp2;
    char *newfile1;
    int i, j=0, status;
    char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = filenumber; fn[5] = '\0';

    switch(statement_type) {

        case create:
            fname = new_table;
            fp = fopen(fname, "w");

            struct listAttr *temp = newattrs;

            while(temp) {

                fprintf(fp, "|%s\t\t", temp->name);
                temp = temp->next;
            }

            
            fprintf(fp, "\n");
            fclose(fp);
            printf("Table %s is created successfully\n",new_table);
            return;

        case selec:

			firstfile_flag = 1;

            if(tables->next) {

            	printf("SELECT Statement: Attributes: [ ");

            	while(list) {

            		printf("%s, \n", list->name);
            		list = list->next;
            	}
            	printf(" ]\n");

            	printf("JOIN Tables: [ ");

            	while(tlist) {

            		printf("%s, \n", tables->tableName);
            		tlist = tlist->next;
            	}
				printf(" ]\n");

				printf("Conditions: \n");

				           	
                // JOIN TWO TABLES
            }
            // Single Table 

            fp = fopen(tables->tableName, "r");
			fp = rec_eval(boolean, fp);
			fclose(fp);

			fn[4] = filenumber;
			
			finalprint_select();
			
			for (i=1;i<=filenumber;i++) {
				fn[4] = i;
				remove(fn);
			}

			filenumber = 0;

            return;
            // boolean

        case insert:
            newfile1 = (char *)malloc(sizeof(new_file)-2);
            for(i=1; i<strlen(new_file)-1;i++) {
                newfile1[j] = new_file[i];
                j++;
            }
            merge(old_table, newfile1);

        break;

        case drop:
            status = remove(old_table);
          
            if( status == 0 )
               printf("%s Table deleted successfully.\n",old_table);
            else
            {
               printf("Unable to delete the Table\n");
               perror("Error");
            }
        return;


    }

}


void merge(char *file1, char *file2) {

	// remove single quote from file2

	FILE *fs1, *fs2, *ft; char ch;

	fs1 = fopen(file1,"r");
    fs2 = fopen(file2,"r");
 
   if( fs1 == NULL || fs2 == NULL ) {
      perror("Error ");
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   ft = fopen("just","w");
 
   if( ft == NULL ) {
      perror("Error opening File");
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 	
   while( ( ch = fgetc(fs1) ) != EOF )
      fputc(ch,ft);
    while( ( ch = fgetc(fs2) ) != EOF )
      fputc(ch,ft);
	

  fclose(fs1);
	fclose(fs2);
   fclose(ft);

   fs1 = fopen(file1,"w");
   ft = fopen("just","r");
 
	while( ( ch = fgetc(ft) ) != EOF )
    	  fputc(ch,fs1);

    fclose(fs1);fclose(ft);
}

FILE* rec_eval(struct node *p, FILE *fp) {

	FILE *fp1, *fp2, *fp3;
	rewind(fp); // check here later
	 char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = filenumber; fn[5] = '\0';

	switch(p->type) {

		case andlist:

			fp1 = rec_eval(p->left, fp);
			rewind(fp1);

			fclose(fp1);
			fn[4] = filenumber;
			fp1 = fopen(fn, "r");

			if(!p->right)
				return fp1;

			fp2 = rec_eval(p->right, fp1);
			rewind(fp2);
			return fp2;
		case orlist:

			fp1 = rec_eval(p->left, fp);
			rewind(fp);rewind(fp1);

			fclose(fp1);
			fn[4] = filenumber;
			fp1 = fopen(fn, "r");

			if(!p->right)
				return fp1;

			fp2 = rec_eval(p->right, fp);

			rewind(fp2);

			fclose(fp2);
			fn[4] = filenumber;
			fp2 = fopen(fn, "r");

			fp3 = merge_removedup(fp1, fp2);
			//rewind(fp3);
			return fp3; // anything mishap
		case comparision:

			fp3 = eval_condition(p->code, p, fp);
			rewind(fp3);
			return fp3;
	}
}

FILE* eval_condition(int code, struct node* p, FILE *fp) {

	char *attr_name = p->left->value;int attr_no = 0;char buff[100], valuebuff[100]; 
	char c;
	int i, j=0, intvar;
	float floatvar;
	int t = STRING, val;float fval;char *tname = tables->tableName;
	struct Gtable *temp = head;struct listAttr *alist;
	char * line = NULL;
   size_t len = 0;
   ssize_t read;
   char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = (filenumber+1); filenumber++; fn[5] = '\0';

   FILE *fp1 = fopen(fn, "w");

	while(temp) {

		if(strcmp(tname, temp->tablename))
			temp = temp->next;
		else
			break;
	}

	if(temp == NULL) {
		printf("%s table not present\n", tname);
		exit(1);
	}
	else {

		alist = temp->attrlist;

		while(alist) {

			if(strcmp(attr_name, alist->name)) {
				alist = alist->next;
				attr_no++;
			}
			else {
				break;
			}
		}
	}

	// obtained attr-no .

	if(p->right->code == INT) {

		t = INT;
		val = atoi(p->right->value);
	}
	else if(p->right->code == DOUBLE) {

		t = DOUBLE;
		fval = atof(p->right->value);
	}
	else if(p->right->code == STRING) {

		t = STRING;
		// here
		for(i = 1, j = 0; i < strlen(p->right->value)-1; i++, j++)
			valuebuff[j] = p->right->value[i];
		valuebuff[j] = '\0';

	}

	if(firstfile_flag) { 

		firstfile_flag = 0;
		read = getline(&line, &len, fp);
	}


	while ((read = getline(&line, &len, fp)) != -1) {

		j = 0;
		for(i = 0; i < attr_no;) {
			if (line[j] == ',')
				i++;
			j++;
		}

		for (i = 0; line[j] != ',' && line[j];) {
			if (line[j] != '\n' && line[j] !=' ') {
				buff[i] = line[j];
				i++;
			}
			j++;
		}
		buff[i] = '\0';

		if (t == DOUBLE) 
			floatvar = atof(buff);
		else if (t == INT)
			intvar = atoi(buff);
		
		switch(p->code) {
		
			case EQUALS: 
				
				if(t == STRING) {

					if(strcmp(buff, valuebuff) == 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val == intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval == floatvar)
						fprintf(fp1, "%s\n", line);
				}
			break;
			case LESS_THAN:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) < 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val > intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval > floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case GREATER_THAN:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) > 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val < intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval < floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case NOTEQUAL:

				if(t == STRING) {
					if(strcmp(buff, valuebuff) != 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val != intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval != floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case GREATER_THAN_EQ:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) >= 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val <= intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval <= floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case LESS_THAN_EQ:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) <= 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val >= intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval >= floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
		}
	}

	rewind(fp1);
	return fp1;
}

FILE* merge_removedup(FILE* fp1, FILE* fp2) {

	FILE *fp3;
	char *line1 = NULL, *line2 = NULL;
	size_t len1 = 0, len2 = 0;
	ssize_t read1, read2; int putflag = 1;
	char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = (filenumber+1); filenumber++; fn[5] = '\0';

	rewind(fp1); rewind(fp2);

	fp3 = fopen(fn, "w");


	while ((read1 = getline(&line1, &len1, fp1)) != -1) {

		while ((read2 = getline(&line2, &len2, fp2)) != -1) {

			if(strcmp(line1, line2) == 0) {

				putflag = 0;
				break;
			}
		}

		if(putflag)
			fprintf(fp3, "%s\n", line1);	
	}

	rewind(fp2);

	while ((read2 = getline(&line2, &len2, fp2)) != -1) {

		fprintf(fp3, "%s\n", line2);
	}

	rewind(fp3);

	return fp3;
}

int compare(const void* a, const void *b) {

	return ( *(int*)a - *(int*)b);
}

void finalprint_select() {

	int att_arr[11] = {0}, i, j; int len;struct listAttr *list, *list1;struct Gtable *temp = head;struct n_list *temp2 = attsToSelect;

	char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = filenumber; fn[5] = '\0';
	FILE *fp = fopen(fn, "r");

	while(temp) {

		if(strcmp(tables->tableName, temp->tablename))
			temp = temp->next;
		else 
			break;
	}

	if(temp == NULL) {

		printf("Table not Found ..Error\n");
		exit(1);
	}

	list = temp->attrlist;

	i = 0;

	while(attsToSelect) {
		list1 = list;
		while(list1) {

			if(strcmp(list1->name, attsToSelect->name)) {
				
				list1 = list1->next;
				att_arr[i]++;
			}
			else
				break;
		}
		i++;
		attsToSelect = attsToSelect->next;
	}

	len = i;

	qsort(att_arr, len, sizeof(int), compare);

	printf("-----------------------------------------------------------------------------\n");

	printf("Select Statement successfully executed. Table: %s\n", tables->tableName);

	while(temp2) {

		printf("|%s ||  ", temp2->name);
		temp2 = temp2->next;
	}
	printf("\n");

	int k = 0, l;
	char *line = NULL;
	char buff[100];
    size_t leng = 0;
    ssize_t read;
	// printed the initial line stating the name of the attributes
	while ((read = getline(&line, &leng, fp)) != -1) {
		if (strcmp(line, "\n") == 0)
			continue;
		i = 0; j = 0;
		k=0;
		while(k<=len-1) {
			for(; i < att_arr[k];) {
				if (line[j] == ',' && line[j])
					i++;
				j++;
			}

			for (l = 0; line[j] != ',' && line[j]; ) {
				if (line[j] != '\n' && line[j] !=' ') {
					buff[l] = line[j];
					l++;	
				}
				j++;
			}
			buff[l] = '\0';
			printf("%s ||  ", buff);
			k++;
		}
		printf("\n");
	}
}