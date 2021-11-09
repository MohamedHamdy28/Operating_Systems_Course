#include <stdio.h>
#include <dirent.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
int main(void){
FILE *fp;
fp = fopen("ex2.txt","w");  
 char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
   int fd = open(dev,O_RDONLY);
  if(fd<0){
  return 0;
}
  else{
while(1){
  struct input_event evt;
  read(fd,&evt,sizeof(evt));
  if(evt.type==EV_KEY)
  { if(evt.value==0)
  	 printf("RELEASED 0x00%x (%d)\n", evt.code);
    if(evt.value==1)
	printf("PRESSED 0x00%x (%d)\n",evt.code);	
}
}
}  
fflush(fp);   
return 0;
}
