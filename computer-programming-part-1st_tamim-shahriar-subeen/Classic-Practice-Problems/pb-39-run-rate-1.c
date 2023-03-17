#include <stdio.h>

int main() {
    int t; float total_run, current_run, remaining_boll;
    float current_boll, current_run_rate, requird_run_rate;

    scanf("%d", &t);
    while (t--) {
        scanf("%f %f %f", &total_run, &current_run, &remaining_boll);
        if (remaining_boll != 0) {
            current_boll = 300 - remaining_boll;
            current_run_rate = current_run / (current_boll / 6);
            if (total_run < current_run) 
            {
                requird_run_rate = 0.00;
            }
            else {
                requird_run_rate = ((total_run + 1) - current_run) / (remaining_boll / 6);
            }
            
        }
        else {
            current_run_rate = current_run / 50;
            if (current_run > total_run) {
                requird_run_rate = 0.00;
            }
            else {
                requird_run_rate = (total_run + 1) - current_run;
            }
        }
        printf("%.2f %.2f\n", current_run_rate, requird_run_rate);

        
    }
    return 0;
}