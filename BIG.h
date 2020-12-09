#include <afxwin.h>
#include <stdio.h>
class BIG
{
public:
	BIG() {CString num = '0'; lenth = 1; Num = new char[lenth]; strcpy(Num, num);}
	BIG(CString number) { CString num = number; lenth = num.GetLength(); Num = new char[lenth]; strcpy(Num, number); }
	~BIG() {};
	CString shownum();
	void setnum(int num) 
	{
		CString number;
		number.Format("%d", abs(num));
		lenth = number.GetLength();
		delete Num;
		Num = new char[lenth];
		strcpy(Num, number);
	}
	friend BIG operator +(BIG& num1, BIG& num2)
	{
		CString  answer = num1.Add(num1.shownum(), num2.shownum());
		return BIG(answer);
	}

	friend BIG operator +(CString& num1, BIG& num2)
	{
		BIG Num1(num1);
		return Num1 + num2;
	}

	friend BIG operator +(BIG& num1, CString& num2)
	{
		BIG Num2(num2);
		return Num2 + num1;
	}

	friend BIG operator -(BIG& num1, BIG& num2)
	{
		BIG  answer = num1.Sub(num1.shownum(), num2.shownum());
		return BIG(answer);
	}

	friend BIG operator -(CString& num1, BIG& num2)
	{
		BIG Num1;
		return Num1-num2;
	}

	friend BIG operator -(BIG& num1, CString& num2)
	{
		BIG Num2;
		return Num2 - num1;
	}

	friend BIG operator *(BIG& num1, BIG& num2)
	{
		BIG  answer = num1.Mult(num1.shownum(), num2.shownum());
		return BIG(answer);
	}

	friend BIG operator *(BIG& num1, CString& num2)
	{
		BIG Num2;
		return Num2 * num1;
	}

	friend BIG operator *(CString& num1, BIG& num2)
	{
		BIG Num1;
		return Num1 * num2;
	}

	friend BIG operator /(BIG& num1, BIG& num2)
	{
		CString  answer = num1.Divide(num1.shownum(), num2.shownum());
		if (answer[0] != '里')
			return BIG(answer);
		else return BIG("0");
	}

	friend BIG operator /(CString& num1, BIG& num2)
	{
		BIG Num1;
		return Num1 / num2;
	}

	friend BIG operator /(BIG& num1, CString& num2)
	{
		BIG Num2;
		return Num2 / num1;
	}

private:
	char* Num;										//动态数组以保证数组大小足够储存数据
	int lenth;
	//CString num;
	CString Add(CString num1, CString num2);		//加法
	CString Sub(CString num1, CString num2);		//减法
	CString Mult(CString num1, CString num2);		//乘法
	CString Mult(CString num1, int num2);			//重定义乘法
	CString Mult(int num1, CString num2);			
	CString Divide(CString num1, CString num2);		//除法
	bool larger_eq_than(CString a, CString b);		//比较CString形式的整数大小，将用于内部使用
	bool larger_than(CString a, CString b);
	CString Toscientific_notation(CString num);		//转化为科学计数法
	CString scientific_notation_To_num(CString num);//科学计数法转化为普通数

};
