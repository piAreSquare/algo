#include<stdio.h>

void CMaxSub(int arr[],int low,int mid,int high,int* cl,int* ch,int *cs){
	
   int Ls = -100000;
   int sum=0;
      int i;
      for(i=mid;i>=low;i--){
      	sum = sum+arr[i];
      	if(sum>Ls){
      		Ls = sum;
      		
      		*cl = i;
		  }
	  }
	int Rs = -10000;
	sum =0;
	for(i=mid+1;i<=high;i++){
		sum +=arr[i];
		if(sum>Rs){
			Rs = sum;
			*ch = i;
		}
	}
	
	*cs = Rs + Ls;
	
	
	
}


void MaxArr(int arr[],int low,int high,int* lw,int *hw,int *sum){
	
	if(low==high){
		*lw = *hw = low;
		*sum = arr[low];
		return;
	}
	else {
		
	int 	mid = (low+high)/2;
		int lh,ll,ls;
		int rh,rl,rs;
		int cl,ch,cs;
		MaxArr(arr,low,mid,&ll,&lh,&ls);
			MaxArr(arr,mid+1,high,&rl,&rh,&rs);
        CMaxSub(arr,low,mid,high,&cl,&ch,&cs);
		if(ls>rs&& ls>cs){
			
			*lw = ll;
			 *hw = lh;
			  *sum = ls;
		} 		
		else if(rs>ls&&rs>cs){
			*lw = rl;
			 *hw = rh;
			  *sum = rs;
			
		}
		else{
			
			*lw = cl;
			 *hw = ch;
			  *sum = cs;
		}
		
	}
}


void main(){
	int size;
	scanf("%d",&size);
	int arr[size];
	int i,m=0;
	for(i=0;i<size;i++){
		
		scanf("%d",&arr[i]);
		arr[i] = arr[i]-m;
		m = m+arr[i];
		
		
	}
	arr[0]=0;
	int low,high,sum;
	MaxArr(arr,1,size-1,&low,&high,&sum);
	
	printf("%d.....%d.......%d",low-1 ,high,sum);
	
	
}
