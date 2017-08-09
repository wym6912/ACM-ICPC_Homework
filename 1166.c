#include <stdio.h>
#define MAX 100000
int r[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                 {0,1,1,0,1,1,0,0,0,0},{0,1,1,1,0,0,0,0,0,0},{0,0,1,1,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0,1,0,0},{0,0,1,0,1,1,1,0,1,0},{0,0,0,1,0,0,1,0,0,1},
                 {0,0,0,0,1,1,0,1,1,0},{0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,1,1,0,1,1}};
int matrix[10], ind[10];
main()
{
   int i,i1,i2,i3,i4,i5,i6,i7,i8,i9;
   int num,min=MAX,f;
  
   for(i=1;i<=9;i++)
      scanf("%d",&matrix[i]);
   //Ã¶¾ÙËùÓÐ¿ÉÄÜ
   for(i1=0;i1<=3 ;i1++)
      for(i2=0;i2<=3;i2++)
         for(i3=0;i3<=3;i3++)
            for(i4=0;i4<=3;i4++)
               for(i5=0;i5<=3;i5++)
                  for(i6=0;i6<=3;i6++)
                     for(i7=0;i7<=3;i7++)
                        for(i8=0;i8<=3;i8++)
                           for(i9=0;i9<=3;i9++)
                           {
                              f=1;
                              i=1;
                              num = i1+i2+i3+i4+i5+i6+i7+i8+i9;
                              if(num>=min)
                                 break;
                              while(i<=9)
                              {                             
                                 if(0 !=(matrix[i]+i1*r[1][i] + i2*r[2][i] + i3*r[3][i] + i4*r[4][i] + i5*r[5][i]+ i6*r[6][i]+ i7*r[7][i]+ i8*r[8][i]+ i9*r[9][i])%4 )
                                 {
                                    f=0;
                                    break;
                                 }                          
                                 i++;
                              }
                              if(1==f)
                              {
                                    min = num;
                                    ind[1] = i1;
                                    ind[2] = i2;
                                    ind[3] = i3;
                                    ind[4] = i4;
                                    ind[5] = i5;
                                    ind[6] = i6;
                                    ind[7] = i7;
                                    ind[8] = i8;
                                    ind[9] = i9;
                              }
                           }
   // Êä³öind
   for(i=1;i<=9;i++)
      if(ind[i]!=0)
         num = i;
   for(i=1;i<num;i++)
   {
       while(ind[i]>0)
       {
          printf("%d ",i);
          ind[i]--;
       }
   }
   while(ind[num]>1)
   {
      printf("%d ",num);
      ind[num]--;
   }
   printf("%d\n",num);
  
   system("pause");
   return 0;
}