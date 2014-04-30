#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
pid_t GetPidByName(const char *pName)  
{  
	    DIR *pdir = NULL;  
	    struct dirent *pde = NULL;  
	    FILE *pf = NULL;  
            char buff[128]; 
            pid_t pid;  
            char szName[128];  
	    pdir = opendir("/proc");  
	    if (!pdir)  
	    {
            	perror("open /proc fail.\n");  
	        return -1;  
            }  			  
	    while ((pde = readdir(pdir)))  
	    {  
	    	if ((pde->d_name[0] < '0')|| (pde->d_name[0] > '9'))  
		{  
	        	continue;  
	        }  
	        sprintf(buff, "/proc/%s/status", pde->d_name);  
		pf = fopen(buff, "r");  
		if (pf)  
                {  
			fgets(buff,sizeof(buff),pf);  
			fclose(pf);  
			// 文件第一行格式 Name:  top   
			sscanf(buff,"%*s %s",szName);//sscanf不错,获取进程名  
			pid=atoi(pde->d_name);  
	                if(strcmp(szName,pName)==0)   
		        {  
				closedir(pdir);  
				return pid;  
			}
                 }	
	    } 
	    closedir(pdir);  
            return 0;  
}
int main()
{
	char task_name[50];
	pid_t pid;
	printf("please input process name:\n");
	scanf("%s",task_name);
        pid=GetPidByName(task_name);
	printf("This process pid is:%d\n",pid);

}
