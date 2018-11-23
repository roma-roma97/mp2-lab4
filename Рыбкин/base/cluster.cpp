#include "cluster.h"
#include "queue.h"
#include <list>
#include <cstdlib>
#include <time.h>

using namespace std;

int TProgram::next_id = -1;

TProgram::TProgram(int _number_cycle, int _number_cores)
{
	id = NextId();
	number_cycle = _number_cycle;
	number_cores = _number_cores;
	time_execution = 0;
	static int id = 1;
}

TProgram TProgram::Creat(int cores)
{
	TProgram tmp;
	srand(time(NULL));
	tmp.number_cores = rand() % (cores + 5);
	srand(time(NULL));
	tmp.number_cycle = rand() % 10;
	tmp.time_execution = tmp.number_cycle;
	return tmp;
}

Cluster::Cluster(int per, int cyc, int cor) :number_finish_program(0),
program_queue(0), number_refusal(0), number_refusal_queue(0), average_time(0), number_programs(0),
number_cycle(cyc), number_cores(cor) {};

void Cluster::Start(double new_prog)
{
	list<TProgram> programs;
	list<TProgram>::iterator it;
	TQueue<TProgram> queue(5);
	TProgram tmp;
	int free_cores = number_cores;
	double flag;
	for (int i = 0; i < number_cycle; i++)
	{
		for (it = programs.begin(); it != programs.end();)
		{
			if ((*it).time_execution == 0)
			{
				average_time += (*it).number_cycle;
				++number_finish_program;
				free_cores += (*it).number_cores;
				programs.erase(it++);
			}
			else
			{
				(*it).time_execution--;
				it++;
			}
		}
		srand(time(NULL));
		flag = rand() % 10;
		flag = flag / 10;
		if (flag < new_prog)
		{
			number_programs++;
			tmp = tmp.Creat(number_cores);
			if ((tmp.number_cores > number_cores))
				number_refusal++;
			else if (queue.IsFull())
				number_refusal_queue++;
			else
				queue.Push(tmp);
		}
		while (!queue.IsEmpty() && (free_cores >= queue.GetFirstEl().number_cores))
		{
			free_cores -= queue.GetFirstEl().number_cores;
			programs.push_back(queue.Pop());
		}
	}
	program_queue = queue.GetCount();
	average_time = average_time / number_finish_program;
	number_refusal_queue = (number_refusal_queue / number_programs) * 100;
	number_refusal = (number_refusal / number_programs) * 100;
	number_finish_program = (number_finish_program / number_programs) * 100;
}
