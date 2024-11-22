#include<stdio.h>
#include<string.h>

void crc(char msg[], char key[], char temp[], int msg_len, int key_len) {
    int i, x = key_len;
    char temp1[10];

    while (x <= msg_len) {
        if (temp[0] == '1') {
            for (i = 0; i < key_len; i++) {
                temp[i] = (temp[i] == key[i]) ? '0' : '1'; 
            }
        }

        for (i = 0; i < key_len - 1; i++) {
            temp1[i] = temp[i + 1];
        }

        temp1[key_len - 1] = msg[x]; 
        temp1[key_len] = '\0';       

        strcpy(temp, temp1); 
        x++;
    }
}

int main() {
    char key[10], msg[30], temp[10]; 
    int i, msg_len, key_len;

    printf("\nSender Side\n");
    printf("Enter message: ");
    scanf("%s", msg);
    printf("Enter key: ");
    scanf("%s", key);

    msg_len = strlen(msg);
    key_len = strlen(key);

    for (i = 0; i < key_len - 1; i++) {
        msg[msg_len + i] = '0';
    }
    msg[msg_len + key_len - 1] = '\0';

    for (i = 0; i < key_len; i++) {
        temp[i] = msg[i];
    }
    temp[key_len] = '\0';

    crc(msg, key, temp, strlen(msg), key_len);

    printf("CRC remainder (sender): %s\n", temp);

    for (i = 0; i < key_len - 1; i++) {
        msg[msg_len + i] = temp[i];
    }
    msg[msg_len + key_len - 1] = '\0';
    printf("Message with CRC (transmitted): %s\n", msg);

    printf("\nReceiver Side\n");
    printf("Enter received message: ");
    scanf("%s", msg);  

    msg_len = strlen(msg); 
    for (i = 0; i < key_len; i++) {
        temp[i] = msg[i];
    }
    temp[key_len] = '\0';

    crc(msg, key, temp, msg_len, key_len);

    int error = 0;
    for (i = 0; i < key_len - 1; i++) {
        if (temp[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error) {
        printf("Error detected in received message.\n");
    } else {
        printf("No error detected in received message.\n");
    }

    return 0;
}