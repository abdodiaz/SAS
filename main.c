#include <stdio.h>
#include <stdlib.h>
#define max 50

// les structure

struct president
{
    char name[max];
    int vote[max];

}president1;

struct electeur
{
    int CIN[max];
};
//declaration object G

	struct electeur *rprme;
	struct president *rprme1;
	struct president *vot;
	struct president *getpr;


//nombre de presedent
int PresidentNumber()
{
	int n;
	do{
        printf("Enter the Number of President :");
        scanf("%d",&n);
    }while(n < 5);
    return n;
}

//nombre de electeur
int ElecteurNumber()
{
	int m;
	do{
        printf("Enter the Number of Electeur  :");
        scanf("%d",&m);
    }while(m < 10);
    return m;
}

// insertion de presedent
struct president *getPresidents(int n)
{
	int i;

	getpr = (struct president*)malloc(n * sizeof(struct president));
    for(i = 0;i < n;i++)
    {
    		printf("\nEntre the name of president :");
            scanf(" %[^\n]%*c",&getpr[i].name);
    }
    rprme1 = getpr;
}



//afficher les presedent
void printPresident(int n)
{
	printf("\nPresident       Full Name \n");
	for(int i = 0;i < n;i++)
    {
        printf("%d President --> %s\n",i + 1,rprme1[i].name);
    }
}


//inserer les electeur
struct electeur *getElcteurs(int m)
{
	struct electeur *elc;
	int i;

	elc = (struct electeur*)malloc(m * sizeof(struct electeur));
	printf("\n\t\tEnter The CIN \n");
    for(i = 0;i < m;i++)
    {
    	printf("\nEnter the CIN of the %d President : ",i+1);
        scanf("%d",&elc[i].CIN);
    }
    rprme =elc;
    return elc;
}


//aficher les electeur
void	printElecteur(int m)
{
	for(int i = 0;i < m;i++)
    {
        printf("%d Electeur ---> %d \n",i + 1,*rprme[i].CIN);
    }
}

//vote
struct president vote(int n,int m)
{
	struct president vt[max],vtR[max];
    struct electeur *elc;
    elc = rprme ;
    //inicial vote
	int i,j;
	for(i = 0; i < n;i++)
    {
        *vt[i].vote = 0;
    }
    //get vote
	for ( i = 0; i < m;i++)
    {
		do
        {
            printf("\n%d vote :",*elc[i].CIN);
            scanf("%d",&vtR[i].vote);
        }while(*vtR[i].vote > n || *vtR[i].vote < 0 );
        for ( j = 0; j< n;j++)
        {
            if (*vtR[i].vote == j+1)
                    *vt[j].vote = (*(vt[j].vote) + 1);
        }
    }
    vot = vt;
}


// 1�re etape
void	firstPeriod(int n,int m)
{

	struct president *vt;
    int i,j,array[max],index[max],e,f;

    prem:
	printf("\n\tThe First Vote : \n");
	vote(n,m);
    printf("\n\n");
    j = 0;
    f=0;
    e=*vot[0].vote *(100/m);
    //repet
    for(i=1;i<n;i++)
    {
        if(e==*vot[i].vote *(100/m))
        {
            f++;
        }
        else
        {
            f--;
        }

    }
    if(f==n-1)
    {
        goto prem;
    }
    printf("\n the result of votes \n\n");
    //
	for (i = 0;i < n;i++)
    {
        if (*vot[i].vote *(100/m) > 15)
        {
            array[i] = *vot[i].vote * (100/m);
            index[i] = i + 1;
            printf("%d president and %d vote\n",index[i],array[i]);

		}
    }

}

