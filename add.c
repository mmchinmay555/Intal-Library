#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* intal_add(const char *intal1, const char * intal2);

int main()
{
    const char intal_1[1000] = "00";
    const char intal_2[1000] = "0000";
    
    printf("sol recieved %s\n",intal_add(intal_1, intal_2));

}

char* intal_add(const char* intal1, const char* intal2)
{   
    int len_1 = strlen(intal1);
    int len_2 = strlen(intal2);

   
    int diff_len = len_1 - len_2;

    

    if(diff_len < 0)
    {
        diff_len = diff_len * -1;
    }

    //printf("DIFF in len %d\n", diff_len);
    char * zero = malloc(sizeof(char) * (len_1 + len_2));
    int i;
    for(i=0;i<diff_len;i++)
    {
        *(zero + i) = '0';
    }
   
   	*(zero + i) = '\0';	
   	
    //printf("%s\n", zero);
    //printf("%d\n",i);
    
    int x, y, res, carry;
    
    int p;
    char* sol = (char *)malloc(sizeof(char*) * 1000);
    
    carry = 0;
    
    if(len_1 < len_2)
    {
    	 int sol_index = 0;
    	 for (int j = 0; intal1[j] != '\0'; ++j, ++i)
    	 {
         	*(zero + i) = intal1[j];
   		 }
   		 
   		*(zero + i) = '\0';
   		 
   		 //printf("%s\n", zero);
    	 //printf("%s\n", intal2);
   		 
   		//Perform addition on zero and intal2
   		
   		*(sol+len_2) = '\0';
   		for(p = len_2 -1; p >= 0; p--)
   		{
   			x = *(zero + p) - '0';
   			y = intal2[p] - '0';
   			
   			res = x + y  + carry;
   			
   			carry = res / 10; 
   			
   			res = res % 10;
   			//printf("Store %d, Carry %d\n",res, carry);
   			*(sol + p + 1)  = 	res + '0';
   			
   			
   		}
   		
   		*(sol + p+1) = carry + '0';
   		*(sol+ p) = '\0';
   		
   		//printf("%s\n",sol);
   		
    }
    else
    {
    	int sol_index = 0;
    	 for (int j = 0; intal2[j] != '\0'; ++j, ++i)
    	 {
         	*(zero + i) = intal2[j];
   		 }
   		  *(zero + i) = '\0';
   		 
    	
    	//Perform addition on zero and intal1
    	*(sol+len_1) = '\0';

    	for(p = len_1 -1; p >= 0; p--)
   		{
   			x = *(zero + p) - '0';
   			y = intal1[p] - '0';
   			
   			res = x + y  + carry;
   			
   			carry = res / 10; 
   			
   			res = res % 10;

   			*(sol+p+1)  = 	res  + '0';
   			
   			
   			//printf("Store %d, Carry %d\n",res, carry)	;
   			
   		}
   		
   		*(sol+p+1) = carry + '0';
   		*(sol+p) = '\0';
   		
   		//printf("%s\n",sol);
   	
    }
    
    while(*(sol + 0) == '0'&& *(sol + 1) != '\0')
    {
    	sol++;
    }
    
    return  sol;
    
}
