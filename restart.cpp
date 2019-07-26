#include <iostream>                      
#include<random>
#include<ctime>
#include<cstdlib>
#include <bits/stdc++.h> 
#include<conio.h>
#include<pthread.h>

using namespace std;
void *game1(void *);
void *game2(void *);
void difficulty(void);
void lost(void);
void funk(int);

int a[30],temp1,count1=0,speed=0,playing=0,high,manframe,score=0,highscore=0;

int start=1,dd1,dd2;    //dd=difficulty desider
char dopt='0',ch='d';              //dopt=difficulty opted

int main(){
	pthread_t thread1,thread2;
	int rc;
      rc = pthread_create(&thread1, NULL,game1,(void *) NULL);
      
      if (rc) 
         cout << "Error:unable to create thread," << rc << endl;
           

      rc = pthread_create(&thread2, NULL, game2,(void *) NULL);
      
      if (rc) 
         cout << "Error:unable to create thread," << rc << endl;
        
      pthread_exit(NULL);   

}


//game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 
//game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 game1 


void *game1(void *){
srand(time(0));
//playing=0 on initialization;
//ch='2' on initialization
difficulty();
dopt='0';

restart:                      //-------RESTART---------->>>>>>>>
temp1=20;
for(int i=0;i<30;i++){
    a[i]=temp1+dd1+(rand()%dd2)  ;       //min 12. and max 30
    temp1=a[i];
}

playing=1;                    //restart from here
count1=0;                        
manframe=0;
high=0;
speed=0;


int n=0,t=0,m=0;                //n->count1s the no. of poles passed
                                //t->helps skets poles in each frame
                                //m->helps t gets proper value after each layer
 label:

     cout<<"\n\n\n\n";       //vertically 4 below
     cout<<"                                    SCORE! \n";
     cout<<"                             ";
     for(int p=0;p<10-log10(count1+1);p++) cout<<" ";
     cout<<count1;	
     for(int p=0;p<9-log10(count1+1);p++) cout<<" ";
     cout<<"\n";

    funk(1);
    funk(2);
    funk(3);
    funk(4);
 
     m=n;
     t=n;

    funk(5);
    for(int i=count1;i<count1+71;i++)                      //70 length of full screen
	{
	    if(i==a[t]) {
	        cout<<"_";
	        t=t+1;
	        if(i==count1) n++;                //a pole has just passed
	    }
	    else cout<<" ";
	}
	cout<<"\n";
	for(int j=0;j<3;j++){                    //3 layers of wall
	    t=m;
	    
	    funk(j+6);
	    
	    
	    
	    
	  int  i=count1;
	    if(count1==a[t]){
	        cout<<" |";
	        i=i+2;
	        t++;
	    }
	    
	    
	    
	    
	    
	    for(i;i<count1+70;i++)    //i=count1;
	    {
	        
	        if((i+1)==a[t]){
	            cout<<"| |";
	            t=t+1;
	            i=i+2;
	        }
	        else if(j==2) cout<<"_";
	        else cout<<" ";
	    }
	    cout<<"\n";
	} 

if(manframe==0) speed=0;
	else speed++;

	if(speed==2){                     //vary speed of jump
		speed=0;
		manframe++;
	} 


count1++;
system("CLS");

if(n!=m){
	if(manframe<3 || manframe>5){
		  score=count1;
		  if(score>highscore) highscore=score;
          playing=0;
          lost();
          
          if(ch=='e'){exit(0);}
          else if(ch=='r'){goto restart;}
          else{system("CLS"); difficulty();dopt='0';goto restart;}

	}
}
if(n!=30) goto label;
		exit(0);

pthread_exit(NULL);
}


void *game2(void *){
	for(int i=0;i>-1;i++){
			if(playing==0){
							 if(ch=='d') {
							 				while(dopt!='1' && dopt!='2' && dopt!='3' && dopt!='4')
							 					dopt=getch();
							 				  
							              }
						  }

			else 
		      if(high==0){
              manframe=1;
              high=1;}		
			ch=getch();






}
}


















