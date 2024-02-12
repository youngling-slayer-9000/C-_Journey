#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int get_shared_block(char* file , int size){
	key_t key;
	key = ftok(file , 0);
	if(key == -1)
		return -1;

	return shmget(key, size, 0666 | IPC_CREAT );
}

char* attach_to_shared(char* filename , int block_size){
	int shmid = get_shared_block(filename , block_size);
	if(shmid == -1)
		return NULL;
	char* result = shmat(shmid , NULL, 0);
	if(result == (char*)-1)
		return NULL;
	return result;
}

bool destroy_shared(char* filename){
	int block_id = get_shared_block(filename , 0)
	if(block_id == -1)
		return NULL;
	return(shmctl(block_id, IPC_RMID, NULL) != -1);
}


int main(int argc , int** argv){
	int key = ftok("prog.c" , 1);
	printf("%d", key);
}
