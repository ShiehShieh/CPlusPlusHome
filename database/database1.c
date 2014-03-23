#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>
//various of database

int n,rownumber=-1;
char filename[128];
FILE *filepointer=NULL,*newfilepointer=NULL,*fp=NULL;
int count=0;
char **table_nametotal=NULL;

struct Database
{
	char *column_name;
	int datatype;
	int datalength;
	int null;
}*database;

struct Datafloat
{
	float datafloat;
	struct Datafloat *nextf;
	struct Datachar *nextc;
	struct Datafloat *nextcolumnf;
}**datafloat,**newfloat1,**newfloat2,***headfloat=NULL;

struct Datachar
{
	char *datachar;
	struct Datafloat *nextf;
	struct Datachar *nextc;
	struct Datachar *nextcolumnc;
}**datachar,**newchar1,**newchar2,***headchar=NULL;

int newstrcmp(char * a,char * b)
{
	int i=0;
	while(a[i]==b[i]&&a[i]!='\0'&&b[i]!='\0')
	{
		i++;
	}
	if(a[i]=='\0'||b[i]=='\0')
	{
		return 0;
	}
	else if(a[i]>b[i])
	{
		return 1;
	}
	else if(a[i]<b[i])
	{
		return -1;
	}
}

void newstrlwr(char * a)
{
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]<='Z'&&a[i]>='A')
		{
			a[i]=a[i]+32;
		}
		i++;
	}
}

char *newstrcpy(char *a,char *b)
{
	int i=0;
	char *c=a;
	while(*(b+i)!='\0')
	{
 		*(c+i)=*(b+i);
		i++;
	}
	*(c+i)='\0';
	return c;
}

void newstrcat(char *a,char *b)
{
	int i=0,j=0;
	while(a[i]!='\0')
	{
		i++;
	}
	while(b[j]!='\0')
	{
		a[i]=b[j];
		i++;
		j++;
	}
}

int newstrlen(char *a)
{
	int i=0,l=0;;
	for(;a[i]!='\0';i++)
	{
		l++;
	}
	return l;
}

int printftable(struct Datafloat **headfloat,FILE *newfilepointer)
{
	int row=0,i=0;
	struct Datafloat *p1=NULL;
	struct Datachar *p2=NULL;
	for(row=0;row<(rownumber+1);row++)
	{
		p1=headfloat[row];
		for(i=0;i<count;i++)
		{
			if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
			{
				fprintf(newfilepointer,"%f,",p1->datafloat);
				p1=p1->nextf;
			}
			else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
			{
				fprintf(newfilepointer,"%f,",p1->datafloat);
				p2=p1->nextc;
			}
			else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
			{
				fprintf(newfilepointer,"%s,",p2->datachar);
				p1=p2->nextf;
			}
			else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
			{
				fprintf(newfilepointer,"%s\n",p2->datachar);
				p2=p2->nextc;
			}
		}
		if(database[count-1].datatype==0)
		{
			fprintf(newfilepointer,"%f\n",p1->datafloat);
		}
		else
		{
			fprintf(newfilepointer,"%s\n",p2->datachar);
		}
	}
}

int printctable(struct Datachar **headchar,FILE *newfilepointer)
{
	int row=0,i=0;
	struct Datafloat *p1=NULL;
	struct Datachar *p2=NULL;
	for(row=0;row<(rownumber+1);rownumber++)
	{
		p2=headchar[row];
		for(i=0;i<count;i++)
		{
			if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
			{
				fprintf(newfilepointer,"%f,",p1->datafloat);
				p1=p1->nextf;
			}
			else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
			{
				fprintf(newfilepointer,"%f,",p1->datafloat);
				p2=p1->nextc;
			}
			else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
			{
				fprintf(newfilepointer,"%s,",p2->datachar);
				p1=p2->nextf;
			}
			else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
			{
				fprintf(newfilepointer,"%s\n",p2->datachar);
				p2=p2->nextc;
			}
		}
		if(database[count-1].datatype==0)
		{
			fprintf(newfilepointer,"%f\n",p1->datafloat);
		}
		else
		{
			fprintf(newfilepointer,"%s\n",p2->datachar);
		}
	}
}

int realcreat()
{
	int i=0,j=0;
	FILE *filepointer;
	char *word,chara,Not[4]="not",Float[6]="float",Char[5]="char";
	word=(char *)malloc(sizeof(char)*100);
	table_nametotal[n]=(char *)malloc(sizeof(char)*129);
	if(table_nametotal[n]==NULL)
	{
		printf("error0\n");
		return 0;
	}
	fopen_s(&filepointer,"D:\\vs2012\\file for C\\creat.txt","r");
	if(filepointer==NULL)
	{
		printf("error1\n");
		return 1;
	}
	chara=fgetc(filepointer);
	while(!feof(filepointer))
	{
		if(chara==';')
		{
			count++;
		}
		chara=fgetc(filepointer);
	}
	datachar=(struct Datachar **)malloc(sizeof(struct Datachar *)*count);
	if(datachar==NULL)
	{
		printf("error2\n");
		return 2;
	}
	datafloat=(struct Datafloat **)malloc(sizeof(struct Datafloat *)*count);
	if(datafloat==NULL)
	{
		printf("error3\n");
		return 3;
	}
	rewind(filepointer);
	chara=fgetc(filepointer);
	while(chara!=' ')
	{
		chara=fgetc(filepointer);
	}
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')
	{
		chara=fgetc(filepointer);
	}
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' '&&chara!='\n')
	{
		table_nametotal[n][i]=chara;
		chara=fgetc(filepointer);
		i++;
	}
	table_nametotal[n][i]='\0';
	i=0;
	for(i=0;i<count;i++)
	{
		datafloat[i]=(struct Datafloat *)malloc(sizeof(struct Datafloat));
		if(datafloat[i]==NULL)
		{
			printf("error\n");
			exit(3);
		}
		datafloat[i]->nextf=NULL;
		datafloat[i]->nextc=NULL;
		datachar[i]=(struct Datachar *)malloc(sizeof(struct Datachar));
		if(datachar[i]==NULL)
		{
			printf("error\n");
			exit(4);
		}
		datachar[i]->nextc=NULL;
		datachar[i]->nextf=NULL;
	}	
	database=(struct Database *)malloc(sizeof(struct Database)*count);
	if(database==NULL)
	{
		printf("error\n");
		exit(5);
	}
	while(chara!='(')chara=fgetc(filepointer);
	chara=fgetc(filepointer);
	for(i=0,j=0;i<count;i++)
	{
		database[i].column_name=(char *)malloc(sizeof(char)*100);
		if(database[i].column_name==NULL)
		{
			printf("error\n");
			exit(6);
		}
		while(chara==' '||chara=='\n')chara=fgetc(filepointer);
		while(chara!=' ')
		{
			database[i].column_name[j]=chara;
			chara=fgetc(filepointer);
			j++;
		}
		database[i].column_name[j]='\0';
		j=0;
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!='('&&chara!=' ')
		{
			word[j]=chara;
			chara=fgetc(filepointer);
			j++;
		}
		word[j]='\0';
		j=0;
		newstrlwr(word);
		if(newstrcmp(word,Float)==0)
		{
			database[i].datatype=0;
		}
		else if(newstrcmp(word,Float)!=0)
		{
			database[i].datatype=1;
		}
		while(chara=='('||chara==' ')chara=fgetc(filepointer);
		while(chara!=')'&&chara!=' ')
		{
			word[j]=chara;
			chara=fgetc(filepointer);
			j++;
		}
		word[j]='\0';
		j=0;
		if(database[i].datatype==0)
		{
			database[i].datalength=4;
		}
		else
		{
			database[i].datalength=atoi(word);
		}
		while(chara==' '||chara==')')chara=fgetc(filepointer);
		if(chara!=';')
		{
			j=0;
			while(chara!=' '&&chara!='\n'&&chara!=';')
			{
				word[j]=chara;
				chara=fgetc(filepointer);
				j++;
			}
			word[j]='\0';
			newstrlwr(word);
			if(newstrcmp(word,Not)==0)
			{
				database[i].null=0;
			}
			else
			{
				database[i].null=1;
			}
		}
		else
		{
			database[i].null=1;
		}
		while(chara!='\n')chara=fgetc(filepointer);
		j=0;
	}
	fclose(filepointer);
	n++;
	printf("-----Creat %s completed.-----\n",table_nametotal[n]);
	free(word);
	word=NULL;
	return 7;
}

