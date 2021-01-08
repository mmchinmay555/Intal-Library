#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intal_mod(const char *a,const char *b);
int intal_compare(const char* intal1, const char* intal2);
char* intal_diff(const char* intal1, const char* intal2);

char* intal_pow(const char* intal1, unsigned int n);

static int bigger(const char *a,const char *b);
char* intal_multiply(const char* intal1, const char* intal2);
static char *copy(const char *a);
char* intal_gcd(const char* intal1, const char* intal2);


int main()
{
    const char intal_1[1000] = "2";
    //const char intal_2[1000] = "3990";
    
   	printf("POW %s\n",intal_pow(intal_1,3 ));

}



char* intal_pow(const char* intal1, unsigned int n)
{
	
	char *temp = (char*)malloc(sizeof(char*) * 1000);
		
	if(n == 0)
	{
		strcpy(temp, "1");
		return temp;
	}
		
	else if(n == 1)
	{
		strcpy(temp, intal1);
		return temp;
	}
	
	strcpy(temp, intal1);

	while(n != 1)
	{
		
		n--;
		
		strcpy(temp, intal_multiply(temp,intal1));	
		
	}
	
	return temp;
}

char* intal_multiply(const char* intal1, const char* intal2){
 
	if(intal1[0]==48||intal2[0]==48){
	 
	char *res=(char*)malloc(sizeof(char)*2);
	 
	res[0]=48;
	 
	res[1]='\0';
	 
	return res;}
	 
	int a=strlen(intal1);
	 
	int b=strlen(intal2);
 
    char *result = malloc(sizeof(char)*(a+b+2));  
 
    int i_n1 = 0;  
 
    int i_n2 = 0;  
 
    int i;
 
    for(int i=0;i<a+b+2;i++){
 
        result[i]=48;}
 
    for (i = a - 1; i >= 0; i--)  
 
    {  
 
        int carry = 0;  
 
        int n1 = intal1[i] - '0';
 
        i_n2 = 0;            
 
        for (int j = b - 1; j >= 0; j--)  
 
        {  
 
            int n2 = intal2[j] - '0';  
 
  
 
            int sum = n1 * n2 + (result[i_n1 + i_n2]-'0') + carry;  
 
            carry = sum / 10;  
 
            result[i_n1 + i_n2] = 48+(sum % 10);  
 
  
 
            i_n2++;  
 
        }  
 
  
 
        if (carry > 0)  
 
            result[i_n1 + i_n2] = 48+result[i_n1+i_n2]-'0'+carry;  
 
  
 
        i_n1++;  
 
    }
 
	int v=i_n1+i_n2;
	 
	v--;
	 
	while(result[v]==48)
	{
	 
		v--;
	}
 
 
    result[v+1]='\0';
 

 	int n = strlen(result); 
 
    for (int i = 0; i < n / 2; i++) {
 
        char b = result[i];
 
		result[i] = result[n-i-1];
	 
		result[n-i-1] = b;
 
	} 
 
    return result;
        
}	
static int bigger(const char *a,const char *b)
{
 
	for(int i=0;i<strlen(b);i++)
	{
		if(b[i]>a[i])
		{
			return 0;
		}
		 
		else if(a[i]>b[i])
		{
			return 1;
		}
 
	}
}

static char *copy(const char *a)
{
 
    int b=strlen(a);
 
    char *p=malloc(sizeof(char)*(b+1));
 
    for(int i=0;i<=b;i++){
 
        p[i]=a[i];
 
    }
 
    return p;
 
}

