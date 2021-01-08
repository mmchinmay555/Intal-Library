#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int intal_max(char **arr, int n);
int intal_min(char **arr, int n);

int intal_search(char **arr, int n, char *key);

int intal_compare(const char *intal1, const char * intal2);


int main()
{
	char *arr [1000] = {"123", "765", "543", "2", "23", "543", "765", "2"};
	
	printf("Max %d\n",intal_max(arr, 8));
	
	printf("Min %d\n",intal_min(arr, 8)); 
	
	printf("Index %d\n",intal_search(arr, 8, "2"));
}
	
	
int intal_search(char **arr, int n, char *key)
{

    int index = -1;

    for (int i = 0; i < n; i++)
    {

        if (intal_compare(arr[i], key) == 0)
        {

            index = i;

            return index;
        }
    }

    return index;
}


int intal_max(char **arr, int n)
{
	char temp[1000]; 
	
	strcpy(temp, arr[0]);
	
	int max_index = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(intal_compare(arr[i], temp) == 1 )
		{
			//arr[i] > tem
			
			strcpy(temp, arr[i]);
			
			max_index = i;
			
		}
		//printf("%s\n",arr[i]);
	}
	
	return max_index;
	
}

int intal_min(char **arr, int n)
{
	char temp[1000]; 
	
	strcpy(temp, arr[0]);
	
	int min_index = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(intal_compare(arr[i], temp) == -1 )
		{
			//arr[i] > tem
			
			strcpy(temp, arr[i]);
			
			min_index = i;
			
		}
		//printf("%s\n",arr[i]);
	}
	
	return min_index;
	
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

    //printf("DIFF in len %d\n", diff_len);
    char zero[len_1+len_2];

    int i;
    for(i=0;i<diff_len;i++)
    {
        zero[i] = '0';
    }
   
   	zero[i] = '\0';	
   	
    //printf("%s\n", zero);
    //printf("%d\n",i);
    
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
   		//printf("0\n");
   		return 0;
   		//printf("0\n");
   		
    }
    
}

