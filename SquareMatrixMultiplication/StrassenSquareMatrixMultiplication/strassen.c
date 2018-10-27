#include<stdio.h>
#include<stdlib.h>


int ** add(int **arr1,int **arr2,int size,int bit){

	int i,j;
	
int **arr  = (int **)malloc(size * sizeof(int *));
for (i =0; i<size; i++)
     {
		    arr[i] = (int *)malloc(size * sizeof(int));
            
            
        }
	if(bit==0){
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++)
		{
			
			
			arr[i][j] = arr1[i][j] + arr2[i][j];
			
			
		}
		
	}
}

else{
		for(i=0;i<size;i++){
		for(j=0;j<size;j++)
		{
			
			
			arr[i][j] = arr1[i][j] - arr2[i][j];
			
			
		}
		
	}
	
}

return arr;
}


int** padding(int **arr1,int n){
	
	int **arr  = (int **)malloc((n+1) * sizeof(int *));
	int i,j;
	
		for (i=0; i<n+1; i++)
     {
		   
        arr[i] = (int *)malloc((n+1) * sizeof(int));
    }

	
 	for(i=0;i<=n;i++){
	for(j=0;j<=n;j++){
    if(i==n||j==n){
   	arr[i][j]=0;
         }
else{
	arr[i][j] = arr1[i][j];

}
	
}}

return arr;
}


int ** multiply(int **arr1,int **arr2,int n){
	
	
	
	  int i,j,k=0;
	  if(n!=1&(n%2)!=0){
	  	
	  	arr1 = padding(arr1,n);
		arr2 = padding(arr2,n);
	  	n =n+1;
	  	
	  }
	  
int 	   **arr= (int **)malloc(n * sizeof(int *));
	for (i=0; i<n; i++)
    {
		   
            arr[i] = (int *)malloc(n * sizeof(int));
    }
	if(n==1){
	
		arr[0][0] = arr1[0][0] * arr2[0][0];
	
		
		return arr;
		
	}
	
	

	
	int **a1= (int **)malloc(n/2 * sizeof(int *));
	int **a2= (int **)malloc(n/2 * sizeof(int *));
	int **a3= (int **)malloc(n/2 * sizeof(int *));
	int **a4= (int **)malloc(n/2 * sizeof(int *));
	int **b1= (int **)malloc(n/2 * sizeof(int *));
	int **b2= (int **)malloc(n/2 * sizeof(int *));
	int **b3= (int **)malloc(n/2 * sizeof(int *));
	int **b4= (int **)malloc(n/2 * sizeof(int *));
	
	
	for (i=0; i<n/2; i++)
     {
		    a1[i] = (int *) malloc(n/2*sizeof(int));
		    a2[i] = (int *) malloc(n/2*sizeof(int));
		    a3[i] = (int *) malloc(n/2*sizeof(int));
		    a4[i] = (int *) malloc(n/2*sizeof(int));
		    b1[i] = (int *) malloc(n/2*sizeof(int));
		    b2[i] = (int *) malloc(n/2*sizeof(int));
		    b3[i] = (int *) malloc(n/2*sizeof(int));
		    b4[i] = (int *) malloc(n/2*sizeof(int));
        }
	
	for(i=0;i<n/2;i++){
		
		for(j=0;j<n/2;j++){
			
			a1[i][j]  = arr1[i][j];
			a2[i][j] = arr1[i][j+n/2];
			a3[i][j] = arr1[i+n/2][j];
			a4[i][j] = arr1[i+n/2][j+n/2];
			b1[i][j]  = arr2[i][j];
			b2[i][j] = arr2[i][j+n/2];
			b3[i][j] = arr2[i+n/2][j];
			b4[i][j] = arr2[i+n/2][j+n/2];
			
		}
	}
int **sub[10];

sub[0] = add(b2,b4,n/2,1);  
sub[1] = add(a1,a2,n/2,0);
sub[2] = add(a3,a4,n/2,0);
sub[3] = add(b3,b1,n/2,1);
sub[4]= add(a1,a4,n/2,0);
sub[5]= add(b1,b4,n/2,0);
sub[6]= add(a2,a4,n/2,1);
sub[7] = add(b3,b4,n/2,0);
sub[8] = add(a1,a3,n/2,1);
sub[9] = add(b1,b2,n/2,0);

int **pro[7];
pro[0] = multiply(a1,sub[0],n/2); 
pro[1] = multiply(sub[1],b4,n/2);
pro[2] = multiply(sub[2],b1,n/2);
pro[3] = multiply(a4,sub[3],n/2);
pro[4] = multiply(sub[4],sub[5],n/2);
pro[5] = multiply(sub[6],sub[7],n/2);
pro[6] = multiply(sub[8],sub[9],n/2);




a1 = add(add(add(pro[4],pro[5],n/2,0),pro[3],n/2,0),pro[1],n/2,1); 
a2 = add(pro[0],pro[1],n/2,0);
a3 = add(pro[2],pro[3],n/2,0);
a4 = add(add(add(pro[4],pro[0],n/2,0),pro[2],n/2,1),pro[6],n/2,1); 





	for(i=0;i<n/2;i++){
		
		for(j=0;j<n/2;j++){
			
			arr[i][j] = a1[i][j];
			arr[i][j+n/2] = a2[i][j];
			arr[i+n/2][j] = a3[i][j];
			arr[i+n/2][j+n/2]= a4[i][j]; 
			
		}
	}
	
free(a1);
free(a2);
free(a3);
free(a4);
free(b1);
free(b2);
free(b3);
free(b4);

	return arr;	




}














int main(){
int s;
printf("enter the size of square matrix:\t");	
scanf("%d",&s);


int i=0,j=0;
int **arr;
int **arr2  = (int **)malloc(s * sizeof(int *));
int **arr1 = (int **)malloc(s * sizeof(int *));
for (i=0; i<s; i++)
     {
		    arr1[i] = (int *)malloc(s * sizeof(int));
            arr2[i] = (int *)malloc(s * sizeof(int));
            
        }

printf("enter matrix-1\n");
for(i=0;i<s;i++){
	for(j=0;j<s;j++){
	
	scanf("%d",&arr1[i][j]);
	
}
}

printf("enter matrix-2\n");
for(i=0;i<s;i++){
	for(j=0;j<s;j++){
	
	scanf("%d",&arr2[i][j]);

}
}

 arr = multiply(arr1,arr2,s);
//arr = add(arr1,arr2,s,0);


printf("-----array1-------\n");
for(i=0;i<s;i++){
	for(j=0;j<s;j++){

	printf("%d\t",arr1[i][j]);

}
printf("\n");
}

printf("---------array2---------\n");


for(i=0;i<s;i++){
	for(j=0;j<s;j++){

	printf("%d\t",arr2[i][j]);

}
printf("\n");
}
printf("---------------multiplication------------------\n");
for(i=0;i<s;i++){
	for(j=0;j<s;j++){

	printf("%d\t",arr[i][j]);

}
printf("\n");
}


free(arr1);
free(arr2);
getch();	
	return 0;
}