void lost(){
	cout<<"\n\n";
    
cout<<"                   _____                            _____    _____  _________\n" ;  
cout<<"          \\    /  |     |  |     |          |      |     |  |           |    \n"  ;   
cout<<"           \\  /   |     |  |     |          |      |     |  |____       |    \n"   ;              
cout<<"            \\/    |     |  |     |          |      |     |       |      |    \n"    ;           
cout<<"            /     |     |  |     |          |      |     |       |      |    \n"     ;            
cout<<"           /      |_____|  |_____|          |____  |_____|  _____|      |    \n\n"   ;

cout<<"                                     ||  SCORE!  || \n";
     cout<<"                                  ";
    for(int p=0;p<10-log10(score+1);p++) cout<<" ";
    cout<<score;	
   for(int p=0;p<9-log10(score+1);p++) cout<<" ";
     cout<<"\n";
 cout<<"                                 ||  HIGHEST SCORE!  || \n";
 cout<<"                                  ";
  for(int p=0;p<10-log10(highscore+1);p++) cout<<" ";
    cout<<highscore;	
   for(int p=0;p<9-log10(highscore+1);p++) cout<<" ";
     cout<<"\n";
cout<<"                                       RESTART-> R \n";     
cout<<"                                     DIFFICULTY-> D \n";
cout<<"                                        EXIT-> E   \n";



while(ch!='e' && ch!='r' && ch!='d'){
          	;
          }
	



return;

}








//difficultydifficultydifficultydifficultydifficultydifficultydifficultydifficultydifficulty
//difficultydifficultydifficultydifficultydifficultydifficultydifficultydifficultydifficulty


void difficulty()
{ 
	cout<<"\n\n\n\n\n\n";
	cout<<"                         Select Dificulty (Press 1, 2, 3 or 4)\n\n";
	cout<<"                                     1)EASY \n";
	cout<<"                                    2)MEDIUM \n";
	cout<<"                                     3)HARD \n";
	cout<<"                                  4)IMPOSSIBLE \n";

 

	while(dopt!='1' && dopt!='2' && dopt!='3' && dopt!='4'){;}
        switch(dopt){
		 case '1': dd1=30;
		         dd2=20;
		         break;
		 case '2': dd1=15;
		           dd2=20;
		           break;
		 case '3': dd1=12;
		         dd2=10;
		         break; 
		 case '4': dd1=10;
		         dd2=7;
		         break;                    
	}
	
	return;
}
//difficultydifficultydifficultydifficultydifficultydifficultydifficultydifficulty
//difficultydifficultydifficultydifficultydifficultydifficultydifficultydifficulty


//funkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunk
//funkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunk
void funk(int pos)
{
	if(manframe==0){
		if(pos==1) cout<<"\n";
		if(pos==2) cout<<"\n";
		if(pos==3) cout<<"\n";
		if(pos==4) cout<<"\n";
		if(pos==5) cout<<" _ ";
		if(pos==6) cout<<"|_|";
		if(pos==7) cout<<"-|-";
		if(pos==8) cout<<"/ \\";
		
	}

	if(manframe==2 || manframe==7){
		if(pos==1) cout<<"\n";
		if(pos==2) cout<<"\n";
		if(pos==3) cout<<" _ \n";
		if(pos==4) cout<<"|_|\n";
		if(pos==5) cout<<"-|-";
		if(pos==6) cout<<"/ \\";
		if(pos==7) cout<<"   ";
		if(pos==8) cout<<"   ";

	
		
		
	}

	if(manframe==3 || manframe==4 || manframe==5 || manframe==6 ){
		if(pos==1) cout<<" _ \n";
		if(pos==2) cout<<"|_|\n";
		if(pos==3) cout<<"-|-\n";
		if(pos==4) cout<<"/ \\\n";
        if(pos==5) cout<<"   ";
		if(pos==6) cout<<"   ";
		if(pos==7) cout<<"   ";
		if(pos==8) cout<<"   ";
         

   

	}	

	if(manframe==1 || manframe==8){
		if(pos==1) cout<<"\n";
		if(pos==2) cout<<"\n";
		if(pos==3) cout<<"\n";
		if(pos==4) cout<<" _ \n";
		if(pos==5) cout<<"|_|";
		if(pos==6) cout<<"-|-";
		if(pos==7) cout<<"/ \\";
		if(pos==8) cout<<"   ";	

		if (manframe==8){
			manframe=0;
			high=0;
		}
		
     }
    return;
}


//funkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunk
//funkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunkfunk