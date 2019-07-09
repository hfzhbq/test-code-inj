/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: root
 *
 * Created on March 9, 2019, 7:29 PM
 */

//LD_PRELOAD=./libinjection-so.so ./test

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TESTFILE "./temp"

#undef DEBUG_INJ
/*
 *
 */
int main(int argc, char** argv) {

#ifdef DEBUG_INJ
    int a = 1;
    while (a) {
        sleep(1);
    }
#endif

    int fd;
    int nwrite;
    char buff[1024]="hello hongbq";
    char buff1[1024]="hello again\n";
    fd = open(TESTFILE, O_CREAT | O_RDWR, 0644);
    nwrite = write(fd, buff, strlen(buff));
    nwrite = write(fd, buff1, strlen(buff1));
    close(fd);

    return (EXIT_SUCCESS);
}

