#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// #include<C:\code\C Project\project.c>
struct detail{
    int p,n,k,atm_p,temp;
    char region[15];
    char name[25];
};
struct list{
    struct detail d;  
    struct list* link;
};

int count(struct list* root)
{
    int count=0;
    while(root!=NULL)
    {
        count++;
        root=root->link;
    }
    return count;
}
void display(struct list* l){
    printf("P\tN\tK\tATM\tTemp\n");
    while(l!=NULL){
        printf("%d\t%d\t%d\t%d\t%d\n",l->d.p,l->d.n,l->d.k,l->d.atm_p,l->d.temp);
        l=l->link;
    }
}
float euclidean_distance(struct list* curr,int n,int p,int k,int atm_p,int temp)
{
    return (float)sqrt(pow(curr->d.p-p,2)+pow(curr->d.n-n,2)+pow(curr->d.k-k,2)+pow(curr->d.atm_p-atm_p,2)+pow(curr->d.temp-temp,2));
}
void show(struct detail d){
    printf("%d\t%d\t%d\t%d\t%d\n",d.n,d.p,d.k,d.atm_p,d.temp);
}


struct list* sort(float* dist,struct list* l,int n){
    struct list* cur=l;
    for(int i=0; i<n-1; i++){
        struct list* cur2=cur;
        for(int j=i+1; j<n; j++){
            struct list* next=cur2->link;
            if(dist[j]>dist[j+1] && next!=NULL){
                float temp=dist[j];
                dist[i]=dist[j+1];
                dist[j+1]=temp;
                struct detail dummy=cur2->d;
                cur2->d=next->d;
                next->d=dummy;
            }
            cur2=cur2->link;
        }
        cur=cur->link;
    }
    return l;
}

struct list* form_matrix(struct list* param1,int n,int p,int k,int atm_p,int temp){
    int num=count(param1),i=0;
    float *dist;
    dist=(float *)malloc(n*sizeof(float));
    struct list * result;
    while(param1!=NULL){
        dist[i]=euclidean_distance(param1,n,p,k,atm_p,temp);
        param1=param1->link;
        i++;
    }
    // for(int i=0; i<num; i++)printf("%f\t",dist[i]);
    // printf("\n");
    param1=sort(dist,param1,num);
    return param1;
}

struct list* getNode(){
    struct list* x;
    x=(struct list*)malloc(sizeof(struct list));
    if(x==NULL)
    {
        printf("Memory not available\n");
        exit(2);
    }
    return x;
}
struct list* insertList(struct list* l,struct detail d){
    struct list* temp=getNode(),*cur=l;
    temp->d=d;
    temp->link=NULL;
    if(l==NULL)return temp;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=temp;
    return l;
}
int main(){
    struct list* l=NULL;
    int t,n,p,k,atm_p,temp;
    FILE *fp;
    fp=fopen("data.txt","r");
    if(fp==NULL)
    {
        printf("Error in opening a file\n");
        exit(1);
    }
    struct detail d;
    while(fscanf(fp,"%d, %d, %d, %d, %d\n",&d.n,&d.p,&d.k,&d.atm_p,&d.temp)==5)
    {
        l=insertList(l,d);
    }
    display(l);
    printf("Enter the test instance NPK values\n");
    scanf("%d%d%d%d%d",&n,&p,&k,&atm_p,&temp);
    l=form_matrix(l,n,p,k,atm_p,temp);
    display(l);
    return 0;
}
