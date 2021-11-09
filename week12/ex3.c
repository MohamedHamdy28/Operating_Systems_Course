#include <stdio.h>
#include <dirent.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
int main(void){
int a[100];
 char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
   int fd = open(dev,O_RDONLY);
  if(fd<0){
  return 0;
}
  else{
while(1){
  
  for(int i=0;i<100;i++)
  {
  	a[i]=0;
  }
  struct input_event evt;
  read(fd,&evt,sizeof(evt));
  if(evt.type==EV_KEY)
  {
  	printf("lll%d",evt.code);
	a[evt.code]=evt.value;
	printf("%d",a[evt.code]);
	if(a[25]==2&&a[18]==2||a[25]==1&&a[18]==1)
	{
		printf("I passed the Exam\n");
	}	
	if(a[46]==2&&a[30]==2&&a[25]==2||a[46]==1&&a[30]==1&&a[25]==1)
	{
		printf("Get some cappuccino!\n");
	}
	}
}
}     
return 0;
}
// p= 25 e=18 c = 46 a = 30
