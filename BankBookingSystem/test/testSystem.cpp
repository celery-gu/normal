#include "queue_system.h"
#include <cassert>	
#include <cstdlib>
	using namespace std;

QueueSystem qs(200);

void testCreate() {
	assert(qs.rest() == 200);
}

void testExpand() {
	qs.expand(100);
	assert(qs.rest() == 300);
}

void testGetTicket() {
	int tk = qs.getTicket();
	assert(tk == 100);
	assert(qs.rest() == 299);
	
	int tk2 = qs.getTicket();
	assert(tk2 == 101);
	assert(qs.rest() == 298);
	
	for (int i = 0; i < 10; ++i) {
		qs.getTicket();
	}
}

void testQuery() {
	Position pos = qs.query(100);
	assert(pos.getDesk() == 1);
	assert(pos.getPosition() == 1);
}

void testCall() {
	assert(qs.call(1) == 100);
}

void testFinish() {
	qs.finish(1, "Great");
	qs.finish(2, "awfual");
}

void testCallNotResponse() {
	for (int i = 0; i < 1; ++i) {
		qs.callNoResponse(3);
	}
	for (int j = 0;  j < 2; ++j) {
		qs.callNoResponse(4);
	}
}

void testInsert() {
	qs.insert(4, 107);
	qs.insert(3, 107);
	qs.insert(1, 107);
}

void testExchange() {
	qs.exchange(2, 4, 3);
}

int main() {
	testCreate();
	testExpand();
	testGetTicket();
	testQuery();
	testCall();
	testFinish();
	testCallNotResponse();
	testInsert();
	testExchange();
	qs.print();
	system("pause");
	return 0;
}