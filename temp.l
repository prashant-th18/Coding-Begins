%{
#include<stdio.h>
int lc=0, sc=0, tc=0, ch=0,words =0;
%}
/*Rule Section*/
%%
\n lc++; //line counter
([ ])+ sc++; //space counter
\t tc++; //tab counter
. ch++;	 //characters counte
end return 0;
([a-zA-Z0-9])*    {words++;}
%%

int main()
{
	// The function that starts the analysis
	yylex();
	
	printf("\nNo. of lines=%d", lc);
	printf("\nNo. of spaces=%d", sc);
	printf("\nNo. of tabs=%d", tc);
	printf("\nNo. of other characters=%d\n", ch);
	printf("words are %d",words);
}
