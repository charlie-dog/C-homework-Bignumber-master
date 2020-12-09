#include "BIG.h"
#include <string>
#include <stdio.h>
#include <cmath>
CString BIG::shownum()
{
	CString N = Num;
	if (N == "")return "���ڸ���ħ��";
	return N;
}

CString BIG::Add(CString num1, CString num2)						//�ӷ�
{
	CString Num1 = num1, Num2 = num2, Answer, mid;
	int len1, len2;
	char p[1];
	len1 = Num1.GetLength();
	len2 = Num2.GetLength();
	int n1 = 0, n2 = 0, up = 0, index = 1, now = 0, sum;
	while (-1 != len1 - index && -1 != len2 - index)					//�������ĵ�λ��ʼ�ӣ�ֱ���ϴ��������һλ
	{
		p[0] = Num1[len1 - index];
		n1 = atoi(p);
		p[0] = Num2[len2 - index];
		n2 = atoi(p);
		sum = n1 + n2 + up;
		if (sum >= 10)
		{
			now = sum - 10;
			up = 1;													//�н�λup=1
		}
		else
		{
			up = 0;
			now = sum;
		}
		mid.Format("%d", now);
		Answer.Insert(0, mid);										//������õ��ġ�λ����������ǰ��
		index++;
	}
	if (-1 != len2 - index)											//����������ӵ�һ��������ʱ������Ƿ��λ
	{
		Num1 = Num2;
		index = len2 - index;
	}
	else
	{
		index = len1 - index;
	}
	if (index == -1 && up == 1)
	{
		Answer.Insert(0, "1");
	}
	while (index != -1)												//up��ʣ�µ������
	{
		p[0] = Num1[index];
		n1 = atoi(p);
		sum = up+n1;
		if (sum >= 10)
		{
			now =sum- 10;
			up = 1;
		}
		else
		{
			up = 0;
			now = sum;
		}
		mid.Format("%d", now);
		Answer.Insert(0, mid);
		index--;
		if (index == -1 && up == 1)Answer.Insert(0, "1");
	}
	return Answer;
}

CString BIG::Sub(CString num1, CString num2)
{
	if(larger_than(num2,num1))									//�ȱȽϼ�����num1��num2��֤num1>num2�����򽻻�����ӡ�-��
	{
		CString num = Sub(num2, num1);
		num.Insert(0, "-");
		return num;
	}
	CString Num1 = num1, Num2 = num2, Answer, mid;
	int len1, len2;
	char p[1];
	len1 = Num1.GetLength();
	len2 = Num2.GetLength();
	int n1 = 0, n2 = 0, up = 0, index = 1, now = 0, sum;
	while (-1 != len1 - index && -1 != len2 - index)
	{
		p[0] = Num1[len1 - index];								//�õ���Ӧλ�ϵ���
		n1 = atoi(p);
		p[0] = Num2[len2 - index];
		n2 = atoi(p);
		sum = n1 - n2 - up;										//��Ӧλ���������ȥ��λ��
		if (sum < 0)											
		{
			now = sum+ 10;
			up = 1;												//������λ��up��1
		}
		else
		{
			up = 0;
			now = sum;
		}
		mid.Format("%d", now);
		Answer.Insert(0, mid);
		index++;
	}
	if (-1 != len2 - index)										//��һ���������ꡰʱ������һ�����Ͽ��Ƿ�����λ
	{
		Num1 = Num2;
		index = len2 - index;
	}
	else
	{
		index = len1 - index;
	}
	while (index != -1)
	{
		p[0] = Num1[index];
		n1 = atoi(p);
		sum = -up + n1;
		if (sum < 0)
		{
			now =sum+ 10;
			up = 1;
		}
		else
		{
			up = 0;
			now = sum;
		}
		mid.Format("%d", now);
		if(index!=0||now!=0)
		Answer.Insert(0, mid);
		index--;
	}
	index = 0;
	while (Answer.GetLength() > 1 && Answer[0] == '0')
		Answer = Answer.Right(Answer.GetLength()-1);
	return Answer;
}


CString BIG::Mult(CString num1, CString num2)					
{
	if (num1 == '0' || num2 == '0')return "0";
	CString Num1 = num1, Num2 = num2, Answer='0', mid='0';
	int len1, len2;
	char p[1];
	len1 = Num1.GetLength();
	len2 = Num2.GetLength();
	CString MULT1='0',MULT2='0';
	int n1 = 0, n2 = 0, up = 0, index1 = 1, index2, now = 0;
	while (len1 - index1 != -1)											
	{
		p[0] = Num1[len1 - index1];											//��ֳ���
		n1 = atoi(p);
		index2 = 1;
		up = 0;
		while (len2 - index2 != -1)											//��ֱ�����
		{
			p[0] = Num2[len2 - index2];
			n2 = atoi(p);
			now = n1 * n2;
			mid.Format("%d", now);
			for (int i = 0; i < index1 + index2 - 2; i++)mid.Append("0");	//�ò�ֳ�����ת��Ϊint�����γ˱������ĸ�λ��תΪint������ӡ�0������Ϊ�������ĺͳ�����λ����10��n��
			Answer=Add(mid, Answer);
			index2++;
		}
		index1++;

	}
	return Answer;
}

CString BIG::Mult(int num1, CString num2)
{
	CString Num1;
	Num1.Format("%d", num1);
	return Mult(Num1, num2);
}