int realinput(char *intable_name,FILE *filepointer)
{
	clock_t start ,end;
	int i=0,j=0,k=0,n=0,link=0;
	char *word,*midword,chara,*table_name=NULL;
	double time;
	start=clock();
	newfloat1=(struct Datafloat **)malloc(sizeof(struct Datafloat *)*count);
	if(newfloat1==NULL)
	{
		printf("error0\n");
		return 0;
	}
	newfloat2=(struct Datafloat **)malloc(sizeof(struct Datafloat *)*count);
	if(newfloat2==NULL)
	{
		printf("error1\n");
		return 1;
	}
	newchar1=(struct Datachar **)malloc(sizeof(struct Datachar *)*count);
	if(newchar1==NULL)
	{
		printf("error2\n");
		return 2;
	}
	newchar2=(struct Datachar **)malloc(sizeof(struct Datachar *)*count);
	if(newchar2==NULL)
	{
		printf("error3\n");
		return 3;
	}
	word=(char *)malloc(sizeof(char)*100);
	if(word==NULL)
	{
		printf("error4\n");
		return 4;
	}
	midword=(char *)malloc(sizeof(char)*100);
	if(midword==NULL)
	{
		printf("error5\n");
		return 5;
	}
	if(filepointer==NULL)
	{
		printf("error6\n");
		return 6;
	}
	if(newstrcmp(intable_name,table_nametotal[n])!=0)
	{
		printf("error7\n");
		return 7;
	}
	table_name=(char *)malloc(sizeof(char)*129);
	if(table_name==NULL)
	{
		printf("error8\n");
		return 8;
	}
	for(i=0;i<10;i++)
	{
		if(newstrcmp(intable_name,table_nametotal[i])==0)
		{
			n=i;
		}
	}
	for(i=0;i<count;i++)
	{
		if(database[i].datatype==0)
		{
			newfloat1[i]=datafloat[i];
		}
		else if(database[i].datatype==1)
		{
			newchar1[i]=datachar[i];
		}
	}
	chara=fgetc(filepointer);
	j=0;
	while(chara!=' '&&chara!='\n'&&chara!=EOF)
	{
		rownumber++;
		fseek(filepointer,-1L,1);
		fgets(word,129,filepointer);
		chara=fgetc(filepointer);
	}
	headchar[n]=(struct Datachar **)malloc(sizeof(struct Datachar *)*(rownumber+1));
	headfloat[n]=(struct Datafloat **)malloc(sizeof(struct Datafloat *)*(rownumber+1));
	for(i=0;i<count;i++)
	{
		if(database[i].datatype==0)
		{
			newfloat1[i]->nextcolumnf=(struct Datafloat *)malloc(sizeof(struct Datafloat));
			newfloat1[i]=newfloat1[i]->nextcolumnf;
		}
		else
		{
			newchar1[i]->nextcolumnc=(struct Datachar *)malloc(sizeof(struct Datachar));
			newchar1[i]=newchar1[i]->nextcolumnc;
		}
	}
	rewind(filepointer);
	rownumber=-1;
	chara=fgetc(filepointer);
	while(chara!=' '&&chara!='\n'&&chara!=EOF)
	{
		rownumber++;
		fseek(filepointer,-1L,1);
		fgets(word,129,filepointer);
		for(i=0;i<count;i++)
		{
			for(k=0;word[j]!='\0'&&word[j]!=',';k++,j++)
			{
				midword[k]=word[j];
			}
			j++;
			midword[k]='\0';
			if(database[i].datatype==0)
			{
				if(newfloat1[i]->nextcolumnf==NULL)
				{
					printf("error8\n");
					return 8;
				}
				newfloat1[i]->nextf=NULL;
				newfloat1[i]->nextc=NULL;
				newfloat1[i]->nextcolumnf=(struct Datafloat *)malloc(sizeof(struct Datafloat));
				(newfloat1[i]->datafloat)=(atof(midword));
			}
			else if(database[i].datatype!=0)
			{
				newchar1[i]->nextcolumnc=(struct Datachar *)malloc(sizeof(struct Datachar));
				if(newchar1[i]->nextcolumnc==NULL)
				{
					printf("error9\n");
					return 9;
				}
				newchar1[i]=newchar1[i]->nextcolumnc;
				newchar1[i]->nextc=NULL;
				newchar1[i]->nextf=NULL;
				newchar1[i]->nextcolumnc=(struct Datachar *)malloc(sizeof(struct Datachar));
				newchar1[i]->datachar=(char *)malloc(sizeof(char)*129);
				newstrcpy(newchar1[i]->datachar,midword);
			}
		}
		j=0;
		chara=fgetc(filepointer);
		for(link=0;link<count;link++)
		{
			if(database[link].datatype==0&&database[link+1].datatype==0&&link!=count-1)
			{
				(newfloat1[link]->nextf=newfloat1[link+1]);
			}
			else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=count-1)
			{
				newfloat1[link]->nextc=newchar1[link+1];
			}
			else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=count-1)
			{
				newchar1[link]->nextf=newfloat1[link+1];
			}
			else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=count-1)
			{
				newchar1[link]->nextc=newchar1[link+1];
			}
		}
		if(database[0].datatype==0)
		{
			headfloat[n][rownumber]=newfloat1[0];
		}
		else
		{
			headchar[n][rownumber]=newchar1[0];
		}
		for(k=0;k<count;k++)
		{
			if(database[k].datatype==0)
			{
				newfloat1[k]=newfloat1[k]->nextcolumnf;
			}
			else
			{
				newchar1[k]=newchar1[k]->nextcolumnc;
			}
		}
	}
	for(i=0;i<count;i++)
	{
		if(database[i].datatype==0)
		{
			newfloat1[i]->nextf=(struct Datafloat *)malloc(sizeof(struct Datafloat));
			if(newfloat1[i]->nextf==NULL)
			{
				printf("error10\n");
				return 10;
			}
			newfloat1[i]=newfloat1[i]->nextf;
			newfloat1[i]->nextf=NULL;
			newfloat1[i]->nextc=NULL;
			newfloat1[i]->datafloat=0;
		}
		else if(database[i].datatype!=0)
		{
			newchar1[i]->nextc=(struct Datachar *)malloc(sizeof(struct Datachar));
			if(newchar1[i]->nextc==NULL)
			{
				printf("error11\n");
				return 11;
			}
			newchar1[i]=newchar1[i]->nextc;
			newchar1[i]->nextc=NULL;
			newchar1[i]->nextf=NULL;
			newchar1[i]->datachar=(char *)malloc(sizeof(char)*129);
			newstrcpy(newchar1[i]->datachar,"\0\0");
		}
	}
	j=0;
	for(link=0;link<count;link++)
	{
		if(database[link].datatype==0&&database[link+1].datatype==0&&link!=count-1)
		{
			(newfloat1[link]->nextf=newfloat1[link+1]);
		}
		else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=count-1)
		{
			newfloat1[link]->nextc=newchar1[link+1];
		}
		else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=count-1)
		{
			newchar1[link]->nextf=newfloat1[link+1];
		}
		else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=count-1)
		{
			newchar1[link]->nextc=newchar1[link+1];
		}
	}
	if(database[0].datatype==0)
	{
		headfloat[n][rownumber+1]=newfloat1[0];
	}
	else
	{
		headchar[n][rownumber+1]=newchar1[0];
	}
	printf("-----input data complete.-----\n");
	printf("-----%d Records Imported Successfully-----\n",rownumber);
	end=clock();
	time=(double)(start-end)/CLOCKS_PER_SEC;
	fopen_s(&fp,"D:\\vs2012\\file for C\\inputtime.txt","w");
	fprintf(fp,"execute time :%f\n",time);
	fclose(filepointer);
	free(word);
	free(midword);
	word=NULL;
	midword=NULL;
	return 7;
}

