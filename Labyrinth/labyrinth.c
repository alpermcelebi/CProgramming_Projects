#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **lines,**lab,*firstline = (char*)malloc(sizeof(char)*50000),*ilk = malloc(sizeof(char)*10);
    int qx,qy,lineCount = 1,i=0,j=0,columnCount = 1,x,y,linenumber,columnnumber,**q,qeleman=1,currentq,check=1,endcheck,**visitedList;
    scanf("%d %d",&x,&y);
    fgets(ilk,100,stdin);
    free(ilk);
    fgets(firstline, 50000, stdin);
    for (i = 0; firstline[i] != '\0'; i++){
        columnCount++;
    }
    lines = malloc(sizeof(char*)*3);
    lines[0] = malloc(sizeof(char)*columnCount);
    lines[1] = malloc(sizeof(char)*columnCount);
    lines[2] = malloc(sizeof(char)*columnCount);
    for(j=0;j<(columnCount-1);j++){
        lines[1][j] = firstline[j];
    }
    free(firstline);
    for(lineCount = 2;fgets(lines[lineCount], 100000, stdin) != NULL;){
        lineCount++;
        lines = realloc(lines,sizeof(char*)*(lineCount+1));
        lines[lineCount] = malloc(sizeof(char)*columnCount);
    }
    
    
    lab = (char**)malloc(sizeof(char*)*(lineCount-1));
    
    for(i = 0;i<(lineCount-1);i++){
        lab[i] = (char*)malloc(sizeof(char)*(columnCount-1));
    }
    for(i=0;i<(lineCount-1);i++){
        for(j=0;j<(columnCount-1);j++){
            lab[i][j] = lines[i+1][j];
        }
    }
    linenumber = lineCount - 1;
    columnnumber = columnCount - 1;
    visitedList = (int**)malloc(sizeof(int*)*linenumber);
    for(i=0;i<linenumber;i++){
        visitedList[i] = (int*)malloc(sizeof(int)*columnnumber);
    }
    
    
    q = (int**)malloc(sizeof(int*)*qeleman);
    q[0] = (int*)malloc(sizeof(int)*2);
    q[0][0] = x;
    q[0][1] = y;
    
    while(1){
        for(i = 0; i < qeleman; i++){
            if((q[i][1] != 0) || (q[i][0] != 0)){
                currentq = i;
                break;
            }
            else if(((qeleman - i) == 1) && (q[i][1] == 0) && (q[i][0] == 0)){
                check = 0;
            }
        }
        if(check == 0){
            break;
        }
        qx = q[currentq][0];
        qy = q[currentq][1];
        q[currentq][0] = 0;
        q[currentq][1] = 0;
        
        
        
        if (qy != 0 && qx != 0 && qx != (columnnumber-1) && qy != (linenumber-1)){
            if((visitedList[qy-1][qx] != 1) &&(lab[qy-1][qx] == ' ')){
                visitedList[qy-1][qx] = 1;
                qeleman++;
                q = (int**)realloc(q, sizeof(int*)*qeleman);
                q[qeleman-1] = (int*)malloc(sizeof(int)*2);
                q[qeleman-1][0] = qx;
                q[qeleman-1][1] = qy-1;
            }
            if((visitedList[qy][qx+1] != 1) &&(lab[qy][qx+1] == ' ')){
                visitedList[qy][qx+1] = 1;
                qeleman++;
                q = (int**)realloc(q, sizeof(int*)*qeleman);
                q[qeleman-1] = (int*)malloc(sizeof(int)*2);
                q[qeleman-1][0] = qx+1;
                q[qeleman-1][1] = qy;
            }
            if((visitedList[qy][qx-1] != 1) &&(lab[qy][qx-1] == ' ')){
                visitedList[qy][qx-1] = 1;
                qeleman++;
                q = (int**)realloc(q, sizeof(int*)*qeleman);
                q[qeleman-1] = (int*)malloc(sizeof(int)*2);
                q[qeleman-1][0] = qx-1;
                q[qeleman-1][1] = qy;
            }
            if((visitedList[qy+1][qx] != 1) &&(lab[qy+1][qx] == ' ')){
                visitedList[qy+1][qx] = 1;
                qeleman++;
                q = (int**)realloc(q, sizeof(int*)*qeleman);
                q[qeleman-1] = (int*)malloc(sizeof(int)*2);
                q[qeleman-1][0] = qx;
                q[qeleman-1][1] = qy+1;
            }
        }
        else if(qy == 0 || qx == 0 || qx == (columnnumber-1) || qy == (linenumber-1)){
            endcheck = 1;
            lab[qy][qx] = '*';
            break;
        }
    }
    
    
    for(i=0;i<(linenumber);i++){
        for(j=0; j<(columnnumber); j++){
            if(endcheck){
                if(visitedList[i][j] == 1){
                    lab[i][j] = '*';
                }
                else{
                    continue;
                }
            }
            else{
                if(visitedList[i][j] == 1){
                    lab[i][j] = '.';
                }
                else{
                    continue;
                }
                
            }
        }
    }    
            
    for(i=0;i<(lineCount-1);i++){
        for(j=0;j<(columnCount-1);j++){
            if(j==columnCount-2){
                printf("%c",lab[i][j]);
            }
            else{
                printf("%c",lab[i][j]);
            }
        }
    }
    free(lab);
    return 0;
}
