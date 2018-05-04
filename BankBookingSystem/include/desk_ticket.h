	
class DeskTicket : private deque<int> {
	
	public:

	
		DeskTicket() {}                  //���캯�� 
		
		int finish() {                   //���һ�˾ͽ����Ӷ���ɾ��
			int cur = front();           //�����ǰ���Ʊ�� 
			pop_front();                 //ɾ������ 
			return cur;
		}
		
		void push(int toPush) {          //��һ�����ŵ��˶�β��toPush�Ǹ��˵�Ʊ�� 
			push_back(toPush);
		}
		
		int size() {
			return deque<int>::size();   //��ǰ�����̨�ж����� 
		}
		
		int call() {                     //�к�
			return front();              //������ǰ�����˵�Ʊ�� 
		}
		
		void insert(int toInsert) {      //���˲���ˣ������˲������
			push_front(toInsert);
		}
		
		void erase(int position) {       //�����˴Ӷ�����ɾȥ���������� 
			deque<int>::erase(begin() + position);   //����deque�еĺ��� 
		}
		
		int find(int num) {              //�ҵ�Ʊ��num�������̨�ŵڼ�λ 
			int position = 0;
			for (deque<int>::iterator iter = begin(); iter != end(); ++iter) {
				if (*iter == num) {
					return position;
				}
				++position;
			}
			return -1;
		}
		
		bool empty() {                  //�ж������̨��û����
			return deque<int>::empty(); //����deque�еĺ��� 
		}
		void print() {                  //�������̨������Щ�˴�ӡ����
			for (deque<int>::iterator iter = begin(); iter != end(); ++iter) {
				cout<<*iter<<"\t";
			}
			cout<<endl;
		}

		int pop_back() {               //�����һλ�ĺ��뷵�أ���������������һλɾ�� 
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
