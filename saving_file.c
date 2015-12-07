#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
int main()
{
	int i;
	int j;
	int k = 0;
	int l;
	char buf[10];
	int blockSize = 10;
	int input_file;
	int disk;
	int randint;
	int freeSpace[100];
	srand(time(0));
	struct inode{
		int block[10];
	}inode;
	
	struct file{
		 struct inode inodes[10];
	}file;
	
	struct directory{
		char * name;
		struct file files[10];
	}dir;
	
	
	
	
	
	
	const char filename[] = "input_file";
	const char filename2[] = "disk";
	input_file = open(filename,  O_RDONLY);
	disk = open( filename2, O_RDWR |O_CREAT, 0640|O_TRUNC);
	
	write(disk,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",1000);
	for (i=0; i<100; i++)
	{
	
		freeSpace[i] = 0;

	}
	
	struct stat st;
		stat(filename, &st);
		int size = st.st_size;

	for (i=0; i<(size/blockSize); i++)
	{
		
		read(input_file, buf, blockSize);
		randint = rand()%100;
		
		for (j = 0;j<100; j++)
		{
			
			if (freeSpace[randint] == 1)
			{
						
				randint = rand()%100;
				j = 0;
	
			}
			
		}
		
		lseek(disk,blockSize*randint,SEEK_SET);
		write(disk,buf, blockSize);
		dir.name = "file";
		dir.files[0].inodes[0].block[i];
		freeSpace[randint] = 1;

	}
	for (i=0; i<100; i++)
	{
		printf("freeSpace%i =%i\n",i, freeSpace[i]);
	}
}
