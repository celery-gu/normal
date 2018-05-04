#include <deque>
#include <iostream>
#include <string>
	using namespace std;
	
class LogUnit {                               //��Ϣ�¼��࣬�൱�ڽ�� 
	public:
		LogUnit() {}                          //���캯�� 
		LogUnit(int num, int desk, string reason) 
				: num(num), desk(desk), reason(reason) {
		}
		int getNum() {                        //Ʊ�� 
			return num;
		}
		int getDesk() {                       //��̨�� 
			return desk;
		} 
		string getReason() {                  //�����¼� 
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
		void push(const LogUnit& logUnit) {  //�������Ϣ����β�� 
			push_back(logUnit);
		}
		LogUnit get() {                      //������¼�������Ӷ���ɾ��
			LogUnit cur = front();
			pop_front();
			return cur;
		}
		int search(int num) {                //ͨ�������ҵ�����¼���������롢��̨�š������¼������ع�̨��
			int pos = -1;
			for (deque<LogUnit>::iterator iter = begin(); iter != end(); ++iter) {
				if (iter->getNum() == num) {
					pos = iter->getDesk();
				}
			}
			return pos;
		}
		void print() {                       //��ӡ�������ĺ��롢��̨�š������¼� 
			for (deque<LogUnit>::iterator iter = begin(); iter != end(); ++iter) {
				iter->print();	
			}
		}
};
