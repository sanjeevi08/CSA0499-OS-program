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
    
    // FCFS Scheduling
    printf(&quot;\nFCFS Disk Scheduling:\n&quot;);
    printf(&quot;Head Movement Sequence: %d&quot;, head);
    
    for (int i = 0; i < n; i++) {
        seek_time += abs(head - request_queue[i]);
        head = request_queue[i];
        printf(&quot; -> %d&quot;, head);
    }
    
    printf(&quot;\nTotal Seek Time: %d\n&quot;, seek_time);
    printf(&quot;Average Seek Time: %.2f\n&quot;, (float) seek_time / n);
    
    return 0;
}
```
