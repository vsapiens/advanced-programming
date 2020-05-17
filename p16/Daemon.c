#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(void)
{

    /* Our process ID and Session ID */
    pid_t pid, sid;

    /* Fork off the parent process */
    pid = fork();
    if (pid < 0)
    {
        exit(EXIT_FAILURE);
    }
    /* If we got a good PID, then
           we can exit the parent process. */
    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    /* Change the file mode mask */
    umask(0);

    /* Open any logs here */

    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0)
    {
        /* Log the failure */
        exit(EXIT_FAILURE);
    }

    /* Close out the standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    /* Daemon-specific initialization goes here */

    /* The Big Loop */
    while (1)
    {
        FILE *in, *out;

        int curr;
        in = fopen("input.txt", "r");
        out = fopen("output.txt", "w+");
        fscanf(in, "%d", &curr);
        while (curr--)
        {
            int num, a, v;
            int s = 0;

            fscanf(in, "%d", &num);
            while (num--)
            {
                fscanf(in, "%d %d", &a, &v);
                s += a - v;
            }
            fprintf(out, "%d\n", s);
        }
        fclose(in);
        fclose(out);

        sleep(10); /* wait 30 seconds */
    }
    exit(EXIT_SUCCESS);
}