#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


int main()
{
    DIR *dirct = opendir("./tmp");
	if (dirct == NULL) { return (ERROR); }
	int c = 0;
	struct dirent *e;
	while((e = readdir(dirct)) != NULL)
	{
		if(e->d_name[0] == '.') continue;

		struct stat s = {};
		char d[100] = "tmp/";
		stat(strcat(d, e->d_name), &s);
	
    	if(s.st_nlink >= 2){
            printf("File -- Hard Links\n%s -- ",e->d_name);
    	    for(int i=0;i<s.st_nlink;i++)
            {
                printf("link%d ",i);
            }
	    }
    }

    printf("Found %d i-node(s) with hardlink count of two or more\n", cnt);
}
