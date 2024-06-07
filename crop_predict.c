#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nutrients
{
    float N,P,K,Atm_P,Soil_M,temp;
    char sol[100];
}Fact;
struct details
{
    Fact factors;
    struct details *link;
};
typedef struct details * SEED;
//function to allocate memory for nodes of linked list
SEED getdeatils()
{
    SEED x;
    x=(SEED)malloc(sizeof(struct details));
    if(x==NULL)
    {
        printf("Memory not available\n");
        exit(2);
    }
    return x;
}
int count(SEED root)
{
    //Function to count number of nodes in a linked list 
    int count=0;
    while(root!=NULL)
    {
        count++;
        root=root->link;
    }
    return count;
}
void print(Fact crop)
{
    //Function used to display the solution for the farmer
    printf("%s",crop.sol);
}
void solution(SEED root,Fact farm,int op)
{
    /*Function to compare the adjacent nodes of the user data which is closely related NPK data
    Which can be a solution for the farmer to decide what needs to be cultivated in his farmland*/ 
    SEED curr=root,pre = NULL,next;
    for(int i=0; i<count(curr); i++)
    {
        if(strcmp((curr->factors).sol,farm.sol)==0)
        break;
        pre=curr;
        curr=curr->link;
    }
    next=curr->link;
    if(next != NULL && pre!=NULL)
    {
        switch(op)
        {
            case 1:
            if((curr->factors).N -  (pre->factors).N > (next->factors).N - (curr->factors).N)
            print(next->factors);
            else
            print(pre->factors);
            break;
            case 2:
            if((curr->factors).P -  (pre->factors).P > (next->factors).P - (curr->factors).P)
            print(next->factors);
            else
            print(pre->factors);
            break;
            case 3:
            if((curr->factors).K -  (pre->factors).K > (next->factors).K - (curr->factors).K)
            print(next->factors);
            else
            print(pre->factors);
            break;
            case 4:
            if((curr->factors).Atm_P -  (pre->factors).Atm_P > (next->factors).Atm_P - (curr->factors).Atm_P)
            print(next->factors);
            else
            print(pre->factors);
            break;
            case 5:
            if((curr->factors).Soil_M -  (pre->factors).Soil_M > (next->factors).Soil_M - (curr->factors).Soil_M)
            print(next->factors);
            else
            print(pre->factors);
            break;
            case 6:
             if((curr->factors).temp -  (pre->factors).temp > (next->factors).temp - (curr->factors).temp)
            print(next->factors);
            else
            print(pre->factors);
            break;
            default:
            printf("Error  in giving solution\n");
            exit(4);
        }
    }
    else if(next==NULL)
    print(pre->factors);
    else if(pre==NULL)
    print(next->factors);
}
void sort_N(SEED root)
{
    //Function to sort the linked list based on Nitrogen content
    SEED icurr=root,jcurr;
    int n=count(root),i,j;
    for(i=0; i<n-1; i++)
    {
        jcurr=icurr->link;
        for(j=0; j<n-i-1; j++)
        {
            Fact temp;
            if((icurr->factors).N > (jcurr->factors).N)
            {
                temp=icurr->factors;
                icurr->factors=jcurr->factors;
                jcurr->factors=temp;
            }
            jcurr=jcurr->link;
        }
        icurr=icurr->link;
    }
}
void sort_P(SEED root)
{
    //Function to sort the linked list based on Phosphorous content
    SEED icurr=root,jcurr;
    int n=count(root),i,j;
    for(i=0; i<n-1; i++)
    {
        jcurr=icurr->link;
        for(j=0; j<n-i-1; j++)
        {
            Fact temp;
            if((icurr->factors).P > (jcurr->factors).P)
            {
                temp=icurr->factors;
                icurr->factors=jcurr->factors;
                jcurr->factors=temp;
            }
            jcurr=jcurr->link;
        }
        icurr=icurr->link;
    }
}
void sort_K(SEED root)
{
    //Function to sort the linked list based on Potassium content
    SEED icurr=root,jcurr;
    int n=count(root),i,j;
    for(i=0; i<n-1; i++)
    {
        jcurr=icurr->link;
        for(j=0; j<n-i-1; j++)
        {
            Fact temp;
            if((icurr->factors).K > (jcurr->factors).K)
            {
                temp=icurr->factors;
                icurr->factors=jcurr->factors;
                jcurr->factors=temp;
            }
            jcurr=jcurr->link;
        }
        icurr=icurr->link;
    }
}
void sort_Atm_P(SEED root)
{
    //Function to sort the linked list based on Atmospheric pressure content
    SEED icurr=root,jcurr;
    int n=count(root),i,j;
    for(i=0; i<n-1; i++)
    {
        jcurr=icurr->link;
        for(j=0; j<n-i-1; j++)
        {
            Fact temp;
            if((icurr->factors).Atm_P > (jcurr->factors).Atm_P)
            {
                temp=icurr->factors;
                icurr->factors=jcurr->factors;
                jcurr->factors=temp;
            }
            jcurr=jcurr->link;
        }
        icurr=icurr->link;
    }
}
void sort_Soil_M(SEED root)
{
    //Function to sort the linked list based on Soil moisture content
    SEED icurr=root,jcurr;
    int n=count(root),i,j;
    for(i=0; i<n-1; i++)
    {
        jcurr=icurr->link;
        for(j=0; j<n-i-1; j++)
        {
            Fact temp;
            if((icurr->factors).Soil_M > (jcurr->factors).Soil_M)
            {
                temp=icurr->factors;
                icurr->factors=jcurr->factors;
                jcurr->factors=temp;
            }
            jcurr=jcurr->link;
        }
        icurr=icurr->link;
    }
}
void sort_temp(SEED root)
{
    //Function to sort the linked list based on Temperature in the agricultural land
    SEED icurr=root,jcurr;
    int n=count(root),i,j;
    for(i=0; i<n-1; i++)
    {
        jcurr=icurr->link;
        for(j=0; j<n-i-1; j++)
        {
            Fact temp;
            if((icurr->factors).temp > (jcurr->factors).temp)
            {
                temp=icurr->factors;
                icurr->factors=jcurr->factors;
                jcurr->factors=temp;
            }
            jcurr=jcurr->link;
        }
        icurr=icurr->link;
    }
}

