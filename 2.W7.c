#include <stdio.h>
#include <string.h>
#define SIZE 25
short block[SIZE][SIZE];

//策略: 用二維陣列表達方塊世界

int main(void){
    //以-1代表此元素無積木
    for(int i=0 ; i<SIZE ; i++)
      for(int j=0 ; j<SIZE ; j++){
        block[i][j] = -1;
      }
    int n; //有n個方塊
    char string_1[5], string_2[5];
    int a,b;
    scanf("%d",&n);

    //初始化方塊世界
    for(int i=0 ; i<n ; i++)
        block[0][i] = i;

    while(1){
      scanf("%s",string_1);
      if(strcmp(string_1,"quit") == 0)
          break;
      scanf("%d %s %d", &a, string_2, &b);
      if(a == b)
        continue;
      int y1,x1; //block[y1][x1] 代表積木a
      int y2,x2; //block[y2][x2] 代表積木b

      if(strcmp(string_1,"move") == 0 && strcmp(string_2,"onto") == 0){
          //找指定的積木a
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == a)
                  y1=i, x1=j;
          //找指定的積木b
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == b)
                  y2=i, x2=j;
          //a, b在同一堆積木中，那麼這樣的動作算是不合法的。所有不合法的動作應該被忽略
          if(x1 == x2)
            continue;
          //a上面的積木歸位。i控制陣列y軸，j控制積木號碼
          for(int i=1 ; i<SIZE-y1 ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[y1+i][x1] == j){
                  block[0][j] = j ;
                  block[y1+i][x1] = -1;
                }
          //b上面的積木歸位
          for(int i=1 ; i<SIZE-y2 ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[y2+i][x2] == j){
                  block[0][j] = j ;
                  block[y2+i][x2] = -1;
                }
          //積木a移動到積木b上面
          block[y2+1][x2] = block[y1][x1];
          block[y1][x1] = -1; //用-1代表這個元素沒有積木
      }
      else if(strcmp(string_1,"move") == 0 && strcmp(string_2,"over") == 0){
          //找指定的積木a
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == a)
                  y1=i, x1=j;
          //找指定的積木b
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == b)
                  y2=i, x2=j;
          //a, b在同一堆積木中，那麼這樣的動作算是不合法的。所有不合法的動作應該被忽略
          if(x1 == x2)
            continue;
          //a上面的積木歸位
          for(int i=1 ; i<SIZE-y1 ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[y1+i][x1] == j){
                  block[0][j] = j ;
                  block[y1+i][x1] = -1;
                }
          //把積木a堆在積木b和其上方積木群的上面
          for(int i=1 ; i<SIZE-y2 ; i++)
              if(block[y2+i][x2] == -1){
                  block[y2+i][x2] = block[y1][x1];
                  block[y1][x1] = -1;
              }
      }
      else if(strcmp(string_1,"pile") == 0 && strcmp(string_2,"onto") == 0){
          //找指定的積木a
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == a)
                  y1=i, x1=j;
          //找指定的積木b
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == b)
                  y2=i, x2=j;
          //a, b在同一堆積木中，那麼這樣的動作算是不合法的。所有不合法的動作應該被忽略
          if(x1 == x2)
            continue;
          //b上面的積木歸位
          for(int i=1 ; i<SIZE-y2 ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[y2+i][x2] == j){
                  block[0][j] = j ;
                  block[y2+i][x2] = -1;
                }
          //把積木a與其上方的積木群疊在積木b上
          for(int j=0 ; j<SIZE-y1 ; j++)
            if(block[y1+j][x1] != -1){
                block[y2+1+j][x2] = block[y1+j][x1];
                block[y1+j][x1] = -1;
            }            
      }
      else if(strcmp(string_1,"pile") == 0 && strcmp(string_2,"over") == 0){
          //找指定的積木a
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == a)
                  y1=i, x1=j;
          //找指定的積木b
          for(int i=0 ; i<SIZE ; i++)
            for(int j=0 ; j<SIZE ; j++)
                if(block[i][j] == b)
                  y2=i, x2=j;
          //a, b在同一堆積木中，那麼這樣的動作算是不合法的。所有不合法的動作應該被忽略
          if(x1 == x2)
            continue;
          //把積木群a疊在積木群b上面
          for(int i=1 ; i<SIZE-y2 ; i++){
              if(block[y2+i][x2] == -1){
                  for(int j=0 ; /*j<SIZE-i*/ y1 + j <SIZE ; j++)
                      if(block[y1+j][x1] != -1){
                          block[y2+i+j][x2] = block[y1+j][x1];
                          block[y1+j][x1] = -1;
                      }
              }
          }
      }
          /*輸出
    for(int i=0 ; i<n ; i++){
      printf("%d:",i);
      for(int j=0 ; j<SIZE ; j++){
        if(block[j][i] != -1) //-1代表沒積木，所以不用印
          printf(" %d",block[j][i]);
    
      }
      printf("\n");
    }*/
    }

     //輸出
    for(int i=0 ; i<n ; i++){
      printf("%d:",i);
      for(int j=0 ; j<SIZE ; j++){
        if(block[j][i] != -1) //-1代表沒積木，所以不用印
          printf(" %d",block[j][i]);
    
      }
      printf("\n");
    }

    return 0;
}
