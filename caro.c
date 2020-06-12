#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int m = 20;
const int n = 20;

// Test code:
void checkNgang(int table[m][n], int *counter){
    // int count=1;
    for(int i = 0; i < 20; i++){
      for(int j = 0; j < 20; j++){
          if(table[i][j] == table[i][j+1] && table[i][j] == 1){
              *counter+=1;
          }else if(*counter == 5){
            break;
          }else{
              *counter=1;
          }
      }
      if(*counter ==5) break;
  }
}

int loopThroughColumns(int arr[m][n], int numRow, int numCol, int *count){
  int temp;
    for(int i = 0; i < numRow-1; i++){
      if(*count == 5){
        return 1;
      };
      if(arr[i][numCol] == arr[i+1][numCol] && arr[i][numCol] == 1) *count += 1;
      else *count = 1; continue;
    }
    return 0;
}

void checkDoc(int table[m][n], int *count) {
	int res;
    for(int j =0; j < 20; j++){
      res = loopThroughColumns(table, m, j, count);
      if(res == 1) break;
      else continue;
    }
}

int checkcheoPhu(int table[20][20], int i, int j) {
  int p1,p2,p3,p4,p5; 
  int win=0,breakOut=0,breakOut2=0;
        //chéo phải
        if(j<16) {
            p1=table[i][j];     
            p2=table[i+1][j+1]; 
            p3=table[i+2][j+2]; 
            p4=table[i+3][j+3]; 
            p5=table[i+4][j+4];
            if(p1==p2 && p1==p3 && p1==p4 && p1==p5 && p1>0) {
              breakOut = 5;
              printf("\nWin cheo phai at\n ");
              printf("%d   %d\n", i, j);
            }
        } 
        //chéo trái
        if(j>3) {
            p1=table[i][j];     
            p2=table[i+1][j-1]; 
            p3=table[i+2][j-2]; 
            p4=table[i+3][j-3]; 
            p5=table[i+4][j-4];
            if(p1==p2 && p1==p3 && p1==p4 && p1==p5 && p1>0) {
              breakOut = 5;
              printf("\nWin cheo trai at\n ");
              printf("%d   %d\n", i, j);
            }
        } 
        return breakOut;
    }


void checkCheo(int table[m][n], int *count){
  int k, m, out;
  for(k=0;k<17;k++) {                                          
      for(m=0;m<17-k;m++) {
        *count=checkcheoPhu(table,m+k,m);
        if(*count==5) {
          // goto breakStatement;
          break;
          }
      }
      if(*count == 5) return;  
    }     
    
  for(k=0;k<17;k++){                                          
    for(m=0;m<17-k;m++) { 
      *count=checkcheoPhu(table,m,m+k);
      if(*count==5) { 
        // goto breakStatement;
        break;
        }
    }
    if(*count == 5){
      // goto breakStatement;
      break;
    }
    if(*count == 5) return;  
  }
  
  for(k=0;k<17;k++) {                                           
    for(m=k;m<17;m++) {
      *count=checkcheoPhu(table,m,k+20-m);
      if(*count==5) {
        // goto breakStatement;
        break;
      }
    }
    if(*count == 5) return;   
  }

  for(k=17;k>0;k--) {                                         
    for(m=0;m<k;m++){
      *count=checkcheoPhu(table,m,k+3-m);
      if(*count==5) {
        break;
        // goto breakStatement;
      }        
    }
    if(*count == 5) return;   
  }
}

int checkresult(int *won){
	int res;
  (*won == 5) ? (res = 5) : (res = -1);
  return res;
}

void red () {
  printf("\033[1;31m   _");
}

void blue() {
  printf("\033[1;34m");
}

void reset () {
  printf("\033[0m");
}

void green(){
  printf("\033[0;32m");
}

int main() {
	int i, j, repeat;
  int count=1;
	int table[20][20] = {};
  
	for (repeat = 0; repeat < 99999; repeat++) {
		printf("player 1 input coordination of x y\n");
		scanf("%d %d", &i, &j);
		table[i][j] = 1;
		printf("\n");
    
		// in bảng
        printf("      00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19\n");
		for (i = 0; i < 20; i++) {
			printf("%2d  ", i);
        for (j = 0; j < 20; j++) {
          if (table[i][j] == 2){
            blue();
					  printf("   X");
          }
				  else if (table[i][j] == 1){
            green();
					  printf("   O");
          }
				  else
            red();
          }
          reset();
        printf("\n");
		}
    
		int wonDoc = 1, wonNgang = 1, wonCheo = 1;
    checkCheo(table, &wonCheo);
    checkresult(&wonCheo);
    checkDoc(table, &wonDoc); checkresult(&wonDoc);
    checkNgang(table, &wonNgang); checkresult(&wonNgang);
  
    if (wonDoc == 5 || wonCheo == 5 || wonNgang == 5) {
			printf("player 1 wins");
			break;
		}
    else {wonDoc = 0; wonCheo = 0; wonNgang = 0; printf("\n");}



		printf("player 2 input coordination of x y\n");
		scanf("%d %d", &i, &j);    
		table[i][j] = 2;
		printf("\n");
		
		// in bảng
		printf("      00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19\n");
		for (i = 0; i < 20; i++) {
			printf("%2d  ", i);
        for (j = 0; j < 20; j++) {
          if (table[i][j] == 2){
            blue();
					  printf("   X");
          }
				  else if (table[i][j] == 1){
            green();
					  printf("   O");
          }
				  else
            red();
          }
          reset();
        printf("\n");
		}
		
		int wonDoc2 = 1, wonNgang2 = 1, wonCheo2 = 1;
    checkCheo(table, &wonCheo2); checkresult(&wonCheo2);
    checkDoc(table, &wonDoc2); checkresult(&wonDoc2);
    checkNgang(table, &wonNgang2); checkresult(&wonNgang2);

    if (wonDoc2 == 5 || wonCheo2 == 5 || wonNgang2 == 5) {
			printf("player 2 wins");
			break;
		} 
    else {wonDoc2 = 0; wonCheo2 = 0; wonNgang2 = 0;printf("\n");}

	}

	return 0;
}
    