int realselect(FILE *filepointer)
{
	clock_t start,end;
	int i=0,j=0,k=0,link=0,n=0,m=0,p=0,u=0,top=0,model=0,table=0,size=0,sizewhere=0,columnnumbers=0,*setcolumn=NULL,**columnnumber=NULL,*orsize,and=0,or=0,row=0,rows=0,midal=0,*headnumber=NULL,*orderf=NULL;
	char chara,chara1,*word=NULL,*midword=NULL,*midmidword=NULL,*table_nameselect=NULL,**column_name=NULL,*columnorder=NULL,*Order=NULL,***column_nameorrarry=NULL,***columnrarryc=NULL,**orderc=NULL,TOP[]="top",star[]="*",AND[]="and",OR[]="or",ORDER[]="order",ASC[]="asc",DESC[]="desc";
	double time;
	struct Datafloat *p1=NULL;
	struct Datachar *p2=NULL;
	start=clock();
	word=(char *)malloc(sizeof(char)*100);
	midword=(char *)malloc(sizeof(char)*100);
	midmidword=(char *)malloc(sizeof(char)*100);
	if(word==NULL||midword==NULL||midmidword==NULL)
	{
		printf("error0\n");
		return 0;
	}
	table_nameselect=(char *)malloc(sizeof(char)*129);
	if(table_nameselect==NULL)
	{
		printf("error1\n");
		return 1;
	}
	orsize=(int *)malloc(sizeof(int)*25);
	if(orsize==NULL)
	{
		printf("error2\n");
		return 2;
	}
	orsize[0]=0;
	headnumber=(int *)malloc(sizeof(int)*rownumber);
	if(headnumber==NULL)
	{
		printf("error3\n");
		return 3;
	}
	memset(headnumber,0,sizeof(int)*rownumber);
	setcolumn=(int *)malloc(sizeof(int)*count);
	if(setcolumn==NULL)
	{
		printf("error3\n");
		return 3;
	}
	chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	size=ftell(filepointer);
	while(chara!=' ')
	{
		while(chara!=' ')
		{
			word[i]=chara;
			i++;
			chara=fgetc(filepointer);
		}
		word[i]='\0';
		i=0;
	}
	if(newstrcmp(word,"*")==0)
	{
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' ')chara=fgetc(filepointer);
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' '&&chara!='\n'&&chara!=EOF)
		{
			word[i]=chara;
			i++;
			chara=fgetc(filepointer);
		}
		word[i]='\0';
		i=0;
		j=0;
		k=0;
		newstrcpy(table_nameselect,word);
		model=0;
		top=rownumber;
	}
	else
	{
		newstrlwr(word);
	}
	if(newstrcmp(word,TOP)==0)
	{
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' ')
		{
			word[i]=chara;
			i++;
			chara=fgetc(filepointer);
		}
		word[i]='\0';
		i=0;
		top=atoi(word);
		while(chara==' ')chara=fgetc(filepointer);
		size=ftell(filepointer);
		if(chara=='{')
		{
			model=1;
			while(chara!='}')
			{
				word[i]=chara;
				i++;
				chara=fgetc(filepointer);
			}
			word[i]='\0';
			for(i=0;word[i]!='\0';i++)
			{
				if(word[i]==',')
				{
					columnnumbers++;
				}
			}
			i=0;
			column_name=(char **)malloc(sizeof(char *)*(columnnumbers+1));
			fseek(filepointer,size,0);
			for(j=0;j<=columnnumbers;j++)
			{
				chara=fgetc(filepointer);
				column_name[j]=(char *)malloc(sizeof(char)*50);
				while(chara!=','&&chara!='}')
				{
					word[i]=chara;
					i++;	
					chara=fgetc(filepointer);
				}
				word[i]='\0';
				i=0;
				newstrcpy(column_name[j],word);
			}
			column_name[columnnumbers+1]=(char *)malloc(sizeof(char)*50);
			newstrcpy(column_name[columnnumbers+1],"1");
			for(i=0,j=0,k=0;i<count;i++)
			{
				if(newstrcmp(database[i].column_name,column_name[j])==0)
				{
					setcolumn[k]=i;
					k++;
					j++;
				}
			}
			u=k;
			i=0;
			chara=fgetc(filepointer);
			while(chara==' ')chara=fgetc(filepointer);
			while(chara!=' ')chara=fgetc(filepointer);
			while(chara==' ')chara=fgetc(filepointer);
			while(chara!=' '&&chara!='\n'&&chara!=EOF)
			{
				word[i]=chara;
				i++;
				chara=fgetc(filepointer);
			}
			word[i]='\0';
			i=0;
			j=0;
			newstrcpy(table_nameselect,word);
		}
		else if(chara=='*')
		{
			model=2;
			while(chara!=' ')chara=fgetc(filepointer);
			while(chara==' ')chara=fgetc(filepointer);
			while(chara!=' ')chara=fgetc(filepointer);
			while(chara==' ')chara=fgetc(filepointer);
			while(chara!=' '&&chara!='\n'&&chara!=EOF)
			{
				word[i]=chara;
				i++;
				chara=fgetc(filepointer);
			}
			word[i]='\0';
			i=0;
			j=0;
			k=0;
			newstrcpy(table_nameselect,word);
		}
	}
	else if(word[0]=='{')
	{
		model=3;
		top=rownumber;
		for(i=0;word[i]!='\0';i++)
		{
			if(word[i]==',')
			{
				columnnumbers++;
			}
		}
		i=0;
		column_name=(char **)malloc(sizeof(char *)*(columnnumbers+1));
		fseek(filepointer,size,0);
		for(j=0;j<=columnnumbers;j++)
		{
			chara=fgetc(filepointer);
			column_name[j]=(char *)malloc(sizeof(char)*50);
			while(chara!=','&&chara!='}')
			{
				word[i]=chara;
				i++;	
				chara=fgetc(filepointer);
			}
			word[i]='\0';
			i=0;
			newstrcpy(column_name[j],word);
		}
		column_name[columnnumbers+1]=(char *)malloc(sizeof(char)*50);
		newstrcpy(column_name[columnnumbers+1],"1");
		for(i=0,j=0,k=0;i<count;i++)
		{
			if(newstrcmp(database[i].column_name,column_name[j])==0)
			{
				setcolumn[k]=i;
				k++;
				j++;
			}
		}
		u=k;
		i=0;
		chara=fgetc(filepointer);
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' ')chara=fgetc(filepointer);
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' '&&chara!='\n'&&chara!=EOF)
		{
			word[i]=chara;
			i++;
			chara=fgetc(filepointer);
		}
		word[i]='\0';
		i=0;
		j=0;
		newstrcpy(table_nameselect,word);
	}
	for(i=0;i<10;i++)
	{
		if(newstrcmp(table_nameselect,table_nametotal[i])==0)
		{
			table=i;
		}
	}
	if(chara==EOF)
	{
		fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_select1_1.txt","w");
		if(newfilepointer==NULL)
		{
		printf("error5\n");
		return 5;
		}
		end=clock();
		time=(double)(start-end)/CLOCKS_PER_SEC;
		fprintf(newfilepointer,"execute time:%fms\n",time);
		fprintf(newfilepointer,"execute result:\n");
		if(model==0)
		{
			if(database[0].datatype==0)
			{
				printftable(headfloat[table],newfilepointer);
			}
			else
			{
				printctable(headchar[table],newfilepointer);
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully------\n",top);
		}
		else if(model==1)
		{
			for(row=0;row<rownumber&&row<top;row++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[table][row];
				}
				else
				{
					p2=headchar[table][row];
				}
				for(i=0;i<count;i++)
				{
					if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p1=p1->nextf;
					}
					else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p2=p1->nextc;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%s\n",p2->datachar);
							}
						}
						p1=p2->nextf;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%s\n",p2->datachar);
							}
						}
						p2=p2->nextc;
					}
				}
				if(database[count-1].datatype==0&&i==count-1)
				{
					for(j=0;j<k;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%f\n",p1->datafloat);
						}
					}
				}	
				else
				{
					for(j=0;j<k;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%s\n",p2->datachar);
						}
					}
				}
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully------\n",top);
		}
		else if(model==2)
		{
			for(row=0;row<top;row++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[table][row];
				}
				else
				{
					p2=headchar[table][row];
				}
				for(i=0;i<count;i++)
				{
					if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
					{
						fprintf(newfilepointer,"%f,",p1->datafloat);
						p1=p1->nextf;
					}
					else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
					{
						fprintf(newfilepointer,"%f,",p1->datafloat);
						p2=p1->nextc;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
					{
						fprintf(newfilepointer,"%s,",p2->datachar);
						p1=p2->nextf;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
					{
						fprintf(newfilepointer,"%s\n",p2->datachar);
						p2=p2->nextc;
					}
				}
				if(database[count-1].datatype==0)
				{
					fprintf(newfilepointer,"%f\n",p1->datafloat);
				}
				else
				{
					fprintf(newfilepointer,"%s\n",p2->datachar);
				}
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully------\n",top);
		}
		else if(model==3)
		{
			for(row=0;row<rownumber&&row<top;row++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[table][row];
				}
				else
				{
					p2=headchar[table][row];
				}
				for(i=0;i<count;i++)
				{
					if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p1=p1->nextf;
					}
					else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p2=p1->nextc;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
						}
						p1=p2->nextf;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
						}
						p2=p2->nextc;
					}
				}
				if(database[count-1].datatype==0&&i==count-1)
				{
					for(j=0;j<k;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%f\n",p1->datafloat);
						}
					}
				}	
				else
				{
					for(j=0;j<k;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%s\n",p2->datachar);
						}
					}
				}
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully------\n",top);
		}
	}
	else
	{
		i=0;
		j=0;
		k=0;
		while(chara!=' ')chara=fgetc(filepointer);
		sizewhere=ftell(filepointer);
		for(;!feof(filepointer);)
		{
			while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)
			{
				word[i]=chara;
				i++;
				chara=fgetc(filepointer);
			}
			word[i]='\0';
			i=0;
			newstrlwr(word);
			if(newstrcmp(word,AND)==0)
			{
				and++;
				k++;
			}
			else if(newstrcmp(word,OR)==0&&newstrlen(word)<3)
			{
				or++;
				k++;
				orsize[j+1]=k;
				j++;
			}
		}
		and--;
		k--;
		orsize[or+1]=k+1;
		columnrarryc=(char ***)malloc(sizeof(char **)*(or+1));
		if(columnrarryc==NULL)
		{
			printf("error3\n");
			return 3;
		}
		column_nameorrarry=(char ***)malloc(sizeof(char **)*(or+1));
		if(column_nameorrarry==NULL)
		{
			printf("error4\n");
			return 4;
		}
		for(j=0;j<or+1;j++)
		{
			columnrarryc[j]=(char **)malloc(sizeof(char *)*(orsize[j+1]-orsize[j]));//空间长度。
			if(columnrarryc[j]==NULL)
			{
				printf("error5\n");
				return 5;
			}
			column_nameorrarry[j]=(char **)malloc(sizeof(char *)*(orsize[j+1]-orsize[j]));
			if(column_nameorrarry[j]==NULL)
			{
				printf("error6\n");
				return 6;
			}
		}
		for(i=0;i<or+1;i++)
		{
			for(j=0;j<orsize[i+1]-orsize[i];j++)
			{
				columnrarryc[i][j]=(char *)malloc(sizeof(char)*25);
				column_nameorrarry[i][j]=(char *)malloc(sizeof(char)*25);
				if(columnrarryc[i][j]==NULL)
				{
					printf("error7\n");
					return 7;
				}
				if(column_nameorrarry[i][j]==NULL)
				{
					printf("error8\n");
					return 8;
				}
			}
		}
		i=0;
		j=0;
		k=0;
		fseek(filepointer,sizewhere,0);
		chara=fgetc(filepointer);
		for(i=0;i<(or+1);i++)
		{
			for(j=0;j<(orsize[i+1]-orsize[i]);j++)
			{
				while(chara==' ')chara=fgetc(filepointer);
				while(chara!=' '&&chara!=EOF)
				{
					word[k]=chara;
					k++;
					chara=fgetc(filepointer);
				}
				word[k]='\0';
				k=0;
				newstrcpy(column_nameorrarry[i][j],word);
				while(chara==' ')chara=fgetc(filepointer);
				while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
				while(chara==' ')chara=fgetc(filepointer);
				while(chara!=' '&&chara!=EOF)
				{
					word[k]=chara;
					k++;
					chara=fgetc(filepointer);
				}
				word[k]='\0';
				k=0;
				newstrcpy(columnrarryc[i][j],word);
				while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
				while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
			}
		}
		i=0;
		j=0;
		k=0;
		if(feof(filepointer)==0)
		{
			fseek(filepointer,-6L,1);
		}
		chara=fgetc(filepointer);
		while(chara!=' ')
		{
			word[i]=chara;
			i++;
			chara=fgetc(filepointer);
		}
		word[i]='\0';
		i=0;
		if(newstrcmp(word,ORDER)==0)
		{
			while(chara==' ')chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara==' ')chara=fgetc(filepointer);
		}
		while(chara!=' '&&chara!=EOF)
		{
			word[i]=chara;
			i++;
			chara=fgetc(filepointer);
		}
		word[i]='\0';
		i=0;
		columnorder=(char *)malloc(sizeof(char)*50);
		if(columnorder==NULL)
		{
			printf("error9\n");
			return 9;
		}
		newstrcpy(columnorder,word);
		Order=(char *)malloc(sizeof(char)*10);
		if(chara!=EOF)
		{
			while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)
			{
				word[i]=chara;
				i++;
				chara=fgetc(filepointer);
			}
			word[i]='\0';
			i=0;
			newstrcpy(Order,word);
		}
		else
		{
			newstrcpy(Order,"ASC");
		}
		newstrlwr(Order);
		for(;i<count;i++)
		{
			if(newstrcmp(database[i].column_name,word)==0)
			{
				n=i;
			}
		}
		i=0;
		columnnumber=(int **)malloc(sizeof(int *)*(or+1));
		for(i=0;i<(or+1);i++)
		{
			columnnumber[i]=(int *)malloc(sizeof(int)*(orsize[i+1]-orsize[i]));
		}
		i=0;
		for(k=0;k<count;k++)
		{
			for(i=0;i<(or+1);i++)
			{
				for(j=0;j<(orsize[i+1]-orsize[i]);j++)
				{
					if(newstrcmp(database[k].column_name,column_nameorrarry[i][j])==0)
					{
						columnnumber[i][j]=k;
					}
				}
			}
		}
		i=0;
		j=0;
		k=0;
		for(row=0;row<(rownumber+1);row++)
		{
			for(i=0;i<(or+1);i++)
			{
				for(j=0,midal=0;j<(orsize[i+1]-orsize[i]);j++)
				{
					if(database[0].datatype==0)
					{
						p1=headfloat[table][row];
					}
					else
					{
						p2=headchar[table][row];
					}
					for(link=0;link<=columnnumber[i][j];link++)
					{
						if(database[link].datatype==0&&database[link+1].datatype==0&&link!=columnnumber[i][j])
						{
							p1=p1->nextf;
						}
						else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=columnnumber[i][j])
						{
							p2=p1->nextc;
						}
						else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=columnnumber[i][j])
						{
							p1=p2->nextf;
						}
						else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=columnnumber[i][j])
						{
							p2=p2->nextc;
						}
						if(link==columnnumber[i][j])
						{
							if((database[columnnumber[i][j]].datatype==0)&&(p1->datafloat==(atof(columnrarryc[i][j]))))
							{
								midal++;
								rows++;
							}
							else if((database[columnnumber[i][j]].datatype==1)&&newstrcmp(p2->datachar,columnrarryc[i][j])==0)
							{
								midal++;
								rows++;
							}
						}
					}
				}
				if(midal==(orsize[i+1]-orsize[i]))
				{
					headnumber[k]=row;
					k++;
				}
			}
		}
		if(newstrcmp(Order,ASC)==0)
		{
			size=1;
		}
		else
		{
			size=-1;
		}
		for(i=0;i<count;i++)
		{
			if(newstrcmp(database[i].column_name,columnorder)==0)
			{
				n=i;
			}
		}
		if(database[n].datatype==0)
		{
			orderf=(int *)malloc(sizeof(int)*k);
			if(orderf==NULL)
			{
				printf("error10\n");
				return 10;
			}
			for(i=0;i<k;i++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[table][headnumber[i]];
				}
				else
				{
					p2=headchar[table][headnumber[i]];
				}
				for(link=0;link<=n;link++)
				{
					if(database[link].datatype==0&&database[link+1].datatype==0&&link!=n)
					{
						p1=p1->nextf;
					}
					else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=n)
					{
						p2=p1->nextc;
					}
					else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=n)
					{
						p1=p2->nextf;
					}
					else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=n)
					{
						p2=p2->nextc;
					}
				}
				orderf[i]=p1->datafloat;
			}
		}
		else
		{
			orderc=(char **)malloc(sizeof(char *)*k);
			if(orderc==NULL)
			{
				printf("error11\n");
				return 11;
			}
			for(i=0;i<k;i++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[table][headnumber[i]];
				}
				else
				{
					p2=headchar[table][headnumber[i]];
				}
				orderc[i]=(char *)malloc(sizeof(char)*50);
				for(link=0;link<=n;link++)
				{
					if(database[link].datatype==0&&database[link+1].datatype==0&&link!=n)
					{
						p1=p1->nextf;
					}
					else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=n)
					{
						p2=p1->nextc;
					}
					else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=n)
					{
						p1=p2->nextf;
					}
					else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=n)
					{
						p2=p2->nextc;
					}
				}
				newstrcpy(orderc[i],p2->datachar);
			}
		}
		if(database[n].datatype==0)
		{
			for(i=0;i<k;i++)
			{
				j=orderf[i];
				for(n=i+1;n<k;n++)
				{
					if(j<orderf[n])
					{
						j=orderf[n];
					}
				}
				for(p=i;p<k;p++)
				{
					if(j==orderf[p])
					{
						m=orderf[i];
						orderf[i]=orderf[p];
						orderf[p]=m;
						m=headnumber[i];
						headnumber[i]=headnumber[p];
						headnumber[p]=m;
					}
				}
			}
		}
		else
		{
			for(i=0;i<k;i++)
			{
				newstrcpy(word,orderc[i]);
				for(n=i+1;n<k;n++)
				{
					if(newstrcmp(word,orderc[n])==size)
					{
						newstrcpy(word,orderc[n]);
					}
					else if(newstrcmp(word,orderc[n])==0)
					{
						if(newstrlen(word)>newstrlen(orderc[n]))
						{
							newstrcpy(word,orderc[n]);
						}
					}
				}
				for(p=i;p<k;p++)
				{
					if(newstrcmp(word,orderc[p])==0)
					{
						newstrcpy(midmidword,orderc[i]);
						newstrcpy(orderc[i],orderc[p]);
						newstrcpy(orderc[p],midmidword);
						m=headnumber[i];
						headnumber[i]=headnumber[p];
						headnumber[p]=m;
					}
				}
			}
		}
		if(model==0)
		{
			fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_select1_1.txt","w");
			if(newfilepointer==NULL)
			{
				printf("error5\n");
				return 5;
			}
			end=clock();
			time=(double)(start-end)/CLOCKS_PER_SEC;
			fprintf(newfilepointer,"execute time:%fms\n",time);
			fprintf(newfilepointer,"execute result:\n");
			for(row=0;row<k&&row<top;row++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[headnumber[row]];
				}
				else
				{
					p2=headchar[headnumber[row]];
				}
				for(i=0;i<count;i++)
				{
					if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
					{
						fprintf(newfilepointer,"%f,",p1->datafloat);
						p1=p1->nextf;
					}
					else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
					{
						fprintf(newfilepointer,"%f,",p1->datafloat);
						p2=p1->nextc;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
					{
						fprintf(newfilepointer,"%s,",p2->datachar);
						p1=p2->nextf;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
					{
						fprintf(newfilepointer,"%s\n",p2->datachar);
						p2=p2->nextc;
					}
				}
				if(database[count-1].datatype==0)
				{
					fprintf(newfilepointer,"%f\n",p1->datafloat);
				}
				else
				{
					fprintf(newfilepointer,"%s\n",p2->datachar);
				}
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully0------\n",k);
		}
		else if(model==1)
		{
			fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_select1_1.txt","w");
			if(newfilepointer==NULL)
			{
				printf("error5\n");
				return 5;
			}
			end=clock();
			time=(double)(start-end)/CLOCKS_PER_SEC;
			fprintf(newfilepointer,"execute time:%fms\n",time);
			fprintf(newfilepointer,"execute result:\n");
			for(row=0;row<k&&row<top;row++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[headnumber[row]];
				}
				else
				{
					p2=headchar[headnumber[row]];
				}
				for(i=0;i<count;i++)
				{
					if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<u;j++)
						{
							if(i==setcolumn[j]&&j!=u-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==u-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p1=p1->nextf;
					}
					else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<u;j++)
						{
							if(i==setcolumn[j]&&j!=u-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==u-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p2=p1->nextc;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<u;j++)
						{
							if(i==setcolumn[j]&&j!=u-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==u-1)
							{
								fprintf(newfilepointer,"%s\n",p2->datachar);
							}
						}
						p1=p2->nextf;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<u;j++)
						{
							if(i==setcolumn[j]&&j!=u-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==u-1)
							{
								fprintf(newfilepointer,"%s\n",p2->datachar);
							}
						}
						p2=p2->nextc;
					}
				}
				if(database[count-1].datatype==0&&i==count-1)
				{
					for(j=0;j<u;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%f\n",p1->datafloat);
						}
					}
				}	
				else
				{
					for(j=0;j<u;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%s\n",p2->datachar);
						}
					}
				}
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully------1\n",top);
		}
		else if(model==2)
		{
			fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_select1_1.txt","w");
			if(newfilepointer==NULL)
			{
				printf("error5\n");
				return 5;
			}
			end=clock();
			time=(double)(start-end)/CLOCKS_PER_SEC;
			fprintf(newfilepointer,"execute time:%fms\n",time);
			fprintf(newfilepointer,"execute result:\n");
			for(row=0;row<k&&row<top;row++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[headnumber[row]];
				}
				else
				{
					p2=headchar[headnumber[row]];
				}
				for(i=0;i<count;i++)
				{
					if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
					{
						fprintf(newfilepointer,"%f,",p1->datafloat);
						p1=p1->nextf;
					}
					else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
					{
						fprintf(newfilepointer,"%f,",p1->datafloat);
						p2=p1->nextc;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
					{
						fprintf(newfilepointer,"%s,",p2->datachar);
						p1=p2->nextf;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
					{
						fprintf(newfilepointer,"%s\n",p2->datachar);
						p2=p2->nextc;
					}
				}
				if(database[count-1].datatype==0)
				{
					fprintf(newfilepointer,"%f\n",p1->datafloat);
				}
				else
				{
					fprintf(newfilepointer,"%s\n",p2->datachar);
				}
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully------2\n",top);
		}
		else if(model==3)
		{
			fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_select1_1.txt","w");
			if(newfilepointer==NULL)
			{
				printf("error5\n");
				return 5;
			}
			end=clock();
			time=(double)(start-end)/CLOCKS_PER_SEC;
			fprintf(newfilepointer,"execute time:%fms\n",time);
			fprintf(newfilepointer,"execute result:\n");
			for(row=0;row<k&&row<top;row++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[headnumber[row]];
				}
				else
				{
					p2=headchar[headnumber[row]];
				}
				for(i=0;i<count;i++)
				{
					if(database[i].datatype==0&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<u;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p1=p1->nextf;
					}
					else if(database[i].datatype==0&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<u;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%f,",p1->datafloat);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%f\n",p1->datafloat);
							}
						}
						p2=p1->nextc;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==0&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
						}
						p1=p2->nextf;
					}
					else if(database[i].datatype==1&&database[i+1].datatype==1&&i!=count-1)
					{
						for(j=0;j<k;j++)
						{
							if(i==setcolumn[j]&&j!=k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
							if(i==setcolumn[j]&&j==k-1)
							{
								fprintf(newfilepointer,"%s,",p2->datachar);
							}
						}
						p2=p2->nextc;
					}
				}
				if(database[count-1].datatype==0&&i==count-1)
				{
					for(j=0;j<k;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%f\n",p1->datafloat);
						}
					}
				}	
				else
				{
					for(j=0;j<k;j++)
					{
						if(count-1==setcolumn[j])
						{
							fprintf(newfilepointer,"%s\n",p2->datachar);
						}
					}
				}
			}
			printf("-----Select Completed!-----\n");
			printf("-----%d Record Selected Successfully------3\n",k);
		}
	}
	fclose(filepointer);
	fclose(newfilepointer);
	fclose(filepointer);
	fclose(newfilepointer);
	free(word);
	free(columnrarryc);
	free(columnnumber);
	free(column_nameorrarry);
	free(headnumber);
	word=NULL;
	columnrarryc=NULL;
	columnnumber=NULL;
	column_nameorrarry=NULL;
	headnumber=NULL;
	filepointer=NULL;
	newfilepointer=NULL;
	return 0;
}

