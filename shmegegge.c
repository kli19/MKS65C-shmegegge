#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  // generates key
  key_t key = ftok("shmegegge.c", 'A');
  printf("key: %d\n", key);

  // gets id
  int shmid = shmget(key, 100, 0666|IPC_CREAT);
  printf("id: %d\n", shmid);

  // attach to shared memory
  char * data = shmat(shmid, 0, 0);
  if (data == (char *) (0)){
    printf("shmat error\n");
  }
  printf("data: %s\n", data);

  if (!*data){
    printf("You've just created a shared memory segment!\n");
  }
  else{
    printf("This is the data in this shared segment: %s\n", data);
  }

  printf("Do you want to change the data in this shared segment?\n");
  
  return 0;
}
