#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>

using namespace std;

#define cehua 0
#define meishu 1
#define yanfa 2

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "worker:";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;
        v.push_back(worker);
    }    
}

//员工分组
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门编号
		int deptId = rand() % 3; // 0 1 2 

		//将员工插入到分组中
		//key部门编号，value具体员工
		m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGroup(multimap<int,Worker>&m)
{
    //0 A B C  1D E   2 F G
    cout<<"cehua:"<<endl;

    multimap<int,Worker>::iterator pos = m.find(cehua);
    int count = m.count(cehua);
    int index = 0;
    for (; pos!=m.end() && index < count; pos++,index++)
    {
        cout << "name:" << pos->second.m_Name << "salary:" << pos->second.m_Salary << endl;
    }
    
    cout << "----------------------" << endl;
	cout << "meishu:" << endl;
	pos = m.find(meishu);
	count = m.count(meishu); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name:" << pos->second.m_Name << "salary:" << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "yanfa:" << endl;
	pos = m.find(yanfa);
	count = m.count(yanfa); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name:" << pos->second.m_Name << "salary:" << pos->second.m_Salary << endl;
	}
}

int main()
{
    srand((unsigned int)time(NULL));

    //1.创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    //2.员工分组
    multimap<int,Worker> mWorker;
    setGroup(vWorker,mWorker);

    //3.分组显示员工
    showWorkerByGroup(mWorker);

    return 0;
}
