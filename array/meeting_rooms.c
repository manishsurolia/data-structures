#include <stdio.h>

typedef struct meeting
{
    int start;
    int end;
} meeting;

typedef struct room
{
    meeting m;
    int used;
} room;


int rooms_required(meeting m[], int no_of_meetings)
{
    int no_of_rooms = no_of_meetings;
    room r[no_of_rooms];
    int count = 0;

    for (int i=0; i<no_of_rooms; i++)
        r[i].m.start = r[i].m.end = r[i].used = 0;

    for (int i=0; i<no_of_meetings; i++) {
        for (int j=0; j <no_of_rooms; j++) {
            if (m[i].start >= r[j].m.end) {
                r[j].m.start = m[i].start;
                r[j].m.end = m[i].end;
                r[j].used = 1;
                break;
            }
        }
    }

    for (int i=0; i<no_of_rooms; i++)
        if (r[i].used)
            count++;

    return count;
}

int main(void)
{
    meeting m[4] = {{0, 30}, {5, 10}, {15, 20}, {20, 30}};
    printf("Result = %d\n",rooms_required(m, 4));
    return 0;
}



