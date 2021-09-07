#include <stdio.h>
#include "src/checker.h"

int exitNow = 0;

int main() {
    const char *options[] = {"listening_ports",PORT,"request_timeout_ms","10000","error_log_file","error.log","enable_auth_domain_check","no","num_threads","2",0};

    struct mg_callbacks callbacks;
    struct mg_context *ctx;

    mg_init_library(0);

    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.log_message = log_message;

    ctx = mg_start(&callbacks, 0, options);

    if (ctx == NULL) {
        log_error("Err -> %s",stderr);
        log_error("Cannot start CivetWeb - mg_start failed.");
        return EXIT_FAILURE;
    }

    initialize_route(ctx);

    log_info("Server Listening Address: %s", HOST_INFO);
    log_info("Shutdown Server:  %s%s", HOST_INFO,"/shutdown");

    while (!exitNow) {
#ifdef _WIN32
        Sleep(500);
#else
        sleep(1);
#endif
    }

    mg_stop(ctx);

    log_info("Server shutdown.");

    return EXIT_SUCCESS;
}
