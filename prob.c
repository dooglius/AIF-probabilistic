#include <stdio.h>

const double late_person_prob = (double) 0.4;

const double reslife_double_prob = 0.6;
const double big_double_lottery_prob = (double).7;
const double mid_double_lottery_prob = (double).9;

#define NUM 7
const double people[NUM] = {
(double)1/3, // REDACTED NAME
(double)1/3, // REDACTED NAME
(double)3/4, // REDACTED NAME
(double)2/3, // REDACTED NAME
(double)1/6, // REDACTED NAME
(double)0.9, // REDACTED NAME
(double)0.9  // REDACTED NAME
};

int main(){
	int i;
	double count[NUM+2];
	for(i = 0; i < (1 << NUM); i++){
		double a = 1;
		int c = 0;
		int b;
		for(b = 0; b < NUM; b++){
			if(i & (1 << b)){
				c++;
				a = a*people[b];
			} else {
				a = a*(1-people[b]);
			}
		}
		count[c] += a*(1-late_person_prob);
		count[c+1]+=a*late_person_prob;
	}
	for(i = 0; i < NUM+1; i++){
//		printf("DEBUG: Probability of %d accepting: %f\n",i,count[i]);
	}

	double twenty_or_more = 0;
	double twenty_two_or_more = 0;
	for(i = 4; i < NUM+1; i++){
		twenty_or_more += count[i];
	}
	for(i = 6; i < NUM+1; i++){
		twenty_two_or_more += count[i];
	}

/*
	printf("Strategy 1:\n");
	printf("Apply for the 3 suites; if we get >= 19 confirms, go for double via lottery\n");
	printf("\n");
	printf("Filling only 16 spots: %.1f\%\n",100*count[0]);
	printf("Filling only 17 spots: %.1f\%\n",100*count[1]);
	printf("Filling exactly 18 spots: %.1f\%\n",100*count[2]);
	printf("Filling 17 spots of floor, getting 760 via lottery: %.1f\%\n",100*count[3]*big_double_lottery_prob);
	printf("Filling 17 spots of floor, getting 751 via lottery: %.1f\%\n",100*count[3]*(1-big_double_lottery_prob)*mid_double_lottery_prob);
	printf("Filling 17 spots of floor, failing housing lottery: %.1f\%\n",100*count[3]*(1-big_double_lottery_prob)*(1-mid_double_lottery_prob));
	printf("Filling 18 spots of floor, getting 760 via lottery: %.1f\%\n",100*twenty_or_more*big_double_lottery_prob);
	printf("Filling 18 spots of floor, getting 751 via lottery: %.1f\%\n",100*twenty_or_more*(1-big_double_lottery_prob)*mid_double_lottery_prob);
	printf("Filling 18 spots of floor, failing housing lottery: %.1f\%\n",100*twenty_or_more*(1-big_double_lottery_prob)*(1-mid_double_lottery_prob));
*/

	printf("\n\n\n");
	printf("Strategy 2:\n");
	printf("Apply for the 3 suites plus a double; if we don't get the double, and get >= 19 confirms, go for double via lottery\n");
	printf("If we do get the double, and we have >= 2 more people interested, go for other double via lottery\n");
	printf("\n");
	printf("Don't get the double, fill only 16 spots: %.1f\%\n",100*count[0]*(1-reslife_double_prob));
	printf("Don't get the double, fill only 17 spots: %.1f\%\n",100*count[1]*(1-reslife_double_prob));
	printf("Don't get the double, fill exactly 18 spots: %.1f\%\n",100*count[2]*(1-reslife_double_prob));
	printf("Don't get the double, fill 17 spots of floor, getting 760 via lottery: %.1f\%\n",100*count[3]*big_double_lottery_prob*(1-reslife_double_prob));
	printf("Don't get the double, fill 17 spots of floor, getting 751 via lottery: %.1f\%\n",100*count[3]*(1-big_double_lottery_prob)*mid_double_lottery_prob*(1-reslife_double_prob));
	printf("Don't get the double, fill 17 spots of floor, failing housing lottery: %.1f\%\n",100*count[3]*(1-big_double_lottery_prob)*(1-mid_double_lottery_prob)*(1-reslife_double_prob));
	printf("Don't get the double, fill 18 spots of floor, getting 760 via lottery: %.1f\%\n",100*twenty_or_more*big_double_lottery_prob*(1-reslife_double_prob));
	printf("Don't get the double, fill 18 spots of floor, getting 751 via lottery: %.1f\%\n",100*twenty_or_more*(1-big_double_lottery_prob)*mid_double_lottery_prob*(1-reslife_double_prob));
	printf("Don't get the double, fill 18 spots of floor, failing housing lottery: %.1f\%\n",100*twenty_or_more*(1-big_double_lottery_prob)*(1-mid_double_lottery_prob)*(1-reslife_double_prob));
	printf("Get the double, fill only 16 spots: %.1f\%\n",100*count[0]*reslife_double_prob);
	printf("Get the double, fill only 17 spots: %.1f\%\n",100*count[1]*reslife_double_prob);
	printf("Get the double, fill only 18 spots: %.1f\%\n",100*count[2]*reslife_double_prob);
	printf("Get the double, fill only 19 spots: %.1f\%\n",100*count[3]*reslife_double_prob);
	printf("Get the double, fill all 20 spots: %.1f\%\n",100*(twenty_or_more-twenty_two_or_more)*reslife_double_prob);
	printf("Get the double, fill 20 spots of floor, and get 760 via lottery: %.1f\%\n", 100*twenty_two_or_more*reslife_double_prob*big_double_lottery_prob);
	printf("Get the double, fill 20 spots of floor, and try but fail lottery: %.1f\%\n", 100*twenty_two_or_more*reslife_double_prob*(1-big_double_lottery_prob));
}
