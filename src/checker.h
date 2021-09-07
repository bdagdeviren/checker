//
// Created by Burak on 7.09.2021.
//

#ifndef CHECKER_CHECKER_H
#define CHECKER_CHECKER_H

#define NO_SSL

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdlib.h>
#include <string.h>

#include <civetweb.h>
#include <log.h>
#include <signal.h>
#include <cjson/cJSON.h>
#include <direct.h>
#include <stdio.h>
#include <sys/stat.h>

#ifdef NO_SSL
#define PORT "8089"
#define HOST_INFO "http://localhost:8089"
#else
#define PORT "8843"
#define HOST_INFO "https://localhost:8843"
#endif

extern int exitNow;

int server();

void initialize_route(struct mg_context *ctx);
int ExampleHandler(struct mg_connection *conn, void *cbdata);
int ExitHandler(struct mg_connection *conn, void *cbdata);
int FileHandler(struct mg_connection *conn, void *cbdata);

int SendJSON(struct mg_connection *conn, cJSON *json_obj);
int log_message(const struct mg_connection *conn, const char *message);
void sigHandler();
int checkIfFileExists(const char* filename);

#endif //CHECKER_CHECKER_H
