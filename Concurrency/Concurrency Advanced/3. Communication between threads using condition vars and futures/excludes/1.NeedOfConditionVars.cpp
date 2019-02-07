/* Analogy: Driver and night road journey: Traveller must be aware to wake up at his desired stop
 * Options:
 * 1.stay awake all night -- disturbs the sleep ~ consumes your resources
 * 2.set alarm clock to wake up - bus stop is traffic dependent so may miss the stop cannot set alarm
 * 3.Ask someone who is getting off one stop before you to wake you up at the right moment -- best option
 * */

#include <iostream>
#include <mutex>
#include <thread>
#include <stack>

bool i_have_arrived = false;
int final_destination = 13;
int distance_to_destination = 10;
int distance_covered = 0;

bool keep_driving(){
	while(distance_covered<=final_destination){
		if(distance_covered==3) std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //random traffic at stop 3
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		distance_covered++;
	}
	printf("final destination %d reached\n", final_destination);
	return false;
}

//case 1: unnecessary resource utilization
void keep_awake_all_night(){
	while(distance_covered <= distance_to_destination){
		printf("keep checking, whether I am there %d\n", distance_covered);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

//case 2: uncertainty
void set_the_alarm_and_take_a_nap(){
	if(distance_covered<=distance_to_destination){
		printf("taking a nap...\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(10000)); //represents time for set for an alarm
	}
	std::cout << "finally awake and distance covered = " << distance_covered << "\n";
}

int main() {
	std::thread driver_thread(keep_driving);
	std::thread traveller1_thread(keep_awake_all_night);
	std::thread traveller2_thread(set_the_alarm_and_take_a_nap);

	traveller1_thread.join();
	traveller2_thread.join();
	driver_thread.join();

	return 0;
}
