#include <stdio.h>

void print_combinations(int td, int fg, int td_converted, int fg_1point, int safety) {
    printf("%d TD + %d FG + %d TD + %d FG + %d Safety\n", td, fg, td_converted, fg_1point, safety);
}

void scoring_possibilities(int score) {
    printf("Possible combinations of scoring plays for %d points:\n", score);

    for (int td = 0; td <= score / 6; td++) {
        for (int fg = 0; fg <= score / 3; fg++) {
            for (int td_converted = 0; td_converted <= score / 8; td_converted++) {
                for (int fg_1point = 0; fg_1point <= score / 7; fg_1point++) {
                    for (int safety = 0; safety <= score / 2; safety++) {
                        if ((td * 6 + fg * 3 + td_converted * 8 + fg_1point * 7 + safety * 2) == score) {
                            print_combinations(td, fg, td_converted, fg_1point, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    do {
        printf("Enter the NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score > 1) {
            scoring_possibilities(score);
        } else {
            printf("Program terminated.\n");
            break;
        }

    } while (1);

    return 0;
}
