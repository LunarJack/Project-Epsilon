#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}
int main(int argc, char *argv[])
{
    CURL *curl_handle;
    static const char *pagefilename = "epsilon.zip";
    FILE *pagefile;
    curl_global_init(CURL_GLOBAL_ALL);
    return 0;
}