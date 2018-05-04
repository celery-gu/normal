	
class DeskTicket : private deque<int> {
	
	public:

	
		DeskTicket() {}                  //构造函数 
		
		int finish() {                   //完成一人就将它从队首删除
			int cur = front();           //获得最前面的票号 
			pop_front();                 //删掉该人 
			return cur;
		}
		
		void push(int toPush) {          //有一个人排到了队尾，toPush是该人的票号 
			push_back(toPush);
		}
		
		int size() {
			return deque<int>::size();   //当前这个柜台有多少人 
		}
		
		int call() {                     //叫号
			return front();              //返回最前面那人的票号 
		}
		
		void insert(int toInsert) {      //有人插队了，将此人插入队首
			push_front(toInsert);
		}
		
		void erase(int position) {       //将此人从队列中删去，估计走了 
			deque<int>::erase(begin() + position);   //调用deque中的函数 
		}
		
		int find(int num) {              //找到票号num在这个柜台排第几位 
			int position = 0;
			for (deque<int>::iterator iter = begin(); iter != end(); ++iter) {
				if (*iter == num) {
					return position;
				}
				++position;
			}
			return -1;
		}
		
		bool empty() {                  //判断这个柜台有没有人
			return deque<int>::empty(); //调用deque中的函数 
		}
		void print() {                  //将这个柜台排了哪些人打印出来
			for (deque<int>::iterator iter = begin(); iter != end(); ++iter) {
				cout<<*iter<<"\t";
			}
			cout<<endl;
		}

		int pop_back() {               //将最后一位的号码返回，并将这个队列最后一位删除 
			int bk = back(); 
			deque<int>::pop_back();
			return bk;
		}
};


/*
int main() {
	RestTicket rt(200);
	DeskTicket dt[DeskTicket::NUM];
	bool b = true;
	while (b) {
		for (int i = 0; i < DeskTicket::NUM; i++) {
			if (rt.empty()) {
				b = false;
				break;
			}
			dt[i].push(rt.get());
		}
	}
	for (int i = 0; i < DeskTicket::NUM; i++) {
		dt[i].print();
	}
	for (int i = 0; i < DeskTicket::NUM; i++) {
		for (int j = 0; j < 5; j++) 
			dt[i].finish();
	}
	for (int i = 0; i < DeskTicket::NUM; i++) {
		dt[i].print();
	}
	return 0;
}
*/
