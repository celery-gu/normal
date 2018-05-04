#include <deque>
#include <iostream>
#include <string>
	using namespace std;
	
class LogUnit {                               //消息事件类，相当于结点 
	public:
		LogUnit() {}                          //构造函数 
		LogUnit(int num, int desk, string reason) 
				: num(num), desk(desk), reason(reason) {
		}
		int getNum() {                        //票号 
			return num;
		}
		int getDesk() {                       //柜台号 
			return desk;
		} 
		string getReason() {                  //发生事件 
			return reason;
		}
		void print() {
			cout << num << " " << reason << " to " << desk + 1 << endl;
		}
	protected:
		int num;
		int desk;
		string reason;
};

class Log : public deque<LogUnit> {
	public:
		Log() {}
		void push(const LogUnit& logUnit) {  //把这个消息插入尾部 
			push_back(logUnit);
		}
		LogUnit get() {                      //将这个事件处理完从队首删除
			LogUnit cur = front();
			pop_front();
			return cur;
		}
		int search(int num) {                //通过号码找到这个事件并输出号码、柜台号、发生事件，返回柜台号
			int pos = -1;
			for (deque<LogUnit>::iterator iter = begin(); iter != end(); ++iter) {
				if (iter->getNum() == num) {
					pos = iter->getDesk();
				}
			}
			return pos;
		}
		void print() {                       //打印这个号码的号码、柜台号、发生事件 
			for (deque<LogUnit>::iterator iter = begin(); iter != end(); ++iter) {
				iter->print();	
			}
		}
};
