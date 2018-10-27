#define TASKN 5
#define AT 15
#define Q1 4
#define Q2 3
#define Q3 2
#define ET 20
#define P 4
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int get_quanta(double type){
int dum=type;
if(type==1)
return Q1;
if(type==2)
return Q2;
if(type==3)
return Q3;
}

void swap_wl(int fresh,double data[][TASKN]){
int i;
for(i=TASKN-1;i>=0;i--)
if(data[4][i]==1)
break;

if(1){
double temp0=data[0][fresh],temp1=data[1][fresh],temp2=data[2][fresh],temp3=data[3][fresh],temp4=data[4][fresh];
int j;
for(j=fresh;j<i;j++){
	data[0][j]=data[0][j+1];
	data[1][j]=data[1][j+1];
	data[2][j]=data[2][j+1];
	data[3][j]=data[3][j+1];
	data[4][j]=data[4][j+1];
	}
data[0][i]=temp0;
data[1][i]=temp1;
data[2][i]=temp2;
data[3][i]=temp3;
data[4][i]=temp4;
}
}
int find(double data[][TASKN],int num,int i,int end){
int j;

for(j=0;j<end;j++)
	if(num==data[i][j])
		return 1;
return 0;
}

int find_q(double data[][TASKN]){
int i,j;
for(j=1;j<=P;j++){
for(i=0;i<TASKN;i++){
if(data[3][i]==j){int k=data[4][i];
	if(k==1)
	return i;
	}
}
}
return -1;
}
void set_1(double data[5][TASKN],double time){
int i;
for(i=0;i<TASKN;i++)
	if(data[2][i]<=time&&data[4][i]!=2)
		data[4][i]=1;
}

int cpu(double data[5][TASKN],double *time){
int i=find_q(data);
if(i!=-1){
	int quanta=get_quanta(data[3][i]);
	int dum=data[1][i];
	if(dum>quanta){
		printf("->executing %0.0f for %d\n",data[0][i],quanta);
		data[1][i]-=quanta;
		*time+=quanta;
		return i;
		}
	else{   
		*time+=data[1][i];
		printf("->executing %0.0f for %0.0f\n",data[0][i],data[1][i]);
		data[1][i]=0;
		data[4][i]=2;
		}
	}
else{printf("idlw");}
return -1;
}
int check(double data[TASKN]){
int i;
for(i =0;i<TASKN;i++){
	int val=data[i];
	if(val==0||val==1){
		return 1;}
	}
return 0;
}

void swap(double *a,double *b){
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;
}

void sort(double data[][TASKN]){
int i,j;
for(i=0;i<TASKN-1;i++)
	for(j=0;j<TASKN-i-1;j++)
		if(data[2][j]>data[2][j+1]){ swap(&data[0][j],&data[0][j+1]);
					     swap(&data[1][j],&data[1][j+1]);
					     swap(&data[2][j],&data[2][j+1]);
					     swap(&data[3][j],&data[3][j+1]);
					}
}
void mlq(){
double data[5][TASKN];
int i,num;
//task id generation
for(i=0;i<TASKN;i++){
num=rand()%TASKN;
//printf("random %d\n",num);
while(find(data,num,0,i)){
num=rand()%TASKN;
}
data[0][i]=num;
}
//exc time generation
for(i=0;i<TASKN;i++){
data[1][i]=(rand()%ET)+1;

}

//arrival time
for(int i=0;i<TASKN;i++)
data[2][i]=(rand()%(AT));

//priority queue
for(int i=0;i<TASKN;i++){
int dum=rand()%P;
while(dum==0){
dum=(rand()%(P));
}
data[3][i]=dum;
}

printf("GIVEN INPUTS\n");
printf("Task ID\tEXEXUTION TIME\t ARRIVAL TIME\tPRIORITY\n");
for(i=0;i<TASKN;i++)
      printf("%0.0f\t%.2f\t\t%0.2f\t\t %0.0f \t%0.0f\n",data[0][i],data[1][i],data[2][i],data[3][i],data[4][i]);


sort(data);
printf("GIVEN INPUTS\n");
printf("Task ID\tEXEXUTION TIME\t ARRIVAL TIME\tPRIORITY\n");
for(i=0;i<TASKN;i++)
      printf("%0.0f\t%.2f\t\t%0.2f\t\t %0.0f \t%0.0f\n",data[0][i],data[1][i],data[2][i],data[3][i],data[4][i]);
printf("\n");

double time;
int fresh=-1;
time=data[2][0];
while(check(data[4])){
set_1(data,time);


fresh=cpu(data,&time);
set_1(data,time);
if(fresh!=-1)
swap_wl(fresh,data);
/*for(i=0;i<TASKN;i++)
      printf("%0.0f\t%.2f\t\t%0.2f\t %0.0f \t%0.0f\n",data[0][i],data[1][i],data[2][i],data[3][i],data[4][i]);*///to see on going chart

}

}
