#include <stdio.h>

int vekilalan(float arr[],int oylar[], int n)
{
    int i,j=0; 
    
    float max = arr[0];
    
        
    for (i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
            j = i;
        }
        if (arr[i] == max)
            max = oylar[j]>oylar[i]?max:arr[i],j=i;            
    }
    return j;
}
    

int main(){
    int vekil_alan,N,M,i=0,a=0,j=0,oylar[26],vekilsayisi[26]={0};
    float quotients[26];
    char partiler[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
    scanf("%d %d",&N,&M);
    for(;i<N;i++){
        scanf("%d", &oylar[i]);
    }
    for(i=0;M>0;M--,j=0){
        while(j<N){
            quotients[j] = oylar[j]/(vekilsayisi[j]+1.0);
            j++;    
        }
        vekil_alan = vekilalan(quotients,oylar,N);
        vekilsayisi[vekil_alan]+=1;
        }
    for(M=100;M>0;M--){
        for(i=0;i<N;i++){
            if(vekilsayisi[i]==M){
                a++;
                    
                printf("%c: %d\n",partiler[i],vekilsayisi[i]);
                    

            }
        }

    }
        
    return 0;
    }
