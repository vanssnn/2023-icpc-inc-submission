#include <stdio.h>
#include <string.h>

int max(int total, int* arr, int* arr2){
	
    int i, temp=-1;
    
    for(i=1; i<=total; i++){
    	
        if(!arr2[i] && (temp == -1 || arr[i] > arr[temp])){
            temp = i;
        }
    }
    
    return temp;
}

int main(){
	
    int n, m, k, i, check, sum_milk=0, count=0;
    
    scanf("%d %d %d", &n, &m, &k);
    getchar();
    
    int arr[n+1], arr2[n+1];
    memset(arr2, 0, sizeof(arr2));
    
    for(i=1; i<=n; i++){
    	
        scanf("%d", &arr[i]);
        
        sum_milk += arr[i];
        
        while(k>0 && sum_milk>m){
        	
            check = max(i, arr, arr2);
            
            if(check != -1){
            	
            	sum_milk -= arr[check];
                arr2[check]=1;
                k--;
            }
            else{
                break;
            }
        }
        
        if(sum_milk>m){
        	break;
		}
		
        count++;
    }
    
    printf("%d", count);
    
    return 0;
}
