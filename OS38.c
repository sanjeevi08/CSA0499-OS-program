
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek_time = 0;
    printf(&quot;Enter the number of disk requests: &quot;);
    scanf(&quot;%d&quot;, &n);
    
    int request_queue[n];
    printf(&quot;Enter the disk request queue:\n&quot;);
    for (int i = 0; i < n; i++) {
        scanf(&quot;%d&quot;, &request_queue[i]);
    }

    printf(&quot;Enter the initial position of the disk head: &quot;);
    scanf(&quot;%d&quot;, &head);

    // Sort the request queue to simplify SCAN algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (request_queue[i] > request_queue[j]) {
                int temp = request_queue[i];
                request_queue[i] = request_queue[j];
                request_queue[j] = temp;
            }
        }
    }

    // SCAN (Elevator) Scheduling
    printf(&quot;\nSCAN (Elevator) Disk Scheduling:\n&quot;);
    int start = 0;
    int end = n - 1;
    int current_direction = 1; // 1 for moving right, -1 for moving left

    while (start <= end) {
        if (current_direction == 1) {
            for (int i = start; i <= end; i++) {
                if (request_queue[i] >= head) {
                    seek_time += abs(head - request_queue[i]);
                    head = request_queue[i];
                    start = i + 1;
                    break;
                }
            }
            current_direction = -1; // Change direction
        } else {
            for (int i = end; i >= start; i--) {
                if (request_queue[i] <= head) {
                    seek_time += abs(head - request_queue[i]);
                    head = request_queue[i];
                    end = i - 1;
                    break;
                }
            }
            current_direction = 1; // Change direction
        }
    }

    printf(&quot;Total Seek Time: %d\n&quot;, seek_time);
    printf(&quot;Average Seek Time: %.2f\n&quot;, (float)seek_time / n);
    return 0;
}
```
