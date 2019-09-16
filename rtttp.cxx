#include <iostream>
#include <thread>
#include "Timestamp.hxx"

using namespace std::chrono;


void Do(RemoteTimestamp &rts, const milliseconds &rtt);


int main(int argc, char **args)
{
	const Timestamp remoteNow;
	const auto initialRtt = nanoseconds{1000ms}.count();

	RemoteTimestamp rts1, rts2;

	rts1.Start(remoteNow, initialRtt);
	rts2.Start(remoteNow, initialRtt);

	Do(rts1, 1000ms);

	rts1.ResetStatistics();

	Do(rts1, 500ms);

	return 0;
}


void Do(RemoteTimestamp &rts, const milliseconds &rtt)
{
	int32_t remain = 5;

	while (0 < remain--)
	{
		std::cout << rts.CalcNow() << std::endl;

		std::this_thread::sleep_for(1s);

		const Timestamp remoteNow;
		rts.AddRtt(nanoseconds{rtt}.count());
		std::cout
			<< "remote elapsed:"
			<< rts.CalcElapsed(remoteNow)
			<< std::endl;
	}
}