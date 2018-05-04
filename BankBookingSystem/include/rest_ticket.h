#include <deque>
#include <iostream>
	using namespace std;
	
class RestTicket: private deque<int> {      //��Ʊ���� 
	public:
		RestTicket(int total):start_ticket(100),last_ticket(start_ticket){    //��Ʊ�� 
			expand(total);
		}
		int get() {                        //��ӡ��һ��Ʊ�ͽ�Ʊ�ŴӶ���ɾȥ
			if (empty()) {
				return -1;
			}
			int cur = front();
			pop_front();
			return cur;
		}

		int expand(int added) {            //�����ж���Ʊ���������Ʊ
			int total = last_ticket + added;
			for (; last_ticket < total; ++last_ticket) {
				push_back(last_ticket);
			}						
		}
		
		void push(int toPut) {            //��������һ������
			push_front(toPut);
		}
		
		int rest() {                      //�ж�����Ʊ      
			return deque<int>::size();
		}
		
		int min_ticket_num() {            //���ؿ�ʼ��Ʊ�ţ����������趨Ϊ100
			return start_ticket;
		}
		
		int max_ticket_num() {            //���ض�β��Ʊ��
			return last_ticket - 1;
		}
		
		bool empty() {                    //�ж��Ƿ���Ʊ
			return deque<int>::empty();
		}
		
	private:
		const int start_ticket;
		int last_ticket;
};



/*int main(int argc, char** argv) {
	RestTicket rt(200);
	cout<<rt.rest()<<endl;
	cout<<"get" << rt.get()<<endl;
	cout<<rt.rest()<<endl;
	rt.expand(100);
	cout<<rt.rest()<<endl;
	cout<<rt.get()<<endl;
	cout<<rt.rest()<<endl;
	rt.push(101);
	cout<<rt.rest()<<endl;
	cout<<rt.min_ticket_num()<<endl;
	cout<<rt.max_ticket_num()<<endl;
	return 0;
}*/
