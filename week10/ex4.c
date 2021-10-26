#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


int main()
{
    DIR *dirct = opendir("./tmp");
	if (dirct == NULL) { return 1; }
	int c = 0;
	struct dirent *e;
    struct dirent *a;
	printf("File -- Hard Links\n");
	while((e = readdir(dirct)) != NULL)
	{
		if(e->d_name[0] == '.') continue;

		struct stat s = {};
        struct stat t = {};
		char d[100] = "tmp/";
		stat(strcat(d, e->d_name), &s);
		
    	if(s.st_nlink >= 2){
            printf("%s -- ",e->d_name);
            DIR *dirct2 = opendir("./tmp");
            while ((a = readdir(dirct2)) != NULL)
            {
                char d2[100] = "tmp/";
                stat(strcat(d2, a->d_name), &t);
                if(t.st_ino==s.st_ino)
                {
                    printf("%s ", a->d_name);
                }
            }
	    }
	    printf("\n");
    }
}