char* intal_diff(const char* intal1, const char* intal2)
{
	int check = intal_compare(intal1, intal2);
	char* sol = malloc(sizeof(char*) * 1000);
	
	if(check == 1)
	{
		//intal1 - intal2
		
		//-----------------------------------------------------------------------------------------
		
		
	    int len_1 = strlen(intal1);
		int len_2 = strlen(intal2);

	   
		int diff_len = len_1 - len_2;

		

		if(diff_len < 0)
		{
		    diff_len = diff_len * -1;
		    
		}
	

		////printf("DIFF in len %d\n", diff_len);
		char zero[len_1+len_2];

		int i;
		for(i=0;i<diff_len;i++)
		{
		    zero[i] = '0';
		}
	   
	   	zero[i] = '\0';	
	   	
		int sol_index = 0;	
    	
    	
        for (int j = 0; intal2[j] != '\0'; ++j, ++i)
        {
        	zero[i] = intal2[j];
   		}
   		 		
	   
	   	zero[i] = '\0';	
	   		
	   	//printf("intal1 %s - ",intal1); 
	   	//printf("intal2 %s\n",zero);
		
		//-----------------------------------------------------------------------------------------
		*(sol + strlen(zero)) = '\0';
		int B =0;
		int res;
		int p;
		
		for(p = strlen(zero)-1; p >= 0; p--)
   		{
   			int x = intal1	[p] - '0';
   			int y = zero[p] - '0';
   		   			
   			int res = (x - B) - y;
   			
   			if(res < 0)
   			{
   				res = res + 10;
   				B = 1;
   			}
   			else
   			{
   				B = 0;
   			}
   			//printf("res %d\n",res);
   			*(sol + p) = res + '0';
   			
   		}
   		
   		//printf("res %d\n",res);
		//printf("sol %s\n",sol);
		
		
		
	}
	
	else if(check == -1)
	{
		//intal2 - intal1
		
		//-----------------------------------------------------------------------------------------
		
		
	    int len_1 = strlen(intal1);
		int len_2 = strlen(intal2);

	   
		int diff_len = len_1 - len_2;

		

		if(diff_len < 0)
		{
		    diff_len = diff_len * -1;
		}
		

		//printf("DIFF in len %d\n", diff_len);
		char zero[len_1+len_2];

		int i;
		for(i=0;i<diff_len;i++)
		{
		    zero[i] = '0';
		}
	 	
	 	zero[i] = '\0';	
	 		
	 	int sol_index = 0;	
    	
    	
        for (int j = 0; intal1[j] != '\0'; ++j, ++i)
        {
        	zero[i] = intal1[j];
   		}
   		 		
	   
	   	zero[i] = '\0';	
	   	
	   	
		//printf("intal2 %s - ",intal2); 
		//printf("intal1 %s\n",zero);
		
		
		//-----------------------------------------------------------------------------------------
		
		*(sol + strlen(zero)) = '\0';
		
		int B =0;
		int res;
		
		int p;
		
		for(p = strlen(zero) -1; p >= 0; p--)
   		{
   			int x = intal2[p] - '0';
   			int y = zero[p] - '0';
   		   			
   			int res = (x - B) - y;
   			
   			if(res < 0)
   			{
   				res = res + 10;
   				B = 1;
   			}
   			else
   			{
   				B = 0;
   			}
   			//printf("res %d\n",res);
   			*(sol + p) = res + '0';
   			
   		}
   		
   		//printf("res %d\n",res);
		//printf("sol %s\n",sol);
		
		
			
	}
	else
	{
		//intal1 == intal2
		
		//printf("0\n");
		return "0";	
	}
	 while(*(sol + 0) == '0')
    {
    	sol++;
    }
	return sol;
}	

int intal_compare(const char* intal1, const char* intal2)
{   
    int len_1 = strlen(intal1);
    int len_2 = strlen(intal2);

   
    int diff_len = len_1 - len_2;

    

    if(diff_len < 0)
    {
        diff_len = diff_len * -1;
        char sol[len_2];
    }
    
    char* sol = malloc(sizeof(char*) * 1000);

    //printf("DIFF in len %d\n", diff_len);
    char zero[len_1+len_2];

    int i;
    for(i=0;i<diff_len;i++)
    {
        zero[i] = '0';
    }
   
   	zero[i] = '\0';	
   	
    //printf("%s\n", zero);
   // printf("%d\n",i);
    
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
   		 
   		 //printf("zero   %s\n", zero);
    	 //printf("intal2 %s\n", intal2);
   		 
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
   		 
   		 //printf("zero   %s\n", zero);
    	 //printf("intal1 %s\n", intal1);
   		 
    	
    	
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
   		printf("0\n");
   		return 0;
   		//printf("0\n");
   		
    }
    
}



	
char* intal_mod(const char *intal1, const char *intal2)
{
 
 	char *temp = (char*)malloc(sizeof(char*) * 1000);
	
	if(intal_compare(intal1,intal2)==-1)
	{
		strcpy(temp,intal1);
		return temp;
	}
	
	 
	int diff_len = strlen(intal1) - strlen(intal2);
	 
	int r =  (intal_compare(intal2,intal1)==1)?0:1;
	
	
	 
	diff_len -= r;
	
	 
	if(diff_len > 0)
	{
	 
		char *temp_str = malloc(sizeof(char)*(strlen(intal2)+diff_len + 1));
		 
		for(int i=0;i<strlen(intal2);i++){
		 
			temp_str[i]=intal2[i];}
		 
		int m = strlen(intal2);
		
		 
		for(int i=0;i<diff_len;i++)
		{
			temp_str[i+m]=48;
		}
		 
		
		temp_str[diff_len+m]='\0';
		 
		temp_str = intal_diff(intal1, temp_str);
		 
		return intal_mod(temp_str,intal2);
		
	}
	 
	return intal_mod(intal_diff(intal1,intal2),intal2);
	 
}
