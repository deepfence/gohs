#include <hs.h>

int found;
unsigned long long last_index;
char *data;
unsigned int data_size;

int hsGlobalMatchEventCallback(unsigned int id, unsigned long long from, unsigned long long to, unsigned int flag, void* dummy) {
	found = 1;
	last_index = to;
	return 0;
}

void call_hs(hs_database_t* db, hs_scratch_t *s) {
	hs_scan(db, data, data_size, 0, s, hsGlobalMatchEventCallback, 0);
}
