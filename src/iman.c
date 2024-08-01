#include "headers.h"
#define MAX_REQUEST_SIZE 100000

void usage()
{
    fprintf(stderr, "Usage: iMan <command_name>\n");
}

void iman(char **entries)
{

    const char *command_name = entries[1];
    if (command_name == NULL)
    {
        usage();
        return;
    }

    char addr_str[NI_MAXHOST];
    struct addrinfo *addr_info_list;


    int addr_info = getaddrinfo("man.he.net", "80", NULL, &addr_info_list);

    if (addr_info)
    {
        fprintf(stderr, "DNS resolution failed\n");
        return;
    }

    int sock_fd = -1;

    for (struct addrinfo *list = addr_info_list; list != NULL; list = list->ai_next)
    {
        int ni_ret = getnameinfo(list->ai_addr, list->ai_addrlen, addr_str, sizeof(addr_str), NULL, 0, NI_NUMERICHOST);

        if (ni_ret)
        {
            fprintf(stderr, "getnameinfo() failed: %s\n", gai_strerror(ni_ret));
            continue;
        }

        printf("AF %s: %s\n", (list->ai_family == AF_INET) ? "IPv4" : "IPv6", addr_str);

        sock_fd = socket(list->ai_family, list->ai_socktype, list->ai_protocol);

        if (sock_fd < 0)
        {
            perror("Creating Socket failed");
            continue;
        }

        if (connect(sock_fd, list->ai_addr, list->ai_addrlen) < 0)
        {
            perror("Connection failed");
            close(sock_fd);
            sock_fd = -1;
            continue;
        }

        break;
    }

    if (sock_fd < 0)
    {
        fprintf(stderr, "Failed to establish a connection\n");
        freeaddrinfo(addr_info_list);
        return;
    }
    else
    {
        printf("Connected successfully to IP: %s\n", addr_str);

        char s1[qt], s2[qt], get_request[3 * qt];
        snprintf(s1, sizeof(s1), "/?topic=%s", entries[1]);
        snprintf(s2, sizeof(s2), "&section=all");
        snprintf(get_request, sizeof(get_request), "GET %s%s HTTP/1.1\r\nHost: man.he.net\r\n\r\n", s1, s2);
        // Send the GET request
        if (send(sock_fd, get_request, strlen(get_request), 0) == -1)
        {
            perror("send");
            close(sock_fd);
            freeaddrinfo(addr_info_list);
            return;
        }

        char response[MAX_REQUEST_SIZE];
        int bytes_received;

        while ((bytes_received = recv(sock_fd, response, sizeof(response) - 1, 0)) > 0)
        {
            response[bytes_received] = '\0';
            int flag = 0;
            for (int i = 0; i < strlen(response); i++)
            {
                if (response[i] == '<')
                    flag = 1;
                else if (response[i] == '>')
                    flag = 0;

                if (flag == 0 && response[i] != '>')
                    printf("%c", response[i]);
            }
        }
        close(sock_fd);
    }

    freeaddrinfo(addr_info_list);
}
