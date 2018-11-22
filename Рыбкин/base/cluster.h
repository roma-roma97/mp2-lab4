#ifndef __CLUSTER_H__
#define __CLUSTER_H__

using namespace std;

struct TProgram
{
	static int next_id;
	int id;
	int number_cycle;
	int number_cores;
	int time_execution;
	TProgram(int number_cycle = 1, int number_cores = 1);
	TProgram Creat(int cores);
	static int NextId()
	{
		next_id++;
		return next_id;
	}
};

struct Cluster
{
	int number_cycle;
	int number_cores;
	int number_finish_program; // Количество выполненных программ.
	int program_queue; // Количество программ, оставшихся в очереди.
	float number_programs;
	float number_refusal_queue; // Количество отказов из за переполненной очереди.
	float number_refusal; // Количество откзов из-за нехватки ядер во всей системе.
	float average_time; //среднее время выполнения в тактах.

	Cluster(int per = 0, int cyc = 1, int cor = 1);
	void Start(double _new_program);
};

#endif 