bool BIG::larger_than(CString a, CString b)
{
	if (a.GetLength() < b.GetLength())return false;										//ͨ���������ȱȽϴ�С
	if (a.GetLength() > b.GetLength())return true;
	else
	{
		CString an, bn;
		int count = 0;
		an = a[0];
		bn = b[0];
		while (1)																		//������ͬ�Ӹ�λ����λ�Ƚ�
		{
			if (atoi(an) > atoi(bn))return true;
			else if (atoi(an) < atoi(bn))return false;
			count++;
			if (count == a.GetLength())break;
			an = a[count];
			bn = b[count];
		}
		return false;
	}
}

bool BIG::larger_eq_than(CString a, CString b)//a>=b
{
	if (a.GetLength() < b.GetLength())return false;									//ԭ��ͬ��
	if (a.GetLength() > b.GetLength())return true;
	else
	{
		CString an , bn;
		int count = 0;
		an = a[0];
		bn = b[0];
		while (1)
		{
			if (atoi(an) > atoi(bn))return true;
			else if (atoi(an) < atoi(bn))return false;
			count++;
			if (count == a.GetLength())break;
			an = a[count];
			bn = b[count];
		}
		return true;
	}
}

CString BIG::Divide(CString num1, CString num2)//num1/num2
{
	CString Num1 = num1, Num2 = num2, Answer = "", mid = "",mid2;
	int len1, len2;
	char p[1],q[1];
	len1 = Num1.GetLength();
	len2 = Num2.GetLength();
	CString devided = '1', devider = '1';
	int n1 = 0, n2 = 0, up = 0, index1 = 1, index2, now = 0,devideanswer,count=0;
	if (num1[0] == '0')return "0.0e1";
	if (num2[0] == '0')return "���ڸ���ħ��";
	for (int i = 0; i < len1 - len2; i++)									//�ȷŴ���������ʹ���������ڳ��������������������1
	{
		Num2.Append("0");
		count++;
	}

	while (larger_than(Num2, Num1))
	{
		Num1.Append("0");
		count--;
	}
	mid = Num1;
	for (int i = 0; i <= 2; i++)
	{
		for (int d = 1; d <= 10; d++)
		{
			if (larger_than(Mult(d, Num2), mid))							//��1-10����һ����nʹ��n*����>����������λ�𰸼�Ϊn-1
			{
				now = d - 1;
				mid2.Format("%d", now);
				Answer.Append(mid2);
				break;
			}
		}
		mid = Sub(mid , Mult(now, Num2));
		mid = Mult(mid , "10");												//��������ȥ�����˴𰸵õ�������������ʮ
	}
	p[0] = Answer[2];
	up = atoi(p);
	if (up >= 5)
	{
		Answer = Add(Answer, "10");
		Answer = Answer.Mid(0, 3);
		if (Answer == "100")
		{
			count++;
			Answer = "10";
		}
		else
		{
			Answer = Answer.Mid(0, 2);

		}
	}
	else
	{
		Answer = Answer.Mid(0, 2);
	}
	Answer.Insert(1, ".");
	mid.Format("e%d", count);
	Answer.Append(mid);
	return Answer;
}



CString BIG::Toscientific_notation(CString num)								//��ѧ������ת��
{
	CString nu = num,a;
	int index = 0;
	char now = nu[0];
	index = nu.Find('.');
	if (index == -1)
	{
		index = nu.GetLength() - 1;
		nu.Insert(1, '.');
		a.Format("e%d", index);
		nu.Append(a);
		return nu;
	}
	else
	{
		index = index - 1;
		nu.Remove('.');
		nu.Insert(1, '.');
		nu.Insert(1, '.');
		a.Format("e%d", index);
		nu.Append(a);
		return nu;
	}
}
CString BIG::scientific_notation_To_num(CString num)
{
	CString nu = num, nu1;
	int index = 0,lenofnum,dotindex,zeroindex;
	index=nu.Find('e');
	nu1 = nu.Left(index);
	index=atoi(nu.Right(index));
	lenofnum = nu1.GetLength();
	if (nu1.Find('.') == -1)
	{
		dotindex = index + lenofnum;
		if (dotindex <= 0)
		{
			for (int i = 0; i < -dotindex; i++)
			{
				nu1.Insert(0, '0');
			}
			nu1.Insert(0, "0.");
			return nu1;
		}
		else
		{
			for (int i = 0; i < dotindex - lenofnum; i++)
			{
				nu1.Append("0");
			}
			if (nu1.GetLength()==dotindex)
			{
				nu1.Append(".0");
				return nu1;
			}
			else
			{
				nu1.Insert(dotindex, ".");
				return nu1;
			}
		}
	}
	else
	{
		dotindex = index + nu1.Find(".");
		if (dotindex <= 0)
		{
			for (int i = 0; i < -dotindex; i++)
			{
				nu1.Insert(0, '0');
			}
			nu1.Insert(0, "0.");
			return nu1;
		}
		else
		{
			for (int i = 0; i < dotindex - lenofnum; i++)
			{
				nu1.Append("0");
			}
			if (nu1.GetLength() == dotindex)
			{
				nu1.Append(".0");
				return nu1;
			}
			else
			{
				nu1.Insert(dotindex, ".");
				return nu1;
			}
		}
	}
}