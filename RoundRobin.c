#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int id,at,bt,tat,wt;

}process;
process p[10];
int q[15],F=-1,R=-1;

void insert(int p){
    if(F==-1){
        F=F+1;
    }
    R=R+1;
    q[R]=p;
}

int delete(void){
    int p;
    p=q[F];
    F=F+1;
    return p;
}


int main(){
    int i,j,s,time=0,n,temp[10],exist[10]={0},a;
    int total_tat=0,total_wt=0;
    float avg_tat,avg_wt;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    printf("/n Enter the arrival time,burst time:\n");
    for(i=0;i<n;i++){
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].id=i+1;
        temp[i]=p[i].bt;
    }
    printf("Enter the time slice\n");
    scanf("%d",&s);
    insert(0);
    exist[0]=1;
    while(F<=R){
        a=delete();
        if(p[a].bt>=s){
            time=time+s;
            p[a].bt=p[a].bt-s;
        }
        else{
            time=time+p[a].bt;
            p[a].bt=0;
        }
        for(i=0;i<n;i++){
            if(exist[i]==0&&p[i].at<=time){
                insert(i);
                exist[i]=1;
            }
        }
        if(p[a].bt==0){
            p[a].tat=time-p[a].at;
            p[a].wt=p[a].tat-temp[a];
            total_tat+=p[a].tat;
            total_wt+=p[a].wt;


        }else{
            insert(a);
        }

    }
    printf("Gantt chart:\n");
    for(i=0;i<n;i++){
        printf("p%d(%d,%d,%d)",p[i].id,p[i].at,temp[i],p[i].tat);
            if(i<n-1){
                printf("--->");
            }
    }
    
    return 0;

}