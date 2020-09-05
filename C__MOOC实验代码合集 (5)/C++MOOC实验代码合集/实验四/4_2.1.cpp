// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// ConsoleApplication7.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������


#include <iostream>
using namespace std;

enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};
class CPU
{
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
    CPU (CPU_Rank r, int f, float v)
	{
		rank = r;
		frequency = f;
		voltage = v;
		cout << "������һ��CPU!" << endl;
	}

	/*CPU(CPU &c)
	{
		rank= c.rank;
		frequency = c.frequency;
        voltage = c.voltage;

		cout << "����������һ��CPU!" << endl;
	}*/

	~CPU () { cout << "������һ��CPU!" << endl; }

    CPU_Rank GetRank() const { return rank; }
    int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }

    void SetRank(CPU_Rank r) { rank = r; }
    void SetFrequency(int f) { frequency = f; }
    void SetVoltage(float v) { voltage = v; }

    void Run() {cout << "CPU��ʼ����!" << endl; }
	void Stop() {cout << "CPUֹͣ����!" << endl; }
};

enum RAM_Type {DDR2=2,DDR3,DDR4};
class RAM 
{
private:
	enum RAM_Type type;
	unsigned int frequency;//MHz
	unsigned int size;//GB

public:
    RAM (RAM_Type t, unsigned int f, unsigned int s)
	{
		type = t;
		frequency = f;
		size = s;
		cout << "������һ��RAM!" << endl;
	}
	~RAM () { cout << "������һ��RAM!" << endl; }

    RAM_Type GetType() const { return type; }
    unsigned int GetFrequency() const { return frequency; }
	unsigned int GetSize() const { return size; }

    void SetType(RAM_Type t) { type = t; }
    void SetFrequency(unsigned int f) { frequency = f; }
    void SetSize(unsigned int s) { size = s; }

    void Run() {cout << "RAM��ʼ����!" << endl; }
	void Stop() {cout << "RAMֹͣ����!" << endl; }

};

enum CDROM_Interface {SATA,USB};
enum CDROM_Install_type {external,built_in};
class CD_ROM
{
private:
	enum CDROM_Interface interface_type;
	unsigned int cache_size;//MB
	CDROM_Install_type install_type;

public:
    CD_ROM (CDROM_Interface i, unsigned int s,  CDROM_Install_type it)
	{
		interface_type = i;
		cache_size = s;
		install_type = it;
		cout << "������һ��CD_ROM!" << endl;
	}
	~CD_ROM () { cout << "������һ��CD_ROM!" << endl; }

    CDROM_Interface GetInterfaceType() const { return interface_type; }
    unsigned int GetSize() const { return cache_size; }
	CDROM_Install_type GetInstallType() const { return install_type; }

    void SetInterfaceType(CDROM_Interface i) { interface_type = i; }
    void SetSize(unsigned int s) { cache_size = s; }
    void SetInstallType(CDROM_Install_type it) { install_type = it; }

    void Run() {cout << "CD_ROM��ʼ����!" << endl; }
	void Stop() {cout << "CD_ROMֹͣ����!" << endl; }

};


class COMPUTER
{
private:
	CPU my_cpu;
	RAM my_ram;
	CD_ROM my_cdrom;
	unsigned int storage_size;//GB
	unsigned int bandwidth;//MB

public:
	COMPUTER (CPU c, RAM r, CD_ROM cd,unsigned int s,unsigned int b);
	
	~COMPUTER () { cout << "������һ��COMPUTER!" << endl; }

	void Run() 
	{
		my_cpu.Run();
		my_ram.Run();
        my_cdrom.Run();
		cout << "COMPUTER��ʼ����!" << endl; 
	}

	void Stop() 
	{
		my_cpu.Stop();
		my_ram.Stop();
        my_cdrom.Stop();
		cout << "COMPUTERֹͣ����!" << endl; 
	}

};

COMPUTER::COMPUTER(CPU c, RAM r, CD_ROM cd,unsigned int s,unsigned int b):
	       my_cpu(c),my_ram(r),my_cdrom(cd)
{
	storage_size = s;
	bandwidth = b;

	cout << "������һ��COMPUTER!" << endl;
}


int main()
{
	CPU a(P6,300,2.8);
	a.Run();
	a.Stop();
	cout<<"*************************\n";


	RAM b(DDR3,1600,8);
	b.Run();
	b.Stop();
	cout<<"*************************\n";

	CD_ROM c(SATA,2,built_in);
	c.Run();
	c.Stop();
	cout<<"*************************\n";

	COMPUTER my_computer(a,b,c,128,10);
	cout<<"*************************\n";

	my_computer.Run();
	my_computer.Stop();
	cout<<"*************************\n";

	return 0;
}
