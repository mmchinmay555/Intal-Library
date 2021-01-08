#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intal_multiply(const char* intal1, const char* intal2);
char* intal_add(const char* intal1, const char* intal2);
char* intal_diff(const char* intal1, const char* intal2);
int intal_compare(const char *intal1, const char * intal2);

	
static void reverseStr(char *a) 
 
{ 
 
    int n = strlen(a); 
 
    for (int i = 0; i < n / 2; i++) {
 
        char b=a[i];
 
    a[i]=a[n-i-1];
 
    a[n-i-1]=b;
 
	} 
}

int main()
{
    const char intal_1[1000] = "999999999";
    const char intal_2[1000] = "999999999";
    
   	printf("%s\n",intal_multiply(intal_1,intal_2));

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

    
