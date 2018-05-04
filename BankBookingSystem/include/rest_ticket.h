#include <deque>
#include <iostream>
	using namespace std;
	
class RestTicket: private deque<int> {      //余票队列 
	public:
		RestTicket(int total):start_ticket(100),last_ticket(start_ticket){    //总票数 
			expand(total);
		}
		int get() {                        //打印出一张票就将票号从队首删去
			if (empty()) {
				return -1;
			}
			int cur = front();
			pop_front();
			return cur;
		}

		int expand(int added) {            //计算有多少票，可以添加票
			int total = last_ticket + added;
			for (; last_ticket < total; ++last_ticket) {
				push_back(last_ticket);
			}						
		}
		
		void push(int toPut) {            //队首增加一个号码
			push_front(toPut);
		}
		
		int rest() {                      //有多少余票      
			return deque<int>::size();
		}
		
		int min_ticket_num() {            //返回开始的票号，这里我们设定为100
			return start_ticket;
		}
		
		int max_ticket_num() {            //返回队尾的票号
			return last_ticket - 1;
		}
		
		bool empty() {                    //判断是否有票
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
