
#include<iostream>

using  namespace std;
struct node //Định nghĩa node
{
	float info;
	node *next;
};

struct list //Định nghĩa danh sách
{
	node *first;
	node *last;
};

void KhoiTao(list &d) //Khởi tạo danh sách
{
	d.first = d.last = NULL;
}

void Xem(list d) //Xem danh sách
{
	if (d.first == NULL) { cout << "\nDanh sach rong"; return; }
	node *p = d.first;
	while (p != NULL)
	{
		cout <<" "<< p->info;
		p = p->next;
	}
	cout << endl;
}

void ThemDau(list &d, float x) //Thêm phần tử vào đầu danh sách
{
	node *p = new node; //Khai báo con trỏ kiểu node
	p->info = x;
	p->next = NULL;
	if (d.first == NULL)
	{
		d.first = d.last = p;
	}
	else
	{
		p->next = d.first; //p trỏ tới node đầu của danh sách
		d.first = p; //p trở thành node đầu của danh sách
	}
}

void ThemCuoi(list &d, float x) //Thêm phần tử vào cuối danh sách
{
	node *p = new node; //Khai bảo con trỏ kiểu node
	p->info = x;
	p->next = NULL;

	if (d.first == NULL) //Nếu danh sách rỗng
	{
		d.first = d.last = p;
	}

	else
	{
		d.last->next = p; //Node cuối của danh sách trỏ tới p
		d.last = p; //p trở thành node cuối mới của danh sách
	}
}

void XoaCuoi(list &d) //Xóa phần tử cuối cùng của danh sách
{
	if (d.first == NULL) return; //Nếu danh sách rỗng thì thoát khỏi hàm
	node *p = d.first; //khai báo con trỏ gán với node đầu của danh sách
	node *r = d.last; //khai báo con trỏ gán với node cuối của danh sách
	if (p == r) //Nếu danh sách chỉ có một node
	{
		d.first = d.last = NULL;
		delete p;
	}
	else //Nếu không p chạy tới node cận cuối cùng
	{
		while (p->next != r) p = p->next;
		p->next = NULL; //p trỏ đến NULL
		d.last = p; //Node cận cuối p trở thành node cuối
		delete r; //Xóa node cuối ban đầu
	}
}

void XoaDau(list &d){

node *p = d.first;
if(p == NULL) return;
if( d.first == d.last) d.first= d.last = NULL;
else
    {
    d.first = p->next;
    if(p ==d.last) d.last->next = d.first;
    }
    delete p;
}


void loop(list &d){



    if(d.first ==NULL ) return;
    node *p = d.first->next;

    if (d.first == d.last)  return;
	else
	{
        node *p = d.first->next;
        d.first->next = NULL;
        d.last->next = d.first;
        d.last = d.first;
        d.first = p;
    }

    /*
    // tạo biến tạm lưu lại first element hiện tại
node *p = d.first;
// chuyển first element sang vị trí của d.second
d.first = p->next;
// trỏ new last element vào phía sau old last element
// thằng new last element chính là p hay old d.first.
d.last->next = p;
// nội dung của new last element
d.last = p;
// gán *next = null để xác nhận nó là thằng cuối cùng
d.last->next = NULL;

*/
}
int main()
{
    int a,b,n;
	struct list d;
//	node tmp = new *tmp;

	KhoiTao(d);
  cout<<"So kich ban va uu tien: ";
  cin>>a>>b;


  for(int i=0; i<a; i++){
    cin>>n;
	ThemCuoi(d, n);
	}
	  XoaDau(d);
cout<<"sau khi xoa dau";  Xem(d);

loop(d); cout<<"loop 1 lan :";	Xem(d);
loop(d); cout<<"loop 2 lan :";	Xem(d);

XoaDau(d);
loop(d); cout<<"xoa first, loop :";	Xem(d);
XoaCuoi(d);
loop(d); cout<<"xoa last, loop :";	Xem(d);

loop(d); Xem(d);

	return 0;
}