int realupdate(FILE *filepointer)
{
	clock_t start,end;
	int i=0,j=0,k=0,n=0,and=0,or=0,size=0,link=0,row=0,*headnumber=NULL,rows=0,**columnnumber=NULL,*orsize=NULL,sizewhere=0,midal=0;
	char chara,*word=NULL,*table_nameupdate=NULL,*column_nameset=NULL,***column_nameorrarry=NULL,*column_valuecset=NULL,AND[]="and",OR[]="or",***columnrarryc=NULL;
	float column_valueset=0;
	double time;
	struct Datafloat *p1=NULL;
	struct Datachar *p2=NULL;
	start=clock();
	word=(char *)malloc(sizeof(char)*50);
	if(word==NULL)
	{
		printf("error0\n");
		return 0;
	}
	table_nameupdate=(char *)malloc(sizeof(char)*129);
	if(table_nameupdate==NULL)
	{
		printf("error1\n");
		return 1;
	}
	column_nameset=(char *)malloc(sizeof(char)*50);
	if(column_nameset==NULL)
	{
		printf("error2\n");
		return 2;
	}
	column_valuecset=(char *)malloc(sizeof(char)*50);
	if(column_valuecset==NULL)
	{
		printf("error3\n");
		return 3;
	}
	headnumber=(int *)malloc(sizeof(int)*rownumber);
	if(headnumber==NULL)
	{
		printf("error4\n");
		return 4;
	}
	memset(headnumber,0,sizeof(int)*rownumber);
	orsize=(int *)malloc(sizeof(int)*25);
	if(orsize==NULL)
	{
		printf("error5\n");
		return 5;
	}
	orsize[0]=0;
	chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' '&&chara!='\n')
	{
		word[i]=chara;
		i++;
		chara=fgetc(filepointer);
	}
	word[i]='\0';
	i=0;
	newstrcpy(table_nameupdate,word);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')
	{
		word[i]=chara;
		i++;
		chara=fgetc(filepointer);
	}
	word[i]='\0';
	i=0;
	newstrcpy(column_nameset,word);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')
	{
		word[i]=chara;
		i++;
		chara=fgetc(filepointer);
	}
	word[i]='\0';
	i=0;
	newstrcpy(column_valuecset,word);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	sizewhere=ftell(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
	size=ftell(filepointer);
	for(;!feof(filepointer);)
	{
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' '&&chara!=EOF)
		{
			word[i]=chara;
			i++;
			chara=fgetc(filepointer);
		}
		word[i]='\0';
		i=0;
		newstrlwr(word);
		if(newstrcmp(word,AND)==0)
		{
			and++;
			k++;
		}
		else if(newstrcmp(word,OR)==0&&(newstrlen(word)<5))
		{
			or++;
			k++;
			orsize[j+1]=k;
			j++;
		}
		while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
		while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
		while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
		while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
		while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
		while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
	}
	orsize[or+1]=k+1;
	columnrarryc=(char ***)malloc(sizeof(char **)*(or+1));
	if(columnrarryc==NULL)
	{
		printf("error5\n");
		return 5;
	}
	column_nameorrarry=(char ***)malloc(sizeof(char **)*(or+1));
	if(column_nameorrarry==NULL)
	{
		printf("error7\n");
		return 7;
	}
	for(j=0;j<or+1;j++)
	{
		columnrarryc[j]=(char **)malloc(sizeof(char *)*(orsize[j+1]-orsize[j]));//空间长度。
		if(columnrarryc[j]==NULL)
		{
			printf("error8\n");
			return 8;
		}
		column_nameorrarry[j]=(char **)malloc(sizeof(char *)*(orsize[j+1]-orsize[j]));
		if(column_nameorrarry[j]==NULL)
		{
			printf("error10\n");
			return 10;
		}
	}
	for(i=0;i<or+1;i++)
	{
		for(j=0;j<orsize[i+1]-orsize[i];j++)
		{
			columnrarryc[i][j]=(char *)malloc(sizeof(char)*25);
			column_nameorrarry[i][j]=(char *)malloc(sizeof(char)*25);
			if(columnrarryc[i][j]==NULL)
			{
				printf("error11\n");
				return 11;
			}
			if(column_nameorrarry[i][j]==NULL)
			{
				printf("error12\n");
				return 12;
			}
		}
	}
	i=0;
	j=0;
	k=0;
	fseek(filepointer,sizewhere,0);
	for(i=0;i<or+1;i++)
	{
		for(j=0;j<orsize[i+1]-orsize[i];j++)
		{
			chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)
			{
				word[k]=chara;
				k++;
				chara=fgetc(filepointer);
			}
			word[k]='\0';
			k=0;
			newstrcpy(column_nameorrarry[i][j],word);
			while(chara==' ')chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara==' ')chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)
			{
				word[k]=chara;
				k++;
				chara=fgetc(filepointer);
			}
			word[k]='\0';
			k=0;
			newstrcpy(columnrarryc[i][j],word);
			while(chara==' '&&chara!=EOF)chara=fgetc(filepointer);
			while(chara!=' '&&chara!=EOF)chara=fgetc(filepointer);
		}
	}
	column_valueset=atof(column_valuecset);
	i=0;
	j=0;
	k=0;
	columnnumber=(int **)malloc(sizeof(int *)*(or+1));
	for(i=0;i<(or+1);i++)
	{
		columnnumber[i]=(int *)malloc(sizeof(int)*(orsize[i+1]-orsize[i]));
	}
	i=0;
	for(k=0;k<count;k++)
	{
		for(i=0;i<(or+1);i++)
		{
			for(j=0;j<(orsize[i+1]-orsize[i]);j++)
			{
				if(newstrcmp(database[k].column_name,column_nameorrarry[i][j])==0)
				{
					columnnumber[i][j]=k;
				}
			}
		}
	}
	i=0;
	j=0;
	k=0;
	for(row=0;row<(rownumber+1);row++)
	{
		for(i=0;i<(or+1);i++)
		{
			for(j=0,midal=0;j<(orsize[i+1]-orsize[i]);j++)
			{
				if(database[0].datatype==0)
				{
					p1=headfloat[row];
				}
				else
				{
					p2=headchar[row];
				}
				for(link=0;link<=columnnumber[i][j];link++)
				{
					if(database[link].datatype==0&&database[link+1].datatype==0&&link!=columnnumber[i][j])
					{
						p1=p1->nextf;
					}
					else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=columnnumber[i][j])
					{
						p2=p1->nextc;
					}
					else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=columnnumber[i][j])
					{
						p1=p2->nextf;
					}
					else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=columnnumber[i][j])
					{
						p2=p2->nextc;
					}
					if(link==columnnumber[i][j])
					{
						if((database[columnnumber[i][j]].datatype==0)&&(p1->datafloat==(atof(columnrarryc[i][j]))))
						{
							midal++;
							rows++;
						}
						else if((database[columnnumber[i][j]].datatype==1)&&newstrcmp(p2->datachar,columnrarryc[i][j])==0)
						{
							midal++;
							rows++;
						}
					}
				}
			}
			if(midal==(orsize[i+1]-orsize[i]))
			{
				headnumber[k]=row;
				k++;
			}
		}
	}
	for(i=0;i<count;i++)
	{
		if(newstrcmp(database[i].column_name,column_nameset)==0)
		{
			n=i;
		}
	}
	i=0;
	for(row=0;row<k;row++)
	{
		if(database[0].datatype==0)
		{
			p1=headfloat[headnumber[row]];
		}
		else
		{
			p2=headchar[headnumber[row]];
		}
		for(link=0;link<=n;link++)
		{
			if(database[link].datatype==0&&database[link+1].datatype==0&&link!=n)
			{
				p1=p1->nextf;
			}
			else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=n)
			{
				p2=p1->nextc;
			}
			else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=n)
			{
				p1=p2->nextf;
			}
			else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=n)
			{
				p2=p2->nextc;
			}
			if(link==n)
			{
				if(database[n].datatype==0)
				{
					p1->datafloat=column_valueset;
				}
				else if(database[n].datatype==1)
				{
					newstrcpy(p2->datachar,column_valuecset);
				}
			}
		}
	}
	i=0;
	//
	fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_update1_1.txt","w");
	if(newfilepointer==NULL)
	{
		printf("error5\n");
		return 5;
	}
	end=clock();
	time=(double)(start-end)/CLOCKS_PER_SEC;
	fprintf(newfilepointer,"execute time:%fms\n",time);
	fprintf(newfilepointer,"execute result:\n");
	if(database[0].datatype==0)
	{
		printftable(headfloat,newfilepointer);
	}
	else
	{
		printctable(headchar,newfilepointer);
	}
	printf("-----Update Completed!-----\n");
	printf("-----%d Record Updated Successfully-----\n",k);
	fclose(filepointer);
	fclose(newfilepointer);
	free(word);
	free(column_nameset);
	free(column_valuecset);
	free(table_nameupdate);
	free(columnrarryc);
	free(columnnumber);
	free(column_nameorrarry);
	word=NULL;
	column_nameset=NULL;
	column_valuecset=NULL;
	columnrarryc=NULL;
	columnnumber=NULL;
	column_nameorrarry=NULL;
	filepointer=NULL;
	newfilepointer=NULL;
	return 0;
}

