#include <stdio.h>

double helper_calculate_pressure_on_block(int row, int column, double block_weight){
    if(row == 0){
        return 0;
    }
    else if((column == 0)||(column == row)){
        if(column==0){
            double pressure = block_weight/2;
            pressure += (0.15)*helper_calculate_pressure_on_block(row-1,column,block_weight);
            return pressure;
        }
        else if(column == row){
            double pressure = block_weight/2;
            pressure += (0.15)*helper_calculate_pressure_on_block(row-1,column-1,block_weight);
            return pressure;
        }
    }
    else{
        double pressure = block_weight;
        pressure+=(0.15)*helper_calculate_pressure_on_block(row-1,column-1,block_weight) + (0.15)*helper_calculate_pressure_on_block(row-1,column,block_weight);
        return pressure;  
    }

}
double calculate_pressure_on_block(int row, int column, double block_weight){
    if(row == 0)
        printf("(0,0) 0.00000000\n");
    else if(column<0){
        row-=1;
        column = row;
        calculate_pressure_on_block(row, column,block_weight);
    }
    else{
        calculate_pressure_on_block(row,column-1,block_weight);
        printf("(%d,%d) %.8lf\n",row,column,helper_calculate_pressure_on_block(row,column,block_weight));
    }
    return 0;


}
int main(){
    int N;
    double W;
    scanf("%d %lf",&N,&W);
    calculate_pressure_on_block(N-1,N-1,W);
    return 0;
}	