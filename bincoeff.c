#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *intal_add(const char *intal1, const char *intal2);
char *intal_bincoeff(unsigned int n, unsigned int k);


int main()
{
	
    printf("%s\n",intal_bincoeff(10,8));

    return 0;

}



char *intal_bincoeff(unsigned int n, unsigned int k)
{
    char **c[n+1][k+1]= (char *)malloc(n*sizeof(char*));

    int i, j, min;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= min; j++)
        {
            if(j == 0 || j == i)
            {
                c[i][j] = "1";
            }
            else
            {
                c[i][j] =  intal_add(c[i-1][j-1], c[i-1][j]);
            }
            min = (i < k)? i: k;
            printf("%s\n",c[i][j]);
        }
    }

    return c[n][k];
}

char *intal_add(const char *intal1, const char *intal2)
{
    int len_1 = strlen(intal1);
    int len_2 = strlen(intal2);

    int diff_len = len_1 - len_2;

    if (diff_len < 0)
    {
        diff_len = diff_len * -1;
    }

    char *zero = malloc(sizeof(char) * (len_1 + len_2));

    int i;

    for (i = 0; i < diff_len; i++)
    {
        *(zero + i) = '0';
    }

    *(zero + i) = '\0';

    int x, y, res, carry;

    int p;

    char *sol = (char *)malloc(sizeof(char *) * 1000);

    carry = 0;

    if (len_1 < len_2)
    {
        int sol_index = 0;
        for (int j = 0; intal1[j] != '\0'; ++j, ++i)
        {
            *(zero + i) = intal1[j];
        }

        *(zero + i) = '\0';

        *(sol + len_2) = '\0';

        for (p = len_2 - 1; p >= 0; p--)
        {
            x = *(zero + p) - '0';
            y = intal2[p] - '0';

            res = x + y + carry;

            carry = res / 10;

            res = res % 10;

            *(sol + p + 1) = res + '0';
        }

        *(sol + p + 1) = carry + '0';
        *(sol + p) = '\0';
    }
    else
    {
        int sol_index = 0;

        for (int j = 0; intal2[j] != '\0'; ++j, ++i)
        {
            *(zero + i) = intal2[j];
        }
        *(zero + i) = '\0';

        *(sol + len_1) = '\0';

        for (p = len_1 - 1; p >= 0; p--)
        {
            x = *(zero + p) - '0';
            y = intal1[p] - '0';

            res = x + y + carry;

            carry = res / 10;

            res = res % 10;

            *(sol + p + 1) = res + '0';
        }

        *(sol + p + 1) = carry + '0';

        *(sol + p) = '\0';
    }

    while (*(sol + 0) == '0')
    {
        sol++;
    }
    free(zero);

    char *temp = malloc((strlen(sol) + 1) * sizeof(char));
    strcpy(temp, sol);

    return temp;
}

