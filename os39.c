
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
    
    // Sort the request queue for simplicity
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (request_queue[i] > request_queue[j]) {
                int temp = request_queue[i];
                request_queue[i] = request_queue[j];
                request_queue[j] = temp;
            }
        }
    }
    
    // C-SCAN Scheduling
    printf(&quot;\nC-SCAN Disk Scheduling:\n&quot;);
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        for (int i = start; i <= end; i++) {
            if (request_queue[i] >= head) {
                seek_time += abs(head - request_queue[i]);
                head = request_queue[i];
                start = i + 1;
            }
        }
        
        // Move the head to the end in the current direction
        seek_time += abs(head - 0);
        head = 0;

        // Change direction to the opposite side
        seek_time += abs(head - request_queue[end]);
        head = request_queue[end];
        end = n - 2; // Exclude the last request, as it has already been served
    }

    printf(&quot;Total Seek Time: %d\n&quot;, seek_time);
    printf(&quot;Average Seek Time: %.2f\n&quot;, (float)seek_time / n);
    
    return 0;
}