int realdelete(FILE *filepointer)
{
	clock_t start,end;
	int i=0,j=0,k=0,n=0,row=0,link=0,*headnumber=NULL,rows=0;
	char *word,chara,*filetablename,*column_name,*column_valuec,*table_name=NULL;
	float column_value=0;
	double time;
	struct Datafloat *p1=NULL;
	struct Datachar *p2=NULL;
	start=clock();
	column_name=(char *)malloc(sizeof(char)*100);
	if(column_name==NULL)
	{
		printf("error0\n");
		return 0;
	}
	headnumber=(int *)malloc(sizeof(int)*rownumber);
	if(headnumber==NULL)
	{
		printf("error1\n");
		return 1;
	}
	word=(char *)malloc(sizeof(char)*129);	
	if(word==NULL)
	{
		printf("error2\n");
		return 2;
	}
	filetablename=(char *)malloc(sizeof(char)*129);
	if(filetablename==NULL)
	{
		printf("error3\n");
		return 3;
	}
	column_valuec=(char *)malloc(sizeof(char)*100);
	if(column_valuec==NULL)
	{
		printf("error4\n");
		return 4;
	}
	table_name=(char *)malloc(sizeof(char)*129);
	if(table_name==NULL)
	{
		printf("error5");
		return 5;
	}
	chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' ')chara=fgetc(filepointer);
	while(chara==' ')chara=fgetc(filepointer);
	while(chara!=' '&&chara!=EOF)
	{
		word[i]=chara;
		i++;
		chara=fgetc(filepointer);
	}
	word[i]='\0';
	i=0;
	newstrcpy(filetablename,word);
	if((chara=fgetc(filepointer))==EOF)
	{
		for(;i<=rownumber;i++)
		{
			if(database[0].datatype==0)
			{
				free(headfloat[i]);
				headfloat[i]=headfloat[rownumber+1];
			}
			else
			{
				free(headchar[i]);
				headchar[i]=headchar[rownumber+1];
			}
		}
		i=0;
		fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_delete1_1.txt","w");
		if(newfilepointer==NULL)
		{
			printf("error5\n");
			return 5;
		}
		end=clock();
		time=(double)(start-end)/CLOCKS_PER_SEC;
		fprintf(newfilepointer,"execute time:%fms\n",time);
		fprintf(newfilepointer,"execute result:\n");
		if(database[0].datatype==0)
		{
			printftable(headfloat,newfilepointer);
		}
		else
		{
			printctable(headchar,newfilepointer);
		}
	}
	else
	{
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' ')chara=fgetc(filepointer);
		chara=fgetc(filepointer);
		while(chara!=' ')
		{
			word[i]=chara;
			chara=fgetc(filepointer);
			i++;
		}
		word[i]='\0';
		i=0;
		newstrcpy(column_name,word);
		while(chara==' ')chara=fgetc(filepointer);
		chara=fgetc(filepointer);
		while(chara==' ')chara=fgetc(filepointer);
		while(chara!=' '&&chara!=']'&&chara!=EOF)
		{
			word[i]=chara;
			chara=fgetc(filepointer);
			i++;
		}
			word[i]='\0';
		i=0;
		newstrcpy(column_valuec,word);
		column_value=atof(word);
		for(;i<count;i++)
		{
			if(newstrcmp(database[i].column_name,column_name)==0)
			{
				n=i;
			}
		}
		i=0;
		if(database[0].datatype==0)
		{
			p1=headfloat[0];
		}
		else
		{
			p2=headchar[0];
		}
		for(link=0;link<n;link++)
		{
			if(database[link].datatype==0&&database[link+1].datatype==0&&link!=count)
			{
				p1=p1->nextf;
			}
			else if(database[link].datatype==0&&database[link+1].datatype==1&&link!=count)
			{
				p2=p1->nextc;
			}
			else if(database[link].datatype==1&&database[link+1].datatype==0&&link!=count)
			{
				p1=p2->nextf;
			}
			else if(database[link].datatype==1&&database[link+1].datatype==1&&link!=count)
			{
				p2=p2->nextc;
			}
		}
		for(row=0;row<rownumber;row++)
		{
			if(database[n].datatype==0)
			{
				if(p1->datafloat==column_value)
				{
					headnumber[i]=row;
					i++;
					rows++;
				}
				p1=p1->nextcolumnf;
			}
			else if(database[n].datatype==1)
			{
				if(newstrcmp(p2->datachar,column_valuec)==0)
				{
					headnumber[i]=row;
					i++;
					rows++;
				}
				p2=p2->nextcolumnc;
			}
		}
		i=0;
		if(database[0].datatype==0)
		{
			for(j=0;j<rows;j++)
			{
				for(i=0;i<rownumber;i++)
				{
					if(i>=headnumber[j])
					{
						headfloat[i]=headfloat[i+1];
					}
				}
				for(k=0;k<rows;k++)
				{
					headnumber[k]--;
				}
			}
		}
		else
		{
			for(j=0;j<rows;j++)
			{
				for(i=0;i<rownumber;i++)
				{
					if(i>=headnumber[j])
					{
						headchar[i]=headchar[i+1];
					}
				}
				for(k=0;k<rows;k++)
				{
					headnumber[k]--;
				}
			}
		}
	}
	fopen_s(&newfilepointer,"D:\\vs2012\\file for C\\1352975_delete1_1.txt","w");
	if(newfilepointer==NULL)
	{
		printf("error5\n");
		return 5;
	}
	end=clock();
	time=(double)(start-end)/CLOCKS_PER_SEC;
	fprintf(newfilepointer,"execute time:%fms\n",time);
	fprintf(newfilepointer,"execute result:\n");
	if(database[0].datatype==0)
	{
		printftable(headfloat,newfilepointer);
	}
	else
	{
		printctable(headchar,newfilepointer);
	}
	printf("-----Delete Completed!-----\n");
	printf("-----%d Record Deleted Successfully------\n",rows);
	fclose(filepointer);
	fclose(newfilepointer);
	free(word);
	free(filetablename);
	free(column_name);
	free(headnumber);
	free(column_valuec);
	free(table_name);
	table_name=NULL;
	filepointer=NULL;
	newfilepointer=NULL;
	column_valuec=NULL;
	headnumber=NULL;
	word=NULL;
	filetablename=NULL;
	column_name=NULL;
	return 4;
}

