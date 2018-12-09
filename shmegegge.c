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
    printf("This is the data in this shared memory segment: %s\n", data);
  }

  printf("Do you want to change the data in this shared memory segment? (y/n):\n");
  char line[100];
  fgets(line, 100, stdin);
  if (line[0] == 'y'){
    printf("Enter the new data:\n");
    fgets(line, 100, stdin);
    strcpy(data,line);
    printf("The data in the shared memory segment is now: %s\n", data);
  }
  else if(*line == 'n'){
    printf("Understood! No changes to the data in this shared memory segment.\n");
  }
  shmdt(data);
  

  return 0;
}
