#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>


void* func1(void *param)
{
	printf("This is pthread creation using user attributes\n");
	sleep(2);
	
	return NULL;
}




int main(void)
{
	pthread_attr_t myAttr;
	pthread_t tid1;
	
	void *stck;
	size_t siz;
	int err;
	
	size_t my_stksize = 300000;
	void * my_stack;
	
	pthread_attr_init(&myAttr);			
	pthread_attr_getstacksize(&myAttr, &siz);	
	pthread_attr_getstackaddr(&myAttr, &stck);	
	
	printf("default address of stack : %08x  -->> default size of stack : %d\n", stck, siz);
	
	my_stack = (void*)malloc(my_stksize);		
	
	pthread_attr_setstack(&myAttr, my_stack, my_stksize);		
	
	pthread_create(&tid1, &myAttr, func1, NULL);
	
	
	pthread_attr_getstack(&myAttr, &stck, &siz);			
	
	printf("\ndefault address of stack : %08x  -->> default size of stack : %d\n", stck, siz);
	
	return 0;
}