void realhelp()
{
	printf("***************  please input following order.  ***************\n");
	printf("-c Filename					creat a database  \n");
	printf("-i Tablename Filename				import datas into a specific database.\n");
	printf("-s Filename					select datas from the database.\n");
	printf("-u Filename					update datas from the database.\n");
	printf("-d Filename					delete datas from the databse.\n");
	printf("-q						stop this software.\n");
	printf("***************					***************\n");
}

int realquit()
{
	//free(table_name);
	//fclose(filepointer);
	//fclose(newfilepointer);
	//table_name=NULL;
	//filepointer=NULL;
	//newfilepointer=NULL;
	printf("-----Thanks for you prase.-----\n");
	return 0;
}

int main()
{
	//int equal;
	char order[5],Order;
	table_nametotal=(char **)malloc(sizeof(char *)*10);
	headfloat=(struct Datafloat ***)malloc(sizeof(struct Datafloat **)*10);
	headchar=(struct Datachar ***)malloc(sizeof(struct Datachar **)*10);
	printf("**********************************************\n");
	printf("*	Tiny In-Mem Database version 0.1     *\n");
	printf("*		All rights Reserved	     *\n");
	printf("**********************************************\n");
	printf("DB1=>");
	scanf_s("%s",order,5);
	Order=order[1];
	while(Order!='q')
	{
		Order=order[1];
		switch(Order)
		{
		case 'c':realcreat();break;
		case 'i':{
			char intable_name[]="Student";
			fopen_s(&filepointer,"D:\\vs2012\\file for C\\data3.txt","r");
			realinput(intable_name,filepointer);
				 }break;
		case 's':{
			fopen_s(&filepointer,"D:\\vs2012\\file for C\\select.txt","r");
			realselect(filepointer);
				 }break;
		case 'u':{
			fopen_s(&filepointer,"D:\\vs2012\\file for C\\update.txt","r");
			realupdate(filepointer);
				 }break;
		case 'd':{
			fopen_s(&filepointer,"D:\\vs2012\\file for C\\delete.txt","r");
			realdelete(filepointer);
				 }break;
		case 'h':realhelp();break;
		case 'q':realquit();break;
		default:
			{
				printf("please input right order\n");
				printf("if you need help,you can input '-h' for help.\n");
			}
		}
		printf("DB1=>");
		scanf_s("%s",order,5);
	}
	printf("-----Thanks for your prase.-----\n");
	system("PAUSE");
	return 0;
}