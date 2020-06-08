#include <stdio.h>
// const int m = 8;
// const int n = 8;

int checkcheo(int table[20][20], int i, int j) {

  int p1,p2,p3,p4,p5; 
  int win=0,breakOut=0,breakOut2=0;
        //chéo phải
        if(j<16) {
            p1=table[i][j];     
            p2=table[i+1][j+1]; 
            p3=table[i+2][j+2]; 
            p4=table[i+3][j+3]; 
            p5=table[i+4][j+4];
            if(p1==p2 && p1==p3 && p1==p4 && p1==p5 && p1 == 1) {
              breakOut = 1;
              printf("\nWin chéo phải at\n ");
              printf("%d   %d", i, j);
            }
        } 
        //chéo trái
        if(j>3) {
            p1=table[i][j];     
            p2=table[i+1][j-1]; 
            p3=table[i+2][j-2]; 
            p4=table[i+3][j-3]; 
            p5=table[i+4][j-4];
            if(p1==p2 && p1==p3 && p1==p4 && p1==p5 && p1 == 1) {
              breakOut = 1;
              printf("\nWin chéo trái at\n ");
              printf("%d   %d", i, j);
            }
        } 
        return breakOut;
    }

    

    
  int main(){
                  
    int table[20][20]={
              //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //0
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //1
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //2
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //3
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, //4
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, //5
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, //6
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //7
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //8
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //9
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //10
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //11
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //12
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //13
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //14
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //15
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //16
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //17
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //18
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //19
    };
    
    int i=0,j=0,out,m,k;
    

    //in bảng
    printf("   00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19\n");
    for (int x = 0; x < 20; x++) {
      printf("%2d  ", x);
      for (int y = 0; y < 20; y++) 
        printf("%d  ",table[x][y]); 
        printf("\n");
    } 
    

    for(k=0;k<17;k++)                                       // +
        for(m=0;m<17-k;m++) out=checkcheo(table,m+k,m);     // - +
    for(k=0;k<17;k++)                                       // + -
        for(m=0;m<17-k;m++) out=checkcheo(table,m,m+k);     //   +
    for(k=0;k<17;k++)                                       //   +
        for(m=k;m<17;m++) out=checkcheo(table,m,k+20-m);    // + -
    for(k=17;k>0;k--)                                       // - +
        for(m=0;m<k;m++) out=checkcheo(table,m,k+3-m);      // +
            
    /*
    for(m=0;m<17;m++) out=checkcheo(table,m,m);
    for(m=0;m<16;m++) out=checkcheo(table,m+1,m);
    for(m=0;m<15;m++) out=checkcheo(table,m+2,m);
    
    for(m=0;m<17;m++) out=checkcheo(table,m,m);
    for(m=0;m<16;m++) out=checkcheo(table,m,m+1);
    for(m=0;m<15;m++) out=checkcheo(table,m,m+2);
    
    for(m=0;m<17;m++) out=checkcheo(table,m,20-m);
    for(m=1;m<17;m++) out=checkcheo(table,m,21-m);
    for(m=2;m<17;m++) out=checkcheo(table,m,22-m);
    
    // for(m=0;m<17;m++) out=checkcheo(table,m,20-m);
    for(m=0;m<16;m++) out=checkcheo(table,m,19-m);
    for(m=0;m<15;m++) out=checkcheo(table,m,18-m);
    */
    return 0;
}