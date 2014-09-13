#include<bits/stdc++.h>
using namespace std;
class element{
	public:
		int num;
		int count;
		element()
		{
			count = 1;
		}
};
bool myfunction(element A,element B)
{
	if(A.count>B.count)
	return 0;
	else return 1;
}

int main()
{
	int T,elements=0;
	cin>>T;
	cout<<"Frequency Of elements";
	int size;
	cin>>size;
	vector<element> vect;
	vector<int> vect2;
	while(T--)
	{
		int data;
		cin>>data;
		if(find(vect2.begin(),vect2.end(),data)==vect2.end())
		{
			//Element Not Present
			cout<<"NOt"<<endl;
			if(elements!=size)
			{
				element temp;
				temp.num = data;
				vect.push_back(temp);
				make_heap(vect.begin(),vect.end(),myfunction);
				vect2.push_back(data);
				elements++;
			}
			else
			{//evict
				for(int i = vect.size()-1;i>=0;i++)
				{
					if(vect[i].count == 1)
					{
						vect[i].num = data;
					vect2.push_back(data);
					break;
					}
				}
			}
		}
		else
		{
			for(int i=0;i<vect.size();i++)
			{
				if(vect[i].num==data)
				{
					(vect[i].count)++;
					make_heap(vect.begin(),vect.end(),myfunction);
					cout<<"Yes"<<vect[i].count<<endl;
					break;
				}
			}
		}
	}
	for(int i=0;i<vect.size();i++)
	{
		cout<<vect[i].num<<endl;
	}
}

