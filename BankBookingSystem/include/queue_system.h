#include "log.h"
#include "resume.h"
#include "rest_ticket.h"
#include "desk_ticket.h"

class Position {
	public:
	Position() {}
	Position(int desk, int position):desk(desk), position(position){}
	friend ostream& operator << (ostream& out, Position pos) {
		out<<"Desk : "<<pos.desk<<"\tPosition : "<<pos.position;
		return out;
	}
	int getDesk() {
		return desk;
	}
	int getPosition() {
		return position;
	}
	protected:
		int desk;
		int position;
};

class QueueSystem {
	public:
		static const int NUM_OF_DESK = 4;
			QueueSystem(int total):rt(total) {
		}
		int getTicket() {
			int ticket = rt.get();
			int desk = getDesk(ticket);
			dt[desk].push(ticket);
			return ticket;
		}
	
		int getDesk(int ticket) {
			return ticket % NUM_OF_DESK;
		}
	
		int backTicket(int ticket) {
			rt.push(ticket);
		}
	
		int expand(int new_space) {
			rt.expand(new_space);
		}
	
		int call(int desk) {
			--desk;
			return dt[desk].call();
		}
	
		void callNoResponse(int desk) {
			--desk;
			static int times = 0;
			int ticket = dt[desk].finish();

			times %= 3;
			dt[desk].push(ticket);
			
		}
	
		int insert(int desk, int ticket) {
			--desk;
			Position pos = query(ticket);
			if (pos.getPosition() == 0) 
				return -1;
			
			dt[pos.getDesk() - 1 ].erase(pos.getPosition() - 1 );
			dt[desk].insert(ticket);
			log.push(LogUnit(ticket, desk, "insert"));
		}
	
		int exchange(int num, int from, int to) {
			from--;
			to--;
		//	cout<<from<<to<<endl;
			num = num < dt[from].size() ? num : dt[from].size();
			for (int i = 0; i < num; ++i) {
				int ticket = dt[from].pop_back();
				dt[to].push(ticket);
				log.push(LogUnit(ticket, to, "exchange"));
			//	cout<<i<<from<<to<<endl;
			}

		}
	
		Position query(int ticket) {
			int desk = log.search(ticket);
			if (desk == -1) {
				desk = getDesk(ticket);
			}
			int pos = dt[desk].find(ticket);
			return Position(desk + 1, pos + 1);
		}
	
		void finish(int desk, string review) {
			--desk;
			int ticket = dt[desk].finish();
			ResumeUnit ru(ticket, review);
			rsm[desk].push(ru);
		}
		int rest() {
			return rt.rest();
		}
		void print() {
			cout<<"Cur Desk Situation"<<endl;
			for (int i = 0; i < NUM_OF_DESK; ++i) {
				cout << "Desk " << i+1<<"     ----    ";
				dt[i].print();
			}
			cout<<endl;
			cout<<"Resumption"<<endl;
			for (int i = 0; i < NUM_OF_DESK; ++i) {
				cout << "Resume " << i+1<<"     ----    ";
				rsm[i].print();
				cout<<endl;
			}
			cout<<endl;
			cout<<"Log"<<endl;
			log.print();
		}
	private:
		RestTicket rt;
		DeskTicket dt[NUM_OF_DESK];
		Resume rsm[NUM_OF_DESK];
		Log log;
};
const int QueueSystem::NUM_OF_DESK;