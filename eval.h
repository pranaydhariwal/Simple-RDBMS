

void eval() {

	char *fname; FILE *fp, *fp1, *fp2;

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
			return;

		case selec:

			if(tables->next) {

				// JOIN TWO TABLES
			}

			// Single Table 

			fp = fopen(tables->name, "r");

			fp = rec_eval(boolean, fp);

			return;
			// boolean

		case insert:
			merge(old_table, new_file);
		break;

		case del:
			return;
		
		case drop:
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
 
   ft = fopen("just.bak","w");
 
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
   ft = fopen("just.bak","r");
 
	while( ( ch = fgetc(ft) ) != EOF )
    	  fputc(ch,fs1);
}

FILE* rec_eval(struct node *p, FILE *fp) {

	FILE *fp1, *fp2, *fp3;
	rewind(fp); // check here later

	switch(p->type) {

		case andlist:

			fp1 = rec_eval(p->left, fp);
			rewind(fp1);

			fp2 = rec_eval(p->right, NULL, fp1);
			rewind(fp2);
			return fp2;
		case orlist:

			fp1 = eval_condition(p->left, fp);
			rewind(fp);rewind(fp1);
			fp2 = rec_andlist(p->right, fp);

			rewind(fp2);

			fp3 = concat(fp1, fp2);
			rewind(fp3);
			return fp3; // anything mishap
		case comparision:

			fp3 = eval_condition(p->code, p, fp);
			rewind(fp3);
			return fp3;
	}
}



FILE* eval_condition(int code, struct node* p, FILE *fp) {

	char *attr_name = p->left;int attr_no = 0;char buff[100];
	int t = STRING, val;float fval;char *tname = tables->tableName;
	struct Gtable *temp = head;struct listAttr *alist;
	char * line = NULL;
   size_t len = 0;
   ssize_t read;
   char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = (fileno+1); fileno++; fn[5] = '\0';

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
	else if(p->right->code == FLOAT) {

		t = FLOAT;
		fval = atof(p->right->value);
	}

	char c;
	int j=0, intvar;
	float floatvar;
	read = getline(&line, &len, fp);
	while ((read = getline(&line, &len, fp)) != -1) {
		for(i = 0; i < attr_no;) {
			if (line[j] == ',')
				i++;
			j++;
		}
		for (i = 0; line[j] != ','; i++) {
			buff[i] = line[j];
			j++;
		}
		buff[i] = '\0';
		if (t == FLOAT) 
			floatvar = atof(buff);
		else if (t == INT)
			intvar = atoi(buff);
		
		switch(p->code) {
		
			case EQUALS: 
				
				if(t == STRING) {

					if(strcmp(buff, p->right->value) == 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val == intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == FLOAT) {

					if(fval == floatvar)
						fprintf(fp1, "%s\n", line);
				}
			break;
			case LESS_THAN:

			break;
		}
	}

	rewind(fp1);
	return fp1;
}


void dash() {

	printf("------------------------------------------------------------------------------------\n");
}

// TO DO 


/// Gsymbo NULL init
