// common.h
#ifndef COMMON_H
#define COMMON_H

#define MSG_KEY 0x1234     // Unique key for message queue
#define MSG_SIZE 100       // Max size of message text

// Define the message structure
struct message {
    long msg_type;         // Message type (must be > 0)
    char msg_text[MSG_SIZE];
};

#endif
