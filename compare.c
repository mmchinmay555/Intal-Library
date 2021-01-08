#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int intal_compare(const char *intal1, const char * intal2);

int main()
{
    const char intal_1[1000] = "67890678909876543";
    const char intal_2[1000] = "67898767881234567";
    
    printf("%d\n",intal_compare(intal_1, intal_2));

}

int intal_compare(const char* intal1, const char* intal2)
{   
    int len_1 = strlen(intal1);
    int len_2 = strlen(intal2);

   
    int diff_len = len_1 - len_2;

    

    if(diff_len < 0)
    {
        diff_len = diff_len * -1;
    }

    printf("DIFF in len %d\n", diff_len);
    char zero[len_1+len_2];

    int i;
    for(i=0;i<diff_len;i++)
    {
        zero[i] = '0';
    }
   
   	zero[i] = '\0';	
   	
    printf("%s\n", zero);
    printf("%d\n",i);
    
    int x, y, res, carry;
    
    int p;
    
    
    carry = 0;
    
    int check = 0;
    
    if(len_1 < len_2)
    {
    	
    	 for (int j = 0; intal1[j] != '\0'; ++j, ++i)
    	 {
         	zero[i] = intal1[j];
   		 }
   		 
   		 zero[i] = '\0';
   		 
   		 printf("zero   %s\n", zero);
    	 printf("intal2 %s\n", intal2);
   		 
   		//Perform compare on zero and intal2
   		
   		for(p = 0; p <= len_2 -1; p++)
   		{
   			if(*(intal2 + p) - '0' > *(zero + p) - '0')
   			{
   				//printf("%d > %d\n",*(intal2 + p) - '0',*(zero + p) - '0');
   				//printf("-1\n");
   				return -1;
   			}
   			else if(*(intal2 + p) - '0' < *(zero + p) - '0')
   			{
   				//printf("%d < %d\n",*(intal2 + p) - '0',*(zero + p) - '0');
   				//printf("+1\n");
   				return 1;
   			}
   			else
   			{
   				//printf("%d= %d\n",*(intal2 + p) - '0',*(zero + p) - '0');
   				
   				
   			}
   			
   		}
   		//printf("0\n");
   		return 0;	
   		
    }
    else
    {
    	int sol_index = 0;	
    	 for (int j = 0; intal2[j] != '\0'; ++j, ++i)
    	 {
         	zero[i] = intal2[j];
   		 }
   		  zero[i] = '\0';
   		 
   		 printf("zero   %s\n", zero);
    	 printf("intal1 %s\n", intal1);
   		 
    	
    	
    	//Perform compare on zero and intal1
    	
    	for(p = 0; p <= len_1 -1; p++)
   		{
   			if(*(intal1 + p) - '0' > *(zero + p) - '0')
   			{
   				//printf("%d > %d\n",*(intal1 + p) - '0',*(zero + p) - '0');
   				//printf("+1\n");
   				return 1;
   			}
   			else if(*(intal1 + p) - '0' < *(zero + p) - '0')
   			{
   				//printf("%d < %d\n",*(intal1 + p) - '0',*(zero + p) - '0');
   				//printf("-1\n");
   				return -1;
   			}
   			else
   			{
   				//printf("%d = %d\n",*(intal1 + p) - '0',*(zero + p) - '0');
   				
   			}
   			
   		}
   		//printf("0\n");
   		return 0;
   		//printf("0\n");
   		
    }
    
}


