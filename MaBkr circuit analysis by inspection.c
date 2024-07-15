//Mohamed Bakr
// Analysis by inspection project
#include<stdio.h>
#include<math.h>
float determinant(float [][25], float);
void cofactor(float [][25], float, char t);
void transpose(float [][25], float [][25], float, char t);
int main()
{
  float array[25][25], d;
	int n;
	int i;
	int temo;
	int j =1;
	int nr1;
	float sumr1 = 0;
	float r1;
	float g1;
	int h;
	float rc1;
	char t;
	char desc = 'c';
	while ((desc == 'c' || desc == 'C'))
	{
	printf("Enter [C] if you have all current sources and [V] if you have all voltage sources\n if you have a mix of both in the circuit,");
	printf("convert all of them to one type\n");
		scanf("%c",&t);
while ((t!= 'c' && t!= 'C') &&(t!= 'V' && t!= 'v'))
{ 
printf("Error : Enter [C] or [V] only\n" );
	scanf("%c",&t);
	}
	
	if (t == 'C' || t == 'c'){
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	for(i=0; i<n; j++)
	{
		printf("Enter the number of resistors connected to the node number [%d] \n",j);
	scanf("%d",&nr1);
	for (h=1; h<=nr1; h++)
	{
			printf("Enter the value of resistor number [%d] connected to the node number [%d] \n",h,j);

		scanf("%f",&r1);
		sumr1 = sumr1 + (1/ r1);
		}
				g1 = sumr1;
		sumr1 = 0;
		array[i][i] = g1;
		i=i+1;
		g1 = 0;
		}
	
		for(int l=0; l<n ; l++)
		{ 
			for(int s=0; s<=l ; s++)
			{
				if ( s==l)
				continue;
				if (s<l)
				{
				
			printf("Enter the value of resistor connected between the node number [%d] and node number [%d] \n",(l+1),(s+1));

		scanf("%f",&rc1);
		if (rc1 == 0)
{	array[l][s] = 0;
		array [s][l] = 0;}
		else {
				array[l][s] = -1/rc1;
		array [s][l] = -1/rc1;}
		}
					}
	}
	
	   printf("\n the Inspection matrix >>>>> \n\n");

	for (i =0 ; i < n ; i ++)
		{
		
		for (j =0 ; j< n ; j++)
		{
	printf ("%f   ", array[i][j]);
	}
		
		
	printf("\n");
	}
  d = determinant(array, n);
  if (d == 0)
   printf("\Error\n");
  else
   cofactor(array, n, t);
}
else if (t == 'v' || t == 'V')
{	printf("Enter the number of Loops\n");
	scanf("%d",&n);
	for(i=0; i<n; j++)
	{
		printf("Enter the number of resistors connected inside the loop number [%d] \n",j);
	scanf("%d",&nr1);
	for (h=1; h<=nr1; h++)
	{
			printf("Enter the value of resistor number [%d] connected in the loop number [%d] \n",h,j);

		scanf("%f",&r1);
		sumr1 = sumr1 +  r1;
		}
				g1 = sumr1;
		sumr1 = 0;
		array[i][i] = g1;
		i=i+1;
		g1 = 0;
		}
	
		for(int l=0; l<n ; l++)
		{ 
			for(int s=0; s<=l ; s++)
			{
				if ( s==l)
				continue;
				if (s<l)
				{
				
			printf("Enter the value of resistors in common between the loop number [%d] and loop number [%d] \n",(l+1),(s+1));

		scanf("%f",&rc1);
		if (rc1 == 0)
{	array[l][s] = 0;
		array [s][l] = 0;}
		else {
				array[l][s] = -rc1;
		array [s][l] = -rc1;}
		}
					}
	}
	
	   printf("\n the Inspection matrix >>>>> \n\n");

	for (i =0 ; i < n ; i ++)
		{
		
		for (j =0 ; j< n ; j++)
		{
	printf ("%f   ", array[i][j]);
	}
		
		
	printf("\n");
	}
  d = determinant(array, n);
  if (d == 0)
   printf("\Error\n");
  else
   cofactor(array, n, t);}
   //desc = 'e';
    printf("\nPress any key if you want to esxit the program\n\n");
    scanf("%c", &desc);
        scanf("%d", &temo);

}
    
}
 
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 
void cofactor(float num[25][25], float f, char t)
{
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f, t);
}
void transpose(float num[25][25], float fac[25][25], float r,char t)
{
	if (t == 'V' || t == 'v')
	{
		 int i, j;
  float b[25][25], inverse[25][25], aric[25], result[25], d;
 
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }

      int nrcc1;
    float v1;
    float sumrcc1 =0;
    int z = 1;
    for(int lw=0; lw<r; z++)
   
	{
		printf("Enter the number of voltage sources connected inside the loop number [%d] \n",z);
	scanf("%d",&nrcc1);
	if (nrcc1 == 0 )
	aric[lw] = 0;
	else {
	for (int as=1; as<=nrcc1; as++)
	{
			printf("Enter the value of the voltage source number [%d] connected inside the loop number [%d] \n {+} if the assumed current in the loop passes into the [+] terminal of the battery\n and {-} if the assumed current in the loop passes into the [-] terminal of the battery \n",as,z);

		scanf("%f",&v1);
		sumrcc1 = sumrcc1 -  v1;
		
		}
		aric[lw] = sumrcc1;
		sumrcc1 = 0;
		v1 = 0;
				}
		lw=lw+1;

	}
		for (int cu = 0; cu < r; ++cu) {
         for (int k = 0; k < r; ++k) {
            result[cu] += inverse[cu][k] * aric[k];
         }
 
   }

   for (i = 0;i < r; i++)
    {
		   printf("\nThe current passing in the loop number [%d]  is : \n", (i+1));

         printf("\t%f", result[i]); 
    printf("\n");
     }
   
 
  
		
		}
	
	
	else if (t == 'C' || t == 'c')
	{
		 int i, j;
  float b[25][25], inverse[25][25], aric[25], result[25], d;
 
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
 
      int nrcc1;
    float v1;
    float sumrcc1 =0;
    int z = 1;
    for(int lw=0; lw<r; z++)
   
	{
		printf("Enter the number of current sources connected to the node number [%d] \n",z);
	scanf("%d",&nrcc1);
	if (nrcc1 == 0 )
	aric[lw] = 0;
	else {
	for (int as=1; as<=nrcc1; as++)
	{
			printf("Enter the value of the current source number [%d] connected directrly to the node number [%d] \n {+} for current in and {-} for current out \n",as,z);

		scanf("%f",&v1);
		sumrcc1 = sumrcc1 +  v1;
		
		}
		aric[lw] = sumrcc1;
		sumrcc1 = 0;
		v1 = 0;
				}
		lw=lw+1;

	}
		for (int cu = 0; cu < r; ++cu) {
         for (int k = 0; k < r; ++k) {
            result[cu] += inverse[cu][k] * aric[k];
         }

   }


   for (i = 0;i < r; i++)
    {
		   printf("\nThe volatage on the node number [%d]  is : \n", (i+1));

         printf("\t%f", result[i]); 
    printf("\n");
     }
   
  
   }
 
}