SEED insert(SEED root,Fact plant)
{
    //Function to insert nodes in linked list
    SEED temp;
    temp=getdeatils();
    temp->factors=plant;
    temp->link=NULL;
    if(root==NULL)
    return temp;
    SEED curr=root;
    while(curr->link!=NULL)
    curr=curr->link;
    curr->link=temp;
    return root;
}
SEED delete(SEED root)
{
    //Function to delete node in the linked list
    if(root==NULL)
    {
        printf("Deletion not possible\n");
        return NULL;
    }
    SEED curr=root->link;
    free(root);
    return curr;
}

int main()
{
    SEED root;
    root = NULL;
    Fact plant,farm;
    int op;
    FILE *fp;
    //Opening a file which has the data of NPK values and it's corresponding crop to be grown
    fp=fopen("Details.txt","r");
    if(fp==NULL)
    {
        printf("Error in opening a file\n");
        exit(1);
    }
    //Reading data from the file till it reach end of file
    while(fscanf(fp," %[^,], %f, %f, %f, %f, %f,%f\n",plant.sol,&plant.N,&plant.P,&plant.K,&plant.Atm_P,&plant.Soil_M,&plant.temp)==7)
    {
        root=insert(root,plant);
    }
    root=delete(root);
    //display(root);
    //Taking input from the sensors to feed in and get the output crop to be grown
    printf("Enter the N,P,K,Atmosphere pressure,Soil moisture and temperature of your land\n");
    scanf("%f%f%f%f%f%f",&farm.N,&farm.P,&farm.K,&farm.Atm_P,&farm.Soil_M,&farm.temp);
    strcpy(farm.sol,"Problem");
    root=insert(root,farm);
    printf("Enter your primary key to sort\n");
    printf("1: Based on Nitrogen content in soil\n");
    printf("2: Based on Phosphorous content in soil\n");
    printf("3: Based on Potassium content in soil\n");
    printf("4: Based on Atmosphere pressure in the region\n");
    printf("5: Based on Soil moisture in the region\n");
    printf("6: Based on the temperature in the region\n");
    //Primary key is to select crop based on which content needs to increased in land so that, it doesn't lose fertility
    scanf("%d",&op);
    switch(op)
    {
        case 1:
        sort_N(root);
        break;
        case 2:
        sort_P(root);
        break;
        case 3:
        sort_K(root);
        break;
        case 4:
        sort_Atm_P(root);
        break;
        case 5:
        sort_Soil_M(root);
        break;
        case 6:
        sort_temp(root);
        break;
        default:
        printf("Invalid option\n");
        exit(3);
    }
    //display(root);
    printf("\a");
    solution(root,farm,op);
    printf("\n");
    fclose(fp);
    char feedback[100],soln[100];
    printf("\nFeed back regarding the solution\n");
    printf("Your feedback is very precious to us, as you are the one to have practical knowledge and our data is bassed on the scientific calculations collaging all together will be a accurate solution\n");
    scanf(" %[^\n]",feedback);
    printf("This section is to get the solution you may be come up with the situation to resolve this problem\n");
    printf("Here you can share\n It will help to the farmers who are in need of your expertise and your experiential words\n");
    scanf(" %[^\n]",soln);
    strcpy(farm.sol,soln);
    FILE *f;
    f=fopen("Solution.txt","w+");
    if(f==NULL)
    {
        printf("Error in opening a file\n");
        exit(1);
    }
    fprintf(f,soln);
    fclose(f);
    return 0;
}