//2�me etape
void	secondPeriod(int n,int m)
{
	struct president vt[max],vtR[max];
    struct electeur *elc;
    int array1[max]={0},index[max];
	elc = rprme ;
	int count,i,j,l = 0;
    int min;

	printf("\n\tThe Second vote\n");
	two:
	vote(n,m);

    j = 0;
    count = 0;
    for (i = 0;i < n;i++)
    {
        if (*vot[i].vote * (100/m) != 0)
        {
            array1[j] = *vot[i].vote * (100/m);
            index[j] = i + 1;
			j++;
            count++;
        }
    }
   	min = array1[0];
    for (i = 0;i < n;i++)
    {
        if (index[i] != 0)
        {
            for (j = 0; j < count;j++)
            {
            	 if (array1[j] < min )
                    min = array1[j];
            }

        }
    }
    int ct = 0;
    for (j = 1; j < n;j++)
		{
			if (index[j] != 0 && min == array1[j])
			{
				ct++;
			}
		}

		for (j = 1; j < n;j++)
		{
			if (index[j] != 0 && min == array1[j] && ct >= 2)
			{
				l = 1;
				printf("\n\t try vote again\n");
				for (int d = 0;d < n;d++)
			    {
			            *vot[d].vote = 0;
			            array1[d] = 0;
			            index[d] = 0;
			    }

			}
		}

	while(l == 1)
	{
		l = 0;
		goto two;
	}

	printf("\n the result of votes \n\n");
	for (i = 0;i < n;i++)
	{
		if (index[i] != 0 &&  array1[i] != 0 && array1[i] != min)
			printf("president %d and vote (%d) \n",index[i],array1[i]);
	}

}

// 3eme etape
void	thirdPeriod(int n,int m)
{
	int i,j,winner,d = 0,l = 0;
	int array[max] = {0},index[max] = {0};

	printf("\n\t the Third votes : \n");
	one:
	vote(n,m);

    for (i = 0;i < n;i++)
    {
            array[i] = *vot[i].vote * (100/m);
            index[i] = i + 1;
    }


	int Max = array[0];
	for (i = 0;i < n;i++)
	{
		for ( j = 0;j < n;j++)
		{
			if (Max < array[j])
			{
				Max = array[j];
			}
		}
	}

		int ct = 0;
    	for (j = 1; j < n;j++)
		{
			if (index[j] != 0 && Max == array[j])
			{
				ct++;
			}
		}
		for (j = 1; j < n;j++)
		{
			if (index[j] != 0 && Max == array[j] && ct >= 2)
			{
				l = 1;
				printf("\n\t try vote again\n");
				for (d = 0;d < n;d++)
			    {

			            *vot[d].vote = 0;
			            index[d] = 0;
			    }

			}
		}

	while(l == 1)
	{
		l = 0;
		goto one;
	}

		printf("\n the result of votes \n\n");
	for (i = 0;i < n;i++)
	{
		if (index[i] != 0 &&  array[i] != 0 && array[i] != max)
			printf("president %d and vote (%d) \n",index[i],array[i]);
	}

    for (i = 0; i < n; i++)
    {
        if (index[i] != 0 &&  array[i] != 0 )
        {
        	winner =  array[i];
        }

    }



        	for (j = 0; j < n; j++)
        	{
        		if (winner < array[j] && index[j] != 0)
				{
					 winner = array[j];

				}
			}


			for (j = 0;j < n;j++)
			{
				if (winner == array[j])
					printf("\nThe president  %d %s is the winner with (%d) votes \n",index[j],rprme1[j].name,array[j]);
			}

}





int main()
{
    int n,m;

	// nombre de presedent et electeur
	n = PresidentNumber();
	m = ElecteurNumber();
	// inserer les presedent
	getPresidents(n);
	// afficher les presedent
	printPresident(n);
    // inserer les electeur
	getElcteurs(m);
	// afficher les presedent
	printElecteur(m);

    system("cls");
    printPresident(n);

	// 1ere periode
	firstPeriod(n,m);

   	//2eme periode
   	secondPeriod(n,m);

	//2eme periode
    thirdPeriod(n,m);

	return 0;
}
