#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int main(){
    int msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    if(msgid==-1){
        perror("msgget failed ");
        return 1;
    }
    struct message ms;
    ms.msg_type = 1;
    for(int i=0;i<5;i++){
        snprintf(ms.msg_text, MSG_SIZE, "Message %d from sender", i+1);
        if(msgsnd(msgid, &ms, sizeof(ms.msg_text), 0) == -1){
            perror("msgsnd failed");
            return 1;
        }
        printf("Msg sent : %s\n", ms.msg_text);
    }
    return 0;
}
