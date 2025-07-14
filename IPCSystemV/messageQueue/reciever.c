#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int main(){
    int msgid = msgget(MSG_KEY, 0666);
    if(msgid == -1){
        perror("msgget failed");
        return 1;
    }

    struct message ms;
    for(int i=0;i<5;i++){
        if(msgrcv(msgid, &ms, sizeof(ms.msg_text), 1,0 )==-1){
            perror("msgrcv failed");
            return 1;
        }
        printf("Recieved message : %s\n", ms.msg_text);
    }

    msgctl(msgid, IPC_RMID, NULL);
}

