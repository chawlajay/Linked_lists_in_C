

// 1. Find length of string
int string_length(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++);

    return i;
}

// 2. Concatenation of two different strings
char *concate(char *s1,char *s2)
{
    int i,n1,n2;
    char *str;
    n1=string_length(s1);
    n2=string_length(s2);
   // printf("%d %d",n1,n2);
    str=(char *)malloc((n2+n1)*sizeof(char));
    for(i=0;i<n1;i++)
    {
        *(str+i)=*(s1+i);

    }


    for(i=n1;i<(n1+n2);i++)
    {
            *(str+i)=*(s2+i-n1);
    }

    *(str+i)='\0';

    return str;
}

// 3. Retrieve the first index/position/occurrence of given symbol in the string
void first_occu(char *s,char c,int n)
{
 int i,j=-1;
 for(i=0;i<n;i++)
 {
     if(*(s+i)==c)
        {
            j=i;
            break;
        }

 }

 if(j==-1)
    printf("\nLetter not found in the string");
    else
    printf("\nfirst occurrence Index of %c in %s is %d",c,s,j);

}

// 4. Retrieve the last occurrence of given symbol in the string
void last_occu(char *s,char c,int n)
{
 int i,j=-1;
 for(i=n-1;i>=0;i--)
 {
     if(*(s+i)==c)
         {
             j=i;
             break;
         }
 }

 if(j==-1)
    printf("\nLetter not found in the string");
    else
    printf("\nLast occurrence Index of %c in %s is %d",c,s,j);

}

// 9. Reverse of the given string
char *reverse_string(char *s1)
{
    int i,n;
    n=string_length(s1);
    char *str=(char *)malloc(n*sizeof(char));
    for(i=0;i<n;i++)
        *(str+i)=*(s1+n-1-i);

        *(str+i)='\0';

    return str;
}

// 5. Concatenate the reversal of string at the end
char *concate_reverse(char *s1)
{
    return concate(s1,reverse_string(s1));

}

// 6. Duplicate and concatenate the main string
char *concate_duplicate(char *s1)
{
  return concate(s1,s1);
}

// 7. Compare Strings
void compare(char *s1,char *s2)
{
    int i,k=1,n1,n2;

    n1=string_length(s1);
    n2=string_length(s2);
   // printf("%d %d",n1,n2);
    if(n1==n2)
    {
    for(i=0;i<n1;i++)
    {
        if(*(s1+i)!=*(s2+i))
        {
           k=0;
            break;
        }

    }

     if(k)
     printf("Strings are equal");
     else
        printf("Strings are not equal");

    }
    else
        printf("Strings are not equal");
}

// 8. Compare Strings without case sensitivity
void compare_no_case_sensitive(char *s1,char *s2)
{
    int i,k=1,n1,n2;

    n1=string_length(s1);
    n2=string_length(s2);
   // printf("%d %d",n1,n2);
    if(n1==n2)
    {
    for(i=0;i<n1;i++)
    {
        if((*(s1+i))<95)
        {
            if( *(s1+i)==*(s2+i)-32 || (*(s1+i)==*(s2+i)))
            {


            }
            else
            {
                    k=0;
                break;
            }

        }
        else
        {
            if( *(s1+i)==*(s2+i)+32 || (*(s1+i)==*(s2+i)))
            {

            }
            else
            {
               // printf("%d",i);
                    k=0;
                break;
            }
        }

    }

     if(k)
     printf("Strings are equal");
     else
        printf("Strings are not equal");

    }
    else
        printf("Strings are not equal");
}



// 10. Convert the string to upper case
void convert_to_upper_case(char *s)
{

 int i,n;
n=string_length(s);
 for(i=0;i<n;i++)
 {

     if(*(s+i)>='a' && *(s+i)<='z')
         {
             *(s+i)=*(s+i)-32;
         }
          printf("%c",*(s+i));
 }


}

// 11. Convert the string to lower case
void convert_to_lower_case(char *s)
{

 int i,n;
n=string_length(s);
 for(i=0;i<n;i++)
 {
     if(*(s+i)>='A' && *(s+i)<='Z')
         {
             *(s+i)=*(s+i)+32;
         }
       printf("%c",*(s+i));
 }


}

// 12. Convert the string to Title case
void convert_to_title_case(char *s)
{

 int i,n;

if(*(s+0)>='a' && *(s+0)<='z')
         {
             *(s+0)=*(s+0)-32;
         }
printf("%c",*(s+0));
n=string_length(s);
 for(i=1;i<n;i++)
 {

     if(*(s+i)>='A' && *(s+i)<='Z')
         {
             *(s+i)=*(s+i)+32;
         }
printf("%c",*(s+i));
 }


}

// 13. Replace the given substring in the main string from the given position
void replace_substring(char *str,char *sub_str,int pos)
{

 int i,m,j=0;



m=string_length(sub_str);
// s=(char *)malloc((n+m)*sizeof(char));

		 for(i=pos-1;i<pos-1+m;i++)
		 {
		//printf("%d",i);

			     *(str+i)=*(sub_str+j);
		j++;
		 }

printf("%s",str);
}

// 14. Retrieve the index of the substring in the main string
void find_string(char *str,char *sub_str)
{
int p,i,j,k,n,m;
m=string_length(sub_str);
n=string_length(str);
k=0;
	for(i=0;i<n;i++)
	{
	  j=0;
	  p=i;
		 while(j<m)
		{
		    if(str[p++]!=sub_str[j++])
		break;
		}

			if(j==m)
			{
			printf("%d",i);
k=1;
			break;
			}

	}

if(k==0)
printf("string not found");

}

// 15. Check the given string is palindrome or not (using loop)
void palindrome(char *str)
{
    int i,j=1,n;
    n=string_length(str);

    for(i=0;i<n/2;i++)
    {
        if(str[i]!=str[n-1-i])
        {
            j=0;
            break;
        }
    }
    if(j)
        printf("Palindrome");
    else
        printf("Not Palindrome");
}

// 16. Display and count the vowels present in the string
void vowel_count(char *str)
{
    int i,n,c=0;
    n=string_length(str);

    for(i=0;i<n;i++)
    {
       if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='I' || str[i]=='i' || str[i]=='O' || str[i]=='o' || str[i]=='u' || str[i]=='U')
       {
          c++;
          printf("%c",str[i]);
       }
    }
    printf("\nNumber of vowels in the string is %d",c);
}

// 17. Count the characters and words
void count_words_and_characters(char *str)
{
    int i,n,c=0;
    n=string_length(str);
    for(i=0;i<n;i++)
    {
        if(str[i]==' ')
            c++;

    }
    printf("\nNo. of Characters are %d\n",n-c);
    printf("\nNo. of Words are %d\n",++c);
}
