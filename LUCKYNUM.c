    #include<stdio.h>
    
    int main()
    {
        int t,x,num1,num2,temp,flag1,flag2,i,ans1,ans2;
        scanf("%d",&t);
        while(t--)
        {
                  scanf("%d",&x);
                  if(x%10==0 || x%10==5)
                  printf("-1\n");
                  
                  if(x%10==1)
                  {
                             for(i=6;i<10000;i=i+10)
                                 {
                                             num1=x*i;
                                             temp=num1;
                                             while(temp>0)
                                             {
                                                       if(temp%10 == 8 || temp%10 == 6)
                                                       {
                                                                 temp=temp/10;
                                                                 flag1=1;
                                                       }
                                                       
                                                       else 
                                                       {
                                                                 flag1=0;
                                                                 break;
                                                       }  
                                                       
                                             }
                                             if(flag1==1)
                                             {
                                                        break;
                                             }
                                                        
                                 }
                                 if(flag1==1) printf("%d\n",num1);
                                 
                                             
                             for(i=8;i<10000;i=i+10)
                             {
                                             num2=x*i;
                                             temp=num2;
                                             while(temp>0)
                                             {
                                                       if(temp%10 == 8 || temp%10 == 6)
                                                       {
                                                                 temp=temp/10;
                                                                 flag2=1;
                                                       }
                                                       
                                                       else 
                                                       {
                                                                 flag2=0;
                                                                 break;
                                                       }
                                             }  
                                                       
                                             if(flag2==1)
                                             {
                                                break;
    											
    										 }
                              }
    							if(flag2==1)			 
    			               printf("%d\n",num2);
                             
                             
                                                       
                             
                                                    
                      }
                  }
                  return 0;                     
                                       
                                                    
    }
