/*
 * Copyright (C) 2008, Robert Oostenveld
 * F.C. Donders Centre for Cognitive Neuroimaging, Radboud University Nijmegen,
 * Kapittelweg 29, 6525 EN Nijmegen, The Netherlands
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

/* this is used for debugging */
int verbose = 0;

void cleanup_socket(int *arg) {
	if (verbose>0) fprintf(stderr, "cleanup_socket: s = %d\n", *arg);
	if ((*arg)>0) {
		close_connection(*arg);
    }
    *arg = 0;
	return;
}

void cleanup_message(void **arg) {
	message_t *message = (message_t *)*arg;
	if (verbose>0) fprintf(stderr, "cleanup_message()\n");
	if (message) {
		FREE(message->def);
		FREE(message->buf);
		FREE(message);
	}
	return;
}

void cleanup_header(void **arg) {
	header_t *header = (header_t *)*arg;
	if (verbose>0) fprintf(stderr, "cleanup_header()\n");
	if (header) {
		FREE(header->def);
		FREE(header->buf);
		FREE(header);
	}
	return;
}

void cleanup_data(void **arg) {
	data_t *data = (data_t *)*arg;
	if (verbose>0) fprintf(stderr, "cleanup_data()\n");
	if (data) {
		FREE(data->def);
		FREE(data->buf);
		FREE(data);
	}
	return;
}

void cleanup_event(void **arg) {
	event_t *event = (event_t *)*arg;
	if (verbose>0) fprintf(stderr, "cleanup_event()\n");
	if (event) {
		FREE(event->def);
		FREE(event->buf);
		FREE(event);
	}
	return;
}

void cleanup_buf(void **arg) {
	if (verbose>0) fprintf(stderr, "cleanup_buf()\n");
	if (*arg) {
		FREE(*arg);
	}
	return;
}

