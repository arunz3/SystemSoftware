#include <stdio.h>
#include <stdlib.h>

int number_of_philosophers, chopstick_availability[16];
int take_chopstick(int philosopher) {
    if (chopstick_availability[philosopher] && chopstick_availability[(philosopher+1)%number_of_philosophers]) {
        chopstick_availability[philosopher] = chopstick_availability[(philosopher+1)%number_of_philosophers] = 0;
        return 1;
    } else {
        return 0;
    }
}
void putback_chopstick(int philosopher) {
    chopstick_availability[philosopher] = chopstick_availability[(philosopher+1)%number_of_philosophers] = 1;
}
int main() {
    int philosophers[16], i, all_philosophers_done = 0;
    for (i=0; i<16; i++) {
        philosophers[i] = 0;
        chopstick_availability[i] = 1;
    }
    number_of_philosophers = 5;

    while (!all_philosophers_done) {
        for (i=0; i<number_of_philosophers; i++) {
            if (!philosophers[i]) {
                if (take_chopstick(i)) {
                    printf("Philosopher %d eating\n", i);
                    philosophers[i] = 1;
                } else {
                    printf("Philosopher %d couldnt take chopstick\n", i);
                }
            }
        }
        printf("\n");
        all_philosophers_done = 1;
        for (i=0; i<number_of_philosophers; i++) {
            if (!philosophers[i]) {
                all_philosophers_done = 0;
                break;
            }
        }
        for (i=0; i<number_of_philosophers; i++) {
            if (philosophers[i]) {
                putback_chopstick(i);
                printf("Philosopher %d has finished eating\n",  i);
            }
        }
        printf("\n");
    }
    return 0;
}
