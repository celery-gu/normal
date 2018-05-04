#include <deque>
#include <string>
#include <iostream>
	using namespace std;
	
class ResumeUnit {               //工作类，每个柜台一个 
	public:
		ResumeUnit(){}
		ResumeUnit(const int num, string& remark) : num(num), remark(remark) {
		}
		void print() {
			cout<<num<<"   :   "<<remark;
		}
	private:
		int num;
		string remark;
};

class Resume : public deque<ResumeUnit> {
	public:
		Resume() {}
		void push(const ResumeUnit& ru) {
			push_back(ru);
		}
		
		ResumeUnit get() {
			ResumeUnit cur = front();
			pop_front();
			return cur;
		}
		
		void print() {
			for (deque<ResumeUnit>::iterator iter = begin(); iter != end(); ++iter) {
				iter->print();
			}
		}
		bool empty() {
			return deque<ResumeUnit>::empty();
		}
		int size() {
			return deque<ResumeUnit>::size();
		}
};
